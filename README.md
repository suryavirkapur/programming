# LeetCode / DSA Solutions — @suryavirkapur

A curated collection of C++ solutions to classic data-structures & algorithms
problems (LeetCode-style). Each solution lives under
`Data Structures & Algorithms/<problem>/` as a standalone `submission-*.cpp`
file.

## Project Layout

```
.
├── CMakeLists.txt                     # top-level CMake build
├── include/
│   └── dsa/
│       ├── dsa.hpp                    # shared types & std re-exports
│       └── test_harness.hpp           # lightweight test runner
├── scripts/
│   └── run-all-tests.sh              # build + run every test suite
├── Data Structures & Algorithms/
│   ├── anagram-groups/
│   │   └── submission-0.cpp
│   ├── climbing-stairs/
│   │   └── submission-1.cpp
│   └── … (75+ problems)
└── README.md
```

## Building

Requirements:
- **CMake** ≥ 3.14
- **C++17** compiler (GCC ≥ 8, Clang ≥ 7, or MSVC 2019+)

```bash
# Configure
cmake -S . -B build

# Build everything
cmake --build build --target all_dsa -j$(nproc)

# Build a single target (e.g. anagram-groups)
cmake --build build --target dsa_Data_Structures___Algorithms_anagram_groups_submission_0
```

## Running Tests

The easiest way to run **every** test suite:

```bash
./scripts/run-all-tests.sh
```

To clean the build directory first:

```bash
./scripts/run-all-tests.sh --clean
```

To run a single suite manually:

```bash
cmake --build build --target dsa_Data_Structures___Algorithms_climbing_stairs_submission_1
./build/dsa_Data_Structures___Algorithms_climbing_stairs_submission_1
```

**Note:** All 84 submission files compile and link successfully.
Refactored suites run self-checking tests; non-refactored suites
return 0 (they include shared headers but retain the original
LeetCode solution classes without explicit test cases).

## Refactored Solutions (namespace `dsa::` + test harness)

The following files have been modernised — they use `namespace dsa`, the
shared headers (`dsa.hpp` / `test_harness.hpp`), and include a `main()`
with self-checking test cases:

| Problem                    | File                                  |
|----------------------------|---------------------------------------|
| Anagram Groups             | `anagram-groups/submission-0.cpp`     |
| Climbing Stairs            | `climbing-stairs/submission-1.cpp`    |
| House Robber               | `house-robber/submission-1.cpp`       |
| Maximum Subarray           | `maximum-subarray/submission-2.cpp`   |
| Buy and Sell Crypto        | `buy-and-sell-crypto/submission-0.cpp`|
| Single Number              | `single-number/submission-0.cpp`      |
| Missing Number             | `missing-number/submission-0.cpp`     |
| Plus One                   | `plus-one/submission-0.cpp`           |
| Number of One Bits         | `number-of-one-bits/submission-0.cpp` |
| Longest Consecutive Seq.   | `longest-consecutive-sequence/submission-0.cpp` |

## Build Status

All 84 targets compile and link cleanly with zero errors or warnings
(CMake ≥ 3.14, C++17, GCC 13). The shared header `include/dsa/dsa.hpp`
provides `TreeNode`, `ListNode`, `Node`, `Interval`, and re-exports
the full C++ standard library so every submission can be compiled
independently.

## Minimal Environment Notes

- Workspace inside MicroVM: `/workspace/repo`
- Bootstrap entrypoint copied by worker: `/opt/seasnoke/project-entrypoint.sh`
- Required entrypoint env: `SEASNOKE_RUNTIME`, `SEASNOKE_CLONE_BRANCH`,
  `SEASNOKE_CLONE_URL`, `SEASNOKE_HEAD_BRANCH`
- Recreate this repo environment by running the project entrypoint, then
  the repo-native install/test commands from the detected setup files.
