#!/bin/sh
sed /etc/passwd -e "/^\s*#/d" -ne "2~2p" | cut -d ":" -f1 | rev | sort -r | sed -n -e "$FT_LINE1, $FT_LINE2 p" | paste -sd, | sed -e "s/,/, /g" -e "s/$/./" | tr -d "\n"
