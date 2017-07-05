library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity  yima38 is
	port(
		C,B,A:in std_logic;
		y0,y1,y2,y3,y4,y5,y6,y7:out std_logic);
	end yima38;

architecture a of yima38 is
begin
	y0<=not C and not B and not A;
	y1<=not C and not B and  A;
	y2<=not C and  B and not A;
	y3<=not C and  B and  A;
	y4<= C and not B and not A;
	y5<= C and not B and  A;
	y6<= C and  B and not A;
	y7<= C and  B and  A;
end a;
