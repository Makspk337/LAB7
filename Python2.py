def diff_ways_to_compute(expression):
    results = []

    for i in range(len(expression)):
        char = expression[i]
        if char in "+-*":
            left = expression[:i]
            right = expression[i+1:]

            left_results = diff_ways_to_compute(left)
            right_results = diff_ways_to_compute(right)

            for l in left_results:
                for r in right_results:
                    if char == '+':
                        results.append(l + r)
                    elif char == '-':
                        results.append(l - r)
                    elif char == '*':
                        results.append(l * r)
    if not results:
        results.append(int(expression))
    return results

results = diff_ways_to_compute(input("Введите выражение: "))

print("Все возможные результаты:", results)
