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
-- CREATED		"Sun Jul 02 11:28:23 2017"

LIBRARY ieee;
USE ieee.std_logic_1164.all; 

LIBRARY work;

ENTITY test IS 
	PORT
	(
		clk :  IN  STD_LOGIC;
		set0 :  IN  STD_LOGIC;
		set2 :  IN  STD_LOGIC;
		qd :  IN  STD_LOGIC;
		pin_name :  IN  STD_LOGIC;
		clk100k :  IN  STD_LOGIC;
		K3 :  IN  STD_LOGIC;
		k10 :  IN  STD_LOGIC;
		k11 :  IN  STD_LOGIC;
		k12 :  IN  STD_LOGIC;
		k13 :  IN  STD_LOGIC;
		k14 :  IN  STD_LOGIC;
		k15 :  IN  STD_LOGIC;
		H1A :  OUT  STD_LOGIC;
		H1B :  OUT  STD_LOGIC;
		H1C :  OUT  STD_LOGIC;
		H1D :  OUT  STD_LOGIC;
		H2A :  OUT  STD_LOGIC;
		H2B :  OUT  STD_LOGIC;
		H2C :  OUT  STD_LOGIC;
		H2D :  OUT  STD_LOGIC;
		M1A :  OUT  STD_LOGIC;
		M1B :  OUT  STD_LOGIC;
		M1C :  OUT  STD_LOGIC;
		M1D :  OUT  STD_LOGIC;
		M2A :  OUT  STD_LOGIC;
		M2C :  OUT  STD_LOGIC;
		M2D :  OUT  STD_LOGIC;
		M2B :  OUT  STD_LOGIC;
		S1A :  OUT  STD_LOGIC;
		S1B :  OUT  STD_LOGIC;
		S1C :  OUT  STD_LOGIC;
		S1D :  OUT  STD_LOGIC;
		S2A :  OUT  STD_LOGIC;
		S2B :  OUT  STD_LOGIC;
		S2C :  OUT  STD_LOGIC;
		S2D :  OUT  STD_LOGIC;
		S2E :  OUT  STD_LOGIC;
		S2F :  OUT  STD_LOGIC;
		S2G :  OUT  STD_LOGIC;
		final :  OUT  STD_LOGIC
	);
END test;

ARCHITECTURE bdf_type OF test IS 

COMPONENT count10
	PORT(cin : IN STD_LOGIC;
		 reset : IN STD_LOGIC;
		 set0 : IN STD_LOGIC;
		 set1 : IN STD_LOGIC;
		 set2 : IN STD_LOGIC;
		 add : IN STD_LOGIC;
		 clk : IN STD_LOGIC;
		 set3 : IN STD_LOGIC;
		 cout : OUT STD_LOGIC;
		 A : OUT STD_LOGIC;
		 B : OUT STD_LOGIC;
		 C : OUT STD_LOGIC;
		 D : OUT STD_LOGIC;
		 timer : OUT STD_LOGIC
	);
END COMPONENT;

COMPONENT count2
	PORT(cin : IN STD_LOGIC;
		 reset : IN STD_LOGIC;
		 set0 : IN STD_LOGIC;
		 set1 : IN STD_LOGIC;
		 set2 : IN STD_LOGIC;
		 add : IN STD_LOGIC;
		 clk : IN STD_LOGIC;
		 set3 : IN STD_LOGIC;
		 A : OUT STD_LOGIC;
		 B : OUT STD_LOGIC;
		 timer : OUT STD_LOGIC
	);
END COMPONENT;

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

COMPONENT count6
	PORT(cin : IN STD_LOGIC;
		 reset : IN STD_LOGIC;
		 set0 : IN STD_LOGIC;
		 set1 : IN STD_LOGIC;
		 set2 : IN STD_LOGIC;
		 add : IN STD_LOGIC;
		 clk : IN STD_LOGIC;
		 set3 : IN STD_LOGIC;
		 cout : OUT STD_LOGIC;
		 A : OUT STD_LOGIC;
		 B : OUT STD_LOGIC;
		 C : OUT STD_LOGIC;
		 timer : OUT STD_LOGIC
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

COMPONENT tran6
	PORT(b : IN STD_LOGIC;
		 a1 : OUT STD_LOGIC;
		 a2 : OUT STD_LOGIC;
		 a3 : OUT STD_LOGIC;
		 a4 : OUT STD_LOGIC;
		 a5 : OUT STD_LOGIC;
		 a6 : OUT STD_LOGIC
	);
END COMPONENT;

SIGNAL	SYNTHESIZED_WIRE_0 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_1 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_2 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_28 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_4 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_5 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_6 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_7 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_8 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_9 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_10 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_11 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_12 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_13 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_14 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_29 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_17 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_18 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_20 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_21 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_22 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_23 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_24 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_25 :  STD_LOGIC;
SIGNAL	SYNTHESIZED_WIRE_26 :  STD_LOGIC;


BEGIN 
H1C <= pin_name;
H1D <= pin_name;
M1D <= pin_name;
S1D <= pin_name;
H1B <= SYNTHESIZED_WIRE_0;
H2C <= SYNTHESIZED_WIRE_1;



b2v_inst : count10
PORT MAP(cin => clk,
		 reset => qd,
		 set0 => set0,
		 set1 => k10,
		 set2 => set2,
		 add => qd,
		 clk => clk,
		 cout => SYNTHESIZED_WIRE_9,
		 A => SYNTHESIZED_WIRE_8,
		 B => SYNTHESIZED_WIRE_7,
		 C => SYNTHESIZED_WIRE_6,
		 D => SYNTHESIZED_WIRE_5,
		 timer => SYNTHESIZED_WIRE_21);


SYNTHESIZED_WIRE_14 <= SYNTHESIZED_WIRE_0 AND SYNTHESIZED_WIRE_1;


b2v_inst10 : count2
PORT MAP(cin => SYNTHESIZED_WIRE_2,
		 reset => SYNTHESIZED_WIRE_28,
		 set0 => set0,
		 set1 => k15,
		 set2 => set2,
		 add => qd,
		 clk => clk,
		 set3 => SYNTHESIZED_WIRE_4,
		 A => H1A,
		 B => SYNTHESIZED_WIRE_0,
		 timer => SYNTHESIZED_WIRE_25);


b2v_inst16 : to7
PORT MAP(DD => SYNTHESIZED_WIRE_5,
		 CC => SYNTHESIZED_WIRE_6,
		 BB => SYNTHESIZED_WIRE_7,
		 AA => SYNTHESIZED_WIRE_8,
		 a => S2A,
		 b => S2B,
		 c => S2C,
		 d => S2D,
		 e => S2E,
		 f => S2F,
		 g => S2G);


b2v_inst17 : count6
PORT MAP(cin => SYNTHESIZED_WIRE_9,
		 reset => qd,
		 set0 => set0,
		 set1 => k11,
		 set2 => set2,
		 add => qd,
		 clk => clk,
		 cout => SYNTHESIZED_WIRE_10,
		 A => S1A,
		 B => S1B,
		 C => S1C,
		 timer => SYNTHESIZED_WIRE_22);


b2v_inst18 : count10
PORT MAP(cin => SYNTHESIZED_WIRE_10,
		 reset => qd,
		 set0 => set0,
		 set1 => k12,
		 set2 => set2,
		 add => qd,
		 clk => clk,
		 set3 => SYNTHESIZED_WIRE_11,
		 cout => SYNTHESIZED_WIRE_12,
		 A => M2A,
		 B => M2B,
		 C => M2C,
		 D => M2D,
		 timer => SYNTHESIZED_WIRE_20);


b2v_inst19 : count6
PORT MAP(cin => SYNTHESIZED_WIRE_12,
		 reset => qd,
		 set0 => set0,
		 set1 => k13,
		 set2 => set2,
		 add => qd,
		 clk => clk,
		 set3 => SYNTHESIZED_WIRE_13,
		 cout => SYNTHESIZED_WIRE_29,
		 A => M1A,
		 B => M1B,
		 C => M1C,
		 timer => SYNTHESIZED_WIRE_23);


SYNTHESIZED_WIRE_28 <= SYNTHESIZED_WIRE_14 OR qd;


b2v_inst21 : count10
PORT MAP(cin => SYNTHESIZED_WIRE_29,
		 reset => SYNTHESIZED_WIRE_28,
		 set0 => set0,
		 set1 => k14,
		 set2 => set2,
		 add => qd,
		 clk => clk,
		 set3 => SYNTHESIZED_WIRE_17,
		 cout => SYNTHESIZED_WIRE_2,
		 A => H2A,
		 B => H2B,
		 C => SYNTHESIZED_WIRE_1,
		 D => H2D,
		 timer => SYNTHESIZED_WIRE_24);


b2v_inst3 : music
PORT MAP(clk => clk100k,
		 en => SYNTHESIZED_WIRE_18,
		 aclk => clk,
		 choice => SYNTHESIZED_WIRE_29,
		 final => final);


SYNTHESIZED_WIRE_26 <= SYNTHESIZED_WIRE_20 AND SYNTHESIZED_WIRE_21 AND SYNTHESIZED_WIRE_22 AND SYNTHESIZED_WIRE_23 AND SYNTHESIZED_WIRE_24 AND SYNTHESIZED_WIRE_25;


SYNTHESIZED_WIRE_18 <= SYNTHESIZED_WIRE_26 OR SYNTHESIZED_WIRE_29;


b2v_inst7 : tran6
PORT MAP(b => K3,
		 a3 => SYNTHESIZED_WIRE_11,
		 a4 => SYNTHESIZED_WIRE_13,
		 a5 => SYNTHESIZED_WIRE_17,
		 a6 => SYNTHESIZED_WIRE_4);


END bdf_type;
