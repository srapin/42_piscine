ls -l | awk -NF==%2 'NR%2 {print}'

