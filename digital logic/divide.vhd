library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;
entity fenpin is port
(
  clk:in std_logic;--主频 10kHz
  oout:out std_logic--复位信号 低有效
);
end entity;

architecture behav of fenpin is
  signal cnt:std_logic_vector(9 downto 0);
	begin
process(clk)
  begin
  if(clk'event and clk='1') then
		cnt<=cnt+1;
	end if;
  end process;
  oout<= cnt(9) and cnt(8) and cnt(7) and cnt(6) and cnt(5) and cnt(4) and cnt(3) and cnt(2) and cnt(1) and cnt(0);
end architecture;
