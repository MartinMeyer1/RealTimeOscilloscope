#ifndef XF_INTERFACE_MUTEX_H
#define XF_INTERFACE_MUTEX_H

#include <stdint.h>

namespace interface {

/**
 * @brief Mutex interface needed by the XF to access a mutex.
 *
 * This interface only needs to be implemented for an XF port using
 * an underlying OS. An IDF based XF does not need to provide a
 * mutex.
 *
 * A non-recursive mutex needs to be implemented.
 */
class XFMutex
{
public:
    virtual ~XFMutex() = default;

    virtual void lock() = 0;						///< Blocks until the mutex becomes available.
    virtual void unlock() = 0;						///< Releases the mutex so it can be taken by other threads.

    /**
     * @brief Tries to get the mutex.
     *
     * If timeout is 0 method will leave immediately and then the return parameter indicates it the
     * mutex could be taken or not. Giving a negative value will block the thread until the mutex
     * becomes available.
     */
    virtual bool tryLock(int32_t timeout = 0) = 0;

    /**
     * @brief Creates and returns a new mutex instance.
     * @return Pointer to the created mutex object.
     *
     * The implementation of this method needs to be provided by
     * every XF port realizing a Mutex with this XFMutex interface.
     * Best way is to implement this method in the mutex.cpp file
     * of the XF port.
     *
     * Attention:
     *   Do not forget to create an object of the class realizing
     *   the interface and then return this object.
     *
     *   You cannot instanciate an object of an abstract class!
     */
    static XFMutex * create();

protected:
    XFMutex() = default;
};

} // namespace interface
#endif // XF_INTERFACE_MUTEX_H
