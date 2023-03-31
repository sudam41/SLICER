import networkx as nx
from networkx.drawing.nx_agraph import write_dot
import re
import sys

ori_file = "SDF-transmit_nocache"
new_file = "SDF-transmit_nocache_new"

file =ori_file
# G = nx.DiGraph(nx.nx_agraph.read_dot(file+".dot"))
G = nx.DiGraph(nx.nx_pydot.read_dot(file+".dot"))


for node_id in G.nodes:
	lab = G._node[node_id]['label']
    #  print(lab)
	G._node[node_id]['label'] =""
	G._node[node_id]['style'] ="filled"
	G._node[node_id]['fillcolor'] ='grey'


write_dot(G, file+"_nolabel.dot")