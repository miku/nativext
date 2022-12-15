SOURCES := $(shell find $(SOURCEDIR) -name '*.c')

.PHONY: conda-build
conda-build:
	conda build .

.PHONY: build
build: fmt
	python setup.py build
	python setup.py sdist # https://github.com/pypa/pip/issues/6041
	pip wheel .
	find . -type f -name "*.so" -exec cp {} . \; # so we can import directly

.PHONY:
clean:
	rm -rf build
	rm -rf dist
	rm -f certinfo
	rm -f *.so
	rm -fr certinfo.egg-info/
	rm -rf *.whl

.PHONY: fmt
fmt: $(SOURCES)
	clang-format -i --style WebKit $(SOURCES)
	black setup.py

certinfo:
	cc -o certinfo certinfo.c -lcurl

