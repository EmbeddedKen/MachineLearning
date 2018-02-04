#SciKit (SK) Learn Initial Test Program
#Modfied from Siraj Raval's SourceCode...
#"Introduction- Learn Python for Data Science"
#By Kenneth Vorseth, 2/4/18

#<Import Tree from Sci-Kit Learn>
from sklearn import tree

#<Initial Training Data>
#(Height, Weight, Shoe Size)
X = [[181, 80, 44], #Data 0x00
     [177, 70, 43], #Data 0x01
     [160, 60, 38], #Data 0x02
     [154, 54, 37], #Data 0x03
     [166, 65, 40], #Data 0x04
     [190, 90, 47], #Data 0x05
     [175, 64, 39], #Data 0x06
     [177, 70, 40], #Data 0x07
     [159, 55, 37], #Data 0x08
     [171, 75, 42], #Data 0x09
     [181, 85, 43]] #Data 0x0A
#<Labels for Associated Data>
Y = ['male',    #Data 0x00
     'female',  #Data 0x01
     'female',  #Data 0x02
     'female',  #Data 0x03
     'male',    #Data 0x04
     'male',    #Data 0x05
     'male',    #Data 0x06
     'female',  #Data 0x07
     'male',    #Data 0x08
     'female',  #Data 0x09
     'male']    #Data 0x0A
#<Choose Model for Machine Learning (Tree Classifier)>
clf = tree.DecisionTreeClassifier()
#<Adjust the Tree to Learn from Labeled Data>
clf = clf.fit(X, Y)
#<Get Input From User to Make Predictions>
pState = 'y' #Initial Program State (For Repeating)
while (pState == 'y'):
    #> Grab Input Data from User for Prediction
    print("Predict Gender from Data...")  #Program Header
    bHeight = int(input("Height (cm): ")) #Body Weight
    bWeight = int(input("Weight (kg): ")) #Body Height
    sSize   = int(input("Shoe Size: "))   #Shoe Size
    #> Bind DataSet to New List
    dataSet = [bHeight, bWeight, sSize]
    #> Make a Prediction Based on Our Fitted Tree
    prediction = clf.predict([dataSet])
    #> Display the Prediction to the User
    print("Predicted Gender:", prediction)
    #> Ask User Whether to Repeat Program
    pState = input("Run Again? (y/n): ")

