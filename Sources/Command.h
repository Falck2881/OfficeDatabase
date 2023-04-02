#ifndef COMMAND_H
#define COMMAND_H

#include <QObject>

class Command: public QObject
{
    Q_OBJECT

    public:
        virtual ~Command() = default;
    public slots:
        virtual void execute(const QString& idCompany){};
    protected:
        Command() = default;
};

#endif // COMMAND_H
