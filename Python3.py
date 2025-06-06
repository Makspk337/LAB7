def can_fill_rope(items, used, index, current_sum, total_length):
    if index == len(items):
        return current_sum == total_length

    for i in range(len(items)):
        if not used[i]:
            used[i] = True
            if can_fill_rope(items, used, index + 1, current_sum + items[i], total_length):
                return True
            used[i] = False

    return False

try:
    rope_length = int(input("Введите длину веревки: "))
    n = int(input("Введите количество оставшихся предметов: "))
except ValueError:
    print("Ошибка ввода! Пожалуйста, введите целые числа.")
    exit()

items = []
print(f"Введите длины {n} оставшихся предметов: ")
for _ in range(n):
    length = int(input())
    if length < 0:
        print("Длина не может быть отрицательной!")
        exit()
    items.append(length)

used = [False] * n

if can_fill_rope(items, used, 0, 0, rope_length):
    print("Можно перевесить предметы так, чтобы занять всю веревку.")
else:
    print("Нельзя занять всю веревку оставшимися предметами.")
