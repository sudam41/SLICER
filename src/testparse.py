#!/usr/bin/env python

from parseconfig import Parsing
from calc_thermal_parameters import Thermal_Parameters
from task import Task
from component import Component
from app import Application
from cluster import Cluster
from scheduler import Scheduler
from simulator import Simulator
from thermal import Thermal


P = Parsing("matex.config","multicore.flp")

conf = P.parseconfig()

flp = P.parsefloorplan()

#print(flp)
#clus = Cluster()
#for i,unit in enumerate(flp):
#	clus.add_component(Component(i, 0, (unit[3],unit[4]),unit[1],unit[2]))

#print("no of comp:",clus.number_of_comps())

#for comp in clus._clus:
#	print(comp)


Th = Thermal(16)







#T = Thermal_Parameters()

#T.getThermalParameters('matex')

#print("cap:",T.cap,"\ncond:",T.cond)



