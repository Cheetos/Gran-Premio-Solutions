# This is a memoization problem along with graph traversal
#
# When we are in section i of the river, we can only visit ONE
# section after that, it should be a section between i + ai, and if i + bi.
# Since we don't know which one, we visit all of them, but after we finish
# exploring a section we store the maximum gold we can extract from there,
# in case we want to visit this section again, we can just retrieve the
# amount of gold without actually visiting that section, this technique
# is called memoization. We will only visit each section once.

def DFS(i, n, v, gold, graph):
    max_gold = 0 # We haven't extracted any gold yet

    # Attempt to visit other sections from section i
    for j in range(i + graph[i]["a"], i + graph[i]["b"] + 1):
        # Visit only sections 0 to n-1
        if j >= n:
            break
        if v[j] == -1:
            # We haven't visit section j, visit it and get the the maximum
            # gold we can extract from there
            max_gold = max(max_gold, DFS(j, n, v, gold, graph))
        else:
            # If we have visited section j before, NOT visit again, just retrieve
            # the maximum gold from that section
            max_gold = max(max_gold, v[j])

    # The maximum gold we can extract from current section i is gold[i] + max_gold
    v[i] = gold[i] + max_gold
    return v[i]

def main():
    n = int(input())
    v = [-1 for num in range(n)] # Haven't visited any section
    gold = [0 for num in range(n)]
    graph = [{} for num in range(n)]

    # Read the input
    for i in range(n):
        gold[i], graph[i]["a"], graph[i]["b"] = [int(num) for num in input().split()]

    k = 0
    for i in range(n):
        if v[i] == -1: # Have we visited section i?
            # if not, then visit setion i and calculate the maximum amount of gold we
            # can extract from there (keep the maximum)
            k = max(k, DFS(i, n, v, gold, graph))

    print(k)

if __name__ == '__main__':
    main()
