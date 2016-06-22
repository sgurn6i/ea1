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
/* malloc解放 */
#define  EA1_SAFE_FREE(p) \
  do { if(p) { free(p); p = NULL; }} while(0)
#ifdef __cplusplus
}
#endif	/* C++ */

/* 簡単なエラーコード */
#define EA1_OK              0
#define EA1_FAIL            -1  /* 一般エラー */
#define EA1_OUTOF_MEMORY    -2  /* メモリ不足 */
#define EA1_FILE_ERROR      -3  /* ファイル IO エラー */
#define EA1_EINVAL          -4  /* invalid argument */
#define EA1_ERANGE          -5  /* 数値範囲外の結果になる。 */
#define EA1_NOT_IMPLEMENTED -100  /* まだ実装してない */

#define  EA1_SAFE_DELETE(p) \
  do { if(p) { delete(p); p = NULL; }} while(0)
#endif /* _EA1_BENRI_H_ */
