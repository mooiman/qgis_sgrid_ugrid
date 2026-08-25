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

#include <string.h>
#include "sgrid_ugrid_version.h"

#if defined(WIN32) || defined (WIN64)
# define strdup _strdup
#endif

static char sgrid_ugrid_build_string[] = { sgrid_ugrid_build };
static char sgrid_ugrid_version[] = { sgrid_ugrid_major "." sgrid_ugrid_minor "." sgrid_ugrid_revision "." sgrid_ugrid_build " (" sgrid_ugrid_arch ")" };
static char sgrid_ugrid_version_id[] = {"@(#)Mooiman, " sgrid_ugrid_program " Version " sgrid_ugrid_major "." sgrid_ugrid_minor "." sgrid_ugrid_revision "." sgrid_ugrid_build " (" sgrid_ugrid_arch "), " __DATE__ ", " __TIME__ "" };

static char sgrid_ugrid_company_name[] = {"Mooiman"};
static char sgrid_ugrid_program_name[] = { sgrid_ugrid_program };

char * getfullversionstring_sgrid_ugrid(void)
{
    return strdup(sgrid_ugrid_version_id);
}
char * getversionstring_sgrid_ugrid(void)
{
    return strdup(sgrid_ugrid_version);
}
char * getcompanystring_sgrid_ugrid(void)
{
    return strdup(sgrid_ugrid_company_name);
}
char * getprogramstring_sgrid_ugrid(void)
{
    return strdup(sgrid_ugrid_program_name);
}
char * getbranchstring_sgrid_ugrid(void)
{
    return strdup(sgrid_ugrid_branch);
}
char * geturlstring_sgrid_ugrid(void)
{
    return strdup(sgrid_ugrid_source_url);
}
char * getbuildstring_sgrid_ugrid(void)
{
    return strdup(sgrid_ugrid_build_string);
}
