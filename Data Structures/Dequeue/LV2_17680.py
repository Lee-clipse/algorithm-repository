def solution(cacheSize, cities):
    import collections
    cache = collections.deque(maxlen = cacheSize)
    time = 0
    for city in cities:
        city = city.lower()
        if city in cache:
            cache.remove(city)
            cache.append(city)
            time += 1
        else:
            cache.append(city)
            time += 5
    return time