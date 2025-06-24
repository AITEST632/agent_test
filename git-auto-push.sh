#!/bin/bash
# git-auto-push.sh: Automatically add, commit, and push all changes

git add .

if [ -z "$1" ]; then
    status=$(git diff --cached --name-status)
    msg_parts=()
    added=$(echo "$status" | awk '$1=="A"{print $2}')
    modified=$(echo "$status" | awk '$1=="M"{print $2}')
    deleted=$(echo "$status" | awk '$1=="D"{print $2}')
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

git commit -m "$commit_msg"
git push
