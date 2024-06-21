#!/usr/bin/python3
import sys
import signal
import re

def print_stats(total_size, status_counts):
    """ Print the accumulated statistics
    """
    print("File size: {}".format(total_size))
    for status_code in sorted(status_counts.keys()):
        if status_counts[status_code] > 0:
            print("{}: {}".format(status_code, status_counts[status_code]))

count = 0
total_size = 0
status_counts = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0
}
pattern = r'<IP Address> - \[.+\] "GET /projects/260 HTTP/1.1" \d{3} \d+'

def signal_handler(sig, frame):
    """ Handle the keyboard interruption signal
    """
    print_stats(total_size, status_counts)
    sys.exit(0)

signal.signal(signal.SIGINT, signal_handler)

for line in sys.stdin:
    check_line = line.strip()
    if not re.search(pattern, check_line):
        continue
    count += 1
    parts = line.split()

    if len(parts) < 9:
        continue

    status = parts[-2]
    file_size = parts[-1]

    try:
        file_size = int(file_size)
        total_size += file_size
    except ValueError:
        continue

    if status in status_counts:
        status_counts[status] += 1

    if count % 10 == 0:
        print_stats(total_size, status_counts)

print_stats(total_size, status_counts)
