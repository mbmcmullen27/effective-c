SHELL = /usr/bin/env bash -o pipefail
.SHELLFLAGS = -ec

SOURCES = $(wildcard chapter-[1-9]/*.c)
SOURCES_CHAPTER_11 = $(wildcard chapter-11/*.c)
NAMES = $(basename $(SOURCES))
NAMES_CHAPTER_11 = $(basename $(SOURCES_CHAPTER_11))
DIRS = $(wildcard ./chapter-*/)
DIST = $(subst ./,dist/,$(DIRS))
DATA = chapter-8/signals.txt
ANNEX_K_SUPPORTED := $(shell cc -dM -E - </dev/null | grep -c __STDC_LIB_EXT1__)

all: $(DIST) $(NAMES) $(NAMES_CHAPTER_11)

$(NAMES): $(SOURCES)
	cc $@.c -o dist/$@

$(NAMES_CHAPTER_11): $(SOURCES_CHAPTER_11)
ifeq ($(ANNEX_K_SUPPORTED),1)
	cc $@.c -o dist/$@
else
	cc $@.c -o dist/$@ -lsafec
endif

$(DIST): $(DIRS)
	mkdir -p $@

dist/$(DATA): $(DIST) $(DATA)
	cp $(DATA) dist/$(DATA)

.Phony: clean check distcheck failing
clean: dist/*
	rm -r dist/

check:
	echo "todo: implement $@"

distcheck:
	echo "todo: implement $@"

failing: */*.fails
	echo */*.fails | tr " " "\n"
