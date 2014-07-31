echo "Adding project file sorting to Git hooks"
rm -fr .git/hooks/pre-commit
ln -s ../../sort-project-files.sh .git/hooks/pre-commit
echo "Done"