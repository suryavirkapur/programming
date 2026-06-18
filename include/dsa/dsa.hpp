#pragma once
// dsa.hpp — Shared DSA types and utilities for all LeetCode-style solutions.
// Include this header in every refactored submission to pull in standard
// library headers, common data structures, and the dsa namespace.

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

// ── Common LeetCode data structures ────────────────────────────────────────

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Interval (used by meeting-schedule and similar problems)
struct Interval {
    int start, end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

// Graph node (used by clone-graph and similar problems)
struct Node {
    int val;
    std::vector<Node*> neighbors;
    Node() : val(0), neighbors{} {}
    Node(int _val) : val(_val), neighbors{} {}
    Node(int _val, std::vector<Node*> _neighbors)
        : val(_val), neighbors(std::move(_neighbors)) {}
};

// ── DSA namespace ──────────────────────────────────────────────────────────
// All refactored solutions live inside namespace dsa so they can coexist
// peacefully inside a single translation unit if needed.

namespace dsa {

// Re-export commonly used standard names into dsa:: for convenience.
using std::abs;
using std::cout;
using std::deque;
using std::endl;
using std::function;
using std::list;
using std::map;
using std::max;
using std::min;
using std::pair;
using std::priority_queue;
using std::queue;
using std::set;
using std::sort;
using std::stack;
using std::string;
using std::swap;
using std::unordered_map;
using std::unordered_set;
using std::vector;

}  // namespace dsa
