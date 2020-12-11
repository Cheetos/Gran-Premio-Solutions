def main():
    n, mul = [int(num) for num in input().split()]
    performance = [int(num) for num in input().split()]

    # For each performance, store an array with the position in the table
    # of all employees with that performance. e. a.
    # Input:
    # 8 1
    # 1 2 3 2 1 3 2 1
    #
    # we get
    # 1: [0, 4, 7]
    # 2: [1, 3, 6]
    # 3: [2, 5]
    employee_table = {}
    for i, p in enumerate(performance):
        if p in employee_table:
            employee_table[p].append(i)
        else:
            employee_table[p] = [i]

    # All the performance values sorted increasingly
    performance_set = sorted(set(performance))

    # Initially all employees have zero bonus
    bonus = [0 for num in range(n)]

    # Employees with performance 0 will get 0 bonus, for the rest
    # try to give them the less you can to save money for the company.
    # Ideally the rest will have 1 for bonus if possible.
    for p in performance_set:
        if p != 0:  # Employees with performance 0 have 0 bonus
            for i in employee_table[p]:
                # Get the position of the employee to the left and right
                a = (i - 1) if i > 0 else n - 1
                b = (i + 1) if i < n - 1 else 0

                # Initially try to give 1 as bonus
                bonus[i] = 1

                # If a neighbor has worst performance but a larger bonus, then give 1 unit
                # more than the neighbor
                if performance[a] < performance[i] and bonus[a] >= bonus[i]:
                    bonus[i] = bonus[a] + 1
                if performance[b] < performance[i] and bonus[b] >= bonus[i]:
                    bonus[i] = bonus[b] + 1

    for i in range(n):
        bonus[i] *= mul

    print(*bonus[0:n])


if __name__ == '__main__':
    main()
