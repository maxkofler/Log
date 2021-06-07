#ifndef LOG_H
#define LOG_H

class Log;
#include "logfunction.h"

extern Log* hlog;

#ifdef WIN32
    #define FUN() LogFunction logfun(__FUNCTION__, hlog)
#else
    #define FUN() LogFunction logfun(__PRETTY_FUNCTION__, hlog)
#endif

#define LOGUE(text) hlog->log(text, Log::UE);
#define LOGUW(text) hlog->log(text, Log::UW);
#define LOGU(text) hlog->log(text, Log::U);
#define LOGP(text) hlog->log(text, Log::P);
#define LOGE(text) hlog->log(text, Log::E);
#define LOGW(text) hlog->log(text, Log::W);
#define LOGI(text) hlog->log(text, Log::I);
#define LOGD(text) hlog->log(text, Log::D);
#define LOGF(text) hlog->log(text, Log::F);
#define LOGIO(text) hlog->log(text, Log::IO);
#define LOGMEM(text) hlog->log(text, Log::MEM);

#define LOGSP(level) hlog->startProgress(level);
#define LOGPP(text, level) hlog->printProgress(text, level);
#define LOGEP(level) hlog->endProgress(level);

#define LOG(text, level) hlog->log(text, level);
#define FLUSH() hlog->flush();

#include <vector>
#include <string>
#include <inttypes.h>
#include <sstream>
#include <bitset>

class Log
{
public:
    Log(int level, bool printFunNames);

    const static int UE = 1;
    const static int UW = 2;
    const static int U = 3;
    const static int P = 4;
    const static int E = 5;
    const static int W = 6;
    const static int I = 7;
    const static int D = 8;
    const static int IO = 9;
    const static int MEM = 10;
    const static int F = 11;

    const static int FUNCALLS = 75;
    const static int A = 100;

    void                        push(LogFunction*);

    void                        pop();

    void                        log(std::string text, int level);

    void                        logw(std::string text, int level);

    void                        startProgress(int level);

    void                        printProgress(std::string text, int level);

    void                        endProgress(int level);

    void                        flush();

    const static std::string    toHexString(uint16_t num){
        std::stringstream sstream;
        sstream << "0x" << std::hex << num;
        return sstream.str();
    }

    const static std::string    toBinString16(uint16_t num){
        return "0b" + std::bitset< 16 >( num ).to_string();
    }
    const static std::string    toBinString8(uint8_t num){
        return "0b" + std::bitset< 8 >( num ).to_string();
    }

private:
    std::vector<LogFunction* >  _functionStack;
    int                         _curLevel;

    bool                        _inProgress;

    bool                        _printFunNames;
};
#endif // LOG_H
