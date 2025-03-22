#include "errorhandler.h"

ErrorHandler::ErrorHandler()
{

}

void ErrorHandler::addError(const QString &message)
{
    errors.append(message);
}

bool ErrorHandler::hasErrors() const
{
    return !errors.isEmpty();
}

void ErrorHandler::printErrors() const
{

}

void ErrorHandler::clear()
{
    errors.clear();
}
