/* ea1_debug.h    -*- C -*-
  デバッグユーティリティ
  2016-06-07 15:29:15 Sgurn6i
 */
/* usage:
 * #define LOG_TAG "Choge"
 * LOGI("hoge info %d", i);
 * LOGE("BUG found");
 * Todo:
 * Android 対応
 * */
#ifndef _EA1_DEBUG_H_
#define _EA1_DEBUG_H_
#include <stdio.h>
#ifdef __cplusplus
extern "C" {
#endif
  
#ifndef EA1_NO_LOGI 
#define LOGI(...) EA1_LOG_PRINTF(__VA_ARGS__)
#else // def EA1_NO_LOGI
#define LOGI(...) \
 do { } while(0)
#endif // def EA1_NO_LOGI
  
#ifndef EA1_NO_LOGE
#define LOGE(fmt, ...)            \
  EA1_LOG_PRINTF("Error %s %d: " fmt, __FILE__, __LINE__, ##__VA_ARGS__)
#else  // def EA1_NO_LOGE
#define LOGE(fmt, ...)            \
  do { } while(0)
#endif  // def EA1_NO_LOGE
  
#ifdef EA1_DEBUG
#define LOGD(fmt, ...)            \
  EA1_LOG_PRINTF("%s %d: " fmt, __FILE__, __LINE__, ##__VA_ARGS__)
#else // ndef EA1_DEBUG
#define LOGD(fmt, ...) \
  do { } while(0)
#endif  // ndef EA1_DEBUG

  /* 内部マクロ */
#define EA1_LOG_PRINTF(fmt, ...)                 \
  fprintf (stderr, LOG_TAG " " fmt "\n", ##__VA_ARGS__)
#ifdef __cplusplus
}
#endif	/* C++ */
/* LOGEしてから throw codeする。 */
#define THROW_E(code, ...) \
  do {                     \
    LOGE(__VA_ARGS__);     \
    throw code;            \
  } while(0)
#endif /* _EA1_DEBUG_H_ */
