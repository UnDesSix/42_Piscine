#!/bin/sh
ifconfig | grep 'ether' | sed 's/ether//' | tr -d '\t' | tr -d ' '
