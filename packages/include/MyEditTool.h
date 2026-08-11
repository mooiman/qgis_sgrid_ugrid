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
//
// Copied from MyCanvas.cpp, project mfe_qgis dd 2019-05-19
//

#ifndef _INC_MYEDITTOOL
#define _INC_MYEDITTOOL

#include <assert.h>



#include <QVector>
#include <QObject>
#include <QPointer>

#include <QColor>
#include <QCursor>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QWheelEvent>

#include <QLabel>
#include <QMessageBox>
#include <QVBoxLayout>

#include "qgisinterface.h"
#include "qgsmaptool.h"
#include "qgsmaptoolemitpoint.h"
#include "qgsmapcanvas.h"
#include "qgsmapcanvasitem.h"
#include "qgsmapmouseevent.h"
#include "qgspointxy.h"
#include "qgsrubberband.h"

#define IMAGE_WIDTH  3840 // 1420 // 
#define IMAGE_HEIGHT 2140 // 1080 // 

class MyEditTool : public QgsMapTool, public QgsMapCanvasItem
{
    Q_OBJECT

public:  // function containing the emit-statement
    void canvasDoubleClickEvent(QgsMapMouseEvent *);
    void canvasMoveEvent(QgsMapMouseEvent *);
    void canvasPressEvent(QgsMapMouseEvent *);
    void canvasReleaseEvent(QgsMapMouseEvent *);
    void wheelEvent(QWheelEvent *);

signals:  // functions send by the emit-statement
    void MouseDoubleClickEvent(QMouseEvent*);
    void MouseMoveEvent(QMouseEvent*);
    void MousePressEvent(QMouseEvent*);
    void MouseReleaseEvent(QgsMapMouseEvent *);
    void WheelEvent(QWheelEvent*);

private slots:
/********** Events a widget must handle or forward to plugin **********/
    void MyMouseDoubleClickEvent(QMouseEvent*);
    void MyMouseMoveEvent(QMouseEvent*);
    void MyMousePressEvent(QMouseEvent*);
    void MyMouseReleaseEvent(QMouseEvent*);
    void MyWheelEvent(QWheelEvent* e);

    void MyKeyPressEvent(QKeyEvent*);
    void MyKeyReleasedEvent(QKeyEvent*);

public:
    MyEditTool(QgsMapCanvas*);
    ~MyEditTool();

protected:
    void paint(QPainter * p);

private:
    // variables
    QgisInterface* mQGisIface;
    QPointer<QgsMapCanvas> mMapCanvas;
    QPointer<QgsMapCanvas> mMapCanvasItem;
    QPixmap * mMapCanvasMap;

    QPaintDevice * pd;
    QWidget * w;
    QVBoxLayout * vb;
};

#endif  /* _INC_MYEDITTOOL */
