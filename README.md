# OSProjects

## Final work how to run:

### q2: 
- run `make all`

for check pid run the following commands
- `./check_pid <pid number>`

for checking signals with client and server run the following commands:
- `./server // on the first terminal`
- `ps -a | grep server // then take the pid of the server`
- `./client <pid of the server> 2 10000 // on the second terminal`
- `./client <pid of the server> 10 1 // on the second terminal`
