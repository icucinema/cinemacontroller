#include <QtGui/QBitmap>
#include <QtGui/QCursor>
#include <QtWidgets/QApplication>
#include "qtquick2applicationviewer.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Make the mouse cursor invisible
    QBitmap transparentBitmap(32, 32);
    transparentBitmap.clear();
    QCursor invisibleCursor(transparentBitmap, transparentBitmap);
    app.setOverrideCursor(invisibleCursor);

    QtQuick2ApplicationViewer viewer;
    viewer.setMainQmlFile(QStringLiteral("qml/CinemaController/main.qml"));
    viewer.showExpanded();

    return app.exec();
}
