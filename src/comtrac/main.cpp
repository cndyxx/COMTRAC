
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Controllers/login.h"
#include "Models/dbmanager.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/comtrac/Ui/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    Login login;
    QQmlContext *ctx = engine.rootContext();
    ctx->setContextProperty("login", &login);

    DbManager database;

    engine.load(url);

    return app.exec();
}
