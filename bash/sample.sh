#!/bin/bash

message="Hello World"
echo $message

for var in "$@"; do
  echo "$var"
done

cat $1

echo "-----------------------------------"

echo "number of arguments is: $#"
echo "your name is $USER"

MY_VAR=$( ls -l )

echo $MY_VAR

echo "_______________________________________________"

echo "What is your name?"
read -p 'Username: ' name
echo "Your name is $name"
echo "What is your password?"
read -sp "Password: " password
echo "Your password is $password"

COOL_VAR="Lorem Ipsum Dolor sit Amet"

echo "length of COOL_VAR is: ${#COOL_VAR}"

case $2 in 
  start)
    echo "we are starting"
    ;;
  end)
    echo "we are ending"
    ;;
  pause)
    echo "we are pausing"
    ;;
esac