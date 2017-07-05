library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity yaopin is
	port(
		mode3:in std_logic;
		bnum,pnum:in std_logic_vector(3 downto 0);
		C:out std_logic_vector(3 downto 0));--from a to g
	end yaopin;

architecture a of yaopin is
signal y:std_logic_vector(6 downto 0);
begin
	process(mode3)
		begin
		if(mode3='1') then C<=bnum;-- xian shi yao ping shu liang 
		else C<=pnum;-- xian shi yao pian shu liang
		end if;
		end process;
end a;
