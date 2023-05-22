
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQmlComponent>
#include "Controllers/login.h"
#include "Models/dbmanager.h"

#include "Models/medicationmodel.h"
#include "Controllers/medication.h"
#include "Models/symptommodel.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    //Datenbank-Verbinung herstellen
    DbManager* database;
    database = DbManager::holeInstanz();
    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/comtrac/Ui/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    //Verknüpfung zwischen QML und C++-Model

   // qmlRegisterType<MedicationModel>("Medication", 1, 0, "MedicationModel");
    qmlRegisterUncreatableType<Medication>("Medication", 1, 0, "MedicationList",
                                           QStringLiteral("MedicationList should not be created in QML"));

    Login login;
    QQmlContext *ctx = engine.rootContext();
    ctx->setContextProperty("login", &login);

    MedicationModel *medModel = new MedicationModel();
    engine.rootContext()->setContextProperty("medModel", medModel);


    SymptomModel *symptomModel = new SymptomModel();
    engine.rootContext()->setContextProperty("symptomModel", symptomModel);

    engine.load(url);

    return app.exec();
}
