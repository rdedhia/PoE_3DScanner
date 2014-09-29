import numpy as np
from matplotlib import pyplot as plt

with open('values.txt', 'r') as f:
	values = np.array(map(float, f)).reshape((90, 100))

for i in range(len(values)):
	if i % 2 == 1:
		values[i] = np.flipud(values[i])

x_angs = xrange(50, 141, 10)
y_angs = xrange(30, 131, 10)

plt.imshow(values.T, interpolation="nearest")
plt.xticks(xrange(0, 91, 10), x_angs)
plt.yticks(xrange(0, 101, 10), y_angs)
plt.xlabel('Panning Angle (degrees)')
plt.ylabel('Tilting Angle (degrees)')
plt.title("3D Scanning of the Letter 'H'")
plt.colorbar()
plt.show()



