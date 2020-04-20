#ifndef TRACE_H
#define TRACE_H

#include <stddef.h>
#include <stdint.h>
#include <config/trace-config.h>

#ifdef __cplusplus
extern "C" {
#endif

void trace_initialize();
void trace_out(const char * const format , ...);

#ifdef __cplusplus
}   // extern "C"
#endif

#ifdef __cplusplus

#include <string>

using namespace std;

/** \mainpage Trace
 *
 * \section sec_trace_intro Introduction
 *
 * This small library is used to print debug information to an output.
 * It serves as a general interface (LAL <b>L</b>ibrary <b>A</b>bstraction <b>L</b>ayer).
 *
 * The library consists of a single class named Trace. There is no need to make an instance
 * of this class. Instead use the #Trace::out() methods to output the information needed.
 *
 * \section sec_trace_targets Targets
 * \subsection subsec_trace_armebs4 Armebs4 Board
 * When working with the F7-DISCO board, Trace outputs the information using the USB-STLINK interface
 * of the debugger USB cable to the Host. On Windows, the 'STLink Virtual COM' Port must be opened to
 * see the trace output.
 * During compilation time, the constant \a USE_PLATFORM_F7_DISCO_GCC_TRACE must be defined.
 * \subsubsection subsubsec_trace_f7_disco_serial_config Serial Configuration
 * - Baud: 115200
 * - Data Bits: 8
 * - Parity: none
 * - Stop Bits: 1
 * - Flow control: none
 *
 * \subsection subsec_trace_qt QT library
 * When working with the QT library, Trace outputs the information to the debuggers output window.
 * During compilation time, the constant \a TC_QTCREATOR must be defined.
 *
 * \section sec_trace_external_links Links to related Documentation
 * \if DOC_WITH_TESTBENCH
 * - <a href="../../../../../../test-bench/doxygen/output/html/index.html">Test Bench Documentation</a>
 * \endif
 * - <a href="../../../../../xf/doxygen/output/html/index.html">XF Documentation</a>
 */

/**
 * \example trace-example01.cpp
 */

/**
 * Prints debug information to a predefined output (output window).
 */
class Trace
{
public:

    /**
     * @brief Initializes trace functionality.
     *
     * Call this method prior to use trace functionality.
     */
    static void initialize();

    /**
     * Outputs an STL string to the output window. The method will automatically add a new line, so
     * the next string will be put automatically on the next line in the output window.
     *
     * \param str String to print to the output window.
     */
    static void out(string str);

    /**
     * Outputs a sequence of data formatted as the fromat argument specifies.
     * This method can be used the same way as the traditional printf.
     * The method will automatically add a new line too.
     *
     * \param format The string that contains the text to be printed. It
     *               can optionally contain embedded format specifiers that
     *               are replaced by the values specified in subsequent additional
     *               arguments and formatted as requested.
     */
    static void out(const char * format, ...);

protected:
    Trace() {}
};
#endif // __cplusplus
#endif // TRACE_H
