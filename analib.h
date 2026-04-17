/*

-------------- Details --------------
Name        : Analib
Version     : 0.1.5

Author      : Simon Danielsson
Email       : contact@simondanielsson.se
Repository  : https://github.com/simon-danielsson/analib.h
Website     : https://www.simondanielsson.se/

------------ MIT License ------------
Copyright © 2026 Simon Danielsson

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files, to deal in the Software
without restriction, including without limitation the rights to use, copy,
modify, merge, publish, distribute, sublicense, and/or sell copies of the
Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#ifndef ANALIB_H_
#define ANALIB_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef ANALIB_DEF
#define ANALIB_DEF
#endif // ANALIB_DEF

// INTERNAL DEFINITIONS
// =============================================================================

// generic label builder for debug functions
static inline void al_db_lbl(const char *label, char *header, int header_size) {
  int label_size = strlen(label);
  int wings_len = (header_size - label_size);

  if (wings_len <= 0 || header_size <= 0) {
    if (header_size > 0)
      header[0] = '\0';
    return;
  }

  char wing[wings_len + 1];
  memset(wing, ' ', wings_len);
  wing[wings_len] = '\0';

  snprintf(header, header_size, " %s %s", label, wing);
}

// generic msg call for debug functions
static inline void _al_db_msg(const char *type, const char *msg,
                              const char *file, int line,
                              const char *function) {

  char label[9];
  al_db_lbl(type, label, 9);

  char space[11 + 1];
  memset(space, ' ', 11);
  space[11] = '\0';

  fprintf(stderr, "%-8s%s:%d (%s)%-2s%-32s\n", type, file, line, function, " ",
          msg);
}

static inline int _al_min_int(int a, int b) { return a < b ? a : b; }
static inline int _al_max_int(int a, int b) { return a > b ? a : b; }
static inline double _al_min_double(double a, double b) {
  return a < b ? a : b;
}
static inline double _al_max_double(double a, double b) {
  return a > b ? a : b;
}

// PUBLIC API
// =============================================================================

// get length of str
ANALIB_DEF int AL_str_len(char *s);

#ifdef AL_DEBUG_OFF
#define AL_db_assert(cond, do_abort) ((void)0)
#define AL_db_log(msg) ((void)0)
#define AL_db_todo(msg) ((void)0)

#else
// formatted assert message
// prints to stderr regardless of condition
// does not abort on do_abort=true if condition was true
#define AL_db_assert(cond, do_abort)                                           \
  do {                                                                         \
    char msg[32];                                                              \
    if (!(cond)) {                                                             \
      snprintf(msg, sizeof(msg), "failure -> %s", #cond);                      \
    } else {                                                                   \
      snprintf(msg, sizeof(msg), "success -> %s", #cond);                      \
    }                                                                          \
    _al_db_msg("ASSERT", msg, __FILE_NAME__, __LINE__, __func__);              \
    if (!(cond) && (do_abort)) {                                               \
      abort();                                                                 \
    }                                                                          \
  } while (0)

// formatted log message
#define AL_db_log(msg)                                                         \
  _al_db_msg("LOG", msg, __FILE_NAME__, __LINE__, __func__);

// rust-like formatted todo message that aborts the program if reached
#define AL_db_todo(msg)                                                        \
  do {                                                                         \
    _al_db_msg("TODO", (msg), __FILE_NAME__, __LINE__, __func__);              \
    abort();                                                                   \
  } while (0)

#endif // AL_DEBUG_OFF

// compare two integers or doubles and return the smaller one
#define AL_cmp_min(a, b)                                                       \
  _Generic((a) + (b), int: _al_min_int, double: _al_min_double)(a, b)

// compare two integers or doubles and return the bigger one
#define AL_cmp_max(a, b)                                                       \
  _Generic((a) + (b), int: _al_max_int, double: _al_max_double)(a, b)

#endif // ANALIB_H_

// IMPLEMENTATIONS
// =============================================================================

#ifdef ANALIB_IMPLEMENTATION

ANALIB_DEF int AL_str_len(char *s) {
  char *t;
  for (t = s; *t != '\0'; t++)
    ;
  return t - s;
}

#endif // ANALIB_IMPLEMENTATION
