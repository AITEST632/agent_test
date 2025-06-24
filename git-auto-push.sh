#!/bin/bash
# git-auto-push.sh: Automatically add, commit, and push all changes

if [ -z "$1" ]; then
    read -p "Enter commit message: " commit_msg
else
    commit_msg="$1"
fi

git add .
git commit -m "$commit_msg"
git push
