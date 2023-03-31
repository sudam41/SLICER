import networkx as nx
from networkx.drawing.nx_agraph import write_dot
import re
import sys

# filenames = ["BeamFormer/SDF-BeamFormer_nocache","fft/SDF-FFT2_nocache","fft/SDF-FFT4_nocache","Filterbank/SDF-FilterBankNew_nocache","FMRadio/SDF-FMRadio_nocache","802.11a/SDF-transmit_nocache","des/SDF-DES_nocache"]

# filenames = ["cfar/SDF-CFARtest_nocache","dct/SDF-iDCTcompare_nocache"]

filenames = ["BeamFormer/SDF-BeamFormer_nocache"]

for filename in filenames:
	print("\n"+filename)

	G = nx.DiGraph(nx.nx_pydot.read_dot(filename+".dot"))
	# for node_id in G.nodes:
	# 	print (node_id," : ",G._node[node_id]['label']," ",G._node[node_id]['work']) # here, 'node_id' is the 'str' you said

	oriNumTasks = len(G.nodes)

	for node_id in G.nodes:
	#	print (node_id," : ",G._node[node_id]['label']) # here, 'node_id' is the 'str' you said
	#	print("prev:",list(G.predecessors(node_id)))
		pred = list(G.predecessors(node_id))
		suc = list(G.successors(node_id))

		if len(list(G.predecessors(node_id))) == 1:
			pred = list(G.predecessors(node_id))[0]
	#		print("pred",pred, " work",list(G.successors(pred)))
			
			if len(list(G.successors(pred)))==1:
	#			suc = list(G.successors(pred[0]))[0]
	#			print(pred,node_id)
				tot_work = int(G._node[pred]['work'][1:-1]) +  int(G._node[node_id]['work'][1:-1])
				# print("total work:",tot_work)
				if tot_work<4000:
					G._node[pred]['work'] = "\""+str(tot_work)+"\""
					G.remove_edge(pred, node_id)
					G = nx.contracted_nodes(G, pred, node_id)
					# G._node[node_id]['label']
	#			print(G._node[pred[0]]['label'])


	# for node_id in G.nodes:
	# 	print (node_id," -> ",G._node[node_id]['label']," ",G._node[node_id]['work'])		

	print("original number of tasks:",oriNumTasks,"\nnumber of tasks:",len(G.nodes))		

	# sys.exit()
	#******************	
	write_dot(G, filename+"_new_.dot")
	#******************
	
	with open(filename+'.c', 'r') as file, open(filename+'_new.c', 'w+') as writefile:

		count =0
		writefile.write("#include \"sim_api.h\"\n")
		for line in file:
			writefile.write(line)
			# print(line)
			for node_id in G.nodes:
				
	#			print (node_id," -> ",G._node[node_id]['label'])
			
				if(re.search("^void " + G._node[node_id]['label'][1:-1],line)):
					
					writefile.write("SimNamedMarker(5, __func__);\n")
					count=count+1
			
		print("Markers added:",count)
		if count != len(G.nodes):
			print("ERROR!")
			sys.exit()








