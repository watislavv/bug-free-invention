# check.py
import subprocess
import os

def compile_and_run(student_code_path):
    # Компилируем код студента
    compile_command = f"gcc -o student_program main.c {student_code_path} sparse_list.c"
    
    # Запускаем компиляцию
    compile_result = subprocess.run(compile_command, shell=True, capture_output=True)
    
    if compile_result.returncode != 0:
        print("Ошибка компиляции:")
        print(compile_result.stderr.decode())
        return None

    # Генерация входных данных для тестирования
    input_data = "push_front 30\npush_back 40\ncount\nget_head\nget_tail\n"
    
    # Запуск программы студента с входными данными
    run_result = subprocess.run("./student_program", input=input_data.encode(), stdout=subprocess.PIPE)
    
    # Возвращаем результат выполнения
    return run_result.stdout.decode()

if __name__ == "__main__":
    student_code_path = "student_code.c"  # Путь к файлу студента
    output = compile_and_run(student_code_path)
    
    if output:
        print("Вывод программы студента:")
        print(output)
