/**
 * This file has a different license to the rest of the uGFX system.
 * You can copy, modify and distribute this file as you see fit.
 * You do not need to publish your source modifications to this file.
 * The only thing you are not permitted to do is to relicense it
 * under a different license.
 */

/**
 * Copy this file into your project directory and rename it as gfxconf.h
 * Edit your copy to turn on the uGFX features you want to use.
 * The values below are the defaults.
 *
 * Only remove the comments from lines where you want to change the
 * default value. This allows definitions to be included from
 * driver makefiles when required and provides the best future
 * compatibility for your project.
 *
 * Please use spaces instead of tabs in this file.
 */
//* <<< Use Configuration Wizard in Context Menu >>>  
#ifndef _GFXCONF_H
#define _GFXCONF_H

#include <stdint.h>

#define GFX_COMPAT_V2                               GFXOFF

//<h> uGFX configuration without operating system.
//<i> Full documentation available at: https://wiki.ugfx.io
#define CONFIGURATION_WITH_OS	GFXOFF
///////////////////////////////////////////////////////////////////////////
// GOS - One of these must be defined, preferably in your Makefile       //
///////////////////////////////////////////////////////////////////////////
//#define GFX_USE_OS_CHIBIOS                           FALSE
//#define GFX_USE_OS_FREERTOS                          FALSE
//    #define GFX_FREERTOS_USE_TRACE                   FALSE
//#define GFX_USE_OS_WIN32                             FALSE
//#define GFX_USE_OS_LINUX                             FALSE
//#define GFX_USE_OS_OSX                               FALSE
//#define GFX_USE_OS_ECOS                              FALSE
//#define GFX_USE_OS_RAWRTOS                           TRUE
//#define GFX_USE_OS_ARDUINO                           FALSE
//#define GFX_USE_OS_KEIL                              TRUE
//#define GFX_USE_OS_CMSIS                             FALSE
//#define GFX_USE_OS_CMSIS2                            FALSE
#if (CONFIGURATION_WITH_OS == GFXOFF)
    #define GFX_USE_OS_RAW32                         GFXON
    #define GFX_OS_PRE_INIT_FUNCTION                 Raw32OSInit
    #define GFX_OS_INIT_NO_WARNING                   TRUE
    #define INTERRUPTS_OFF()    __asm volatile ("cpsid i" : : : "memory")
    #define INTERRUPTS_ON()     __asm volatile ("cpsie i" : : : "memory")
#else
    #define GFX_USE_OS_FREERTOS                      GFXON
    #define GFX_OS_INIT_NO_WARNING                   GFXON
#endif
//#define GFX_USE_OS_ZEPHYR                            FALSE
//#define GFX_USE_OS_NIOS                              FALSE
//#define GFX_USE_OS_QT                                FALSE
//    #define INTERRUPTS_OFF()                         optional_code
//    #define INTERRUPTS_ON()                          optional_code

// Options that (should where relevant) apply to all operating systems
//    #define GFX_NO_INLINE                            FALSE
    #define GFX_COMPILER                             GFX_COMPILER_GCC
//    #define GFX_SHOW_COMPILER                        FALSE
    #define GFX_CPU                                  GFX_CPU_CORTEX_M7
//    #define GFX_CPU_NO_ALIGNMENT_FAULTS              FALSE
//    #define GFX_CPU_ENDIAN                           GFX_CPU_ENDIAN_UNKNOWN
//<o> GFX heap size (in bytes), min. 32000		

    #define GFX_OS_HEAP_SIZE                         64000
    #define GFX_OS_NO_INIT                           TRUE
//    #define GFX_OS_EXTRA_INIT_FUNCTION               myOSInitRoutine
//    #define GFX_OS_EXTRA_DEINIT_FUNCTION             myOSDeInitRoutine
//    #define GFX_OS_CALL_UGFXMAIN                     FALSE
//    #define GFX_OS_UGFXMAIN_STACKSIZE                0
//    #define GFX_EMULATE_MALLOC                       FALSE
//<o> LCD orientartion <0=> Board orientation
//                     <90=> 90 degree rotate
//                     <180=> 180 degree rotate (default laboratory)
//                     <270=> 270 degree rotate
#define GDISP_DEFAULT_ORIENTATION                    180    // If not defined the native hardware orientation is used.

///////////////////////////////////////////////////////////////////////////
// GDISP                                                                 //
///////////////////////////////////////////////////////////////////////////
// <e> GDISP configuration
#define GFX_USE_GDISP                                GFXON
#define GDISP_NEED_CONTROL                           GFXON		// always because LCD is 180 degree
//<q> Use of draw circle functions
#define GDISP_NEED_CIRCLE                            0
//<q> Use of draw circle into circle
#define GDISP_NEED_DUALCIRCLE                        0
//<q> Use of draw ellipse functions
#define GDISP_NEED_ELLIPSE                           0
//<q> Use of draw arc functions
#define GDISP_NEED_ARC                               0
//<q> Use of draw arc sectors functions
#define GDISP_NEED_ARCSECTORS                        0
//<q> Use of draw convex polygon functions
#define GDISP_NEED_CONVEX_POLYGON                    0
//<q> Use of scrolling functions
#define GDISP_NEED_SCROLL                            0
//<q> Use of read pixel functions
#define GDISP_NEED_PIXELREAD                         0
//#define GDISP_NEED_QUERY                             FALSE
#define GDISP_NEED_MULTITHREAD                       GFXON              /* Set to 1 if gfx drawing needs to be thread-safe. */
//#define GDISP_NEED_STREAMING                         FALSE
//#define GDISP_NEED_AUTOFLUSH                         FALSE
//#define GDISP_NEED_TIMERFLUSH                        FALSE

//<q> Control LCD boundaries
#define GDISP_NEED_VALIDATION                        0
#define GDISP_NEED_CLIP                              GFXON
// <e> Text usage
#define GDISP_NEED_TEXT                              GFXON

//<q> Text word wrap
    #define GDISP_NEED_TEXT_WORDWRAP                 0
//    #define GDISP_NEED_TEXT_BOXPADLR                 1
//    #define GDISP_NEED_TEXT_BOXPADTB                 1
//<q> Text antialiasing
    #define GDISP_NEED_ANTIALIAS                     0
//<q> Text UTF8
    #define GDISP_NEED_UTF8                          GFXON
//<q> Text kerning
    #define GDISP_NEED_TEXT_KERNING                  0

// <e> Fonts (use one at least)
#define FOR_CONF_WIZARD 1
//<q> Font ui1
    #define GDISP_INCLUDE_FONT_UI1                   0
//<q> Font ui2
    #define GDISP_INCLUDE_FONT_UI2                   GFXON		// The smallest preferred font.
//<q> Font Largenumbers
    #define GDISP_INCLUDE_FONT_LARGENUMBERS          0
//<q> Font DejaVuSans10
    #define GDISP_INCLUDE_FONT_DEJAVUSANS10          0
//<q> Font DejaVuSans12
    #define GDISP_INCLUDE_FONT_DEJAVUSANS12          0
//<q> Font DejaVuSans16
    #define GDISP_INCLUDE_FONT_DEJAVUSANS16          0
//<q> Font DejaVuSans20
    #define GDISP_INCLUDE_FONT_DEJAVUSANS20          0
//<q> Font DejaVuSans24
    #define GDISP_INCLUDE_FONT_DEJAVUSANS24          0
//<q> Font DejaVuSans32
    #define GDISP_INCLUDE_FONT_DEJAVUSANS32          0
//<q> Font DejaVuSansBold12
    #define GDISP_INCLUDE_FONT_DEJAVUSANSBOLD12      0
//<q> Font Fixed_10x20
    #define GDISP_INCLUDE_FONT_FIXED_10X20           0
//<q> Font Fixed_7x14
    #define GDISP_INCLUDE_FONT_FIXED_7X14            0
//<q> Font Fixed_5x8
    #define GDISP_INCLUDE_FONT_FIXED_5X8             0
//<q> Font DejaVuSans12_aa
    #define GDISP_INCLUDE_FONT_DEJAVUSANS12_AA       0
//<q> Font DejaVuSans16_aa
    #define GDISP_INCLUDE_FONT_DEJAVUSANS16_AA       0
//<q> Font DejaVuSans20_aa
    #define GDISP_INCLUDE_FONT_DEJAVUSANS20_AA       0
//<q> Font Dejavusans24_aa
    #define GDISP_INCLUDE_FONT_DEJAVUSANS24_AA       0
//<q> Font DejaVuSans32_aa
    #define GDISP_INCLUDE_FONT_DEJAVUSANS32_AA       0
//<q> Font DejaVuSansBold12_aa
    #define GDISP_INCLUDE_FONT_DEJAVUSANSBOLD12_AA   0
//<q> Font user
    #define GDISP_INCLUDE_USER_FONTS                 GFXON
// </e>
// </e>
// <e> Image usage
#define GDISP_NEED_IMAGE                             GFXON
// <e> Image bitmap (BMP)
    #define GDISP_NEED_IMAGE_BMP                     0
//<q> Bitmap 1 bit
    #define GDISP_NEED_IMAGE_BMP_1               0
//<q> Bitmap 4 bits
    #define GDISP_NEED_IMAGE_BMP_4               0
//<q> Bitmap 4 bits RLE compressed
    #define GDISP_NEED_IMAGE_BMP_4_RLE           0
//<q> Bitmap 8 bits
    #define GDISP_NEED_IMAGE_BMP_8               0
//<q> Bitmap 8 bits RLE compressed
    #define GDISP_NEED_IMAGE_BMP_8_RLE           0
//<q> Bitmap 16 bits
    #define GDISP_NEED_IMAGE_BMP_16              0
//<q> Bitmap 24 bits
    #define GDISP_NEED_IMAGE_BMP_24              0
//<q> Bitmap 32 bits
    #define GDISP_NEED_IMAGE_BMP_32              0		
    #define GDISP_IMAGE_BMP_BLIT_BUFFER_SIZE     32
// </e>
//<q> Image GIF	
   #define GDISP_NEED_IMAGE_GIF                  0
   #define GDISP_IMAGE_GIF_BLIT_BUFFER_SIZE     32
//<q> Image JPG	 
   #define GDISP_NEED_IMAGE_JPG                  0
//<e> Image PNG
   #define GDISP_NEED_IMAGE_PNG                  GFXON
//<q> PDG interlaced
   #define GDISP_NEED_IMAGE_PNG_INTERLACED       GFXOFF
//<q> PDG transparency
   #define GDISP_NEED_IMAGE_PNG_TRANSPARENCY     GFXON
//<q> PDG background
   #define GDISP_NEED_IMAGE_PNG_BACKGROUND       GFXON
//        #define GDISP_NEED_IMAGE_PNG_ALPHACLIFF      32
//        #define GDISP_NEED_IMAGE_PNG_PALETTE_124     TRUE
//        #define GDISP_NEED_IMAGE_PNG_PALETTE_8       TRUE
//        #define GDISP_NEED_IMAGE_PNG_GRAYSCALE_124   TRUE
//        #define GDISP_NEED_IMAGE_PNG_GRAYSCALE_8     TRUE
//        #define GDISP_NEED_IMAGE_PNG_GRAYSCALE_16    TRUE
//        #define GDISP_NEED_IMAGE_PNG_GRAYALPHA_8     TRUE
//        #define GDISP_NEED_IMAGE_PNG_GRAYALPHA_16    TRUE
//        #define GDISP_NEED_IMAGE_PNG_RGB_8           TRUE
//        #define GDISP_NEED_IMAGE_PNG_RGB_16          TRUE
//        #define GDISP_NEED_IMAGE_PNG_RGBALPHA_8      TRUE
//        #define GDISP_NEED_IMAGE_PNG_RGBALPHA_16     TRUE
//        #define GDISP_IMAGE_PNG_BLIT_BUFFER_SIZE     32
//        #define GDISP_IMAGE_PNG_FILE_BUFFER_SIZE     8
//        #define GDISP_IMAGE_PNG_Z_BUFFER_SIZE        32768
// </e>
//    #define GDISP_NEED_IMAGE_ACCOUNTING              FALSE
//    #define GDISP_NEED_IMAGE_NATIVE                  FALSE

//#define GDISP_NEED_PIXMAP                            FALSE
//    #define GDISP_NEED_PIXMAP_IMAGE                  FALSE

//#define GDISP_LINEBUF_SIZE                           128
//#define GDISP_STARTUP_COLOR                          Black
#define GDISP_NEED_STARTUP_LOGO                      FALSE

//#define GDISP_TOTAL_DISPLAYS                         1

#define GDISP_DRIVER_LIST                            GDISPVMT_STM32LTDC
//    #ifdef GDISP_DRIVER_LIST
//        // For code and speed optimization define as TRUE or FALSE if all controllers have the same capability
//        #define GDISP_HARDWARE_STREAM_WRITE          FALSE
//        #define GDISP_HARDWARE_STREAM_READ           FALSE
//        #define GDISP_HARDWARE_STREAM_POS            FALSE
//        #define GDISP_HARDWARE_DRAWPIXEL             FALSE
//        #define GDISP_HARDWARE_CLEARS                FALSE
//        #define GDISP_HARDWARE_FILLS                 FALSE
//        #define GDISP_HARDWARE_BITFILLS              FALSE
//        #define GDISP_HARDWARE_SCROLL                FALSE
        #define GDISP_HARDWARE_PIXELREAD             GFXON
//        #define GDISP_HARDWARE_CONTROL               FALSE
//        #define GDISP_HARDWARE_QUERY                 FALSE
//        #define GDISP_HARDWARE_CLIP                  FALSE

        #define GDISP_PIXELFORMAT                    GDISP_PIXELFORMAT_RGB565
//    #endif

//#define GDISP_USE_GFXNET                             FALSE
//    #define GDISP_GFXNET_PORT                        13001
//    #define GDISP_GFXNET_CUSTOM_LWIP_STARTUP         FALSE
//    #define GDISP_DONT_WAIT_FOR_NET_DISPLAY          FALSE
//    #define GDISP_GFXNET_UNSAFE_SOCKETS              FALSE
//</e>
// </e>
///////////////////////////////////////////////////////////////////////////
// GWIN                                                                  //
///////////////////////////////////////////////////////////////////////////
// <e> GWIN configuration
#define GFX_USE_GWIN                                 TRUE
// <e> Use windows manager
  #define GWIN_NEED_WINDOWMANAGER                    GFXON
//<q> Redraw imadiate
    #define GWIN_REDRAW_IMMEDIATE                    0
//<q> Redraw all windows in single operation
    #define GWIN_REDRAW_SINGLEOP                     GFXON
//<q> Flashing widget support
    #define GWIN_NEED_FLASHING                       0
//<o> Flashing period
      #define GWIN_FLASHING_PERIOD                 250
// </e>
// <e> Console support
#define GWIN_NEED_CONSOLE                            0
//<q> Console history
    #define GWIN_CONSOLE_HISTORY_ATCREATE            0
//    #define GWIN_CONSOLE_USE_HISTORY                 0
//        #define GWIN_CONSOLE_HISTORY_AVERAGING       FALSE
//<q> Use escape command for coloring
    #define GWIN_CONSOLE_ESCSEQ                      0
//    #define GWIN_CONSOLE_USE_BASESTREAM              FALSE	// chibios only
//<q> Floating numbers support
    #define GWIN_CONSOLE_USE_FLOAT                   0
//</e>
#define GWIN_NEED_GRAPH                              GFXON
//#define GWIN_NEED_GL3D                               FALSE
//<q> Widget support
#define GWIN_NEED_WIDGET                             GFXON
//#define GWIN_FOCUS_HIGHLIGHT_WIDTH                   1
//<q> Label support
    #define GWIN_NEED_LABEL                          GFXON
//        #define GWIN_LABEL_ATTRIBUTE                 FALSE
//<q> Button support
    #define GWIN_NEED_BUTTON                         GFXON
//        #define GWIN_BUTTON_LAZY_RELEASE             FALSE
//<q> Slider support
    #define GWIN_NEED_SLIDER                         0
//        #define GWIN_SLIDER_NOSNAP                   FALSE
//        #define GWIN_SLIDER_DEAD_BAND                5
//        #define GWIN_SLIDER_TOGGLE_INC               20
//<q> Checkbox support
    #define GWIN_NEED_CHECKBOX                       0
//<e> Image support
    #define GWIN_NEED_IMAGE                          GFXON
//<q> Image animation support
        #define GWIN_NEED_IMAGE_ANIMATION            0
//</e>
//<q> Radio button support
    #define GWIN_NEED_RADIO                          GFXON
//<e> List support		
    #define GWIN_NEED_LIST                           0
//<q> List image support		
        #define GWIN_NEED_LIST_IMAGES                0
// </e>
				
//<q> Progressbar support		
    #define GWIN_NEED_PROGRESSBAR                    0
//        #define GWIN_PROGRESSBAR_AUTO                FALSE
//<q> Keyboard support		
    #define GWIN_NEED_KEYBOARD                       0
//        #define GWIN_KEYBOARD_DEFAULT_LAYOUT         VirtualKeyboard_English1
//        #define GWIN_NEED_KEYBOARD_ENGLISH1          TRUE
//<q> Text edit support		
    #define GWIN_NEED_TEXTEDIT                       0
//    #define GWIN_FLAT_STYLING                        FALSE
//<q> Widgets tag support		
    #define GWIN_WIDGET_TAGS                         0
//<q> Containers support		
    #define GWIN_NEED_CONTAINERS                        GFXON
//<q> Need container support		
    #define GWIN_NEED_CONTAINER                         GFXON
//<q> Frame support
    #define GWIN_NEED_FRAME                          0
//<q> Tabset support (see details)		
    #define GWIN_NEED_TABSET                         0
//        #define GWIN_TABSET_TABHEIGHT                18
// </e>

///////////////////////////////////////////////////////////////////////////
// GTRANS                                                                //
///////////////////////////////////////////////////////////////////////////
//#define GFX_USE_GTRANS                               FALSE


///////////////////////////////////////////////////////////////////////////
// GEVENT                                                                //
///////////////////////////////////////////////////////////////////////////
// <e> GEVENT configuration
#define GFX_USE_GEVENT                               GFXON

//#define GEVENT_ASSERT_NO_RESOURCE                    FALSE
//<o> Maximum size of an event (in bytes)		
#define GEVENT_MAXIMUM_SIZE                          32
//<o> Maximum Source/Listener pair		
#define GEVENT_MAX_SOURCE_LISTENERS                  32

//</e>
///////////////////////////////////////////////////////////////////////////
// GTIMER                                                                //
///////////////////////////////////////////////////////////////////////////
#define GFX_USE_GTIMER                               1

#define GTIMER_THREAD_PRIORITY                       (HIGH_PRIORITY - 3)
#define GTIMER_THREAD_WORKAREA_SIZE                  4096


///////////////////////////////////////////////////////////////////////////
// GQUEUE                                                                //
///////////////////////////////////////////////////////////////////////////
#define GFX_USE_GQUEUE                               TRUE

#define GQUEUE_NEED_ASYNC                            TRUE
//#define GQUEUE_NEED_GSYNC                            FALSE
//#define GQUEUE_NEED_FSYNC                            FALSE
//#define GQUEUE_NEED_BUFFERS                          FALSE

///////////////////////////////////////////////////////////////////////////
// GINPUT                                                                //
///////////////////////////////////////////////////////////////////////////
// <e> GINPUT configuration
#define GFX_USE_GINPUT                               GFXON

//<q> Mouse / touchscreen support
#define GINPUT_NEED_MOUSE                            GFXON
//    #define GINPUT_TOUCH_STARTRAW                    FALSE

//    #define GINPUT_TOUCH_NOTOUCH                     FALSE
//    #define GINPUT_TOUCH_NOCALIBRATE                 FALSE
#define GINPUT_TOUCH_NOCALIBRATE_GUI             TRUE
//    #define GINPUT_MOUSE_POLL_PERIOD                 25
//    #define GINPUT_MOUSE_CLICK_TIME                  300
//    #define GINPUT_TOUCH_CXTCLICK_TIME               700
//    #define GINPUT_TOUCH_USER_CALIBRATION_LOAD       FALSE
//    #define GINPUT_TOUCH_USER_CALIBRATION_SAVE       FALSE
    #define GMOUSE_DRIVER_LIST                        GMOUSEVMT_FT5336
//<q> Keyboard support
#define GINPUT_NEED_KEYBOARD                         0
//    #define GINPUT_KEYBOARD_POLL_PERIOD              200
//    #define GKEYBOARD_DRIVER_LIST                    GKEYBOARDVMT_Win32, GKEYBOARDVMT_Win32
//    #define GKEYBOARD_LAYOUT_OFF                     FALSE
//        #define GKEYBOARD_LAYOUT_SCANCODE2_US        FALSE
//#define GINPUT_NEED_TOGGLE                           FALSE
//#define GINPUT_NEED_DIAL                             FALSE
//</e>


///////////////////////////////////////////////////////////////////////////
// GFILE                                                                 //
///////////////////////////////////////////////////////////////////////////
// <e> GFILE configuration
#define GFX_USE_GFILE                                GFXON
// <e> String support
#define GFILE_NEED_STRINGS                           0
//<q> printfg, fprintg, etc support
#define GFILE_NEED_PRINTG                            0
//<q> scang, fscang, etc support
#define GFILE_NEED_SCANG                             0
//</e>
//#define GFILE_NEED_FILELISTS                         FALSE
//#define GFILE_NEED_STDIO                             FALSE
//#define GFILE_NEED_NOAUTOMOUNT                       FALSE
//#define GFILE_NEED_NOAUTOSYNC                        FALSE

//#define GFILE_NEED_MEMFS                             FALSE
//<q> ROM file system support
#define GFILE_NEED_ROMFS                             GFXON
//<q> RAM file system support
#define GFILE_NEED_RAMFS                             0
//#define GFILE_NEED_FATFS                             FALSE
//#define GFILE_NEED_NATIVEFS                          FALSE
//#define GFILE_NEED_CHBIOSFS                          FALSE
//#define GFILE_NEED_USERFS                            FALSE

//#define GFILE_ALLOW_FLOATS                           FALSE
//#define GFILE_ALLOW_DEVICESPECIFIC                   FALSE
//<o> Maximum number of files		
#define GFILE_MAX_GFILES                             6
//</e>

///////////////////////////////////////////////////////////////////////////
// GADC                                                                  //
///////////////////////////////////////////////////////////////////////////
//#define GFX_USE_GADC                                 FALSE
//    #define GADC_MAX_LOWSPEED_DEVICES                4

///////////////////////////////////////////////////////////////////////////
// GAUDIO                                                                //
///////////////////////////////////////////////////////////////////////////
//#define GFX_USE_GAUDIO                               FALSE
//    #define GAUDIO_NEED_PLAY                         FALSE
//    #define GAUDIO_NEED_RECORD                       FALSE

///////////////////////////////////////////////////////////////////////////
// GMISC                                                                 //
///////////////////////////////////////////////////////////////////////////
// <e> GMISC configuration (see details in file)
#define GFX_USE_GMISC                                0

//#define GMISC_NEED_ARRAYOPS                          FALSE
//#define GMISC_NEED_FASTTRIG                          FALSE
//#define GMISC_NEED_FIXEDTRIG                         FALSE
//#define GMISC_NEED_INVSQRT                           FALSE
//    #define GMISC_INVSQRT_MIXED_ENDIAN               FALSE
//    #define GMISC_INVSQRT_REAL_SLOW                  FALSE
#define GMISC_NEED_MATRIXFLOAT2D                     0
//#define GMISC_NEED_MATRIXFIXED2D                     FALSE
//#define GMISC_NEED_HITTEST_POLY                      FALSE
// </e>
//</h>


#endif /* _GFXCONF_H */
