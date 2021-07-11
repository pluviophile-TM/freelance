from easygui import fileopenbox
from subprocess import Popen, PIPE

if __name__ == '__main__':
    solver_path = fileopenbox('Choose your solver file')
    Popen('g++ judge.cpp -o judge.out'.split()).wait()
    Popen(f'g++ {solver_path} -o solver.out'.split()).wait()
    judge = Popen(['./judge.out'], stdout=PIPE, stdin=PIPE)
    solver = Popen(['./solver.out'], stdout=PIPE, stdin=PIPE)
    line = b'\n'
    while True:
        try:
            judge.stdin.write(line)
            judge.stdin.flush()
            line = judge.stdout.readline()
            print(f'judge >> {line.decode()}', end='')
            int(line.decode())
            solver.stdin.write(line)
            solver.stdin.flush()
            line = solver.stdout.readline()
            print(f'solver >> {line.decode()}', end='')
        except:
            break
    input('Press enter to exit interaction')