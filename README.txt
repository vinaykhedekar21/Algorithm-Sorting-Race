
Project Number and Name - Project #1 – Sort Race

Team Name - ACVK

Team Members - Vinay Khedekar (CWID-893284166)
						 
I. Introduction -

The project #1 is about identifying the fastest algorithm by executing two sorting algorithm, we call it sorting race. We are using two sorting algorithms,
one with complexity O(N^2) a bubble sort algorithm and another with complexity  O(N*logN) a Merge Sort algorithm. 
The project technical flow broadly contains below components.

1. Input for each algorithm is a integer array of elements, maximum upto 12 elements.

2. Race Mgr - 
Race manager is the main class and starting point for the race. It contains the logic to accepts the user inputs and invoking each algorithms step method. 
It consist of objects for the sorting alogorithms, in our case Bubble sort object and Merge Sort object.
It gives each algorithm a turn to execute a comparision operation alternatively. It keeps track of which algorithm is still running and count of how many turn it took to complete the race. 
Also, it print out three main items-
a. The current step call count
b. The algorithm's ID letter (I, B, M, H, or Q)
c. The current state of the algorithm's integer array inside brackets and final output as  #12, B: [2, 4, 3, 6, 14, 10, 9, 1]

3. Step method - 
Each algorithm will have its own step method like bubbleStep() and mergeStep(). Step method will have sorting logic for respective algorithm which is implemented to execute algorithm's in alternate turns 
as each algorithm will perform a comparison and will give a control to race manager to run another algorithm's step method.
It also, keep track of whether algorithm has completed its execution and prints execution for each step. 
Once the array is completly sorted, it will stop calling its step method and print the output with number of turn it took to complete.
						  
II. Contents of zip folder

The zip file contains below folders and files in it.

1. Source folder -
	BubbleSort.cpp
	BubbleSort.h
	MergeSort.h
	MergeSort.cpp
	RaceMgr.cpp
	
2. Test Runs folder-

All test run files have been kept at folder location: 335-p1_ACVK\Test_Runs

3. README.txt file

III. External Requirements

No external requirements and dependancies to run the project.

IV. Setup and Installation 

Steps-
1. Copy all the source files from the folder : 335-p1_ACVK\Source_Files  into your IDE.
2. Build the project
3. Run the project

V. Sample Invocation

After runniing the project, you will be promted to enter number of integers you want to sort and all those integers one by one.
Sample Run -

Enter number of elements you want to sort:7
Enter Element 1: 4
Enter Element 2: 1
Enter Element 3: 3
Enter Element 4: 2
Enter Element 5: 8
Enter Element 6: 5
Enter Element 7: 7
Initial Array Elements are: [ 4 1 3 2 8 5 7 ]

 #1, B: [ 1 4 3 2 8 5 7 ]

 #1, M: [ 1 4 3 2 8 5 7 ]

 #2, B: [ 1 3 4 2 8 5 7 ]

 #2, M: [ 1 4 2 3 8 5 7 ]

 #3, B: [ 1 3 4 2 8 5 7 ]

 #3, M: [ 1 4 2 3 5 8 7 ]

 #4, B: [ 1 3 4 2 8 5 7 ]

 #4, M: [ 1 4 2 3 5 7 8 ]

 #5, B: [ 1 3 2 4 8 5 7 ]

 #5, M: [ 1 4 2 3 5 7 8 ]

 #6, B: [ 1 2 3 4 8 5 7 ]

 #6, M: [ 1 2 4 3 5 7 8 ]

 #7, B: [ 1 2 3 4 8 5 7 ]

 #7, M: [ 1 2 3 4 5 7 8 ]

 #8, B: [ 1 2 3 4 8 5 7 ]

 #8, M: [ 1 2 3 4 5 7 8 ]

 #9, B: [ 1 2 3 4 8 5 7 ]

 #9, M: [ 1 2 3 4 5 7 8 ]

 #10, B: [ 1 2 3 4 8 5 7 ]

 #10, M: [ 1 2 3 4 5 7 8 ]

 #11, B: [ 1 2 3 4 5 8 7 ]

 #11, M: [ 1 2 3 4 5 7 8 ]

 #12, B: [ 1 2 3 4 5 8 7 ]

 #12, M: [ 1 2 3 4 5 7 8 ]

 #13, B: [ 1 2 3 4 5 8 7 ]

 #13, M: [ 1 2 3 4 5 7 8 ]

 #14, B: [ 1 2 3 4 5 7 8 ]

 #14, M: [ 1 2 3 4 5 7 8 ]

 #15, B: [ 1 2 3 4 5 7 8 ]

 #15, M: [ 1 2 3 4 5 7 8 ]

 #16, B: [ 1 2 3 4 5 7 8 ]

 #15, M: [ 1 2 3 4 5 7 8 ]
Bubble Sort completed sorting the array in 16 steps.
Merge Sort completed sorting the array in 15 steps. 

 VI. Features-
 
 1. Users are allowed to provides input integers as elements to be sorted.
 2. Sorting algorithms runs alternatively and perform one comparision for each call.
 3. Race manager outputs a users whether algorithm has completed or still running, how many turn took by each algorithm to finish the sorting, and final sorted array.	
 4. Output displays execution of algorithms for each step and include information such as -
		a. The current step call count
		b. The algorithm's ID letter (I, B, M, H, or Q)
		c. The current state of the algorithm's integer array inside brackets [2, 4, 3, 6, 14, 10, 9, 1]
		
 
VII. Bugs or Limitation(If any)

1. Merge Sort is failing sorting backward when input elements are 12 but It works perfectly for other number of input elements.  

