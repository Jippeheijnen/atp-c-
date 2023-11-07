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

#include "../cpp/include/atp_cplusplus_parts/TMC2209.hpp"
#include <pybind11/pybind11.h>


namespace py = pybind11;

void init_TMC2209(py::module &m) {

    py::class_<sensors::TMC2209>(m, "TMC2209")
            // Constructor
            .def(py::init<uint8_t>(), py::arg("slave_addr"))

            // class docstring
            .def("__doc__", [](){return "This is the TMC2209 Stepper Driver.\n";})

            // communication function
            .def("__lshift__", py::overload_cast<std::array<uint8_t, 8>&>(&sensors::TMC2209::operator<<))

            // docstring for communication function
            .def("__lshift__.__doc__", [](){return
            "The communication with a TMC2209\n"
            "For more info, see the documentation in the c++ classes.\n";});
}