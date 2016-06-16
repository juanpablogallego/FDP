reset
set terminal epslatex size 8.89cm, 6.65cm color colortext
set grid
set yran[-1.1:1.1]
set xlabel '$Space$'
set ylabel '$U$'
set xtics (0,'$\frac{\pi}{2}$' pi/2, '$\pi$' pi,'$\frac{3 \pi}{2}$' 3*pi/2, '$2\pi$' 2*pi)
filesol(n) = sprintf("burgers-%04d.dat",n)
fileplot(n) = sprintf("burgers-%04d.eps",n)
N=system("ls -1 burgers-*.dat | wc -l")
do for [i=0:N-1] {
   set output fileplot(i)
   plot filesol(i) u 1:2 title '$\sin(x)$' w l lw 5
   pause 0.2
}
