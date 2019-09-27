#pragma once

#include <QTime>


class ActivePeriod
{

public:
    ActivePeriod(const QTime &start, const QTime &end);
    ActivePeriod(const ActivePeriod &other);
    ActivePeriod(ActivePeriod &&other);

    ActivePeriod& operator=(const ActivePeriod &other);
    ActivePeriod& operator=(ActivePeriod &&other);

    bool isActive() const;

private:
    QTime m_start;
    QTime m_end;
};
