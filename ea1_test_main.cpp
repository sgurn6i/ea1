/* ea1_test_main.cpp    -*- C++ -*-
   EA1 テスト用 main 関数。 
   2016-06-14 08:26:20 Sgurn6i
*/
#include <vector>
#include "ea1_debug.h"
#include "ea1_benri.h"

#define LOG_TAG "EA1_TEST"

int main(int argc, char *argv[])
{
  int a = 123;
  int * ap = NULL;
  int * bp = (int *)malloc(100);
  std::vector<int> * vp = new std::vector<int>(10);
  LOGE("a fake error");
  LOGD("debug point");
  LOGI("info a = %d", a);
  LOGI("vsize= %d", (int)vp->size());
  EA1_SAFE_FREE(ap);
  EA1_SAFE_FREE(bp);
  EA1_SAFE_FREE(bp);
  EA1_SAFE_DELETE(vp);
  EA1_SAFE_DELETE(vp);
  return 0;
}
