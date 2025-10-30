import math
import re
def trig(expression):
    trig = r"arcsin|arccos|arctan"
    number = r'\d+'
    trignum = re.findall(number, expression)
    trigex = re.findall(trig , expression)
    print(trigex)
    print(trignum)
expression = input("Input your expression: ")
if 'arccos' in expression:
    trig(expression)
if 'arcsin' in expression:
    trig(expression)
#print(result)