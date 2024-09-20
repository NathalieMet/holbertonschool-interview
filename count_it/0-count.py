#!/usr/bin/python3

import requests


def count_words(subreddit, word_list, after=None, word_count={}):

    headers = {'User-Agent': 'Mozilla/5.0'}

    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    params = {'limit': 100, 'after': after}
    response = requests.get(url, headers=headers, params=params,
                            allow_redirects=False)

    if response.status_code != 200:
        return

    data = response.json().get('data', {})
    posts = data.get('children', [])
    after = data.get('after', None)

    word_list = [word.lower() for word in word_list]

    for post in posts:
        title = post.get('data', {}).get('title', '').lower().split()

        for word in word_list:
            word_count[word] = word_count.get(word, 0) + title.count(word)

    if after:
        return count_words(subreddit, word_list, after, word_count)

    if word_count:
        sorted_word_count = sorted(word_count.items(),
                                   key=lambda x: (-x[1], x[0]))
        for word, count in sorted_word_count:
            if count > 0:
                print(f"{word}: {count}")
