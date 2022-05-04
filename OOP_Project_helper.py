import matplotlib.pyplot as plt

text=open('track1_note.txt')
y=[]
cnt=0
for line in text:
    line=line.rstrip()
    y.append(int(line))
    cnt+=1
x=[i for i in range (cnt)]
plt.plot(x,y, linewidth=0.25)
plt.show()
