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
#ifndef HANDLE_VECTOR_LAYER_H
#define HANDLE_VECTOR_LAYER_H

#include <boost/property_tree/ptree.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/property_tree/json_parser.hpp>

#include <iostream>

#include <QAction>
#include <QComboBox>
#include <QScreen>
#include <QIcon>
#include <QLayout> 
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QProcessEnvironment>
#include <QProgressBar>
#include <QSizePolicy> 
#include <QSpacerItem> 
#include <QToolBar>
#include <QTreeWidget>
#include <QtMath>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>

#include <qgis.h>
#include <qgis_core.h>
#include <qgisinterface.h>
#include <qgslayertree.h>
#include <qgslayertreeview.h>
#include <qgsvectorlayer.h>
#include <qgsmultilinestring.h>
#include <qgslinesymbollayer.h>
#include <qgsmarkersymbol.h>
#include <qgsmarkersymbollayer.h>
#include <qgsbasicnumericformat.h>   // <- concrete numeric format
#include <qgssinglesymbolrenderer.h>
#include <qgssymbol.h>

#include "sgrid_ugrid_version.h"
#include "grid.h"
#include "his_cf.h"
#include "json_reader.h"
#include "perf_timer.h"

#include <direct.h> // for getcwd
#include <stdlib.h> // for MAX_PATH
#include <filesystem> // for MAX_PATH

#define MSG_LENGTH 101
#define PATH_LENGTH 1024

#define    WAIT_MODE 1
#define NO_WAIT_MODE 0

class QAction;
class GRID;

class HVL
    : public QObject

{
    Q_OBJECT

    public:
        HVL(QgisInterface* iface);
        ~HVL();

        void set_grid_file(std::vector<GRID *>);
        GRID* get_active_grid_file(QString layer_id);

        //  qgis_umesh functions
        void create_vector_layer_data_on_edges(QString, _variable * var, struct _feature *, struct _edge *, double *, long, QgsLayerTreeGroup *);
        void create_vector_layer_edge_type(QString, _variable * var, struct _feature *, struct _edge *, double *, long, QgsLayerTreeGroup *);
        void create_vector_layer_data_on_nodes(QString, _variable * var, struct _feature *, double *, long, QgsLayerTreeGroup *);
        void create_vector_layer_nodes(QString, QString, struct _feature *, long, QgsLayerTreeGroup *);
        void create_vector_layer_edges(QString, QString, struct _feature *, struct _edge *, long, QgsLayerTreeGroup *);
        void create_vector_layer_geometry(QString, QString, struct _ntw_geom *, long, QgsLayerTreeGroup *);
        void create_vector_layer_observation_point(QString, QString, _location_type *, long, QgsLayerTreeGroup *);
        void create_vector_layer_observation_polyline(QString, QString, _location_type *, long, QgsLayerTreeGroup *);

        // Reading input files (ie JSON format)
        void create_vector_layer_1D_external_forcing(GRID *, JSON_READER *, long, QgsLayerTreeGroup *);
        void create_vector_layer_1D_structure(GRID *, JSON_READER *, long, QgsLayerTreeGroup *);
        void create_vector_layer_chainage_observation_point(GRID *, JSON_READER *, long, QgsLayerTreeGroup *);
        void create_vector_layer_crs_observation_point(GRID *, JSON_READER *, long, QgsLayerTreeGroup *);
        void create_vector_layer_fixed_weir(GRID *, JSON_READER *, long, QgsLayerTreeGroup *);
        void create_vector_layer_thin_dams(GRID *, JSON_READER *, long, QgsLayerTreeGroup *);
        void create_vector_layer_observation_point(GRID *, JSON_READER *, long, QgsLayerTreeGroup *);
        void create_vector_layer_observation_cross_section(GRID *, JSON_READER*, long, QgsLayerTreeGroup*);
        void create_vector_layer_1D_observation_cross_section(GRID *, JSON_READER*, long, QgsLayerTreeGroup*);
        void create_vector_layer_2D_observation_cross_section(GRID *, JSON_READER*, long, QgsLayerTreeGroup*);
        void create_vector_layer_structure(GRID *, JSON_READER *, long, QgsLayerTreeGroup *);
        void create_vector_layer_drypoints(GRID *, JSON_READER*, long, QgsLayerTreeGroup*);
        void create_vector_layer_1D_cross_section(GRID *, JSON_READER *, long, QgsLayerTreeGroup *);
        void create_vector_layer_1D_retention(GRID *, JSON_READER*, long, QgsLayerTreeGroup*);
        void create_vector_layer_sample_point(GRID *, JSON_READER *, long, QgsLayerTreeGroup *);

        void create_vector_layer_1D2D_link(JSON_READER *, long);
        long compute_location_along_geometry(struct _ntw_geom *, struct _ntw_edges *, std::string, double, double *, double *, double *);
        long find_location_boundary(struct _ntw_nodes *, std::string, double *, double *);
        
        QgsLayerTreeGroup* get_subgroup(QgsLayerTreeGroup*, QString);
        void add_layer_to_group(QgsVectorLayer*, QgsLayerTreeGroup*);
        void setLabelFontSize(QgsVectorLayer *layer, double size);
        std::vector<std::string> tokenize(const std::string& s, char c);
        std::vector<std::string> tokenize(const std::string& s, std::size_t count);

    private slots:

    private:
        void CrsChanged();

        QgisInterface* m_QGisIface;
        std::vector<GRID*> m_grid_file;
};
#endif  // HANDLE_VECTOR_LAYER_H
