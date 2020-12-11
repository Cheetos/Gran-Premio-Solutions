###########################################################################
# if there n lines from the top vertex to the base of the larger triangle,
# then there are C(n + 2, 2) possible triangles. Since there are n + 2
# possible vertices in the base, and we need to take 2 to form a triangle.
# There are k + 1 vertical sections, so the same apply for each section.
# Then the result is C(n+2, 2) * (k + 1)
#
# C(n + 2, 2) = (n + 2)! / (2! * n!)
# C(n + 2, 2) = ((n + 2) * (n + 1) * n!) / (2! * n!)
# C(n + 2, 2) = ((n + 2) * (n + 1)) / 2
#
# Then the result is given by
# ((n + 2) * (n + 1) * (k + 1)) / 2
############################################################################

def main():
    m = 1000000007
    t = int(input())
    while t > 0:

        n, k = [int(num) for num in input().split()]
        res = ((n + 2) * (n + 1) * (k + 1)) // 2
        print("{}".format(res % m))
        t -= 1

if __name__ == '__main__':
    main()
