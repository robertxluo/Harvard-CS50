from nltk.tokenize import sent_tokenize


def lines(a, b):
    """Return lines in both a and b"""

    a_lines = a.split('\n')
    b_lines = b.split('\n')
    both = set(a_lines).intersection(b_lines)
    return both


def sentences(a, b):
    """Return sentences in both a and b"""

    a_sentences = sent_tokenize(a)
    b_sentences = sent_tokenize(b)
    both = set(a_sentences).intersection(b_sentences)
    return both


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    a_substrings = substringTokenize(a, n)
    b_substrings = substringTokenize(b, n)
    both = set(a_substrings).intersection(b_substrings)
    return both


def substringTokenize(x, n):
    """Return the substrings of a given string based on length provided"""

    len_str = len(x)
    result = set()
    count = 0
    for i in range(len(x) - n + 1):
        result.add(x[i:i + n])
    return result