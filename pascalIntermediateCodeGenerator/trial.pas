program example(input, output);
var x,y: integer;
var carray: array[1..10] of integer;
function gcd(a,b,c:integer; d:real):integer;
var gc:integer;
begin
    a:=1;
    carray[5]:=gc;
    a:= b+c;
    x := 10;
    a:=c;
    if b = 0 then gc:=a
    else gc := gcd(b, a mod b, 0, 0.0)

end;
function adder(a,b:integer):integer;
var c,gc:integer;
begin
	c:=a+b;
	carray[1]:=gc;
	gc:=gcd(x,y,0,0.0)

end;
	
begin
    read(x, y);
    write(gcd(x,y, 0, 0.0))
end.
