/**
 * @file        log/log_progress.cpp
 * @author      Max Kofler (kofler.max.dev@gmail.com)
 * @brief       The file implementing the Progress related functions of the Log class
 * @copyright   Copyright (c) 2022 Max Kofler
 */

#include "log.h"

namespace Log{

	std::shared_ptr<Progress> Log::createProgress(const conf_Progress& conf){
		Progress* progress = new Progress(this, conf);
		std::shared_ptr<Progress> p = std::shared_ptr<Progress>(progress);
		_progresses.push_back(progress);

		//A new progress requires a new line
		for (const auto &stream : _streams){
			if (stream.second.enable_progress)
				*(stream.first) << std::endl;
		}

		return p;
	}

	void Log::removeProgress(Progress* p){
		for (uint32_t i = 0; i < _progresses.size(); i++){
			if (_progresses[i] == p){
				_progresses.erase(_progresses.begin()+i);
				break;
			}
		}
	}

	void Log::progressUpdated(Progress* progress){

		for (const auto &stream : _streams){

			if (!stream.second.enable_progress)
				continue;

			//If there is nothing to do, return immediately
			if (_progresses.size() == 0)
				return;

			std::lock_guard __guard(_m_logging);

			//Go up for all the progresses
			for (uint32_t i = 0; i < _progresses.size(); i++)
				*(stream.first) << "\033[F";

			for (uint32_t i = _progresses.size(); i > 0; i--){
				_progresses[i-1]->_m_bar.lock();
				*(stream.first) << _progresses[i-1]->_bar << "\n";
				_progresses[i-1]->_m_bar.unlock();
			}

			stream.first->flush();

		}

	}

}
