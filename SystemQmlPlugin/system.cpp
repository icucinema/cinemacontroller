#include "system.h"

#include <QtCore/QCoreApplication>
#include <QtCore/QProcess>
#include <QtCore/QDebug>

System::System(QQuickItem *parent):
    QQuickItem(parent)
{
    // By default, QQuickItem does not draw anything. If you subclass
    // QQuickItem to create a visual item, you will need to uncomment the
    // following line and re-implement updatePaintNode()
    
    // setFlag(ItemHasContents, true);
}

System::~System()
{
}

void System::exit()
{
    QCoreApplication::instance()->quit();
}

void System::shutdown()
{
    qDebug() << "Initiating External Script";
/*    QString program = "/opt/CinemaController/bin/shutdown.sh";
    QStringList arguments;
    QProcess *myProcess = new QProcess(this);
    myProcess->start(program, arguments);
*/    QProcess::startDetached("/opt/CinemaController/bin/shutdown.sh", QStringList());
}
