dir=`ls test/functional/*.sy`
for test_file in $dir
do
    echo "!!!!!!!!!!!!!!!!!!!"
    echo "Compile $test_file"
    ./build/compiler $test_file
done
dir=`ls test/functional/*.S`
for test_file in $dir
do
    echo "Generate ${test_file:0:-2}"
    arm-linux-gnueabihf-gcc -g $test_file -L./ -lcact -static -o ${test_file:0:-2}
    arm-linux-gnueabihf-objdump -S ${test_file:0:-2} > "${test_file:0:-2}.obj"
done
dir=`ls test/functional/*.S`
for test_file in $dir
do
    echo "======================="
    echo "Testing ${test_file:0:-2}"
    file ${test_file:0:-2}
    FILE="${test_file:0:-2}.in"
    if [ -f "$FILE" ]; then
        ./${test_file:0:-2} > "${test_file:0:-2}.output"
    else
        ./${test_file:0:-2} > "${test_file:0:-2}.output"
    fi
    echo "======================="
    echo "!!!!!!!!!!!!!!!!!!!"
done