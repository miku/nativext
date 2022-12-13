SHELL=/bin/bash
SOURCES := $(shell find $(SOURCEDIR) -name '*.c')

.PHONY: build
build: fmt
	python setup.py build
	find . -type f -name "*.so" -exec cp {} . \; # so we can import directly

.PHONY: fmt
fmt: $(SOURCES)
	clang-format -i --style WebKit $(SOURCES)

.PHONY: clean
clean:
	rm -rf build
	rm -f *.so
