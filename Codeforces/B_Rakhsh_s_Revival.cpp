import math

def solve():
    t = int(input())  # Number of test cases
    for _ in range(t):
        n, m, k = map(int, input().split())  # Read n, m, k for the test case
        s = input().strip()  # The binary string

        # Count the number of operations required
        operations = 0
        i = 0
        while i <= n - m:
            # Find the next block of m consecutive '0's
            if s[i:i+m] == '0' * m:
                # We found a sequence of 'm' consecutive 0's
                operations += 1
                i += k  # Move forward by k to avoid fixing the same segment multiple times
            else:
                i += 1  # Move to the next index

        print(operations)

# Calling the solve function to process all test cases
solve()
