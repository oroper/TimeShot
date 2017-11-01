l = 130;
b = 85;
h = 45;
s = 5;

usbB = 12;
usbA = 11;

rJeck = 10/2;

difference(){
	cube([l+2*s,b+2*s,h], center = true);
	translate([0,0,s])
	cube([l,b,h], center= true);
}

