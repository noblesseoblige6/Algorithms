#include <bits/stdc++.h>

using namespace std;

#define DEG2RAD(a)   ((a) / (180 / M_PI))
#define RAD2DEG(a)   ((a) * (180 / M_PI))
#define EARTH_RADIUS 6378137

/* The following functions take their parameter and return their result in degrees */

double y2lat_d(double y)   { return RAD2DEG( atan(exp( DEG2RAD(y) )) * 2 - M_PI/2 ); }
double x2lon_d(double x)   { return x; }

double lat2y_d(double lat) { return RAD2DEG( log(tan( DEG2RAD(lat) / 2 +  M_PI/4 )) ); }
double lon2x_d(double lon) { return lon; }

/* The following functions take their parameter in something close to meters, along the equator, and return their result in degrees */

double y2lat_m(double y)   { return RAD2DEG(2 * atan(exp( y/EARTH_RADIUS)) - M_PI/2); }
double x2lon_m(double x)   { return RAD2DEG(              x/EARTH_RADIUS           ); }

/* The following functions take their parameter in degrees, and return their result in something close to meters, along the equator */

double lat2y_m(double lat) { return log(tan( DEG2RAD(lat) / 2 + M_PI/4 )) * EARTH_RADIUS; }
double lon2x_m(double lon) { return          DEG2RAD(lon)                 * EARTH_RADIUS; }

int main()
{
  int w = 1024, h = 512;
  for(int i = 1; i < 360; ++i)
  {
    for(int j = 0; j < 360; ++j)
    {

      double x = w * (j/360.0);
      double mercN = log(tan((DEG2RAD((i-180)/2.0) + M_PI / 2.0f) / 2.0f));
      double y = h * (RAD2DEG(mercN)/360 + 1)/2;
      cout << x << " " << y << endl;

      double r = 10.0;
      cout << r * sin(DEG2RAD(i)) * cos(DEG2RAD(j)) << " " <<  r * sin(DEG2RAD(i)) * sin(DEG2RAD(j)) << " " << r * cos(DEG2RAD(i)) << endl;
    }
  }
  return 0;
}
