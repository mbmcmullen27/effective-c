SHELL = /usr/bin/env bash -o pipefail
.SHELLFLAGS = -ec

SOURCES = $(wildcard chapter-[1-9]/*.c chapter-11/*.c)
NAMES = $(basename $(SOURCES))
DIST = $(subst ./,dist/,$(wildcard ./chapter-*/))

all: $(DIST) $(NAMES)
$(NAMES): $(SOURCES)
	cc $@.c -o dist/$@

$(DIST): $(wildcard chapter-*/)
	mkdir -p $@

.Phony: clean check distcheck failing
clean: dist/*
	rm -r dist/

check:
	echo "todo: implement $@"

distcheck:
	echo "todo: implement $@"

failing: */*.fails
	echo */*.fails | tr " " "\n"