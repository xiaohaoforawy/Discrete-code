library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity count6b is
	port(
		cin,reset,set0,set1,set2,add,clk,set3,clk1:in std_logic;
		cout,A,B,C,timer,baoshi,D:out std_logic);
	end count6b;

architecture a of count6b is
signal q_temp:std_logic_vector(2 downto 0);
signal q1:std_logic_vector(2 downto 0);
--signal q2:std_logic_vector(2 downto 0);
signal q:std_logic_vector(2 downto 0);
signal qtimer:std_logic_vector(2 downto 0);
signal flag:std_logic;
signal aaa:std_logic;
signal bbb:std_logic;
begin
		
		process(cin,reset,set2)--add time
		begin
		if(set2='1' and set0='1')	then 
			q_temp<=q1;
			cout<='0';
			aaa<='0';
		elsif (set0='0' and reset='1') then
			q_temp<="000";
		elsif (cin'event and cin='1') then			
			if (q_temp="101") then 
				q_temp<="000";
				cout<='1';
				aaa<='1';
			else 
				q_temp<=q_temp+1;
				cout<='0';
				aaa<='0';
			end if;
		end if;
	end process;
	process(clk1)
		begin
		if(clk1'event and clk1='1') then
			if(set0='0' and set1='0') then
				q<=q_temp;
				D<='0';
			elsif(set0='1' and set1='0') then 
				q<=q1;
				D<='0';
			else	
				if(flag='0') then
					flag<='1';
					q<=q1;
					D<='0';
				else
					flag<='0';
					q<="111";
					D<='1';
				end if;
			end if;
		end if;
	end process;
	process(set3)
		begin
		if(set3='1' and set0='1')	then 
			qtimer<=q1;
		end if;
	end process;
	process(clk)
		begin
		
		if(clk'event and clk='1' ) then
		if(qtimer=q_temp and set3='1') then timer<='1';
			else timer<='0';
			end if;
		if(aaa='1' and bbb='1' and q_temp="000")	then
		 baoshi<='1';
		 bbb<='0';
		elsif(aaa='1' and bbb='0')	then
		 baoshi<='0';
		else bbb<='1';
			baoshi<='0';
		end if;
		
--		if(cin='1' and  q_temp="101")	then baoshi<='1';
--		else baoshi<='0';
--		end if;
--			q2<=q1;
--		if(set1='1')	then		
--			if(flag='0') then
--				flag<='1';
--			else
--				flag<='0';
--				q2<="111";
--			end if;
--		end if;

		end if;
		end process;
	process(add)--set
		begin
		if (set0='1' and set1='1' and (add'event and add='1')) then
			if(q1="101") then q1<="000";
			else q1<=q1+1;
			end if;
		end if;
	end process;
		C<=q(2);
		B<=q(1);
		A<=q(0);
end a;
