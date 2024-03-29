/*
 * import.h
 *
 *  Created on: Feb 6, 2015
 *      Author: nbingham
 */

#include <common/standard.h>

#include <parse/tokenizer.h>

#include <ucs/variable.h>
#include <prs/production_rule.h>

#include <parse_prs/production_rule.h>
#include <parse_prs/production_rule_set.h>


#ifndef interpret_prs_import_h
#define interpret_prs_import_h

prs::production_rule import_production_rule(const parse_prs::production_rule &syntax, ucs::variable_set &variables, int default_id, tokenizer *tokens, bool auto_define);
prs::production_rule_set import_production_rule_set(const parse_prs::production_rule_set &syntax, ucs::variable_set &variables, int default_id, tokenizer *tokens, bool auto_define);

#endif
