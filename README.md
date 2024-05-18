# CH559sdccUSBmouseHost

forked from https://github.com/atc1441/CH559sdccUSBHost

This is a part of [modulo keyboard project](https://github.com/tadakado/modulo)

## Modification
1. main.c : boaud-rate: 57600
2. uart.c : custom output (mouse report) 0x80 BB XX YY VV HH

## Compile
compile.bat

## Flash
1. Short Download and Gnd, then connect to PC (converting USB male to female)
2. chflasher.exe CH559USB.bin

## Support additional mouse
1. Identify mouse report format of your mouse. To investigate the format genuine CH559 output gives all information you need. Some mice format were analyzed and summarized in [the file](CH559_output_format.txt).
2. Modify uart.c
