import prac13
import math

class threeDpoint(prac13.twoDpoint):
    def __init__(self, x, y, z):
        prac13.twoDpoint.__init__(self, x, y)
        self.z = z
    def distance(obj1,obj2):
        point1 = [obj1.x,obj1.y,obj1.z]
        point2 = [obj2.x,obj2.y,obj2.z]
        distance = math.dist(point1,point2)
        return distance
    def set_point(self, z):
        self.z = z
    def get_point(self):
        return self.x,self.y,self.z
#Example
p1 = threeDpoint(2,-8,3)
p2 = threeDpoint(6,4,-3)
print("First point is: ",p1.get_point())
print("Second point is: ",p2.get_point())
print("Distance between the points is: ",threeDpoint.distance(p1,p2))