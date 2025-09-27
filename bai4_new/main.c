#include "logger.h"
#include <stdio.h>

int main(void) {
    /* Init logger:
     * - write to "app.log"
     * - min level = LOG_INFO (so DEBUG messages will be ignored)
     */
    if (logger_init("app.log", LOG_INFO) != 0) {
        fprintf(stderr, "Failed to open log file\n");
        /* We can still continue without file logging by calling logger_init(NULL, ...) */
    }

    log_message(LOG_INFO, "Application started");
    log_message(LOG_DEBUG, "This DEBUG message will be ignored at current level");
    log_message(LOG_WARNING, "Low disk space: %d%% remaining", 12);
    log_message(LOG_ERROR, "Failed to open resource: code=%d", -5);

    /* Change runtime level to DEBUG to allow debug messages */
    logger_set_level(LOG_DEBUG);
    log_message(LOG_DEBUG, "Now DEBUG messages are enabled (value=%d)", 123);

    /* Simulate a critical failure */
    log_message(LOG_CRITICAL, "Out of memory while allocating buffer");

    logger_close();
    return 0;
}