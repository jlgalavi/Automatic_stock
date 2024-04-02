class target:
    
    position_x = 0
    position_y = 0
    position_z = 0
    ID_box = 0

    def __init__(self, position_x, position_y, position_z):
        self.position_x = position_x
        self.position_y = position_y
        self.position_z = position_z

    def set_ID_box(self, ID_box):
        self.ID_box = ID_box