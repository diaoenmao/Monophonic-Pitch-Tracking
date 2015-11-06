/*
 * yaapt_types.h
 *
 * Code generation for function 'yaapt'
 *
 */

#ifndef __YAAPT_TYPES_H__
#define __YAAPT_TYPES_H__

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef struct_emxArray__common
#define struct_emxArray__common
struct emxArray__common
{
    void *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};
#endif /*struct_emxArray__common*/
#ifndef typedef_emxArray__common
#define typedef_emxArray__common
typedef struct emxArray__common emxArray__common;
#endif /*typedef_emxArray__common*/
#ifndef struct_emxArray_b_real_T_1
#define struct_emxArray_b_real_T_1
struct emxArray_b_real_T_1
{
    real_T data[1];
    int32_T size[1];
};
#endif /*struct_emxArray_b_real_T_1*/
#ifndef typedef_emxArray_b_real_T_1
#define typedef_emxArray_b_real_T_1
typedef struct emxArray_b_real_T_1 emxArray_b_real_T_1;
#endif /*typedef_emxArray_b_real_T_1*/
#ifndef struct_emxArray_boolean_T
#define struct_emxArray_boolean_T
struct emxArray_boolean_T
{
    boolean_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};
#endif /*struct_emxArray_boolean_T*/
#ifndef typedef_emxArray_boolean_T
#define typedef_emxArray_boolean_T
typedef struct emxArray_boolean_T emxArray_boolean_T;
#endif /*typedef_emxArray_boolean_T*/
#ifndef struct_emxArray_creal_T
#define struct_emxArray_creal_T
struct emxArray_creal_T
{
    creal_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};
#endif /*struct_emxArray_creal_T*/
#ifndef typedef_emxArray_creal_T
#define typedef_emxArray_creal_T
typedef struct emxArray_creal_T emxArray_creal_T;
#endif /*typedef_emxArray_creal_T*/
#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T
struct emxArray_int32_T
{
    int32_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};
#endif /*struct_emxArray_int32_T*/
#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T
typedef struct emxArray_int32_T emxArray_int32_T;
#endif /*typedef_emxArray_int32_T*/
#ifndef struct_emxArray_int32_T_5776
#define struct_emxArray_int32_T_5776
struct emxArray_int32_T_5776
{
    int32_T data[5776];
    int32_T size[1];
};
#endif /*struct_emxArray_int32_T_5776*/
#ifndef typedef_emxArray_int32_T_5776
#define typedef_emxArray_int32_T_5776
typedef struct emxArray_int32_T_5776 emxArray_int32_T_5776;
#endif /*typedef_emxArray_int32_T_5776*/
#ifndef struct_emxArray_int32_T_75
#define struct_emxArray_int32_T_75
struct emxArray_int32_T_75
{
    int32_T data[75];
    int32_T size[1];
};
#endif /*struct_emxArray_int32_T_75*/
#ifndef typedef_emxArray_int32_T_75
#define typedef_emxArray_int32_T_75
typedef struct emxArray_int32_T_75 emxArray_int32_T_75;
#endif /*typedef_emxArray_int32_T_75*/
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T
{
    real_T *data;
    int32_T *size;
    int32_T allocatedSize;
    int32_T numDimensions;
    boolean_T canFreeData;
};
#endif /*struct_emxArray_real_T*/
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /*typedef_emxArray_real_T*/
#ifndef struct_emxArray_real_T_1
#define struct_emxArray_real_T_1
struct emxArray_real_T_1
{
    real_T data[1];
    int32_T size[1];
};
#endif /*struct_emxArray_real_T_1*/
#ifndef typedef_emxArray_real_T_1
#define typedef_emxArray_real_T_1
typedef struct emxArray_real_T_1 emxArray_real_T_1;
#endif /*typedef_emxArray_real_T_1*/
#ifndef struct_emxArray_real_T_1x15
#define struct_emxArray_real_T_1x15
struct emxArray_real_T_1x15
{
    real_T data[15];
    int32_T size[2];
};
#endif /*struct_emxArray_real_T_1x15*/
#ifndef typedef_emxArray_real_T_1x15
#define typedef_emxArray_real_T_1x15
typedef struct emxArray_real_T_1x15 emxArray_real_T_1x15;
#endif /*typedef_emxArray_real_T_1x15*/
#ifndef struct_emxArray_real_T_1x4097
#define struct_emxArray_real_T_1x4097
struct emxArray_real_T_1x4097
{
    real_T data[4097];
    int32_T size[2];
};
#endif /*struct_emxArray_real_T_1x4097*/
#ifndef typedef_emxArray_real_T_1x4097
#define typedef_emxArray_real_T_1x4097
typedef struct emxArray_real_T_1x4097 emxArray_real_T_1x4097;
#endif /*typedef_emxArray_real_T_1x4097*/
#ifndef typedef_yaaptStackData
#define typedef_yaaptStackData
typedef struct
{
    union
    {
        struct
        {
            creal_T y1[8192];
        } f0;
        struct
        {
            real_T G[5776];
            real_T a[5776];
            real_T dv5[5776];
            real_T dv6[5776];
            real_T dv7[5776];
        } f1;
    } u1;
    struct
    {
        creal_T dcv0[8192];
    } f2;
} yaaptStackData;
#endif /*typedef_yaaptStackData*/

#endif
/* End of code generation (yaapt_types.h) */
