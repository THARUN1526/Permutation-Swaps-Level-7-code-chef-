# cook your dish here
import sys,os,io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

for _ in range (int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    p = [int(i)-1 for i in input().split()]
    cycles = []
    vis = [-1]*n
    idInC = []
    for i in range (n):
        if vis[i]==-1:
            cycles.append([i])
            idInC.append({})
            idInC[-1][i] = 0
            curr = p[i]
            vis[i] = len(cycles)-1
            while(curr!=i):
                cycles[-1].append(curr)
                idInC[-1][curr] = len(cycles[-1])-1
                vis[curr] = vis[i]
                curr = p[curr]
    # print(cycles)
    # print(idInC)
    steps = 0
    q = int(input())
    for i in range (q):
        inp = [int(i) for i in input().split()]
        if inp[0]==1:
            steps+=1

        if inp[0]==3:
            pos = inp[1]-1
            ind = vis[pos]
            cid = idInC[ind][pos]
            cid = cycles[ind][(cid-steps)%len(cycles[ind])]
            print(a[cid])

        if inp[0]==2:
            pos1 = inp[1]-1
            ind1 = vis[pos1]
            cid1 = idInC[ind1][pos1]
            cid1 = cycles[ind1][(cid1-steps)%len(cycles[ind1])]

            pos2 = inp[2]-1
            ind2 = vis[pos2]
            cid2 = idInC[ind2][pos2]
            cid2 = cycles[ind2][(cid2-steps)%len(cycles[ind2])]
            # print('h',cid1,cid2)
            a[cid1],a[cid2] = a[cid2],a[cid1]