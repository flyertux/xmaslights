# BasicChristmasTree / Arduino Project

  This is our repo with code for hacking GE G35 Christmas Lights
## Libraries

We use the G35Arduino library by sowbug: https://github.com/sowbug/G35Arduino

## About Functions
BasicChristmasTree:
1. Random ornaments- 4 per branch
2. Knight Rider from one side to the other
3. Knight Rider up and down the branches only.

## Light Setup

Here is how our lights are run:
```
            0 (top array is up here)
1           o
2          ooo
3         oo oo
4        o o o o
5       o  o o  o       (Branches == the up/down strands)
6      o   o o   o
7    o    o   o   o
8   o     o   o    o
9  o     o     o    o
10 o o o o     o o o o 
   (bottom arrays) 
```

## Future Plans

Began implementation of two strings, but not sure how to set that up so it is commented out

-Billy & Sarah