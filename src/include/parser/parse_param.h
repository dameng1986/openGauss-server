/* -------------------------------------------------------------------------
 *
 * parse_param.h
 *	  handle parameters in parser
 *
 * Portions Copyright (c) 1996-2012, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/parser/parse_param.h
 *
 * -------------------------------------------------------------------------
 */
#ifndef PARSE_PARAM_H
#define PARSE_PARAM_H

#include "parser/parse_node.h"

extern void parse_fixed_parameters(ParseState* pstate, Oid* paramTypes, int numParams);
#ifdef ENABLE_MULTIPLE_NODES
extern void parse_variable_parameters(ParseState* pstate, Oid** paramTypes, int* numParams);
#else
extern void parse_variable_parameters(ParseState* pstate, Oid** paramTypes, int* numParams, char** paramTypeNames);
#endif
extern void check_variable_parameters(ParseState* pstate, Query* query);

#endif /* PARSE_PARAM_H */
