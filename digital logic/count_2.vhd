library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity count2 is
	port(
		cin,reset,set0,set1,set2,add,clk,set3,clk1:in std_logic;
		A,B,timer,C,D:out std_logic);
	end count2;

architecture a of count2 is
signal q_temp:std_logic_vector(1 downto 0);
signal q1:std_logic_vector(1 downto 0);
--signal q2:std_logic_vector(1 downto 0);
signal q:std_logic_vector(1 downto 0);
signal qtimer:std_logic_vector(1 downto 0);
signal flag:std_logic;
begin
	
		process(cin,reset,set2)--add time
		begin
		if(set2='1' and set0='1')	then 
			q_temp<=q1;
		elsif (set0='0' and reset='1') then
			q_temp<="00";
		elsif (cin'event and cin='1') then			
			if (q_temp="10") then 
				q_temp<="00";
			else 
				q_temp<=q_temp+1;
			end if;
		end if;
	end process;
	process(clk1)
		begin
		if(clk1'event and clk1='1') then
			if(set0='0' and set1='0') then
				q<=q_temp;
				C<='0';
				D<='0';
			elsif(set0='1' and set1='0') then 
				q<=q1;
				C<='0';
				D<='0';
			else	
				if(flag='0') then
					flag<='1';
					q<=q1;
					C<='0';
					D<='0';
				else
					flag<='0';
					q<="11";
					C<='1';
					D<='1';
				end if;
			end if;
		end if;
	end process;
	process(clk)
		begin
		
		if(clk'event and clk='1' ) then
--			q2<=q1;
			if(set3='1' and set0='1')	then 
				qtimer<=q1;
			else null;
			end if;
			if(qtimer=q_temp and set3='1') then timer<='1';
			else timer<='0';
			end if;
--		if(set1='1')	then		
--			if(flag='0') then
--				flag<='1';
--			else
--				flag<='0';
--				q2<="11";
--			end if;
--		end if;

		end if;
		end process;
	process(add)--set
		begin
		if (set0='1' and set1='1' and (add'event and add='1')) then
			if(q1="10") then q1<="00";
			else q1<=q1+1;
			end if;
		end if;
	end process;
		B<=q(1);
		A<=q(0);
end a;
