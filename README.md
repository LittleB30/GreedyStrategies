# GreedyStrategies
Your program will generate sequences of 100 random integers between 1 and 100. It will then use each of the 5 strategies discussed in class to try to pack the items represented by the numbers into bins of size 100, keeping track of the number of bins required by each strategy. Note that you’re using each sequence of numbers 5 times (once with each strategy).

Your program will do this 10 times, then report for each strategy both the average number of bins required and the number of runs (of the 10) for which that strategy did best (note that you may have multiple strategies that perform best for a given run). This summary information will be printed both to the screen and to a file named results.txt. Note that only summary information will be printed to the screen. You must also print all relevant information about each run to a file named rawdata.txt. For each run, this would include the list of 100 numbers, something indicating what bin each item was assigned to for each strategy, and the size of the final contents of each bin for each strategy. 

Format the information well enough for it to be readable and useful in determining whether you implemented each strategy correctly. Note that I have dictated nothing about the design of this program. You are responsible to apply basic principles of good program design to design the program well. You can complete this program without using dynamic memory that you are managing. If you choose to allocate memory dynamically (i.e. if you use the new operator), you must manage that memory properly.