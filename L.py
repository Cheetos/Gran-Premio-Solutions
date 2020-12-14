def main():
    n = int(input())
    words = input().split()
    generators = [words[0]]

    for word in words[1:]:
        for gen in generators:
            if (word + word).find(gen) != -1:
                break
        else:
            generators.append(word)
    print(len(generators))


if __name__ == '__main__':
    main()
