import pprint
from array import array
from terminaltables import AsciiTable

sscheme = ['T', 'C', 'A', 'G']
smatrix = [[20,10,5,5],
           [10,20,5,5],
           [5,5,20,10],
           [5,5,10,20]]

test = []
j = 0;
for row in range(0, len(smatrix) + 1):
    test.append([])
    for col in range(0, len(smatrix) + 1):
        if row == 0 and col == 0:
            test[0].append(" ")
        elif row == 0 and col > 0:
            test[0].append(sscheme[col - 1])
        elif row > 0:
            if col == 0:
                test[row].append(sscheme[j])
                j += 1
            else:
                test[row].append(smatrix[row-1][col-1])

table = AsciiTable(test)
table.inner_row_border = True

# for i in range(0, len(smatrix) + 1):
#     table.justify_columns[i] = 'center'


print("Score Scheme")
print (table.table)
print("                     ")
##########################################

score_dict = {(rx, cx) : smatrix[r][c] for r, rx in enumerate(sscheme) for c, cx in enumerate(sscheme)}

##########################################

def CalTable(strX, strY, gap):
    print("Data_Set 1st Sequence:", strX)
    print("Data_Set 2nd Sequence:", strY)
    print("Gap Penalty:", gap)
    
    strX = "-" + strX
    strY = "-" + strY
    
    len_strX = len(strX)
    len_strY = len(strY)
    
    score = len_strX*[len_strY*[0]]
    
    score_table = []
    j = 0

    for row in range(0, len_strY + 1):
        score_table.append([])
        for col in range(0, len_strX + 1):
            if row == 0 and col == 0:
                score_table[0].append(" ")
            elif row == 0 and col > 0:
                score_table[0].append(strX[col - 1])
            else:
                if col == 0:
                    score_table[row].append(strY[j])
                    j += 1
                elif row == 1 and col == 1:
                    score_table[row].append(0)
                elif row == 1:
                    score_table[row].append(score_table[row][col - 1] + gap)
                elif col == 1:
                    score_table[row].append(score_table[row - 1][col] + gap)
                else:
                    Match = score_table[row - 1][col - 1] + score_dict[(strY[row - 1], strX[col - 1])]
                    #print(row, col, strY[row - 1], strX[col - 1])
                    Insert = score_table[row][col - 1] + gap
                    Delete = score_table[row - 1][col] + gap
                    score_table[row].append(max(Match, Insert, Delete))

    print()
    print()
    print("Scoring Matrix")
    table_print = AsciiTable(score_table)
    table_print.inner_row_border = True
    
    # for i in range(0, len_strX + 1):
    #     table_print.justify_columns[i] = 'center'
	

    print(table_print.table)

    GetScore(score_table, strX, strY, gap)

    return
##########################################

def GetScore(AliTable, strX, strY, gap):
#    table_print = AsciiTable(AliTable)
#    table_print.inner_row_border = True
#    
#    print(table_print.table)

    strX = '-' + strX
    strY = '-' + strY
    
#    print(strX)
#    print(strY)

    # Pseudo-code based on Needleman-Wunsch algorithm that
    AlignmentA = []
    AlignmentB = []
    
    row = len(strY) - 1
    col = len(strX) - 1

    
    while(row > 1 or col > 1):
        if (row > 1 and col > 1 and AliTable[row][col] == AliTable[row - 1][col - 1] + score_dict[(strY[row], strX[col])]):
            AlignmentA.insert(0, strY[row])
            AlignmentB.insert(0, strX[col])
            row -= 1
            col -= 1
        elif (row > 1 and AliTable[row][col] == AliTable[row - 1][col] + gap):
            AlignmentA.insert(0, strY[row])
            AlignmentB.insert(0, '-')
            row -= 1
        else:
            AlignmentA.insert(0, '-')
            AlignmentB.insert(0, strX[col])
            col -= 1
    print()
    print("Alignment Sequence based on Needleman-Wunsch's algorithm")

    table_print = AsciiTable([AlignmentA,AlignmentB])
    table_print.inner_row_border = True

    #table_print.justify_columns[0] = 'center'
    print(table_print.table)

    Print_Score(AlignmentA, AlignmentB)

    return
##########################################
def Print_Score(AlgA, AlgB):

    match_score = 0
    mismatch_seq = 0
    gap_seq = 0
    match_seq = 0

#   print(len(AlgA))
    
    for i in range(0, len(AlgA)):
        if (AlgA[i] == AlgB[i]):
            match_seq += 1
            match_score += 1
        else:
            match_score -= 1
            if (AlgA[i] == '-' or AlgB[i] == '-'):
                gap_seq += 1
            else:
                mismatch_seq += 1

    print()
    print("Matched Sequence \t\t= ", match_seq)
    print("Mismatched Sequence \t\t= ", mismatch_seq)
    print("Gap \t\t\t\t= ", gap_seq)
    print("Alignment Sequence Score \t= ", match_score)

    return


##########################################
CalTable("ATGTTAT", "ATCGTAG", -1)

#print()
#print("-" * 60)
#CalTable("ATGTTAT", "ATCGTAG", -5)

#print()
#print("-" * 60)
#CalTable("ATGAATGCGATTTCGGGTGGCC", "TTGGCAGGACATGAAGTTCGATACGGAA", -1)

#print()
#print("-" * 60)
#CalTable("ATGAATGCGATTTCGGGTGGCC", "TTGGCAGGACATGAAGTTCGATACGGAA", -5)
