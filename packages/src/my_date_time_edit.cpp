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
#include "../include/my_date_time_edit.h"

MyQDateTimeEdit::MyQDateTimeEdit(QVector<QDateTime> q_times, int nsteps)
{
    _qdt = q_times;
    _nsteps = nsteps;
    _ansatz = false;
    _ansatz_d = 0;
    _ansatz_u = 0;
}
void MyQDateTimeEdit::stepBy(int step)
{
    if (_ansatz)
    {
        if (_ansatz_d == _ansatz_u)
        {
            _nsteps = _ansatz_u;
            if (step == 1) _nsteps = _ansatz_d;
            _ansatz = false;
        }
        else
        {
            _nsteps = _ansatz_d;
            if (step == -1) _nsteps = _ansatz_u;
            _ansatz = false;
        }
    }
    switch (step) {
    case 1:
        if (maximumDateTime() > _qdt[_nsteps])
        {
            _nsteps = std::min(int(_qdt.size()-1), _nsteps + step);
            setDateTime(_qdt[_nsteps]);
        }
        break;
    case -1:
        if (minimumDateTime() < _qdt[_nsteps])
        {
            _nsteps = std::max(0, _nsteps + step);
            setDateTime(_qdt[_nsteps]);
        }
        break;
    default:    
        break;
        //emit set_step(_nsteps);
    }
}
void MyQDateTimeEdit::setAnsatz(int step_d, int step_u)
{
    _ansatz_d = step_d;
    _ansatz_u = step_u;
    _ansatz = true;
}
