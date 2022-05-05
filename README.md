# Compiler

Antlr and CACT compiler demo.

Platform support MacOS and Linux, but for specific installation of tools, please STFW.

## Compile

```shell
export DYLD_LIBRARY_PATH=/Volumes/study/code/C++/vscode/compiler/compiler/dependencies/mac/antlr4-runtime/lib:$DYLD_LIBRARY_PATH

mkdir build
cd build
cmake ..
make
```

## Run demo

```shell
# under build/
./compiler ../samples/00_main.cact
```

## Run test

```shell
# under project root
mkdir res
./run_test.sh
```

check error in `res/log.txt` and view program output in `res/pass_out.txt`.
