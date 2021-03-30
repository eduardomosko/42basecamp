ls -l | awk 'BEGIN { C = 1 } { if (C % 2) print $0; C = C + 1 }'
