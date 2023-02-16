#include "serikbldbackend.h"

#include <QDebug>

SerikBLDBackend::SerikBLDBackend(QQuickItem *parent)
    :QQuickItem(parent)
{

}

void SerikBLDBackend::registerQML()
{
    qmlRegisterType<SerikBLDBackend>("com.belediye",1,0, "SerikBLDBackend");
}

QString SerikBLDBackend::currentPage() const
{
    return mCurrentPage;
}

void SerikBLDBackend::setCurrentPage(const QString &newCurrentPage)
{
    if (mCurrentPage == newCurrentPage)
        return;

    qDebug() << "Changed: " << newCurrentPage;
    mCurrentPage = newCurrentPage;
    emit currentPageChanged();
}

void SerikBLDBackend::resetCurrentPage()
{
    setCurrentPage({"QML/AnaMenu.qml"}); // TODO: Adapt to use your actual default value
}

