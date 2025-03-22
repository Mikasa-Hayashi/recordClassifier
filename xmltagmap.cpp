#include "xmltagmap.h"

XMLTagMap::XMLTagMap()
{
    tagMap["items"] = {
        TagInfo("items", {}, true, "item", false, ""),
        TagInfo("item", {"name"}, true, "properties", true, "items"),
        TagInfo("properties", {}, true, "property", true, "item"),
        TagInfo("property", {"name"}, true, "value", true, "properties"),
        TagInfo("value", {}, false, "", true, "property"),
    };

    tagMap["classes"] = {
        TagInfo("classes", {}, true, "class", false, ""),
        TagInfo("class", {"name"}, true, "property", true, "classes"),
        TagInfo("property", {"name", "condition", "values_count", "contains_value"}, true, "value", true, "class"),
        TagInfo("value", {}, false, "", true, "property")
    };

    tagMap["classification"] = {
        TagInfo("classification", {}, true, "class", false, ""),
        TagInfo("class", {"name"}, true, "item", true, "classification"),
        TagInfo("item", {"name"}, false, "", true, "class")
    };
}

const QList<TagInfo> & XMLTagMap::getValidTags(const QString &fileType) const
{
    static QList<TagInfo> emptyList;
    auto it = tagMap.find(fileType);
    return (it != tagMap.end()) ? it.value() : emptyList;
}

QString XMLTagMap::getTagHint(const QString & fileType) const
{
    QString hint;
    if (fileType == "items")
    {
        hint = "Допустимые теги для набора записей:\n";
    }
    else if (fileType == "classes")
    {
        hint = "Допустимые теги для набора классов:\n";
    }
    else
    {
        return hint;
    }

    const QList<TagInfo> & tags = getValidTags(fileType);
    for (const TagInfo & tag : tags)
    {
        hint += "<" + tag.name;
        if (!tag.attributes.isEmpty())
        {
            hint += " " + tag.attributes.join("=\"...\" ");
        }
        hint += ">";


    }
}
