#include <assert.h>
#include <config/xf-config.h>

#if (USE_XF_MUTEX_DEFAULT_QT_IMPLEMENTATION != 0)

#include "mutex-default.h"

/**
 * @brief Implementation of interface::XFMutex::create method.
 */
interface::XFMutex * interface::XFMutex::create()
{
    return new XFMutexDefault;
}

void XFMutexDefault::lock()
{
    _mutex.lock();
}

void XFMutexDefault::unlock()
{
    _mutex.unlock();
}

bool XFMutexDefault::tryLock(int32_t timeout /* = 0 */)
{
    return _mutex.tryLock(timeout);
}

#endif // USE_XF_MUTEX_DEFAULT_QT_IMPLEMENTATION
