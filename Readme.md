### Project Summary

The project involves implementing a section of the C++ containers from the standard template library, aligning with the C++98 standard while reflecting the structure of each standard container.

#### Sequence Containers
- **list**
- **deque**
- **vector** (excluding the `vector<bool>` specialization)

#### Associative Containers
- **map**
- **set**
- **multimap**
- **multiset**

#### Container Adaptors
- **stack**
- **queue**
- **priority_queue**

The implementation must cover the container's iterator system and implement non-member functions and classes (e.g., `swap()`) within the `ft` namespace. Complexity must adhere to the ISO's specifications.

### Testing

For defense, a `main.cpp` test file must be provided in addition to the attached testers. Two binaries should be produced for running identical tests: one with your implemented containers and another with the STL containers. A comparative analysis of outputs and performance/timing is required, acknowledging that your containers might be up to 20 times slower.
