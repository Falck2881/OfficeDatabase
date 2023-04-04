#ifndef FIND_H
#define FIND_H

#include <QObject>
#include <QString>

class Find: public QObject
{
    Q_OBJECT

    public:
        virtual ~Find() = default;
    public slots:
        virtual void execute() = 0;
    protected:
        Find() = default;
};
#endif // FIND_H
