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
#ifndef _INC_EditObsPoints
#define _INC_EditObsPoints

#include <QObject>
#include <QAction>
#include <QButtonGroup>
#include <QComboBox>
#include <QDateTime>
#include <QDateTimeEdit>
#include <QDockWidget>
#include <QFont>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QIcon>
#include <QLabel>
#include <QListWidget>
#include <QMessageBox>
#include <QPushButton>
#include <QSizePolicy>
#include <QSlider>
#include <QToolBar>
#include <QVBoxLayout>

#include <qmath.h>
#include <QgsLayerTreeView.h>
#include <qgsmapmouseevent.h>

#include <qgisplugin.h>

#include <direct.h> // for getcwd
#include <stdlib.h> // for MAX_PATH

#include "MyDrawingCanvas.h"

class EditObsPoints
    : public QDockWidget

{
    Q_OBJECT

    public:
        static int object_count;

    public slots:
        void cb_clicked(int);
    public slots:
        void MyMouseReleaseEvent(QgsMapMouseEvent *);

    public:
        EditObsPoints(QgsMapLayer *, QgsMapLayer *, GRID *, QgisInterface *);
        ~EditObsPoints();
        static int get_count();

    public:
        QDockWidget * edit_obs_panel;

    private:
        QgisInterface * m_QGisIface;
        QgsMapCanvas * m_QgsMapcanvas;
        QgsMapLayer * m_obs_layer;
        QgsMapLayer * m_geom_layer;
        GRID * m_grid_files;
        MyCanvas * m_MyCanvas;
        struct _ntw_geom * m_ntw_geom;

        void create_window();
        void closeEvent(QCloseEvent *);
};

#endif
