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
#ifndef __JSON_READER_H__
#define __JSON_READER_H__

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ptree_fwd.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/property_tree/json_parser.hpp>

using namespace boost;
using namespace property_tree;

class JSON_READER
{
public:
    JSON_READER(std::string);
    long get(std::string, std::vector<std::string> &);
    long get(std::string, std::vector<double> &);
    long get(std::string, std::vector<std::vector<std::vector<double>>> &);
    std::string get_filename();
    void prop_get_json(boost::property_tree::iptree &, const std::string, std::vector<std::string> &);
    void prop_get_json(boost::property_tree::iptree &, const std::string, std::vector<double> &);
    void prop_get_json(boost::property_tree::iptree &, const std::string, std::vector<std::vector<std::vector<double>>> &);

private:
    std::string m_filename;
    boost::property_tree::iptree m_ptrtree;
};
#endif  // __JSON_READER_H__
