# *******************************************
# ************* VARIABLES *******************
# *******************************************
FILE_NAME=main
FOLDER=global
FILE1=GlobalTest
FILE2=LUTTest
EXTENSION=csv

# Compilation Flags
CXXFLAGS = -fopenmp -O3 -march=native

# Object files
OBJS = $(FILE_NAME).o
#OBJS = $(FILE_NAME).o FunctionKing.o

# *******************************************
# ************ FILE GENERATION **************
# *******************************************
$(FILE_NAME): $(OBJS)
	g++ $(CXXFLAGS) $(OBJS) -o $(FILE_NAME)

$(FILE_NAME).o: $(FILE_NAME).cpp
	g++ $(CXXFLAGS) -c $(FILE_NAME).cpp

#$(FILE_NAME).o: $(FILE_NAME).cpp FunctionKing.h
#	g++ $(CXXFLAGS) -c $(FILE_NAME).cpp

#FunctionKing.o: FunctionKing.cpp FunctionKing.h
#	g++ $(CXXFLAGS) -c FunctionKing.cpp

# *******************************************
# ************ RUN **************************
# *******************************************

run_global_10:
	./$(FILE_NAME) global 10 $(FOLDER)/$(FILE1).$(EXTENSION) $(FOLDER)/$(FILE2).$(EXTENSION)

run_global_25:
	./$(FILE_NAME) global 25 $(FOLDER)/$(FILE1).$(EXTENSION) $(FOLDER)/$(FILE2).$(EXTENSION)

run_global_50:
	./$(FILE_NAME) global 50 $(FOLDER)/$(FILE1).$(EXTENSION) $(FOLDER)/$(FILE2).$(EXTENSION)

run_global_100:
	./$(FILE_NAME) global 100 $(FOLDER)/$(FILE1).$(EXTENSION) $(FOLDER)/$(FILE2).$(EXTENSION)

run_global_1000:
	./$(FILE_NAME) global 1000 $(FOLDER)/$(FILE1).$(EXTENSION) $(FOLDER)/$(FILE2).$(EXTENSION)

run_local_1:
	./$(FILE_NAME) local 1

run_local_3:
	./$(FILE_NAME) local 3

run_local_5:
	./$(FILE_NAME) local 5

run_local_7:
	./$(FILE_NAME) local 7

run_local_10:
	./$(FILE_NAME) local 10

# *******************************************
# *********** CLEAN *************************
# *******************************************
clean:
	rm -f $(OBJS) $(FILE_NAME)

clean_output_global:
	rm global/top7Graphs/f_measure*
	rm global/top7Graphs/tree*

clean_output_local:
	rm local/top7Graphs/f_measure*
	rm local/top7Graphs/tree*

# *******************************************
# ********** TEST ***************************
# *******************************************
#test_function_king:
#	g++ -o testFunctionKing FunctionKing.cpp TestFunctionKing.cpp $(CXXFLAGS)

# Mark targets as phony
.PHONY: run default_run clean
#.PHONY: run default_run clean test_function_king
