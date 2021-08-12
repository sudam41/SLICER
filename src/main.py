#!/usr/bin/env python

from task import Task
from component import Component
from app import Application
from cluster import Cluster
from scheduler import Scheduler

#hardcode simple DAG for testing 
#    t0
#    /\
#  2/  \4.5
#  t1   t2
#   \   /
#1.5 \ /1.5
#     t3

#t0 = Task(0, 0, 1.1)
#t1 = Task(1, 3.1, 5.9, {0:2})
#t2 = Task(2, 5.6, 7.5, {0:4.5})
#t3 = Task(3, 9, 10.2 , {1:1.5,2:1.5})

#print ("Task 3 : ", repr(t3))

#second implementation
edges = ({},{0:2},{0:4.5},{1:1.5,2:0})
tasks = [0,1,2,3]

##second implementation
#edges = ({},{0:2},{0:4.5},{1:1.5,2:0},{})
#tasks = [0,1,2,3,4]


A = Application(tasks,edges,15)
print("alltasks: ", A.alltasks)





##hardcode component for testing
#power1 = {0:1.1, 1:2.2, 2:3.3, 3:4.4, 4:1}
#power2 = {0:1.2, 1:2.2, 2:3.3, 3:4.4, 4:1}
#power3 = {0:1.3, 1:2.2, 2:3.3, 3:4.4, 4:1}

#WCET1 = {0:1.1, 1:2.8, 2:1.6, 3:1.3, 4:11}
#WCET2 = {0:1.2, 1:2.2, 2:1.0, 3:1.5, 4:11}
#WCET3 = {0:1.3, 1:3.0, 2:1.6, 3:1.2, 4:10}




#hardcode component for testing
power1 = {0:1.1, 1:2.2, 2:3.3, 3:4.4}
power2 = {0:1.2, 1:2.2, 2:3.3, 3:4.4}
power3 = {0:1.3, 1:2.2, 2:3.3, 3:4.4}

WCET1 = {0:1.1, 1:2.8, 2:1.6, 3:1.3}
WCET2 = {0:1.2, 1:2.2, 2:1.0, 3:1.5}
WCET3 = {0:1.3, 1:3.0, 2:1.6, 3:1.2}


c0 = Component(0, WCET1, power1, (0,0))
c1 = Component(1, WCET2, power2, (0,1))
c2 = Component(2, WCET3, power3, (1,0))

clus = Cluster()
clus.add_component(c0)
clus.add_component(c1)
clus.add_component(c2)

#print("\n\n", clus)

S = Scheduler(A,clus)
#go = S.MET()

#print("final res:",go)
#for c in clus.components:
#	print("component:",c.ID)
#	print (c.assigned_tasks)
#	
#	
print("-----------")
go = S.ETF()
print("-----------")
print("final res:",go)
for c in clus.components:
	print("component:",c.ID)
	print (c.assigned_tasks)



