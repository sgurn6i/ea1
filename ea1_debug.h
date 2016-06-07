/* ea1_debug.h    -*- C -*-
  デバッグユーティリティ
  2016-06-07 15:29:15 Sgurn6i
 */
/* usage:
 * LOGI("hoge info %d\n", i);
 * LOGE("BUG found\n");
 * 文末改行コードを入れて呼び出すこと。 */
#ifndef _EA1_DEBUG_H_
#define _EA1_DEBUG_H_
#include <stdio.h>
#ifdef __cplusplus
extern "C" {
#endif
  
#define LOGI(...) EA1_LOG_PRINTF(__VA_ARGS__)
#define LOGE(fmt, ...)            \
  EA1_LOG_PRINTF("Error %s %d: " fmt, __FILE__, __LINE__, ##__VA_ARGS__)
/* 内部マクロ */
#define EA1_LOG_PRINTF(fmt, ...)                 \
  fprintf (stderr, fmt, ##__VA_ARGS__)
  
#ifdef __cplusplus
}
#endif	/* C++ */
#endif /* _EA1_DEBUG_H_ */
