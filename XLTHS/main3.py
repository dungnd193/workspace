# importing the numpy module
import numpy as np
import matplotlib.pyplot as plt

# 
# n = np.arange(0, 8, 1)
# Hn = 1.0 * (n >= 0)
# Xn = 0.8**n * Hn
# Yn = Xn*Hn
# conv_array = np.convolve(Xn, Hn, mode='same')

# print(Hn)
# print(Xn)

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