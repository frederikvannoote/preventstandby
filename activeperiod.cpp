#include "activeperiod.h"

ActivePeriod::ActivePeriod(const QTime &start, const QTime &end):
    m_start(start),
    m_end(end)
{
}

ActivePeriod::ActivePeriod(const ActivePeriod &other):
    m_start(other.m_start),
    m_end(other.m_end)
{
}

ActivePeriod::ActivePeriod(ActivePeriod &&other):
    m_start(qMove(other.m_start)),
    m_end(qMove(other.m_end))
{
}

ActivePeriod &ActivePeriod::operator=(const ActivePeriod &other)
{
    if (this != &other)
    {
        m_start = other.m_start;
        m_end = other.m_end;
    }
    return *this;
}

ActivePeriod &ActivePeriod::operator=(ActivePeriod &&other)
{
    if (this != &other)
    {
        m_start = qMove(other.m_start);
        m_end = qMove(other.m_end);
    }
    return *this;
}

bool ActivePeriod::isActive() const
{
    const QTime now = QTime::currentTime();

    return (m_start < now) && (now < m_end);
}
