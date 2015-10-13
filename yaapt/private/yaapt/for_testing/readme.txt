MATLAB Builder JA Read Me

1. Prerequisites for Deployment 

. Verify the MATLAB Compiler Runtime (MCR) is installed and ensure you    
  have installed version 8.3 (R2014a). 

. If the MCR is not installed, do the following:
  (1) enter
  
      >>mcrinstaller
      
      at MATLAB prompt. The MCRINSTALLER command displays the 
      location of the MCR Installer.

  (2) run the MCR Installer.

Or download the Windows 64-bit version of the MCR for R2014a 
from the MathWorks Web site by navigating to

   http://www.mathworks.com/products/compiler/mcr/index.html
   
 
For more information about the MCR and the MCR Installer, see 
Distribution to End Users in the MATLAB Compiler documentation  
in the MathWorks Documentation Center. 

. Ensure you have the version 1.7 of the Java Development Kit (JDK) to integrate the 
  component. 

. yaapt.jar must be included in your CLASSPATH.

. javabuilder.jar must be included in your CLASSPATH. javabuilder.jar 
  can be found in: 
  
  <mcr_root>*\toolbox\javabuilder\jar\win64\javabuilder.jar
  

NOTE: You will need administrator rights to run MCRInstaller. 
 
2. Files to Deploy and Package

-yaapt.jar
-MCRInstaller.exe 
   - if end users are unable to download the MCR using the above  
     link, include it when building your component by clicking 
     the "Add MCR" link in the Deployment Tool
-Javadoc   
   - javadoc for yaapt is in the doc directory. While  
     distributing the javadoc, this entire directory should be distributed.
-This readme file


3. Resources

   - To learn more about Deploying Java applications on the Web, see Web Deployment in 
     the MATLAB Builder JA documentation in the MathWorks Documentation Center.   


4. Definitions

For information on deployment terminology, go to 
http://www.mathworks.com/help. Select MATLAB Compiler >   
Getting Started > About Application Deployment > 
Application Deployment Terms in the MathWorks Documentation 
Center.


* NOTE: <mcr_root> is the directory where MCR is installed on the target machine.


5. Appendix 

A. Linux x86-64 systems:   
   On the target machine, add the MCR directory to the environment variable 
   LD_LIBRARY_PATH by issuing the following commands:

        NOTE: <mcr_root> is the directory where MCR is installed
              on the target machine.         

            setenv LD_LIBRARY_PATH
                $LD_LIBRARY_PATH:
                <mcr_root>/v83/runtime/glnxa64:
                <mcr_root>/v83/bin/glnxa64:
                <mcr_root>/v83/sys/os/glnxa64
            setenv XAPPLRESDIR <mcr_root>/v83/X11/app-defaults
 
B. Mac systems: 
   On the target machine, add the MCR directory to the environment variable 
   DYLD_LIBRARY_PATH by issuing the following commands:

        NOTE: <mcr_root> is the directory where MCR is installed
              on the target machine.         

            setenv DYLD_LIBRARY_PATH
                $DYLD_LIBRARY_PATH:
                <mcr_root>/v83/runtime/maci64:
                <mcr_root>/v83/sys/os/maci64:
                <mcr_root>/v83/bin/maci64


   For more detail information about setting MCR paths, see Distribution to End Users in 
   the MATLAB Builder JA documentation in the MathWorks Documentation Center.


       
        NOTE: To make these changes persistent after logout on Linux or 
              Mac machines, modify the .cshrc file to include this  
              setenv command.
        NOTE: On Windows, the environment variable syntax utilizes 
              backslashes (\), delimited by semi-colons (;). 
              On Linux or Mac, the environment variable syntax utilizes   
              forward slashes (/), delimited by colons (:).  
        NOTE: On Maci64, ensure you are using 64-bit JVM.
