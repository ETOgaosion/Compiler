dir=`ls test/manual/*.cact`
for test_file in $dir
do
    echo "Test $test_file"
    ./build/compiler $test_file
done
dir=`ls test/manual/*.S`
for test_file in $dir
do
    echo "Compile $test_file"
    riscv64-unknown-elf-gcc -g $test_file -L./ -lcact -static -o ${test_file:0:-2}
    riscv64-unknown-elf-objdump -S ${test_file:0:-2} > "${test_file:0:-2}.obj"
    spike pk ${test_file:0:-2} > "${test_file:0:-2}.out"
done