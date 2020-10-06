
# Python program to  
# demonstrate queue implementation 
# using list 
  
# Initializing a queue 
queue = [] 
  
# Adding elements to the queue 
queue.append('a') 
queue.append('b') 
queue.append('c') 
  
print("Initial queue") 
print(queue) 
  
# Removing elements from the queue 
print("\nElements dequeued from queue") 
print(queue.pop(0)) 
print(queue.pop(0)) 
print(queue.pop(0)) 
  
print("\nQueue after removing elements") 
print(queue) 
  
# Uncommenting print(queue.pop(0)) 
# will raise and IndexError 
# as the queue is now empty 



# Python3 program to add two numbers 

num1 = 15
num2 = 12

# Adding two nos 
sum = num1 + num2 

# printing values 
print("Sum of {0} and {1} is {2}" .format(num1, num2, sum)) 

