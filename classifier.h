#include <QObject>
#include <QSet>
#include <QHash>
#include <QDebug>
#include "record.h"
#include "rule.h"
#include "xmlparser.h"
#include "errorhandler.h"

#ifndef CLASSIFIER_H
#define CLASSIFIER_H


class Classifier
{
public:
    Classifier();
    bool loadData(const QString & itemsPath, const QString & classesPath);
    bool validate();
    void classify();
    bool saveResults(const QString & outputPath);

private:
    QSet<Record> records;
    QSet<Rule> rules;
    QHash<QString, QSet<QString>> results;
    ErrorHandler errorHandler;

    bool isMatchesRule(const Record & record, const Rule & rule);
};

#endif // CLASSIFIER_H
