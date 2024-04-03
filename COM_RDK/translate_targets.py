import classtarget
#from robodk import *
#from robolink import *

file_tagets = open('D:\\repos\Automatic_stock\\filesTXT\\results.txt', 'r')
lines = file_tagets.readlines()
containers = {}
boxes = {}
targets = {}
cont_box = 0
cont_target = 0
pos_x = 0
pos_y = 0
pos_z = 0
ID_box = 0
cont_target_vector = 0
targets_vector = []
str_number = ''
coordenadas = ""
contador_target = 0
contador_boxes = 0

for line in lines:
    if line.startswith('Container'):
        container_id = line.split(':')[1].strip()
        containers[container_id] = []
    elif line.startswith('Number-boxes'):
        n_box = int(line.split(':')[1].strip())
        containers[container_id].append({'n_box': n_box}) 
    elif line.startswith('ID_Box'):
        box_id = line.split(':')[1].strip()
        boxes[cont_box] = {box_id}
        cont_box = cont_box + 1
    elif line.startswith('Target'):
        target_id = line.split(':')[1].strip()
        targets[cont_target] = {target_id}
        cont_target = cont_target + 1

for target_id_vector in targets.items():
    coordenadas = str(targets[contador_target]).strip("{'}").strip("()").split(",")
    pos_x = float(coordenadas[0])
    pos_y = float(coordenadas[1])
    pos_z = float(coordenadas[2])
    T1 = classtarget.target(pos_x, pos_y, pos_z)
    targets_vector.append(T1)
    contador_target = contador_target + 1

for box_id_vector in boxes.items():
    ID_box = str(boxes[contador_boxes]).strip("{'}")
    targets_vector[contador_boxes].set_ID_box(int(ID_box))
    contador_boxes = contador_boxes + 1

for container_id in containers.items():
    print(f"Container ID: {container_id}")
    for box_id in boxes.items():
        print(f"Box ID: {box_id}")
    for target_id in targets.items():
        print(f"Target ID: {target_id}")

# Print the targets
for j in targets_vector:
    print(f"Target ID: {j.ID_box}  - Position: ({j.position_x}, {j.position_y}, {j.position_z})")

file_tagets.close()

RDK = robolink.Robolink()
robot = RDK.Item('UR10', ITEM_TYPE_ROBOT)

reference = robot.Parent()
robot.setPoseFrame(reference)

pose_ref = robot.Pose()

for target in targets_vector:
    pose_i =pose_ref * transl(target.position_x, target.position_y, target.position_z)
    MoveJ(pose_i)

MoveJ(pose_ref)

quit()