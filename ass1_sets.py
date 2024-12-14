'''

In second year, computer engineering class, group A student’s play cricket, group B students play 
badminton and group C students play football. Write a Python program using functions to compute 
following: - 
a) List of students who play both cricket and badminton 
b) List of students who play either cricket or badminton but not both 
c) Number of students who play neither cricket nor badminton 
d) Number of students who play cricket and football but not badminton.
#


'''

cricket = ['a', 'b', 'c','d'] 
badminton = ['e', 'f', 'a', 'z']
football = ['z', 'a', 'm', 'n', 'o', 'b']


def cricketandBadminton():
    res = []
    for i in cricket :
        if(i in badminton):
            res.append(i)
     
    return res

def cricketORbadminton():
    #symmetric difference
    res= []
    for i in cricket :
        if(i not in  badminton) :
            res.append(i)
    for j in badminton:
        if j not in cricket :
            res.append(j) 
    return res

            

def neitherCricketNorBadminton() :
    res = []
    for i in football : 
        if i not in cricket and i not in badminton:
            res.append(i) 
    return res

def cricketandfootballNObadminton():
    combined = cricket + football
    res = []  # Initialize an empty list for the result

    for i in combined:
        if i not in badminton:
            res[len(res):] = i  # Add only those elements not in badminton
    
    return set(res)


res = cricketandBadminton()
print("students Who play Both cricket and Badminton\n",res) 

res= cricketORbadminton() 
print("\nsymmetric diff of cricket and badminton\n", res)  


res = neitherCricketNorBadminton()
print("\nNeither Cricket and Badminton: \n", len(res), res)


res = cricketandfootballNObadminton() 
print("\n Cricket and football not badminton :\n ", len(res), res)