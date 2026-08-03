#!/usr/bin/env python3
import subprocess
import sys
from pathlib import Path


ALLOWED_SUFFIXES = {".cc", ".rs", ".ts", ".js", ".py", ".md"}
IGNORED_PREFIXES = ("MiniProjects/",)


def staged_paths() -> list[Path]:
    result = subprocess.run(
        ["git", "diff", "--cached", "--name-only", "--diff-filter=AMR"],
        check=True,
        stdout=subprocess.PIPE,
        text=True,
    )
    return [Path(line) for line in result.stdout.splitlines() if line]


def looks_binary(path: Path) -> bool:
    try:
        data = path.read_bytes()
    except FileNotFoundError:
        return False
    return b"\0" in data


def main() -> int:
    bad_paths: list[str] = []
    bad_extension: list[str] = []
    binary_files: list[str] = []

    for path in staged_paths():
        path_text = path.as_posix()
        if path_text.startswith(IGNORED_PREFIXES):
            bad_paths.append(path_text)
            continue
        if path.suffix not in ALLOWED_SUFFIXES:
            bad_extension.append(path_text)
            continue
        if looks_binary(path):
            binary_files.append(path_text)

    if bad_paths:
        print("Ignored paths cannot be committed:")
        for path in bad_paths:
            print(f"  {path}")

    if bad_extension:
        print("Disallowed file extensions:")
        for path in bad_extension:
            print(f"  {path}")

    if binary_files:
        print("Binary files are not allowed:")
        for path in binary_files:
            print(f"  {path}")

    if bad_paths or bad_extension or binary_files:
        print("Allowed extensions: .cc, .rs, .ts, .js, .py, .md")
        return 1

    return 0


if __name__ == "__main__":
    sys.exit(main())
