
#ifndef LOGIN_H
#define LOGIN_H

#include <QDebug>
#include <QObject>


class Login : public QObject
{
    Q_OBJECT
public:
    explicit Login(QObject *parent = nullptr);

signals:
    void loginButtonClicked();
public slots:
    void checkLoginData(QString userName, QString password);

};

#endif // LOGIN_H
