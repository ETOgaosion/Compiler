./build.sh
# ./run_test.sh > res/code_gen_res.txt
gdb build/compiler
arm-linux-gnueabihf-gcc -static -g test/manual/tests.S -L./ -lsysy -o test/manual/tests
arm-linux-gnueabihf-objdump -S test/manual/tests > test/manual/tests.obj
file test/manual/tests
./test/manual/tests