F0012E18: 9de3bf98                 save    %sp, -0x68, %sp
F0012E1C: 40020f5b                 call    _splusclock
F0012E20: 01000000                 nop
F0012E24: a0100008                 mov     %o0, %l0
F0012E28: 90100018                 mov     %i0, %o0
F0012E2C: 92102001                 mov     1, %o1
F0012E30: 40017873                 call    _thread_wakeup_prim
F0012E34: 94102000                 mov     0, %o2
F0012E38: 40020fbb                 call    _splx
F0012E3C: 90100010                 mov     %l0, %o0
F0012E40: 81c7e008                 ret
F0012E44: 81e80000                 restore
