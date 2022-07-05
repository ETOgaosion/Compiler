./build.sh
# ./run_test.sh > res/code_gen_res.txt
gdb build/compiler test/manual/tests.cact
riscv64-unknown-elf-gcc -g test/manual/tests.S -L./ -lcact -o test/manual/tests
riscv64-unknown-elf-objdump -S test/manual/tests > test/manual/tests.obj
spike pk test/manual/tests
