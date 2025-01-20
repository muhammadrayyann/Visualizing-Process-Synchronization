#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/delay.h>
#include <linux/semaphore.h>
#define N 5 // Number of philosophers
// Semaphores representing chopsticks
static struct semaphore chopsticks[N];
// Task structures for philosopher threads
static struct task_struct *philosophers[N];
// Function for philosophers to simulate dining behavior
static int philosopher_thread(void *arg)
{
 int id = *(int *)arg;
 while (!kthread_should_stop())
 {
 printk(KERN_INFO "Philosopher %d is THINKING\n", id);
 msleep(500); // Simulate thinking time
 if (id % 2 == 0)
 {
 // Even philosopher picks the right chopstick first
 down(&chopsticks[(id + 1) % N]);
 printk(KERN_INFO "Philosopher %d picks up right chopstick %d\n", id, (id + 1) % N);
 down(&chopsticks[id]);
 printk(KERN_INFO "Philosopher %d picks up left chopstick %d\n", id, id);
 }
 else
 {
 // Odd philosopher picks the left chopstick first
 down(&chopsticks[id]);
 printk(KERN_INFO "Philosopher %d picks up left chopstick %d\n", id, id);
 down(&chopsticks[(id + 1) % N]);
 printk(KERN_INFO "Philosopher %d picks up right chopstick %d\n", id, (id + 1) % N);
 }
 printk(KERN_INFO "Philosopher %d is EATING\n", id);
 msleep(500); // Simulate eating time
 // Release chopsticks
 up(&chopsticks[id]);
 printk(KERN_INFO "Philosopher %d puts down left chopstick %d\n", id, id);
 up(&chopsticks[(id + 1) % N]);
 printk(KERN_INFO "Philosopher %d puts down right chopstick %d\n", id, (id + 1) % N);
 }
 return 0;
}
// Module initialization
static int __init dpp_init(void)
{
 int i;
 printk(KERN_INFO "Initializing Dining Philosophers Problem Module\n");
 // Initialize semaphores for chopsticks
 for (i = 0; i < N; i++)
 {
 sema_init(&chopsticks[i], 1);
 }
 // Create threads for philosophers
 for (i = 0; i < N; i++)
 {
 philosophers[i] = kthread_create(philosopher_thread, &i, "Philosopher-%d", i);
 if (philosophers[i])
 {
 wake_up_process(philosophers[i]);
 printk(KERN_INFO "Philosopher %d thread created\n", i);
 }
 else
 {
 printk(KERN_ERR "Failed to create thread for Philosopher %d\n", i);
 }
 msleep(10); // Small delay to avoid race conditions during thread creation
 }
 return 0;
}
// Module cleanup
static void __exit dpp_exit(void)
{
 int i;
 printk(KERN_INFO "Cleaning up Dining Philosophers Problem Module\n");
 // Stop philosopher threads
 for (i = 0; i < N; i++)
 {
 if (philosophers[i])
 {
 kthread_stop(philosophers[i]);
 printk(KERN_INFO "Philosopher %d thread stopped\n", i);
 }
 }
}
module_init(dpp_init);
module_exit(dpp_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("OpenAI");
MODULE_DESCRIPTION("Dining Philosophers Problem as a Linux Kernel Module");