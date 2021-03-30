#!/bin/sh
git check-ignore $(find -type f | sed -e "s:./::")
