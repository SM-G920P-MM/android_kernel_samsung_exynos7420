#!/bin/bash

make AR='$(CROSS_COMPILE)gcc-ar' "$@"
