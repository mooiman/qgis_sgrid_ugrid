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
#ifndef __MAPPING_H__
#define __MAPPING_H__

#include <QtCore/QFileInfo>

#include <QtWidgets/QMessageBox>
#include <QtWidgets/QProgressBar>

#include <qgsmessagelog.h>

#include "netcdf.h"
#include "data_struct.h"
#include "perf_timer.h"


class MAPPING
{
public:
    MAPPING();
    ~MAPPING();
    long set_epsg(int, std::string);
    long get_epsg();
    std::string get_epsg_string();

private:
    std::string m_name;
    long m_epsg;
    std::string m_grid_mapping_name;
    double m_longitude_of_prime_meridian;
    double m_semi_major_axis;
    double m_semi_minor_axis;
    double m_inverse_flattening;
    std::string m_epsg_string;
    std::string m_value;
    std::string m_projection_name;
    std::string m_wkt;
};
#endif __MAPPING_H__
