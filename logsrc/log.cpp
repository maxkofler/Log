#include "log.h"

#include <iostream>


Log::Log(int level, bool printFunNames, bool indent){
    this->_curLevel = level;
    this->_printFunNames = printFunNames;
    this->_indent = indent;
}

void Log::log(std::string text, int level){
    logentry_t entry;
    entry.function = this->_functionStack.back()->name();
    entry.text = text;
    entry.level = level;
    this->trace.add(entry);
    if (level <= _curLevel){
        std::cout.flush();
        std::cout << p_getIndent();
        if (this->_printFunNames){
            std::cout << "(" << level << ")";
            std::cout << "[" << this->_functionStack.back()->name() << "]>>";
        }
        std::cout << text << std::endl;
        std::cout.flush();
    }
}

void Log::logw(std::string text, int level){
    logentry_t entry;
    entry.function = this->_functionStack.back()->name();
    entry.text = text;
    entry.level = level;
    this->trace.add(entry);
    if (level <= _curLevel){
        std::cout.flush();
        std::cout << p_getIndent();
        if (this->_printFunNames){
            std::cout << "(" << level << ")";
            std::cout << "[" << this->_functionStack.back()->name() << "]>>";
        }
        std::cout << text;
        std::cout.flush();
    }
}

inline void Log::flush(){
    std::cout.flush();
}

void Log::push(LogFunction *fun){
    this->_functionStack.push_back(fun);
}

void Log::pop(){
    this->_functionStack.pop_back();
}


void Log::startProgress(int level){
    if (level <= _curLevel)
        this->_inProgress = true;
}

void Log::printProgress(std::string text, int level){
    logentry_t entry;
    entry.function = this->_functionStack.back()->name();
    entry.text = text;
    entry.level = level;
    this->trace.add(entry);
    if (level <= _curLevel){
        this->logw(text, level);
        std::cout << "\r";
        this->flush();
    }
}

void Log::endProgress(int level){
    if (level <= _curLevel){
        std::cout << std::endl;
        this->_inProgress = false;
    }
}
