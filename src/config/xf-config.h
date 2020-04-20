#ifndef XF_CONFIG_H
#define XF_CONFIG_H

#include "config/xf-port-config.h"

#if (PORT_IDF_STM32CUBE != 0)
    #define USE_XF_DEFAULT_IMPLEMENTATION                                   1
    #define USE_XF_DISPATCHER_DEFAULT_IMPLEMENTATION                        1
    #define USE_XF_TIMEOUTMANAGER_DEFAULT_IMPLEMENTATION                    1
    #define USE_XF_RESOURCE_FACTORY_DEFAULT_IMPLEMENTATION                  1
    #define USE_XF_MUTEX_DEFAULT_IDF_IMPLEMENTATION                         1
    #define USE_XF_EVENT_QUEUE_DEFAULT_IDF_IMPLEMENTATION                   1
    #define USE_XF_PORT_IDF_STM32CUBE_PORT_FUNCTIONS_IMPLEMENTATION         1

    #include "default-idf/eventqueue-default.h"
#ifdef __cplusplus
    using XFEventQueue = XFEventQueueDefault;
#endif // __cplusplus
#endif // PORT_IDF_STM32CUBE
#if (PORT_STM32CUBE_CMSIS_FREERTOS != 0)
    #define USE_XF_DISPATCHER_ACTIVE_DEFAULT_IMPLEMENTATION                          1
    #define USE_XF_MUTEX_DEFAULT_CMSIS_OS_IMPLEMENTATION                             1
    #define USE_XF_THREAD_DEFAULT_CMSIS_OS_IMPLEMENTATION                            1
    #define USE_XF_PORT_STM32CUBE_CMSIS_FREERTOS_RESOURCE_FACTORY_IMPLEMENTATION     1
    #define USE_XF_PORT_STM32CUBE_CMSIS_FREERTOS_TIMEOUTMANAGER_IMPLEMENTATION       1
    #define USE_XF_PORT_STM32CUBE_CMSIS_FREERTOS_EVENT_QUEUE_IMPLEMENTATION          1

    #define XFTHREAD_DEFAULT_STACK_SIZE                                              512

#include "stm32cube-cmsis-freertos/eventqueue.h"
#endif // PORT_STM32CUBE_CMSIS_FREERTOS

#endif // XF_CONFIG_H
