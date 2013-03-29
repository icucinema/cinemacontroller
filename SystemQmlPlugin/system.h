#ifndef SYSTEM_H
#define SYSTEM_H

#include <QQuickItem>

class System : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(System)
    
public:
    System(QQuickItem *parent = 0);
    ~System();

public Q_SLOTS:
    Q_INVOKABLE void exit();
    Q_INVOKABLE void shutdown();
};

QML_DECLARE_TYPE(System)

#endif // SYSTEM_H

