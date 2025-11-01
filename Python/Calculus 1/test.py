import math
import re
def trig(expression):
    trig = r"arcsin|arccos|arctan"
    number = r'\d+'
    trignum = re.findall(number, expression)
    trigex = re.findall(trig , expression)
    print(trigex)
    for x in trigex:
        if x == "arccos":
            y = math.acos(trignum[i])
    print(trignum)
expression = input("Input your expression: ")
expression_updated = expression
match expression:
    case _ if 'arcsin' in expression:
        expression_updated = expression.replace("sin", "math.sin")
print(expression_updated)
print(eval(expression_updated))
#if 'asin' in expression:
#    raise TypeError("arcsin not asin")
#if 'arccos' in expression:
#    trig(expression)
#if 'arcsin' in expression:
#    trig(expression)
#if 'arctan' in expression:
#    trig(expression)
#print(result)