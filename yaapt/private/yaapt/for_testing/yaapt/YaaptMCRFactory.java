/*
 * MATLAB Compiler: 5.1 (R2014a)
 * Date: Tue Oct 13 14:42:09 2015
 * Arguments: "-B" "macro_default" "-W" "java:yaapt,Class1" "-T" "link:lib" "-d" 
 * "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt\\for_testing" "-v" 
 * "D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m" 
 * "class{Class1:D:\\GitHub\\Monophonic-Pitch-Tracking\\yaapt\\private\\yaapt.m}" 
 */

package yaapt;

import com.mathworks.toolbox.javabuilder.*;
import com.mathworks.toolbox.javabuilder.internal.*;

/**
 * <i>INTERNAL USE ONLY</i>
 */
public class YaaptMCRFactory
{
   
    
    /** Component's uuid */
    private static final String sComponentId = "yaapt_04FD5378C872FE74528E7FA87FBF0F64";
    
    /** Component name */
    private static final String sComponentName = "yaapt";
    
   
    /** Pointer to default component options */
    private static final MWComponentOptions sDefaultComponentOptions = 
        new MWComponentOptions(
            MWCtfExtractLocation.EXTRACT_TO_CACHE, 
            new MWCtfClassLoaderSource(YaaptMCRFactory.class)
        );
    
    
    private YaaptMCRFactory()
    {
        // Never called.
    }
    
    public static MWMCR newInstance(MWComponentOptions componentOptions) throws MWException
    {
        if (null == componentOptions.getCtfSource()) {
            componentOptions = new MWComponentOptions(componentOptions);
            componentOptions.setCtfSource(sDefaultComponentOptions.getCtfSource());
        }
        return MWMCR.newInstance(
            componentOptions, 
            YaaptMCRFactory.class, 
            sComponentName, 
            sComponentId,
            new int[]{8,3,0}
        );
    }
    
    public static MWMCR newInstance() throws MWException
    {
        return newInstance(sDefaultComponentOptions);
    }
}
