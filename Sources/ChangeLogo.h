#ifndef CHANGELOGO_H
#define CHANGELOGO_H

#include "Command.h"

class QLabel;

class ChangeLogo: public Command
{
    Q_OBJECT
    public:
        ChangeLogo(QLabel* const logo);
    public slots:
        void execute(const QString &idCompany) override;
    private:
        QLabel* const logo;
};

#endif // CHANGELOGO_H
