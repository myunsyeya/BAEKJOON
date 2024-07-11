def suffix_array(s):
    n = len(s)
    suffix_arr = sorted(range(n), key=lambda i: s[i:])
    return suffix_arr

def longest_common_prefix(s, suffix_arr):
    n = len(s)
    rank = [0] * n
    lcp = [0] * n
    for i, suffix in enumerate(suffix_arr):
        rank[suffix] = i

    h = 0
    for i in range(n):
        if rank[i] > 0:
            j = suffix_arr[rank[i] - 1]
            while i + h < n and j + h < n and s[i + h] == s[j + h]:
                h += 1
            lcp[rank[i]] = h
            if h > 0:
                h -= 1
    return lcp

def count_substrings(s):
    n = len(s)
    sa = suffix_array(s)
    lcp = longest_common_prefix(s, sa)
    
    substring_count = 0
    for i in range(n):
        start = sa[i]
        length = n - start
        if i > 0:
            length -= lcp[i]
        substring_count += length
    
    return substring_count

# Example usage:
if __name__ == "__main__":
    string = input().strip()
    result = count_substrings(string)
    print(result)
