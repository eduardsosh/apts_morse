import filecmp




def prRed(skk): print("\033[91m {}\033[00m" .format(skk))
def prGreen(skk): print("\033[92m {}\033[00m" .format(skk))


def compare_files(file1_path, file2_path, testn):
    try:
        if filecmp.cmp(file1_path, file2_path):
            prGreen(f"Test {testn} passed")
        else:
            prRed(f"Test {testn} failed")
    except FileNotFoundError:
        print("One or both files not found.")


if __name__ == "__main__":
    # List of file pairs to compare
    file_pairs = [
        ("outputs/morse.o1", "test_files/morse.o1"),
        ("outputs/morse.o2", "test_files/morse.o2"),
        ("outputs/morse.o3", "test_files/morse.o3"),
        ("outputs/morse.o4", "test_files/morse.o4"),
        ("outputs/morse.o5", "test_files/morse.o5"),
        ("outputs/morse.o6", "test_files/morse.o6"),
        ("outputs/morse.o7", "test_files/morse.o7"),
        ("outputs/morse.o8", "test_files/morse.o8"),
        ("outputs/morse.o9", "test_files/morse.o9"),
        ("outputs/morse.o10", "test_files/morse.o10"),
        ("outputs/morse.o11", "test_files/morse.o11"),
        # Add more file pairs as needed
    ]

    # Compare each pair of files
    n = 1
    for file1, file2 in file_pairs:
        compare_files(file1, file2,n)
        n += 1
