mat = read("solution_einstein.dat", -1, 3);

//t     = mat(3:$,1);
r     = mat(3:$,2);
theta = mat(3:$,3);

//pas     = mat(1,2)
//t_min   = mat(1,3)
//t_max   = mat(1,4)
//r0     = mat(2,1)
//r0_point =
//theta0 = 
//theta0_point = 

//plot2d([t,t],[y,z], leg="numerique", style=5) //Trace de la solution en vert
polarplot(theta, r)

set(gca(), "grid", [1,1])
//xtitle('Calcul de la trajectoire avec la force corrigée')
