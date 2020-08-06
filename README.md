# OSProjects

## Final work how to run:

### q2: 
  #### q21
  - navigate to the directory of q21 in terminal
  - run `make all`

  for check pid run the following commands
  - `./check_pid <pid number>`

  #### q22
  - navigate to the directory of q22 in terminal
  - run `make all`

  for checking signals with client and server run the following commands:
  - `./server` // on the first terminal
  - `ps -a | grep server` // then take the pid of the server
  - `./client <pid of the server> 2 10000` // on the second terminal
  - `./client <pid of the server> 10 1` // on the second terminal

### q3: 
  Policy codes : SCHED_OTHER - 0 , SCHED_FIFO - 1 , SCHED_RR - 2 , SCHED_IDLE - 5 , SCHED_DEADLINE - 6

  - navigate to the directory of q3 in terminal
  - run `make all`
  - run `./set_policy <number of policy from the list above> <number of priority>` // to see valid priorities to each policy please run first `chrt -m`
  - if you want to check process policy and priority , please run `chrt -p <pid>`
