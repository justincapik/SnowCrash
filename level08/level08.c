// address: 0x8048554
int main(__size32 argc, char[] **argv, char *envp[]) {
    __size32 eax; 		// r24
    size_t eax_2; 		// r24{100}
    int eax_3; 		// r24{75}
    __size32 eax_4; 		// r24{43}
    int edx; 		// r26
    int local0; 		// m[esp - 0x408]

    eax = *20;
    if (argc == 1) { // check there is in fact an argumant
        edx = *argv;
        printf("%s [file to read]\n", edx);
        exit(1);
    }
    eax = LOGNAME;
    strstr(eax, "token");
    if (eax_4 != 0) { // check if you can access it? don't undertsnad how it works exactly yet
        edx = LOGNAME;
        printf("You may not access '%s'\n", edx);
        exit(1);
    }
    eax = LOGNAME;
    open(eax, 0); // open file to read
    if (eax_3 == -1) { // check open worked
        err();
    }
    read(eax_3, &local0, 1024);
    if (eax_2 == -1) { // check read worked
        err();
    }
    write(1, &local0, eax_2); // write file contect
    edx = eax ^ *20;
    if (edx != 0) { // idk system stuff
        __stack_chk_fail();
    }
    return;
}

