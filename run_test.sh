result_array=(0 1 0 1 1
              1 1 1 1 1
              1 1 0 1 0
              1 1 1 0 1
              1 1 1 1 1
              1 1)

echo "Error log:" > res/log.txt
echo "Program out:" > res/pass_out.txt

all_files=27
passed_files=0
index=0
dir=`ls test/samples_lex_and_syntax/*.cact`
for test_file in $dir
do
    echo "Test $test_file"
    ./build/compiler $test_file >> res/pass_out.txt
    command_stat=$?
    if [[ $command_stat == 0 && ${result_array[$index]} == 0 ]] \
    || [[ $command_stat != 0 && ${result_array[$index]} == 1 ]];
    then
        let "passed_files++"
    else
        echo "$index: should be: ${result_array[$index]}, is $command_stat" >> res/log.txt
    fi
    let "index++"
done

echo "compiler${number}: $passed_files / $all_files"


result_array=(0 0 0 1 1
              1 0 1 0 0
              1 0 1 1 1
              1 1 1 1 1
              1 1 0 0 0
              1 1 1 1 0
              1 1 1 0 1
              1 0 1 1 1
              1 1 1 1 1
              0 1 0)

all_files=48
passed_files=0
index=0
dir=`ls test/samples_semantic/*.cact`
for test_file in $dir
do
    echo "Test $test_file"
    ./build/compiler $test_file >> res/pass_out.txt
    command_stat=$?
    if [[ $command_stat == 0 && ${result_array[$index]} == 0 ]] \
    || [[ $command_stat != 0 && ${result_array[$index]} == 1 ]];
    then
        let "passed_files++"
    else
        echo "$index: should be: ${result_array[$index]}, is $command_stat" >> res/log.txt
    fi
    let "index++"
done

echo "compiler${number}: $passed_files / $all_files"