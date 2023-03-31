#!/usr/bin/env/python3
import networkx as nx
from networkx.drawing.nx_agraph import write_dot

benchmarkpath = ["802.11a/SDF-transmit_nocache_new","Audiobeam/SDF-Audiobeam_nocache","BeamFormer/SDF-BeamFormer_nocache","cfar/SDF-CFARtest_nocache_new","ComplexFIR/SDF-ComplexFIR_nocache","dct/SDF-iDCTcompare_nocache_new","des/SDF-DES_nocache_new","fft/SDF-FFT2_nocache_new","fft/SDF-FFT4_nocache_new","Filterbank/SDF-FilterBankNew_nocache_new","FMRadio/SDF-FMRadio_nocache_new"]
datarate = 1000000000
datatype = {'"void"': 0, '"complex"': 16, '"int"': 4, 'void': 0, 'float': 4, 'complex': 16, '"float"': 4}

benchmarks = {"802.11a" : "802.11a/SDF-transmit_nocache_new" , "Audiobeam" : "Audiobeam/SDF-Audiobeam_nocache" , "BeamFormer" : "BeamFormer/SDF-BeamFormer_nocache" , "CFAR" : "cfar/SDF-CFARtest_nocache_new" , "CFIR" : "ComplexFIR/SDF-ComplexFIR_nocache" , "DCT" : "dct/SDF-iDCTcompare_nocache_new" , "DES" : "des/SDF-DES_nocache_new" , "FFT2" : "fft/SDF-FFT2_nocache_new" , "FFT4" : "fft/SDF-FFT4_nocache_new" , "FilterBank" : "Filterbank/SDF-FilterBankNew_nocache_new" , "FMRadio" : "FMRadio/SDF-FMRadio_nocache_new"}


# for i in range(11):
#     print("\""+benchmarks[i] + "\" : \"" + benchmarkpath[i] + "\" , ",end="")


def parse_dot_file(bench):

# for bench in benchmarks[0:1]:

	dot_file = "../benchmarks/STR2RTS/src/" + benchmarks[bench] + ".dot"

	G = nx.DiGraph(nx.nx_agraph.read_dot(dot_file))

	taskID_map={}
	tasks = []
	task_names = {}
	for i,node_id in enumerate(G.nodes):
		# print(i,node_id)
		taskID_map [node_id] = i
		tasks.append(i)

		if G._node[node_id]['label'][0]=="\"":
			name = G._node[node_id]['label'][1:-1]
		else:
			name = G._node[node_id]['label']

		task_names[i] = name
	# print(taskIDs)

	edges_list = []
	for node_id in G.nodes:
		# print (node_id," | task ",taskID_map[node_id]," : ",G._node[node_id]['label']," ",G._node[node_id]['work'])
		popType = G._node[node_id]['popType']
		pop_str = G._node[node_id]['pop']
		if pop_str[0]=="\"":
			pop = float(pop_str[1:-1])
		else:
			pop = float(pop_str)

		delay = (datatype[popType] * pop * 8)/datarate
		# print(delay)
		pred={}
		for edge in G.edges:
			if edge[1]==node_id:
				pred[taskID_map[edge[0]]] = delay
		edges_list.append(pred)

	

	edges = tuple(edges_list)

	# print("tasks:",tasks,"\nedges:",edges,"\ntask names:",task_names)

	# print("PARSING DONE!")
	return tasks,edges,task_names




benchmarks_ = ["802.11a","Audiobeam","BeamFormer","CFAR","CFIR","DCT","DES","FFT2","FFT4","FilterBank","FMRadio"]

for bench in benchmarks_:
	T,E,tnames =parse_dot_file(bench)
	print(bench+" & "+str(len(tnames))+" \\\\")


# nx.nx_agraph.write_dot(G,"testagraph.dot")
# write_dot(G, "test.dot")

# newfile = "testagraph.dot"

# # nx.nx_pydot.read_dot(newfile)

# # print(nx.nx_pydot.read_dot(newfile))
# G2 = nx.DiGraph(nx.nx_agraph.read_dot(newfile))
# for node_id in G2.nodes:
# 	print (node_id," : ",G._node[node_id]['label']," ",G._node[node_id]['work']) # here, 'node_id' is the 'str' you said
	
