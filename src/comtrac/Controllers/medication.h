
#ifndef MEDICATION_H
#define MEDICATION_H


#include <QObject>


class Medication : public QObject
{
    Q_OBJECT
public:
    explicit Medication(QObject *parent = nullptr);

signals:

public slots:
    void readMedication(QString medication);

};

#endif // MEDICATION_H
