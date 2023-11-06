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

    /**
     * Trinamic Stepper Driver that uses single-wire UART.
     */
    class TMC2209 {

        /*
         * This is the slave address physically configured with the MS1 and MS2 pins.
         * The address can differ between 0x00 and 0x03 (default 0x00).
         */
        uint8_t slave_addr = 0x00;


        // global configuration flags
        volatile bool
        I_scale_analog =        1,
        internal_Rsense =       0,
        en_SpreadCycle =        0,
        shaft =                 0,
        index_otpw =            0,
        index_step =            0,
        pdn_disable =           0,
        mstep_reg_select =      0,
        multistep_filt =        1,
        test_mode =             0,
        
        // global status flags
        reset =                 0,
        drv_err =               0,
        uv_cp =                 0;

        // otp configuration memory
        // otp_en_SpreadCycle =    0,
        // OTP_IHOLD =             0,
        // OTP_IHOLDDELAY =        0,
        // otp_PWM_FREQ =          0,
        // otp_PWM_REG =           0,
        // otp_PWM_OFS =           0,
        // OTP_CHOPCONF8 =         0,
        // OTP_TPWMTHRS =          0,
        // otp_pwm_autograd =      0,




        // internal registers

        // General

        volatile uint32_t
        // 0x00 10bits
        GCONF = 0x00,

        //0x01 3bits
        GSTAT = 0x00,

        // 0x02 8bits
        IFCNT = 0x00,

        // 0x03 4bits
        SLAVECONT = 0x00,

        // 0x04 16bits
        OTP_PROG = 0x00,

        // 0x05 24bits
        OTP_READ = 0x00,

        // 0x06 10+8bits
        IOIN = 0x00,

        // 0x07 5+2bits
        FACTORY_CONF = 0x00,


        // Velocity Dependent Control

        // 0x10 5+5+4bits
        IHOLD_IRUN = 0x00,

        // 0x11 8bits
        TPOWER_DOWN = 0x00,

        // 0x12 20bits
        TSTEP = 0x00,

        // 0x13 20bits
        TPWMTHRS = 0x00,

        // 0x22 24bits
        VACTUAL = 0x00,


        // StallGuard Control

        // 0x14 20bits
        TCOOLTHRS = 0x00,

        // 0x40 8bits
        SGTHRS = 0x00,

        // 0x41 10bits
        SG_RESULT = 0x00,

        // 0x42 16bits
        COOLCONF = 0x00,


        // Sequencer Registers

        // 0x6A 10bits
        MSNCT = 0x00,

        // 0x6B 9+9bits
        MSCURACT = 0x00,


        // Chopper Control Registers

        // 0x6C 32bits
        CHOPCONF = 0x00,

        // 0x6F 32bits
        DRV_STATUS = 0x00,

        // 0x70 22bits
        PWMCONF = 0x00,

        // 0x71 9+8bits
        PWM_SCALE = 0x00,

        // 0x72 8+8bits
        PWM_AUTO = 0x00;




    public:

        explicit TMC2209(uint8_t slave_addr);

        /**
         * This command is for sending to the chip.
         * All bytes are LSB to MSB and the highest byte is transmitted first
         * @param rhs The datagram to be sent to the slave.
         *
         * @rhs0 sync + reserved (reserved bits are included in CRC)
         * example: 1010'0000
         *
         * @rhs1 8bit slave address (=0...3)
         *
         * @rhs2 Read (0) or Write (1) + 7bit register address.
         *
         * @rhs3...6 32 bits data. (Remember the LSB to MSB order!)
         *
         * @rhs7 Cyclic Redundancy Check
         * The sync nibble is assumed to be sent correctly,
         * but the rest of that byte is included in the crc.
         *
         * @Calculation
         * CRC = x⁸ + x² + x¹ + x⁰
         *
         * @return no return value.
         */
        void operator<<(std::array<uint8_t, 8> &rhs);


    };

}

#endif //ATP_CPLUSPLUS_TMC2209_HPP
