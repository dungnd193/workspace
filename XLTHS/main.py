# This is a sample Python script.

# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.

import numpy as np
import matplotlib.pyplot as plt

# todo: tin hieu xung don vv
n = np.arange(-5, 5)
delta = 1.0 * (n == 0)
plt.subplot(2, 2, 1)
plt.plot(n, delta)


# todo:  bac don vi
u = 1.0 * (n >= 0)
plt.subplot(2, 2, 2)
plt.plot(n, u)
# todo: ham mu
expnt = 2.0*0.6**n
plt.subplot(2, 2, 3)
plt.plot(n, expnt)
# todo: ham sin
N=10
ns = np.arange(-10, 10)
sinsig = 2.0 * np.sin(2.0*np.pi*ns/N)
plt.subplot(2, 2, 4)
plt.plot(sinsig)

plt.show()
# See PyCharm help at https://www.jetbrains.com/help/pycharm/
