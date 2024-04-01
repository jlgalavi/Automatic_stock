file_tagets = open('D:\\repos\Automatic_stock\\filesTXT\\results.txt', 'r')
lines = file_tagets.readlines()

container_numbers = []
id_boxes = []
target_coordinates = []

for line in lines:
    for i in range(0, len(line)):
        if line[i] == 'C':
            container_numbers.append(line[i+10])
            break
        elif line[i] == 'I':
            id_boxes.append(line[i+7])
            break
        elif line[i] == 'T':
            target = ''
            for j in range(i, len(line)):
                if line[j] == '(':
                    while line[j] != ')':
                        target = target + line[j]
                        j += 1
                target_coordinates.append(target)
                break

print("Container Numbers:", container_numbers)
print("ID Boxes:", id_boxes)
print("Target Coordinates:", target_coordinates)