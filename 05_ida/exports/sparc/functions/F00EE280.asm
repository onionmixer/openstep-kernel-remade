F00EE280: 9de3be98                 save    %sp, -0x168, %sp
F00EE284: 90066001                 add     %i1, 1, %o0! __size
F00EE288: 80a22100                 cmp     %o0, 0x100
F00EE28C: 04800005                 ble     loc_F00EE2A0
F00EE290: a007bef8                 add     %fp, var_108, %l0
F00EE294: 7ffde7e7                 call    _malloc
F00EE298: 01000000                 nop
F00EE29C: a0100008                 mov     %o0, %l0
F00EE2A0: 90100010                 mov     %l0, %o0! buffer
F00EE2A4: 92100018                 mov     %i0, %o1! __src
F00EE2A8: 7ffc674a                 call    _memmove
F00EE2AC: 94100019                 mov     %i1, %o2
F00EE2B0: c02c0019                 clrb    [%l0+%i1]
F00EE2B4: 7fffffa3                 call    _NXUniqueString
F00EE2B8: 90100010                 mov     %l0, %o0
F00EE2BC: b0100008                 mov     %o0, %i0
F00EE2C0: 90066001                 add     %i1, 1, %o0! void *
F00EE2C4: 80a22100                 cmp     %o0, 0x100
F00EE2C8: 04800004                 ble     locret_F00EE2D8
F00EE2CC: 01000000                 nop
F00EE2D0: 7ffde80c                 call    _free
F00EE2D4: 90100010                 mov     %l0, %o0
F00EE2D8: 81c7e008                 ret
F00EE2DC: 81e80000                 restore
