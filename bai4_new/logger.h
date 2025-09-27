#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <stdarg.h>

/* Syslog-like priorities (0 = most severe) */
typedef enum {
    LOG_EMERGENCY = 0,
    LOG_ALERT     = 1,
    LOG_CRITICAL  = 2,
    LOG_ERROR     = 3,
    LOG_WARNING   = 4,
    LOG_NOTICE    = 5,
    LOG_INFO      = 6,
    LOG_DEBUG     = 7
} LogLevel;

/* Initialize logger
 * log_filename: path to file or NULL to disable file logging
 * min_level: minimum level allowed (messages with numeric value > min_level are dropped)
 * returns 0 on success, non-zero on error (file open failure)
 */
int logger_init(const char *log_filename, LogLevel min_level);

/* Change runtime minimum level */
void logger_set_level(LogLevel min_level);

/* Log function (use macro log_message to call this automatically with __FILE__ and __LINE__) */
void logger_log(LogLevel level, const char *file, int line, const char *fmt, ...);

/* Close logger and free resources */
void logger_close(void);

/* Convenience macro: hides __FILE__ and __LINE__ from caller */
#define log_message(level, fmt, ...) \
    logger_log(level, __FILE__, __LINE__, fmt, ##__VA_ARGS__)

#endif /* LOGGER_H */