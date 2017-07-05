library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity tran6 is
	port(
		b:in std_logic;
		a1,a2,a3,a4,a5,a6:out std_logic);--from a to g
	end tran6;

architecture a of tran6 is

begin
	a1<=b;
	a2<=b;
	a3<=b;
	a4<=b;
	a5<=b;
	a6<=b;
end a;
