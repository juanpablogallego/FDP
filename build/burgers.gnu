reset
unset key
set grid
set yran[0:1.1]
filename_u(n) = sprintf("burgers-000%d.dat",n)
filename(n) = sprintf("burgers-00%d.dat",n)

N=system("ls -1 burgers-*.dat | wc -l")

do for [i=1:N] {
   if (i < 10) {
		plot filename_u(i) u 1:2 w l lw 2
	}
   else {
		plot filename(i) u 1:2 w l lw 2
	}
   pause 0.1
}
