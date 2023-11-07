/*
Created by Jippe Heijnen on 06-11-23.

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

#include <atp_cplusplus>

#include <iostream>
#include <chrono>
#include <thread>

using namespace sensors;

void showReadCommand(TMC2209 &chip, std::string cmdName, std::array<uint8_t, 8> command) {

    uint16_t response = chip << command; // reading from chip

    std::cout << cmdName << "\n";

    // pretty printing the chip response.
    std::string output = "";
    for (int i = 15; i >= 0; i--) {
        uint16_t mask = 1 << i;
        uint16_t bit = (response & mask) >> i;
        output += std::to_string(bit);
    }

    std::cout << output << "\n\n";

}

int main() {

    TMC2209 s1 = TMC2209(0);
    TMC2209 s2 = TMC2209(1);
    TMC2209 s3 = TMC2209(3);
    TMC2209 s4 = TMC2209(3);
    std::array<TMC2209, 4> arr = {s1, s2, s3, s4};

    for (;;) {
//        showReadCommand(s1, "Chip ID:", 0x0);
//        showReadCommand(s1, "UVA data:", 0x7);

        // adding delay
        using namespace std::this_thread;
        using namespace std::chrono;
        sleep_for(nanoseconds(10));
        sleep_until(system_clock::now() + milliseconds(100));
        std::cout << "\n\n";
    }

}