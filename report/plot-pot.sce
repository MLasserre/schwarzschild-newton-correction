xdel(winsid());
clear;
clc;


function y = V(a, b, r)
y = -a*r .^(-1) + b*r .^(-2)
endfunction

x = 0.01:0.001:2;
y_1 = V(1.,2.,x);
y_2 = V(1.,0.,x);

scf(1);
clf(1);
plot2d(x,y_1);
plot2d(x,y_2);

a=gca()
//a.box = "off"  remove the box
a.x_location = "origin";
//a.y_location = "middle";
//set(gca(), "grid", [1,1])  grid on

