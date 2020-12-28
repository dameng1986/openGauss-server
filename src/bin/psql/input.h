/*
 * psql - the PostgreSQL interactive terminal
 *
 * Copyright (c) 2000-2012, PostgreSQL Global Development Group
 *
 * src/bin/psql/input.h
 */
#ifndef INPUT_H
#define INPUT_H

/*
 * If some other file needs to have access to readline/history, include this
 * file and save yourself all this work.
 *
 * USE_READLINE is the definite pointers regarding existence or not.
 */
#define USE_READLINE 1

#include <editline/readline.h>

#include "libpq/pqexpbuffer.h"

char* gets_interactive(const char* prompt);
char* gets_fromFile(FILE* source);

bool saveHistory(const char* fname, int max_lines, bool appendFlag, bool encodeFlag);

void pg_append_history(const char* s, PQExpBuffer history_buf);
void pg_send_history(PQExpBuffer history_buf);
void setHistSize(const char* targetName, const char* targetValue, bool setToDefault);
extern bool useReadline;
extern bool SensitiveStrCheck(const char* target);

#endif /* INPUT_H */
