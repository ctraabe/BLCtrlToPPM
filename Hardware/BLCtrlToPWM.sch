EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:mikrokopter
LIBS:BLCtrlToPWM
LIBS:BLCtrlToPWM-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ATMEGA2560-A IC1
U 1 1 5635F722
P 3150 4050
F 0 "IC1" H 2000 6850 40  0000 L BNN
F 1 "ATMEGA2560-A" H 3850 1200 40  0000 L BNN
F 2 "Housings_QFP:TQFP-100_14x14mm_Pitch0.5mm" H 3150 4050 30  0000 C CIN
F 3 "" H 3150 4050 60  0000 C CNN
	1    3150 4050
	1    0    0    -1  
$EndComp
$Comp
L Crystal Y1
U 1 1 5635F7D4
P 1400 1900
F 0 "Y1" H 1400 2050 50  0000 C CNN
F 1 "16MHz" H 1400 1750 50  0000 C CNN
F 2 "Crystals:Crystal_HC49-SD_SMD" H 1400 1900 60  0001 C CNN
F 3 "" H 1400 1900 60  0000 C CNN
	1    1400 1900
	0    1    1    0   
$EndComp
$Comp
L CP1_Small C1
U 1 1 5635F98C
P 1050 1750
F 0 "C1" H 1060 1820 50  0000 L CNN
F 1 "27p" V 950 1600 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 1050 1750 60  0001 C CNN
F 3 "" H 1050 1750 60  0000 C CNN
	1    1050 1750
	0    1    1    0   
$EndComp
$Comp
L CP1_Small C2
U 1 1 5635F9E9
P 1050 2050
F 0 "C2" H 1060 2120 50  0000 L CNN
F 1 "27p" V 1200 1900 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 1050 2050 60  0001 C CNN
F 3 "" H 1050 2050 60  0000 C CNN
	1    1050 2050
	0    1    1    0   
$EndComp
$Comp
L Earth #PWR01
U 1 1 563604FA
P 800 2150
F 0 "#PWR01" H 800 1900 50  0001 C CNN
F 1 "Earth" H 800 2000 50  0001 C CNN
F 2 "" H 800 2150 60  0000 C CNN
F 3 "" H 800 2150 60  0000 C CNN
	1    800  2150
	1    0    0    -1  
$EndComp
$Comp
L Earth #PWR02
U 1 1 56360578
P 3150 7150
F 0 "#PWR02" H 3150 6900 50  0001 C CNN
F 1 "Earth" H 3150 7000 50  0001 C CNN
F 2 "" H 3150 7150 60  0000 C CNN
F 3 "" H 3150 7150 60  0000 C CNN
	1    3150 7150
	1    0    0    -1  
$EndComp
$Comp
L MKISP SV1
U 1 1 56360786
P 5700 2600
F 0 "SV1" H 5700 2650 60  0000 C CNN
F 1 "MKISP" H 5700 2550 60  0000 C CNN
F 2 "Pin_Headers_Edge:Pin_Header_Edge_2x03" H 5700 2600 60  0001 C CNN
F 3 "" H 5700 2600 60  0000 C CNN
	1    5700 2600
	1    0    0    -1  
$EndComp
$Comp
L FltCtrl SV2
U 1 1 563607EC
P 5700 4850
F 0 "SV2" H 5700 4900 60  0000 C CNN
F 1 "FltCtrl" H 5700 4800 60  0000 C CNN
F 2 "Pin_Headers_Edge:Pin_Header_Edge_2x05" H 5700 4850 60  0001 C CNN
F 3 "" H 5700 4850 60  0000 C CNN
	1    5700 4850
	1    0    0    -1  
$EndComp
$Comp
L LED D3
U 1 1 56360901
P 6400 1200
F 0 "D3" H 6400 1300 50  0000 C CNN
F 1 "RED" H 6400 1100 50  0000 C CNN
F 2 "LEDs:LED-0805" H 6400 1200 60  0001 C CNN
F 3 "" H 6400 1200 60  0000 C CNN
	1    6400 1200
	0    -1   -1   0   
$EndComp
$Comp
L LED D1
U 1 1 56360A2B
P 8100 5800
F 0 "D1" H 8100 5900 50  0000 C CNN
F 1 "RX" H 8100 5700 50  0000 C CNN
F 2 "LEDs:LED-0805" H 8100 5800 60  0001 C CNN
F 3 "" H 8100 5800 60  0000 C CNN
	1    8100 5800
	1    0    0    -1  
$EndComp
$Comp
L LED D4
U 1 1 56360A6F
P 8500 5650
F 0 "D4" H 8500 5750 50  0000 C CNN
F 1 "GREEN" H 8500 5550 50  0000 C CNN
F 2 "LEDs:LED-0805" H 8500 5650 60  0001 C CNN
F 3 "" H 8500 5650 60  0000 C CNN
	1    8500 5650
	1    0    0    -1  
$EndComp
$Comp
L LED D5
U 1 1 56360AB0
P 8500 5950
F 0 "D5" H 8500 6050 50  0000 C CNN
F 1 "TX" H 8500 5850 50  0000 C CNN
F 2 "LEDs:LED-0805" H 8500 5950 60  0001 C CNN
F 3 "" H 8500 5950 60  0000 C CNN
	1    8500 5950
	1    0    0    -1  
$EndComp
$Comp
L ESC_GND GND1
U 1 1 563612FD
P 8850 4650
F 0 "GND1" H 8850 4700 60  0000 C CNN
F 1 "ESC_GND" H 8850 4600 60  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x08" H 8850 4650 60  0001 C CNN
F 3 "" H 8850 4650 60  0000 C CNN
	1    8850 4650
	1    0    0    -1  
$EndComp
$Comp
L ESC_PWM PWM1
U 1 1 5636134C
P 8850 1500
F 0 "PWM1" H 8850 1550 60  0000 C CNN
F 1 "ESC_PWM" H 8850 1450 60  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x08" H 8850 1500 60  0001 C CNN
F 3 "" H 8850 1500 60  0000 C CNN
	1    8850 1500
	1    0    0    -1  
$EndComp
$Comp
L ESC_PWR PWR1
U 1 1 5636143F
P 8850 3050
F 0 "PWR1" H 8850 3100 60  0000 C CNN
F 1 "ESC_PWR" H 8850 3000 60  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x08" H 8850 3050 60  0001 C CNN
F 3 "" H 8850 3050 60  0000 C CNN
	1    8850 3050
	1    0    0    -1  
$EndComp
$Comp
L C C4
U 1 1 56361996
P 5200 1200
F 0 "C4" H 5225 1300 50  0000 L CNN
F 1 "100n" H 5225 1100 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 5238 1050 30  0001 C CNN
F 3 "" H 5200 1200 60  0000 C CNN
	1    5200 1200
	1    0    0    -1  
$EndComp
$Comp
L C C5
U 1 1 56361A23
P 5550 1200
F 0 "C5" H 5575 1300 50  0000 L CNN
F 1 "100n" H 5575 1100 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 5588 1050 30  0001 C CNN
F 3 "" H 5550 1200 60  0000 C CNN
	1    5550 1200
	1    0    0    -1  
$EndComp
$Comp
L C C6
U 1 1 56361A94
P 5900 1200
F 0 "C6" H 5925 1300 50  0000 L CNN
F 1 "100n" H 5925 1100 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 5938 1050 30  0001 C CNN
F 3 "" H 5900 1200 60  0000 C CNN
	1    5900 1200
	1    0    0    -1  
$EndComp
$Comp
L C C3
U 1 1 56361AF2
P 1650 6850
F 0 "C3" H 1675 6950 50  0000 L CNN
F 1 "100n" H 1675 6750 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 1688 6700 30  0001 C CNN
F 3 "" H 1650 6850 60  0000 C CNN
	1    1650 6850
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR03
U 1 1 5636356F
P 6600 3700
F 0 "#PWR03" H 6600 3550 50  0001 C CNN
F 1 "+5V" H 6600 3840 50  0000 C CNN
F 2 "" H 6600 3700 60  0000 C CNN
F 3 "" H 6600 3700 60  0000 C CNN
	1    6600 3700
	1    0    0    -1  
$EndComp
$Comp
L Earth #PWR04
U 1 1 56363646
P 6550 2800
F 0 "#PWR04" H 6550 2550 50  0001 C CNN
F 1 "Earth" H 6550 2650 50  0001 C CNN
F 2 "" H 6550 2800 60  0000 C CNN
F 3 "" H 6550 2800 60  0000 C CNN
	1    6550 2800
	1    0    0    -1  
$EndComp
Text Label 4750 5350 2    60   ~ 0
PWM1
Text Label 4750 5450 2    60   ~ 0
PWM2
Text Label 4750 5550 2    60   ~ 0
PWM3
$Comp
L Earth #PWR05
U 1 1 563656A9
P 4850 5200
F 0 "#PWR05" H 4850 4950 50  0001 C CNN
F 1 "Earth" H 4850 5050 50  0001 C CNN
F 2 "" H 4850 5200 60  0000 C CNN
F 3 "" H 4850 5200 60  0000 C CNN
	1    4850 5200
	1    0    0    -1  
$EndComp
$Comp
L Earth #PWR06
U 1 1 563664B0
P 5900 1500
F 0 "#PWR06" H 5900 1250 50  0001 C CNN
F 1 "Earth" H 5900 1350 50  0001 C CNN
F 2 "" H 5900 1500 60  0000 C CNN
F 3 "" H 5900 1500 60  0000 C CNN
	1    5900 1500
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR07
U 1 1 56366500
P 5900 900
F 0 "#PWR07" H 5900 750 50  0001 C CNN
F 1 "+5V" H 5900 1040 50  0000 C CNN
F 2 "" H 5900 900 60  0000 C CNN
F 3 "" H 5900 900 60  0000 C CNN
	1    5900 900 
	1    0    0    -1  
$EndComp
Text Label 1550 5350 0    60   ~ 0
PWM4
Text Label 1550 5450 0    60   ~ 0
PWM5
Text Label 1550 5550 0    60   ~ 0
PWM6
Text Label 4750 2850 2    60   ~ 0
PWM7
Text Label 4750 2950 2    60   ~ 0
PWM8
Text Label 1350 1450 0    60   ~ 0
RESET
Text Label 6900 2450 2    60   ~ 0
RESET
$Comp
L R R7
U 1 1 56367E1A
P 6150 950
F 0 "R7" V 6230 950 50  0000 C CNN
F 1 "1k" V 6150 950 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6080 950 30  0001 C CNN
F 3 "" H 6150 950 30  0000 C CNN
	1    6150 950 
	0    1    1    0   
$EndComp
$Comp
L R R2
U 1 1 5636885F
P 8750 5800
F 0 "R2" V 8830 5800 50  0000 C CNN
F 1 "1k" V 8750 5800 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 8680 5800 30  0001 C CNN
F 3 "" H 8750 5800 30  0000 C CNN
	1    8750 5800
	0    1    1    0   
$EndComp
$Comp
L R R4
U 1 1 56368EC8
P 9000 5650
F 0 "R4" V 9080 5650 50  0000 C CNN
F 1 "1k" V 9000 5650 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 8930 5650 30  0001 C CNN
F 3 "" H 9000 5650 30  0000 C CNN
	1    9000 5650
	0    1    1    0   
$EndComp
$Comp
L R R5
U 1 1 56368F3C
P 9000 5950
F 0 "R5" V 9080 5950 50  0000 C CNN
F 1 "1k" V 9000 5950 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 8930 5950 30  0001 C CNN
F 3 "" H 9000 5950 30  0000 C CNN
	1    9000 5950
	0    1    1    0   
$EndComp
$Comp
L R R3
U 1 1 56368F99
P 8750 6100
F 0 "R3" V 8830 6100 50  0000 C CNN
F 1 "1k" V 8750 6100 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 8680 6100 30  0001 C CNN
F 3 "" H 8750 6100 30  0000 C CNN
	1    8750 6100
	0    1    1    0   
$EndComp
$Comp
L R R6
U 1 1 5636927D
P 9000 6250
F 0 "R6" V 9080 6250 50  0000 C CNN
F 1 "1k" V 9000 6250 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 8930 6250 30  0001 C CNN
F 3 "" H 9000 6250 30  0000 C CNN
	1    9000 6250
	0    1    1    0   
$EndComp
$Comp
L LED D2
U 1 1 56369996
P 8100 6100
F 0 "D2" H 8100 6200 50  0000 C CNN
F 1 "BLUE1" H 8100 6000 50  0000 C CNN
F 2 "LEDs:LED-0805" H 8100 6100 60  0001 C CNN
F 3 "" H 8100 6100 60  0000 C CNN
	1    8100 6100
	1    0    0    -1  
$EndComp
$Comp
L LED D6
U 1 1 563699FA
P 8500 6250
F 0 "D6" H 8500 6350 50  0000 C CNN
F 1 "BLUE2" H 8500 6150 50  0000 C CNN
F 2 "LEDs:LED-0805" H 8500 6250 60  0001 C CNN
F 3 "" H 8500 6250 60  0000 C CNN
	1    8500 6250
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 5636A8D0
P 1750 1200
F 0 "R1" V 1830 1200 50  0000 C CNN
F 1 "10k" V 1750 1200 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 1680 1200 30  0001 C CNN
F 3 "" H 1750 1200 30  0000 C CNN
	1    1750 1200
	-1   0    0    1   
$EndComp
Text Label 7800 1000 0    60   ~ 0
PWM1
Text Label 7800 1150 0    60   ~ 0
PWM2
Text Label 7800 1300 0    60   ~ 0
PWM3
Text Label 7800 1450 0    60   ~ 0
PWM4
Text Label 7800 1600 0    60   ~ 0
PWM5
Text Label 7800 1750 0    60   ~ 0
PWM6
Text Label 7800 1900 0    60   ~ 0
PWM7
Text Label 7800 2050 0    60   ~ 0
PWM8
$Comp
L Earth #PWR08
U 1 1 5636F5CD
P 8000 5250
F 0 "#PWR08" H 8000 5000 50  0001 C CNN
F 1 "Earth" H 8000 5100 50  0001 C CNN
F 2 "" H 8000 5250 60  0000 C CNN
F 3 "" H 8000 5250 60  0000 C CNN
	1    8000 5250
	1    0    0    -1  
$EndComp
$Comp
L R R9
U 1 1 563706DE
P 6350 3950
F 0 "R9" V 6430 3950 50  0000 C CNN
F 1 "10k" V 6350 3950 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6280 3950 30  0001 C CNN
F 3 "" H 6350 3950 30  0000 C CNN
	1    6350 3950
	-1   0    0    1   
$EndComp
$Comp
L R R10
U 1 1 563708BD
P 6600 3950
F 0 "R10" V 6680 3950 50  0000 C CNN
F 1 "10k" V 6600 3950 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6530 3950 30  0001 C CNN
F 3 "" H 6600 3950 30  0000 C CNN
	1    6600 3950
	-1   0    0    1   
$EndComp
Wire Wire Line
	1150 1750 1850 1750
Connection ~ 1400 1750
Wire Wire Line
	1150 2050 1850 2050
Connection ~ 1400 2050
Wire Wire Line
	800  2050 950  2050
Wire Wire Line
	800  1750 800  2150
Connection ~ 800  2050
Wire Wire Line
	3100 7050 3100 6950
Wire Wire Line
	1650 7050 3300 7050
Wire Wire Line
	3200 7050 3200 6950
Wire Wire Line
	3150 7050 3150 7150
Connection ~ 3150 7050
Wire Wire Line
	3300 7050 3300 6950
Connection ~ 3200 7050
Wire Wire Line
	3000 6950 3000 7050
Connection ~ 3100 7050
Wire Wire Line
	4450 2450 4950 2450
Wire Wire Line
	4950 2750 4550 2750
Wire Wire Line
	4550 2750 4550 2550
Wire Wire Line
	4550 2550 4450 2550
Wire Wire Line
	5900 1350 5900 1500
Wire Wire Line
	4850 1450 6400 1450
Wire Wire Line
	5550 1450 5550 1350
Connection ~ 5900 1450
Wire Wire Line
	5200 1450 5200 1350
Connection ~ 5550 1450
Wire Wire Line
	5900 900  5900 1050
Wire Wire Line
	1750 950  6000 950 
Wire Wire Line
	5550 950  5550 1050
Wire Wire Line
	5200 950  5200 1050
Connection ~ 5550 950 
Wire Wire Line
	3300 950  3300 1150
Connection ~ 5200 950 
Wire Wire Line
	3000 950  3000 1150
Connection ~ 3300 950 
Wire Wire Line
	2900 950  2900 1150
Connection ~ 3000 950 
Wire Wire Line
	2800 950  2800 1150
Connection ~ 2900 950 
Connection ~ 5900 950 
Wire Wire Line
	1850 6650 1650 6650
Wire Wire Line
	1650 7050 1650 7000
Connection ~ 3000 7050
Wire Wire Line
	1650 6650 1650 6700
Wire Wire Line
	6400 950  6400 1000
Wire Wire Line
	6400 1450 6400 1400
Wire Wire Line
	6450 2600 6550 2600
Wire Wire Line
	6450 2750 6550 2750
Wire Wire Line
	6550 2750 6550 2800
Wire Wire Line
	4450 5350 4750 5350
Wire Wire Line
	4450 5450 4750 5450
Wire Wire Line
	4450 5550 4750 5550
Wire Wire Line
	4950 4550 4550 4550
Wire Wire Line
	4550 4550 4550 5150
Wire Wire Line
	4550 5150 4450 5150
Wire Wire Line
	6550 4700 6550 4350
Wire Wire Line
	6550 4350 4450 4350
Wire Wire Line
	6650 4250 6650 5000
Wire Wire Line
	4450 4250 6650 4250
Wire Wire Line
	6750 4150 6750 5150
Wire Wire Line
	4450 4150 6750 4150
Wire Wire Line
	4950 5150 4650 5150
Wire Wire Line
	4650 5150 4650 5050
Wire Wire Line
	4650 5050 4450 5050
Wire Wire Line
	4950 4700 4650 4700
Wire Wire Line
	4650 4700 4650 4450
Wire Wire Line
	4650 4450 4450 4450
Wire Wire Line
	6750 5150 6450 5150
Wire Wire Line
	6650 5000 6450 5000
Wire Wire Line
	6550 4700 6450 4700
Wire Wire Line
	4950 5000 4850 5000
Wire Wire Line
	4850 5000 4850 5200
Wire Wire Line
	1850 5350 1550 5350
Wire Wire Line
	1850 5450 1550 5450
Wire Wire Line
	1850 5550 1550 5550
Wire Wire Line
	4950 2600 4650 2600
Wire Wire Line
	4650 2600 4650 2650
Wire Wire Line
	4650 2650 4450 2650
Wire Wire Line
	4450 2850 4750 2850
Wire Wire Line
	4450 2950 4750 2950
Wire Wire Line
	6850 4550 6450 4550
Wire Wire Line
	1350 1450 1850 1450
Wire Wire Line
	6450 2450 6900 2450
Wire Wire Line
	6400 950  6300 950 
Wire Wire Line
	1750 950  1750 1050
Connection ~ 2800 950 
Wire Wire Line
	1750 1350 1750 1450
Connection ~ 1750 1450
Wire Wire Line
	8100 1000 7800 1000
Wire Wire Line
	8100 1150 7800 1150
Wire Wire Line
	8100 1300 7800 1300
Wire Wire Line
	8100 1450 7800 1450
Wire Wire Line
	8100 1600 7800 1600
Wire Wire Line
	8100 1750 7800 1750
Wire Wire Line
	8100 1900 7800 1900
Wire Wire Line
	8100 2050 7800 2050
Wire Wire Line
	8100 4150 8000 4150
Wire Wire Line
	8100 4300 8000 4300
Wire Wire Line
	8000 4450 8100 4450
Wire Wire Line
	8000 4600 8100 4600
Wire Wire Line
	8000 4750 8100 4750
Wire Wire Line
	8000 4900 8100 4900
Wire Wire Line
	8000 5050 8100 5050
Wire Wire Line
	8000 5200 8100 5200
Wire Wire Line
	8000 4150 8000 5250
Connection ~ 8000 4300
Connection ~ 8000 4450
Connection ~ 8000 4600
Connection ~ 8000 4750
Connection ~ 8000 4900
Connection ~ 8000 5050
Connection ~ 8000 5200
Wire Wire Line
	6600 4150 6600 4100
Connection ~ 6600 4150
Wire Wire Line
	6600 3700 6600 3800
Connection ~ 6600 3750
$Comp
L CP C7
U 1 1 56371507
P 4850 1200
F 0 "C7" H 4875 1300 50  0000 L CNN
F 1 "10u" H 4875 1100 50  0000 L CNN
F 2 "Capacitors_SMD:C_1210_HandSoldering" H 4888 1050 30  0001 C CNN
F 3 "" H 4850 1200 60  0000 C CNN
	1    4850 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 1050 4850 950 
Connection ~ 4850 950 
Wire Wire Line
	4850 1350 4850 1450
Connection ~ 5200 1450
$Comp
L R R8
U 1 1 56371A1B
P 1750 1900
F 0 "R8" V 1830 1900 50  0000 C CNN
F 1 "1M" V 1750 1900 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 1680 1900 30  0001 C CNN
F 3 "" H 1750 1900 30  0000 C CNN
	1    1750 1900
	-1   0    0    1   
$EndComp
Wire Wire Line
	800  1750 950  1750
Connection ~ 1750 2050
Connection ~ 1750 1750
Wire Wire Line
	6350 4100 6350 4250
Connection ~ 6350 4250
Wire Wire Line
	6350 3800 6350 3750
Wire Wire Line
	6350 3750 6850 3750
Wire Wire Line
	6850 3750 6850 4550
Wire Wire Line
	7800 5650 7800 6300
Connection ~ 7800 5800
Connection ~ 7800 5950
Connection ~ 7800 6100
Wire Wire Line
	9150 5650 9650 5650
Wire Wire Line
	8900 5800 9650 5800
Wire Wire Line
	9150 5950 9650 5950
Wire Wire Line
	8900 6100 9650 6100
Wire Wire Line
	9150 6250 9650 6250
Text Label 9650 5650 2    60   ~ 0
GREEN_LED
Text Label 9650 5800 2    60   ~ 0
RX_LED
Text Label 9650 5950 2    60   ~ 0
TX_LED
Text Label 9650 6100 2    60   ~ 0
BLUE1_LED
Text Label 9650 6250 2    60   ~ 0
BLUE2_LED
$Comp
L +5V #PWR09
U 1 1 5637AC80
P 6550 2350
F 0 "#PWR09" H 6550 2200 50  0001 C CNN
F 1 "+5V" H 6550 2490 50  0000 C CNN
F 2 "" H 6550 2350 60  0000 C CNN
F 3 "" H 6550 2350 60  0000 C CNN
	1    6550 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 2600 6550 2350
$Comp
L Earth #PWR010
U 1 1 5638C101
P 7800 6300
F 0 "#PWR010" H 7800 6050 50  0001 C CNN
F 1 "Earth" H 7800 6150 50  0001 C CNN
F 2 "" H 7800 6300 60  0000 C CNN
F 3 "" H 7800 6300 60  0000 C CNN
	1    7800 6300
	1    0    0    -1  
$EndComp
Connection ~ 7800 6250
Wire Wire Line
	8700 5950 8850 5950
Wire Wire Line
	8700 5650 8850 5650
Wire Wire Line
	8600 5800 8300 5800
Wire Wire Line
	8300 6100 8600 6100
Wire Wire Line
	8700 6250 8850 6250
Wire Wire Line
	8300 6250 7800 6250
Wire Wire Line
	8300 5650 7800 5650
Wire Wire Line
	7900 5800 7800 5800
Wire Wire Line
	8300 5950 7800 5950
Wire Wire Line
	7900 6100 7800 6100
Text Label 1300 6250 0    60   ~ 0
BLUE1_LED
Wire Wire Line
	1850 6250 1300 6250
Wire Wire Line
	1850 6350 1300 6350
Text Label 1300 6350 0    60   ~ 0
BLUE2_LED
Text Label 5000 6450 2    60   ~ 0
TX_LED
Text Label 5000 6550 2    60   ~ 0
RX_LED
Text Label 5000 6650 2    60   ~ 0
GREEN_LED
Wire Wire Line
	4450 6650 5000 6650
Wire Wire Line
	5000 6550 4450 6550
Wire Wire Line
	4450 6450 5000 6450
$EndSCHEMATC
