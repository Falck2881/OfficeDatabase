#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "IdentifyCompany.h"
#include "IdentifyContacts.h"
#include "IdentifyProduct.h"
#include "FindProduct.h"
#include <QTabWidget>
#include <QSqlDatabase>
#include <QTableView>
#include <QSqlTableModel>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent):
    QWidget(parent),
    ui(new Ui::MainWindow),
    winContact{std::make_unique<WindowContacts>()},
    identifyProviders{std::make_unique<IdentifyCompany>()}
{
    ui->setupUi(this);
    move(100,10);
    setStartBackground();
    setIcons();
    addCommandsForIndentifyCompany();
    initializeCommandsOfFind();
    connectingToYourSlots();
    connectingWithProviders();
    connectingForProductFind();
}

void MainWindow::setStartBackground()
{
    QPixmap pixmap(":/StartBackground.jpg");
    QLabel* background{new QLabel};
    background->setPixmap(pixmap);
    ui->tabsWorking->addTab(background,"Start");
}

void MainWindow::setIcons()
{
    ui->iconFind->setPixmap(QPixmap(":/Find.png"));
    ui->iconFindDataBase->setPixmap(QPixmap(":/FindDataBase.png"));
}

void MainWindow::initializeCommandsOfFind()
{
    findProduct = std::make_unique<FindProduct>(ui->tabsWorking);
}

void MainWindow::addCommandsForIndentifyCompany()
{
    identifyProduct = std::make_shared<IdentifyProduct>(ui->tabsWorking);
    identifyProviders->append(identifyProduct);
    identifyProviders->append(std::make_shared<IdentifyContacts>(winContact.get()));
}

void MainWindow::connectingToYourSlots()
{
    QObject::connect(ui->chooseCompany, &QComboBox::currentIndexChanged, this, &MainWindow::changeStateOfButtons);
}

void MainWindow::connectingWithProviders()
{
    QObject::connect(ui->chooseCompany, &QComboBox::currentTextChanged,
                     identifyProviders.get(), &IdentifyCompany::execute);
    QObject::connect(ui->chooseTypeProducts, &QComboBox::currentTextChanged,
                     identifyProduct.get(), &IdentifyProduct::addProductsTable);
    QObject::connect(ui->full_Info_Company_Button, &QPushButton::clicked,
                     winContact.get(), &WindowContacts::showCommonInformation);
    QObject::connect(ui->managersButton, &QPushButton::clicked,
                     winContact.get(), &WindowContacts::showManagers);
    QObject::connect(ui->requisitesButton, &QPushButton::clicked,
                     winContact.get(), &WindowContacts::showRequisites);
}

void MainWindow::connectingForProductFind()
{
    QObject::connect(ui->inputNameProducts, &QLineEdit::textEdited, findProduct.get(), &FindProduct::saveNameProduct);
    QObject::connect(ui->inputNameProducts, &QLineEdit::returnPressed, findProduct.get(), &FindProduct::execute);
}

void MainWindow::changeStateOfButtons(const qint32 indexOnCompany)
{
    if(indexOnCompany != 0)
        buttonsActivity(true);
    else
        buttonsActivity(false);
}

void MainWindow::buttonsActivity(bool state)
{
    QList<QWidget*> widgets{ui->chooseTypeProducts, ui->inputNameProducts, ui->findSimilarButton,
                            ui->full_Info_Company_Button, ui->requisitesButton, ui->managersButton};

    for(auto widget: widgets)
        widget->setEnabled(state);
}

MainWindow::~MainWindow()
{
    delete ui;
}
