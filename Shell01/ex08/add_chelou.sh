#!/bin/sh
X=`echo ${FT_NBR1} | sed 'y/'\''\\"?!/01234/'`
Y=`echo ${FT_NBR2} | sed 'y/mrdoc/01234/'`
Z=`echo "ibase=5;${X}+${Y}" | bc`
echo "obase=13;${Z}" | bc | sed 'y/0123456789ABC/gtaio luSnemf/'
