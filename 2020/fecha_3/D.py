def main():
    t = int(input())
    while t > 0:
        s, k = [token for token in input().split()]
        k = int(k)
        total_len = 0
        p = 0
        res = ""

        # Iterate trough the string
        for c in s:
            # If c is a letter then concatenate p times the letter c
            # The length of the result is increased by p
            # Set p = 0 ready for the next letter
            if c.isalpha():
                if p == 0:
                    res += c
                    total_len += 1
                else:
                    res += (c * p)
                    total_len += p

                if total_len > k:
                    print("unfeasible")
                    break
                p = 0
            else:
                # If c is a number, just multiply p by 10 and add c
                # In case p is larger than, we can stop, no need to keep adding.
                p = p * 10 + int(c)
                if p > k:
                    print("unfeasible")
                    break
        else:
            print(res)

        t -= 1

if __name__ == '__main__':
    main()
