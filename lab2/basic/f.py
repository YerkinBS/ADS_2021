import re
f = open('input.txt', 'r')
outp = open('output.txt', 'w')
lines = f.readlines()
d = []
for line in lines:
    n = re.findall(r'\d+', line)
    if line[0] == '+':
        if 1 <= int(n[0]) <= len(d) + 1:
            d.insert(int(n[0]) - 1, line[len(n[0]) + 2:])
        else:
            outp.write('ERROR')
            exit()
    elif line[0] == '-':
        if int(n[0]) <= len(d):
            del d[int(n[0]) - 1]
        else:
            outp.write('ERROR')
            exit()
    elif line[0] == '*':
        if int(n[0]) <= len(d):
            d[int(n[0]) - 1] = line[len(n[0]) + 2:]
        else:
            outp.write('ERROR')
            exit()
if len(d) == 0:
    outp.write('EMPTY')
    exit()
outp.write(''.join([str(i) for i in d]))
outp.close()