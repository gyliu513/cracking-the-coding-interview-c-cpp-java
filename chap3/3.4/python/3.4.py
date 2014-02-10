class hanoi_class():
    count = 0
    def move(self, x, n, z):
        print "Move %d from %c to %c" % (n, x, z)
 
    def hanoi(self, n, x, y, z):
        if n==1:
            self.move(x, 1, z)
        else:
            self.hanoi(n-1, x, z, y)
            self.move(x, n, z)
            self.hanoi(n-1, y, x, z)
 
if __name__ == "__main__":
    s = hanoi_class()
    s.hanoi(4, 'a', 'b', 'c');
