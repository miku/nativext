# Conda package example

* using miniconda: https://docs.conda.io/en/latest/miniconda.html#linux-installers
* adjust path

Install `conda install conda-build`

> Conda recipes are typically built with a trial-and-error method. Often the
> first attempt to build a package fails with compiler or linker errors, often
> caused by missing dependencies. The person writing the recipe then examines
> these errors and modifies the recipe to include the missing dependencies,
> usually as part of the meta.yaml file. Then the recipe writer attempts the
> build again and, after a few of these cycles of trial and error, the package
> builds successfully.

```
$ make

...
# Automatic uploading is disabled
# If you want to upload package(s) to anaconda.org later, type:


# To have conda build upload to anaconda.org automatically, use
# conda config --set anaconda_upload yes
anaconda upload \
    /home/tir/.pyenv/versions/miniconda3-latest/envs/playground/conda-bld/linux-64/certinfo-0.1.0-py37_0.tar.bz2
anaconda_upload is not set.  Not uploading wheels: []

INFO :: The inputs making up the hashes for the built packages are as follows:
{
  "certinfo-0.1.0-py37_0": {
    "recipe": {}
  }
}


####################################################################################
Resource usage summary:

Total time: 0:00:30.3
CPU usage: sys=0:00:00.0, user=0:00:00.0
Maximum memory usage observed: 3.8M
Total disk usage observed (not including envs): 232B
```

The resulting file:

```
$ tar -tf /home/tir/.pyenv/versions/miniconda3-latest/envs/playground/conda-bld/linux-64/certinfo-0.1.0-py37_0.tar.bz2
info/hash_input.json
info/recipe/.gitignore
info/recipe/build.sh
info/recipe/meta.yaml.template
info/index.json
info/recipe/conda_build_config.yaml
info/recipe/setup.py
info/recipe/cidump.py
info/recipe/Makefile
info/has_prefix
info/recipe/README.md
info/files
info/recipe/meta.yaml
info/recipe/certinfo.c
info/recipe/certinfo_module.c
info/about.json
info/paths.json
info/git
lib/python3.7/site-packages/certinfo-1.0-py3.7-linux-x86_64.egg-info/not-zip-safe
lib/python3.7/site-packages/certinfo-1.0-py3.7-linux-x86_64.egg-info/PKG-INFO
lib/python3.7/site-packages/certinfo-1.0-py3.7-linux-x86_64.egg-info/dependency_links.txt
lib/python3.7/site-packages/certinfo-1.0-py3.7-linux-x86_64.egg-info/top_level.txt
lib/python3.7/site-packages/certinfo-1.0-py3.7-linux-x86_64.egg-info/requires.txt
lib/python3.7/site-packages/certinfo-1.0-py3.7-linux-x86_64.egg-info/native_libs.txt
lib/python3.7/site-packages/certinfo-1.0-py3.7-linux-x86_64.egg-info/SOURCES.txt
lib/python3.7/site-packages/certinfo.cpython-37m-x86_64-linux-gnu.so
lib/python3.7/site-packages/certinfo-1.0-py3.7-linux-x86_64.egg-info/scripts/__pycache__/cidump.cpython-37.pyc
bin/cidump.py
lib/python3.7/site-packages/certinfo.py
lib/python3.7/site-packages/certinfo-1.0-py3.7-linux-x86_64.egg-info/scripts/cidump.py
```

Unpacked archive contents:

```
[4.0K]  .
├── [4.0K]  bin
│   └── [ 420]  cidump.py
├── [4.0K]  info
│   ├── [2.7K]  about.json
│   ├── [ 902]  files
│   ├── [   0]  git
│   ├── [   2]  hash_input.json
│   ├── [ 607]  has_prefix
│   ├── [ 281]  index.json
│   ├── [3.6K]  paths.json
│   └── [4.0K]  recipe
│       ├── [  68]  build.sh
│       ├── [2.4K]  certinfo.c
│       ├── [2.6K]  certinfo_module.c
│       ├── [ 479]  cidump.py
│       ├── [ 458]  conda_build_config.yaml
│       ├── [ 546]  Makefile
│       ├── [1.4K]  meta.yaml
│       ├── [ 199]  meta.yaml.template
│       ├── [ 649]  README.md
│       └── [ 460]  setup.py
└── [4.0K]  lib
    └── [4.0K]  python3.7
        └── [4.0K]  site-packages
            ├── [4.0K]  certinfo-1.0-py3.7-linux-x86_64.egg-info
            │   ├── [   1]  dependency_links.txt
            │   ├── [  41]  native_libs.txt
            │   ├── [   1]  not-zip-safe
            │   ├── [  83]  PKG-INFO
            │   ├── [  10]  requires.txt
            │   ├── [4.0K]  scripts
            │   │   ├── [ 479]  cidump.py
            │   │   └── [4.0K]  __pycache__
            │   │       └── [ 669]  cidump.cpython-37.pyc
            │   ├── [ 205]  SOURCES.txt
            │   └── [   9]  top_level.txt
            ├── [ 45K]  certinfo.cpython-37m-x86_64-linux-gnu.so
            └── [ 434]  certinfo.py

9 directories, 30 files
```

* info/index.json

```json
{
  "arch": "x86_64",
  "build": "py37_0",
  "build_number": 0,
  "depends": [
    "libcurl >=7.86.0,<8.0a0",
    "python >=3.7,<3.8.0a0",
    "termcolor"
  ],
  "name": "certinfo",
  "platform": "linux",
  "subdir": "linux-64",
  "timestamp": 1671138678218,
  "version": "0.1.0"
}
```
