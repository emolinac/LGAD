#!/bin/bash

# Script to comment the headers of the oscilloscope output
# Facilitates ROOT TNtuple obtention

DATA_LOCATION=${HOME}/Documents/LGAD/DATA_RAW/

echo "Data is located at $DATA_LOCATION"

cd $DATA_LOCATION

sed -i 's/LECROY/# LECROY/g' *.txt
sed -i 's/Segment/# Segment/g' *.txt
sed -i 's/Time/# Time/g' *.txt

