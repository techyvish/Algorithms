echo "Adding pre-commit script to sort project files and reformat source code to Git hooks"
rm -fr .git/hooks/pre-commit
ln -s ../../pre-commit.sh .git/hooks/pre-commit
echo "Done"