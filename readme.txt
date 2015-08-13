Raymond Luu

As of right now my code does not work at all. I encountered many problems that I was unable to solve. I looked online for examples of mqueues and how it was being utilized and got a hold of an example that did it so perfectly. I understood what was going on and tried to implement it with this assignment. So far the only difficulty I am having is getting my queue to set up properly. I am facing this error in my mq_open method where errno was returning 13 and saying that the queue exists and I don't have permission for it or the name contains one too many slashes. Neither of those were the case in my code so I gave up there. I have encountered other problems with different errors but I was able to find my mistake and fix it but got to this point and it made no sense to me why I was receiving this error so I stopped there. I used ipcs to see if there were any message queues still openned but none were open.

I was able to get the file parsing to do what I need and get the information to send over. I have also set up the message queue in each section to open, send, and receive. It just doesn't seem to be working properly.

The last thing that I was struggling with a lot is how to make things go in order. Example using the sleeps to delay things to go in order. I was never able to get to this since I was getting errors with my queue.

I hope to continue working on this to get it working as I have been struggling and feel like I am very close to finishing it. I would like to visit during office hours to get this sorted out.

Other than that this assignment has been a huge learning experience for me.