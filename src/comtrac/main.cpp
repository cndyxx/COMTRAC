
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlComponent>
#include "Models/login.h"
#include "Models/dbmanager.h"

#include "Models/medicationmodel.h"
#include "Models/medication.h"
#include "Models/symptommodel.h"
#include "Models/messagemodel.h"
#include <QQmlDebuggingEnabler>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    //Datenbank-Verbinung herstellen
    DbManager* database = DbManager::holeInstanz();

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/comtrac/Ui/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    //Verknüpfung zwischen QML und C++-Model
    QQmlContext *ctx = engine.rootContext();

    Login login;
    ctx->setContextProperty("login", &login);

    MedicationModel *medModel = new MedicationModel();
    engine.rootContext()->setContextProperty("medModel", medModel);


    SymptomModel *symptomModel = new SymptomModel();
    engine.rootContext()->setContextProperty("symptomModel", symptomModel);

    MessageModel *messageModel = new MessageModel();
    engine.rootContext()->setContextProperty("messageModel", messageModel);
    engine.load(url);

    return app.exec();
}
