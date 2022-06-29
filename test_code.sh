./build.sh
./build/compiler test/manual/tests.cact
riscv64-unknown-elf-gcc test/manual/tests.S -L./ -lcact -static -o test/manual/tests
spike pk test/manual/tests