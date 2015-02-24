/*
 * import.cpp
 *
 *  Created on: Feb 6, 2015
 *      Author: nbingham
 */

#include "import.h"
#include <interpret_boolean/import.h>

prs::production_rule import_production_rule(tokenizer &tokens, const parse_prs::production_rule &syntax, boolean::variable_set &variables, bool auto_define)
{
	prs::production_rule result;
	result.guard = import_cover(tokens, syntax.implicant, variables, auto_define);
	result.action = import_cover(tokens, syntax.action, variables, auto_define);
	return result;
}

prs::production_rule_set import_production_rule_set(tokenizer &tokens, const parse_prs::production_rule_set &syntax, boolean::variable_set &variables, bool auto_define)
{
	prs::production_rule_set result;

	for (int i = 0; i < (int)syntax.rules.size(); i++)
		result.rules.push_back(import_production_rule(tokens, syntax.rules[i], variables, auto_define));

	return result;
}
