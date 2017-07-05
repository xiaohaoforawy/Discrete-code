library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;
entity count24 is
	port(
		cin,reset,set0,set1,set2,add,clk,set3:in std_logic;
		cout,A,B,C,D,E,F,timer:out std_logic);
	end count24;

architecture a of count24 is
signal q_temp:integer range 0 to 23;
signal q1:integer range 0 to 23;
signal q2:integer range 0 to 23;
signal q:integer range 0 to 23;
signal qtimer:integer range 0 to 23;
signal flag:std_logic;
signal H1:std_logic_vector(1 downto 0);
signal H0:std_logic_vector(3 downto 0);
begin
		process(cin,reset,set2)--add time
		begin
		if(set2='1' and set0='1')	then 
			q_temp<=q1;
		elsif (set0='0' and reset='1') then
			q_temp<=0;
		elsif (cin'event and cin='1') then
			if(q_temp=23) then cout<='1';
			else cout<='0';
			end if;
			q_temp<=q_temp+1;
		end if;
	end process;
	process(set3)
		begin
		if(set3='1' and set0='1')	then 
			qtimer<=q1;
		end if;
	end process;
	process(clk)
	variable aa:integer;
	variable bb:integer;
		begin
		
		if(clk'event and clk='1' ) then
			if(qtimer=q_temp and set3='1') then timer<='1';-- set3 and the same time
			else timer<='0';
			end if;
			q2<=q1;
		if(set1='1')	then		
			if(flag='0') then
				flag<='1';
			else
				flag<='0';
				q2<=23;
			end if;
		end if;

		if(set0='0') then
			q<=q_temp;
		else 
			q<=q2;
		aa:=q MOD 10;
		bb:= q /10;	
		H1<=conv_std_logic_vector(bb,2);
		H0<=conv_std_logic_vector(aa,4);
		end if;
		end if;
		end process;
	process(add)--set
		begin
		if (set0='1' and set1='1' and (add'event and add='1')) then
			q1<=q1+1;
		end if;
	end process;
		F<=H1(1);
		E<=H1(0);
		D<=H0(3);
		C<=H0(2);
		B<=H0(1);
		A<=H0(0);
	end a;
