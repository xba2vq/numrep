# a simle gnuplot macro

set encoding utf8
set term png size 1200,900 enhanced
set output 'bessel.png'

set xlabel "x"
set ylabel "bessel_n(x)"

DN=19
UP=2

plot "bessel0.dat" using 1:2 pt DN title "j0 - downward",\
     "bessel0.dat" using 1:3 pt UP title "j0 - upward",\
     "bessel3.dat" using 1:2 pt DN title "j3 - downward",\
     "bessel3.dat" using 1:3 pt UP title "j3 - upward",\
     "bessel5.dat" using 1:2 pt DN title "j5 - downward",\
     "bessel5.dat" using 1:3 pt UP title "j5 - upward",\
     "bessel8.dat" using 1:2 pt DN title "j8 - downward",\
     "bessel8.dat" using 1:3 pt UP title "j8 - upward"

