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
#<Make a Prediction Based on Literal List>
prediction = clf.predict([[190,70,43]])
#> Display the Prediction to the User
print("Predicted Gender:", prediction)
