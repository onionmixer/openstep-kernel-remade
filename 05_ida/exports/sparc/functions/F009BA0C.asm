F009BA0C: 9de3bf98                 save    %sp, -0x68, %sp
F009BA10: 113c04f7                 sethi   %hi(_pcb_zone), %o0
F009BA14: 7fff75ae                 call    _zalloc
F009BA18: d0022200                 ld      [%o0+%lo(_pcb_zone)], %o0! void *
F009BA1C: a0100008                 mov     %o0, %l0
F009BA20: e0262028                 st      %l0, [%i0+0x28]
F009BA24: 7fffe50d                 call    _bzero
F009BA28: 921022a4                 mov     0x2A4, %o1
F009BA2C: 7ffff9a1                 call    _ipltospl
F009BA30: 9010200a                 mov     0xA, %o0
F009BA34: 901220a0                 bset    0xA0, %o0
F009BA38: d0242008                 st      %o0, [%l0+8]
F009BA3C: 90102080                 mov     0x80, %o0
F009BA40: d0242234                 st      %o0, [%l0+0x234]
F009BA44: 81c7e008                 ret
F009BA48: 81e80000                 restore
