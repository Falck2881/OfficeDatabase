#include "BraubergProductTables.h"

QString BraubergProductTables::getNameTableFromDataBase(const QString &nameTable)
{
    if(nameTable == "Бумажные изделия")
        return "Brauberg_Paper_and_other";
    else if(nameTable == "Письменные принадлежности")
        return "Brauberg_pens_and_other";
    else if(nameTable == "Канцелярские мелочи")
        return "Brauberg_screbki_and_other";
}
