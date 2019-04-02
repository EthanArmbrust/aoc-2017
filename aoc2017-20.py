input = open('2017-20.txt').read().splitlines()

position = dict()
velocity = dict()
acceleration = dict()

from numpy import *
time = 0

for index, line in enumerate(input):
    tokens = line.split()
    pos = tokens[0][3:-2].split(',')
    vel = tokens[1][3:-2].split(',')
    acc = tokens[2][3:-1].split(',')
    position[index] = array([int(pos[0]), int(pos[1]), int(pos[2])])
    velocity[index] = array([int(vel[0]), int(vel[1]), int(vel[2])])
    acceleration[index] = array([int(acc[0]), int(acc[1]), int(acc[2])])

def closest():
    dists = {index:sum(abs(pos)) for index, pos in position.items()}
    return min(dists, key=dists.get)

def tick():
    for index in acceleration.keys():
        velocity[index] += acceleration[index]
        position[index] += velocity[index]
    collide()

from collections import defaultdict
def collide():
    collision = defaultdict(set)
    for index, p in position.items():
        t = p[0], p[1], p[2]
        collision[t].add(index)
    for pos, items in collision.items():
        if len(items) > 1:
            print("time ", time)
            for item in items:
                print("collision at index", item)
                del position[item]
                del velocity[item]
                del acceleration[item]

for i in range(20000):
    time = i
    tick()
print(closest())
print(len(position))
