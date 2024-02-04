SHELL = /usr/bin/env bash -o pipefail
.SHELLFLAGS = -ec

SOURCES = $(wildcard chapter-[1-9]/*.c chapter-11/*.c)
NAMES = $(basename $(SOURCES))
DIRS = $(wildcard ./chapter-*/)
DIST = $(subst ./,dist/,$(DIRS))
DATA = chapter-8/signals.txt

all: $(DIST) $(NAMES)
$(NAMES): $(SOURCES)
	cc $@.c -o dist/$@

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
