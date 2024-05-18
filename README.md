# CH559sdccUSBmouseHost

forked from https://github.com/atc1441/CH559sdccUSBHost

## Modification
1. main.c : boaud-rate: 57600
2. uart.c : custom output (mouse report) 0x80 BB XX YY VV HH

## Compile
compile.bat

## Flash
1. Short Download and Gnd, then connect to PC (converting USB male to female)
2. chflasher.exe CH559USB.bin
