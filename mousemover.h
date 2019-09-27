#pragma once

#include <QObject>

class MouseMover : public QObject
{
    Q_OBJECT
public:
    explicit MouseMover(QObject *parent = nullptr);

signals:

public slots:
    void moveMouse();
};
