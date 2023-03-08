/**
 * @file        include/progress.h
 * @author      Max Kofler (kofler.max.dev@gmail.com)
 * @brief       The header declaring the Progress class
 * @copyright   Copyright (c) 2023 Max Kofler
 */

#ifndef __PROGRESS_H__
#define __PROGRESS_H__

#include <memory>

namespace Log{
    class Log;
}

#include "log.h"

namespace Log {

    class conf_Progress {
    public:
        /* A progress bar looks like this:

        <prefix>            <preBar> [######################] xxx%
                                      <      maxSteps      >

        */

        /// @brief  The prefix to display
        std::string             prefix;

        /// @brief  The maximum amount of steps to display
        uint32_t                maxSteps;

    };

    class Progress{

    public:

        //Delete the copy constructor, keep move constructor
        Progress(const Progress&) = delete;
        Progress(Progress &&) = default;
        ~Progress();

        /**
         * @brief   Updates the progress bar
         * @param   max             The maximum value (100%)
         * @param   cur             The current value
         * @param   preBar          The text to display before the bar
         */
        bool                        update(uint32_t max, uint32_t cur, const std::string& preBar = "");

        //The Log class is a friend
        friend class Log;
    private:

        /**
         * @brief   Private constructor, only the parent can create a Progress
         * @param   parent          The parent this Progress belongs to
         * @param   config          The configuration to use
         */
        Progress(Log* parent, const conf_Progress& config);

        /// @brief  A reference to the parent Log object
        Log*                        _log;

        /// @brief  The configuration to use
        conf_Progress               _config;

        /// @brief  Stores the last rendered bar
        std::string                 _bar = "";

        /// @brief  A mutex to protect the string from being updated while outputting
        std::mutex                  _m_bar;

    };

}

#endif
