/* ea1_test_main.c    -*- C -*-
   EA1 テスト用 main 関数。 
   2016-06-14 08:26:20 Sgurn6i
*/
#include "ea1_debug.h"
#include "ea1_benri.h"

#define LOG_TAG "EA1_TEST"

int main(int argc, char *argv[])
{
  int a = 123;
  int * ap = NULL;
  LOGE("an error");
  LOGD("debug point");
  LOGI("info a = %d", a);
  EA1_SAFE_FREE(ap);
  return 0;
}
