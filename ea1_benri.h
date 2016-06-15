/* ea1_benri.h    -*- C -*-
   便利ツール
   2016-06-13 16:31:07 Sgurn6i
*/
#ifndef _EA1_BENRI_H_
#define _EA1_BENRI_H_
#include <stdlib.h>
#ifdef __cplusplus
extern "C" {
#endif
#define  EA1_SAFE_FREE(p) \
  do { if(p) { free(p); p = NULL; }} while(0)
#ifdef __cplusplus
}
#endif	/* C++ */
#define  EA1_SAFE_DELETE(p) \
  do { if(p) { delete(p); p = NULL; }} while(0)
#endif /* _EA1_BENRI_H_ */
