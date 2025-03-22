#include <QObject>

#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H


enum class ErrorType
{
    XML_SYNTAX_ERROR,
    XML_INVALID_TAG,
    XML_INVALID_ATTRIBUTE,
    XML_INVALID_ATTRIBUTE_VALUE,
    INVALID_RECORD_COUNT_RANGE,
    INVALID_CLASS_COUNT_RANGE,
    INVALID_PROPERTY_COUNT_RANGE,
    INVALID_PROPERTY_VALUE_COUNT_RANGE,
    INVALID_PROPERTY_VALUE_RANGE,
    DUPLICATE_RECORD_NAME,
    DUPLICATE_CLASSE_NAME,
    DUPLICATE_PROPERTY_NAME,
    DUPLICATE_PROPERTY_VALUE,
    INVALID_FILE_PATH,
    UNKNOWN_ERROR
};


struct Error
{
    ErrorType type;
    QString file;
    QString context;
    int lineNumber;
    QString description;

    Error(ErrorType t, const QString & f,const QString & ctx, int line, const QString & desc)
        : type(t), file(f), context(ctx), lineNumber(line), description(desc)
    {

    }

    QString toString() const
    {
        QString result;
        switch(type)
        {
            case ErrorType::XML_SYNTAX_ERROR:
                result = QString("Невозможно обработать файл \"%1\". Возможно, синтаксис файла неверный.").arg(file);
                break;
            case ErrorType::XML_INVALID_TAG:
                result = QString();
                break;
            case ErrorType::XML_INVALID_ATTRIBUTE:

                break;
            case ErrorType::XML_INVALID_ATTRIBUTE_VALUE:

                break;
            case ErrorType::INVALID_RECORD_COUNT_RANGE:

                break;
            case ErrorType::INVALID_CLASS_COUNT_RANGE:

                break;
            case ErrorType::INVALID_PROPERTY_COUNT_RANGE:

                break;
            case ErrorType::INVALID_PROPERTY_VALUE_COUNT_RANGE:

                break;
            case ErrorType::INVALID_PROPERTY_VALUE_RANGE:

                break;
            case ErrorType::DUPLICATE_RECORD_NAME:

                break;
            case ErrorType::DUPLICATE_CLASSE_NAME:

                break;
            case ErrorType::DUPLICATE_PROPERTY_NAME:

                break;
            case ErrorType::DUPLICATE_PROPERTY_VALUE:

                break;
            case ErrorType::INVALID_FILE_PATH:

                break;
            case ErrorType::UNKNOWN_ERROR:

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
