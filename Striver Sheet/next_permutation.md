# Next Permutation

Here we have to find lexographically next permutation of string.

## Approach

### This to get next permutation

1. `a[i] < a[i+1]`place `index1` here.
2. linear traversal from back and find `a[ind2]>a[ind1` then place there `ind2`.
3. Swap the value the value at `ind1` and `ind2`.
4. reverse the array after `ind1+1` till last.
