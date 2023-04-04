#include "LustrofProductTables.h"

QString LustrofProductTables::getNameTableFromDataBase(const QString &nameTable)
{
    if(nameTable == "Бумажные изделия")
        return "Lustrof_Paper_and_other";
    else if(nameTable == "Письменные принадлежности")
        return "Lustrof_pens_and_other";
    else if(nameTable == "Канцелярские мелочи")
        return "Lustrof_screbki_and_other";
}
