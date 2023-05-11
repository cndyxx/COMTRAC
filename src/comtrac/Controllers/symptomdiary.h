
#ifndef SYMPTOMDIARY_H
#define SYMPTOMDIARY_H


#include <QObject>


class SymptomDiary : public QObject
{
    Q_OBJECT
public:
    explicit SymptomDiary(QObject *parent = nullptr);

signals:

public slots:
    void readSymptom(QString symptom);


};

#endif // SYMPTOMDIARY_H
