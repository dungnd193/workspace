# importing the numpy module
import numpy as np
import matplotlib.pyplot as plt
# Bai1: 
n = np.arange(-15, 15)

hn = un = (n>0)

xn = pow(0.8, n)*un

yn = np.convolve(xn, hn, 'same')


plt.subplot(2, 2, 1)
plt.stem(n, xn)

plt.subplot(2, 2, 2)
plt.stem(n, hn)

plt.subplot(2, 2, 3)
plt.stem(n, yn)

plt.show()

# Bai 2:
# H1
omega = np.linspace(0, 2 * np.pi, 256)
H1 = 1 / (1 - 0.87 * np.exp(1j * omega))
plt.subplot(2,1,1)
plt.plot(omega, abs(H1))
plt.title("H1")

# H2
H2=1-np.exp(-1j*omega)
plt.subplot(2,1,2)
plt.plot(omega, abs(H2))
plt.title("H2")

plt.show()