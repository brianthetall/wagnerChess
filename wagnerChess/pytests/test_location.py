import pytest
import logging
import sys
import os

sys.path.append(os.environ['BACKEND'])
from location import Location
                

def test_location_feature_0():

    logger = logging.getLogger("logger")
    logger.setLevel(logging.DEBUG)

    #build a Location
    Location("E",4)
    #check stuff about it...

    assert (True)
    
