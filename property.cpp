#include "property.h"

Property::Property() : name(""), values()
{

}

Property::Property(const QString & name, const QSet<int> & values)
{
    this->name = name;
    this->values = values;
}

void Property::addValue(const int value)
{
    values.insert(value);
}

QString Property::getName() const
{
    return name;
}

QSet<int> Property::getValues() const
{
    return values;
}

void Property::operator=(const Property &other)
{
    name = other.name;
    values = other.values;
}

bool Property::operator==(const Property &other) const
{
    return name == other.name && values == other.values;
}
