F00AFE10: 9de3bf98                 save    %sp, -0x68, %sp
F00AFE14: 90100018                 mov     %i0, %o0! __s
F00AFE18: 7ffd552c                 call    _strrchr
F00AFE1C: 9210202f                 mov     0x2F, %o1 ! '/'! __c
F00AFE20: 80a22000                 cmp     %o0, 0
F00AFE24: 22800008                 be,a    locret_F00AFE44
F00AFE28: b0102000                 mov     0, %i0
F00AFE2C: 7ffd5527                 call    _strrchr
F00AFE30: 9210203a                 mov     0x3A, %o1 ! ':'
F00AFE34: 80a22000                 cmp     %o0, 0
F00AFE38: 12800003                 bne     locret_F00AFE44
F00AFE3C: b0022001                 add     %o0, 1, %i0
F00AFE40: b0102000                 mov     0, %i0
F00AFE44: 81c7e008                 ret
F00AFE48: 81e80000                 restore
