#include <QObject>
#include <QSet>

#ifndef PROPERTY_H
#define PROPERTY_H


class Property
{
public:
    Property();
    Property(const QString & name, const QSet<int> & values);
    void addValue(const int value);
    QString getName() const;
    QSet<int> getValues() const;
    Property & operator=(const Property & other);
    bool operator==(const Property & other) const;

private:
    QString name;
    QSet<int> values;
};

inline uint qHash(const Property & prop, uint seed = 0)
{
    return qHash(prop.getName(), seed);
}

#endif // PROPERTY_H
