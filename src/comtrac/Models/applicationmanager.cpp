
#include "applicationmanager.h"

ApplicationManager::ApplicationManager(QObject *parent)
    : QObject{parent}
{

}

int ApplicationManager::getPageState() const
{
    return pageState;
}

void ApplicationManager::setPageState(int newPageState)
{
    if (pageState == newPageState)
        return;
    pageState = newPageState;
    emit pageStateChanged();
}

