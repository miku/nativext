SOURCES := $(shell find $(SOURCEDIR) -name '*.c')

.PHONY: build
build: fmt
	python setup.py build
	python setup.py sdist bdist_wheel
	find . -type f -name "*.so" -exec cp {} . \; # so we can import directly

.PHONY:
clean:
	rm -rf build
	rm -rf dist
	rm -f certinfo
	rm -f *.so
	rm -fr certinfo.egg-info/

.PHONY: fmt
fmt: $(SOURCES)
	clang-format -i --style WebKit $(SOURCES)
	black setup.py

certinfo:
	cc -o certinfo certinfo.c -lcurl

