/**
 * @file        progress/progress.cpp
 * @author      Max Kofler (kofler.max.dev@gmail.com)
 * @brief       The file implementing the Progress class
 * @copyright   Copyright (c) 2022 Max Kofler
 */

#include "progress.h"

#include <stddef.h>

namespace Log {

    Progress::Progress(Log* log, const conf_Progress& config) :
        _log(log),
        _config(config){
    }

    Progress::~Progress(){
        _log->removeProgress(this);
    }

    bool Progress::update(uint32_t p_max, uint32_t p_cur, const std::string& preBar){

        //Do some sanity checks
        if (p_cur > p_max || p_max == 0)
            return false;

        //Cache variables
        uint32_t terminal_width = _log->getTerminalWidth();
        uint32_t len_preBar = preBar.length();
        uint32_t len_prefix = _config.prefix.length();
        uint32_t maxSteps = _config.maxSteps;

        //If the progress bar fits, or we skip rendering the bar
        bool fits = true;

        // " " + " [" + "] 100%"
        uint32_t min_width = len_prefix + 1 + len_preBar + 8;
        if (terminal_width <= (min_width + maxSteps)){
            int32_t new_steps = maxSteps - (min_width + maxSteps - terminal_width);
            //std::cout << "min_width - available_width=" << (min_width + maxSteps - terminal_width) << std::endl << std::endl;

            fits = new_steps > 0;
            if (fits)
                maxSteps = new_steps;
            else
                return false;
        }

        uint32_t progress;
        if (p_max / (double)maxSteps < maxSteps){
            double p_per_step = p_max / (double)maxSteps;
            progress = p_cur / p_per_step;
        } else {
            uint32_t p_per_step = p_max / (double)maxSteps;
            progress = p_cur / p_per_step;
        }
        uint32_t spaces = terminal_width - min_width - maxSteps;
        uint32_t percentage = ((double)p_cur / (double)p_max) * 100.0;

        //For debugging
        //std::cout << "mw: " << min_width << ", ms: " << maxSteps << ", pps: " << p_per_step << ", sp: " << spaces << ", pr: " << progress << ", pc: " << percentage << std::endl;

        std::string output = _config.prefix + " ";

        if (spaces > 0)
            output += std::string(spaces, ' ');

        output += preBar + " ";
        output += "[" + std::string(progress, '#') + std::string(maxSteps - progress, ' ') + "] ";
        output += std::to_string(percentage) + "%";
        output += std::string(terminal_width - output.length(), ' ');

        //Only output if the bar has changed
        if (output != _bar){
            #ifndef LOG_NOMUTEX
                _m_bar.lock();
            #endif

            _bar = output;

            #ifndef LOG_NOMUTEX
                _m_bar.unlock();
            #endif

            //Notify the Log instance
            _log->progressUpdated(this);
        }

        return true;
    }

}


