#include "classifier.h"

Classifier::Classifier() : records(), rules()
{

}

bool Classifier::loadData(const QString & itemsPath, const QString & classesPath)
{
    records.clear();
    rules.clear();


    Record closet("шкаф");
    QSet<int> color;
    color.insert(1);
    color.insert(2);
    closet.addPropery("цвет", color);

    QSet<int> size;
    size.insert(10);
    size.insert(40);
    size.insert(60);
    closet.addPropery("размер", size);

    records.insert(closet);


    Record table("стол");
    color.clear();
    color.insert(1);
    color.insert(4);
    table.addPropery("цвет", color);

    size.clear();
    size.insert(20);
    size.insert(40);
    table.addPropery("размер", size);

    QSet<int> cover;
    cover.insert(44);
    table.addPropery("покрытие", cover);

    records.insert(table);

    Rule withCover("с покрытием", "покрытие", ConditionType::Exist);
    rules.insert(withCover);

    Rule valuable("объемный", "размер", ConditionType::ValuesCount, 3);
    rules.insert(valuable);

    Rule blue("синий", "цвет", ConditionType::ContainsValues, 1);
    rules.insert(blue);

    QSet<int> values;
    values.insert(44);
    values.insert(21);


    Rule matte("матовый", "покрытие", ConditionType::ValuesMatch, values);
    rules.insert(matte);


    return true;
}

void Classifier::classify()
{
    results.clear();

    for (const Rule & rule : rules)
    {
        results[rule.getClassName()] = QSet<QString>();
    }

    for (const Record & record : records)
    {
        for (const Rule & rule : rules)
        {
            if (isMatchesRule(record, rule))
            {
                results[rule.getClassName()].insert(record.getName());
            }
        }
    }
}

bool Classifier::isMatchesRule(const Record & record, const Rule & rule)
{
    if (!record.hasProperty(rule.getPropertyName()))
    {
        return false;
    }

    const Property & prop = record.getProperty(rule.getPropertyName());

    switch(rule.getCondition())
    {
        case ConditionType::Exist:
            return true;

        case ConditionType::ValuesCount:
            return prop.getValues().size() == rule.getTargetCount();

        case ConditionType::ContainsValues:
            return prop.getValues().contains(rule.getTargetValue());

        case ConditionType::ValuesMatch:
            return prop.getValues() == rule.getTargetValues();

        default:
            return false;
    }
}

bool Classifier::saveResults(const QString &outputPath)
{
    qDebug() << results.size();

    QHash<QString, QSet<QString>>::const_iterator it = results.constBegin();
    while (it != results.constEnd())
    {
        qDebug() << it.key() << "-" << it.value();
        ++it;
    }



    return true;
}
