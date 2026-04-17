// -------------- Details --------------
//
// Name    : Analib
// Version : 0.1.2
//
// Author  : Simon Danielsson
// Email   : contact@simondanielsson.se
// Website : https://www.simondanielsson.se/
//
// ------------ Description ------------
//
// This library was built to contain most of the common utilities I need for
// building programs in C. I have chosen not to constrain the library to any
// specific utility or theme - my goal is instead to have a single header file
// filled with everything I need, that I can copy into my projects as an easy
// default. Analib is a highly opinionated and personal library catered only to
// myself, and myself only.
//
// -------------- License --------------
//
// Copyright © 2026 Simon Danielsson
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files, to deal in the Software
// without restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, sublicense, and/or sell copies of the
// Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef ANALIB_H_
#define ANALIB_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef ANALIB_DEF
#define ANALIB_DEF
#endif // ANALIB_DEF

// DEFINITIONS: DEBUG
// =============================================================================

// generic msg call for debug functions
ANALIB_DEF static inline void AL_db_gen_msg(const char *type, const char *msg,
                                            const char *file, int line);

// generic label builder for debug functions
ANALIB_DEF static inline void AL_db_make_label(const char *label, char *header,
                                               int header_size);

// formatted assert message that does not abort the program
#define AL_db_assert(cond)                                                     \
  if (cond == false) {                                                         \
    AL_db_gen_msg("ASSERT", #cond, __FILE_NAME__, __LINE__);                   \
  }                                                                            \
  while (0)

// formatted log message
#define AL_db_log(msg) AL_db_gen_msg("LOG", (msg), __FILE_NAME__, __LINE__);

// rust-like formatted todo message that aborts the program
#define AL_db_todo(msg)                                                        \
  do {                                                                         \
    AL_db_gen_msg("TODO", (msg), __FILE_NAME__, __LINE__);                     \
    abort();                                                                   \
  } while (0)

// DEFINITIONS: INTEGERS, FLOATS & DOUBLES
// =============================================================================

static inline int AL_min_int(int a, int b);
static inline int AL_max_int(int a, int b);
static inline double AL_min_double(double a, double b);
static inline double AL_max_double(double a, double b);

// compare two integers or doubles and return the smaller one
#define AL_cmp_min(a, b)                                                       \
  _Generic((a) + (b), int: min_int, double: min_double)(a, b)

// compare two integers or doubles and return the bigger one
#define AL_cmp_max(a, b)                                                       \
  _Generic((a) + (b), int: max_int, double: max_double)(a, b)

// DEFINITIONS: STRINGS
// =============================================================================

// get length of str
ANALIB_DEF int AL_str_len(char *s);

#endif // ANALIB_H_
#ifdef ANALIB_IMPLEMENTATION

// IMPLEMENTATIONS: DEBUG
// =============================================================================

// generic label builder for debug functions
ANALIB_DEF static inline void AL_db_make_label(const char *label, char *header,
                                               int header_size) {
  int label_size = strlen(label);
  int wings_len = (header_size - label_size - 2) / 2;

  if (wings_len <= 0 || header_size <= 0) {
    if (header_size > 0)
      header[0] = '\0';
    return;
  }

  char wing[wings_len + 1];
  memset(wing, '-', wings_len);
  wing[wings_len] = '\0';

  snprintf(header, header_size, "%s %s %s", wing, label, wing);
}

// generic msg call for debug functions
ANALIB_DEF static inline void AL_db_gen_msg(const char *type, const char *msg,
                                            const char *file, int line) {

  char label[24];
  AL_db_make_label(type, label, 24);
  fprintf(stderr, "\n%s\nfile  : %s:%d\nmsg   : %s\n", label, file, line, msg);
}

// IMPLEMENTATIONS: INTEGERS
// =============================================================================

ANALIB_DEF static inline int min_int(int a, int b) { return a < b ? a : b; }
ANALIB_DEF static inline int max_int(int a, int b) { return a > b ? a : b; }
ANALIB_DEF static inline double min_double(double a, double b) {
  return a < b ? a : b;
}
ANALIB_DEF static inline double max_double(double a, double b) {
  return a > b ? a : b;
}

// IMPLEMENTATIONS: STRINGS
// =============================================================================

ANALIB_DEF int AL_str_len(char *s) {
  char *t;
  for (t = s; *t != '\0'; t++)
    ;
  return t - s;
}

#endif // ANALIB_IMPLEMENTATION
