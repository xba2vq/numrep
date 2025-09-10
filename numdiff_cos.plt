#set term postscript size 1200,900 enhanced
#set output 'cos.ps'
set encoding utf8
set term png size 1200,900 enhanced
set output 'cos.png'
set multiplot layout 3,1 margins screen 0.1,0.9,0.1,0.9 spacing screen 0.05,0.08 title 'Numerical Derivative of cos(x)'
#set multiplot layout 3,1 margins screen 0.1,0.9,0.1,0.9 spacing screen 0.05,0.13 title 'Numerical Derivative of cos(x)'
set key bottom left box
set title 'At x=0.1'
set logscale x 10
set logscale y 10
set xrange [1e-15:1]
set yrange [1e-16:1]

set ylabel 'log_{10}(Relative Error)'
plot 'numdiff_cos_t1.dat' u 2:(abs($6)) w p title 'Forward Difference',\
'' u 2:(abs($7)) w p title 'Central Difference',\
'' u 2:(abs($8)) w p title 'Extrapolated Difference',\
x w l title 'O(x)',\
x**2 w l title 'O(x^2)',\
x**4 w l title 'O(x^4)'

set title 'At x=1.0'

plot 'numdiff_cos_t2.dat' u 2:(abs($6)) w p title 'Forward Difference',\
'' u 2:(abs($7)) w p title 'Central Difference',\
'' u 2:(abs($8)) w p title 'Extrapolated Difference',\
x w l title 'O(x)',\
x**2 w l title 'O(x^2)',\
x**4 w l title 'O(x^4)'

set title 'At x=100.0'

set xlabel 'log_{10}(h)'
plot 'numdiff_cos_t3.dat' u 2:(abs($6)) w p title 'Forward Difference',\
'' u 2:(abs($7)) w p title 'Central Difference',\
'' u 2:(abs($8)) w p title 'Extrapolated Difference',\
x w l title 'O(x)',\
x**2 w l title 'O(x^2)',\
x**4 w l title 'O(x^4)'
