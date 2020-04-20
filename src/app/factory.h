#ifndef APP_FACTORY_H
#define APP_FACTORY_H

//
// What is seen only by the C++ compiler
//
#ifdef __cplusplus

#include "main.h"
#include "oscilloscopecontroller.h"
#include "gui.h"
#include "mdw/sig-gen/pwmgenerator.h"

using oscilloscope::Gui;

/**
 * @brief Factory creating all objects/components and relations between them.
 */
class Factory
{
public:
    Factory();                          ///< Constructor

    static void initialize();           ///< Initializes the factory
    static void build();                ///< Creates components and initializes relations

    static OscilloscopeController & getOscilloscopeController();
    static Gui & getGui();

#if defined(ENABLE_SIGGEN_PWMGENERATOR) && (ENABLE_SIGGEN_PWMGENERATOR != 0)
    static siggen::PwmGenerator & pwmGenerator();       ///< PWM signal generator
#endif // ENABLE_SIGGEN_PWMGENERATOR

protected:
    static OscilloscopeController _oscilloscopeController;
    static Gui _gui;
};

#endif // __cplusplus

//
// What is seen by the C and C++ compiler
//
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

void Factory_initialize();
void Factory_build();

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // APP_FACTORY_H
