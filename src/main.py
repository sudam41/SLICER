#!/usr/bin/env python

from task import Task
from component import Component
from app import Application
from cluster import Cluster
from scheduler import Scheduler
from simulator import Simulator
from parseconfig import Parsing
from plotter import Plotter

#hardcode simple DAG for testing 
#    t0
#    /\
#0.5/  \2.5
#  t1   t2
#   \   /
#0.75\ /1
#     t3

edges = ({},{0:0.5},{0:2.5},{1:0.75,2:1})
tasks = [0,1,2,3]

#
#edges = ({},{0:2},{0:4.5},{1:1.5,2:0},{})
#tasks = [0,1,2,3,4]


power = {0:{0:1.1, 1:11.0, 2:5.1}, 1:{0:2.2, 1:50.0, 2:2.2}, 2:{0:15.0, 1:4.3, 2:3.3}, 3:{0:11.2, 1:4.4, 2:10.4}}
WCET = {0:{0:5.0, 1:14.0, 2:7.0}, 1:{0:6.1, 1:40.0, 2:7.2}, 2:{0:3.0, 1:25.0, 2:4.5}, 3:{0:8.4, 1:30.0, 2:7.9}}


A = Application(tasks, edges, WCET, power, 100000)
print("alltasks: ", A.alltasks)


#parsing floorplan to opbtain the components
P = Parsing("matex.config","multicore.flp")
flp = P.parsefloorplan()

#create cluster and add components
clus = Cluster()
for i,unit in enumerate(flp):
	clus.add_component(Component(i, 1, (unit[3],unit[4]),unit[1],unit[2]))


print("cluster: ")
for comp in clus._clus:
	print(comp)
	
print("clus end")

##hardcode component for testing
#c0 = Component(0, 0, (0,0))
#c1 = Component(1, 1, (0,1))
#c2 = Component(2, 2, (1,0))

#clus = Cluster()
#clus.add_component(c0)
#clus.add_component(c1)
#clus.add_component(c2)



sim =  Simulator(A,clus,"MET")

sim.run()






#print("\n\n", clus)

#S = Scheduler(A,clus)


#go = S.MET()
#print("final res:",go)
#for c in clus.components:
#	print("component:",c.ID)
#	print (c.assigned_tasks)
#	
#	
#print("-----------")
#go = S.ETF()
#print("-----------")
#print("final res:",go)
#for c in clus.components:
#	print("component:",c.ID)
#	print (c.assigned_tasks)



