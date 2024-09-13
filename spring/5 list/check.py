import subprocess
import sys

def run_student_code(student_code_file):
    # Компилируем код студента
    compile_cmd = f"gcc -o student_code {student_code_file} reference_solution.c"
    subprocess.run(compile_cmd, shell=True, check=True)

    # Генерируем входные данные
    input_data = "push_back 5\npush_back 10\npush_front 1\ncount\nprint\n"
    
    # Запускаем скомпилированный код студента и передаем ему входные данные
    result = subprocess.run("./student_code", input=input_data, text=True, capture_output=True)

    # Проверяем вывод
    expected_output = "Список: 1 5 10 \nКоличество элементов: 3\n"
    
    if result.stdout == expected_output:
        print("Тест пройден успешно!")
    else:
        print("Тест не пройден.")
        print("Ожидалось:")
        print(expected_output)
        print("Получено:")
        print(result.stdout)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Использование: python check.py <файл_студента.c>")
        sys.exit(1)

    student_code_file = sys.argv[1]
    run_student_code(student_code_file)
