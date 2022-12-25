#!/bin/bash

make CFLAGS="-Wall -Werror -Wextra -g3 -fsanitize=address" -C $(dirname ${BASH_SOURCE:-$0})/../src re && \
  echo -e '\033[0;36m''Compilation Successful''\033[0m'

if [[ ! -z "$1" ]]; then
  FORMATTED_ARGS="\"$1\""
  shift
  for ARG in "$@"
  do
    FORMATTED_ARGS="$FORMATTED_ARGS, \"$ARG\""
  done
fi

LAUNCH_JSON=$(dirname ${BASH_SOURCE:-$0})/../.vscode/launch.json
echo -e '\033[0;36m''[before change]'$(grep "\(\"args\": \[\).*\(\]\)" $LAUNCH_JSON)'\033[0m'
sed -i '' "s|\(\"args\": \[\).*\(\]\)|\1$FORMATTED_ARGS\2|g" $LAUNCH_JSON
echo -e '\033[0;36m''[after  change]'$(grep "\(\"args\": \[\).*\(\]\)" $LAUNCH_JSON)'\033[0m'