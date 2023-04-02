#ifndef WINDOWCONTACTS_H
#define WINDOWCONTACTS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class contactWindow; }
QT_END_NAMESPACE

class QSqlRecord;
class QSqlQuery;
class QSqlDatabase;
class QPixmap;

class WindowContacts : public QMainWindow
{
    Q_OBJECT

    public:
        WindowContacts(QWidget *parent = nullptr);
        ~WindowContacts();
        void setContacts(const std::pair<QPixmap,QString>& attributes);
    private:
        void changeWindowOfContants(const std::pair<QPixmap,QString>&);
        void changeLogoCompany(const QPixmap& logo);
        void changeDescriptionAtCompany(const QString& id);
        void changeTitleCompany(const QString& id);
        void changeCummonInfo(const QString& id);
        void changeCEOInfo(const QString& id);
        void changeManagersInfo(const QString& id);
        void changeRequisitesInfo(const QString& id);
    private:
        Ui::contactWindow *ui;
};
#endif // WINDOWCONTACTS_H
