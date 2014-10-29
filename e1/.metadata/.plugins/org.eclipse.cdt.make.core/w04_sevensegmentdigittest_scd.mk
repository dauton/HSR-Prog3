# This is a generated file. Please do not edit.

.PHONY: all

COMMANDS := 	\
	    scd_cmd_1

all: $(COMMANDS)

scd_cmd_1:
	@echo begin generating scanner info for $@
	g++ -O0 -I "/home/hsr/c++-workspace/w04_sevensegmentdigit" -I "/home/hsr/c++-workspace/w04_sevensegmentdigittest/cute" -E -P -v -dD specs.cpp
	@echo end generating scanner info for $@


