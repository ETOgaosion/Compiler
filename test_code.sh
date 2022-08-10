./build.sh
# ./run_test.sh > res/code_gen_res.txt
./build/compiler -S -o test/manual/tests.s test/manual/tests.sy
arm-linux-gnueabihf-gcc -static -g test/manual/tests.s -L./ -lsysy -o test/manual/tests
arm-linux-gnueabihf-objdump -S test/manual/tests > test/manual/tests.obj
file test/manual/tests
./test/manual/tests