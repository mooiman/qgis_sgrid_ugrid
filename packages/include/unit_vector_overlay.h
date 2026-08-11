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
#include <vector>
#include <QString>
#include <QPolygon>

class QPainter;
class QgsMapCanvas;

class UnitVectorOverlay : public QgsMapCanvasItem
{
public:
    explicit UnitVectorOverlay(QgsMapCanvas* canvas);
    ~UnitVectorOverlay();
    static UnitVectorOverlay* getInstance(QgsMapCanvas* canvas);
    static void deleteInstance();
    int get_count();

    void setShow(bool show);
    void setTitle(const QString& title);
    void setPolyline(std::vector<int> pix_x, std::vector<int> pix_y);
    void paint(QPainter* painter) override;

private:
    static UnitVectorOverlay* obj;
    static int count;

    // Optional but recommended
    UnitVectorOverlay(const UnitVectorOverlay&) = delete;
    UnitVectorOverlay& operator=(const UnitVectorOverlay&) = delete;

    bool mShowUnitVectorOverlay = false;
    const int m_boxWidth = 120;
    const int m_boxHeight = 45;
    const int m_margin = 15;

    QString mTitle = "--- x unit vector";
    QPolygon mPolyline;

    // Store canvas pointer for C++ usage
    QgsMapCanvas* mCanvas = nullptr;
};
