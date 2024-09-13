import subprocess

def run_test(executable):
    commands = [
        "push_front 10",
        "push_back 20",
        "push_front 5",
        "count",
        "get_head",
        "get_tail",
        "is_empty",
        "sort",
        "exit"
    ]
    
    input_data = "\n".join(commands)
    
    process = subprocess.Popen(executable, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    
    stdout, stderr = process.communicate(input=input_data.encode())
    
    print(stdout.decode())
    
if __name__ == "__main__":
    run_test("./main_cyclic")  # Путь к исполняемому файлу для циклического списка.