/* Thanks to jbrewer@jera.com */

#ifndef MINUNIT_H
#define MINUNIT_H

#define mu_assert(message, test)    do { if (!(test)) return message; } while (0)
#define mu_run_test(test)           do { char *message = test(); tests_run++; if (message) return message; } while (0)
#define print_err(message)          printf(ANSI_COLOR_RED "%s" ANSI_COLOR_RESET "\n", message)
#define print_ok(message)           printf(ANSI_COLOR_GREEN "%s" ANSI_COLOR_RESET "\n", message)

#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_RESET    "\x1b[0m"

extern int tests_run;

#endif