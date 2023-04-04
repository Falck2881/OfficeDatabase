#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <memory>
#include "WindowContacts.h"
#include "IdentifyCompany.h"
#include "IdentifyProduct.h"
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
    private:
        void setStartBackground();
        void setIcons();
        void addCommandsForIndentifyCompany();
        void initializeCommandsOfFind();
        void connectingToYourSlots();
        void connectingWithProviders();
        void connectingForProductFind();
        void buttonsActivity(bool state);
    private:
        Ui::MainWindow *ui;
        std::unique_ptr<WindowContacts> winContact;
        std::unique_ptr<IdentifyCompany> identifyProviders;
        std::shared_ptr<IdentifyProduct> identifyProduct;
        std::unique_ptr<FindProduct> findProduct;
};

#endif // MAINWINDOW_H
