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
#ifndef __sgrid_ugrid_VERSION__     
#define __sgrid_ugrid_VERSION__     

#define sgrid_ugrid_major "0"
#define sgrid_ugrid_minor "30"
#define sgrid_ugrid_revision "00"
#define sgrid_ugrid_build "2026-05-13 13:41:26, M-42a46e4"

#define sgrid_ugrid_company "Mooiman"
#define sgrid_ugrid_company_url "---"
#define sgrid_ugrid_source_url "https://github.com/mooiman/qgis_sgrid_ugrid"
#define sgrid_ugrid_program "SGRID-UGRID"
#define sgrid_ugrid_version_number "0.30.00.2026-05-13 13:41:26, M-42a46e4"

#if defined(WIN32)
#define sgrid_ugrid_arch "Win32"
#elif defined(WIN64)
#define sgrid_ugrid_arch "Win64"
#elif defined(LINUX64)
#define sgrid_ugrid_arch "Linux64"
#elif
#define sgrid_ugrid_arch "Unknown"
#endif
/*=================================================== DO NOT MAKE CHANGES BELOW THIS LINE ===================================================================== */

extern "C" {
    extern char * getcompanystring_sgrid_ugrid(void);
    extern char * getfullversionstring_sgrid_ugrid(void);
    extern char * getprogramstring_sgrid_ugrid(void);
    extern char * getversionstring_sgrid_ugrid(void);
    extern char * getsourceurlstring_sgrid_ugrid(void);
}

#endif 
