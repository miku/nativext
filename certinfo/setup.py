import setuptools  # required, e.g. from bdist_wheel
from distutils.core import setup, Extension

certinfo = Extension(
    "certinfo",
    define_macros=[],
    include_dirs=[],
    libraries=["curl"],
    library_dirs=[],
    sources=["certinfo_module.c"],
)

setup(
    name="certinfo",
    version="1.0",
    description="Wrapper around certinfo",
    ext_modules=[certinfo],
    scripts=["cidump.py"],
    install_requires=[
        "termcolor",
    ],
)
