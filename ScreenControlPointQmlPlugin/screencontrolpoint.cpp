#include "screencontrolpoint.h"

#include <HUpnpCore/HActionArguments>
#include <HUpnpCore/HClientAction>
#include <HUpnpCore/HClientActionOp>
#include <HUpnpCore/HClientDevice>
#include <HUpnpCore/HClientService>
#include <HUpnpCore/HControlPoint>
#include <HUpnpCore/HDeviceInfo>
#include <HUpnpCore/HUdn>

#include <QDebug>

using namespace Herqq::Upnp;

ScreenControlPoint::ScreenControlPoint(QQuickItem *parent):
    QQuickItem(parent),
    m_controlPoint(0),
    m_device(0)
{
    // By default, QQuickItem does not draw anything. If you subclass
    // QQuickItem to create a visual item, you will need to uncomment the
    // following line and re-implement updatePaintNode()
    
    // setFlag(ItemHasContents, true);

    m_controlPoint = new HControlPoint();

    m_lowerTimer = new QTimer(this);
    m_lowerTimer->setInterval(250);
    connect(m_lowerTimer, SIGNAL(timeout()), this, SLOT(callLowerScreen()));

    m_raiseTimer = new QTimer(this);
    m_raiseTimer->setInterval(250);
    connect(m_raiseTimer, SIGNAL(timeout()), this, SLOT(callRaiseScreen()));

    if (!m_controlPoint->init()) {
        qWarning() << "*** Failed to set up Control Point.";
        qWarning() << "*** +++ " << m_controlPoint->error();
        qWarning() << "*** +++ " << m_controlPoint->errorDescription();

    }

    connect(m_controlPoint, SIGNAL(rootDeviceOnline(Herqq::Upnp::HClientDevice*)),
            this, SLOT(onRootDeviceOnline(Herqq::Upnp::HClientDevice*)));

    connect(m_controlPoint, SIGNAL(rootDeviceOffline(Herqq::Upnp::HClientDevice*)),
            this, SLOT(onRootDeviceOffline(Herqq::Upnp::HClientDevice*)));

    connect(m_controlPoint, SIGNAL(rootDeviceInvalidated(Herqq::Upnp::HClientDevice*)),
            this, SLOT(onRootDeviceInvalidated(Herqq::Upnp::HClientDevice*)));

    connect(m_controlPoint, SIGNAL(rootDeviceRemoved(Herqq::Upnp::HDeviceInfo)),
            this, SLOT(onRootDeviceRemoved(Herqq::Upnp::HDeviceInfo)));
}

ScreenControlPoint::~ScreenControlPoint()
{
}

void ScreenControlPoint::onRootDeviceOnline(HClientDevice *device)
{
    qDebug() << "*** Device Online: " << device->info().friendlyName();

    // Check if it's a screen and if so, make it our device
    qDebug() << "*** +++ Services Count: " << device->services().count();
    qDebug() << "*** +++ Actions Count:" << device->services().at(0)->actions().count();

    if (device->services().count() > 0 && device->services().at(0)->actions().contains(QLatin1String("LowerScreen")) && device->services().at(0)->actions().contains(QLatin1String("RaiseScreen"))) {
        qDebug() << "*** +++ This is the device you are looking for.  Saving to m_device.";
        m_device = device;
        m_deviceUdn = device->info().udn();
    }
}

void ScreenControlPoint::onRootDeviceOffline(HClientDevice *device)
{
    qDebug() << "Device Offline: " << device->info().friendlyName();

    if (device == m_device) {
        m_device = 0;
    }
}

void ScreenControlPoint::onRootDeviceInvalidated(HClientDevice *device)
{
    qDebug() << "Device Invalidated: " << device->info().friendlyName();

    if (device == m_device) {
        m_device = 0;
    }
}

void ScreenControlPoint::onRootDeviceRemoved(const HDeviceInfo &deviceInfo)
{
    qDebug() << "Device Removed: " << deviceInfo.friendlyName();

    if (deviceInfo.udn() == m_deviceUdn) {
        m_device = 0;
    }
}

void ScreenControlPoint::startRaiseScreen()
{
    qDebug() << "Starting to Raise the Screen";

    m_raiseTimer->start();
}

void ScreenControlPoint::stopRaiseScreen()
{
    qDebug() << "Stopping Raising the Screen";

    m_raiseTimer->stop();
}

void ScreenControlPoint::startLowerScreen()
{
    qDebug() << "Starting to Lower the Screen";

    m_lowerTimer->start();
}

void ScreenControlPoint::stopLowerScreen()
{
    qDebug() << "Stopping Lowering the Screen";

    m_lowerTimer->stop();
}

void ScreenControlPoint::callRaiseScreen()
{
    qDebug() << "+++ Raise Screen Invoked.";
    if (m_device != 0) {
        qDebug() << "+++ +++ We are connected to a real screen.  Actually raising the screen";
        HClientAction *action = m_device->services().at(0)->actions().value(QLatin1String("RaiseScreen"));
        HActionArguments args;
        action->beginInvoke(args);
        m_raiseTimer->start();
    }
}

void ScreenControlPoint::callLowerScreen()
{
    qDebug() << "--- Lower Screen Invoked";
    if (m_device != 0) {
        qDebug() << "--- +++ We are connected to a real screen.  Actually lowering the screen";
        HClientAction *action = m_device->services().at(0)->actions().value(QLatin1String("LowerScreen"));
        HActionArguments args;
        action->beginInvoke(args);
        m_lowerTimer->start();
    }
}
