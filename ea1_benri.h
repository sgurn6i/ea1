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
typedef enum ea1_status_enum
{
  EA1_OK =             0,
  EA1_FAIL =           -1,  /* 一般エラー */
  EA1_OUTOF_MEMORY =   -2,  /* メモリ不足 */
  EA1_FILE_ERROR =     -3,  /* ファイル IO エラー */
  EA1_EINVAL =         -4,  /* invalid argument */
  EA1_ERANGE =         -5,  /* 数値範囲外の結果になる。 */
  EA1_E_NOT_READY =    -6,  /* 準備出来てない。 */
  EA1_NOT_IMPLEMENTED = -100  /* まだ実装してない */
} ea1_status_t;
/* 方言 */
#define EA1_E_FAIL  EA1_FAIL
#define EA1_E_FILE  EA1_FILE_ERROR

#define  EA1_SAFE_DELETE(p) \
  do { if(p) { delete(p); p = NULL; }} while(0)
#endif /* _EA1_BENRI_H_ */
