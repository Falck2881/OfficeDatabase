#include "ChangeLogo.h"
#include <QLabel>
#include <QPixmap>

ChangeLogo::ChangeLogo(QLabel* const logo):
    logo(logo)
{

}

void ChangeLogo::execute(const QString& nameCompany)
{
    if(nameCompany == "Lustrof")
        logo->setPixmap(QPixmap(":/lustrofLogo.png"));
    else if(nameCompany == "Brauberg")
        logo->setPixmap(QPixmap(":/braubergLogo.png"));
    else
        logo->setText("Выберите предприятие");
}
