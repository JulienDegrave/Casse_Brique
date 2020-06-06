#include <QApplication>
#include <QPushButton>
#include <QTimer>
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow* maf = new MainWindow();
    maf->show();

    return app.exec();
}
