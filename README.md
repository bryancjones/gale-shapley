gale-shapley
============

An implementation of the Gale-Shapley matching algorithm

To Execute the Gale-Shapley Algorithm, one will need a csv file with n individuals, classified into two groups of size n/2 (in the classic Stable Marriage Problem, these groups would be n/2 males and n/2 females). Each group only selects individuals from the other group for their preference rankings. Each row corresponds to a person and should have 7 entries corresponding to the person’s ranking of their desired partners. All members of one group should be listed first and then members of the next group in the csv. Depending on whether or not you have an existing csv file on which to run the algorithm, your first step in running our code might differ. If you do not have a csv file fitting these parameters, continue to step 1 to generate such a file by simulating preferences in a variety of situations. Otherwise, proceed to step 2 with your current file.

1. Generate CSV files with preference networks. Open the “data.py” file. We provided code to generate many datasets in the main section. All of these datasets can be found in the directory, but if you would like to regenerate them again, clear all datasets from your directory and then type “python3 data.py” into Terminal. If you would like to generate your own dataset, then clear all code in the main section and instead use a line in the following format to define your dataset: “makeData(num, groups, popNum, preferenceNum, fileName)”. The comment at the top of “data.py” describes what kinds of values you should fill in for each of these variables.

2. If you would like to run the Gale-Shapley algorithm on our pre-generated datasets, simply type “icompile —-run” into Terminal. 

3. If you would like to run the Gale-Shapley algorithm on your own dataset, then open up the “main.cpp” file. You can either leave our code, or delete it and replace it with your own. To run the algorithm, use a line in the following format: “GaleShapley(Graph(“data.csv”));” where data.csv is replaced with your data file name.

4. If you would like to print the pairings produced by the Gale-Shapley algorithm, then open “GaleShapley.h”. At the bottom of the document in the GaleShapley class, you will see  the line, 
“const float galeShapleyHelper(Graph people, bool oneSided = true, bool guyFirst = true, bool print = false);”
You should change the default value of print to be true, so that the line reads, 
“const float galeShapleyHelper(Graph people, bool oneSided = true, bool guyFirst = true, bool print = true);”
After you have saved this change, run the program again on your dataset.

The standard output from the Gale-Shapley algorithm is average happiness value per individual in the four different methods of implementing the algorithm and a sentence indicating which method produced the best happiness rating (lower is better).
