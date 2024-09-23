sym = {'A':'A','E':'3','H':'H','I':'I','M':'M',
       'O':'O','S':'2','T':'T','U':'U','V':'V','W':'W','X':'X','Y':'Y','Z':'5',
       'b':'d','d':'b','i':'i','l':'l','m':'m',
       'n':'n','o':'o','p':'q','q':'p','r':'7','u':'u','v':'v','w':'w','x':'x',
       '0':'0','1':'1','2':'S','3':'E','5':'Z','7':'r','8':'8'}
def is_symmetric(a,b):
    if a.upper() in sym and (sym[a.upper()] == b.upper() or sym[a.upper()] == b.lower()): return 2
    elif a.lower() in sym and (sym[a.lower()] == b.upper() or sym[a.lower()] == b.lower()): return 1
    return 0

s = list(input())
if (stat := is_symmetric(s[0],s[-1])) > 0:
    if stat == 2: s[0] = s[0].upper(); s[-1] = sym[s[0].upper()]
    else: s[0] = s[0].lower(); s[-1] = sym[s[0].lower()]
    for l in range(1,len(s)//2+1):
        r = len(s)-l-1
        if (sym_stat := is_symmetric(s[l],s[r])) > 0:
            if sym_stat == 2: s[l] = s[l].upper(); s[r] = sym[s[l].upper()]
            else: s[l] = s[l].lower(); s[r] = sym[s[l].lower()]
        else: print(-1); break
    else: print(''.join(s))
elif len(s) == 1: print(''.join(s))
else: print(-1)