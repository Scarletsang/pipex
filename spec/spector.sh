#!/bin/bash

GREEN='\033[0;32m'
BLUE='\033[0;36m'
RED='\033[0;31m'
WHITE='\033[0m'

# Renders a text based list of options that can be selected by the
# user using up, down and enter keys and returns the chosen option.
#
#   Arguments   : list of options, maximum of 256
#                 "opt1" "opt2" ...
#   Return value: selected index (0 for opt1, 1 for opt2 ...)
function select_option {

    # little helpers for terminal print control and key input
    ESC=$( printf "\033")
    cursor_blink_on()  { printf "$ESC[?25h"; }
    cursor_blink_off() { printf "$ESC[?25l"; }
    cursor_to()        { printf "$ESC[$1;${2:-1}H"; }
    print_option()     { printf "   $BLUE$1$WHITE "; }
    print_selected()   { printf "   $ESC[7m$1$ESC[27m"; }
    get_cursor_row()   { IFS=';' read -sdR -p $'\E[6n' ROW COL; echo ${ROW#*[}; }
    key_input()        { read -s -n3 key 2>/dev/null >&2
                         if [[ $key = $ESC[A ]]; then echo up;    fi
                         if [[ $key = $ESC[B ]]; then echo down;  fi
                         if [[ $key = ""     ]]; then echo enter; fi; }

    # initially print empty new lines (scroll down if at bottom of screen)
    for opt; do printf "\n"; done

    # determine current screen position for overwriting the options
    local lastrow=`get_cursor_row`
    local startrow=$(($lastrow - $#))

    # ensure cursor and input echoing back on upon a ctrl+c during read -s
    trap "cursor_blink_on; stty echo; printf '\n'; exit" 2
    cursor_blink_off

    local selected=0
    while true; do
        # print options by overwriting the last lines
        local idx=0
        for opt; do
            cursor_to $(($startrow + $idx))
            if [ $idx -eq $selected ]; then
                print_selected "$opt"
            else
                print_option "$opt"
            fi
            ((idx++))
        done

        # user key control
        case `key_input` in
            enter) break;;
            up)    ((selected--));
                   if [ $selected -lt 0 ]; then selected=$(($# - 1)); fi;;
            down)  ((selected++));
                   if [ $selected -ge $# ]; then selected=0; fi;;
        esac
    done

    # cursor position back to normal
    cursor_to $lastrow
    printf "\n"
    cursor_blink_on

    return $selected
}

compile() {
  echo -e $BLUE"Compiling source..."$WHITE
  make CFLAGS="-Wall -Werror -Wextra -g3 -fsanitize=address" -C $(dirname ${BASH_SOURCE:-$0})/../src re
}

set-vscode-debugger() {
  LAUNCH_JSON=$(dirname ${BASH_SOURCE:-$0})/../.vscode/launch.json
  echo -e $BLUE'[current param]'$(grep "\(\"args\": \[\).*\(\]\)" $LAUNCH_JSON)$WHITE
  read -p "Enter args: " ARGS
  FORMATTED_ARGS=$(echo "$ARGS" | xargs -n 1 printf '"%s", ' | sed 's/..$//')
  sed -i '' "s|\(\"args\": \[\).*\(\]\)|\1$FORMATTED_ARGS\2|g" $LAUNCH_JSON
  echo -e $BLUE'[after change]'$(grep "\(\"args\": \[\).*\(\]\)" $LAUNCH_JSON)$WHITE
}

echo -e $BLUE"What do you want to do?"$WHITE
options=("compile source" "set vscode debugger args" "both")

select_option "${options[@]}"
case $? in
  0)
    compile
    ;;
  1)
    set-vscode-debugger
    ;;
  2)
    compile && set-vscode-debugger
    ;;
  *) 
    echo "Invalid option";;
esac
