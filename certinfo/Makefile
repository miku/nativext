SOURCES := $(shell find $(SOURCEDIR) -name '*.c')

certinfo:
	cc -o certinfo certinfo.c -lcurl

.PHONY: build
build: fmt
	python setup.py build
	find . -type f -name "*.so" -exec cp {} . \; # so we can import directly

.PHONY:
clean:
	rm -f certinfo
	rm -f *.so

.PHONY: fmt
fmt: $(SOURCES)
	clang-format -i --style WebKit $(SOURCES)
	black setup.py
