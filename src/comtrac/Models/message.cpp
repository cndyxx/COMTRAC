
#include "message.h"


Message::Message(int type, QString text, QObject *parent)
    : QObject(parent), m_type(type), m_text(text)
{

}

int Message::type() const
{
    return m_type;
}

void Message::setType(int newType)
{
    if (m_type == newType)
        return;
    m_type = newType;
    emit typeChanged();
}

void Message::resetType()
{
    setType({}); // TODO: Adapt to use your actual default value
}

QString Message::text() const
{
    return m_text;
}

void Message::setText(const QString &newText)
{
    if (m_text == newText)
        return;
    m_text = newText;
    emit textChanged();
}



