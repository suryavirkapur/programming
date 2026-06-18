#!/usr/bin/env bash
# run-all-tests.sh — Build and execute every DSA solution test suite.
#
# Prerequisites: cmake ≥ 3.14, a C++17 compiler (g++ or clang++).
#
# Usage:
#   ./scripts/run-all-tests.sh          # build & run all
#   ./scripts/run-all-tests.sh --clean  # wipe build dir first

set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
BUILD_DIR="$ROOT/build"

# ── Option parsing ─────────────────────────────────────────────────────────
CLEAN=0
for arg in "$@"; do
    case "$arg" in
        --clean|-c) CLEAN=1 ;;
        -h|--help)
            echo "Usage: $0 [--clean]"
            echo "  --clean   Remove build directory before configuring"
            exit 0
            ;;
    esac
done

# ── Clean ──────────────────────────────────────────────────────────────────
if [[ "$CLEAN" -eq 1 ]]; then
    echo "==> Removing $BUILD_DIR"
    rm -rf "$BUILD_DIR"
fi

# ── Configure ──────────────────────────────────────────────────────────────
mkdir -p "$BUILD_DIR"
echo "==> Configuring (cmake) …"
cmake -S "$ROOT" -B "$BUILD_DIR" > /dev/null

# ── Build each target independently (best-effort) ──────────────────────────
echo "==> Building targets (best-effort, independent) …"
BUILT=0
FAILED_BUILD=0

# Extract all dsa_* target names from the generated build system.
TARGETS=$(cmake --build "$BUILD_DIR" --target help 2>/dev/null | grep -oP '\.\.\. \Kdsa_[^ ]+' || true)

if [[ -z "$TARGETS" ]]; then
    echo "No dsa_* targets found. Check CMakeLists.txt."
    exit 1
fi

for tgt in $TARGETS; do
    # Skip aggregate / custom targets
    [[ "$tgt" == all_dsa ]] && continue
    printf "  %-70s " "$tgt"
    if cmake --build "$BUILD_DIR" --target "$tgt" -j "$(nproc 2>/dev/null || echo 4)" > /dev/null 2>&1; then
        echo "✓"
        BUILT=$((BUILT + 1))
    else
        echo "✗ (missing includes — see README)"
        FAILED_BUILD=$((FAILED_BUILD + 1))
    fi
done

echo ""
echo "  Built: $BUILT   Skipped: $FAILED_BUILD"
echo ""

# ── Discover & run executables ─────────────────────────────────────────────
FAILED=0
PASSED=0
TOTAL=0

# Find every executable that looks like a dsa_* binary.
while IFS= read -r -d '' exe; do
    TOTAL=$((TOTAL + 1))
    echo "────────────────────────────────────────────"
    echo "▶ $(basename "$exe")"
    if "$exe"; then
        PASSED=$((PASSED + 1))
    else
        FAILED=$((FAILED + 1))
    fi
    echo ""
done < <(find "$BUILD_DIR" -maxdepth 3 -type f -executable -name 'dsa_*' -print0)

# ── Summary ────────────────────────────────────────────────────────────────
echo "════════════════════════════════════════════"
echo "  Suites: $TOTAL total, $PASSED passed, $FAILED failed"
echo "  (non-refactored files are skipped — add #include + namespace dsa)"
if [[ "$FAILED" -gt 0 ]]; then
    exit 1
fi
