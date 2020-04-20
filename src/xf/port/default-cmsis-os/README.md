# CMSIS-OS Platform Default Port

This folder provides a default implementation for CMSIS-OS platform 
related XF classes. You can use these classes to construct a CMSIS-OS
based XF.

If these classes do not suit your needs, they can be reimplemented for
your platform. Create an additional folder in the 'port' folder and
implement there the classes you need for your platform.

# Available Default CMSIS-OS Port Classes

| Class name     | File location                         | Define to set                           |
| -------------- | ------------------------------------- | --------------------------------------- |
| XFMutexDefault | xf/port/default-cmsis-os/mutex-default.cpp | USE_XF_MUTEX_DEFAULT_CMSIS_OS_IMPLEMENTATION |
| XFThreadDefault | xf/port/default-cmsis-os/thread-default.cpp | USE_XF_THREAD_DEFAULT_CMSIS_OS_IMPLEMENTATION |

If you need more information about the classes mentioned above, please
have a look into their header files and the doxygen comments in code.

# Example _config/xf-config.h_ File

Following you will find an example giving you a basic idea which define
to set in the application specific _config/xf-config.h_ file.

The _Stm32Cube CMSIS FreeRTOS_ port uses these classes:

```c++
// Defines to set to use the Stm32Cube CMSIS FreeRTOS port
#define USE_XF_DISPATCHER_ACTIVE_DEFAULT_IMPLEMENTATION                          1
#define USE_XF_MUTEX_DEFAULT_CMSIS_OS_IMPLEMENTATION                             1
#define USE_XF_THREAD_DEFAULT_CMSIS_OS_IMPLEMENTATION                            1
#define USE_XF_PORT_STM32CUBE_CMSIS_FREERTOS_RESOURCE_FACTORY_IMPLEMENTATION     1
#define USE_XF_PORT_STM32CUBE_CMSIS_FREERTOS_TIMEOUTMANAGER_IMPLEMENTATION       1
#define USE_XF_PORT_STM32CUBE_CMSIS_FREERTOS_EVENT_QUEUE_IMPLEMENTATION          1
#define USE_XF_PORT_STM32CUBE_CMSIS_FREERTOS_THREAD_IMPLEMENTATION               1

#include "stm32cube-cmsis-freertos/eventqueue.h"
```
