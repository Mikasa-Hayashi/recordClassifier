#include "record.h"

Record::Record() : name(""), properties()
{

}

Record::Record(const QString & name)
{
    this->name = name;
}

void Record::addPropery(const QString & propertyName, const QSet<int> & values)
{
    Property prop(propertyName, values);
    properties.insert(prop);
}

const Property & Record::getProperty(const QString & propertyName) const
{
    auto it = properties.constBegin();
    for(; it != properties.constEnd() && it->getName() != propertyName; ++it);
    return *it;
}

bool Record::hasProperty(const QString &propertyName) const
{
    auto it = properties.constBegin();
    for(; it != properties.constEnd() && it->getName() != propertyName; ++it);
    return it != properties.constEnd();
}

QString Record::getName() const
{
    return name;
}

QSet<Property> Record::getProperties() const
{
    return properties;
}

Record & Record::operator=(const Record &other)
{
    name = other.name;
    properties = other.properties;
    return *this;
}

bool Record::operator==(const Record & other) const
{
    return name == other.name && properties == other.properties;
}
