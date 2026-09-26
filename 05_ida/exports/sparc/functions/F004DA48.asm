F004DA48: 9de3bf98                 save    %sp, -0x68, %sp
F004DA4C: 90100018                 mov     %i0, %o0! void *
F004DA50: 40011d02                 call    _bzero
F004DA54: 92102028                 mov     0x28, %o1 ! '('
F004DA58: 7ffffdb1                 call    sub_F004D11C
F004DA5C: 90100018                 mov     %i0, %o0
F004DA60: 90062010                 add     %i0, 0x10, %o0
F004DA64: d0262014                 st      %o0, [%i0+0x14]
F004DA68: d0262010                 st      %o0, [%i0+0x10]
F004DA6C: 90102014                 mov     0x14, %o0
F004DA70: d0262018                 st      %o0, [%i0+0x18]
F004DA74: c0262024                 clr     [%i0+0x24]
F004DA78: 81c7e008                 ret
F004DA7C: 81e80000                 restore
