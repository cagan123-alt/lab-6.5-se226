# Question 1
def find_common_elements(list1, list2):
    return list(set(list1) & set(list2))
# Question 2
def find_palindromes(strings):
    return [s for s in strings if s == s[::-1]]
# Question 3
def sieve_of_eratosthenes(numbers):
    primes = []
    is_prime = [True] * (max(numbers) + 1)
    is_prime[0] = is_prime[1] = False
    for i in range(2, len(is_prime)):
        if is_prime[i]:
            for j in range(i * i, len(is_prime), i):
                is_prime[j] = False
    for num in numbers:
        if is_prime[num]:
            primes.append(num)
    return primes
# Question 4
def anagrams(word, word_list):
    word_chars = sorted(word.lower().replace(" ", ""))
    anagrams_list = []
    for w in word_list:
        if sorted(w.lower().replace(" ", "")) == word_chars:
            anagrams_list.append(w)
    return anagrams_list



if __name__ =="__main__":
    # Question 1
    list1 = [1, 2, 3, 4, 5]
    list2 = [2, 4, 6, 8, 10]
    common_elements = find_common_elements(list1, list2)
    print(common_elements)
    # Question 2
    strings = ["racecar", "hello", "madam", "python", "radar"]
    palindromes = find_palindromes(strings)
    print(palindromes)
    # Question 3
    numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    primes = sieve_of_eratosthenes(numbers)
    print(primes)
    # Question 4
    word = "listen"
    word_list = ["enlists", "google", "inlets", "banana"]
    anagrams_list = anagrams(word, word_list)
    print(anagrams_list)