#!/usr/bin/env python
import numpy as np
import subprocess

from pyparsing import Word, alphas ,nums, Literal, restOfLine, OneOrMore, ParserElement, White,Optional

#subprocess.run(['cd','test'])

import os
os.system("../MatEx/MatEx -c matex.config -f multicore.flp -p multicore.ptrace >/dev/null 2>&1")

conffile = open("../MatEx/cond.txt", "r")

ParserElement.setDefaultWhitespaceChars(' \t') 

val = Word('-'+nums+'.'+'e'+nums).setParseAction(lambda tokens: float(tokens[0])) 

line = OneOrMore(val) + White('\n')
val.ignore('#' + restOfLine) 



results = OneOrMore(line).parseFile(conffile)

res = []
row = []
for r in results:
	
	if r != '\n':		
		row.append(r)
	else:
		temp = np.array(row)
		res.append(temp)
		row.clear()

print(np.array(res))


#res = {}
#name = ""
#for r in results:
#	if r!="-":
#		if type(r) == str:
#			name = r
#		else:
#			res.update({name : r})
	

#print(results)

