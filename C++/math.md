# 1. ceil of (k/y)

How many times to add y to get sum >= k === ceil[k/y]
ceil(k/y) === (k+y-1)/y
or ceil(k/y) === k % y == 0 ? k/y : k/y-1;

-   similarly floor (k/y) = ceil(k/y) - 1
