dir=`ls test/samples_codegen/*.cact`
for test_file in $dir
do
    echo "Test $test_file"
    ./build/compiler $test_file
done
dir=`ls test/samples_codegen/*.S`
for test_file in $dir
do
    echo "Compile $test_file"
    riscv64-unknown-elf-gcc $test_file -L./ -lcact -static -o ${test_file#*.S}
    spike pk ${test_file#*.S} > "${test_file#*.S}.out"
done