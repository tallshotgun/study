import math

class twoDpoint:
    def __init__(self,x=0,y=0):
        self.x = x
        self.y = y
    
    def set_point(self,x,y):
        self.x = x
        self.y = y

    def get_point(self):
        return self.x,self.y
    
    def distance(obj1,obj2):
        point1 = twoDpoint.get_point(obj1)
        point2 = twoDpoint.get_point(obj2)
        distance = math.dist(point1,point2)
        return distance
# Example   
if __name__ == "__main__":
    p1 = twoDpoint(-3,1)
    p2 = twoDpoint(4,1)
    print("First point is:",p1.get_point())
    print("Second point is:",p2.get_point())
    print("Distance between the two points is:",twoDpoint.distance(p1,p2))
    