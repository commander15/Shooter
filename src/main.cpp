#include <QtWidgets/qapplication.h>

#include "shooterwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    ShooterWindow win;
    win.resize(800, 480);
    win.showFullScreen();

    return app.exec();
}
