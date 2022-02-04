from matplotlib import pyplot as plt
N=[3,4,5]
States_stored=[288330,34977055,34000000]
States_matched=[703046,1.0238759e+08,86092699]
Transition = [991376,1.3736465e+08,1.200927e+08]
plt.plot(N,States_stored, label='states stored')
plt.plot(N,States_matched, label='states matched')
plt.plot(N,Transition, label='Transition')
plt.legend(fontsize=20)
plt.xticks(N,fontsize=20)
plt.xlabel('Value of N',fontsize=20)
plt.ylabel('number of states',fontsize=20)
plt.show()
