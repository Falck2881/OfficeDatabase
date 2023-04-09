#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "AddContacts.h"
#include "FindIntoPage.h"
#include "CreateTableIntoPage.h"
#include <QTabWidget>
#include <QSqlDatabase>
#include <QTableView>
#include <QSqlTableModel>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent):
    QWidget(parent),
    ui(new Ui::MainWindow),
    winContact{std::make_unique<WindowContacts>()},
    winFind{std::make_unique<WindowFind>()}
{
    ui->setupUi(this);
    move(100,10);
    addStartPage();
    setIcons();
    initializeCommands();
    connectingToYourSlots();
    connectingWithProviders();
    connectingForProductFind();
}

void MainWindow::setIcons()
{
    ui->iconFind->setPixmap(QPixmap(":/Find.png"));
    ui->iconFindDataBase->setPixmap(QPixmap(":/FindDataBase.png"));
}

void MainWindow::initializeCommands()
{
    findProduct = std::make_unique<FindIntoPage>(ui->tabsWorking);

    addTable = std::make_unique<Create::TableIntoPage>(ui->tabsWorking);

    addContacts = std::make_unique<AddContacts>(winContact.get());
}

void MainWindow::connectingToYourSlots()
{
    QObject::connect(ui->chooseCompany, &QComboBox::currentIndexChanged, this, &MainWindow::changeStateOfButtons);
    QObject::connect(ui->tabsWorking, &QTabWidget::tabCloseRequested, this, &MainWindow::removePage);
}

void MainWindow::connectingWithProviders()
{
    QObject::connect(ui->chooseCompany, &QComboBox::currentTextChanged,
                     addContacts.get(), &Command::execute);
    QObject::connect(ui->chooseCompany, &QComboBox::currentTextChanged,
                     addTable.get(), &AddTable::prepareTable);
    QObject::connect(ui->chooseTypeProducts, &QComboBox::currentTextChanged,
                     addTable.get(), &AddTable::execute);
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
    QObject::connect(ui->findButton, &QPushButton::clicked, winFind.get(), &WindowFind::show);
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
    QList<QWidget*> widgets{ui->chooseTypeProducts, ui->inputNameProducts, ui->findButton,
                            ui->full_Info_Company_Button, ui->requisitesButton, ui->managersButton};

    for(auto widget: widgets)
        widget->setEnabled(state);
}

void MainWindow::addStartPage()
{
    QPixmap pixmap(":/StartBackground.jpg");
    QLabel* background{new QLabel};
    background->setPixmap(pixmap);
    ui->tabsWorking->addTab(background,"Start");
}

void MainWindow::removePage(const qint32 index)
{
    if(ui->tabsWorking->count() != 1)
         removeContentOfPage(index);
}

void MainWindow::removeContentOfPage(const qint32 index)
{
    QTableView* table{qobject_cast<QTableView*>(ui->tabsWorking->widget(index))};
    QAbstractItemModel* model{table->model()};
    if(model != nullptr && table != nullptr){
        delete model;
        delete table;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
