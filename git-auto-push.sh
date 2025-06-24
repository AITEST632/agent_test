#!/bin/bash
# git-auto-push.sh: Automatically add, commit, and push all changes

if [ -z "$1" ]; then
    # Auto-generate commit message based on changed files
    changed_files=$(git status --porcelain | awk '{print $2}' | xargs)
    if [ -z "$changed_files" ]; then
        commit_msg="Update: no file changes detected"
    else
        commit_msg="Update: modified $(echo $changed_files | tr ' ' ', ')"
    fi
else
    commit_msg="$1"
fi

git add .
git commit -m "$commit_msg"
git push
