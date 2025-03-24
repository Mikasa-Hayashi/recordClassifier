#include <QObject>

#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H


enum class ErrorSituation
{
    INVALID_IN_FILE_PATH,
    INVALID_OUT_FILE_PATH,
    XML_SYNTAX_ERROR,
    XML_INVALID_TAG,
    XML_MISSED_TAG,
    XML_EXTRA_ATTRIBUTE,
    XML_MISSED_ATTRIBUTE,
    XML_INVALID_ATTRIBUTE_VALUE,
    XML_INVALID_ATTRIBUTE_VALUE_RANGE,
    INVALID_RECORD_COUNT_RANGE,
    INVALID_CLASS_COUNT_RANGE,
    INVALID_PROPERTY_COUNT_RANGE,
    INVALID_PROPERTY_VALUE_COUNT_RANGE,
    INVALID_PROPERTY_VALUE_RANGE,
    DUPLICATE_RECORD_NAME,
    DUPLICATE_CLASSE_NAME,
    DUPLICATE_PROPERTY_NAME,
    DUPLICATE_PROPERTY_VALUE,
    UNKNOWN_ERROR
};


enum class RangeErrorSubType
{
    TOO_MANY,
    EMPTY
};


struct Error
{
    ErrorSituation situation;
    RangeErrorSubType subType;
    QString file;
    QString context;
    int lineNumber;
    QString extraInfo;


    Error(ErrorSituation t, RangeErrorSubType s, const QString & f,const QString & ctx, int line, const QString & extra)
        : situation(t), subType(s), file(f), context(ctx), lineNumber(line), extraInfo(extra)
    {

    }

    QString toString() const
    {
        QString result;
        switch(situation)
        {
            case ErrorSituation::INVALID_IN_FILE_PATH:
                result = QString("Неверно указан файл «%1» с входными данными. Возможно, файл не существует.").arg(file);
                break;
            case ErrorSituation::INVALID_OUT_FILE_PATH:
                result = QString("Неверно указан файл «%1» для выходных данных. Возможно, указанного расположения не существует или нет прав на запись.").arg(file);
                break;
            case ErrorSituation::XML_SYNTAX_ERROR:
                result = QString("Невозможно обработать файл «%1». Возможно, синтаксис файла неверный.").arg(file);
                break;
            case ErrorSituation::XML_INVALID_TAG:
                result = QString("Указан неверный тег <%1> в файле «%2».").arg(context, file);
                break;
            case ErrorSituation::XML_MISSED_TAG:
                result = QString("Неверный порядок тегов в файле «%1». После тега <%2> должен следовать тег <%3>.").arg(file, context, extraInfo);
                break;
            case ErrorSituation::XML_EXTRA_ATTRIBUTE:
                result = QString("Лишний атрибут «%1» в теге <%2>. Тег <%2> должен включать в себя только атрибут «name».").arg(context, extraInfo);
                break;
            case ErrorSituation::XML_MISSED_ATTRIBUTE:
                result = QString("В теге <%1> отсутствует атрибут «%2».").arg(context, extraInfo);
                break;
            case ErrorSituation::XML_INVALID_ATTRIBUTE_VALUE:
                result = QString("В теге <%1> неверное значение атрибута «%2».").arg(context, extraInfo);
                break;
            case ErrorSituation::XML_INVALID_ATTRIBUTE_VALUE_RANGE:
                result = QString("В теге <%1> значение атрибута «name» превышает допустимую длину").arg(context);
                break;
            case ErrorSituation::INVALID_RECORD_COUNT_RANGE:
                if (subType == RangeErrorSubType::EMPTY)
                {
                    result = QString("Во входном файле «%1» отсутствуют записи").arg(file);
                }
                else if (subType == RangeErrorSubType::TOO_MANY)
                {
                    result = QString("В файле «%1» определено более 100 записей").arg(file);
                }
                break;
            case ErrorSituation::INVALID_CLASS_COUNT_RANGE:
                if (subType == RangeErrorSubType::EMPTY)
                {
                    result = QString("Во входном файле «%1» отсутствуют классы").arg(file);
                }
                else if (subType == RangeErrorSubType::TOO_MANY)
                {
                    result = QString("В файле «%1» определено более 100 классов").arg(file);
                }
                break;
            case ErrorSituation::INVALID_PROPERTY_COUNT_RANGE:
                if (subType == RangeErrorSubType::EMPTY)
                {
                    result = QString("В записи «%1» отсутствуют свойства").arg(context);
                }
                else if (subType == RangeErrorSubType::TOO_MANY)
                {
                    result = QString("В записи «%1» определено более 100 свойств").arg(context);
                }
                break;
            case ErrorSituation::INVALID_PROPERTY_VALUE_COUNT_RANGE:
                if (subType == RangeErrorSubType::EMPTY)
                {
                    result = QString("В свойстве «%1» отсутствуют значения").arg(context);
                }
                else if (subType == RangeErrorSubType::TOO_MANY)
                {
                    result = QString("В свойстве «%1» записи «%2» определено более 100 значений").arg(context, extraInfo);
                }
                break;
            case ErrorSituation::INVALID_PROPERTY_VALUE_RANGE:
                result = QString("Неверный диапазон вводимых значений свойства в свойстве «%1» записи «%2»").arg(context, extraInfo);
                break;
            case ErrorSituation::DUPLICATE_RECORD_NAME:
                result = QString("Запись «%1» не уникальна").arg(context);
                break;
            case ErrorSituation::DUPLICATE_CLASSE_NAME:
                result = QString("Класс «%1» не уникален").arg(context);
                break;
            case ErrorSituation::DUPLICATE_PROPERTY_NAME:
                result = QString("В записи «%1» свойство «%2» не уникально").arg(context, extraInfo);
                break;
            case ErrorSituation::DUPLICATE_PROPERTY_VALUE:
                result = QString("В записи «%1» значения свойства «%2» не уникальны").arg(context, extraInfo);
                break;
            case ErrorSituation::UNKNOWN_ERROR:

                break;
        }
    }
};


class ErrorHandler
{
public:
    ErrorHandler();
    void addError(const QString & message);
    bool hasErrors() const;
    void printErrors() const;
    void clear();

private:
    QList<QString> errors;
};

#endif // ERRORHANDLER_H
