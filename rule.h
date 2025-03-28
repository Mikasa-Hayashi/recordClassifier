#include <QObject>
#include <QSet>

#ifndef RULE_H
#define RULE_H

enum ConditionType
{
    Exist,
    ValuesCount,
    ContainsValues,
    ValuesMatch
};

class Rule
{
public:
    Rule();
    Rule(const QString & className, const QString & propertyName, ConditionType condition);
    Rule(const QString & className, const QString & propertyName, ConditionType condition, int value);
    Rule(const QString & className, const QString & propertyName, ConditionType condition, const QSet<int> & targetValues);
    QString getClassName() const;
    QString getPropertyName() const;
    ConditionType getCondition() const;
    int getTargetCount() const;
    int getTargetValue() const;
    QSet<int> getTargetValues() const;
    Rule & operator=(const Rule & other);
    bool operator==(const Rule & other) const;

private:
    QString className;
    QString propertyName;
    ConditionType condition;
    int targetCount;
    int targetValue;
    QSet<int> targetValues;
};

inline uint qHash(const Rule & rule, uint seed = 0)
{
    return qHash(rule.getClassName(), seed);
}

#endif // RULE_H
