#pragma once

#include <QObject>
#include <QList>
#include <QTimer>
#include "activeperiod.h"


class Planner : public QObject
{
    Q_OBJECT
public:
    explicit Planner(QObject *parent = nullptr);

public slots:
    void addActivePeriod(const QTime &start, const QTime &end);

signals:
    void tick();

private slots:
    void check();

private:
    QList<ActivePeriod> m_periods;
    QTimer m_timer;
};
