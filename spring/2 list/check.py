import subprocess
import os

def compile_code(student_code):
    with open("main.c", "a") as f:
        f.write(student_code)
    
    result = subprocess.run(["gcc", "main.c", "-o", "student_program"], capture_output=True)
    if result.returncode != 0:
        print("Compilation failed")
        print(result.stderr.decode())
        return False
    return True

def run_test(input_data):
    result = subprocess.run(["./student_program"], input=input_data.encode(), capture_output=True)
    return result.stdout.decode()

def main():
    student_code = """..."""  # Считывание кода студента из файла или другого источника
    if compile_code(student_code):
        input_data = (
            "push_front 10\n"
            "push_back 20\n"
            "count\n"
            "get_head\n"
            "get_tail\n"
            "is_empty\n"
            "pop\n"
            "count\n"
        )  # Пример входных данных
        
        output = run_test(input_data)
        print(output)
        
        # Проверка корректности вывода...
        
if __name__ == "__main__":
    main()
