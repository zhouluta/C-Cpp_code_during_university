#num = int (input ('num='))
#num1=0
#while num>0:
#    num1=num1 * 10 + num % 10
#    num//=10
#print(num1)
#猜数字
#from random import randint
#x = randint(1,100)
#print ('x=',x)
#while True:
#    n = int (input('n='))
#    if n<x:
#        print('往大了猜')
#    elif(n>x):
#        print('往小了猜' )
#    else:
#        print('Right')
#        break
#from math import factorial
#n = factorial(10)
#print(n)
#print(factorial(5))

#import os
#import time


#def main():
#    content = '微风需要竹林，溪流需要蜻蜓'
#    while True:
#        # 清理屏幕上的输出
#        os.system('cls')  # os.system('clear')
#        print(content)
#        # 休眠200毫秒
#        time.sleep(0.2)
#        content = content[1:] + content[0]


#if __name__ == '__main__':
#    main()


#import random
#def generate_code(code_len=4):
#    """
#    生成指定长度的验证码

#    :param code_len: 验证码的长度(默认4个字符)

#    :return: 由大小写英文字母和数字构成的随机验证码
#    """
#    all_chars = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'
#    last_pos = len(all_chars)
#    code = ''
#    for _ in range(code_len):
#        index = random.randint(0, last_pos)
#        code += all_chars[index]
#    print (code)
#def main():
#    generate_code(5)
#if __name__=='__main__':
#    main()
#def main():
#    num = int(input('Number of rows: '))
#    yh = [[]] * num
#    for row in range(len(yh)):
#        yh[row] = [None] * (row + 1)
#        for col in range(len(yh[row])):
#            if col == 0 or col == row:
#                yh[row][col] = 1
#            else:
#                yh[row][col] = yh[row - 1][col] + yh[row - 1][col - 1]
#            print(yh[row][col], end='\t')
#        print()


#if __name__ == '__main__':
#    main()

#import os


#def print_board(board):
#    print(board['TL'] + '|' + board['TM'] + '|' + board['TR'])
#    print('-+-+-')
#    print(board['ML'] + '|' + board['MM'] + '|' + board['MR'])
#    print('-+-+-')
#    print(board['BL'] + '|' + board['BM'] + '|' + board['BR'])


#def main():
#    init_board = {
#        'TL': ' ', 'TM': ' ', 'TR': ' ',
#        'ML': ' ', 'MM': ' ', 'MR': ' ',
#        'BL': ' ', 'BM': ' ', 'BR': ' '
#    }
#    begin = True
#    while begin:
#        curr_board = init_board.copy()
#        begin = False
#        turn = 'x'
#        counter = 0
#        os.system('clear')
#        print_board(curr_board)
#        while counter < 9:
#            move = input('轮到%s走棋, 请输入位置: ' % turn)
#            if curr_board[move] == ' ':
#                counter += 1
#                curr_board[move] = turn
#                if turn == 'x':
#                    turn = 'o'
#                else:
#                    turn = 'x'
#            os.system('clear')
#            print_board(curr_board)
#        choice = input('再玩一局?(yes|no)')
#        begin = choice == 'yes'


#if __name__ == '__main__':
#    main()

from time import sleep


class Clock(object):
    """数字时钟"""

    def __init__(self, hour=0, minute=0, second=0):
        """初始化方法

        :param hour: 时
        :param minute: 分
        :param second: 秒
        """
        self._hour = hour
        self._minute = minute
        self._second = second

    def run(self):
        """走字"""
        self._second += 1
        if self._second == 60:
            self._second = 0
            self._minute += 1
            if self._minute == 60:
                self._minute = 0
                self._hour += 1
                if self._hour == 24:
                    self._hour = 0

    def show(self):
        """显示时间"""
        return '%02d:%02d:%02d' % \
               (self._hour, self._minute, self._second)


def main():
    clock = Clock(23, 59, 58)
    while True:
        print(clock.show())
        sleep(1)
        clock.run()


if __name__ == '__main__':
    main()