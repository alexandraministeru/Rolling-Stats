# Rolling-Stats
Project in C++ containing two different programs (one time based, one not) used for calculating and storing various data statistics.
The project consists of a class that stores a configurable number of items. The program presents a number of statistics for different data types (using templates). 
There are two ways to query data for a specific range. This can be done by using the copy constructor of the class that creates a new object containing the targeted set of items (no data is to be deleted). The second method uses the SelectQuery function, which keeps only the selected range of data and deletes the rest from the original container.
A quick interface displays the functionalities of the program:
-	Add elements to the data container: either one by one or multiple items at a time
-	Display the elements in the container
-	Various statistics: 
•	Sum - calculates the sum of the items in the container
•	Mean – calculates the mean of the items
•	Median – elements of the container are sorted; Median function is calculated depending on the number of items. If the number is odd, the Median function takes the value of the element at the middle of the container. If the number is even, the Median function takes the value of the mean of the two middle values
•	Sample standard deviation
•	Population standard deviation
-	Flush items: deletes all data inside the container
-	SelectQuery function (detailed above)
-	Exit: exit the application
# Rolling-Stats Time
In the second part of the project, data is stored with timestamps such that the maximum range of data is input over a specified time rather than a specified amount. The class has two containers, one for the data and one for the timestamps. The timestamp corresponding to a piece of data is always in the same position as the data in the container. Whenever the data container is modified, the timestamps are updated as well. The elements that exceed the time limit imposed by the user are gradually deleted.
The functionality is identical to what was presented earlier.


