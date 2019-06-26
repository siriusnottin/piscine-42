#!/bin/sh

# NOT TESTED YET!

# This script will create a folder named drafts, copy all folders
# recursivly from render/ and delete all .git and .gitignore files

mkdir -p drafts/
cd render/
cp -R */ ../drafts/
cd drafts/
rm -r .git .gitignore .DS_Store