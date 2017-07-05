library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity cnt10a is
	port(
		cin,reset,mode1:in std_logic;
		cout:out std_logic;
		Y:out std_logic_vector(3 downto 0));
	end cnt10a;

architecture a of cnt10a is
signal q:std_logic_vector(3 downto 0);
begin
	process(cin,reset)--add time
		begin
		if(reset='1' and mode1='0')	then 
			q<="0000";
			cout<='0';
		elsif (cin'event and cin='1') then			
			if (q="1001") then 
				q<="0000";
				cout<='1';
			else 
				q<=q+1;
				cout<='0';
			end if;
		end if;
	end process;
		Y(3)<=q(3);
		Y(2)<=q(2);
		Y(1)<=q(1);
		Y(0)<=q(0);
	end a;
