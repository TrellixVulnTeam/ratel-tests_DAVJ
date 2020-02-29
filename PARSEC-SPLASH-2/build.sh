#!/bin/bash 

TOPDIR="apps"
OBJDIR="src"
RUNDIR="run"
OPTION1="make"
OPTION2="clean"

if [ "$OPTION1" == "$1" ]; then
    for obj in $(find ./$TOPDIR/ -maxdepth 1 -mindepth 1 -print)
	do
		echo "obj ---> "$obj

		objname=`echo $obj | awk -F "/" '{print $NF}'`
		make -C ./$obj/$OBJDIR && cp $obj/$OBJDIR/$objname $obj/$RUNDIR/$objname
	done

	echo "All build finished"
	exit
fi

if [ "$OPTION2" == "$1" ]; then
	for obj in $(find ./$TOPDIR/ -maxdepth 1 -mindepth 1 -print)
	do
		echo "obj ---> "$obj

		objname=`echo $obj | awk -F "/" '{print $NF}'`
		make -C ./$obj/$OBJDIR clean && rm $obj/$RUNDIR/$objname
	done

	echo "All clean finished"
	exit
fi

echo "please type the right parameter to build!"
echo "$0 [option]";
echo "		make		to build all individual benchmarks into shared objects;";
echo "		clean		to clean all generated files.";
exit;