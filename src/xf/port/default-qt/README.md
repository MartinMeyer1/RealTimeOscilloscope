# Qt Platform Default Port

This folder provides a default implementation for Qt platform 
related XF classes. You can use these classes to construct a Qt
based XF.

If these classes do not suit your needs, they can be reimplemented for
your platform. Create an additional folder in the 'port' folder and
implement there the classes you need for your platform.

# Available Default Qt Port Classes

| Class name | File location | Define to set |
| -- | -- | -- |
| XFMutexDefault | xf/port/default-qt/mutex-default.cpp | USE_XF_MUTEX_DEFAULT_QT_IMPLEMENTATION |
| XFThreadDefault | xf/port/default-qt/thread-default.cpp | USE_XF_THREAD_DEFAULT_QT_IMPLEMENTATION |

If you need more information about the classes mentioned above, please
have a look into their header files and the doxygen comments in code.

# Example _config/xf-config.h_ File

Following you will find an example giving you a basic idea which define
to set in the application specific _config/xf-config.h_ file.

The _IDF Qt_ port uses these classes:

```c++
// Defines to set to use the IDF Qt port
#define USE_XF_TIMEOUTMANAGER_DEFAULT_IMPLEMENTATION        1
#define USE_XF_DISPATCHER_ACTIVE_DEFAULT_IMPLEMENTATION     1
#define USE_XF_MUTEX_DEFAULT_QT_IMPLEMENTATION              1
#define USE_XF_THREAD_DEFAULT_QT_IMPLEMENTATION             1

#define USE_XF_PORT_IDF_QT_XF_IMPLEMENTATION                1
#define USE_XF_PORT_IDF_QT_RESOURCE_FACTORY_IMPLEMENTATION  1
#define USE_XF_PORT_IDF_QT_EVENT_QUEUE_IMPLEMENTATION       1
#define USE_XF_PORT_IDF_QT_PORT_FUNCTIONS_IMPLEMENTATION    1

#include "idf-qt/eventqueue.h"
```
