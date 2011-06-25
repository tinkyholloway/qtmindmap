#include <stdlib.h> // EXIT_SUCCESS
#include <iostream> // cerr

#include <QtGui>
#include <QRegExp>
#include <QTranslator>

#include "include/mainwindow.h"
#include "include/systemtray.h"
#include "include/argumentparser.h"

int main(int argc, char *argv[])
{
    Q_INIT_RESOURCE(qtmindmap);

    QApplication a(argc, argv);

    // translation
    QString locale = QLocale::system().name();
    QTranslator translator;
    if (locale != "C" && !translator.load(QString("qtmindmap_") + locale))
    {
        std::cerr << "No translation file for locale: "
                  << locale.toStdString()
                  << std::endl;
    }
    else
    {
        a.installTranslator(&translator);
    }

    // parse args
    ArgumentParser argParser;
    bool success;
    if (!argParser.parseCmdLineArgs(success))
        return success ? EXIT_SUCCESS : EXIT_FAILURE;

    // system tray?
    MainWindow w;
    SystemTray *systemtray;
    if (argParser.isSystemTray() or argParser.isShowMinimized())
    {
        if (!QSystemTrayIcon::isSystemTrayAvailable())
        {
            QMessageBox::critical(0,
              QObject::tr("QtMindMap Error"),
              QObject::tr("I couldn't detect any system tray on this system."));
            return EXIT_FAILURE;
        }
        QApplication::setQuitOnLastWindowClosed(false);
        systemtray = new SystemTray(&w);
        systemtray->show();
    }

    // open file if any
    if (!argParser.filePath().isEmpty())
        w.openFile(argParser.filePath());

    // show minimized?
    if (!argParser.isShowMinimized())
        w.show();

    return a.exec();
}