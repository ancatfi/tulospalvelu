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

#if defined(__BORLANDC__)
#pragma -K -a1
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tputil.h>
#define TRUE 1
#define FALSE 0

/*  Strtoaika muuttaa muodossa tt.mm.ss annetun ajan sekunneiksi */
/*  tt0 on lis�ys tunteihin */

long strtoaika(char *straika,int tt0)

{
  int tt, tm, ts, nf;

  if (strlen(straika) == 5)  strcat(straika, ".00");
  nf = sscanf(straika, "%2d.%2d.%2d", &tt, &tm, &ts);
  if (tt < tt0 - 12)  tt += 24;
  else if (tt > tt0 + 12) tt -= 24;
  if ((tt0 != 0 && abs(60 * (tt-tt0) + tm) > 545) ||
      (tt0 == 0 && 60 * tt + tm > 1090))
  {
    writeerror("Aika sallitun v�lin ulkopuolella", 2000);
    return(0);
  }
  if ((nf == 3) && (straika[2] == '.') && (straika[5] == '.') &&
       (straika[3] < '6') && (straika[6] < '6'))
    return(3600L * (tt-tt0) + 60L * tm + ts);
  return(-32767);
}

 long wstrtoaika(wchar_t *straika,int tt0)
{
	char str[20];

	wcstoansi(str, straika, 16);
	return(strtoaika(str, tt0));
}

