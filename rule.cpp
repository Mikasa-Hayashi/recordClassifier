#include "rule.h"

Rule::Rule() : className(""), propertyName(""), condition(), targetCount(0), targetValue(0), targetValues()
{

}

Rule::Rule(const QString & className, const QString & propertyName, ConditionType condition)
{
    this->className = className;
    this->propertyName = propertyName;
    this->condition = condition;
}

Rule::Rule(const QString & className, const QString & propertyName, ConditionType condition, int value)
{
    this->className = className;
    this->propertyName = propertyName;
    this->condition = condition;
    this->targetCount = value;
    this->targetValue = value;
}

Rule::Rule(const QString & className, const QString & propertyName, ConditionType condition, const QSet<int> & targetValues)
{
    this->className = className;
    this->propertyName = propertyName;
    this->condition = condition;
    this->targetValues = targetValues;
}

QString Rule::getClassName() const
{
    return className;
}

QString Rule::getPropertyName() const
{
    return propertyName;
}

ConditionType Rule::getCondition() const
{
    return condition;
}

int Rule::getTargetCount() const
{
    return targetCount;
}

int Rule::getTargetValue() const
{
    return targetValue;
}

QSet<int> Rule::getTargetValues() const
{
    return targetValues;
}

void Rule::operator=(const Rule &other)
{
    className = other.className;
    propertyName = other.propertyName;
    condition = other.condition;
    targetCount = other.targetCount;
    targetValue = other.targetValue;
    targetValues = other.targetValues;
}

bool Rule::operator==(const Rule &other) const
{
    return className == other.className &&
           propertyName == other.propertyName &&
           condition == other.condition &&
           targetCount == other.targetCount &&
           targetValue == other.targetValue &&
           targetValues == other.targetValues;
}
