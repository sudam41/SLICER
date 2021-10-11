#!/usr/bin/env python

from pyparsing import Word, alphas ,nums, Literal, restOfLine, OneOrMore

class Parsing():

	def __init__(self, conffile,floorplanfile):
		self.conffile = conffile
		self.floorfile = floorplanfile
		
	def parseconfig(self):

		conffile = open(self.conffile, "r")

		linestart = Literal("-")
		line = linestart + Word(alphas+'_'+alphas) + Word(nums+'.'+'e'+'-'+nums).setParseAction(lambda tokens: float(tokens[0]))#nums+'.'
		line.ignore('#' + restOfLine) 



		results = OneOrMore(line).parseFile(conffile)

		res = {}
		name = ""
		for r in results:
			if r!="-":
				if type(r) == str:
					name = r
				else:
					res.update({name : r})
			
		
#		print(res)
		return res
		
	def parsefloorplan(self):
		floorfile = open(self.floorfile, "r")
		
		
		line = Word(alphas+'_'+nums+','+nums) + Word(nums+'.'+nums).setParseAction(lambda tokens: float(tokens[0])) + Word(nums+'.'+nums).setParseAction(lambda tokens: float(tokens[0]))+ Word(nums+'.'+nums).setParseAction(lambda tokens: float(tokens[0]))+ Word(nums+'.'+nums).setParseAction(lambda tokens: float(tokens[0]))
		line.ignore('#' + restOfLine) 
		
		results = OneOrMore(line).parseFile(floorfile)
		
		res = []
		name = ""
		width = 0
		height = 0
		leftx = 0
		bottomy = 0
		i = 0
		for r in results:
			if type(r) == str:
				name = r
#				print(name)
				i=0
			else:
				if i == 1:
					width = r
				elif i == 2:
					height = r
				elif i == 3:
					leftx = r
				elif i == 4:
					bottomy = r
#					print(bottomy)
					res.append([name,width,height,leftx,bottomy])
					
			i+=1			

		
		return(res)


