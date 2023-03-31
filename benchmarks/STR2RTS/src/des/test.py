import networkx as nx
from networkx.drawing.nx_agraph import write_dot
import re


filename = "SDF-DES_nocache"

G = nx.DiGraph(nx.nx_pydot.read_dot(filename+".dot"))
for node_id in G.nodes:
	print (node_id," : ",G._node[node_id]['label']," ",G._node[node_id]['work']) # here, 'node_id' is the 'str' you said

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
			print("total work:",tot_work)
			if tot_work<4000:
				G._node[pred]['work'] = "\""+str(tot_work)+"\""
				G.remove_edge(pred, node_id)
				G = nx.contracted_nodes(G, pred, node_id)

#			print(G._node[pred[0]]['label'])


for node_id in G.nodes:
	print (node_id," -> ",G._node[node_id]['label']," ",G._node[node_id]['work'])		

print("original number of tasks:",oriNumTasks,"\nnumber of tasks:",len(G.nodes))		
# # here, 'node_id' is the 'str' you said
#	
write_dot(G, filename+"_new.dot")


with open(filename+'.c', 'r') as file, open(filename+'_ori_withmarkers.c', 'w+') as writefile:
#	data = file.read()
#	for node_id in G.nodes:
#		print (node_id," : ",G._node[node_id]['label'])
#		search_text = "void " + G._node[node_id]['label'][1:-1] + "() {"
#		
#		replace_text = search_text + "\nSimNamedMarker(5, __func__);"
#		print("ST:",search_text," RT:",replace_text)
#		data = data.replace(search_text, replace_text)
	count =0
	for line in file:
		writefile.write(line)
		# print(line)
		for node_id in G.nodes:
			
#			print (node_id," -> ",G._node[node_id]['label'])
		
			if(re.search("^void " + G._node[node_id]['label'][1:-1],line)):
				
				writefile.write("SimNamedMarker(5, __func__);\n")
				count=count+1
		
	print("Markers added:",count)
#with open('./SDF-BeamFormer_nocache_new.c', 'w') as file:
#	file.write(data)

#print(file)








