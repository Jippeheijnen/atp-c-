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

#include <atp_cplusplus>

#include <iostream>

using namespace sensors;

void showReadCommand(VEML6075 &chip, std::string cmdName, uint8_t command) {

    uint16_t response = chip >> command; // reading from chip

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

    using namespace sensors;
    VEML6075 s1, s2, s3, s4;
    std::array<VEML6075, 4> arr = {s1, s2, s3, s4};

    int i = 0;
    for (auto i = 0; i<arr.size(); i++) {
        showReadCommand(arr[i], "Reading the chip ID", 0xC);
        showReadCommand(arr[i], "Reading the chip config", 0x0);
        std::array<uint8_t, 3> writeCommand = {0x0, i, 0x0};
        arr[i] << writeCommand;
    }

//    showReadCommand(s1, "Reading the chip ID", 0xC);
//    showReadCommand(s1, "Reading the chip config", 0x0);
    // now changing the chip config
//    std::array<uint8_t, 3> new_conf = {0x0, 0x6, 0x6};
//    s << new_conf;
    for (auto chip : arr) {
        showReadCommand(chip, "Reading the new chip config", 0x0);
    }

    //previous check to see whether the chips responds 0 or something else.
    //if (response) {std::cout << "Even!\n";} else {std::cout << "Uneven!\n";}
}