// Pekka Pirila's sports timekeeping program (Finnish: tulospalveluohjelma)
// Copyright (C) 2015 Pekka Pirila 

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <tputil.h>

char *savescr(int r0, int c0, int r1, int c1)
   {
   char *buf;

   if ((buf = (char *) malloc((r1 - r0 + 1)*(c1 - c0 + 1))) != 0)
      virdrect(r0, c0, r1, c1, buf, 0);
   return(buf);
   }

void restorescr(int r0, int c0, int r1, int c1, char *buf)
   {
   if (!buf)
      return;
   viwrrect(r0, c0, r1, c1, buf, 7, 0, 0);
   free(buf);
   }
