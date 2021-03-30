#!/bin/sh
ifconfig | sed -e "/ether/!d" -e "s:^\s*ether ::"
