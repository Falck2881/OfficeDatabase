#ifndef WINDOWFIND_H
#define WINDOWFIND_H

#include <memory>
#include <QWidget>
#include "AddTable.h"
#include "FindProduct.h"
#include "VolumeSearch.h"

namespace Ui {
class WindowFind;
}

class WindowFind : public QWidget
{
    Q_OBJECT

    public:
        WindowFind();
        ~WindowFind();
    private slots:
        void checkStateOfWidgets();
    private:
        void initializeCommands();
        bool isExistSelectOfCompanies();
        bool isExistSelectOfProduct();
        void setEnabledWidgets(bool value);
        void connectingToMySlots();
        void connectingWithCommands();
    private:
        Ui::WindowFind *ui;
        std::unique_ptr<VolumeSearch> volumeSearch;
        std::shared_ptr<FindProduct> findInFirstTable;
        std::shared_ptr<FindProduct> findInSecondTable;
        std::unique_ptr<AddTable> addFirstTable;
        std::unique_ptr<AddTable> addSecondTable;
        std::unique_ptr<Command> changeLogoFirstCompany;
        std::unique_ptr<Command> changeLogoSecondCompany;
};

#endif // WINDOWFIND_H
