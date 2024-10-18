def canAchieveMinPower(stations, r, k, minPower):
    n = len(stations)
    power = stations.copy()
    usedStations = 0
    window_sum = sum(stations[:r + 1])
    power[0] = window_sum

    for i in range(1, n):
        if i + r < n:
            window_sum += stations[i + r]
        if i - r - 1 >= 0:
            window_sum -= stations[i - r - 1]
        power[i] = window_sum

    needed_power = [minPower - p for p in power]
    for i in range(n):
        if needed_power[i] > 0:
            if usedStations + needed_power[i] > k:
                return False
            usedStations += needed_power[i]

    return True

def maxMinPower(stations, r, k):
    low, high = 0, 10**12
    result = 0

    while low <= high:
        mid = low + (high - low) // 2
        if canAchieveMinPower(stations, r, k, mid):
            result = mid
            low = mid + 1
        else:
            high = mid - 1

    return result

# Test case
stations = [1, 2, 4, 5, 0]
r = 1
k = 2
result = maxMinPower(stations, r, k)  # Output: 5
print("MaxMinPower:",result)
