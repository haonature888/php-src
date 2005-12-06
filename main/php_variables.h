/*
   +----------------------------------------------------------------------+
   | PHP Version 5                                                        |
   +----------------------------------------------------------------------+
   | Copyright (c) 1997-2005 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.0 of the PHP license,       |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_0.txt.                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Authors: Rasmus Lerdorf <rasmus@lerdorf.on.ca>                       |
   |          Zeev Suraski <zeev@zend.com>                                |
   +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHP_VARIABLES_H
#define PHP_VARIABLES_H

#include "php.h"
#include "SAPI.h"

#define PARSE_POST 0
#define PARSE_GET 1
#define PARSE_COOKIE 2
#define PARSE_STRING 3

BEGIN_EXTERN_C()
void php_treat_data(int arg, char *str, zval* destArray TSRMLS_DC);
void php_startup_auto_globals(TSRMLS_D);
extern PHPAPI void (*php_import_environment_variables)(zval *array_ptr TSRMLS_DC);
PHPAPI void php_register_variable(char *var, char *val, zval *track_vars_array TSRMLS_DC);
/* binary-safe version */
PHPAPI void php_register_variable_safe(char *var, char *val, int val_len, zval *track_vars_array TSRMLS_DC);
PHPAPI void php_register_variable_ex(char *var, zval *val, zval *track_vars_array TSRMLS_DC);
PHPAPI void php_u_register_variable_safe(UChar *var, UChar *strval, int32_t str_len, zval *track_vars_array TSRMLS_DC);
PHPAPI void php_u_register_variable_ex(UChar *var, zval *val, zval *track_vars_array TSRMLS_DC);

int php_hash_environment(TSRMLS_D);
END_EXTERN_C()

#define NUM_TRACK_VARS	6

#endif /* PHP_VARIABLES_H */
