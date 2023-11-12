#include "Error.h"
#include <stdexcept>

void Error::RaiseRuntimeError(const std::string& _message) {
    throw std::runtime_error(_message);
}

void Error::RaiseOutOfRangeError(const std::string& _message) {
    throw std::out_of_range(_message);
}

void Error::RaiseLogicError(const std::string& _message) {
    throw std::logic_error(_message);
}

void Error::RaiseDomainError(const std::string& _message) {
    throw std::domain_error(_message);
}

void Error::RaiseInvalidArgument(const std::string& _message) {
    throw std::invalid_argument(_message);
}

void Error::RaiseLengthError(const std::string& _message) {
    throw std::length_error(_message);
}

void Error::RaiseRangeError(const std::string& _message) {
    throw std::range_error(_message);
}

void Error::RaiseOverflowError(const std::string& _message) {
    throw std::overflow_error(_message);
}

void Error::RaiseUnderflowError(const std::string& _message) {
    throw std::underflow_error(_message);
}

void Error::RaiseSystemError(const std::string& _message) {
    //throw std::system_error(std::make_error_code(std::errc::io_error), _message);
}

void Error::RaiseFutureError(const std::string& _message) {
    //throw std::future_error(std::future_errc::broken_promise, _message);
}
