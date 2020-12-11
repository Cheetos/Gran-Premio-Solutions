###########################################################################
# Here I used a simple backtracking, but not sure if it will run on time,
# for each node in the recursion tree, there are 3 possible branches, that
# corresponds to the actions that a member can take. If we go deeper into
# the tree, the nodes are less and less, since there will be less
# problems to solve or less members in the team.
#
# We are marking which problems are still available to solve, and also
# which members can still participate in the contest.
#
# After that is just checking the three possible scenarios for a team member.
# I thought in a possibility of memoization, using bitmask for the team
# members, since there are only 10, but we also need to keep track of
# which problems have been made, so I discarded the idea, and went for the
# backtracking, and I added some checking to early stopping the recursion.
############################################################################

nMembers = 0
nProblems = 0
max_score = 0
member_energy = []
problem_difficulty = []
problem_score = []
problem_available = []


def member_action(member_id,
                  problem_id,
                  current_score,
                  remaining_score):
    global nMembers, nProblems, member_energy
    global problem_difficulty, problem_score, problem_available, max_score

    # ====== 1. Solve the problem if possible ======
    if problem_difficulty[problem_id] <= member_energy[member_id]:
        # Mark the problem as unavailable and subtract the energy to the member
        problem_available[problem_id] = 1
        member_energy[member_id] -= problem_difficulty[problem_id]

        # Go to the next problem and keep the score
        handle_problem(-1,
                       -1,
                       current_score + problem_score[problem_id],
                       remaining_score - problem_score[problem_id])

        # After the recursion brings us back, uncheck the problem and restore the energy
        # to the member, so we can use for other problems.
        problem_available[problem_id] = 0
        member_energy[member_id] += problem_difficulty[problem_id]

    # ===== 2 Stop solving problems ======
    # Set the energy of the member to 0, won't participate anymore
    temp = member_energy[member_id]
    member_energy[member_id] = 0

    # The next member will try to solve this problem
    handle_problem(-1,
                   problem_id,
                   current_score,
                   remaining_score)

    # After recursion brings us back, restore the energy to the member
    # to use it for other problems
    member_energy[member_id] = temp

    # ===== 3 Not solve the problem and go to the next ======
    # Mark the problem as unavailable
    problem_available[problem_id] = 1

    # The same member will go to the next problem
    handle_problem(member_id,
                   -1,
                   current_score,
                   remaining_score - problem_score[problem_id])

    # After recursion brings us back, mark problem as available to be solved
    # for other team members
    problem_available[problem_id] = 0


def handle_problem(current_member,
                   current_problem,
                   current_score,
                   remaining_score):
    global nMembers, nProblems, member_energy
    global problem_difficulty, problem_score, problem_available, max_score

    # If it is impossible to have a larger score, stop looking
    if current_score + remaining_score <= max_score:
        return

    # If there are no more problems to solve or there more team members,
    # check the score and keep the maximum
    if sum(problem_available) == nProblems or sum(member_energy) == 0:
        max_score = max(max_score, current_score)
        return

    if current_member == -1:
        for i in range(nMembers):
            # Find for any member with energy
            if member_energy[i] > 0:
                if current_problem == -1:
                    for j in range(nProblems):
                        # Find for any available problem
                        if problem_available[j] == 0:
                            member_action(i, j, current_score, remaining_score)
                else:
                    # Member i has current_problem in front of him
                    member_action(i, current_problem, current_score, remaining_score)
    else:
        if current_problem == -1:
            for j in range(nProblems):
                # Find for any available problem to be solved by current_member
                if problem_available[j] == 0:
                    # Member current_member has problem j in front of him
                    member_action(current_member, j, current_score, remaining_score)
        else:
            # Member current_member has problem current_problem in front of him
            member_action(current_member, current_problem, current_score, remaining_score)


def main():
    global nMembers, nProblems, member_energy
    global problem_difficulty, problem_score, problem_available, max_score

    nMembers, nProblems = [int(num) for num in input().split()]
    member_energy = [int(num) for num in input().split()]
    problem_difficulty = [int(num) for num in input().split()]
    problem_score = [int(num) for num in input().split()]
    problem_available = [0 for num in range(nProblems)]

    # Initially we have no score and the remaining points is the sum of all problem points
    handle_problem(-1, -1, 0, sum(problem_score))

    print(max_score)


if __name__ == '__main__':
    main()
