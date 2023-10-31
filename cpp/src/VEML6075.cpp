/*
Created by Jippe Heijnen on 31-10-23.

* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#include <VEML6075.hpp>
#include <iostream>

namespace sensors {

    VEML6075::VEML6075(std::string name) :
    _name(name)
    {}

    std::string VEML6075::get_name() const {
        return _name;
    }

    void VEML6075::test(std::string message) {

        std::cout << message << std::endl;

    }

}