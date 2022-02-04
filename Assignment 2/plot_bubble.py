from matplotlib import pyplot as plt
N=[5,6,7,8,9,10]
States_stored=[233,552,1249,2758,6009,12988]
States_matched=[70,173,406,929,2094,17657]
Transition = [303,725,1655,3687,8103,17657]
plt.plot(N,States_stored, label='states stored')
plt.plot(N,States_matched, label='states matched')
plt.plot(N,Transition, label='Transition')
plt.legend(fontsize=20)
plt.xticks(N,fontsize=20)
plt.xlabel('Value of N',fontsize=20)
plt.ylabel('number of states',fontsize=20)
plt.show()
