# Master Makefile

include EpisodeThree.var.mk

.PHONY: all clean

all:
	@echo "---------[Building : $(PROJECT) - $(CONFIG)]---------"
	@$(MAKE) -f "EpisodeThree.mk"

clean:
	@echo "---------[Cleaning : $(PROJECT) - $(CONFIG)]---------"
	@$(MAKE) -f "EpisodeThree.mk" clean
