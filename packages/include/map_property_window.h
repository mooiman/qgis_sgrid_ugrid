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
#ifndef _INC_MAP_PROPERTY_WINDOW
#define _INC_MAP_PROPERTY_WINDOW

#include <QCheckBox>
#include <QCloseEvent>
#include <QDateTimeEdit>
#include <QDockWidget>
#include <QGroupBox>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSlider>

#include "map_property.h"
#include "MyDrawingCanvas.h"

struct _bck_property {
    double opacity;
    double refresh_time;
    bool dynamic_legend;
    double minimum;
    double maximum;
    double vector_scaling;
};

class MapPropertyWindow 
    : public QDockWidget
{
    Q_OBJECT

public:
    static int object_count;

    MapPropertyWindow(MyCanvas *);  // Constructor
    ~MapPropertyWindow();  // Destructor

    void create_window();
    static int get_count();

public slots:
    void close();
    void closeEvent(QCloseEvent *);
    void clicked_ok();
    void clicked_cancel();
    void clicked_apply();
    void setOpacityEditValue(int);
    void setOpacitySliderValue(QString);

signals:
    void draw_all();
    void close_map();

private:
    QWidget * wid;
    QLabel * lbl_opacity;
    QLineEdit * le_opacity;
    QSlider * sl_opacity;
    QLabel * lbl_refresh_time;
    QLineEdit * le_refresh_time;
    QLabel * lbl_min;
    QLabel * lbl_max;
    QLabel * lbl_vs;  // vector scaling
    QLineEdit * le_min;
    QLineEdit * le_max;
    QLineEdit * le_vs;  // vector scaling

    MapProperty * m_property;
    struct _bck_property * m_bck_property;
    QVector<QPair<qreal, QColor> > m_default_ramp;
    MyCanvas * m_myCanvas;
    QCheckBox * m_ckb;

    void state_changed(int);

};
#endif
