ls -l | awk 'BEGIN { C = 0 } { if (C % 2) print $0; C = C + 1 }'
