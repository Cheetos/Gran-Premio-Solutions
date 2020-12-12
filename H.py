#########################################################################
# Most part of this problem is the coin change problem, with a finite
# number of coins (traverse array backwards). In this case instead of
# coins we problems with some value in points, and we want to know the
# minimum amount of problems necessary to reach certain grade. Is the
# same problem as finding the minimum amount of coins to reach certain
# value.
#
# The number of combinations can be obtained solving the original coin
# change problem. In how many ways can we get certain grade with the
# given problems.
#
# To actually print the combinations I used a backtracking solution, and
# used the minimum amount of problems to early stopping the recursion.
#########################################################################

n = 0
lower_bound = 0
min_problems = 0
total_points = 0
problem_points = []
comb = []


def get_combinations(pos, k, score):
    # Early Stopping. Have reached the minimum amount of problems necessary to pass?
    if pos == min_problems:
        # Check if the score is at least the grade we want to have
        if score >= lower_bound:
            print("{}".format(int((score / total_points) * 100)), end=" ")
            print(*comb)
        return
    elif pos > min_problems:
        # We exceeded the minimum number of problems necessary to pass.
        return

    for i in range(k, n):
        # Solve problem i and move to the next problem
        comb[pos] = i + 1
        get_combinations(pos + 1, i + 1, score + problem_points[i])


def main():
    global problem_points, n, lower_bound, min_problems, comb, total_points

    n, grade = [int(num) for num in input().split()]
    problem_points = [int(num) for num in input().split()]

    inf = n + 1
    total_points = sum(problem_points)

    # The minimum points we need to achieve grade
    lower_bound = (grade * total_points)
    lower_bound = lower_bound // 100 if lower_bound % 100 == 0 else lower_bound // 100 + 1

    # Arrays necessary for the coin-change problem
    x = [inf for num in range(total_points + 1)]
    y = [0 for num in range(total_points + 1)]
    x[0] = 0
    y[0] = 1

    for points in problem_points:
        for i in range(total_points, points - 1, -1):
            y[i] += y[i - points]  # Number of ways to get grade i
            x[i] = min(x[i], x[i - points] + 1)  # The minimum number of problems to get grade i

    # Find the minimum number of problems necessary to pass
    min_problems = min(x[lower_bound:total_points + 1])

    # Find the number of combinations that would allow to achieve at least the desired grade
    combinations = 0
    for i in range(lower_bound, total_points + 1):
        if x[i] == min_problems:
            combinations += y[i]

    # Get the combinations
    comb = [0 for num in range(min_problems)]
    print("{} {}".format(min_problems, combinations))
    get_combinations(0, 0, 0)


if __name__ == '__main__':
    main()
