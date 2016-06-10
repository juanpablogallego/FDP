reset
unset key
set grid
#set yran[-0.2:7]
filename(n) = sprintf("burgers-%04d.dat",n)
N=system("ls -1 burgers-*.dat | wc -l")
do for [i=0:N-1] {
   plot filename(i) u 1:2 w l lw 2 title "Burgers"
   pause 0.2
}
