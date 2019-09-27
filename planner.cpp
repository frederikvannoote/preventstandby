#include "planner.h"

Planner::Planner(QObject *parent):
    QObject(parent),
    m_periods(),
    m_timer()
{
    m_timer.setInterval(1000 * 60);
    m_timer.start();
    connect(&m_timer, &QTimer::timeout, this, &Planner::check);
}

void Planner::addActivePeriod(const QTime &start, const QTime &end)
{
    m_periods << ActivePeriod(start, end);
}

void Planner::check()
{
    bool fire = false;

    for (const ActivePeriod &period: m_periods)
    {
        fire &= period.isActive();
    }

    if (fire)
        emit tick();
}
