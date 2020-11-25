
#!/usr/bin/make -f
	#
	# Filename:		Makefile
	# Date:			11/25/2020
	# Author:		Maha Siddique
	# Email:		mxs151731@utdallas.edu
	

	# C++ rules
	CXX = g++
	CXXFLAGS =
	CPPFLAGS = -Wall -Wno-write-strings -g -I/scratch/perkins/include
	LDFLAGS = -L/scratch/perkins/lib
	LDLIBS = -lcdk -lcurses
	

	# PROJECTNAME the name of the main assignment which is assignment 6
	PROJECTNAME = CS_3377_Assignment6
	

	# C++ Source Files
	SRCS := $(wildcard *.cc)
	

	# Name of Executable
	EXEC = Assignment6
	

	OBJS = $(SRCS:.cc=.o)
	

	.PHONY: all clean
	

	# Execute First Makefile Rule
	all: $(EXEC)
	

	# Clean Folder's Files
	clean:
		rm -f $(OBJS) *.d *~ \#* $(EXEC)
	

	# Rule To Link Files
	$(EXEC): $(OBJS)
		$(CXX) -o $@ $(OBJS) $(LDFLAGS) $(LDLIBS)
	

	# Backup Target
	backup:	clean
		@mkdir -p ~/backups; chmod 700 ~/backups
		@$(eval CURDIRNAME := $(shell basename "`pwd`"))
		@$(eval MKBKUPNAME := ~/backups/$(PROJECTNAME)-$(shell date +'%Y.%m.%d-%H:%M:%S').tar.gz)
		@echo
		@echo Writing Backup file to: $(MKBKUPNAME)
		@echo
		@-tar zcfv $(MKBKUPNAME) ../$(CURDIRNAME) 2> /dev/null
		@chmod 600 $(MKBKUPNAME)
		@echo
		@echo Done!




