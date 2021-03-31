#!/bin/bash

tasksDone=$(grep -c " \[x\]" README.md)
tasksUndone=$(grep -c " \[ \]" README.md)
totalTasks=$(( tasksDone + tasksUndone ))

echo "$tasksUndone/$totalTasks"
