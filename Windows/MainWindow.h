#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <memory>
#include "WindowContacts.h"
#include "WindowFind.h"
#include "MacroCommands.h"
#include "AddTable.h"
#include "FindProduct.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
    private slots:
        void changeStateOfButtons(const qint32 indexOnCompany);
        void removePage(const qint32 index);
    private:
        void setIcons();
        void initializeCommands();
        void connectingToYourSlots();
        void connectingWithProviders();
        void connectingForProductFind();
        void buttonsActivity(bool state);
        void addStartPage();
        void removeContentOfPage(const qint32 index);
    private:
        Ui::MainWindow *ui;
        std::unique_ptr<WindowContacts> winContact;
        std::unique_ptr<WindowFind> winFind;
        std::unique_ptr<AddTable> addTable;
        std::unique_ptr<Command> addContacts;
        std::unique_ptr<FindProduct> findProduct;
};

#endif // MAINWINDOW_H
