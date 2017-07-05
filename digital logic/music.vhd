library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;
entity music is port
(
  clk:in std_logic;--?÷?μ 10k
  en:in std_logic;--?′??D?o? μíóDD§
  aclk:in std_logic;--1hz
  --selectin:in std_logic_vector(5 downto 0);--?μ?ê????ê?è?￡?òò?a??óDò???ê?3?￡??ùò?±?D?μ?óD????
  final:out std_logic--?μ?êê?3?
);
end entity;

architecture behav of music is
  signal freqout:std_logic;
  signal freq:std_logic_vector(3 downto 0);
  signal cnt:std_logic_vector(3 downto 0);
  signal tine:std_logic_vector(1 downto 0);
  signal flag:std_logic;
  signal circal:std_logic_vector(3 downto 0);
begin
  final <= freqout;
process(aclk,en)
  begin
  if(en='1' and flag='0')	then 
	tine<="00";
	flag<='1';
	
  elsif(aclk'event and aclk='1') then 
	circal<=circal+1;
	if(circal="1111") then
    circal<="0000";
    end if;
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
		if(flag='1') then
		case circal is
		     when "0000"|"0011"|"0100"|"0111"=> freq <="1010";--1
		     when "0001"|"0101"=> freq <="1001";--2
		     when "0010"|"0110"|"1000"|"1011"=> freq <="1000";--3
		     when "1001"|"1100"=> freq <="0111";--4
		     when "1010"|"1101"=> freq <="0110";--5
--		     when "100"|"110"=> freq <="0101";--6
--		     when "100"|"110"=> freq <="0100";--7
		     when others=>freq <="0000";
		end case;
		else
		    freq<="0000";
		 end if;

			if(freq="0000") then
			null;
			else
				if (cnt = freq )  then--??êy?÷
					cnt <= "0000";
					freqout <= not freqout;--ê?3?è?·′<=>ê?3?·?2¨
				else
					cnt <= cnt + 1;
				end if;
			end if;
		end if;

  end process;
end architecture;
