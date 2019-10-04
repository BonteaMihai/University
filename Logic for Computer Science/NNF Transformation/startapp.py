import os, sys
from UI import UserInterface

if sys.platform.lower() == "win32":
    os.system('color')


ui = UserInterface(None)

ui.start()