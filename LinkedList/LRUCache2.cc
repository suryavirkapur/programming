#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using std::cin, std::cout, std::string, std::vector;
using std::istringstream, std::ostringstream;
using std::unordered_map;

struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
    Node* head;
    Node* tail;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    ~DoublyLinkedList() {
        Node* cur = head;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
    }

    Node* pushFront(int key, int value) {
        Node* node = new Node(key, value);
        if (!head) {
            head = tail = node;
        } else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        return node;
    }

    void remove(Node* node) {
        if (node->prev) node->prev->next = node->next;
        else head = node->next;
        if (node->next) node->next->prev = node->prev;
        else tail = node->prev;
        node->prev = node->next = nullptr;
    }

    Node* back() { return tail; }
    bool empty() { return head == nullptr; }
};

class LRUCache {
    int capacity;
    DoublyLinkedList items;
    unordered_map<int, Node*> lookup;
public:
    LRUCache(int cap) : capacity(cap) {}

    int get(int key) {
        auto it = lookup.find(key);
        if (it == lookup.end()) return -1;
        int value = it->second->value;
        items.remove(it->second);
        Node* node = items.pushFront(key, value);
        it->second = node;
        return value;
    }

    void put(int key, int value) {
        auto it = lookup.find(key);
        if (it != lookup.end()) {
            items.remove(it->second);
        } else if ((int)lookup.size() >= capacity) {
            Node* stale = items.back();
            int staleKey = stale->key;
            items.remove(stale);
            delete stale;
            lookup.erase(staleKey);
        }
        Node* node = items.pushFront(key, value);
        lookup[key] = node;
    }
};

static constexpr auto GREEN = "\033[1;32m";
static constexpr auto RED   = "\033[1;31m";
static constexpr auto RESET = "\033[0m";

void solve() {
    int cap;
    cin >> cap;
    LRUCache cache(cap);
    string cmd;
    while (cin >> cmd) {
        if (cmd == "put") {
            int k, v;
            cin >> k >> v;
            cache.put(k, v);
        } else if (cmd == "get") {
            int k;
            cin >> k;
            cout << cache.get(k) << "\n";
        }
    }
}

void run_tests() {
    struct TestCase { string input; string expected; };
    vector<TestCase> tests = {
        {"2\nput 1 1\nput 2 2\nget 1\nput 3 3\nget 2\nput 4 4\nget 1\nget 3\nget 4\n",
         "1\n-1\n-1\n3\n4\n"},
        {"1\nput 2 1\nget 2\nput 3 2\nget 2\nget 3\n",
         "1\n-1\n2\n"},
        {"2\nget 2\nput 2 6\nget 1\nput 1 5\nput 1 2\nget 1\nget 2\n",
         "-1\n-1\n2\n6\n"},
        {"3\nput 1 10\nput 2 20\nput 3 30\nput 4 40\nget 4\nget 1\nget 2\nget 3\n",
         "40\n-1\n20\n30\n"},
        {"2\nput 2 1\nput 1 1\nput 2 3\nput 4 1\nget 1\nget 2\n",
         "-1\n3\n"},
        {"4\nput 1 1\nput 2 2\nput 3 3\nget 1\nget 2\nget 3\nput 4 4\nput 5 5\nget 1\nget 2\n",
         "1\n2\n3\n-1\n2\n"},
    };
    for (size_t i = 0; i < tests.size(); ++i) {
        istringstream iss(tests[i].input);
        ostringstream oss;
        auto* orig_cin  = cin.rdbuf(iss.rdbuf());
        auto* orig_cout = cout.rdbuf(oss.rdbuf());
        solve();
        cin.rdbuf(orig_cin);
        cout.rdbuf(orig_cout);
        string result = oss.str();
        while (!result.empty() && (result.back() == '\n' || result.back() == '\r'))
            result.pop_back();
        string expected = tests[i].expected;
        while (!expected.empty() && (expected.back() == '\n' || expected.back() == '\r'))
            expected.pop_back();
        if (result == expected)
            cout << "[PASS] Test " << (i + 1) << " - " << GREEN << "OK" << RESET << "\n";
        else {
            cout << "[FAIL] Test " << (i + 1) << " - " << RED << "FAILED" << RESET << "\n";
            cout << "  Expected: '" << expected << "'\n";
            cout << "  Actual:   '" << result   << "'\n";
        }
    }
}

int main() { run_tests(); }
