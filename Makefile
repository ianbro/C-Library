#################################################################
# variables, flags for CFLAGS
# -Wall flags all errors
# -Werror treats warning as an error
# -g  includes symbol table to help gdb
#
#################################################################

CFLAGS  = -g -Wall -Werror -pedantic
CC	= gcc

SRC 		= src/
BIN			= bin/

# Path to project within src folder
PP			= com/ianmann/lib/
TESTS		= $(PP)tests/

# Output files for adamation
OBJS    = $(BIN)$(PP)collections.o

# All test objects
TEST_MAINS = $(BIN)$(TESTS)test_colls.o

# Test dependencies and files
SRCTCOLLS	 = $(SRC)$(TESTS)test_colls.c
BINTCOLLS  = $(BIN)$(TESTS)test_colls.o
TCOLLSOBJS = $(OBJS) $(SRCTCOLLS)

# Builds test main for test_colls.c
$(BINTCOLLS): $(TCOLLSOBJS)
	$(CC) $(CFLAGS) $^ -o $@

# build indevidual object files for library
$(BIN)$(PP)%.o: $(SRC)$(PP)%.c
	$(CC) $(CFLAGS) -c $^ -o $@

# builds all tests
tests: $(TEST_MAINS)

clean:
	rm -rf $(BIN)
	cp -rf $(SRC) $(BIN)
	find $(BIN) -name "*.c" -type f -delete
	find $(BIN) -name "*.o" -type f -delete
