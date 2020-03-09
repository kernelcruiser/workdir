#!/bin/bash
makedumpfile -l --message-level 1 -d 31 /proc/kcore vmcore-$(date +"%Y-%m-%d")
