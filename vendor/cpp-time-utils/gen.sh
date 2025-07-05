#!/bin/bash

source ./utils/inc/sh/colors.sh

function changeDir {
    cd $1

    echo -e "${UNDERLINE}[ * ] Moved to \`$1\`${RESET}"
}

if [ "$1" == "--ungen" ]; then
    echo -e "${BOLD}[ * ] Removing generated files"
    echo -e "${RED}[ WARN ] Are you sure that you want to continue? This will remove all existing data [ Y / N / GET ]${RESET}"

    read answer

    if [ "${answer,,}" == "yes" ] || [ "${answer,,}" == "y" ]; then
        printf "[ DEL ] Deleting all from \`.private/\` " ; find .private -mindepth 1 ! -name "project.json" -delete ; echo "[ DONE ]"

        echo -e "[ DONE ]${RESET}"

    elif [ "${answer,,}" == "get" ]; then
        tree .private/
        
        echo "[ DONE ]"

    else
        echo -e "${RESET}Abort."
    fi

    echo -e "${BOLD}${CYAN}[ NOTE ] Execute this file without the \`--ungen\` flag to generate all files"
    exit
fi

printf "${BOLD}${BRIGHT_GREEN}[ MKDIR ] Generating \`.private/\` files${RESET} " ; mkdir -p ./.private ; echo -e "${BOLD}${BRIGHT_GREEN}[ OK ]${RESET}"
printf "${BOLD}${BRIGHT_GREEN}[ MKDIR ] Generating \`.private/dev\` files${RESET} " ; mkdir -p ./.private/dev ; echo -e "${BOLD}${BRIGHT_GREEN}[ OK ]${RESET}"
printf "${BOLD}${BRIGHT_GREEN}[ MKDIR ] Generating \`build/\` files${RESET} " ; mkdir -p ./build ; echo -e "${BOLD}${BRIGHT_GREEN}[ OK ]${RESET}"

printf "${BOLD}${BRIGHT_GREEN}[ TOUCH ] Generating \`.private/dev/compilation.json\` files${RESET} " ; touch .private/dev/compilation.json ; echo -e "${BOLD}${BRIGHT_GREEN}[ OK ]${RESET}"

doxygen Doxyfile

echo -e "[ DONE ]"

