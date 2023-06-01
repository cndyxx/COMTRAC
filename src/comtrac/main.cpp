
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlComponent>
#include "Controllers/login.h"
#include "Models/dbmanager.h"

#include "Models/medicationmodel.h"
#include "Controllers/medication.h"
#include "Models/symptommodel.h"
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

    Login login;
    QQmlContext *ctx = engine.rootContext();
    ctx->setContextProperty("login", &login);

    MedicationModel *medModel = new MedicationModel();
//    MedicationModel medModel;
//    ctx->setContextProperty("medModel", &medModel);
    engine.rootContext()->setContextProperty("medModel", medModel);


    SymptomModel *symptomModel = new SymptomModel();
    engine.rootContext()->setContextProperty("symptomModel", symptomModel);

    engine.load(url);

    return app.exec();
}
