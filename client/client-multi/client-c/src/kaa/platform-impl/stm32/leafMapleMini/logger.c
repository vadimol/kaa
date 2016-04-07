/*
 *  Copyright 2014-2016 CyberVision, Inc.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#include <stdio.h>
#include <time.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

#include "../../../platform/ext_system_logger.h"
//#include <wirish/wirish.h>

//extern uint32_t timestamp;

//void ext_write_log(FILE * sink, const char * buffer, size_t message_size)
//{
//    if (!buffer || !sink) {
//        return;
//    }
//    //SerialUSB.print(buffer);
//}
//
//time_t ext_get_systime()
//{
//    return 0;
//}

int ext_format_sprintf(char * buffer, size_t buffer_size, const char * format,
        const char * log_level_name, const char * truncated_name, int lineno,
        kaa_error_t error_code)
{
    time_t t = ext_get_systime();
    struct tm* tp = gmtime(&t);

    return snprintf(buffer, buffer_size, format, 1900 + tp->tm_year,
            tp->tm_mon + 1, tp->tm_mday, tp->tm_hour, tp->tm_min, tp->tm_sec,
            log_level_name, truncated_name, lineno, error_code);
}

int ext_snpintf(char * buffer, size_t buffer_size, const char * format, ...)
{
    va_list args;
    va_start(args, format);
    int res_len = vsnprintf(buffer, buffer_size, format, args);
    va_end(args);
    return res_len;
}

int ext_logger_sprintf(char * buffer, size_t buffer_size, const char * format,
        va_list args)
{
    //Leaf Mape vsrpintf don't support %zu, need to change %zu to %lu
    char *n_format = strdup(format);
    int i=0;
    size_t f_size = strlen(n_format);
    while(i < f_size) {
        if (n_format[i] == '%') {
            //Got % check if next is 'z'
            i++;
            if (n_format[i] == 'z') {
                //Change it to 'l'
                n_format[i] = 'l';
            }
        }
        i++;
    }


    int n = vsnprintf(buffer, buffer_size, n_format, args);

    free(n_format);

    return n;
}
