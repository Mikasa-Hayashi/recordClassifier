#include <QObject>
#include <QSet>
#include <QXmlStreamReader>
#include "record.h"
#include "rule.h"
#include "errorhandler.h"

#ifndef XMLPARSER_H
#define XMLPARSER_H


class XMLParser
{
public:
    XMLParser(ErrorHandler & handler);
    bool parseRecords(const QString & filePath, QSet<Record> & records);
    bool parseRules(const QString & filePath, QSet<Rule> & rules);
    bool writeResults(const QString & filePath, const QHash<QString, QSet<QString>> & results);

private:
    ErrorHandler & errorHandler;

    Record parseRecord(QXmlStreamReader & reader);
    Rule parseRule(QXmlStreamReader & reader);
    QSet<int> parseValues(QXmlStreamReader & reader);
};

#endif // XMLPARSER_H
