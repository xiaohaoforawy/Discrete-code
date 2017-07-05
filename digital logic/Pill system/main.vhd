-- Copyright (C) 1991-2009 Altera Corporation
-- Your use of Altera Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Altera Program License 
-- Subscription Agreement, Altera MegaCore Function License 
-- Agreement, or other applicable license agreement, including, 
-- without limitation, that your use is for the sole purpose of 
-- programming logic devices manufactured by Altera and sold by 
-- Altera or its authorized distributors.  Please refer to the 
-- applicable agreement for further details.

-- PROGRAM		"Quartus II"
-- VERSION		"Version 9.1 Build 222 10/21/2009 SJ Full Version"
-- CREATED		"Sat Jul 01 16:53:00 2017"

LIBRARY ieee;
USE ieee.std_logic_1164.all; 

LIBRARY work;

ENTITY yaowan IS 
	PORT
	(
		clk1 :  IN  STD_LOGIC;
		clk10 :  IN  STD_LOGIC;
		qd :  IN  STD_LOGIC;
		K0 :  IN  STD_LOGIC;
		K6 :  IN  STD_LOGIC;
		K5 :  IN  STD_LOGIC;
		K4 :  IN  STD_LOGIC;
		K2 :  IN  STD_LOGIC;
		K1 :  IN  STD_LOGIC;
		clk100k :  IN  STD_LOGIC;
		G :  OUT  STD_LOGIC;
		A :  OUT  STD_LOGIC;
		B :  OUT  STD_LOGIC;
		C :  OUT  STD_LOGIC;
		D :  OUT  STD_LOGIC;
		E :  OUT  STD_LOGIC;
		F :  OUT  STD_LOGIC;
		G6A :  OUT  STD_LOGIC;
		G6B :  OUT  STD_LOGIC;
		G6C :  OUT  STD_LOGIC;
		G6D :  OUT  STD_LOGIC;
		G5A :  OUT  STD_LOGIC;
		G5B :  OUT  STD_LOGIC;
		G5C :  OUT  STD_LOGIC;
		G5D :  OUT  STD_LOGIC;
		G4A :  OUT  STD_LOGIC;
		G4B :  OUT  STD_LOGIC;
		G4C :  OUT  STD_LOGIC;
		G4D :  OUT  STD_LOGIC;
		G2A :  OUT  STD_LOGIC;
		G2B :  OUT  STD_LOGIC;
		G2D :  OUT  STD_LOGIC;
		G2C :  OUT  STD_LOGIC;
		final :  OUT  STD_LOGIC
	);
END yaowan;

ARCHITECTURE bdf_type OF yaowan IS 

COMPONENT to7
	PORT(DD : IN STD_LOGIC;
		 CC : IN STD_LOGIC;
		 BB : IN STD_LOGIC;
		 AA : IN STD_LOGIC;
		 a : OUT STD_LOGIC;
		 b : OUT STD_LOGIC;
		 c : OUT STD_LOGIC;
		 d : OUT STD_LOGIC;
		 e : OUT STD_LOGIC;
		 f : OUT STD_LOGIC;
		 g : OUT STD_LOGIC
	);
END COMPONENT;

COMPONENT music
	PORT(clk : IN STD_LOGIC;
		 en : IN STD_LOGIC;
		 aclk : IN STD_LOGIC;
		 choice : IN STD_LOGIC;
		 final : OUT STD_LOGIC
	);
END COMPONENT;

COMPONENT yima38
	PORT(C : IN STD_LOGIC;
		 B : IN STD_LOGIC;
		 A : IN STD_LOGIC;
		 y0 : OUT STD_LOGIC;
		 y1 : OUT STD_LOGIC;
		 y2 : OUT STD_LOGIC;
		 y3 : OUT STD_LOGIC;
		 y4 : OUT STD_LOGIC;
		 y5 : OUT STD_LOGIC;
		 y6 : OUT STD_LOGIC;
		 y7 : OUT STD_LOGIC
	);
END COMPONENT;

COMPONENT cnt10
	PORT(cin : IN STD_LOGIC;
		 set1 : IN STD_LOGIC;
		 en : IN STD_LOGIC;
		 mode1 : IN STD_LOGIC;
		 mode2 : IN STD_LOGIC;
		 reset : IN STD_LOGIC;
		 add : IN STD_LOGIC;
		 clk : IN STD_LOGIC;
		 cout : OUT STD_LOGIC;
		 A : OUT STD_LOGIC;
		 B : OUT STD_LOGIC;
		 C : OUT STD_LOGIC;
		 D : OUT STD_LOGIC;
		 jam : OUT STD_LOGIC
	);
END COMPONENT;

SIGNAL	SYNTHESIZED_WIRE_0 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_1 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_2 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_3 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_4 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_31 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_6 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_8 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_9 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_32 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_12 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_13 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_14 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_16 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_33 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_34 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_19 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_20 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_23 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_25 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_26 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_28 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_29 :  STD_LOGIC;


BEGIN 



b2v_inst : to7
PORT MAP(DD => SYNTHESIZED_WIRE_0,
		 CC => SYNTHESIZED_WIRE_1,
		 BB => SYNTHESIZED_WIRE_2,
		 AA => SYNTHESIZED_WIRE_3,
		 a => A,
		 b => B,
		 c => C,
		 d => D,
		 e => E,
		 f => F,
		 g => G);


b2v_inst1 : music
PORT MAP(clk => clk100k,
		 en => SYNTHESIZED_WIRE_4,
		 aclk => clk1,
		 choice => SYNTHESIZED_WIRE_31,
		 final => final);


b2v_inst10 : yima38
PORT MAP(C => K6,
		 B => K5,
		 A => K4,
		 y1 => SYNTHESIZED_WIRE_16,
		 y2 => SYNTHESIZED_WIRE_20,
		 y4 => SYNTHESIZED_WIRE_23,
		 y5 => SYNTHESIZED_WIRE_26,
		 y6 => SYNTHESIZED_WIRE_29);


SYNTHESIZED_WIRE_4 <= SYNTHESIZED_WIRE_6 OR SYNTHESIZED_WIRE_31;


SYNTHESIZED_WIRE_31 <= SYNTHESIZED_WIRE_8 AND SYNTHESIZED_WIRE_9;


SYNTHESIZED_WIRE_33 <= K0 AND SYNTHESIZED_WIRE_32;


SYNTHESIZED_WIRE_34 <= SYNTHESIZED_WIRE_31 OR qd;


SYNTHESIZED_WIRE_32 <= NOT(SYNTHESIZED_WIRE_12 AND SYNTHESIZED_WIRE_13 AND SYNTHESIZED_WIRE_14);


SYNTHESIZED_WIRE_6 <= NOT(SYNTHESIZED_WIRE_32);



b2v_inst5 : cnt10
PORT MAP(cin => clk1,
		 set1 => SYNTHESIZED_WIRE_16,
		 en => SYNTHESIZED_WIRE_33,
		 mode1 => K1,
		 mode2 => K2,
		 reset => SYNTHESIZED_WIRE_34,
		 add => qd,
		 clk => clk10,
		 cout => SYNTHESIZED_WIRE_19,
		 A => SYNTHESIZED_WIRE_3,
		 B => SYNTHESIZED_WIRE_2,
		 C => SYNTHESIZED_WIRE_1,
		 D => SYNTHESIZED_WIRE_0,
		 jam => SYNTHESIZED_WIRE_9);


b2v_inst6 : cnt10
PORT MAP(cin => SYNTHESIZED_WIRE_19,
		 set1 => SYNTHESIZED_WIRE_20,
		 en => SYNTHESIZED_WIRE_33,
		 mode1 => K1,
		 mode2 => K2,
		 reset => SYNTHESIZED_WIRE_34,
		 add => qd,
		 clk => clk10,
		 A => G2A,
		 B => G2B,
		 C => G2C,
		 D => G2D,
		 jam => SYNTHESIZED_WIRE_8);


b2v_inst7 : cnt10
PORT MAP(cin => clk1,
		 set1 => SYNTHESIZED_WIRE_23,
		 en => SYNTHESIZED_WIRE_33,
		 mode1 => K1,
		 mode2 => K2,
		 reset => qd,
		 add => qd,
		 clk => clk10,
		 cout => SYNTHESIZED_WIRE_25,
		 A => G4A,
		 B => G4B,
		 C => G4C,
		 D => G4D,
		 jam => SYNTHESIZED_WIRE_14);


b2v_inst8 : cnt10
PORT MAP(cin => SYNTHESIZED_WIRE_25,
		 set1 => SYNTHESIZED_WIRE_26,
		 en => SYNTHESIZED_WIRE_33,
		 mode1 => K1,
		 mode2 => K2,
		 reset => qd,
		 add => qd,
		 clk => clk10,
		 cout => SYNTHESIZED_WIRE_28,
		 A => G5A,
		 B => G5B,
		 C => G5C,
		 D => G5D,
		 jam => SYNTHESIZED_WIRE_13);


b2v_inst9 : cnt10
PORT MAP(cin => SYNTHESIZED_WIRE_28,
		 set1 => SYNTHESIZED_WIRE_29,
		 en => SYNTHESIZED_WIRE_33,
		 mode1 => K1,
		 mode2 => K2,
		 reset => qd,
		 add => qd,
		 clk => clk10,
		 A => G6A,
		 B => G6B,
		 C => G6C,
		 D => G6D,
		 jam => SYNTHESIZED_WIRE_12);


END bdf_type;
