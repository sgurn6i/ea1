/* ea1_debug.h    -*- C -*-
  デバッグユーティリティ
  2016-06-07 15:29:15 Sgurn6i
 */
/* usage:
 * // logs
 * #define LOG_TAG "Choge"
 * LOGI("hoge info %d", i);
 * LOGE("BUG found");
 * #define EA1_DEBUG
 * LOGD("checkpoint");
 *
 * // leak check
 * #define EA1_DEBUG_LEAK
 * int main() {
 * EA1_DEBUG_LEAK_START
 * ... malloc(..)
 * ... strdup(..)
 * ... free(..)
 * EA1_DEBUG_LEAK_END
 *  return 0;
 * }
 */

/* Todo:
 * Android 対応
 * */
#ifndef _EA1_DEBUG_H_
#define _EA1_DEBUG_H_
#include <stdio.h>
#include <string.h>
#ifdef EA1_DEBUG_LEAK
#include <gc.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* ディレクトリ名無しの __FILE__ */
#define EA1_FILE__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
  
#ifndef EA1_NO_LOGI 
#define LOGI(...) EA1_LOG_PRINTF(__VA_ARGS__)
#else // def EA1_NO_LOGI
#define LOGI(...) \
 do { } while(0)
#endif // def EA1_NO_LOGI
  
#ifndef EA1_NO_LOGE
#define LOGE(fmt, ...)            \
  EA1_LOG_PRINTF("Error %s %d: " fmt, EA1_FILE__, __LINE__, ##__VA_ARGS__)
#else  // def EA1_NO_LOGE
#define LOGE(fmt, ...)            \
  do { } while(0)
#endif  // def EA1_NO_LOGE
  
#ifdef EA1_DEBUG
#define LOGD(fmt, ...)            \
  EA1_LOG_PRINTF("%s %d: " fmt, EA1_FILE__, __LINE__, ##__VA_ARGS__)
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

#ifdef __cplusplus
/* LOGEしてから throw codeする。 */
#define THROW_E(code, ...) \
  do {                     \
    LOGE(__VA_ARGS__);     \
    throw code;            \
  } while(0)
#endif	/* C++ */

#ifdef __cplusplus
  extern "C" {
#endif
#ifdef EA1_DEBUG_LEAK
#define malloc(size) GC_debug_malloc(size, EA1_FILE__, __LINE__)
#define realloc(size) GC_debug_realloc(size, EA1_FILE__, __LINE__)
#define calloc(m,n) GC_debug_malloc((m) * (n), EA1_FILE__, __LINE__)
#define strdup(s) GC_debug_strdup(s, EA1_FILE__, __LINE__)
#define strndup(s,n) GC_debug_strdup(s, n, EA1_FILE__, __LINE__)
#define free GC_debug_free
#define EA1_DEBUG_LEAK_START \
      GC_set_find_leak(1);
#define EA1_DEBUG_LEAK_END \
      GC_gcollect(); \
      GC_set_find_leak(0);
#else  /* ndef EA1_DEBUG */
#define EA1_DEBUG_LEAK_START
#define EA1_DEBUG_LEAK_END
#endif /* ndef EA1_DEBUG */
#ifdef __cplusplus
}
#endif	/* C++ */

#endif /* _EA1_DEBUG_H_ */
