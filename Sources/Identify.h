#ifndef COMMAND_H
#define COMMAND_H

#include <QObject>

class Identify: public QObject
{
    Q_OBJECT

    public:
        virtual ~Identify() = default;
    public slots:
        virtual void execute(const QString& idCompany){};
    protected:
        Identify() = default;
};

#endif // COMMAND_H
