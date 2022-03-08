void main(void)
{
    undefined4 uVar1;
    undefined4 uVar2;
    int argc;
    char **argv;
    char **envp;
    
    uVar1 = getegid();
    uVar2 = geteuid();
    setresgid(uVar1, uVar1, uVar1);
    setresuid(uVar2, uVar2, uVar2);
    system("/usr/bin/env echo Exploit me");
    return;
}
