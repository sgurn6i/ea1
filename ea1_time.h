/* ea1_time.h    -*- C -*-
   time.h関係
   2016-06-22 15:05:04 Sgurn6i
*/
#ifndef _EA1_TIME_H_
#define _EA1_TIME_H_
#include <time.h>
#include <sys/time.h>
#ifdef __cplusplus
extern "C" {
#endif
  double ea1_gettimeofday_ms();
  int ea1_timespec_from_ms(struct timespec * ts_p, double ms);
  int ea1_sleep_ms(double ms);
#ifdef __cplusplus
}
#endif	/* C++ */
#endif /* _EA1_TIME_H_ */
