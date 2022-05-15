# Set Matrix Zeroes

[Question Link](https://leetcode.com/problems/set-matrix-zeroes/)

- All the values around zero is 1.
- Whenever we encounter the zero we should not change it to `-1` because it might effecting any column and row.
- And whenever we encounting `1` we change it to `-1`.

## Approach (less optimized)

1. We will maintain two array's column array and right array.
2. Whenever we encounter the `0` we will marked both array position to `0`.
3. Then we traverse the matrix and check the both col and row matrix , if any of them is zero then we mark it to 0.

## Approach (optimized)

1. Here we optimize the space complexiy by taking the dummy array as the first col and first row.
2. We also maintain a `col` bool variable because we have to chnage the `a[0][0]` element as it will cause the error.
