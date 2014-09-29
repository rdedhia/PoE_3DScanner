import numpy as np
from matplotlib import pyplot as plt

with open('values.txt', 'r') as f:
	values = np.array(map(float, f)).reshape((90, 100))

# Flipping values of every other subarray, because we repeated the cycle of
# tilting from 30 to 130 degrees for a given panning angle, and then from 
# 130 to 30 degrees for the next panning angle
for i in range(len(values)):
	if i % 2 == 1:
		values[i] = np.flipud(values[i])

# Using distance equation calculated from our calibration routine
distances = -.083*values + 63.07

x_angs = xrange(50, 141, 10)
y_angs = xrange(30, 131, 10)

# Plotting 3D colormap of distances
plt.imshow(distances.T, interpolation="nearest")
plt.xticks(xrange(0, 91, 10), x_angs)
plt.yticks(xrange(0, 101, 10), y_angs)
plt.xlabel('Panning Angle (degrees)')
plt.ylabel('Tilting Angle (degrees)')
plt.title("3D Scanning of the Letter 'H'")
cbar = plt.colorbar()
cbar.ax.get_yaxis().labelpad = 25
cbar.ax.set_ylabel('Distance from Sensor (cm)', rotation=270)
plt.show()

# Plotting 2D colormap of distances for a fixed panning angle
plt.imshow(distances[20].reshape((100, 1)), interpolation='nearest', aspect='auto')
plt.yticks(xrange(0, 101, 10), y_angs)
plt.xticks([0], [0])
plt.ylabel('Tilting Angle (degrees)')
plt.title("Top-Down 2D Scanning of the Letter 'H'")
cbar = plt.colorbar()
cbar.ax.get_yaxis().labelpad = 25
cbar.ax.set_ylabel('Distance from Sensor (cm)', rotation=270)
plt.show()
