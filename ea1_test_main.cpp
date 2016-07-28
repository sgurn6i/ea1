/* ea1_test_main.cpp    -*- C++ -*-
   EA1 テスト用 main 関数。 
   2016-06-14 08:26:20 Sgurn6i
*/
#include <vector>
#include "ea1_debug.h"
#include "ea1_benri.h"
#include "ea1_time.h"

#define LOG_TAG "EA1_TEST"

int main(int argc, char *argv[])
{
  ea1_status_t status = EA1_OK;
  int a = 123;
  int * ap = NULL;
  int * bp = (int *)malloc(100);
  std::vector<int> * vp = new std::vector<int>(10);
  LOGE("LOGE a fake error");
  LOGD("LOGD debug point");
  LOGI("LOGI info a = %d", a);
  LOGI("vsize= %d", (int)vp->size());
  EA1_SAFE_FREE(ap);
  EA1_SAFE_FREE(bp);
  EA1_SAFE_FREE(bp);
  EA1_SAFE_DELETE(vp);
  EA1_SAFE_DELETE(vp);
  double t1 = ea1_gettimeofday_ms();
  double t_sleep = 1000.0 - 1.0e-6;
  LOGI("t1 = %f ms", t1);
  LOGI("sleeping %f ms", t_sleep);
  int rc = ea1_sleep_ms(t_sleep);
  if (rc != 0)
    status = EA1_E_FAIL;
  double t2 = ea1_gettimeofday_ms();
  LOGI("slept %f ms, rc %d", t2 - t1, rc);
  return status;
}
