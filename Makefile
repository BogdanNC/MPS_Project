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

# *******************************************
# ************ FILE GENERATION **************
# *******************************************
$(FILE_NAME): $(FILE_NAME).o
		g++ $(CXXFLAGS) $(FILE_NAME).o -o $(FILE_NAME)

$(FILE_NAME).o: $(FILE_NAME).cpp
		g++ $(CXXFLAGS) -c $(FILE_NAME).cpp

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
		rm $(FILE_NAME).o
		rm $(FILE_NAME)

# *******************************************
# ********** TEST ***************************
# *******************************************

############ FUNCTION KING ##################
test_function_king:
	g++ -o $(FILE_NAME) FunctionKing.cpp TestFunctionKing.cpp
