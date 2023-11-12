#pragma once
#include <string>

class Error {
public:
    static void RaiseRuntimeError(const std::string& _message);
    static void RaiseOutOfRangeError(const std::string& _message);
    static void RaiseLogicError(const std::string& _message);
    static void RaiseDomainError(const std::string& _message);
    static void RaiseInvalidArgument(const std::string& _message);
    static void RaiseLengthError(const std::string& _message);
    static void RaiseRangeError(const std::string& _message);
    static void RaiseOverflowError(const std::string& _message);
    static void RaiseUnderflowError(const std::string& _message);
    static void RaiseSystemError(const std::string& _message);
    static void RaiseFutureError(const std::string& _message);   
};

