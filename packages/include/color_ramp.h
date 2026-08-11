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
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>

class ColorRamp
{
public:
    ColorRamp();
    ~ColorRamp();

    void initialisation();
    void set_min_max(double, double);
    int get_rgb_from_value(double);

private:
    QVector<QPair<qreal, QColor> > m_default_ramp;
    QVector<QPair<qreal, QColor> > m_ramp;
    double m_z_min;
    double m_z_max;
};
