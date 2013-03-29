#ifndef SCREENCONTROLPOINT_H
#define SCREENCONTROLPOINT_H

#include <QQuickItem>
#include <QTimer>

#include <HUpnpCore/HUdn>

namespace Herqq {
    namespace Upnp {
        class HClientAction;
        class HClientDevice;
        class HClientService;
        class HControlPoint;
        class HDeviceInfo;
    }
}

class ScreenControlPoint : public QQuickItem
{
    Q_OBJECT
    Q_DISABLE_COPY(ScreenControlPoint)
    
public:
    ScreenControlPoint(QQuickItem *parent = 0);
    ~ScreenControlPoint();

public Q_SLOTS:
    Q_INVOKABLE void stopLowerScreen();
    Q_INVOKABLE void stopRaiseScreen();
    Q_INVOKABLE void startLowerScreen();
    Q_INVOKABLE void startRaiseScreen();

protected Q_SLOTS:
    void onRootDeviceOnline(Herqq::Upnp::HClientDevice *device);
    void onRootDeviceOffline(Herqq::Upnp::HClientDevice *device);
    void onRootDeviceInvalidated(Herqq::Upnp::HClientDevice *device);
    void onRootDeviceRemoved(const Herqq::Upnp::HDeviceInfo &deviceInfo);

    void callRaiseScreen();
    void callLowerScreen();

private:
    Herqq::Upnp::HControlPoint *m_controlPoint;
    Herqq::Upnp::HClientDevice *m_device;
    QTimer *m_raiseTimer;
    QTimer *m_lowerTimer;
    Herqq::Upnp::HUdn m_deviceUdn;
};

QML_DECLARE_TYPE(ScreenControlPoint)

#endif // SCREENCONTROLPOINT_H

