import RPi.GPIO as GPIO
from time import sleep
from lcd import *

# Configuration des broches de la Raspberry Pi pour le contrôle de l'afficheur
lcd_rs = 27
lcd_e = 22
lcd_data = [25, 24, 23, 18, 17, 15, 14, 4]

# Initialisation de l'afficheur
lcd = LCD(lcd_rs, lcd_e, lcd_data, cols=16, rows=2)

# Effacement de l'afficheur
lcd.clear()

# Affichage de la phrase
lcd.write("Bonjour, monde!")
