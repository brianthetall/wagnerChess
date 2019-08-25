#!/usr/bin/env bash
set -x

BACKEND=${BACKEND:="$WORKSPACE/games/wagnerChess/wagnerChess"}

pwd
ls -laht
echo $BACKEND
echo $WORKSPACE

source $WORKSPACE/.pyenv-usr-local-bin-python3.6/bin/activate
source $BACKEND/setEnvVariables.sh

python -m pytest ./wagnerChess/pytests/test_location.py
#python -m pytest ./pytests/test_.py
#python -m pytest ./pytests/test_.py
#python -m pytest ./pytests/test_.py
