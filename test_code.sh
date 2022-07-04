./build.sh
# ./run_test.sh > res/code_gen_res.txt
gdb build/compiler test/samples_codegen/16_n_factorial_recursion.cact
riscv64-unknown-elf-gcc -g test/samples_codegen/16_n_factorial_recursion.S -L./ -lcact -o test/samples_codegen/16_n_factorial_recursion
riscv64-unknown-elf-objdump -S test/samples_codegen/16_n_factorial_recursion > test/samples_codegen/16_n_factorial_recursion.obj
spike pk test/samples_codegen/16_n_factorial_recursion