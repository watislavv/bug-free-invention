import subprocess
import os

def run_test(executable, input_data):
    process = subprocess.Popen(executable, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout, stderr = process.communicate(input=input_data.encode())
    return stdout.decode(), stderr.decode()

def check_output(expected_output, actual_output):
    return expected_output.strip() == actual_output.strip()

if __name__ == "__main__":
    input_data = "push_front 10\npush_back 20\ncount\nis_empty\n"
    expected_output = "Count: 2\nIs empty: false\n"
    
    # Создание исполняемого файла
    os.system("gcc -o student_code main.c list.c student_code.c")
    
    output, error = run_test("./student_code", input_data)
    
    if check_output(expected_output, output):
        print("Test passed!")
    else:
        print("Test failed.")

