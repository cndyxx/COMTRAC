
#ifndef MESSAGEMODEL_H
#define MESSAGEMODEL_H


#include <QObject>
#include "message.h"


class MessageModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<Message *> messages READ messages WRITE setMessages NOTIFY messagesChanged)

public:

    explicit MessageModel(QObject *parent = nullptr);
    ~MessageModel();
    QList<Message *> messages() const;





public slots:
    QList<Message *>  getMessages();
    void setMessages(const QList<Message *> &newMessages);
    QString setMessageText(QList<QString> medications);

signals:


    void messagesChanged();

private:
    QList<Message *> m_messages;

};



#endif // MESSAGEMODEL_H
