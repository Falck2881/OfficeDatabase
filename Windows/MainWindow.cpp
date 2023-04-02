#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "IdentifyCompany.h"
#include "IdentifyContacts.h"
#include <QTabWidget>

MainWindow::MainWindow(QWidget *parent):
    QWidget(parent),
    ui(new Ui::MainWindow),
    winContact{std::make_unique<WindowContacts>()},
    identifyCompany{std::make_unique<IdentifyCompany>()}
{
    ui->setupUi(this);
    move(100,10);
    setStartBackground();
    setIcons();
    addCommandsForIndentifyCompany();
    connectToYourSlots();
    connectToWindowOfContacts();
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

void MainWindow::addCommandsForIndentifyCompany()
{
    identifyCompany->append(std::make_unique<IdentifyContacts>(winContact.get()));
}

void MainWindow::connectToYourSlots()
{
    QObject::connect(ui->chooseCompany, &QComboBox::currentIndexChanged, this, &MainWindow::changeStateOfButtons);
}

void MainWindow::connectToWindowOfContacts()
{
    QObject::connect(ui->chooseCompany, &QComboBox::currentTextChanged, identifyCompany.get(), &IdentifyCompany::execute);
    QObject::connect(ui->full_Info_Company_Button, &QPushButton::clicked, winContact.get(), &QWidget::show);
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
