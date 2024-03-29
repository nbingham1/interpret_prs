/*
 * export.cpp
 *
 *  Created on: Feb 6, 2015
 *      Author: nbingham
 */

#include "export.h"
#include <interpret_boolean/export.h>

parse_prs::production_rule export_production_rule(const prs::production_rule &pr, ucs::variable_set &variables)
{
	parse_prs::production_rule result;
	result.valid = true;
	result.implicant = export_expression_xfactor(pr.guard, variables);
	result.action = export_composition(pr.local_action, variables);
	return result;
}

parse_prs::production_rule_set export_production_rule_set(const prs::production_rule_set &prs, ucs::variable_set &variables)
{
	parse_prs::production_rule_set result;
	result.valid = true;
	for (int i = 0; i < (int)prs.rules.size(); i++)
		result.rules.push_back(export_production_rule(prs.rules[i], variables));
	return result;
}
