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
#ifndef _INC_MAP_PROPERTY
#define _INC_MAP_PROPERTY

#include <QDateTimeEdit>
#include <QGroupBox>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QCheckBox>

class MapProperty
{
public:
    MapProperty();  // Constructor
    ~MapProperty();  // Destructor
//    static MapProperty * getInstance();
    static MapProperty * getInstance()
    {
        if (obj == nullptr)
            obj = new MapProperty();
        return obj;
    }

    void set_dynamic_legend(bool);
    void set_minimum(double);
    void set_maximum(double);
    void set_opacity(double);
    void set_refresh_time(double);
    void set_vector_scaling(double);
    bool get_dynamic_legend();
    double get_minimum();
    double get_maximum();
    double get_opacity();
    double get_refresh_time();
    double get_vector_scaling();

private:
    static MapProperty * obj;

    double prop_opacity;
    double prop_refresh_time;
    bool prop_dynamic_min_max;
    double prop_max;
    double prop_min;
    double prop_vector_scaling;
    // TODO: QVector<QPair<qreal, QColor> > prop_initramp;
    // TODO: Drawing on node/edge/face; dot, line or fill 
};
#endif _INC_MAP_PROPERTY
