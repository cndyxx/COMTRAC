
#ifndef SYMPTOMMODEL_H
#define SYMPTOMMODEL_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QTime>
#include <QSqlQueryModel>
#include <QDateTime>

class SymptomModel : public QSqlQueryModel
{
    Q_OBJECT

public:
    explicit SymptomModel(QObject *parent = nullptr);

    void addSymptom(const QString& name, const QString& intensity,const int& frequency, const QString& duration);

private:
    void updateModel();

};

#endif // SYMPTOMMODEL_H
