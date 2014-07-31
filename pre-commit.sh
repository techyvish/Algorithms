
echo "Running pre-commit git hook ..."

sort_script_name="pysock/sock.py"
format_script_name="External/uncrustify/bin/uncrustify"

echo "Checking all Git Staged files ..."
git diff --name-only --staged | while read filename
do
	# echo "Checking: $filename"

	# Project file sorting.
	if [[ "$filename" =~ .*project.pbxproj.* ]]; then
		echo "Sorting project file $filename"
		python $sort_script_name "$filename"
		git add "$filename"
	fi

	# Exit if the file is in a directory we are not interested in. External projects for example.
	if [[ "$filename" = Pods/* 
		|| "$filename" = External/* ]]; then
		continue
	fi

	# Source code formatting.
	if [[ "$filename" = *.m || "$filename" = *.h ]]; then
		echo "Formatting source in $filename"
		$format_script_name -q -c .uncrustifyconfig --no-backup --replace "$filename"
		git add "$filename"
	fi

done

echo "Git hook finished."