#pragma once
// test_harness.hpp — Lightweight zero-dependency test harness.
//
// Usage inside a refactored submission-*.cpp:
//
//   #include "dsa/dsa.hpp"
//   #include "dsa/test_harness.hpp"
//
//   namespace dsa {
//   class SomeSolution { ... };
//   }  // namespace dsa
//
//   using namespace dsa;
//
//   int main() {
//       TestRunner runner;
//
//       runner.test("example 1", [] {
//           SomeSolution sol;
//           ASSERT_EQ(sol.someMethod(...), expected);
//       });
//
//       runner.test("edge case", [] {
//           SomeSolution sol;
//           ASSERT_TRUE(sol.someMethod(...));
//       });
//
//       runner.report();
//       return runner.failures() > 0 ? 1 : 0;
//   }

#include <iostream>
#include <sstream>
#include <string>
#include <functional>
#include <vector>
#include <exception>

namespace dsa::test {

// ── Assertion helpers ─────────────────────────────────────────────────────

inline void fail(const char *file, int line, const std::string &msg) {
    std::ostringstream oss;
    oss << file << ":" << line << ": " << msg;
    throw std::runtime_error(oss.str());
}

#define ASSERT_EQ(a, b)                                                      \
    do {                                                                     \
        auto _va = (a);                                                      \
        auto _vb = (b);                                                      \
        if (!(_va == _vb)) {                                                 \
            std::ostringstream _os;                                          \
            _os << "ASSERT_EQ(" << #a << ", " << #b                          \
                << ") failed: " << _va << " != " << _vb;                    \
            ::dsa::test::fail(__FILE__, __LINE__, _os.str());                \
        }                                                                    \
    } while (0)

#define ASSERT_TRUE(expr)                                                    \
    do {                                                                     \
        if (!(expr)) {                                                       \
            ::dsa::test::fail(__FILE__, __LINE__,                            \
                              "ASSERT_TRUE(" #expr ") failed");              \
        }                                                                    \
    } while (0)

#define ASSERT_FALSE(expr) ASSERT_TRUE(!(expr))

#define ASSERT_VEC_EQ(a, b)                                                  \
    do {                                                                     \
        auto _vec_a = (a);                                                   \
        auto _vec_b = (b);                                                   \
        ASSERT_EQ(_vec_a.size(), _vec_b.size());                             \
        for (size_t _vi = 0; _vi < _vec_a.size(); ++_vi) {                  \
            if (!(_vec_a[_vi] == _vec_b[_vi])) {                            \
                std::ostringstream _vos;                                    \
                _vos << "ASSERT_VEC_EQ mismatch at index " << _vi           \
                     << ": " << _vec_a[_vi] << " != " << _vec_b[_vi];      \
                ::dsa::test::fail(__FILE__, __LINE__, _vos.str());          \
            }                                                                \
        }                                                                    \
    } while (0)

}  // namespace dsa::test

// ── Test runner ────────────────────────────────────────────────────────────

class TestRunner {
public:
    struct Case {
        std::string name;
        bool        passed;
        std::string error;
    };

    void test(const std::string &name, std::function<void()> body) {
        try {
            body();
            cases_.push_back({name, true, {}});
            std::cout << "  [PASS] " << name << std::endl;
        } catch (const std::exception &e) {
            cases_.push_back({name, false, e.what()});
            std::cout << "  [FAIL] " << name << " — " << e.what() << std::endl;
        } catch (...) {
            cases_.push_back({name, false, "unknown exception"});
            std::cout << "  [FAIL] " << name << " — unknown exception"
                      << std::endl;
        }
    }

    void report() const {
        int passed = 0, failed = 0;
        for (auto &c : cases_) {
            if (c.passed)
                ++passed;
            else
                ++failed;
        }
        std::cout << "\n── " << passed << " passed, " << failed << " failed";
        if (failed > 0)
            std::cout << "  ✗";
        else if (passed > 0)
            std::cout << "  ✓";
        std::cout << std::endl;
    }

    int failures() const {
        int f = 0;
        for (auto &c : cases_)
            if (!c.passed) ++f;
        return f;
    }

private:
    std::vector<Case> cases_;
};
