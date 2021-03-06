/*
    Lawyer Race - A game about escaping the law
    Copyright (C) 2012 Samuel Andersson

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


/* Logging facilities */

#ifndef _LOG_H_
#define _LOG_H_

#include <string>
#include <iostream>

namespace lg
{

std::string get_timestamp(const time_t& t, const std::string& format="%Y-%m-%d %H:%M:%S");


class Logger {
public:
    static Logger log_debug;
    static Logger log_error;

    /**
     *  Operator()
     *
     *  @return The outstream of the current Logger. If no outstream is set, std::cout is returned.
     */
    std::ostream& operator()();


    /**
     *  Sets the outstream.
     *
     *  @param os The outstream.
     */
    void set_ostream(std::ostream* os);

private:
    Logger():m_name("-unknown-") {} //this cannot be called.

    /**
     *  Constructor
     *
     *  @param name Name of the logger
     */
    Logger(std::string name);


    /**
     *  Destructor
     */
    ~Logger();

    std::string m_name;  ///< Name of the logger
};

} //namespace lg

#define LOG_DEBUG lg::Logger::log_debug()
#define LOG_ERROR lg::Logger::log_error()

#endif
