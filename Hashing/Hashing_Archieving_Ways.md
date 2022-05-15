# Mod

This is the way by which we can find the function that we use to enter data in hash table.

```cpp
h(x) = (x % size)+1;
```

# MidSquare

In this we create a hash function in which we sqare the key and take the mid value of number.

```cpp
#define key 10
int a = key*key;
// 100 here the index or enter the value.
```

# Folding

This is the way by which we select some digit and sum them to get a single number on which we can save our data.

```cpp
int key = 123347;
// 12 + 33 + 47 = 92;
// for more smaller we can add these two (92) also , which lead to 11
```

## For Character

For these we can add `ASCII` code of character and follow folding.

```cpp
string key = "ABC";
// 65 + 66 + 67 = 198;
```
