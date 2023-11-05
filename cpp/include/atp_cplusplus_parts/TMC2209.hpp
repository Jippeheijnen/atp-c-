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

#ifndef ATP_CPLUSPLUS_TMC2209_HPP
#define ATP_CPLUSPLUS_TMC2209_HPP

#include <iostream>
#include <array>

namespace sensors {

    class TMC2209 {

        // internal registers

        // General

        // 0x00 10bits
        uint32_t GCONF = 0x00;

        //0x01 3bits
        uint32_t GSTAT = 0x00;

        // 0x02 8bits
        uint32_t IFCNT = 0x00;

        // 0x03 4bits
        uint32_t SLAVECONT = 0x00;

        // 0x04 16bits
        uint32_t OTP_PROG = 0x00;

        // 0x05 24bits
        uint32_t OTP_READ = 0x00;

        // 0x06 10+8bits
        uint32_t IOIN = 0x00;

        // 0x07 5+2bits
        uint32_t FACTORY_CONF = 0x00;


        // Velocity Dependent Control

        // 0x10 5+5+4bits
        uint32_t IHOLD_IRUN = 0x00;

        // 0x11 8bits
        uint32_t TPOWER_DOWN = 0x00;

        // 0x12 20bits
        uint32_t TSTEP = 0x00;

        // 0x13 20bits
        uint32_t TPWMTHRS = 0x00;

        // 0x22 24bits
        uint32_t VACTUAL = 0x00;


        // StallGuard Control

        // 0x14 20bits
        uint32_t TCOOLTHRS = 0x00;

        // 0x40 8bits
        uint32_t SGTHRS = 0x00;

        // 0x41 10bits
        uint32_t SG_RESULT = 0x00;

        // 0x42 16bits
        uint32_t COOLCONF = 0x00;


        // Sequencer Registers

        // 0x6A 10bits
        uint32_t MSNCT = 0x00;

        // 0x6B 9+9bits
        uint32_t MSCURACT = 0x00;


        // Chopper Control Registers

        // 0x6C 32bits
        uint32_t CHOPCONF = 0x00;

        // 0x6F 32bits
        uint32_t DRV_STATUS = 0x00;

        // 0x70 22bits
        uint32_t PWMCONF = 0x00;

        // 0x71 9+8bits
        uint32_t PWM_SCALE = 0x00;

        // 0x72 8+8bits
        uint32_t PWM_AUTO = 0x00;




    public:

        TMC2209();


    };

}

#endif //ATP_CPLUSPLUS_TMC2209_HPP
