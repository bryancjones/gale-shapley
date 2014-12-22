import random
import csv

# This code is not designed to be elegant or efficient because our main priority
# when generating a data set was just to generate a realistic data set.
# Therefore, we wrote this program in Python in order to get it done quickly and easily.
# This data set generator takes the following parameters:
#     num = total number of people
#     groups = total number of social groups
#     popNum = total number of popular social groups
#     preferenceNum = number of preferences indicated by each person
#     fileName = name of csv file to write data to
# The total number of people should be even. The group size (determined by dividing
# the number of people by the number of groups) should be an integer divisible by 10.
# The number of popular groups should be less than or equal to the number of groups.
# The data set produced has males as the first half and females as the second half.
# We assume that each social group is half males and half females.
def makeData(num, groups, popNum, preferenceNum, fileName):
    # Initialize variables.
    data = []
    half = num//2
    groupSize = half//groups
    inGroup = int(0.6*groupSize)
    weird = int(0.2*groupSize)
    popular = []
    # Assign preferences to males.
    # Populate the array of popular people.
    for i in range(half, half + (popNum+1)*groupSize):
        popular.append(i)
    # Assign preferences to members of popular groups.
    for g in range(0, popNum):
        # 60% of the group selects within their group.
        for i in range(0, inGroup):
            data.append(random.sample(range(half + groupSize*g, half + groupSize*(g+1)), preferenceNum))
        # 20% of the group selects within all the popular groups.
        for i in range(0, weird):
            data.append(random.sample(range(half, half + popNum*groupSize), preferenceNum))
        # 20% of the group selects within all of the females.
        for i in range(0,weird):
            data.append(random.sample(range(half, num), preferenceNum))
    # Assign preferences to members of nonpopular groups.
    for g in range(popNum,groups):
        # 60% of the group selects within their group.
        for x in range(0, inGroup):
            data.append(random.sample(range(half + groupSize*(g), half + groupSize*(g+1)), preferenceNum))
        # Place members of this group in the popular array.
        for x in range(0, groupSize):
            popular[groupSize*popNum + x] = half + groupSize*(g) + x
        # 20% of the group selects within their group and the popular groups.
        for x in range(0, weird):
            data.append(random.sample(popular, preferenceNum))
        # 20% of the group selects within all of the females.
        for x in range(0, weird):
            data.append(random.sample(range(half,num), preferenceNum))

    # Assign preferences to females.
    # Populate the array of popular people.
    for i in range(0, (popNum+1)*groupSize):
        popular.append(i)
    # Assign preferences to popular people.
    for g in range(0, popNum):
        # 60% of the group selects within their group.
        for i in range(0, inGroup):
            data.append(random.sample(range(groupSize*g, groupSize*(g+1)), preferenceNum))
        # 20% of the group selects within all the popular groups.
        for i in range(0, weird):
            data.append(random.sample(range(0, popNum*groupSize), preferenceNum))
        # 20% of the group selects within all of the males.
        for i in range(0,weird):
            data.append(random.sample(range(0, half), preferenceNum))
    # Assign preferences to members of nonpopular groups.
    for g in range(popNum,groups):
        # 60% of the group selects within their group.
        for x in range(0, inGroup):
            data.append(random.sample(range(groupSize*(g),groupSize*(g+1)), preferenceNum))
        # Place members of this group in the popular array.
        for x in range(0, groupSize):
            popular[groupSize*popNum + x] = groupSize*(g) + x
        # 20% of the group selects within their group and the popular groups.
        for x in range(0, weird):
            data.append(random.sample(popular, preferenceNum))
        # 20% of the group selects within all of the males.
        for x in range(0, weird):
            data.append(random.sample(range(0,half), preferenceNum))
   
    # Write the generated dataset to the csv file. It is important to note that this
    # code will append the dataset to any existing contents in the file, so each time
    # you generate a data set, you should use a new file name.
    with open(fileName, 'a') as f:
        writer = csv.writer(f)
        writer.writerows(data)

##### Main #####
if __name__ == '__main__':
    ## UT Austin - 50000 ##
    population = 50000
    groups = int(0.05 * population)
    popular = int(0.001 * population)
    rankings = 7
    makeData(population,groups,popular,rankings, "data_UTAustin.csv")
    ## Population Varied - 25,000 ##
    population = 25000
    groups = int(0.05 * population)
    popular = int(0.001 * population)
    rankings = 7
    makeData(population,groups,popular,rankings, "data_size25000.csv")
    ## Population Varied - 10,000 ##
    population = 10000
    groups = int(0.05 * population)
    popular = int(0.001 * population)
    rankings = 7
    makeData(population,groups,popular,rankings, "data_size10000.csv")
    ## Population Varied - 5,000 ##
    population = 5000
    groups = int(0.05 * population)
    popular = int(0.001 * population)
    rankings = 7
    makeData(population,groups,popular,rankings, "data_size5000.csv")
    ## Population Varied - 2,000 ##
    population = 2000
    groups = int(0.05 * population)
    popular = int(0.001 * population)
    rankings = 7
    makeData(population,groups,popular,rankings, "data_size2000.csv")
    ## Population Varied - 1,000 ##
    population = 1000
    groups = int(0.05 * population)
    popular = int(0.001 * population)
    rankings = 7
    makeData(population,groups,popular,rankings, "data_size1000.csv")
    ## Population Varied - 500 ##
    population = 500
    groups = int(0.05 * population)
    popular = int(0.001 * population)
    rankings = 7
    makeData(population,groups,popular,rankings, "data_size500.csv")
    ## Population Varied - 200 ##
    population = 200
    groups = int(0.05 * population)
    popular = int(0.001 * population)
    rankings = 7
    makeData(population,groups,popular,rankings, "data_size200.csv")
    ## Population Varied - 100 ##
    population = 100
    groups = int(0.05 * population)
    popular = int(0.001 * population)
    rankings = 7
    makeData(population,groups,popular,rankings, "data_size100.csv")
    makeData(80, 4, 3, 7, "data_WOOLF.csv")
    makeData(60, 2, 1, 7, "data_JA.csv")
    makeData(20, 1, 0, 7, "data_twenty.csv")        
        
