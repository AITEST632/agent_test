#!/bin/bash
# git-auto-push.sh: Automatically add, commit, and push all changes

if [ -z "$1" ]; then
    status=$(git status --porcelain)
    added=$(echo "$status" | awk '/^A /{print $2}')
    modified=$(echo "$status" | awk '/^ M|^M /{print $2}')
    deleted=$(echo "$status" | awk '/^ D|^D /{print $2}')
    msg_parts=()
    if [ -n "$added" ]; then
        msg_parts+=("Added: $(echo $added | tr '\n' ', ' | sed 's/, $//')")
    fi
    if [ -n "$modified" ]; then
        msg_parts+=("Modified: $(echo $modified | tr '\n' ', ' | sed 's/, $//')")
    fi
    if [ -n "$deleted" ]; then
        msg_parts+=("Deleted: $(echo $deleted | tr '\n' ', ' | sed 's/, $//')")
    fi
    if [ ${#msg_parts[@]} -eq 0 ]; then
        commit_msg="Update: no file changes detected"
    else
        commit_msg="$(IFS='; '; echo "${msg_parts[*]}")"
    fi
else
    commit_msg="$1"
fi

git add .
git commit -m "$commit_msg"
git push
