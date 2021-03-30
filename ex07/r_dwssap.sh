sed /etc/passwd -e "/^\s*#/d" | awk "BEGIN { C = 0 } { if (C % 2) print $1; C = C + 1}" | cut -d ":" -f1 | rev | sort -r | sed -n "$FT_LINE1, $FT_LINE2 p" | paste -sd, | tr -d "\n"
