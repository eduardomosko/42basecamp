#!/bin/sh
git status --ignored -s | sed -e "/!!/!d" -e "s/!! //"
