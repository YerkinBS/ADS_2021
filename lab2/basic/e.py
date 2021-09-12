f = open('input.txt', 'r')
outp = open('output.txt', 'w')
d, d1 = {}, {}
lines = f.readlines()
for i in lines:
    i = i.strip()
    if i[0] == '-' and int(i[1:]) not in d.keys():
        outp.seek(0)
        outp.write('ERROR')
        exit()
    elif i[0] == '-' and int(i[1:]) in d.keys():
        if d[int(i[1:])] == 'deleted':
            outp.seek(0)
            outp.write('ERROR')
            exit()
        if d1[int(i[1:])] == 1:
            d[int(i[1:])] = 'deleted'
        d1[int(i[1:])] -= 1
    elif i[0] == '+' and int(i[1:]) not in d.keys():
        d1[int(i[1:])] = 1
        d[int(i[1:])] = 'existing'
    elif i[0] == '+' and int(i[1:]) in d.keys():
        if d[int(i[1:])] == 'deleted':
            d[int(i[1:])] = 'existing'
        d1[int(i[1:])] += 1

cnt = 0
for i in sorted(d.keys(), key=int):
    if d[i] == 'existing':
        for j in range(d1[i]):
            outp.write(str(i) + ' ')
            cnt += 1

if cnt == 0:
    outp.seek(0)
    outp.write('EMPTY')
outp.close()