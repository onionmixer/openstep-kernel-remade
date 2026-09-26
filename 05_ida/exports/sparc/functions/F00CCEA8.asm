F00CCEA8: 9de3bf90                 save    %sp, -0x70, %sp
F00CCEAC: a0100018                 mov     %i0, %l0
F00CCEB0: b0102000                 mov     0, %i0
F00CCEB4: 9010001a                 mov     %i2, %o0! __s1
F00CCEB8: 133c03d3                 sethi   %hi(_IFCONTROL_SETFLAGS), %o1! "setflags"
F00CCEBC: 7ffcecbc                 call    _strcmp
F00CCEC0: 921260d0                 bset    %lo(_IFCONTROL_SETFLAGS), %o1! "setflags"
F00CCEC4: 80a22000                 cmp     %o0, 0
F00CCEC8: 0280000c                 be      locret_F00CCEF8
F00CCECC: 9010001a                 mov     %i2, %o0! __s1
F00CCED0: 133c03d3                 sethi   %hi(_IFCONTROL_GETADDR), %o1! "getaddr"
F00CCED4: 7ffcecb6                 call    _strcmp
F00CCED8: 921260e8                 bset    %lo(_IFCONTROL_GETADDR), %o1! "getaddr"
F00CCEDC: 80a22000                 cmp     %o0, 0
F00CCEE0: 32800006                 bne,a   locret_F00CCEF8
F00CCEE4: b0102016                 mov     0x16, %i0
F00CCEE8: 9004213c                 add     %l0, 0x13C, %o0! void *
F00CCEEC: 9210001b                 mov     %i3, %o1! void *
F00CCEF0: 7fff1f08                 call    _bcopy
F00CCEF4: 94102006                 mov     6, %o2
F00CCEF8: 81c7e008                 ret
F00CCEFC: 81e80000                 restore
