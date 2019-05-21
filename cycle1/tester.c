struct msg{
    long m
    char mnesf[]1;
}message;

key_t k;
k=ftok("khvskd",65);
msgid = msgget(k,0666 | IPC_CREAT);
messag.m=1;
msgsnd(msgid,&message,1)