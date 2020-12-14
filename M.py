###########################################################################################
# For this problem I gor from left to right and if the ith element is smaller or equal than
# (i+1)th element, then I remove the ith element if the amount of digits to remove for that
# element is greater than zero, after that I decrement by 1 the amount of digits to remove
# for that element.
#
# I continue doing that until is not possible, if there are elements I still need to remove,
# then I go from right to left and remove everything that is still missing.
###########################################################################################

def main():
    n = list(input())
    d = [int(num) for num in input().split()]
    c = 1
    while c > 0:
        c = 0
        i = 0
        while i < len(n) - 1:
            a = int(n[i])
            b = int(n[i + 1])
            if b >= a and d[a - 1] > 0:
                n.pop(i)
                d[a - 1] -= 1
                c += 1
            else:
                i += 1

    # Remove everything missing from right to left
    for i in range(len(n) - 1, -1, -1):
        a = int(n[i])
        if d[a - 1] > 0:
            n.pop(i)
            d[a - 1] -= 1

    n = "".join(n)
    print(n)


if __name__ == '__main__':
    main()
