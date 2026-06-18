cmake_minimum_required(VERSION 3.14)
project(dsa-solutions LANGUAGES CXX)

# C++17 for structured bindings, if-init, etc.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Shared include directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# ── Gather every submission-*.cpp under the top-level DSA directory ────────
set(DSA_DIR "${CMAKE_SOURCE_DIR}/Data Structures & Algorithms")

file(GLOB_RECURSE SUBMISSION_FILES "${DSA_DIR}/submission-*.cpp")

foreach(src ${SUBMISSION_FILES})
    # Derive a unique target name from the relative path.
    # e.g.  "Data Structures & Algorithms/anagram-groups/submission-0.cpp"
    #   →   dsa_anagram_groups_submission_0
    file(RELATIVE_PATH rel "${CMAKE_SOURCE_DIR}" "${src}")
    string(REGEX REPLACE "[/ .&-]+" "_" tgt "dsa_${rel}")
    string(REGEX REPLACE "_cpp$" "" tgt "${tgt}")
    add_executable("${tgt}" "${src}")
endforeach()

# ── Convenience aggregate target ───────────────────────────────────────────
#  cmake --build . --target all_dsa    ←  builds every submission
add_custom_target(all_dsa)
foreach(src ${SUBMISSION_FILES})
    file(RELATIVE_PATH rel "${CMAKE_SOURCE_DIR}" "${src}")
    string(REGEX REPLACE "[/ .&-]+" "_" tgt "dsa_${rel}")
    string(REGEX REPLACE "_cpp$" "" tgt "${tgt}")
    add_dependencies(all_dsa "${tgt}")
endforeach()
