//
// Programmer: Jan Mooiman
// Email     : jan.mooiman@outlook.com
//
//    QGIS plugin to plot and animate results from SGRID and/or UGRID compliant grids.
//    1D grid with its geometry, 1D2D, 2D and 3D grids.
//    Copyright (C) 2026 Jan Mooiman
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <https://www.gnu.org/licenses/>.
//
//---------------------------------------------------------------
#include "mapping.h"

MAPPING::MAPPING()
{
    m_name = std::string("---");
    m_epsg = -1;
    m_epsg_string = std::string("---");
}
MAPPING::~MAPPING()
{
}

//------------------------------------------------------------------------------
long MAPPING::set_epsg(int epsg, std::string epsg_code)
{
    long status = 0;
    m_epsg = (long)epsg;
    m_epsg_string = epsg_code;
    return status;
}
//------------------------------------------------------------------------------
long MAPPING::get_epsg()
{
    return m_epsg;
}
//------------------------------------------------------------------------------
std::string MAPPING::get_epsg_string()
{
    return m_epsg_string;
}
