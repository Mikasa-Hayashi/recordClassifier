#include <QObject>
#include <QHash>
#include <QSet>
#include <QDebug>
#include "property.h"

#ifndef RECORD_H
#define RECORD_H


class Record
{
public:
    Record();
    Record(const QString & name);
    void addPropery(const QString & propertyName, const QSet<int> & values);
    const Property & getProperty(const QString & propertyName) const;
    bool hasProperty(const QString & propertyName) const;
    QString getName() const;
    QSet<Property> getProperties() const;
    void operator=(const Record & other);
    bool operator==(const Record & other) const;

private:
    QString name;
    QSet<Property> properties;
};

inline uint qHash(const Record & record, uint seed = 0)
{
    return qHash(record.getName(), seed);
}

#endif // RECORD_H
