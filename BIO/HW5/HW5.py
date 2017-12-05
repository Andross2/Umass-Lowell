#
#		Chuong Vu
#		Bioinformatics
#		Homework 5
#		Prof Kim Byung
#
#

import pprint
import random
import json
from array import array
from collections import OrderedDict
import timeit
#from collections import deque

# reads with average 400 bp
reads = 400

## Working files

# I manually copy 200 line from the removed N
# to write the test because the original file is too long
# it cause my program out of memory
DNA_File1_FASTA = "chr01.fasta"
DNA_File1_RmN = "chr01.RemoveN.orig"
DNA_File1_Orig = "chr01.orig"
DNA_File1_Frag = "chr01.frag"
DNA_File1_Graph = "chr01.graph"
DNA_File1_Graph_Largest = "chr01.graph.largest"
DNA_File1_Path = "chr01.path"
DNA_File1_NewDNA_Seqs = "chr01.newdna.seqs"
DNA_File1_NewDNA = "chr01.newdna"


DNA_File2_FASTA = "chr21.fasta"
DNA_File2_RmN = "chr21.RemoveN.orig"
DNA_File2_Orig = "chr21.orig"
DNA_File2_Frag = "chr21.frag"
DNA_File2_Graph = "chr21.graph"
DNA_File2_Graph_Largest = "chr21.graph.largest"
DNA_File2_Path = "chr21.path"
DNA_File2_NewDNA_Seqs = "chr21.newdna.seqs"
DNA_File2_NewDNA = "chr21.newdna"


# Combined from both file
DNA_File3_RmN = "chrc"
DNA_File3_Orig = "chrc.orig"
DNA_File3_Frag = "chrc.frag"
DNA_File3_Graph = "chrc.graph"
DNA_File3_Graph_Largest = "chrc.graph.largest"
DNA_File3_Path = "chrc.path"
DNA_File3_NewDNA_Seqs = "chrc.newdna.seqs"
DNA_File3_NewDNA = "chrc.newdna"

#
# 1. Remove all N character and SPACE
#
def CleanUpOriginalFileToNewFile(InputFile, OutputFile):
	with open(InputFile, "r") as infile, open(OutputFile, "w") as outfile:
		data = infile.read()
		data = data.replace('N', '')
		data = data.replace(' ', '')
		outfile.write(data)
	return

#	2.
#	Function use to create fragment file from short file
#	This is get random by length of string * 10 and / reads
#
def CreateFragFile(InputFile, OutputFile, OutputFile1):
	FileRead = open(InputFile, "r")
	
	lines = FileRead.readlines()
	DNA_Seq = ''
	
		#DNA_Seq = infile.read()
		#DNA_Seq = DNA_Seq.replace('\n', '')
	for line in lines:
		line = line.replace('\n','')
		if not line.startswith('>'):
			DNA_Seq += line
	
	FileWrite = open(OutputFile1, "w")
	FileWrite.write(DNA_Seq)
	FileWrite.close()
	# get fragment numbers

	frag_num = (len(DNA_Seq) * 10) / reads

	# genete the uniquie start points from DNA sequence based on length from 0 to length - 400
	unum = random.sample(range(0, len(DNA_Seq) - reads), int(frag_num))

	#sorted the array
	#unum.sort()

	# Open file to write
	File_Write = open(OutputFile, "w")

	#print(DNA_Seq)
	#print(unum)
	#print(len(unum))

	# based on the start points, get the fragment sequence and save to output file
	for i in range(len(unum)):
		frag = ''
		frag_end = unum[i] + reads
		frag = DNA_Seq[unum[i]:frag_end]
		File_Write.write(frag + '\n')

	# close file
	File_Write.close()
	return

def JoinFile(Input1, input2, output):
	filenames = [Input1, input2]
	with open(output, 'w') as outfile:
		for fname in filenames:
			with open(fname) as infile:
				for line in infile:
					outfile.write(line)
	return


#
# 3.Create overlap graphs between all fragments
#
def CreateOverlapGraph(InputFile, OutputFile):
	
	OverlayValue = 0
	FileRead = open(InputFile, "r")
	FileWrite = open(OutputFile, "w")

	# Read all lines and store to array
	frag = FileRead.readlines()
	#print(frag[1][1:10])

	# Get numbers of fragment
	frag_num = len(frag)
	#print(frag_num)

	#Graphs = [{} for x in range(frag_num)]

	#print(Graphs)

	# This first loop is get the first DNA Sequence
	for i in range(0, frag_num):
		# Create dict object
		overlap = {}
		# write the line to file (ex 0:)
		#FileWrite.write(str(i) + ": ")

		# this loop get the second DNA Sequence
		for j in range(0, frag_num):
			# if they are same line, ignore and continues
			if (i == j):
				continue
			overlap_index = 0
			# this loop is use to compare the first and seoncd DNA Sequences
			# this run from position 0 to 399 (Mean from 1 to 400)
			for k in range(0, reads - 1):
				# check if the suffix and preffix is same
				if(frag[i][-k-2:-1] == frag[j][0:k+1]):
					overlap_index = k
				
			if(overlap_index > 0):
				# add to dict object
				overlap[j] = overlap_index

		#print(overlap)
		json.dump(overlap, FileWrite)
		FileWrite.write('\n')

	#print(Graphs)
	FileRead.close()
	FileWrite.close()

	return

#
#	4.Get largest overlap graph
#
def CreateLargestOverlapGraph(InputFile, OutputFile):

	FileRead = open(InputFile, "r")
	FileWrite = open(OutputFile, "w")

	# Read all lines and store to array
	Graphs_X = FileRead.readlines()
	#print(Graphs_X[0])

	graph_num = len(Graphs_X)

	Graphs = [{} for i in range(graph_num)]
	#Convert Graphs_X to dict and store to Graphs
	for i in range(0, graph_num):
		Graphs[i] = json.loads(Graphs_X[i])

	graph_l = [{} for i in range(graph_num)]

	for i in range(0, graph_num):
		#Keep tract other
		#FileWrite.write(str(i) + " ")
		overlap_value = 0
		overlap_index = 0
		for key,value in Graphs[i].items():
			# get max value from graph
			if (overlap_value < value):
				overlap_value = value
				overlap_index = key
		graph_l[i][overlap_index] = overlap_value
		json.dump(graph_l[i], FileWrite)
		FileWrite.write('\n')
	FileRead.close()
	FileWrite.close()

	return

#
#	5.Create path from the largest overlap graph
#
def CreatePath(InputFile, OutputFile):

	FileRead = open(InputFile, "r")
	FileWrite = open(OutputFile, "w")
	
	graph_X = FileRead.readlines()
	Graph_num = len(graph_X)

	graph_l = [{} for i in range(Graph_num)]
	#Convert Graphs_X to dict and store to Graphs
	for i in range(0, Graph_num):
		graph_l[i] = json.loads(graph_X[i])

	#Creat object path with subclass OrderedDict()
	Graph_Path = [OrderedDict() for i in range(Graph_num)]
	#print(Graph_Path)
	
	for i in range(Graph_num):
		path = [0 for j in range(Graph_num)]
		path[i] = 1
		lap_weight = 0
		next_vertex = i
		while True:
			current_vertex = next_vertex
			graph = graph_l[current_vertex]
			next_vertex = int(list(graph.keys())[0])
			lap_weight = list(graph.values())[0]
			#print(graph, next_vertex, lap_weight)
			if (path[next_vertex] == 0):
				Graph_Path[i][current_vertex] = lap_weight
				#set path to 1 so it wont read it again
				path[next_vertex] = 1
				lap_weight = 0
			else:
				break

		del path
		json.dump(Graph_Path[i], FileWrite)
		FileWrite.write('\n')

	#print(Graph_Path[0])
	FileRead.close()
	FileWrite.close()
	return

#
# 6.create new DNA based on overlap path
#
def CreateNewDNASequence(InputFile1, InputFile2, OutputFile):

	FileRead = open(InputFile1, "r")
	FileWrite = open(OutputFile, "w")
	FileRead1 = open(InputFile2, "r")
	Fragment = FileRead1.readlines()
	#print(Fragment[0])
	
	graph_X = FileRead.readlines()
	Graph_num = len(graph_X)

	#print(graph_X[0])

	Graph_Path = [{} for i in range(Graph_num)]
	#Convert Graphs_X to dict and store to Graphs
	for i in range(0, Graph_num):
		Graph_Path[i] = json.loads(graph_X[i], object_pairs_hook=OrderedDict)
	#print(graph_X[0])
	newDNA_num = len(Graph_Path)
	newDNA_seq = ['' for i in range(newDNA_num)]

	#print(newDNA_num, newDNA_seq)

	next_seq = 0

	for path in Graph_Path:
		i = int(list(path)[0])
			#print("index:", i)
		overlap = int(list(path.values())[0])
			#print("overlap:", overlap)
		newDNA_seq[next_seq] = Fragment[i].strip('\n')
		#print(newDNA_seq[next_seq])
		for i, nextlap in list(path.items())[1:]:
			newDNA_seq[next_seq] += Fragment[int(i)][overlap+1:].strip('\n')
			overlap = nextlap

		json.dump(newDNA_seq[next_seq], FileWrite)
		FileWrite.write('\n')
		next_seq += 1
	FileRead.close()
	FileRead1.close()
	FileWrite.close()
	return

def CreateDNASequence(InputFile, OutputFile):
	FileRead = open(InputFile, "r")
	FileWrite = open(OutputFile, "w")

	newDNA_logest_len = 0
	Sequences = FileRead.readlines()

	# Remove " sign from read string
	for i in range(len(Sequences)):
		Sequences[i] = Sequences[i].replace('"', '')
		Sequences[i] = Sequences[i].replace('\n', '')

	# Calculate the longest DNA sequences
	for i in Sequences:
		if (newDNA_logest_len < len(i)):
			newDNA_logest_len = len(i)
			#seq = i

	#print(Sequences[0])
	# The new DNA sequence will have the length of the longest DNA sequences
	# Calculate column by column to fine get the new letter
	newDNA_consensus = ''
	newDNA_consensus_len = len(Sequences)

	for i in range(newDNA_logest_len):
		consensus = {"A": 0, "C": 0, "G": 0, "T": 0}
		# Get each string in array of string
		for new_seq in Sequences:
			if (len(new_seq) > i):
				# increase letter counting
				consensus[new_seq[i]] += 1
		newDNA_consensus += max(consensus, key=consensus.get)

	FileWrite.write(newDNA_consensus)
	FileRead.close()
	FileWrite.close()
	return

def CompareDNAs(InputFile1, InputFile2, Org, New):
	FileRead1 = open(InputFile1, "r")
	FileRead2 = open(InputFile2, "r")

	# Get DNA sequence
	New_DNA = FileRead1.readlines()[0]
	Org_DNA = FileRead2.readlines()[0]

	# Get lenght
	New_DNA_len = len(New_DNA)
	Org_DNA_len = len(Org_DNA)
	
	most_ol = 0
	for i in range(Org_DNA_len):
		k = i
		overlap = 0
		for j in range(New_DNA_len):
			if (k < Org_DNA_len):
				if (Org_DNA[k] == New_DNA[j]):
					overlap += 1
				k += 1
			else:
				break
		if (overlap > most_ol):
			most_ol = overlap

	print("Org DNA", Org, "vs New OLC DNA", New)
	print("Org DNA", Org, "Length =", Org_DNA_len)
	print("New DNA", New, "Length =", New_DNA_len)
	print("Number's Overlap =", most_ol)
	print('')
	FileRead1.close()
	FileRead2.close()
	return

def main():

#========================================
#	1. Remove the N and other character
#========================================
	CleanUpOriginalFileToNewFile(DNA_File1_FASTA, DNA_File1_RmN)
	CleanUpOriginalFileToNewFile(DNA_File2_FASTA, DNA_File2_RmN)
	JoinFile(DNA_File1_RmN, DNA_File2_RmN, DNA_File3_RmN)
	print("1. Clean Up - Done")

#========================================
#	2. From short file (200 lines) make a fragment file (Manually made)
#========================================
	CreateFragFile(DNA_File1_RmN, DNA_File1_Frag, DNA_File1_Orig)
	CreateFragFile(DNA_File2_RmN, DNA_File2_Frag, DNA_File2_Orig)
	CreateFragFile(DNA_File3_RmN, DNA_File3_Frag, DNA_File3_Orig)
	print("2. Get Fragment - Done")

#========================================
#	3. Calculate the overlap and save to overlap graph from reads
#========================================
	CreateOverlapGraph(DNA_File1_Frag, DNA_File1_Graph)
	CreateOverlapGraph(DNA_File2_Frag, DNA_File2_Graph)
	CreateOverlapGraph(DNA_File3_Frag, DNA_File3_Graph)
	print("3. Calculate Overlap - Done")

#========================================
#	4. Get the largest overlap graph from the graph_short file
#========================================
	CreateLargestOverlapGraph(DNA_File1_Graph, DNA_File1_Graph_Largest)
	CreateLargestOverlapGraph(DNA_File2_Graph, DNA_File2_Graph_Largest)
	CreateLargestOverlapGraph(DNA_File3_Graph, DNA_File3_Graph_Largest)
	print("4. Get Largest Overlap Graph - Done")

#========================================
#	5. Create path from the largest overlap graph
#========================================
	CreatePath(DNA_File1_Graph_Largest, DNA_File1_Path)
	CreatePath(DNA_File2_Graph_Largest, DNA_File2_Path)
	CreatePath(DNA_File3_Graph_Largest, DNA_File3_Path)
	print("5. Get Path - Done")

#========================================
#	6. Calculate new DNA sequences from overlap path
#========================================
	CreateNewDNASequence(DNA_File1_Path, DNA_File1_Frag, DNA_File1_NewDNA_Seqs)
	CreateNewDNASequence(DNA_File2_Path, DNA_File2_Frag, DNA_File2_NewDNA_Seqs)
	CreateNewDNASequence(DNA_File3_Path, DNA_File3_Frag, DNA_File3_NewDNA_Seqs)
	print("6. Get New DNA Sequences - Done")

#========================================
#	7. Create one new DNA sequence from new DNA sequences
#========================================
	CreateDNASequence(DNA_File1_NewDNA_Seqs, DNA_File1_NewDNA)
	CreateDNASequence(DNA_File2_NewDNA_Seqs, DNA_File2_NewDNA)
	CreateDNASequence(DNA_File3_NewDNA_Seqs, DNA_File3_NewDNA)
	print("7. Create one new DNA sequence - Done")

#========================================
#	8. Compare new and orignal DNA
#========================================
	CompareDNAs(DNA_File1_NewDNA, DNA_File1_Orig, "1", "1")
	CompareDNAs(DNA_File2_NewDNA, DNA_File2_Orig, "2", "2")
	CompareDNAs(DNA_File1_NewDNA, DNA_File3_Orig, "1", "3")
	CompareDNAs(DNA_File2_NewDNA, DNA_File3_Orig, "2", "3")
	print("8. Compare two DNAs - Done")

main()