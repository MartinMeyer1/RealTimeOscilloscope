#include <config/xf-config.h>
#include "xf/interface/timeoutmanager.h"

#if (USE_XF_PORT_IDF_QT_PORT_FUNCTIONS_IMPLEMENTATION != 0)

#include <QObject>
#include <QTimerEvent>
#include "port-functions.h"

static class TimeoutManagerTimer : public QObject
{
public:
    TimeoutManagerTimer()
    : _timerId(0)
    {
    }

    void start(int32_t tickInterval)
    {
        Q_ASSERT(_timerId == 0);	// Method should be called only once!
        _timerId = startTimer(tickInterval, Qt::PreciseTimer);
    }

    void timerEvent(QTimerEvent * event) override
    {
        if (event->timerId() == _timerId)
        {
            interface::XFTimeoutManager::getInstance()->tick();
        }
    }

protected:
    int32_t _timerId;
} timeoutManagerTimer;

void XF_startTimeoutManagerTimer(uint32_t tickInterval)
{
    timeoutManagerTimer.start(int32_t(tickInterval));
}

#endif // USE_XF_PORT_IDF_QT_PORT_FUNCTIONS_IMPLEMENTATION
