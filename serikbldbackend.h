#ifndef SERIKBLDBACKEND_H
#define SERIKBLDBACKEND_H

#include <QQuickItem>

class SerikBLDBackend : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QString currentPage READ currentPage WRITE setCurrentPage RESET resetCurrentPage NOTIFY currentPageChanged)

public:
    SerikBLDBackend(QQuickItem* parent = nullptr);

    static void registerQML();

    QString currentPage() const;
    Q_INVOKABLE void setCurrentPage(const QString &newCurrentPage);
    void resetCurrentPage();

signals:


    void currentPageChanged();

private:
    QString mCurrentPage{"qrc:/QML/AnaMenu.qml"};

};

#endif // SERIKBLDBACKEND_H
