#ifndef VOLUMESEARCH_H
#define VOLUMESEARCH_H

#include "Find.h"
#include <QList>

class VolumeSearch: public Find
{
    Q_OBJECT
    public:
        VolumeSearch() = default;
        void append(std::shared_ptr<Find> command);
    public slots:
        void execute() override;
    private:
        QList<std::shared_ptr<Find>> commands;
};
#endif // VOLUMESEARCH_H
