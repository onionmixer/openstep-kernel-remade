F00C6D30: 9de3bf90                 save    %sp, -0x70, %sp
F00C6D34: 113c0504                 sethi   %hi(paIsinstanceopen), %o0! id
F00C6D38: d2022174                 ld      [%o0+%lo(paIsinstanceopen)], %o1! SEL
F00C6D3C: 4000aacd                 call    _objc_msgSend
F00C6D40: 90100018                 mov     %i0, %o0
F00C6D44: 912a2018                 sll     %o0, 24, %o0
F00C6D48: 80a22000                 cmp     %o0, 0
F00C6D4C: 02800004                 be      loc_F00C6D5C
F00C6D50: 113c0506                 sethi   -0xFEBE800, %o0
F00C6D54: 10800012                 ba      locret_F00C6D9C
F00C6D58: b0102001                 mov     1, %i0
F00C6D5C: e0022198                 ld      [%o0+0x198], %l0
F00C6D60: 90100018                 mov     %i0, %o0! id
F00C6D64: 4000aac3                 call    _objc_msgSend
F00C6D68: 92100010                 mov     %l0, %o1! SEL
F00C6D6C: 80a22000                 cmp     %o0, 0
F00C6D70: 12800004                 bne     loc_F00C6D80
F00C6D74: 90100018                 mov     %i0, %o0! id
F00C6D78: 10800009                 ba      locret_F00C6D9C
F00C6D7C: b0102000                 mov     0, %i0
F00C6D80: 4000aabc                 call    _objc_msgSend
F00C6D84: 92100010                 mov     %l0, %o1
F00C6D88: 133c0506                 sethi   %hi(paIsopen), %o1! SEL
F00C6D8C: 4000aab9                 call    _objc_msgSend
F00C6D90: d2026194                 ld      [%o1+%lo(paIsopen)], %o1
F00C6D94: 912a2018                 sll     %o0, 24, %o0
F00C6D98: b13a2018                 sra     %o0, 24, %i0
F00C6D9C: 81c7e008                 ret
F00C6DA0: 81e80000                 restore
