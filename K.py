#################################################################################
# For this problem we need to compute combinations, that is the main objective.
# We have A, B, and C students in groups A, B, C respectively. And we need to
# c students from C group, and we need to take K students in total.  For the
# example given we have A = B = C = 3, and with K = 7 and c = 2. Said so, for
# group C we there are Comb(2,3) = 3! / (2! * 1!), ways. So we only need to
# find for the remaining 5 students how to split it between students
# from groups A and B. There are only two ways, (a = 2, b = 3),
# and (a = 3, b = 2). So the number of ways to take students is:
#
# Comb(2,3) * Comb(3,3) * Comb(2,3) + Comb(3,3) * Comb(2,3) * Comb(2,3) =
# (3 * 1 * 3) + (1 * 3 * 3) = 9 + 9 = 18.
#
# The problem is that Comb(n,k) can be quite large, but we are asked to print
# the result modulo 1000000007, which means that we must keep our operations
# with sums and products in order to apply the principles of modular arithmetic.
# Then we cannot use the formula Comb(n,k) = n! / (k! * (n - k)!), since it
# contains divisions. One option then is to pre-compute the Pascal's triangle,
# but this implies a huge matrix of 10^5 x 10^5, so we need another approach.
# Since 1000000007 is a prime number we can use the Fermat's Little Theorem to
# compute this. Here is a detailed explanation:
# https://codeforces.com/blog/entry/78873
# Given that we can pre-compute the factorials modulo 1000000007, and the inverse
# multiplicative of the factorials modulo 1000000007, and then just apply the
# formula:
#
# Comb(n, k) = (n! mod p) * (inv(k!) mod p) * (inv((n - k)!) mod p),
#
# where p is a prime number, for this case 1000000007.
#
# We can use binary exponentiation to calculate the inverse multiplicative.
#################################################################################

def binary_pow(a, b, m):
    p = 1
    while b > 0:
        if b % 2 == 1:
            p = (p * a) % m
        a = (a ** 2) % m
        b = b // 2

    return p


def comb(n, k, p, fact, fact_inv):
    return (fact[n] * fact_inv[k] * fact_inv[n - k]) % p


def main():
    p = 1000000007
    f = [1, 1]
    fi = [1, 1]
    for i in range(2, 100001):
        fact = (i * f[i - 1]) % p
        f.append(fact)
        fi.append(binary_pow(fact, p - 2, p))

    t = int(input())
    while t > 0:
        a, b, c, n, k = [int(num) for num in input().split()]

        comb_c = comb(c, k, p, f, fi)
        n -= k
        res = 0
        for i in range(1, a + 1):
            if 0 < n - i <= b:
                comb_a = comb(a, i, p, f, fi)
                comb_b = comb(b, n - i, p, f, fi)
                res += (comb_a * comb_b * comb_c) % p

        print(res)
        t -= 1


if __name__ == '__main__':
    main()
