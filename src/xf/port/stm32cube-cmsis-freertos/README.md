# XF Port - Stm32Cube CMSIS FreeRTOS

This port folder contains specific classes for the _Stm32Cube CMSIS FreeRTOS_
XF port.

# Classes used by the _Stm32Cube CMSIS FreeRTOS_ Port

| Class name | File location | Define to set |
|--|--|--|
| XFDispatcherActiveDefault | xf/port/default/dispatcher-active.cpp | USE_XF_DISPATCHER_ACTIVE_DEFAULT_IMPLEMENTATION |
| XFMutexDefault | xf/port/default-cmsis-os/mutex-default.cpp | USE_XF_MUTEX_DEFAULT_CMSIS_OS_IMPLEMENTATION |
| XFThreadDefault | xf/port/default-cmsis-os/thread-default.cpp | USE_XF_THREAD_DEFAULT_CMSIS_OS_IMPLEMENTATION |
| XFResourceFactoryPort | xf/port/stm32cube-cmsis-freertos/resourcefactory.cpp | USE_XF_PORT_STM32CUBE_CMSIS_FREERTOS_RESOURCE_FACTORY_IMPLEMENTATION |
| XFTimeoutManagerPort | xf/port/stm32cube-cmsis-freertos/timeoutmanager.cpp | USE_XF_PORT_STM32CUBE_CMSIS_FREERTOS_TIMEOUTMANAGER_IMPLEMENTATION |
| XFEventQueuePort | xf/port/stm32cube-cmsis-freertos/eventqueue.cpp | USE_XF_PORT_STM32CUBE_CMSIS_FREERTOS_EVENT_QUEUE_IMPLEMENTATION |

# Example _config/xf-config.h_ File
```c++
#define USE_XF_DISPATCHER_ACTIVE_DEFAULT_IMPLEMENTATION                          1
#define USE_XF_MUTEX_DEFAULT_CMSIS_OS_IMPLEMENTATION                             1
#define USE_XF_THREAD_DEFAULT_CMSIS_OS_IMPLEMENTATION                            1
#define USE_XF_PORT_STM32CUBE_CMSIS_FREERTOS_RESOURCE_FACTORY_IMPLEMENTATION     1
#define USE_XF_PORT_STM32CUBE_CMSIS_FREERTOS_TIMEOUTMANAGER_IMPLEMENTATION       1
#define USE_XF_PORT_STM32CUBE_CMSIS_FREERTOS_EVENT_QUEUE_IMPLEMENTATION          1

#include "stm32cube-cmsis-freertos/eventqueue.h"
```
