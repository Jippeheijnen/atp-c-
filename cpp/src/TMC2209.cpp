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

#include <TMC2209.hpp>
#include <bitset>

namespace sensors {

    TMC2209::TMC2209(uint8_t slave_addr)
            : slave_addr(slave_addr) {}


    uint32_t TMC2209::operator<<(std::array<uint8_t, 8> &rhs) {
        uint8_t sync_nibble, slave_addr, register_addr, CRC;
        uint32_t data;
        bool write = 0; // 1 for write 0 for read.

        // dissecting the received datagram (LSB to MSB)
        sync_nibble = rhs[0];
        slave_addr = rhs[1];
        register_addr = rhs[2];

        // this puts the bytes in the correct order from MSB to LSB
        data = (rhs[6] << 24) |
               ((rhs[5] << 16) |
                ((rhs[4] << 8) |
                 rhs[3]));

        CRC = rhs[7];

        // ignore incoming datagram altogether.
        if (slave_addr != this->slave_addr) {
            return 0;
        }

        // checking for read or write
        std::bitset<8> bs(register_addr);
        write = bs[6];

        // removing the read/write bit to get actual addr
        uint8_t actual_reg_addr = register_addr &= ~(1 << 7);

        // handling the registers
        switch (actual_reg_addr) {
            case 0x00: // GCONF (RW)
                if (write) {
                    this->GCONF = data;
                    auto bs = std::bitset<10>(data);
                    I_scale_analog = bs[0];
                    internal_Rsense = bs[1];
                    en_SpreadCycle = bs[2];
                    shaft = bs[3];
                    index_otpw = bs[4];
                    index_step = bs[5];
                    pdn_disable = bs[6];
                    mstep_reg_select = bs[7];
                    multistep_filt = bs[8];
                    test_mode = bs[9];
                } else /*read*/ {
                    return this->GCONF;
                }
                break;
            case 0x01: // GSTAT
                if (write) {

                } else /*read*/ {

                }
                break;
            case 0x02: // IFCNT
                if (write) {

                } else /*read*/ {

                }
                break;
            case 0x03: // SLAVECONT
                if (write) {

                } else /*read*/ {

                }
                break;
            case 0x04: // OTP_PROG
                if (write) {

                } else /*read*/ {

                }
                break;
            case 0x05: // OTP_READ
                if (write) {

                } else /*read*/ {

                }
                break;
            case 0x06: // IOIN
                if (write) {

                } else /*read*/ {

                }
                break;
            case 0x07: // FACTORY_CONF
                if (write) {

                } else /*read*/ {

                }
                break;
            case 0x10: // IHOLD_IRUN
                if (write) {

                } else /*read*/ {

                }
                break;
            case 0x11: // TPOWER_DOWN
                if (write) {

                } else /*read*/ {

                }
                break;
            case 0x12: // TSTEP
                if (write) {

                } else /*read*/ {

                }
                break;
            case 0x13: // TPWMTHRS
                if (write) {

                } else /*read*/ {

                }
                break;
            case 0x22: // VACTUAL
                if (write) {

                } else /*read*/ {

                }
                break;
            case 0x14: // TCOOLTHRS
                if (write) {

                } else /*read*/ {

                }
                break;
            case 0x40: // SGTHRS
                if (write) {

                } else /*read*/ {

                }
                break;
            case 0x41: // SG_RESULT
                if (write) {

                } else /*read*/ {

                }
                break;
            case 0x42: // COOLCONF
                if (write) {

                } else /*read*/ {

                }
                break;
            case 0x6A: // MSNCT
                if (write) {

                } else /*read*/ {

                }
                break;
            case 0x6B: // MSCURACT
                if (write) {

                } else /*read*/ {

                }
                break;
            case 0x6C: // CHOPCONF
                if (write) {

                } else /*read*/ {

                }
                break;
            case 0x6F: // DRV_STATUS
                if (write) {

                } else /*read*/ {

                }
                break;
            case 0x70: // PWMCONF
                if (write) {

                } else /*read*/ {

                }
                break;
            case 0x71: // PWM_SCALE
                if (write) {

                } else /*read*/ {

                }
                break;
            case 0x72: // PWM_AUTO
                if (write) {

                } else /*read*/ {

                }
                break;
            default:
                break;


        }


    };

}