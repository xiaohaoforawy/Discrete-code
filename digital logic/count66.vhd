library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity count66 is
	port(
		cin:in std_logic;
		A,B,C:out std_logic);
	end count66;

architecture a of count66 is
signal q_temp:std_logic_vector(2 downto 0);
begin
		process(cin)--add time
		begin
		if (cin'event and cin='1') then
			if (q_temp="101") then 
				q_temp<="000";
			else 
				q_temp<=q_temp+1;
			end if;
		end if;
		end process;
		C<=q_temp(2);
		B<=q_temp(1);
		A<=q_temp(0);
	end a;
