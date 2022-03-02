# TaskMarch2022

## Laser system
![Laser Setup](https://github.com/StingrayMarineSolutions/TaskMarch2022/blob/main/laser_setup.png?raw=true)

The figure shows a simplified 2D version of an underwater laser system consisting of 3 parts: a laser with adjustable rotation, a very thin glass interface between air and water, and a board that can be moved along the x-axis.

The parameters of the system are:
- d_glass:  0.04
- n_air: 1.0
- n_water: 1.33

## Task
The task is split into two parts, forward projection and backward projection of the laser beam. Implementations C++, Python or Matlab are preferred.

### a) Forward projection
Given laser angles and x coordinates of the board, write an algorithm to find the y coordinates of the laser hits on the board. Test data is provided in a.csv.

### b) Backward projection
Given (x, y) positions on the board, write an algorithm to find the best laser angles to hit the targets. Test data is provided in b.csv.

