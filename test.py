import numpy as np
import os
import struct

#def load(folder):
#    """
#    load the thermal model from the given folder
#    """


class Eigendata():

	def _read_int(self,f):
		data = f.read(4)
		return struct.unpack('i', data)[0]

	def _read_float(self,f):
		data = f.read(4)
		return struct.unpack('f', data)[0]

	def _read_double(self,f):
		data = f.read(8)
		return struct.unpack('d', data)[0]

	def _read_double_matrix(self,f, rows, columns):
		matrix = []
		for r in range(rows):
		    row = []
		    for c in range(columns):
		        row.append(self._read_double(f))
		    matrix.append(row)
		return np.asarray(matrix)

	def _read_double_vector(self,f, elements):
		vector = []
		for n in range(elements):
		    vector.append(self._read_double(f))
		return np.asarray(vector)

	def _read_line(self,f):
		data = ""
		c = f.read(1)
		while c not in (b"", b"\n"):
		    data += chr(c[0]) if isinstance(c[0], int) else c[0]
		    c = f.read(1)
		return data




	#floorplan_filename = os.path.join(folder, FLOORPLAN)
	#powertrace_filename = os.path.join(folder, POWERTRACE)
	def get_values(self):
		EIGENDATA = 'eigendata.bin'
		
		folder = "../MatEx/"
		eigen_filename = os.path.join(folder, EIGENDATA)

		with open(eigen_filename, 'rb') as f:
			numberUnits = self._read_int(f)
			numberNodesAmbient = self._read_int(f)
			numberThermalNodes = self._read_int(f)
			assert numberThermalNodes == 4 * numberUnits + 12
			assert numberNodesAmbient == numberThermalNodes - 3 * numberUnits

			unitNames = []
			for u in range(numberUnits):
				unitName = self._read_line(f)
				unitNames.append(unitName)
				#width = readDouble(f)
				#height = readDouble(f)

			BInv = self._read_double_matrix(f, numberThermalNodes, numberThermalNodes)
			tick = 0.01

			G = [0.0] * (numberThermalNodes - numberNodesAmbient)
			for n in range(numberNodesAmbient):
				G.append(self._read_double(f))
			G = np.asarray(G)

			eigenValues = self._read_double_vector(f, numberThermalNodes)
			eigenVectors = self._read_double_matrix(f, numberThermalNodes, numberThermalNodes)
			eigenVectorsInv = self._read_double_matrix(f, numberThermalNodes, numberThermalNodes)
			
			D = np.diag(np.exp(eigenValues*tick))
			
			psi = np.matmul(np.matmul(eigenVectors,D),eigenVectorsInv)
#			print("psi:",psi," psi sahpe",psi.shape)
#			
#			print("B_inv: ",BInv)
			assert f.read(1) == b''
			
			return BInv,psi

	#    return ThermalModel(folder, unitNames, BInv, G, eigenValues, eigenVectors, eigenVectorsInv)
	



