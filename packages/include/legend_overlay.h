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
#pragma once

#include <qgsmapcanvasitem.h>
#include <qgscolorramp.h>
#include <memory>
#include <QString>

class QPainter;
class QgsMapCanvas;

class NumericLegendOverlay : public QgsMapCanvasItem
{
public:
    explicit NumericLegendOverlay(QgsMapCanvas* canvas);
    ~NumericLegendOverlay();

    static NumericLegendOverlay* getInstance(QgsMapCanvas* canvas);
    static void deleteInstance();
    static int get_count();

    void setRamp(QgsColorRamp* ramp);
    void setTitle(const QString& title);
    void setRange(double min, double max);
    void setShow(bool show);
    QColor colorForValue(double value) const;
    void paint(QPainter* painter) override;

private:
    static NumericLegendOverlay* obj;
    static int count;

    // Optional but recommended
    NumericLegendOverlay(const NumericLegendOverlay&) = delete;
    NumericLegendOverlay& operator=(const NumericLegendOverlay&) = delete;

    QString mTitle = "Legend";
    double mMin = 0.0;
    double mMax = 1.0;
    bool mShowLegend;

    // Overlay owns the ramp safely
    QgsColorRamp*  mRamp;

    // Store canvas pointer for C++ usage
    QgsMapCanvas* mCanvas = nullptr;
};
