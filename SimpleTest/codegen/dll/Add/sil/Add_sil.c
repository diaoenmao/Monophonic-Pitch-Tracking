/*
 * Add_sil.c
 *
 * Automatically generated host I/O interface for:
 * Component: Add
 * Execution Mode: SIL
 *
 */

#include <stdio.h>
#include <string.h>
#include "mex.h"
#include "rtiostream_utils.h"
#include "xilutils.h"
#include "xilcomms_rtiostream.h"
#include "xilservice.h"
#include "_coder_Add_api.h"
#include "_coder_Add_info.h"

typedef struct {
  FILE ** Fd;
  mwSize size;
  int32_T fidOffset;
} targetIOFd_T;

static targetIOFd_T *targetIOFdPtr = NULL;
static XIL_RtIOStreamData_T* rtIOStreamDataPtr = NULL;
static SIL_DEBUGGING_DATA_T* silDebuggingDataPtr = NULL;
static XIL_IOBuffer_T* IOBufferPtr = NULL;
static int *pCommErrorOccurred = 0;
static void* pXILService = NULL;
static void* pXILComms = NULL;
static void* pXILUtils = NULL;
static void* pMemUnitTransformer = NULL;
static boolean_T firstTime= 0;

/* implements calls into MATLAB */
static int callMATLAB(
                      int nlhs,
                      mxArray * plhs[],
                      int nrhs,
                      mxArray * prhs[],
                      const char * functionName,
                      int withTrap)
{
  int errorOccurred = 0;
  if (withTrap) {
    mxArray * mException;
    mException = mexCallMATLABWithTrap(nlhs, plhs, nrhs, prhs, functionName);

    {
      int i;
      for (i=0; i<nrhs; i++) {
        mxDestroyArray(prhs[i]);
      }                                /* for */
    }

    if (mException != NULL) {
      mxArray * rhsDisplayMException[1];
      errorOccurred = 1;
      rhsDisplayMException[0] = mException;
      mException = mexCallMATLABWithTrap(0, NULL, 1, rhsDisplayMException,
        "rtw.pil.SILPILInterface.displayMException");
      mxDestroyArray(rhsDisplayMException[0]);
      if (mException != NULL) {
        mxDestroyArray(mException);
        mexErrMsgTxt(
                     "Error calling rtw.pil.SILPILInterface.displayMException on mException object.");
      } else {
        mexErrMsgTxt(
                     "mexCallMATLABWithTrap failed. See the full MException report in the MATLAB Command Window.");
      }                                /* if */
    }                                  /* if */
  } else {
    errorOccurred = mexCallMATLAB(nlhs, plhs, nrhs, prhs, functionName);

    {
      int i;
      for (i=0; i<nrhs; i++) {
        mxDestroyArray(prhs[i]);
      }                                /* for */
    }

    if (errorOccurred) {
      mexErrMsgTxt( "mexCallMATLAB failed!");
    }                                  /* if */
  }                                    /* if */

  return errorOccurred;
}

static void xilDisplayException(void* pXILUtils)
{
  if (pXILUtils == NULL) {
    mexPrintf("pXILUtils is NULL!");
    return;
  }                                    /* if */

  {
    mxArray * pMException = xilMATLABUtilsGetException(pXILUtils);
    if (pMException == NULL) {
      mexPrintf("pMException is NULL!\n");
    } else {
      mxArray * prhs[1];
      prhs[0] = pMException;
      mexCallMATLAB(0, NULL, 1, prhs,
                    "rtw.pil.SILPILInterface.displayMException");
    }                                  /* if */
  }
}

/* grow the buffer for target I/O Fd array
 * targetIOFd->Fd is NULL on failure */
static void growTargetIOFd(targetIOFd_T * IOFd, mwSize requiredSize)
{
  if (IOFd->size < requiredSize) {
    IOFd->Fd = mxRealloc(IOFd->Fd, requiredSize * sizeof(FILE*));
    if (IOFd->Fd == NULL) {
      mexErrMsgTxt( "growTargetIOFd: mxRealloc failed.");
    } else {
      mexMakeMemoryPersistent(IOFd->Fd);
      IOFd->size = requiredSize;
    }                                  /* if */
  }                                    /* if */
}

static void closeAndFreeTargetIOFd()
{
  int i;
  if (targetIOFdPtr != NULL) {
    if (targetIOFdPtr->Fd != NULL) {
      for (i=0; i<targetIOFdPtr->size; i++) {
        if (targetIOFdPtr->Fd[i] != NULL) {
          fclose(targetIOFdPtr->Fd[i]);
        }                              /* if */
      }                                /* for */

      mxFree(targetIOFdPtr->Fd);
    }                                  /* if */
  }                                    /* if */
}

/* receive one packet of data and dispatch to owning application */
static int recvData(void* pXILComms)
{
  int errorOccurred = 0;
  if (pCommErrorOccurred == NULL) {
    mexErrMsgTxt( "pCommErrorOccurred is NULL.");
    errorOccurred = 1;
    return errorOccurred;
  }                                    /* if */

  if (pXILUtils == NULL) {
    mexErrMsgTxt( "pXILUtils is NULL.");
    errorOccurred = 1;
    return errorOccurred;
  }                                    /* if */

  errorOccurred = (xilCommsRun(pXILComms, pXILUtils) ==
                   XILCOMMS_RTIOSTREAM_ERROR);
  *pCommErrorOccurred = errorOccurred;
  return errorOccurred;
}

/* send data via xil comms */
static int sendData(void* pXILService, XIL_IOBuffer_T* IOBuffer, mwSize sendSize)
{
  int errorOccurred = 0;
  if (pCommErrorOccurred == NULL) {
    mexErrMsgTxt( "pCommErrorOccurred is NULL.");
    errorOccurred = 1;
    return errorOccurred;
  }                                    /* if */

  errorOccurred = (xilServiceSend(pXILService, IOBuffer->data, sendSize) ==
                   XILSERVICE_ERROR);
  *pCommErrorOccurred = errorOccurred;
  return errorOccurred;
}

/* implements command dispatch layer */
static int commandDispatch(XIL_IOBuffer_T* IOBuffer, mwSize dataOutSize, mwSize *
  dataInSize)
{
  uint8_T COMMAND_COMPLETE = 0;
  int errorOccurred = 0;

  /* send the data */
  errorOccurred = sendData(pXILService, IOBuffer, dataOutSize);
  if (errorOccurred) {
    xilDisplayException(pXILUtils);
    return errorOccurred;
  }                                    /* if */

  /* receive the response data */
  while (!COMMAND_COMPLETE) {
    xilServiceSetIsCommandComplete(pXILService, 0);
    errorOccurred = recvData(pXILComms);
    if (errorOccurred) {
      xilDisplayException(pXILUtils);
      return errorOccurred;
    }                                  /* if */

    COMMAND_COMPLETE = xilServiceGetIsCommandComplete(pXILService);
  }                                    /* while */

  *dataInSize = xilServiceGetPayloadSizeForOneStep(pXILService);
  return errorOccurred;
}

static void mdlInitializeSizes()
{
  {
    mxArray * lhs[1];
    mxArray * error = NULL;
    char * installVersion;
    error = mexCallMATLABWithTrap(1, lhs, 0, NULL,
      "rtw.pil.SILPILInterface.getPILVersion");
    if (error != NULL) {
      mxDestroyArray(error);
      mexErrMsgTxt(
                   "Failed to determine the installed In-the-Loop version for comparison against the In-the-Loop s-function version (release 6.6 (R2014a)_11). To avoid this error, remove the In-the-Loop s-function from your MATLAB path (e.g. delete it or move to a clean working directory).");
      return;
    }                                  /* if */

    if (mxIsEmpty(lhs[0])) {
      mexErrMsgTxt( "rtw.pil.SILPILInterface.getPILVersion returned empty!");
      return;
    }                                  /* if */

    installVersion = mxArrayToString(lhs[0]);
    mxDestroyArray(lhs[0]);
    if (installVersion == NULL) {
      mexErrMsgTxt( "Failed to determine installed In-the-Loop version.");
      return;
    }                                  /* if */

    if (strcmp(installVersion, "6.6 (R2014a)_11") != 0) {
      mexErrMsgTxt(
                   "The In-the-Loop s-function is incompatible with the installed In-the-Loop version (see ver('ecoder')); it was generated for release 6.6 (R2014a)_11. To avoid this error, remove the In-the-Loop s-function from your MATLAB path (e.g. delete it or move to a clean working directory)");
      return;
    }                                  /* if */

    mxFree(installVersion);
  }
}

#define MDL_START                                                /* Change to #undef to remove function */
#if defined(MDL_START)

static void mdlStart()
{
  {
    {
      pCommErrorOccurred = (int *) mxCalloc(1, sizeof(int));
      if (pCommErrorOccurred == NULL) {
        mexErrMsgTxt(
                     "Error in allocating memory for pCommErrorOccurred through mxCalloc.");
        return;
      }                                /* if */

      *pCommErrorOccurred = 0;
      mexMakeMemoryPersistent(pCommErrorOccurred);
    }
  }

  {
    {
      mxArray *rhs[4];
      const char * simulinkBlockPath =
        "D:\\GitHub\\Monophonic-Pitch-Tracking\\SimpleTest\\codegen\\dll\\Add\\Add";
      rhs[ 0 ] = mxCreateString(
        "@coder.connectivity.MATLABInterface.getSILPILInterface");
      rhs[ 1 ] = mxCreateDoubleScalar( 3 );
      rhs[ 2 ] = mxCreateString(simulinkBlockPath);
      rhs[3] = mxCreateString("uint8");
      callMATLAB( 0, NULL, 4, rhs,
                 "rtw.pil.SILPILInterface.sfunctionPILStartHook", 0);
    }
  }

  {
    mxArray *rhs[3];
    mxArray *lhs[5];
    const char * simulinkBlockPath =
      "D:\\GitHub\\Monophonic-Pitch-Tracking\\SimpleTest\\codegen\\dll\\Add\\Add";
    rhs[ 0 ] = mxCreateString(
      "@coder.connectivity.MATLABInterface.getSILPILInterface");
    rhs[ 1 ] = mxCreateDoubleScalar( 3 );
    rhs[ 2 ] = mxCreateString(simulinkBlockPath);
    callMATLAB( 5, lhs, 3, rhs,
               "rtw.pil.SILPILInterface.sfunctionGetRtIOStreamInfoHook", 0);

    {
      rtIOStreamDataPtr = (XIL_RtIOStreamData_T*) mxCalloc(1, sizeof
        (XIL_RtIOStreamData_T));
      if (rtIOStreamDataPtr == NULL) {
        mexErrMsgTxt( "Error in allocating memory through mxCalloc.");
        return;
      }                                /* if */

      rtIOStreamDataPtr->lib = mxArrayToString(lhs[0]);
      rtIOStreamDataPtr->MATLABObject = mxDuplicateArray(lhs[1]);
      mexMakeMemoryPersistent(rtIOStreamDataPtr);
      mexMakeMemoryPersistent(rtIOStreamDataPtr->lib);
      mexMakeArrayPersistent(rtIOStreamDataPtr->MATLABObject);
      rtIOStreamDataPtr->streamID = *mxGetPr(lhs[2]);
      rtIOStreamDataPtr->recvTimeout = *mxGetPr(lhs[3]);
      rtIOStreamDataPtr->sendTimeout = *mxGetPr(lhs[4]);
      rtIOStreamDataPtr->isRtIOStreamCCall = 1;
      rtIOStreamDataPtr->ioMxClassID = mxUINT8_CLASS;
      rtIOStreamDataPtr->ioDataSize = sizeof(uint8_T);
      rtIOStreamDataPtr->targetRecvBufferSizeBytes = 50000;
      rtIOStreamDataPtr->targetSendBufferSizeBytes = 50000;

      {
        int errorStatus = rtIOStreamLoadLib(&rtIOStreamDataPtr->libH,
          rtIOStreamDataPtr->lib);
        if (errorStatus) {
          mexErrMsgTxt( "rtIOStreamLoadLib failed.");
          return;
        }                              /* if */
      }
    }

    {
      int i;
      for (i=0; i<5; i++) {
        mxDestroyArray(lhs[i]);
      }                                /* for */
    }
  }

  {
    IOBufferPtr = (XIL_IOBuffer_T *) mxCalloc(1, sizeof(XIL_IOBuffer_T));
    if (IOBufferPtr == NULL) {
      mexErrMsgTxt( "Error in allocating memory through mxCalloc.");
      return;
    }                                  /* if */

    mexMakeMemoryPersistent(IOBufferPtr);
  }

  {
    const char * simulinkBlockPath =
      "D:\\GitHub\\Monophonic-Pitch-Tracking\\SimpleTest\\codegen\\dll\\Add\\Add";
    silDebuggingDataPtr = (SIL_DEBUGGING_DATA_T*) mxCalloc(1, sizeof
      (SIL_DEBUGGING_DATA_T));
    if (silDebuggingDataPtr == NULL) {
      mexErrMsgTxt(
                   "Error in allocating memory through mxCalloc for SIL_DEBUGGING_DATA_T.");
      return;
    }                                  /* if */

    silDebuggingDataPtr->componentBlockPath = strcpy((char *) mxCalloc(strlen
      (simulinkBlockPath)+1, sizeof(char)), simulinkBlockPath);
    silDebuggingDataPtr->SILPILInterfaceFcnStr = strcpy((char*) mxCalloc(55,
      sizeof(char)), "@coder.connectivity.MATLABInterface.getSILPILInterface");
    silDebuggingDataPtr->inTheLoopType = 3;
    mexMakeMemoryPersistent(silDebuggingDataPtr);
    mexMakeMemoryPersistent(silDebuggingDataPtr->componentBlockPath);
    mexMakeMemoryPersistent(silDebuggingDataPtr->SILPILInterfaceFcnStr);
  }

  {
    targetIOFdPtr = (targetIOFd_T *) mxCalloc(1, sizeof(targetIOFd_T));
    if (targetIOFdPtr == NULL) {
      return;
    }                                  /* if */

    mexMakeMemoryPersistent(targetIOFdPtr);
    targetIOFdPtr->size = 0;
    targetIOFdPtr->Fd = NULL;
    targetIOFdPtr->fidOffset = -1;
  }

  {
    int retValXILUtils;
    uint8_T memUnitSizeBytes = 1;
    uint8_T ioDataTypeSizeBytes = sizeof(uint8_T);
    retValXILUtils = xilMATLABUtilsCreate(&pXILUtils);
    if (retValXILUtils!=XIL_UTILS_SUCCESS) {
      mexErrMsgTxt( "Error instantiating XIL Utils!");
      return;
    }                                  /* if */

    if (xilCommsCreate(&pXILComms, rtIOStreamDataPtr, silDebuggingDataPtr,
                       memUnitSizeBytes, pMemUnitTransformer, pXILUtils) !=
        XILCOMMS_RTIOSTREAM_SUCCESS) {
      xilDisplayException(pXILUtils);
      return;
    }                                  /* if */

    if (xilServiceCreate(&pXILService, pXILComms, pXILUtils, IOBufferPtr,
                         memUnitSizeBytes, ioDataTypeSizeBytes) !=
        XILSERVICE_SUCCESS) {
      xilDisplayException(pXILUtils);
      return;
    }                                  /* if */

    xilCommsRegisterApplication(pXILComms, pXILService);
  }

  {
    uint8_T * mxMemUnitPtr;
    mwSize dataInSize = 0;
    if (IOBufferPtr != NULL) {
      if (pXILService != NULL) {
        if (xilServiceGrowIOBuffer(pXILService, IOBufferPtr, 5, 0)!=
            XILSERVICE_SUCCESS) {
          xilDisplayException(pXILUtils);
          return;
        }                              /* if */

        if (IOBufferPtr->data != NULL) {
          mxMemUnitPtr = (uint8_T *) IOBufferPtr->data;

          /* write command id */
          *mxMemUnitPtr = 0;
          mxMemUnitPtr++;

          {
            uint8_T * simDataMemUnitPtr;
            uint32_T commandDataFcnid = 0;
            simDataMemUnitPtr = (uint8_T *) &commandDataFcnid;

            {
              size_t num_elements = 1;
              size_t bytes_consumed = num_elements * sizeof(uint32_T);
              memcpy((void *) mxMemUnitPtr, (void *) simDataMemUnitPtr,
                     bytes_consumed);
              mxMemUnitPtr+=(bytes_consumed/sizeof(*mxMemUnitPtr));
            }
          }

          {
            int errorOccurred;
            errorOccurred = commandDispatch(IOBufferPtr, 5, &dataInSize);
            if (errorOccurred) {
              return;
            }                          /* if */
          }

          if (dataInSize > 0) {
            size_t dataInMemUnitSize = dataInSize;
            uint8_T responseId;
            uint8_T * mxMemUnitPtrEnd;

#define RESPONSE_ERROR                 0
#define RESPONSE_PRINTF                2
#define RESPONSE_FOPEN                 3
#define RESPONSE_FPRINTF               4
#define TARGET_IO_SUCCESS              0
#define RESPONSE_TYPE_SIZE             5

            mxMemUnitPtr = (uint8_T *) IOBufferPtr->data;
            mxMemUnitPtrEnd = mxMemUnitPtr + dataInMemUnitSize - 1;
            while (mxMemUnitPtr <= mxMemUnitPtrEnd) {
              /* read response id */
              responseId = *mxMemUnitPtr;
              mxMemUnitPtr++;
              switch (responseId) {
               case RESPONSE_ERROR:
                {
                  uint8_T errorId = *mxMemUnitPtr;
                  mxMemUnitPtr++;
                  if (errorId) {
                    {
                      mxArray * prhs[ 2 ];
                      prhs[0] = mxCreateString("PIL:pilverification:PILError");
                      prhs[1] = mxCreateDoubleScalar(errorId);
                      callMATLAB( 0, NULL, 2, prhs, "DAStudio.error", 0);
                      return;
                    }
                  }                    /* if */
                  break;
                }

               case RESPONSE_PRINTF:
                {
                  uint8_T PRINTF_ERROR;
                  uint16_T PRINTF_SIZE;

                  {
                    uint8_T * simDataMemUnitPtr;
                    simDataMemUnitPtr = (uint8_T *) &PRINTF_ERROR;

                    {
                      size_t num_elements = 1;
                      size_t bytes_consumed = num_elements * sizeof(uint8_T);
                      memcpy((void *) simDataMemUnitPtr, (void *) mxMemUnitPtr,
                             bytes_consumed);
                      mxMemUnitPtr+=(bytes_consumed/sizeof(*mxMemUnitPtr));
                    }
                  }

                  {
                    uint8_T * simDataMemUnitPtr;
                    simDataMemUnitPtr = (uint8_T *) &PRINTF_SIZE;

                    {
                      size_t num_elements = 1;
                      size_t bytes_consumed = num_elements * sizeof(uint16_T);
                      memcpy((void *) simDataMemUnitPtr, (void *) mxMemUnitPtr,
                             bytes_consumed);
                      mxMemUnitPtr+=(bytes_consumed/sizeof(*mxMemUnitPtr));
                    }
                  }

                  if (PRINTF_ERROR != TARGET_IO_SUCCESS) {
                    {
                      mxArray * prhs[ 2 ];
                      prhs[0] = mxCreateString("PIL:pil:TargetIOError");
                      prhs[1] = mxCreateDoubleScalar(PRINTF_ERROR);
                      callMATLAB( 0, NULL, 2, prhs, "DAStudio.error", 0);
                      return;
                    }
                  } else {
                    uint8_T *pPrintBuff;
                    pPrintBuff = mxMemUnitPtr;
                    if (pPrintBuff[PRINTF_SIZE-1] == '\0') {
                      mexPrintf("%s", pPrintBuff);
                    }                  /* if */
                  }                    /* if */

                  mxMemUnitPtr = mxMemUnitPtr + PRINTF_SIZE;
                  break;
                }

               case RESPONSE_FOPEN:
                {
                  uint16_T FOPEN_FID;
                  uint16_T FOPEN_NAME_SIZE;

                  {
                    uint8_T * simDataMemUnitPtr;
                    simDataMemUnitPtr = (uint8_T *) &FOPEN_FID;

                    {
                      size_t num_elements = 1;
                      size_t bytes_consumed = num_elements * sizeof(uint16_T);
                      memcpy((void *) simDataMemUnitPtr, (void *) mxMemUnitPtr,
                             bytes_consumed);
                      mxMemUnitPtr+=(bytes_consumed/sizeof(*mxMemUnitPtr));
                    }
                  }

                  {
                    uint8_T * simDataMemUnitPtr;
                    simDataMemUnitPtr = (uint8_T *) &FOPEN_NAME_SIZE;

                    {
                      size_t num_elements = 1;
                      size_t bytes_consumed = num_elements * sizeof(uint16_T);
                      memcpy((void *) simDataMemUnitPtr, (void *) mxMemUnitPtr,
                             bytes_consumed);
                      mxMemUnitPtr+=(bytes_consumed/sizeof(*mxMemUnitPtr));
                    }
                  }

                  if (targetIOFdPtr != NULL) {
                    /* check fid increments by 1 */
                    if (targetIOFdPtr->fidOffset + 1 == FOPEN_FID) {
                      targetIOFdPtr->fidOffset = FOPEN_FID;
                      growTargetIOFd(targetIOFdPtr, targetIOFdPtr->fidOffset + 1);
                      if (targetIOFdPtr->Fd != NULL) {
                        uint8_T *pFopenBuff;
                        targetIOFdPtr->Fd[targetIOFdPtr->fidOffset] = NULL;
                        pFopenBuff = mxMemUnitPtr;
                        if (pFopenBuff[FOPEN_NAME_SIZE-1] == '\0') {
                          FILE * tmpFd = NULL;
                          tmpFd = fopen((char *) pFopenBuff,"w");
                          if (tmpFd != NULL) {
                            /* save the file descriptor */
                            targetIOFdPtr->Fd[targetIOFdPtr->fidOffset] = tmpFd;
                          } else {
                            {
                              mxArray * prhs[ 2 ];
                              prhs[0] = mxCreateString(
                                "PIL:pil:TargetIOFopenError");
                              prhs[1] = mxCreateString((char *) pFopenBuff);
                              callMATLAB( 0, NULL, 2, prhs, "DAStudio.error", 0);
                              return;
                            }
                          }            /* if */
                        }              /* if */
                      }                /* if */
                    } else {
                      {
                        mxArray * prhs[ 2 ];
                        prhs[0] = mxCreateString("PIL:pil:TargetIOFopenFidError");
                        prhs[1] = mxCreateDoubleScalar(FOPEN_FID);
                        callMATLAB( 0, NULL, 2, prhs, "DAStudio.error", 0);
                        return;
                      }
                    }                  /* if */
                  }                    /* if */

                  mxMemUnitPtr = mxMemUnitPtr + FOPEN_NAME_SIZE;
                  break;
                }

               case RESPONSE_FPRINTF:
                {
                  uint8_T FPRINTF_ERROR;
                  uint16_T FPRINTF_FID;
                  uint16_T FPRINTF_SIZE;

                  {
                    uint8_T * simDataMemUnitPtr;
                    simDataMemUnitPtr = (uint8_T *) &FPRINTF_ERROR;

                    {
                      size_t num_elements = 1;
                      size_t bytes_consumed = num_elements * sizeof(uint8_T);
                      memcpy((void *) simDataMemUnitPtr, (void *) mxMemUnitPtr,
                             bytes_consumed);
                      mxMemUnitPtr+=(bytes_consumed/sizeof(*mxMemUnitPtr));
                    }
                  }

                  {
                    uint8_T * simDataMemUnitPtr;
                    simDataMemUnitPtr = (uint8_T *) &FPRINTF_FID;

                    {
                      size_t num_elements = 1;
                      size_t bytes_consumed = num_elements * sizeof(uint16_T);
                      memcpy((void *) simDataMemUnitPtr, (void *) mxMemUnitPtr,
                             bytes_consumed);
                      mxMemUnitPtr+=(bytes_consumed/sizeof(*mxMemUnitPtr));
                    }
                  }

                  {
                    uint8_T * simDataMemUnitPtr;
                    simDataMemUnitPtr = (uint8_T *) &FPRINTF_SIZE;

                    {
                      size_t num_elements = 1;
                      size_t bytes_consumed = num_elements * sizeof(uint16_T);
                      memcpy((void *) simDataMemUnitPtr, (void *) mxMemUnitPtr,
                             bytes_consumed);
                      mxMemUnitPtr+=(bytes_consumed/sizeof(*mxMemUnitPtr));
                    }
                  }

                  if (FPRINTF_ERROR != TARGET_IO_SUCCESS) {
                    {
                      mxArray * prhs[ 2 ];
                      prhs[0] = mxCreateString("PIL:pil:TargetIOError");
                      prhs[1] = mxCreateDoubleScalar(FPRINTF_ERROR);
                      callMATLAB( 0, NULL, 2, prhs, "DAStudio.error", 0);
                      return;
                    }
                  } else {
                    if (targetIOFdPtr != NULL) {
                      if (targetIOFdPtr->size > FPRINTF_FID) {
                        if (targetIOFdPtr->Fd[FPRINTF_FID] != NULL) {
                          uint8_T *pFprintfBuff;
                          pFprintfBuff = mxMemUnitPtr;
                          if (pFprintfBuff[FPRINTF_SIZE-1] == '\0') {
                            fprintf(targetIOFdPtr->Fd[FPRINTF_FID], "%s",
                                    pFprintfBuff);
                          }            /* if */
                        }              /* if */
                      }                /* if */
                    }                  /* if */
                  }                    /* if */

                  mxMemUnitPtr = mxMemUnitPtr + FPRINTF_SIZE;
                  break;
                }

               case RESPONSE_TYPE_SIZE:
                {
                  uint8_T typeId = *mxMemUnitPtr;
                  uint8_T typeBytes;
                  mxMemUnitPtr++;
                  typeBytes = *mxMemUnitPtr;
                  mxMemUnitPtr++;
                  switch (typeId) {
                   case mxSINGLE_CLASS:
                    {
                      if (typeBytes != 4) {
                        {
                          mxArray * prhs[ 3 ];
                          prhs[0] = mxCreateString(
                            "PIL:pilverification:SingleUnsupported");
                          prhs[1] = mxCreateDoubleScalar(4);
                          prhs[2] = mxCreateDoubleScalar(typeBytes);
                          callMATLAB( 0, NULL, 3, prhs, "DAStudio.error", 0);
                          return;
                        }
                      }                /* if */
                      break;
                    }

                   case mxDOUBLE_CLASS:
                    {
                      if (typeBytes != 8) {
                        {
                          mxArray * prhs[ 3 ];
                          prhs[0] = mxCreateString(
                            "PIL:pilverification:DoubleUnsupported");
                          prhs[1] = mxCreateDoubleScalar(8);
                          prhs[2] = mxCreateDoubleScalar(typeBytes);
                          callMATLAB( 0, NULL, 3, prhs, "DAStudio.error", 0);
                          return;
                        }
                      }                /* if */
                      break;
                    }

                   default:
                    {
                      {
                        mxArray * prhs[ 2 ];
                        prhs[0] = mxCreateString(
                          "PIL:pilverification:UnknownTypeId");
                        prhs[1] = mxCreateDoubleScalar(typeId);
                        callMATLAB( 0, NULL, 2, prhs, "DAStudio.error", 0);
                        return;
                      }
                      break;
                    }
                  }                    /* switch */
                  break;
                }

               default:
                {
                  {
                    mxArray * prhs[ 2 ];
                    prhs[0] = mxCreateString(
                      "PIL:pilverification:UnknownResponseId");
                    prhs[1] = mxCreateDoubleScalar(responseId);
                    callMATLAB( 0, NULL, 2, prhs, "DAStudio.error", 0);
                    return;
                  }
                  break;
                }
              }                        /* switch */
            }                          /* while */
          }                            /* if */
        }                              /* if */
      }                                /* if */
    }                                  /* if */
  }

  {
    uint8_T * mxMemUnitPtr;
    mwSize dataInSize = 0;
    if (IOBufferPtr != NULL) {
      if (pXILService != NULL) {
        if (xilServiceGrowIOBuffer(pXILService, IOBufferPtr, 5, 0)!=
            XILSERVICE_SUCCESS) {
          xilDisplayException(pXILUtils);
          return;
        }                              /* if */

        if (IOBufferPtr->data != NULL) {
          mxMemUnitPtr = (uint8_T *) IOBufferPtr->data;

          /* write command id */
          *mxMemUnitPtr = 1;
          mxMemUnitPtr++;

          {
            uint8_T * simDataMemUnitPtr;
            uint32_T commandDataFcnid = 0;
            simDataMemUnitPtr = (uint8_T *) &commandDataFcnid;

            {
              size_t num_elements = 1;
              size_t bytes_consumed = num_elements * sizeof(uint32_T);
              memcpy((void *) mxMemUnitPtr, (void *) simDataMemUnitPtr,
                     bytes_consumed);
              mxMemUnitPtr+=(bytes_consumed/sizeof(*mxMemUnitPtr));
            }
          }

          {
            int errorOccurred;
            errorOccurred = commandDispatch(IOBufferPtr, 5, &dataInSize);
            if (errorOccurred) {
              return;
            }                          /* if */
          }

          if (dataInSize > 0) {
            size_t dataInMemUnitSize = dataInSize;
            uint8_T responseId;
            uint8_T * mxMemUnitPtrEnd;

#define RESPONSE_ERROR                 0
#define RESPONSE_PRINTF                2
#define RESPONSE_FOPEN                 3
#define RESPONSE_FPRINTF               4
#define TARGET_IO_SUCCESS              0

            mxMemUnitPtr = (uint8_T *) IOBufferPtr->data;
            mxMemUnitPtrEnd = mxMemUnitPtr + dataInMemUnitSize - 1;
            while (mxMemUnitPtr <= mxMemUnitPtrEnd) {
              /* read response id */
              responseId = *mxMemUnitPtr;
              mxMemUnitPtr++;
              switch (responseId) {
               case RESPONSE_ERROR:
                {
                  uint8_T errorId = *mxMemUnitPtr;
                  mxMemUnitPtr++;
                  if (errorId) {
                    {
                      mxArray * prhs[ 2 ];
                      prhs[0] = mxCreateString("PIL:pilverification:PILError");
                      prhs[1] = mxCreateDoubleScalar(errorId);
                      callMATLAB( 0, NULL, 2, prhs, "DAStudio.error", 0);
                      return;
                    }
                  }                    /* if */
                  break;
                }

               case RESPONSE_PRINTF:
                {
                  uint8_T PRINTF_ERROR;
                  uint16_T PRINTF_SIZE;

                  {
                    uint8_T * simDataMemUnitPtr;
                    simDataMemUnitPtr = (uint8_T *) &PRINTF_ERROR;

                    {
                      size_t num_elements = 1;
                      size_t bytes_consumed = num_elements * sizeof(uint8_T);
                      memcpy((void *) simDataMemUnitPtr, (void *) mxMemUnitPtr,
                             bytes_consumed);
                      mxMemUnitPtr+=(bytes_consumed/sizeof(*mxMemUnitPtr));
                    }
                  }

                  {
                    uint8_T * simDataMemUnitPtr;
                    simDataMemUnitPtr = (uint8_T *) &PRINTF_SIZE;

                    {
                      size_t num_elements = 1;
                      size_t bytes_consumed = num_elements * sizeof(uint16_T);
                      memcpy((void *) simDataMemUnitPtr, (void *) mxMemUnitPtr,
                             bytes_consumed);
                      mxMemUnitPtr+=(bytes_consumed/sizeof(*mxMemUnitPtr));
                    }
                  }

                  if (PRINTF_ERROR != TARGET_IO_SUCCESS) {
                    {
                      mxArray * prhs[ 2 ];
                      prhs[0] = mxCreateString("PIL:pil:TargetIOError");
                      prhs[1] = mxCreateDoubleScalar(PRINTF_ERROR);
                      callMATLAB( 0, NULL, 2, prhs, "DAStudio.error", 0);
                      return;
                    }
                  } else {
                    uint8_T *pPrintBuff;
                    pPrintBuff = mxMemUnitPtr;
                    if (pPrintBuff[PRINTF_SIZE-1] == '\0') {
                      mexPrintf("%s", pPrintBuff);
                    }                  /* if */
                  }                    /* if */

                  mxMemUnitPtr = mxMemUnitPtr + PRINTF_SIZE;
                  break;
                }

               case RESPONSE_FOPEN:
                {
                  uint16_T FOPEN_FID;
                  uint16_T FOPEN_NAME_SIZE;

                  {
                    uint8_T * simDataMemUnitPtr;
                    simDataMemUnitPtr = (uint8_T *) &FOPEN_FID;

                    {
                      size_t num_elements = 1;
                      size_t bytes_consumed = num_elements * sizeof(uint16_T);
                      memcpy((void *) simDataMemUnitPtr, (void *) mxMemUnitPtr,
                             bytes_consumed);
                      mxMemUnitPtr+=(bytes_consumed/sizeof(*mxMemUnitPtr));
                    }
                  }

                  {
                    uint8_T * simDataMemUnitPtr;
                    simDataMemUnitPtr = (uint8_T *) &FOPEN_NAME_SIZE;

                    {
                      size_t num_elements = 1;
                      size_t bytes_consumed = num_elements * sizeof(uint16_T);
                      memcpy((void *) simDataMemUnitPtr, (void *) mxMemUnitPtr,
                             bytes_consumed);
                      mxMemUnitPtr+=(bytes_consumed/sizeof(*mxMemUnitPtr));
                    }
                  }

                  if (targetIOFdPtr != NULL) {
                    /* check fid increments by 1 */
                    if (targetIOFdPtr->fidOffset + 1 == FOPEN_FID) {
                      targetIOFdPtr->fidOffset = FOPEN_FID;
                      growTargetIOFd(targetIOFdPtr, targetIOFdPtr->fidOffset + 1);
                      if (targetIOFdPtr->Fd != NULL) {
                        uint8_T *pFopenBuff;
                        targetIOFdPtr->Fd[targetIOFdPtr->fidOffset] = NULL;
                        pFopenBuff = mxMemUnitPtr;
                        if (pFopenBuff[FOPEN_NAME_SIZE-1] == '\0') {
                          FILE * tmpFd = NULL;
                          tmpFd = fopen((char *) pFopenBuff,"w");
                          if (tmpFd != NULL) {
                            /* save the file descriptor */
                            targetIOFdPtr->Fd[targetIOFdPtr->fidOffset] = tmpFd;
                          } else {
                            {
                              mxArray * prhs[ 2 ];
                              prhs[0] = mxCreateString(
                                "PIL:pil:TargetIOFopenError");
                              prhs[1] = mxCreateString((char *) pFopenBuff);
                              callMATLAB( 0, NULL, 2, prhs, "DAStudio.error", 0);
                              return;
                            }
                          }            /* if */
                        }              /* if */
                      }                /* if */
                    } else {
                      {
                        mxArray * prhs[ 2 ];
                        prhs[0] = mxCreateString("PIL:pil:TargetIOFopenFidError");
                        prhs[1] = mxCreateDoubleScalar(FOPEN_FID);
                        callMATLAB( 0, NULL, 2, prhs, "DAStudio.error", 0);
                        return;
                      }
                    }                  /* if */
                  }                    /* if */

                  mxMemUnitPtr = mxMemUnitPtr + FOPEN_NAME_SIZE;
                  break;
                }

               case RESPONSE_FPRINTF:
                {
                  uint8_T FPRINTF_ERROR;
                  uint16_T FPRINTF_FID;
                  uint16_T FPRINTF_SIZE;

                  {
                    uint8_T * simDataMemUnitPtr;
                    simDataMemUnitPtr = (uint8_T *) &FPRINTF_ERROR;

                    {
                      size_t num_elements = 1;
                      size_t bytes_consumed = num_elements * sizeof(uint8_T);
                      memcpy((void *) simDataMemUnitPtr, (void *) mxMemUnitPtr,
                             bytes_consumed);
                      mxMemUnitPtr+=(bytes_consumed/sizeof(*mxMemUnitPtr));
                    }
                  }

                  {
                    uint8_T * simDataMemUnitPtr;
                    simDataMemUnitPtr = (uint8_T *) &FPRINTF_FID;

                    {
                      size_t num_elements = 1;
                      size_t bytes_consumed = num_elements * sizeof(uint16_T);
                      memcpy((void *) simDataMemUnitPtr, (void *) mxMemUnitPtr,
                             bytes_consumed);
                      mxMemUnitPtr+=(bytes_consumed/sizeof(*mxMemUnitPtr));
                    }
                  }

                  {
                    uint8_T * simDataMemUnitPtr;
                    simDataMemUnitPtr = (uint8_T *) &FPRINTF_SIZE;

                    {
                      size_t num_elements = 1;
                      size_t bytes_consumed = num_elements * sizeof(uint16_T);
                      memcpy((void *) simDataMemUnitPtr, (void *) mxMemUnitPtr,
                             bytes_consumed);
                      mxMemUnitPtr+=(bytes_consumed/sizeof(*mxMemUnitPtr));
                    }
                  }

                  if (FPRINTF_ERROR != TARGET_IO_SUCCESS) {
                    {
                      mxArray * prhs[ 2 ];
                      prhs[0] = mxCreateString("PIL:pil:TargetIOError");
                      prhs[1] = mxCreateDoubleScalar(FPRINTF_ERROR);
                      callMATLAB( 0, NULL, 2, prhs, "DAStudio.error", 0);
                      return;
                    }
                  } else {
                    if (targetIOFdPtr != NULL) {
                      if (targetIOFdPtr->size > FPRINTF_FID) {
                        if (targetIOFdPtr->Fd[FPRINTF_FID] != NULL) {
                          uint8_T *pFprintfBuff;
                          pFprintfBuff = mxMemUnitPtr;
                          if (pFprintfBuff[FPRINTF_SIZE-1] == '\0') {
                            fprintf(targetIOFdPtr->Fd[FPRINTF_FID], "%s",
                                    pFprintfBuff);
                          }            /* if */
                        }              /* if */
                      }                /* if */
                    }                  /* if */
                  }                    /* if */

                  mxMemUnitPtr = mxMemUnitPtr + FPRINTF_SIZE;
                  break;
                }

               default:
                {
                  {
                    mxArray * prhs[ 2 ];
                    prhs[0] = mxCreateString(
                      "PIL:pilverification:UnknownResponseId");
                    prhs[1] = mxCreateDoubleScalar(responseId);
                    callMATLAB( 0, NULL, 2, prhs, "DAStudio.error", 0);
                    return;
                  }
                  break;
                }
              }                        /* switch */
            }                          /* while */
          }                            /* if */
        }                              /* if */
      }                                /* if */
    }                                  /* if */
  }
}

#endif                                 /* MDL_START */

void Add( double arr[5], double b, double out[5] )
{
  if (!firstTime) {
    firstTime = 1;
    mdlInitializeSizes();
    mdlStart();
  }                                    /* if */

  {
    uint8_T * mxMemUnitPtr;
    mwSize dataInSize = 0;
    if (IOBufferPtr != NULL) {
      if (pXILService != NULL) {
        if (xilServiceGrowIOBuffer(pXILService, IOBufferPtr, 57, 0)!=
            XILSERVICE_SUCCESS) {
          xilDisplayException(pXILUtils);
          return;
        }                              /* if */

        if (IOBufferPtr->data != NULL) {
          mxMemUnitPtr = (uint8_T *) IOBufferPtr->data;

          /* write command id */
          *mxMemUnitPtr = 3;
          mxMemUnitPtr++;

          {
            uint8_T * simDataMemUnitPtr;
            uint32_T commandDataFcnidTID[2] = { 0, 1 };

            simDataMemUnitPtr = (uint8_T *) &commandDataFcnidTID[0];

            {
              size_t num_elements = 2;
              size_t bytes_consumed = num_elements * sizeof(uint32_T);
              memcpy((void *) mxMemUnitPtr, (void *) simDataMemUnitPtr,
                     bytes_consumed);
              mxMemUnitPtr+=(bytes_consumed/sizeof(*mxMemUnitPtr));
            }
          }

          {
            uint8_T * simDataMemUnitPtr;
            simDataMemUnitPtr = ( uint8_T *) &(arr[0]);

            {
              size_t num_elements = 5;
              size_t bytes_consumed = num_elements * sizeof(real64_T);
              memcpy((void *) mxMemUnitPtr, (void *) simDataMemUnitPtr,
                     bytes_consumed);
              mxMemUnitPtr+=(bytes_consumed/sizeof(*mxMemUnitPtr));
            }
          }

          {
            uint8_T * simDataMemUnitPtr;
            simDataMemUnitPtr = ( uint8_T *) &(b);

            {
              size_t num_elements = 1;
              size_t bytes_consumed = num_elements * sizeof(real64_T);
              memcpy((void *) mxMemUnitPtr, (void *) simDataMemUnitPtr,
                     bytes_consumed);
              mxMemUnitPtr+=(bytes_consumed/sizeof(*mxMemUnitPtr));
            }
          }

          {
            int errorOccurred;
            errorOccurred = commandDispatch(IOBufferPtr, 57, &dataInSize);
            if (errorOccurred) {
              return;
            }                          /* if */
          }

          if (dataInSize > 0) {
            size_t dataInMemUnitSize = dataInSize;
            uint8_T responseId;
            uint8_T * mxMemUnitPtrEnd;

#define RESPONSE_ERROR                 0
#define RESPONSE_OUTPUT_DATA           1
#define RESPONSE_PRINTF                2
#define RESPONSE_FOPEN                 3
#define RESPONSE_FPRINTF               4
#define TARGET_IO_SUCCESS              0

            mxMemUnitPtr = (uint8_T *) IOBufferPtr->data;
            mxMemUnitPtrEnd = mxMemUnitPtr + dataInMemUnitSize - 1;
            while (mxMemUnitPtr <= mxMemUnitPtrEnd) {
              /* read response id */
              responseId = *mxMemUnitPtr;
              mxMemUnitPtr++;
              switch (responseId) {
               case RESPONSE_ERROR:
                {
                  uint8_T errorId = *mxMemUnitPtr;
                  mxMemUnitPtr++;
                  if (errorId) {
                    {
                      mxArray * prhs[ 2 ];
                      prhs[0] = mxCreateString("PIL:pilverification:PILError");
                      prhs[1] = mxCreateDoubleScalar(errorId);
                      callMATLAB( 0, NULL, 2, prhs, "DAStudio.error", 0);
                      return;
                    }
                  }                    /* if */
                  break;
                }

               case RESPONSE_PRINTF:
                {
                  uint8_T PRINTF_ERROR;
                  uint16_T PRINTF_SIZE;

                  {
                    uint8_T * simDataMemUnitPtr;
                    simDataMemUnitPtr = (uint8_T *) &PRINTF_ERROR;

                    {
                      size_t num_elements = 1;
                      size_t bytes_consumed = num_elements * sizeof(uint8_T);
                      memcpy((void *) simDataMemUnitPtr, (void *) mxMemUnitPtr,
                             bytes_consumed);
                      mxMemUnitPtr+=(bytes_consumed/sizeof(*mxMemUnitPtr));
                    }
                  }

                  {
                    uint8_T * simDataMemUnitPtr;
                    simDataMemUnitPtr = (uint8_T *) &PRINTF_SIZE;

                    {
                      size_t num_elements = 1;
                      size_t bytes_consumed = num_elements * sizeof(uint16_T);
                      memcpy((void *) simDataMemUnitPtr, (void *) mxMemUnitPtr,
                             bytes_consumed);
                      mxMemUnitPtr+=(bytes_consumed/sizeof(*mxMemUnitPtr));
                    }
                  }

                  if (PRINTF_ERROR != TARGET_IO_SUCCESS) {
                    {
                      mxArray * prhs[ 2 ];
                      prhs[0] = mxCreateString("PIL:pil:TargetIOError");
                      prhs[1] = mxCreateDoubleScalar(PRINTF_ERROR);
                      callMATLAB( 0, NULL, 2, prhs, "DAStudio.error", 0);
                      return;
                    }
                  } else {
                    uint8_T *pPrintBuff;
                    pPrintBuff = mxMemUnitPtr;
                    if (pPrintBuff[PRINTF_SIZE-1] == '\0') {
                      mexPrintf("%s", pPrintBuff);
                    }                  /* if */
                  }                    /* if */

                  mxMemUnitPtr = mxMemUnitPtr + PRINTF_SIZE;
                  break;
                }

               case RESPONSE_FOPEN:
                {
                  uint16_T FOPEN_FID;
                  uint16_T FOPEN_NAME_SIZE;

                  {
                    uint8_T * simDataMemUnitPtr;
                    simDataMemUnitPtr = (uint8_T *) &FOPEN_FID;

                    {
                      size_t num_elements = 1;
                      size_t bytes_consumed = num_elements * sizeof(uint16_T);
                      memcpy((void *) simDataMemUnitPtr, (void *) mxMemUnitPtr,
                             bytes_consumed);
                      mxMemUnitPtr+=(bytes_consumed/sizeof(*mxMemUnitPtr));
                    }
                  }

                  {
                    uint8_T * simDataMemUnitPtr;
                    simDataMemUnitPtr = (uint8_T *) &FOPEN_NAME_SIZE;

                    {
                      size_t num_elements = 1;
                      size_t bytes_consumed = num_elements * sizeof(uint16_T);
                      memcpy((void *) simDataMemUnitPtr, (void *) mxMemUnitPtr,
                             bytes_consumed);
                      mxMemUnitPtr+=(bytes_consumed/sizeof(*mxMemUnitPtr));
                    }
                  }

                  if (targetIOFdPtr != NULL) {
                    /* check fid increments by 1 */
                    if (targetIOFdPtr->fidOffset + 1 == FOPEN_FID) {
                      targetIOFdPtr->fidOffset = FOPEN_FID;
                      growTargetIOFd(targetIOFdPtr, targetIOFdPtr->fidOffset + 1);
                      if (targetIOFdPtr->Fd != NULL) {
                        uint8_T *pFopenBuff;
                        targetIOFdPtr->Fd[targetIOFdPtr->fidOffset] = NULL;
                        pFopenBuff = mxMemUnitPtr;
                        if (pFopenBuff[FOPEN_NAME_SIZE-1] == '\0') {
                          FILE * tmpFd = NULL;
                          tmpFd = fopen((char *) pFopenBuff,"w");
                          if (tmpFd != NULL) {
                            /* save the file descriptor */
                            targetIOFdPtr->Fd[targetIOFdPtr->fidOffset] = tmpFd;
                          } else {
                            {
                              mxArray * prhs[ 2 ];
                              prhs[0] = mxCreateString(
                                "PIL:pil:TargetIOFopenError");
                              prhs[1] = mxCreateString((char *) pFopenBuff);
                              callMATLAB( 0, NULL, 2, prhs, "DAStudio.error", 0);
                              return;
                            }
                          }            /* if */
                        }              /* if */
                      }                /* if */
                    } else {
                      {
                        mxArray * prhs[ 2 ];
                        prhs[0] = mxCreateString("PIL:pil:TargetIOFopenFidError");
                        prhs[1] = mxCreateDoubleScalar(FOPEN_FID);
                        callMATLAB( 0, NULL, 2, prhs, "DAStudio.error", 0);
                        return;
                      }
                    }                  /* if */
                  }                    /* if */

                  mxMemUnitPtr = mxMemUnitPtr + FOPEN_NAME_SIZE;
                  break;
                }

               case RESPONSE_FPRINTF:
                {
                  uint8_T FPRINTF_ERROR;
                  uint16_T FPRINTF_FID;
                  uint16_T FPRINTF_SIZE;

                  {
                    uint8_T * simDataMemUnitPtr;
                    simDataMemUnitPtr = (uint8_T *) &FPRINTF_ERROR;

                    {
                      size_t num_elements = 1;
                      size_t bytes_consumed = num_elements * sizeof(uint8_T);
                      memcpy((void *) simDataMemUnitPtr, (void *) mxMemUnitPtr,
                             bytes_consumed);
                      mxMemUnitPtr+=(bytes_consumed/sizeof(*mxMemUnitPtr));
                    }
                  }

                  {
                    uint8_T * simDataMemUnitPtr;
                    simDataMemUnitPtr = (uint8_T *) &FPRINTF_FID;

                    {
                      size_t num_elements = 1;
                      size_t bytes_consumed = num_elements * sizeof(uint16_T);
                      memcpy((void *) simDataMemUnitPtr, (void *) mxMemUnitPtr,
                             bytes_consumed);
                      mxMemUnitPtr+=(bytes_consumed/sizeof(*mxMemUnitPtr));
                    }
                  }

                  {
                    uint8_T * simDataMemUnitPtr;
                    simDataMemUnitPtr = (uint8_T *) &FPRINTF_SIZE;

                    {
                      size_t num_elements = 1;
                      size_t bytes_consumed = num_elements * sizeof(uint16_T);
                      memcpy((void *) simDataMemUnitPtr, (void *) mxMemUnitPtr,
                             bytes_consumed);
                      mxMemUnitPtr+=(bytes_consumed/sizeof(*mxMemUnitPtr));
                    }
                  }

                  if (FPRINTF_ERROR != TARGET_IO_SUCCESS) {
                    {
                      mxArray * prhs[ 2 ];
                      prhs[0] = mxCreateString("PIL:pil:TargetIOError");
                      prhs[1] = mxCreateDoubleScalar(FPRINTF_ERROR);
                      callMATLAB( 0, NULL, 2, prhs, "DAStudio.error", 0);
                      return;
                    }
                  } else {
                    if (targetIOFdPtr != NULL) {
                      if (targetIOFdPtr->size > FPRINTF_FID) {
                        if (targetIOFdPtr->Fd[FPRINTF_FID] != NULL) {
                          uint8_T *pFprintfBuff;
                          pFprintfBuff = mxMemUnitPtr;
                          if (pFprintfBuff[FPRINTF_SIZE-1] == '\0') {
                            fprintf(targetIOFdPtr->Fd[FPRINTF_FID], "%s",
                                    pFprintfBuff);
                          }            /* if */
                        }              /* if */
                      }                /* if */
                    }                  /* if */
                  }                    /* if */

                  mxMemUnitPtr = mxMemUnitPtr + FPRINTF_SIZE;
                  break;
                }

               case RESPONSE_OUTPUT_DATA:
                {
                  {
                    uint8_T * simDataMemUnitPtr;
                    simDataMemUnitPtr = ( uint8_T *) &(out[0]);

                    {
                      size_t num_elements = 5;
                      size_t bytes_consumed = num_elements * sizeof(real64_T);
                      memcpy((void *) simDataMemUnitPtr, (void *) mxMemUnitPtr,
                             bytes_consumed);
                      mxMemUnitPtr+=(bytes_consumed/sizeof(*mxMemUnitPtr));
                    }
                  }
                  break;
                }

               default:
                {
                  {
                    mxArray * prhs[ 2 ];
                    prhs[0] = mxCreateString(
                      "PIL:pilverification:UnknownResponseId");
                    prhs[1] = mxCreateDoubleScalar(responseId);
                    callMATLAB( 0, NULL, 2, prhs, "DAStudio.error", 0);
                    return;
                  }
                  break;
                }
              }                        /* switch */
            }                          /* while */
          }                            /* if */
        }                              /* if */
      }                                /* if */
    }                                  /* if */
  }
}

void Add_xil_terminate()
{
  int isOkToTerminate;
  int commErrorOccurred = 0;

  {
    if (pCommErrorOccurred != NULL) {
      commErrorOccurred = *pCommErrorOccurred;
    }                                  /* if */
  }

  {
    {
      mxArray *rhs[3];
      mxArray *lhs[1];
      const char * simulinkBlockPath =
        "D:\\GitHub\\Monophonic-Pitch-Tracking\\SimpleTest\\codegen\\dll\\Add\\Add";
      rhs[ 0 ] = mxCreateString(
        "@coder.connectivity.MATLABInterface.getSILPILInterface");
      rhs[ 1 ] = mxCreateDoubleScalar( 3 );
      rhs[ 2 ] = mxCreateString(simulinkBlockPath);
      callMATLAB( 1, lhs, 3, rhs,
                 "rtw.pil.SILPILInterface.sfunctionIsOkToTerminateHook", 0);
      isOkToTerminate = (int) (*mxGetPr(lhs[0]));
      mxDestroyArray(lhs[0]);
    }
  }

  if (isOkToTerminate) {
    if (!commErrorOccurred) {
      {
        uint8_T * mxMemUnitPtr;
        mwSize dataInSize = 0;
        if (IOBufferPtr != NULL) {
          if (pXILService != NULL) {
            if (xilServiceGrowIOBuffer(pXILService, IOBufferPtr, 5, 0)!=
                XILSERVICE_SUCCESS) {
              xilDisplayException(pXILUtils);
            }                          /* if */

            if (IOBufferPtr->data != NULL) {
              mxMemUnitPtr = (uint8_T *) IOBufferPtr->data;

              /* write command id */
              *mxMemUnitPtr = 4;
              mxMemUnitPtr++;

              {
                uint8_T * simDataMemUnitPtr;
                uint32_T commandDataFcnid = 0;
                simDataMemUnitPtr = (uint8_T *) &commandDataFcnid;

                {
                  size_t num_elements = 1;
                  size_t bytes_consumed = num_elements * sizeof(uint32_T);
                  memcpy((void *) mxMemUnitPtr, (void *) simDataMemUnitPtr,
                         bytes_consumed);
                  mxMemUnitPtr+=(bytes_consumed/sizeof(*mxMemUnitPtr));
                }
              }

              {
                int errorOccurred;
                errorOccurred = commandDispatch(IOBufferPtr, 5, &dataInSize);
                if (errorOccurred) {
                  /* continue */
                }                      /* if */
              }
            }                          /* if */
          }                            /* if */
        }                              /* if */
      }
    }                                  /* if */

    closeAndFreeTargetIOFd();

    {
      {
        mxArray *rhs[3];
        const char * simulinkBlockPath =
          "D:\\GitHub\\Monophonic-Pitch-Tracking\\SimpleTest\\codegen\\dll\\Add\\Add";
        rhs[ 0 ] = mxCreateString(
          "@coder.connectivity.MATLABInterface.getSILPILInterface");
        rhs[ 1 ] = mxCreateDoubleScalar( 3 );
        rhs[ 2 ] = mxCreateString(simulinkBlockPath);
        callMATLAB( 0, NULL, 3, rhs,
                   "rtw.pil.SILPILInterface.sfunctionPILStopHook", 0);
      }
    }
  }                                    /* if */

  if (pCommErrorOccurred != NULL) {
    mxFree(pCommErrorOccurred);
  }                                    /* if */

  if (rtIOStreamDataPtr != NULL) {
    {
      int errorStatus = rtIOStreamUnloadLib(&rtIOStreamDataPtr->libH);
      if (errorStatus) {
        mexErrMsgTxt( "rtIOStreamUnloadLib failed.");
      }                                /* if */
    }

    mxFree(rtIOStreamDataPtr->lib);
    mxDestroyArray(rtIOStreamDataPtr->MATLABObject);
    mxFree(rtIOStreamDataPtr);
  }                                    /* if */

  if (silDebuggingDataPtr != NULL) {
    mxFree(silDebuggingDataPtr->componentBlockPath);
    mxFree(silDebuggingDataPtr->SILPILInterfaceFcnStr);
    mxFree(silDebuggingDataPtr);
  }                                    /* if */

  if (IOBufferPtr != NULL) {
    mxFree(IOBufferPtr->data);
    mxFree(IOBufferPtr);
  }                                    /* if */

  closeAndFreeTargetIOFd();
  if (pXILUtils != NULL) {
    xilUtilsDestroy(pXILUtils);
  }                                    /* if */

  if (pXILComms != NULL) {
    xilCommsDestroy(pXILComms);
  }                                    /* if */

  if (pXILService != NULL) {
    xilServiceDestroy(pXILService);
  }                                    /* if */
}
