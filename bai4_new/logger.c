#define _POSIX_C_SOURCE 200809L /* for strftime */
#include "logger.h"
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

static FILE *g_logfile = NULL;
static LogLevel g_min_level = LOG_DEBUG; /* default: allow all */
static const size_t MSG_BUF_SIZE = 1024;
static const size_t LINE_BUF_SIZE = 1400;

/* Map level to string */
static const char *level_to_string(LogLevel level) {
    switch (level) {
    case LOG_EMERGENCY: return "EMERGENCY";
    case LOG_ALERT:     return "ALERT";
    case LOG_CRITICAL:  return "CRITICAL";
    case LOG_ERROR:     return "ERROR";
    case LOG_WARNING:   return "WARNING";
    case LOG_NOTICE:    return "NOTICE";
    case LOG_INFO:      return "INFO";
    case LOG_DEBUG:     return "DEBUG";
    default:            return "UNKNOWN";
    }
}

/* internal timestamp helper */
static void current_timestamp(char *buf, size_t buflen) {
    time_t t = time(NULL);
    struct tm tmv;
#if defined(_WIN32) || defined(_WIN64)
    localtime_s(&tmv, &t);
#else
    localtime_r(&t, &tmv);
#endif
    strftime(buf, buflen, "%Y-%m-%d %H:%M:%S", &tmv);
}

/* Initialise logger */
int logger_init(const char *log_filename, LogLevel min_level) {
    g_min_level = min_level;
    if (log_filename) {
        g_logfile = fopen(log_filename, "a");
        if (!g_logfile) {
            return -1;
        }
        /* Set line buffering to ensure logs are flushed often */
        setvbuf(g_logfile, NULL, _IOLBF, 0);
    }
    return 0;
}

/* Set level at runtime */
void logger_set_level(LogLevel min_level) {
    g_min_level = min_level;
}

/* Core logging function */
void logger_log(LogLevel level, const char *file, int line, const char *fmt, ...) {
    if (level > g_min_level) {
        /* Lower priority (larger numeric value) than allowed -> ignore */
        return;
    }

    char msgbuf[MSG_BUF_SIZE];
    va_list ap;
    va_start(ap, fmt);
    /* Format the user message safely */
    vsnprintf(msgbuf, sizeof(msgbuf), fmt, ap);
    va_end(ap);

    char timebuf[64];
    current_timestamp(timebuf, sizeof(timebuf));

    char finalbuf[LINE_BUF_SIZE];
    /* Full format: [YYYY-MM-DD HH:MM:SS] [LEVEL] [FILENAME:LINE] - Message */
    snprintf(finalbuf, sizeof(finalbuf), "[%s] [%s] [%s:%d] - %s\n",
             timebuf, level_to_string(level), file ? file : "unknown", line, msgbuf);

    /* Choose stream: severe messages (<= LOG_ERROR) -> stderr, else stdout */
    FILE *out = (level <= LOG_ERROR) ? stderr : stdout;
    fputs(finalbuf, out);
    fflush(out);

    /* Also write to file if enabled */
    if (g_logfile) {
        fputs(finalbuf, g_logfile);
        fflush(g_logfile);
    }
}

/* Close logger */
void logger_close(void) {
    if (g_logfile) {
        fclose(g_logfile);
        g_logfile = NULL;
    }
}