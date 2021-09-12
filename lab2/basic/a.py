d = {}
f = open('input.txt', 'r')
lines = f.readlines()
for i in lines:
    d[i.strip()] = d.get(i.strip(), 0) + 1
outp = open('output.txt', 'w')
for i in sorted(d.keys(), key=str):
    outp.write(i + ' ' + str(d[i]) + '\n')
outp.close()