
#ifndef APPLICATIONMANAGER_H
#define APPLICATIONMANAGER_H


#include <QObject>


class ApplicationManager : public QObject
{
    Q_OBJECT
public:
    explicit ApplicationManager(QObject *parent = nullptr);

    int getPageState() const;
    void setPageState(int newPageState);

signals:

    void pageStateChanged();

public slots:


private:

    int pageState;

    Q_PROPERTY(int pageState READ getPageState WRITE setPageState NOTIFY pageStateChanged)
};

#endif // APPLICATIONMANAGER_H
