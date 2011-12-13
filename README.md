# BasicChristmasTree / Arduino Project

We just started playing with Arduino, and haven't written much C; so this code will suck, but you are welcome to take a look, and make a pull request, no promises that we will take it, but it will certainly help us learn.

## Libraries

1. We use the G35Arduino library by sowbug: https://github.com/sowbug/G35Arduino
2. This code required Arduino 1.0.

## About Functions

BasicChristmasTree:

1. Random ornaments- 4 per branch
2. Knight Rider from one side to the other
3. Knight Rider up and down the branches only.

## Light Setup

Here is how our lights are run:

```
(top array is line 1/2)
1           o
2          ooo
3         oo oo
4        o o o o
5       o  o o  o       (Branches == the up/down strands)
6      o   o o   o
7    o    o   o   o
8   o     o   o    o
9  o     o     o    o
10o o o o       o o o o 
 (bottom)       (arrays) 
```

## Future Plans

Began implementation of two strings, but not sure how to set that up so it is commented out
