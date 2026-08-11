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
#ifndef __INC_ADD_CURRENT_VIEW_WINDOW_H__
#define __INC_ADD_CURRENT_VIEW_WINDOW_H__

#include <QCheckBox>
#include <QDateTimeEdit>
#include <QDockWidget>
#include <QGroupBox>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QTableView>
#include <QSizePolicy>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QVBoxLayout>
#include <QHeaderView>

#include <qgis.h>
#include <qgis_core.h>
#include <qgisinterface.h>
#include <qgslayertree.h>
#include <qgslayertreegroup.h>
#include <qgslayertreenode.h>
#include <qgslayertreeview.h>
#include <qgsvectorlayer.h>
#include <qgsmarkersymbollayer.h>
#include <qgssinglesymbolrenderer.h>
#include <qgssymbol.h>

class AddCurrentViewWindow 
    : public QWidget
{
    Q_OBJECT

public:
    static int object_count;

    AddCurrentViewWindow();  // Constructor
    AddCurrentViewWindow(QgisInterface *, QString, QString, double *, std::vector<double>, std::vector<double>, long, double);  // Constructor
    ~AddCurrentViewWindow();  // Destructor
    static AddCurrentViewWindow * getInstance()
    {
        if (obj == nullptr)
            obj = new AddCurrentViewWindow();
        return obj;
    }
    static int get_count();

public slots:
    void close();
    void clicked_addclose();
    void clicked_close();
    void clicked(QModelIndex);

private:
    void create_vector_layer();
    void create_window();
    QgsLayerTreeGroup * get_subgroup(QgsLayerTreeGroup *, QString);
    void add_layer_to_group(QgsVectorLayer *, QgsLayerTreeGroup *);
    void setLabelFontSize(QgsVectorLayer *layer, double size);

    QgisInterface * m_QGisIface; // Pointer to the QGIS interface object
    static AddCurrentViewWindow * obj;
    QWidget * wid;
    QTableView * table;
    QStandardItemModel * table_model;
    QItemSelectionModel *selectionModel;
    QString m_label;
    QString m_quantity;
    double * m_z_value;
    std::vector<double> m_x;
    std::vector<double> m_y;
    long m_epsg;
    int m_cur_view;
    double m_missing_value;
};
#endif
