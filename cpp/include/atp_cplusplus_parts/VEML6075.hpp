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

#ifndef ATP_CPLUSPLUS_VEML6075_HPP
#define ATP_CPLUSPLUS_VEML6075_HPP

#include <string>
#include <array>

namespace sensors {

    class VEML6075 {

        std::string _name;

        // internal registers
        volatile uint8_t UV_CONF = 0x00; // for writing only low address

        volatile uint8_t UVA_Data_LSB = 0x00;
        volatile uint8_t UVA_Data_MSB = 0x00;

        volatile uint8_t UVB_Data_LSB = 0x00;
        volatile uint8_t UVB_Data_MSB = 0x00;

        volatile uint8_t UVCOMP1_Data_LSB = 0x00;
        volatile uint8_t UVCOMP1_Data_MSB = 0x00;

        volatile uint8_t UVCOMP2_Data_LSB = 0x00;
        volatile uint8_t UVCOMP2_Data_MSB = 0x00;

        volatile uint8_t ID_LSB = 0x26;
        volatile uint8_t ID_MSB = 0x00;


    public:
        VEML6075(std::string name);

        std::string get_name() const;

        void test(std::string message);

    };

}
#endif //ATP_CPLUSPLUS_VEML6075_HPP
