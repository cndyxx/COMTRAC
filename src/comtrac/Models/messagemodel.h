
#ifndef MESSAGEMODEL_H
#define MESSAGEMODEL_H


#include <QObject>
#include "message.h"
#include "medicationmodel.h"


class MessageModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<Message *> messages READ messages WRITE setMessages NOTIFY messagesChanged)

public:

    explicit MessageModel(QObject *parent = nullptr);
    ~MessageModel();


    QList<Message *> messages() const;
    void setMessages(const QList<Message *> &newMessages);

public slots:

signals:


    void messagesChanged();

private:
    QList<Message *> m_messages;
    QList<MedicationModel *> m_medications;

};

#endif // MESSAGEMODEL_H
