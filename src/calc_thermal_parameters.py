#!/usr/bin/env python
import numpy as np
import os
from pyparsing import Word, alphas ,nums, Literal, restOfLine, OneOrMore, ParserElement, White,Optional

class Thermal_Parameters():
	def __init__(self):
		pass
#		print(len(floorplan))

	def getThermalParameters(self,source = 'matex'):
		"Call Matex to calculate the conductance and capacitance matrices and store in cap.txt and cond.txt"
		
		if source == 'matex':
			os.system("../MatEx/MatEx -c matex.config -f multicore.flp -p multicore.ptrace #>/dev/null 2>&1")
			print("MatEx...")
			self.cap = self.loadCapacitance()
			self.cond =  self.loadConductance()
		
		
	def loadCapacitance(self):
		conffile = open("../MatEx/cap.txt", "r")
		val = Word('-'+nums+'.'+'e'+nums).setParseAction(lambda tokens: float(tokens[0])) 
		results = OneOrMore(val).parseFile(conffile)
		
		cap = np.zeros((len(results),len(results)))
		
		for i,r in enumerate(results):
			cap[i][i]=r
			
		return(cap)
		
		
	def loadConductance(self):
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

		return np.array(res)
			
		
