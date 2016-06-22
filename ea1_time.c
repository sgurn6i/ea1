/* ea1_time.c    -*- C -*-
   time.h 関係
   2016-06-22 15:07:32 Sgurn6i
*/
#include <limits.h> /* llong_max */
#include "ea1_benri.h"
#include "ea1_time.h"

double ea1_gettimeofday_ms()
{
  struct timeval tv;
  gettimeofday(&tv,NULL);
  return(tv.tv_sec * 1000.0 + tv.tv_usec * 0.001);
}

#define EA1_GIGA (1000 * 1000 * 1000)
int ea1_timespec_from_ms(struct timespec * ts_p, double ms)
{
  struct timespec ts;
  double sec = ms * 0.001;
  if (ts_p == NULL)
    return EA1_EINVAL;
  if (sec > (double)LLONG_MAX)
    return EA1_ERANGE;
  if (sec < (double)LLONG_MIN)
    return EA1_ERANGE;
  ts.tv_sec = (time_t)sec;
  ts.tv_nsec = (long)((sec - (double)(ts.tv_sec)) * (double)EA1_GIGA);
  if (ts.tv_nsec < 0)
    {
      ts.tv_nsec += EA1_GIGA;
      ts.tv_sec --;
      if (ts.tv_sec < 0)
        return EA1_OK;
    }
  else if (ts.tv_nsec >= EA1_GIGA)
    {
      ts.tv_nsec -= EA1_GIGA;
      ts.tv_sec ++; 
    }
  *ts_p = ts;
  return(EA1_OK);
}

int ea1_sleep_ms(double ms)
{
  struct timespec ts;
  int rc = ea1_timespec_from_ms(&ts, ms);
  if (rc != EA1_OK)
    return rc;
  if (ts.tv_sec < 0)
    return EA1_OK;
  return nanosleep(&ts, NULL);
}


