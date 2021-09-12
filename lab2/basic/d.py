def cmp(x):
    error = 0 - x[1]
    return (error, x[0])

d = {}
f = open('input.txt', 'r')
lines = f.readlines()

for i in lines:
    v = i.split()
    for word in v:
        d[word.lower().strip('.,:;!?')] = d.get(word.lower().strip('.,:;!?'), 0) + 1

outp = open('output.txt', 'w')
for i in sorted(d.items(), key=cmp):
    outp.write(i[0] + ' ' + str(i[1]) + '\n')
outp.close()