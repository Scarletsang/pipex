#!/bin/bash

if [[ ! -z "$1" ]]; then
  formatted_args="\"$1\""
  shift
  for arg in "$@"
  do
    formatted_args="$formatted_args, \"$arg\""
  done
fi

echo -e '\033[0;36m''[before change]'$(grep "\(\"args\": \[\).*\(\]\)" ./$(dirname ${BASH_SOURCE:-$0})/../.vscode/launch.json)'\033[0m'
sed -i '' "s/\(\"args\": \[\).*\(\]\)/\1$formatted_args\2/g" ./$(dirname ${BASH_SOURCE:-$0})/../.vscode/launch.json
echo -e '\033[0;36m''[after  change]'$(grep "\(\"args\": \[\).*\(\]\)" ./$(dirname ${BASH_SOURCE:-$0})/../.vscode/launch.json)'\033[0m'