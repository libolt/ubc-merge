#include "courtdata.h"

courtData::courtData()
{
}

courtData::~courtData()
{
}

// gets and sets modelName
std::string courtData::getModelName()
{
    return (modelName);
}
void courtData::setModelName(std::string name)
{
    modelName = name;
}
