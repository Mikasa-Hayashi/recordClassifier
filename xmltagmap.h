#include <QObject>

#ifndef XMLTAGMAP_H
#define XMLTAGMAP_H


struct TagInfo
{
    QString name;
    QList<QString> attributes;
    bool hasChildren;
    QList<QString> children;

    TagInfo(const QString & n, const QList<QString> & attrs, bool hasKids, const QList<QString> & kids = {})
        : name(n), attributes(attrs), hasChildren(hasKids), children(kids)
    {

    }
};


class XMLTagMap
{
public:
    XMLTagMap();
};

#endif // XMLTAGMAP_H
