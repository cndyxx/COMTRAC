
#ifndef INTAKETIME_H
#define INTAKETIME_H


#include <QObject>


class IntakeTime : public QObject
{
    Q_OBJECT
public:
    explicit IntakeTime(QObject *parent = nullptr);

signals:

private:
    int m_medicationIntakeID;
    int m_medicationID;
    int m_intakeID;

};

#endif // INTAKETIME_H
