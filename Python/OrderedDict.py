from collections import OrderedDict

print("dict")
d = {}
d['a'] = 1
d['b'] = 2
d['c'] = 3
d['d'] = 4
d['a'] +=1
for key, val in d.items():
    print(key, val)

print("ordered dict")
od = OrderedDict()
od['d'] = 4
od['b'] = 2
od['a'] = 1
od['c'] = 3
od['d'] = 5
for key, val in od.items():
    print(key, val)
