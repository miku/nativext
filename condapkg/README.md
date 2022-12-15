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
