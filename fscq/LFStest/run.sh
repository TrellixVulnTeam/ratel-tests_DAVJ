#!/bin/sh

make > /dev/null 2>&1
mkdir testdir > /dev/null 2>&1

rmdir testdir/* > /dev/null 2>&1
rm testdir/stat
echo stat > testdir/stat

echo "=== baseline smallfile ==="
./smallfile 1 1024 testdir

echo "\n\n\n"


rmdir testdir/* > /dev/null 2>&1
rm testdir/stat 
echo stat > testdir/stat

echo "=== baseline write1 ==="
./write1 testdir



echo "\n\n\n"

rmdir testdir/* > /dev/null 2>&1
rm testdir/stat 
echo stat > testdir/stat

echo "=== baseline largefile ==="
./largefile -f 1 -i 1 testdir

echo "\n\n\n"

