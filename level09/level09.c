__size32 syscall_open(__size32 param1);
unsigned int syscall_gets(void *param1, unsigned int param2, void *param3);
__size32 isLib(int param1, unsigned int param2, void *param3, char param4, unsigned int param5);
union { unsigned int x3; unsigned char * x4; } afterSubstr(int param1, unsigned int param2, void *param3, char param4, unsigned int param5);

// address: 0x80487ce
int main(int argc, char *argv[], char *envp[]) {
    char dl; 		// r10
    int eax; 		// r24
    int eax_10; 		// r24{70}
    int eax_11; 		// r24{45}
    int eax_12; 		// r24{29}
    int eax_13; 		// r24{215}
    int eax_14; 		// r24{38}
    int eax_15; 		// r24{62}
    int eax_16; 		// r24{325}
    int eax_17; 		// r24{14}
    int eax_3; 		// r24{229}
    int eax_4; 		// r24{254}
    int eax_5; 		// r24{238}
    __size32 eax_6; 		// r24{139}
    int eax_7; 		// r24{123}
    int eax_8; 		// r24{266}
    int eax_9; 		// r24{95}
    void *ecx; 		// r25
    __size8 *edi; 		// r31
    int edx; 		// r26
    int esp; 		// r28
    int local0; 		// m[esp - 368]
    int local1; 		// m[esp - 336]
    int local13; 		// eax_16{325}
    int local14; 		// eax_15{338}
    int local15; 		// eax_15{349}
    int local2; 		// m[esp - 272]
    int local3; 		// m[esp - 280]
    unsigned int local4; 		// m[esp - 284]

    eax_17 = *20;
    local3 = 0;
    local4 = (unsigned int)-1;
    ptrace();
    if (eax_12 >= 0) {
        getenv("LD_PRELOAD");
        if (eax_11 == 0) {
            open("/etc/ld.so.preload", 0);
            if (eax_10 <= 0) {
                eax_9 = syscall_open(0); /* Warning: also results in ecx */
                if (eax_9 != -1) {
                    do {
L22:
                        eax_8 = syscall_gets(&local2, 256, ecx); /* Warning: also results in ecx, edx */
                        local13 = eax_8;
                        if (eax_8 == 0) {
                            goto L3;
                        }
                        eax_7 = isLib(local0, esp - 272, 0x8048c2b, dl, edx); /* Warning: also results in dl, edx */
                        if (eax_7 != 0) {
                            local3 = 1;
                            goto L22;
                        }
                        if (local3 == 0) {
                            continue;
                        }
                        eax_6 = isLib(local0, esp - 272, 0x8048c30, dl, edx); /* Warning: also results in dl, edx */
                        if (eax_6 != 0) {
                            if (argc != 2) {
                                eax = *0x804a040;
                                fwrite("You need to provied only one arg.\n", 1, 34, eax);
                                local13 = eax_3;
                                goto L3;
                            } else {
                                for(;;) {
                                    local4++;
                                    eax = *(argv + 4);
                                    ecx = -1;
                                    edi = eax;
                                    do {
                                        if (ecx == 0) {
                                            goto L10;
                                        }
                                        tmpb = 0 - *edi;
                                        edi +=  (DF == 0) ? 1 : -1;
                                        ecx = ecx - 1;
                                    } while (tmpb != 0);
L10:
                                    if (local4 >=  !ecx - 1) {
                                        fputc();
                                        local13 = eax_13;
                                        goto L3;
                                    }
                                    putchar();
                                }
                            }
                            goto L3;
                        }
                        eax_5 = afterSubstr(local1, esp - 272, 0x8048c57, dl, edx); /* Warning: also results in dl */
                    } while (eax_5 != 0);
                    eax = *0x804a040;
                    fwrite("LD_PRELOAD detected through memory maps exit ..\n", 1, 48, eax);
                    local13 = eax_4;
L3:
                    eax_16 = local13;
                    local14 = eax_16;
                } else {
                    eax = *0x804a040;
                    fwrite("/proc/self/maps is unaccessible, probably a LD_PRELOAD attempt exit..\n", 1, 70, eax);
                    eax_15 = 1;
                    local14 = eax_15;
                }
            } else {
                eax = *0x804a040;
                fwrite("Injection Linked lib detected exit..\n", 1, 37, eax);
                eax_15 = 1;
                local14 = eax_15;
            }
        } else {
            eax = *0x804a040;
            fwrite("Injection Linked lib detected exit..\n", 1, 37, eax);
            eax_15 = 1;
            local14 = eax_15;
        }
    } else {
        puts("You should not reverse this");
        eax_14 = 1;
        local14 = eax_14;
    }
    eax_15 = local14;
    edx = eax_17 ^ *20;
    local15 = eax_15;
    if (edx != 0) {
        __stack_chk_fail();
        local15 = eax;
    }
    eax_15 = local15;
    return eax_15;
}

// address: 0x80485a4
__size32 syscall_open(__size32 param1) {
    return 5; /* WARNING: Also returning: ecx := param1 */
}

// address: 0x80485d4
unsigned int syscall_gets(void *param1, unsigned int param2, void *param3) {
    unsigned int eax; 		// r24
    void *ecx; 		// r25
    unsigned int local0; 		// m[esp - 20]
    void *local1; 		// param3{80}
    void *local2; 		// ecx{91}

    local0 = 0;
    local1 = param3;
    param3 = local1;
    local2 = param3;
    if ((unsigned int)(param2 - 1) > local0) {
        ecx = param1 + local0;
        local1 = ecx;
        local2 = ecx;
        local2 = ecx;
    }
    ecx = local2;
    *(__size8*)(local0 + param1) = 0;
    return local0; /* WARNING: Also returning: ecx := ecx, edx := param1 */
}

// address: 0x80486cb
__size32 isLib(int param1, unsigned int param2, void *param3, char param4, unsigned int param5) {
    char dl; 		// r10
    unsigned char *eax; 		// r24
    unsigned int eax_1; 		// r24
    unsigned int edx; 		// r26
    void *edx_1; 		// r26
    union { unsigned int x5; void * x6; } edx_2; 		// r26
    int local3; 		// m[esp - 12]
    unsigned char *local4; 		// m[esp - 8]
    int local5; 		// m[esp - 16]
    union { unsigned int x5; void * x6; } local6; 		// edx_2{193}

    eax = afterSubstr(param1, param2, param3, param4, param5); /* Warning: also results in dl, edx */
    local6 = edx;
    local6 = edx;
    local6 = edx;
    local6 = edx;
    if (eax != 0) {
        eax_1 = *(unsigned char*)eax;
        if ((unsigned char) eax_1 == 45) {
            local3 = 0;
            local4 = eax + 1;
            eax_1 = *(unsigned char*)local4;
            while ((unsigned char) eax_1 > 47) {
                eax_1 = *(unsigned char*)local4;
                if ((unsigned char) eax_1 > 57) {
                    break;
                }
                local3 = 1;
                local4++;
                eax_1 = *(unsigned char*)local4;
            }
            if (local3 == 0) {
L1:
                eax = 0;
            } else {
                eax_1 = *(unsigned char*)local4;
                if ((unsigned char) eax_1 == 46) {
                    local3 = 0;
                    local4++;
                    eax_1 = *(unsigned char*)local4;
                    while ((unsigned char) eax_1 > 47) {
                        eax_1 = *(unsigned char*)local4;
                        if ((unsigned char) eax_1 > 57) {
                            break;
                        }
                        local3 = 1;
                        local4++;
                        eax_1 = *(unsigned char*)local4;
                    }
                    if (local3 != 0) {
                        local5 = 0;
                        edx_1 = *0x804a030;
                        dl = (unsigned char) edx_1;
                        eax_1 = *(unsigned char*)(local5 + edx_1);
                        local6 = edx_1;
                        while ((unsigned char) eax_1 != 0) {
                            edx_1 = *0x804a030;
                            edx = *(unsigned char*)(local5 + edx_1);
                            dl = (unsigned char) edx;
                            eax = local5 + local4;
                            eax_1 = *(unsigned char*)eax;
                            local6 = edx;
                            if ((unsigned char) edx != (unsigned char) eax_1) {
                                eax = 0;
                                goto L0;
                            }
                            local5++;
                            edx_1 = *0x804a030;
                            dl = (unsigned char) edx_1;
                            eax_1 = *(unsigned char*)(local5 + edx_1);
                            local6 = edx_1;
                        }
                        eax = 1;
                    } else {
                        eax = 0;
                    }
                } else {
                    goto L1;
                }
            }
        } else {
            eax = 0;
        }
    } else {
        eax = 0;
    }
L0:
    edx_2 = local6;
    return eax; /* WARNING: Also returning: dl := dl, edx_3 := edx_2 */
}

// address: 0x8048646
union { unsigned int x3; unsigned char * x4; } afterSubstr(int param1, unsigned int param2, void *param3, char param4, unsigned int param5) {
    unsigned char *eax; 		// r24
    union { unsigned int x3; unsigned char * x4; } eax_1; 		// r24
    unsigned int eax_2; 		// r24
    union { unsigned int x3; unsigned char * x4; } eax_3; 		// r24
    union { unsigned int x3; unsigned char * x4; } eax_4; 		// r24
    int local0; 		// m[esp - 12]
    unsigned int local1; 		// m[esp - 8]
    int local2; 		// m[esp - 16]
    union { unsigned int x3; unsigned char * x4; } local3; 		// m[esp - 8]
    union { unsigned int x3; unsigned char * x4; } local4; 		// m[esp - 8]
    union { unsigned int x3; unsigned char * x4; } local5; 		// local3{127}
    int local6; 		// param1{129}
    int local7; 		// local2{131}
    union { unsigned int x3; unsigned char * x4; } local8; 		// eax_4{119}

    local0 = 0;
    local1 = param2;
    local5 = local1;
    local6 = param1;
    local3 = local5;
    param1 = local6;
    eax_2 = *(unsigned char*)local3;
    local7 = param1;
    while ((unsigned char) eax_2 != 0) {
        local0 = 1;
        local2 = 0;
L11:
        local6 = local2;
        local7 = local2;
        if (local0 == 1) {
            eax = local2 + param3;
            eax_2 = *(unsigned char*)eax;
            if ((unsigned char) eax_2 != 0) {
                eax = local2 + param3;
                param5 = *(unsigned char*)eax;
                param4 = (unsigned char) param5;
                eax_1 = local2 + local3;
                eax_2 = *(unsigned char*)eax_1;
                if ((unsigned char) param5 != (unsigned char) eax_2) {
                    local0 = 0;
                }
                local2++;
                goto L11;
            }
        }
        if (local0 == 1) {
            goto L3;
        }
        local4 = local3 + 1;
        local5 = local4;
        local3 = local5;
        param1 = local6;
        eax_2 = *(unsigned char*)local3;
        local7 = param1;
    }
L3:
    local2 = local7;
    if (local0 != 0) {
        eax_3 = local2 + local3;
        local8 = eax_3;
    } else {
        eax = 0;
        local8 = eax;
    }
    eax_4 = local8;
    return eax_4; /* WARNING: Also returning: dl := param4, edx := param5 */
}


