# Bloom Filter in C++

A **Bloom Filter** is a space efficient probabilistic data structure used to test whether an element is a member of a set. It is widely used in databases, caching, and large scale systems where speed and memory efficiency are critical.
It is even used by Instagram to check whether a specific username is taken or not.
---

## Outputs given by Bloom filter
- **Definite Negatives**: If the filter says an element is *not present*, it is guaranteed to be absent.
- **Possible Positives**: If the filter says an element *may be present*, there is a chance of a **false positive**.
- This trade off makes Bloom Filters extremely fast and memory friendly compared to traditional search methods like Linear and Binary search.

---

## Time and Space complexity
- **Insertion**: `O(k)` where `k` = number of hash functions.
- **Query**: `O(k)` (constant time for practical purposes).
- **Space**: Only a few bits per element (≈10 bits for 1% false positive rate).
- Faster than:
  - Linear Search → `O(n)`
  - Binary Search → `O(log n)`

---

## Use Cases
- **Databases**: Avoid unnecessary disk lookups
- **Web Crawlers**: Prevent revisiting the same URL
- **Networking**: Efficient packet routing and filtering.
- **Authentication Systems**: Quickly check if a username/email *may* already exist.

---

## Features of This Implementation
- Written in **C++** with STL support.
- Configurable **bit array size** and **number of hash functions**.
- Demonstrates insertion and membership queries.

---
