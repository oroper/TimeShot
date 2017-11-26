l = 130;
b = 85;
h = 45;
s = 5;

usbB = 12;
usbx = 5;
usbA = 11;
usbz = 6.5;

rJeck = 10/2;
jeckz = 6 + rJeck;
jeckx = 58 + usbx;

// Supporti
rse = 3;
rsi = 1.4;
// 1
x1 = usbx + 5;
y1 = 73;
// 2
x2 = usbx + usbB + 26;
y2 = 50;
// 3
x3 = usbx + usbB + 60;
y3 = 30;
// 4
x4 = usbx + usbB + 70;
y4 = 73;

module sup(){
	translate([-l/2+usbx,b/2,-h/2])
	difference(){
		cylinder(5,rse,rse);
		cylinder(5,rsi,rsi);
	}
}

difference(){
difference(){
	translate([0,0,-s])
	cube([l+2*s,b+2*s,h+s], center = true);
	
	cube([l,b,h], center= true);
}

union(){
#translate([-l/2+usbx, b/2,-h/2+usbz])
cube([usbB,s,usbA]);

translate([-l/2+jeckx,b/2+s,-h/2+jeckz])
rotate([90,0,0])
#cylinder(s,rJeck,rJeck);

}

}

translate([x1,-y1,0])
sup();
translate([x2,-y2,0])
sup();
translate([x3,-y3,0])
sup();
translate([x4,-y4,0])
sup();