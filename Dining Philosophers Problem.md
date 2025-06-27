## INTRODUCTION:

The dining philosophers' problem is considered a classic synchronization problem. This problem deals with resource allocation; it is an example of a large class of concurrency-control problems. It was originally formulated in 1965 by Edsger Dijkstra as a student exam exercise, presented in terms of computers competing for access to tape drive peripherals. Soon after, Tony Hoare gave the problem its present formulation.

## PROBLEM STATEMENT:

Five silent philosophers sit at a round table around a bowl of spaghetti. Chopsticks are placed between each pair of adjacent philosophers. Each philosopher must alternately think and eat. However, a philosopher can only eat spaghetti when they have both left and right chopsticks. Only one philosopher can hold each chopstick so a philosopher can use the chopstick only if another philosopher is not using it. After an individual philosopher finishes eating, they need to put down both forks so that the forks become available to others. A philosopher can take the fork on their right and the one on their left as they become available, but cannot start eating before getting both chopsticks. Eating is not limited by the remaining amounts of spaghetti or stomach space; an infinite supply and an infinite demand are assumed. The problem is how to design a discipline of behavior such that no philosopher will starve; i.e., each can forever continue to alternate between eating and thinking, without any deadlock.

#### *NUMBER OF WAYS TO RESOLVE THIS PROBLEM:*
- Allows at most four philosophers who sit together at one table
- Allows a philosopher to take chopsticks only if both chopsticks are there
- Using asymmetric solutions, philosophers in odd numbers took a left chopstick first and then a right chopstick. While philosophers in even numbers take the right chopstick first and then the left chopstick

## OPERATING SYSTEM IMPLEMENTATION:

We have utilized Semaphore and Threads to exhibit and take care of the issue. One straightforward arrangement is to address every chopstick with a semaphore. A philosopher attempts to get a chopstick by executing a wait () procedure on that semaphore so that not more than one philosopher can eat at a time. The philosopher delivers his chopsticks by executing the signal () procedure on the semaphores. Philosophers in odd numbers take the left chopstick first and then the right chopstick. Whereas, philosophers in even numbers take the right chopstick first and then the left chopstick.

## PROJECT OUTCOME:

The main objective of this project was to learn the use of semaphores and threads and to understand the concept of deadlock, race conditions, resource allocation, and process synchronization.

## PROJECT RECORDING:

[Dining_Philosophers_Problem_Recording](https://www.loom.com/share/d537b4b1d03441ba8f1feedac357d62a?sid=27666a5e-c0fb-43ae-ac14-b5c44f51ef25)
