
#include "messagemodel.h"
#include "iostream"


MessageModel::MessageModel(QObject *parent)
    : QObject{parent}
{
    m_messages.push_back(new Message (1, "Hallo, wählen Sie bitte die Kategorie aus, um den Chat zu starten:", this));
    m_messages.push_back(new Message(2, "Rezept bestellen", this));
    m_messages.push_back(new Message(3, "Für welche(s) Medikament(e) möchten Sie ein neues Rezept(e) bestellen?", this));
    m_messages.push_back(new Message(4, "Message 4: Text and buttons in a row", this));
    m_messages.push_back(new Message(5, "Ihre Rezeptbestellung ist erfolgreich bei uns eingegangen.", this));


}

MessageModel::~MessageModel()
{
    for (Message * message : m_messages) {
        delete message;
    }
}


QList<Message *> MessageModel::messages() const
{
    return m_messages;
}

QList<Message *> MessageModel::getMessages()
{
    return messages();
}

void MessageModel::setMessages(const QList<Message *> &newMessages)
{
    if (m_messages == newMessages)
        return;
    m_messages = newMessages;
    emit messagesChanged();
}


QString MessageModel::setMessageText(QList<QString> medications)
{
    QString orderText = "Rezept für ";
        if (medications.size() == 1) {
        orderText += medications[0] + " bestellen.";
    } else if (medications.size() > 1) {
        orderText = "Rezepte für ";
            for (int i = 0; i < medications.size() - 1; i++) {
            orderText += medications[i] + " und ";
        }
        orderText += medications[medications.size() -1 ] + " bestellen.";
    }
    m_messages[3]->setText(orderText);
    return orderText;
}
