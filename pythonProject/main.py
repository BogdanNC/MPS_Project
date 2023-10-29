import csv
from locale import atoi

# Open file
with open('GlobalTest.csv', newline='') as file_obj:

    reader_obj = csv.reader(file_obj)
    # Iterate over each row in the csv
    # file using reader object
    row = next(reader_obj)
    print(row)
    row = next(reader_obj)
    print(row)
    row = next(reader_obj)
    sum = 0.0
    totalNum = 0.0
    for number in row[1:] :
        sum = float(number) + sum
        totalNum += 1
        print(number)

    print(sum/totalNum)

    #for row in reader_obj:
    #    print(row)

print("hello world")
