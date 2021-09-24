#ifndef __LOG_H__
#define __LOG_H__

namespace Log{
    class Log;
}

extern Log::Log* hlog;

namespace Log{
    enum level{
        UE,
        UW,
        U,
        P,
        E,
        W,
        I,
        D,
        F,
        N,
        IO,
        MEM,
        FUNCALLS,
        A
    };

    class Log{

    public:
        Log(level loglevel);

        /**
         * @brief                           Returns if the global log variable is present and initialized
         */
        static bool                         check();

        level                               getLevel();
        void                                setLevel(level loglevel);
    
    private:
        level                               _loglevel;
    };
};

#define LOGUE(msg)

#endif