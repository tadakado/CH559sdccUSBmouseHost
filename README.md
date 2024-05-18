# CH559sdccUSBmouseHost

forked from https://github.com/atc1441/CH559sdccUSBHost

## Modification
main.c & uart.c
boaud-rate: 57600
custom output (mouse report) 0x80 BB XX YY VV HH

## Compile
compile.bat

## Flash
1. Short Download and Gnd, then connect to PC (converting USB male to female)
2. chflasher.exe CH559USB.bin
