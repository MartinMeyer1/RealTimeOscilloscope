#ifndef XF_MUTEX_DEFAULT_IDF_H
#define XF_MUTEX_DEFAULT_IDF_H

#include <config/xf-config.h>

#if (USE_XF_MUTEX_DEFAULT_IDF_IMPLEMENTATION != 0)

#include <stdint.h>
#include "xf/interface/mutex.h"

/** @ingroup port_default_idf
 *  @{
 */

/**
 * @brief Default IDF imlementation XFMutex interface.
 *
 * This class uses `enterCritical()` and `exitCritical()`
 * functions which must be provided by the platform.
 * Therefore, this mutex implementation can be used
 * in Embedded Systems without OS.
 */
class XFMutexDefault : public interface::XFMutex
{
public:
	XFMutexDefault();
	virtual ~XFMutexDefault();

	virtual void lock();
	virtual void unlock();

	virtual bool tryLock(int32_t timeout = 0);
};

/** @} */ // end of port_default_idf group
#endif // USE_XF_MUTEX_DEFAULT_IDF_IMPLEMENTATION
#endif // XF_MUTEX_DEFAULT_IDF_H
