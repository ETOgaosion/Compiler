dir=`ls test/samples_codegen/*.cact`
for test_file in $dir
do
    echo "!!!!!!!!!!!!!!!!!!!"
    echo "Compile $test_file"
    ./build/compiler $test_file
done
dir=`ls test/samples_codegen/*.S`
for test_file in $dir
do
    echo "Generate ${test_file:0:-2}"
    riscv64-unknown-elf-gcc -g $test_file -L./ -lcact -static -o ${test_file:0:-2}
    riscv64-unknown-elf-objdump -S ${test_file:0:-2} > "${test_file:0:-2}.obj"
done
dir=`ls test/samples_codegen/*.S`
for test_file in $dir
do
    echo "Test ${test_file:0:-2}"
    spike pk ${test_file:0:-2} > "${test_file:0:-2}.out"
    echo "!!!!!!!!!!!!!!!!!!!"
done