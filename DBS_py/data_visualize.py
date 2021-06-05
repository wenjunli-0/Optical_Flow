import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

data = np.loadtxt(
    "1225.txt",
    delimiter="\t",
    dtype=float
)

print(data.shape)
x = data[:, 0]
y = data[:, 1]
print(x.shape)
print(y.shape)

plt.scatter(x, y)
plt.axis('equal')
ax = plt.gca()
ax.xaxis.set_ticks_position('top')
ax.invert_yaxis()
plt.title("Point Distribution @ 1225 Frame")
plt.show()
