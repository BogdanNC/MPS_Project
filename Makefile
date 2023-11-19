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
OBJS = $(FILE_NAME).o FunctionKing.o

# *******************************************
# ************ FILE GENERATION **************
# *******************************************
$(FILE_NAME): $(OBJS)
	g++ $(CXXFLAGS) $(OBJS) -o $(FILE_NAME)

$(FILE_NAME).o: $(FILE_NAME).cpp FunctionKing.h
	g++ $(CXXFLAGS) -c $(FILE_NAME).cpp

FunctionKing.o: FunctionKing.cpp FunctionKing.h
	g++ $(CXXFLAGS) -c FunctionKing.cpp

# *******************************************
# ************ RUN **************************
# *******************************************
run:
	./$(FILE_NAME) $1 $(FOLDER)/$(FILE1).$(EXTENSION) $(FOLDER)/$(FILE2).$(EXTENSION)

default_run:
	./$(FILE_NAME) 100 $(FOLDER)/$(FILE1).$(EXTENSION) $(FOLDER)/$(FILE2).$(EXTENSION)

# *******************************************
# *********** CLEAN *************************
# *******************************************
clean:
	rm -f $(OBJS) $(FILE_NAME)

# *******************************************
# ********** TEST ***************************
# *******************************************
test_function_king:
	g++ -o testFunctionKing FunctionKing.cpp TestFunctionKing.cpp $(CXXFLAGS)

# Mark targets as phony
.PHONY: run default_run clean test_function_king
