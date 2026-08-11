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
#include "map_property.h"

MapProperty::MapProperty()
{
    prop_opacity = 0.75; 
    prop_dynamic_min_max = true;
    prop_refresh_time = 0.1;
    prop_min = INFINITY;
    prop_max = -INFINITY;
    prop_vector_scaling = 1.0;  // 1.0 times the average cell length (= sqrt{cell_area})
}
MapProperty::~MapProperty()
{
}
//MapProperty* MapProperty::getInstance()
//{
//    if (obj == nullptr)
///        obj = new MapProperty();
//    return obj;
//}
void MapProperty::set_dynamic_legend(bool dynamic)
{
    prop_dynamic_min_max = dynamic;
}
void MapProperty::set_minimum(double z_min)
{
    prop_min = z_min;
}
void MapProperty::set_maximum(double z_max)
{
    prop_max = z_max;
}
void MapProperty::set_opacity(double opacity)
{
    prop_opacity = opacity;
}
void MapProperty::set_refresh_time(double refresh_time)
{
    prop_refresh_time = refresh_time;
}
void MapProperty::set_vector_scaling(double v_fac)
{
    prop_vector_scaling = v_fac;
}
bool MapProperty::get_dynamic_legend()
{
    return prop_dynamic_min_max;
}
double MapProperty::get_minimum()
{
    return prop_min;
}
double MapProperty::get_maximum()
{
    return prop_max;
}
double MapProperty::get_opacity()
{
    return prop_opacity;
}
double MapProperty::get_refresh_time()
{
    return prop_refresh_time;
}
double MapProperty::get_vector_scaling()
{
    return prop_vector_scaling;
}
