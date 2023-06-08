
#ifndef MESSAGE_H
#define MESSAGE_H


#include <QObject>


class Message : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int type READ type WRITE setType RESET resetType NOTIFY typeChanged)
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
public:
    explicit Message(int type, QString text, QObject *parent = nullptr);

    int type() const;
    void setType(int newType);
    void resetType();

    QString text() const;
    void setText(const QString &newText);

private:
    int m_type;
    QString m_text;


signals:


    void typeChanged();
    void textChanged();
};

#endif // MESSAGE_H
