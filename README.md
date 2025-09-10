# numrep

Overflow and underflow:
======================

1. For floats, overflow occurred above 1.701412e38 (IEEE 754 max float: 3.4028235e38) and underflow occurred below 1.401298e-45 (IEEE 754 min float: 1.40129846e-45).

2. For doubles, overflow occurred above 8.988466e307 (IEEE 754 max double: ~ 1.79769313e308) and underflow occurred below 4.940656e-324 (IEEE 754 min double: ~ 4.94055e-324).

3. For signed integers, overflow occurred at 2147483647 and underflow occurred at -2147483648.

4. For unsigned integers, overflow occurred at 4294967295 and underflow occurred at 0.

Note: 3 and 4 rely on undefined behavior according to the C++ specification. The test applications work as intended when optimizations are turned off, but they produce unexpected results (not halting when desired) when optimizations are enabled.

5. The default integer type in Python is of arbitrary precision. Attempting to find the limits by search, like was done in 3-4, would find the limits of time, computing resources, or the universe before finding the bounds on the integer data type.

Bessel Function calculation:
===========================

The downward recursion relation seems to give better results for small x (around x=0.1). Both compare favorably to Table 2.1 in Landau for x=1 and x=10.

Numerical Derivatives:
=========================

For cos(x), the relative error in the numerical derivatives track the precision predicted in the text pretty well. For exp(x), my code does not cope with exp(x) for large x -- thus, my final plot at x=100 did not work. For the other two x values, the numerical derivatives tracked the expected values well.

Roundoff error begins to dominate around the turning points on each graph.

