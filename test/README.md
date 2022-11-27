# Unittests

Put unittest codes in this directory and confrom to naming convention listed below.

## Naming Convention

file name: `xx_test.cpp`.

Write header only helper class instead of separated sources if external helpers is needed.

## Run tests

```shell
# Run all gtests all at once
mkdir build && cd build
cmake ..
make test

# Run specific gtest
make xx_unittest
${BuildDir}/bin/xx_unitest
```