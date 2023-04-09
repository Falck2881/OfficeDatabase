#include "WindowFind.h"
#include "ui_WindowFind.h"
#include "FindIntoTable.h"
#include "CreateModelIntoTable.h"
#include "ChangeLogo.h"
#include <QPixmap>

WindowFind::WindowFind():
    ui(new Ui::WindowFind),
    volumeSearch{std::make_unique<VolumeSearch>()}
{
    ui->setupUi(this);
    initializeCommands();
    connectingToMySlots();
    connectingWithCommands();
}

void WindowFind::initializeCommands()
{
    changeLogoFirstCompany = std::make_unique<ChangeLogo>(ui->logo);
    changeLogoSecondCompany = std::make_unique<ChangeLogo>(ui->logo_2);

    addFirstTable = std::make_unique<Create::ModelIntoTable>(ui->tableView);
    addSecondTable = std::make_unique<Create::ModelIntoTable>(ui->tableView_2);

    findInFirstTable = std::make_shared<FindIntoTable>(ui->tableView);
    findInSecondTable = std::make_shared<FindIntoTable>(ui->tableView_2);

    volumeSearch->append(findInFirstTable);
    volumeSearch->append(findInSecondTable);
}

void WindowFind::connectingToMySlots()
{
    QObject::connect(ui->chooseCompany, &QComboBox::currentTextChanged,
                     this, &WindowFind::checkStateOfWidgets);

    QObject::connect(ui->chooseCompany_2, &QComboBox::currentTextChanged,
                     this, &WindowFind::checkStateOfWidgets);

    QObject::connect(ui->chooseCompany, &QComboBox::currentTextChanged,
                     changeLogoFirstCompany.get(), &Command::execute);

    QObject::connect(ui->chooseCompany_2, &QComboBox::currentTextChanged,
                     changeLogoSecondCompany.get(), &Command::execute);

    QObject::connect(ui->chooseTypeProducts, &QComboBox::currentTextChanged,
                     this, &WindowFind::checkStateOfWidgets);
}

void WindowFind::connectingWithCommands()
{
    QObject::connect(ui->chooseCompany, &QComboBox::currentTextChanged,
                     addFirstTable.get(), &AddTable::prepareTable);

    QObject::connect(ui->chooseCompany_2, &QComboBox::currentTextChanged,
                     addSecondTable.get(), &AddTable::prepareTable);

    QObject::connect(ui->chooseTypeProducts, &QComboBox::currentTextChanged,
                     addFirstTable.get(), &AddTable::execute);

    QObject::connect(ui->chooseTypeProducts, &QComboBox::currentTextChanged,
                     addSecondTable.get(), &AddTable::execute);

    QObject::connect(ui->inputProductName, &QLineEdit::textEdited,
                     findInFirstTable.get(), &FindIntoTable::saveNameProduct);

    QObject::connect(ui->inputProductName, &QLineEdit::textEdited,
                     findInSecondTable.get(), &FindIntoTable::saveNameProduct);

    QObject::connect(ui->findButton, &QPushButton::clicked,
                     volumeSearch.get(), &VolumeSearch::execute);
}

void WindowFind::checkStateOfWidgets()
{
    if(isExistSelectOfCompanies()){
        ui->chooseTypeProducts->setEnabled(true);
        if(isExistSelectOfProduct())
            setEnabledWidgets(true);
        else
            setEnabledWidgets(false);
    }
    else{
        ui->chooseTypeProducts->setEnabled(false);
        setEnabledWidgets(false);
    }
}

bool WindowFind::isExistSelectOfCompanies()
{
    return ui->chooseCompany->currentText() != "Выбрать" && ui->chooseCompany_2->currentText() != "Выбрать";
}

bool WindowFind::isExistSelectOfProduct()
{
    return ui->chooseTypeProducts->currentText() != "Выбрать тип товаров";
}

void WindowFind::setEnabledWidgets(bool value)
{
    ui->inputProductName->setEnabled(value);
    ui->findButton->setEnabled(value);
}

WindowFind::~WindowFind()
{
    delete ui;
}
