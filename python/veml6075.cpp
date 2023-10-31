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

#include "../cpp/include/atp_cplusplus_parts/VEML6075.hpp"

#include <pybind11/stl.h>

#include <pybind11/pybind11.h>
namespace py = pybind11;

void init_VEML6075(py::module &m) {

    py::class_<sensors::VEML6075>(m, "VEML6075")
            .def(py::init<std::string>(), py::arg("name"))
            .def("get_name",
                 py::overload_cast<>( &sensors::VEML6075::get_name, py::const_))
            .def("test",
                 py::overload_cast<std::string>( &sensors::VEML6075::test),
                 py::arg("message"));
}