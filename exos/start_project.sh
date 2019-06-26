#!/bin/sh

# Starting here:
PS3='What do you want to do?'
options=("Start a fresh new project" "Create a .gitignore file" "Add 42 git remote url" "Quit")
select opt in "${options[@]}"
do
    case $opt in
        "Start a fresh new project")
            echo "Ok, starting new project..."
            break
            ;;
        "Create a .gitignore file")
            echo "Here you go!"
            break
            ;;
        "Add 42 git remote url")
            echo "So you know Git huh^^"
            break
            ;;
        "Quit")
            break
            ;;
        *) echo "invalid option $REPLY";;
    esac
done

# Opt. 2: Create a .gitignore file
if [ $REPLY = 2 ]
then
    echo "Where do you want to create the file?" && read GITIGNORE_CREATION_PATH
	{
            echo "# OSX"
            echo ".DS_Store"
            echo "# VS Code"
            echo ".vscode/**/*"
            echo ".code-workspace"
            echo "# C files"
            echo "a.out"
            echo ".o"
            echo "# VIM"
            echo ".swp"
        } >${GITIGNORE_CREATION_PATH}.gitignore
fi

# Opt. 3: Add 42 git remote url
if [ $REPLY = 3 ]
then
    echo "Please set the remote url you want to set..." && read GIT_REMOTE_URL
    git remote add origin ${GIT_REMOTE_URL}
fi

# Opt. 1: Start a fresh new project
if [ $REPLY = 1 ]
then
    # Project folder creation
    echo "What is the name of the folder you want to create?" && read FOLDER_NAME
    echo "Creating the folder.."
    mkdir $FOLDER_NAME && cd $FOLDER_NAME
    echo "Folders created!"

    # Git

    # - Initialization
    echo "Do you want to initiate a git repository? (y/n)" && read CHOICE
    if [ $CHOICE = "y" ]
    then
        git init .
    fi

    # - Gitignore creation
    echo "Do you want to create a .gitignore (y/n)" && read CHOICE
    if [ $CHOICE = "y" ]
    then
        {
            echo "# OSX"
            echo ".DS_Store"
            echo "# VS Code"
            echo ".vscode/**/*"
            echo ".code-workspace"
            echo "# C files"
            echo "a.out"
            echo ".o"
            echo "# VIM"
            echo ".swp"
        } >.gitignore
    fi

    # Exercices folders creation
    echo "How much exercices folders do you want? (starting with a lead 0!)" && read FOLDERS_LEN
    echo "Do you want to start from \"00\"? (y/n)" && read CHOICE
    FOLDERS_START=00
    if [ $CHOICE = "n" ]
    then
        echo "From where do you want to start?" && read FOLDERS_START
    fi
    echo "Creating the folders..."
    for ((i = ${FOLDERS_START}; i <= ${FOLDERS_LEN}; i++));
    do
        mkdir "ex"$(printf %02d $i)
    done
    cd "ex"${FOLDERS_START}
    echo "Folders created!"
fi