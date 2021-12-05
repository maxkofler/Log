if [ $# -ne 1 ]
then
	echo "Please specify either \"deploy\" or \"testing\""
	exit -1
else
	if [ $1 == "deploy" ]
	then	
		cp CMakeLists_Deploy.txt CMakeLists.txt
	elif [ $1 == "testing" ]
	then	
		cp CMakeLists_Testing.txt CMakeLists.txt
	else
		echo "Invalid option \"$1\", use either \"deploy\" or \"testing\""
	fi
fi