library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity count10 is
	port(
		cin,reset,set0,set1,set2,add,clk,set3,clk1:in std_logic;
		cout,A,B,C,D,timer:out std_logic);
	end count10;

architecture a of count10 is
signal q_temp:std_logic_vector(3 downto 0);
signal q1:std_logic_vector(3 downto 0);
signal q:std_logic_vector(3 downto 0);
signal qtimer:std_logic_vector(3 downto 0);
signal flag:std_logic;

begin
	process(cin,reset,set2)--add time
		begin
		if(set2='1' and set0='1')	then 
			q_temp<=q1;
			cout<='0';
		elsif (set0='0' and reset='1') then
			q_temp<="0000";
		elsif (cin'event and cin='1') then			
			if (q_temp="1001") then 
				q_temp<="0000";
				cout<='1';
			else 
				q_temp<=q_temp+1;
				cout<='0';
			end if;
		else
			null;
		end if;
	end process;
	process(clk1)
		begin
		if(clk1'event and clk1='1') then
			if(set0='0' and set1='0') then
				q<=q_temp;
			elsif(set0='1' and set1='0') then 
				q<=q1;
			else	
				if(flag='0') then
					flag<='1';
					q<=q1;
				else
					flag<='0';
					q<="1111";
				end if;
			end if;
		end if;
	end process;
			
	process(clk)
		begin		
		if(clk'event and clk='1' ) then
		
			if(set3='1' and set0='1')	then 
				qtimer<=q1;
			else null;
			end if;
			if(qtimer=q_temp and set3='1') then timer<='1';-- set3 and the same time
			else timer<='0';
			end if;
--			if(set1='1')	then		
--				if(flag='0') then
--					flag<='1';
--				else
--					flag<='0';
--					q2<="1111";
--				end if;
--			else null;
--			end if;

			
		end if;
	end process;
	process(add)--set q1
		begin
		if (set0='1' and set1='1' and (add'event and add='1')) then
			if(q1="1001") then q1<="0000";
			else q1<=q1+1;
			end if;
		end if;
	end process;
		D<=q(3);
		C<=q(2);
		B<=q(1);
		A<=q(0);
	end a;
