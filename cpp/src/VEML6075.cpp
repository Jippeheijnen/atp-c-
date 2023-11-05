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

    VEML6075::VEML6075() {
        srandom(time(nullptr));
    };

    uint16_t VEML6075::operator>>(const uint8_t rhs) {
        uint16_t response;

        switch (rhs) {
            case 0x0:
                // crafting the response
                response = (0x00 << 8); // first shift the most significant bits to the left.
                response |= this->UV_CONF; // and add the least significant bits.
                break;
            case 0x1:
                response = 0x00;
                break;
            case 0x2:
                response = 0x00;
                break;
            case 0x3:
                response = 0x00;
                break;
            case 0x4:
                response = 0x00;
                break;
            case 0x5:
                response = 0x00;
                break;
            case 0x6:
                response = 0x00;
                break;
            case 0x7:
                this->UVA_Data_LSB = uint8_t(random());
                this->UVA_Data_MSB = uint8_t(random());
                response = (this->UVA_Data_MSB << 8);
                response |= this->UVA_Data_LSB;
                break;
            case 0x8:
                response = 0x00;
                break;
            case 0x9:
                this->UVB_Data_LSB = uint8_t(random());
                this->UVB_Data_MSB = uint8_t(random());
                response = (this->UVB_Data_MSB << 8);
                response |= this->UVB_Data_LSB;
                break;
            case 0xA:
                this->UVCOMP1_Data_LSB = uint8_t(random());
                this->UVCOMP1_Data_MSB = uint8_t(random());
                response = (this->UVCOMP1_Data_MSB << 8);
                response |= this->UVCOMP1_Data_LSB;
                break;
            case 0xB:
                this->UVCOMP2_Data_LSB = uint8_t(random());
                this->UVCOMP2_Data_MSB = uint8_t(random());
                response = (this->UVCOMP2_Data_MSB << 8);
                response |= this->UVCOMP2_Data_LSB;
                break;
            case 0xC:
                response = (this->ID_MSB << 8);
                response |= this->ID_LSB;
                break;
            default:
                // this is to catch incorrect command codes:
                response = 0x66;
        }


        // this checks whether rhs is even (for testing purposes, not necessary anymore).
        //(rhs & 1) == 0 ? result = 0x00 : result = 0x01;

        return response;
    }

    void VEML6075::operator<<(std::array<uint8_t, 3> &rhs) {
        uint8_t REG, L, H;
        REG = rhs[0];
        L = rhs[1];
        H = rhs[2];

        switch (REG) {
            case 0x0:
                UV_CONF = L;
                return;
            case 0x1:
                return;
            case 0x2:
                return;
            case 0x3:
                return;
            case 0x4:
                return;
            case 0x5:
                return;
            case 0x6:
                return;
            default:
                return;
        }

    }

}