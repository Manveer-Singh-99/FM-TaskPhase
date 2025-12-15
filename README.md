# FM-TaskPhase

###1. Math Check**File:** `task1_math_check.c`

* **Negative Inputs:** Explicitly checks for negative numbers before attempting prime/composite logic, as definitions for negatives vary or are undefined in this context.
* **Numbers 0 and 1:** Specifically handles 0 and 1, correctly identifying them as "neither prime nor composite" rather than incorrectly labeling them.
* **Sum Parity:** Works correctly regardless of whether the sum is positive, negative, or zero.

###2. Time Conversion**File:** `task2_time_conversion.c`

* **Negative Seconds:** Validates input to ensure time is non-negative.
* **Zero Input:** Correctly calculates and formats 0 hours, 0 minutes, and 0 seconds.
* **Large Inputs:** The math uses modulo arithmetic correctly, so inputs larger than 24 hours are handled without overflow or logic errors (e.g., calculating total hours rather than cycling day clocks).

###3. Electricity Bill**File:** `task3_electricity_bill.c`

* **Negative Usage:** Returns an error code (`-1.0`) if the unit input is negative.
* **Exact Tier Boundaries:** The logic `if (units <= 100)` handles the exact boundary values (100, 300) correctly, preventing "off-by-one" calculation errors.

###4. Login System**File:** `task4_login.c`

* **Buffer Overflow:** Uses `fgets` with a constrained size limit to prevent users from crashing the program by entering extremely long passwords.
* **Newline Handling:** Accounts for the `\n` character that `fgets` automatically captures (which `gets` does not), removing it to ensure `strcmp` works correctly.
* **Empty Input/EOF:** Checks if `fgets` returns `NULL` (indicating an error or End-Of-File) to prevent processing invalid memory.

###5. Remove Duplicates**File:** `task5_remove_duplicates.c`

* **Invalid Array Size:** Returns `NULL` immediately if the array size is 0 or negative.
* **Memory Allocation Failure:** Checks if `malloc` returns `NULL` and safely cleans up (frees) any partial memory before exiting.
* **All Duplicates:** Correctly handles arrays where every element is identical (e.g., `{2, 2, 2}` becomes `{2}`).
* **No Duplicates:** Correctly handles arrays that are already unique.

###6. String Operations**File:** `task6_string_ops.c`

* **Case Insensitivity:** Converts characters to `tolower()` before checking, ensuring 'A' and 'a' are both counted as vowels.
* **Non-Letters:** Uses `isalpha()` to skip over spaces, punctuation, and numbers when counting vowels/consonants.
* **Random Seeding:** Uses `srand(time(NULL))` so the string scramble pattern is different every time the program runs.

###7. Second Largest Element**File:** `task7_second_largest.c`

* **Small Arrays:** Explicitly checks if `n < 2` because a "second largest" cannot exist in an array with 0 or 1 elements.
* **Negative Numbers:** Initializes `second_largest_val` to `INT_MIN` (minimum possible integer) to ensure the logic works even if the array contains only negative numbers.
* **Duplicate Maxima:** The condition `arr[i] != largest` ensures strict ranking (e.g., in `{5, 5, 2}`, the second largest is 2, not 5).

###8. Swap Adjacent Elements**File:** `task8_swap_pointers.c`

* **Invalid Size:** Returns early if the array size is 0 or negative.
* **Loop Boundaries:** The loop condition `i < n - 1` ensures the pointer never accesses memory outside the array bounds (accessing `*(arr + i + 1)` at the last element would be a segmentation fault).

###9. Matrix Operations**File:** `task9_matrix_ops.c`

* **Fixed Dimensions:** While the code is specific to 4x4, the loops are hardcoded to match the array declaration, preventing index out-of-bounds errors.

###10. Rotate Matrix**File:** `task10_rotate_matrix.c`

* **Data Overwrite Protection:** Uses a temporary matrix (`temp`) to store rotated values. Attempting to rotate a matrix in-place without a temp buffer often leads to data loss (reading a value you just overwrote).

###11. Sorting and Searching**File:** `task11_sort_search.c`

* **Binary Search Prerequisite:** The main function explicitly calls `bubble_sort` *before* `binary_search`. Binary search fails silently on unsorted data.
* **Integer Overflow:** The midpoint calculation `low + (high - low) / 2` is used instead of `(low + high) / 2`. The latter can cause an integer overflow crash if the array indices are very large.
* **Element Not Found:** Returns `-1` if the target is missing, and the main function checks for this specific return code.

###12. Inventory Management**File:** `task12_inventory.c`

* **Type Safety:** Replaced the original (unsafe) 2D integer array with a `struct`. This prevents the critical error of trying to store string names and float prices inside an integer array.
* **Data Integrity:** Structs ensure that the ID, name, quantity, and price remain linked together correctly during sorting or access.

###13. Star Pattern**File:** `task13_star_pattern.c`

* **Zero/Negative Rows:** The loop condition `i <= n` ensures that if the user asks for 0 or negative rows, the program outputs nothing instead of entering an infinite loop.

###14. File Statistics**File:** `task14_file_stats.c`

* **File Open Failure:** Checks if `fopen` returns `NULL` and prints a system-level error message using `perror`.
* **Word Boundaries:** Uses a state flag (`in_word`) to correctly handle multiple spaces. It ensures that "word1   word2" is counted as 2 words, not 4.
* **Empty Files:** The `while` loop condition naturally fails immediately on an empty file, resulting in accurate counts of 0.

###15. Recursive Fibonacci**File:** `task15_fibonacci.c`

* **Base Case:** Checks `n <= 1` to stop recursion. This effectively handles `n=0`, `n=1`, and implicitly returns the input for negative numbers (preventing infinite recursion stack overflow).

###16. String Compression**File:** `task16_string_compression.c`

* **Null/Empty Input:** Checks if `(!str)` or `strlen == 0` at the very start to avoid processing invalid pointers.
* **Buffer Bounds:** The logic `while (i + 1 < len)` ensures the inner loop never reads past the null terminator of the string.
* **Memory Safety:** Checks if `malloc` fails before writing to the new string.
