'''
Problem Statement: Write a Python program to store marks scored in subject “Fundamental of 
Data Structure” by N students in the class. Write functions to compute following: 
a) The average score of class 
b)Highest score and lowest score of class 
c)Count of students who were absent for the test 
d)Display mark with highest frequency 

'''
marks = [10, 9,7,5,3,-1,8,9,2,4,6,0,-1,0,7] 
absent_students = marks.count(-1) 
present_students = len(marks) -  absent_students
totalScore = present_students * 10 

def avgScore():
    sum =  0 
    for i in marks:
        if(i != -1) :
            sum = sum + i 
    
    return (sum/totalScore)*10 

def marks_with_highest_freq():
    freq_count = []

    for i in marks:
        count = marks.count(i) 
        freq_count.append((i, count)) 
    
    unique = list(set(freq_count)) 
    
    prevHigh = 0
    highest_freq_element = []
    for i in unique :
        if i[1] > prevHigh  :
            prevHigh =  i[1]
            highest_freq_element = [i] 
        
        if i[1] == prevHigh :
            highest_freq_element.append(i)


    # print(highest_freq_element) 

    for i in highest_freq_element :
        if(i[0] == -1) :
            highest_freq_element.remove(i)
    
    print("marks with highest frequency\n", set(highest_freq_element))




score = avgScore()
print("Average score of class : ", round(score, 2))
marks_with_highest_freq() 

print("Absent students : ", absent_students)
print("Present students : ", present_students)