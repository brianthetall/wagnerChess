#!/usr/bin/env bash
set -x

BACKEND=${BACKEND:="$WORKSPACE/backend"}

source $WORKSPACE/.pyenv-usr-local-bin-python3.6/bin/activate
source $BACKEND/setEnvVariables.sh

python -m pytest ./pytests/test_location.py
#python -m pytest ./pytests/test_.py
#python -m pytest ./pytests/test_.py
#python -m pytest ./pytests/test_.py
