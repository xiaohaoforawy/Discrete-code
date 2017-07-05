library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity to7 is
	port(
		AA,BB,CC,DD:in std_logic;
		a,b,c,d,e,f,g:out std_logic);--from a to g
	end to7;

architecture a of to7 is
signal y:std_logic_vector(6 downto 0);
begin
	process(DD,BB,CC,AA)
		variable x:std_logic_vector(3 downto 0);
		begin
		x:=DD&CC&BB&AA;
		case x is
			when"0000"=>y<="1111110";--0
			when"0001"=>y<="0110000";--1
			when"0010"=>y<="1101101";--2
			when"0011"=>y<="1111001";--3
			when"0100"=>y<="0110011";--4
			when"0101"=>y<="1011011";--5
			when"0110"=>y<="0011111";--6
			when"0111"=>y<="1110000";--7
			when"1000"=>y<="1111111";--8
			when"1001"=>y<="1111011";--9
			when others=>y<="0000000";
		end case;
		end process;
	a<=y(6);
	b<=y(5);
	c<=y(4);
	d<=y(3);
	e<=y(2);
	f<=y(1);
	g<=y(0);
end a;
