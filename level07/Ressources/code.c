void main(void)
{
    undefined4 uVar1;
    int argc;
    char **argv;
    char **envp;
    undefined4 uStack28;
    undefined4 uStack24;
    undefined4 uStack20;
    
    uStack24 = getegid();
    uStack20 = geteuid();
    setresgid(uStack24, uStack24, uStack24);
    setresuid(uStack20, uStack20, uStack20);
    uStack28 = 0;
    uVar1 = getenv("LOGNAME");
    asprintf(&uStack28, "/bin/echo %s ", uVar1);
    system(uStack28);
    return;
}
