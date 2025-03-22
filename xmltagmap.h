#include <QObject>
#include <QMap>

#ifndef XMLTAGMAP_H
#define XMLTAGMAP_H


struct TagInfo
{
    QString name;
    QList<QString> attributes;
    bool hasChildren;
    QString children;
    bool hasParent;
    QString parent;

    TagInfo(const QString & n, const QList<QString> & attrs, bool hasChild, const QString & child, bool hasPar, const QString & par)
        : name(n), attributes(attrs), hasChildren(hasChild), children(child), hasParent(hasPar), parent(par)
    {

    }
};


class XMLTagMap
{
public:
    XMLTagMap();
    const QList<TagInfo> & getValidTags(const QString & fileType) const;
    QString getTagHint(const QString & fileType) const;

private:
    QMap<QString, QList<TagInfo>> tagMap;
};

#endif // XMLTAGMAP_H
