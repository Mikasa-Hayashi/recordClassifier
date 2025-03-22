#include "xmlparser.h"

XMLParser::XMLParser(ErrorHandler & handler) : errorHandler(handler)
{

}

bool XMLParser::parseRecords(const QString &filePath, QSet<Record> &records)
{

}

bool XMLParser::parseRules(const QString &filePath, QSet<Rule> &rules)
{

}

bool XMLParser::writeResults(const QString &filePath, const QHash<QString, QSet<QString> > &results)
{

}
