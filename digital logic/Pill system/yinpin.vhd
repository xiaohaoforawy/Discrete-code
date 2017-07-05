library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;
entity music is port
(
  clk:in std_logic;--主频 100k
  en:in std_logic;--复位信号 低有效
  aclk:in std_logic;--1hz
  final:out std_logic--频率输出
);
end entity;

architecture behav of music is
  signal freqout:std_logic;
  signal freq:std_logic_vector(7 downto 0);
  signal cnt:std_logic_vector(7 downto 0);
  signal tine:std_logic_vector(1 downto 0);
  signal flag:std_logic;
  signal g:std_logic;
begin
  final <= freqout;
process(aclk,en)
  begin


  if(en='1' and flag='0')	then 
	tine<="00";
	flag<='1';
	
  elsif(aclk'event and aclk='1') then 
	g<=not g;
	
	if(tine="01") then flag<='0';
	else tine<=tine+1;
	if(en='1')  then flag<='1';
	end if;
  end if;
  

 
  end if;
  end process;
process(clk)
  begin
    
		if rising_edge(clk) then
		if(flag='1' and g='0') then
		freq<="10011100";
		else
		    freq<="00000000";
		 end if;


		   if (cnt = freq )  then--计数器
			  cnt <= "00000000";
				freqout <= not freqout;--输出取反<=>输出方波
			else
			  cnt <= cnt + 1;
			end if;

		end if;

  end process;
end architecture;
