Machine Learning | UAT
C Neural Network Application - Final Project
Kenneth Vorseth, 2018

Summary: This project utilizes the 'C Neural Network' I developed earlier in this class in an embedded application. The application at hand is scanning objects and classifying objects based on point-cloud data. Originally, I intended to use a full LIDAR system; however with limited time and resources the project will utilize a single rotation axis, SharpIR system to generate similiar point-cloud data.

Each degree of rotation has an associated "distance/value" to the object it strikes. Each distance represents the value of an input neuron in the single-layer artifical neural network. The number of objects to classify will be the number of output neurons. The output neuron with the highest overall activation, will be considered the singular type of the object being examined.

The system will include a way for the user to "train" objects by placing them on the scanning plate and initiating a variety of scans of the object(s) at various angles. The user will be able to use the device to put any object (within size restrictions) on the scanning plate for classification of known objects.

(Stretch-Goal) Known Object data will be stored in a 2Kb non-volatile EEPROM storage on the microcontroller, and populated into RAM (32Kb) on power-on.

Project Checklist:
-Have a Functional Neural Network  (Done)
-Develop Hardware Scanner Platform (Done)
-Routine for Scanning Objects      (Done)
-Linking of Neural Network         (In-Progress)
-Tuning of Neural Network          (Not Started)
-User-Interface / Buttons          (Not Started)
-EEPROM Memory Storage		   (Optional- Not Started)