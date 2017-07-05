library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;
entity fenpin2 is port
(
  clk:in std_logic;--主频 1HZ
  oout:out std_logic--复位信号 低有效
);
end entity;

architecture behav of fenpin2 is
  signal flag :std_logic;
	begin
process(clk)
  begin
  if(clk'event and clk='1') then
	flag<=not flag;
	end if;
  end process;
 oout<=flag;
end architecture;
