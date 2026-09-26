F0090BF0: 9de3bf98                 save    %sp, -0x68, %sp
F0090BF4: 80a62000                 cmp     %i0, 0
F0090BF8: 12800004                 bne     loc_F0090C08
F0090BFC: 90100019                 mov     %i1, %o0! __s
F0090C00: 10800019                 ba      locret_F0090C64
F0090C04: b0103d3f                 mov     -0x2C1, %i0
F0090C08: 80a6afff                 cmp     %i2, 0xFFF
F0090C0C: 38800002                 bgu,a   loc_F0090C14
F0090C10: b4102fff                 mov     0xFFF, %i2
F0090C14: 4000cbdc                 call    _findBootConfigString
F0090C18: 01000000                 nop
F0090C1C: b0920000                 orcc    %o0, %g0, %i0
F0090C20: 12800004                 bne     loc_F0090C30
F0090C24: 01000000                 nop
F0090C28: 1080000f                 ba      locret_F0090C64
F0090C2C: b0103d40                 mov     -0x2C0, %i0
F0090C30: 7ffdda02                 call    _strlen
F0090C34: 90100018                 mov     %i0, %o0
F0090C38: 80a68008                 cmp     %i2, %o0
F0090C3C: 38800002                 bgu,a   loc_F0090C44
F0090C40: b4100008                 mov     %o0, %i2
F0090C44: 90100018                 mov     %i0, %o0! void *
F0090C48: 9210001b                 mov     %i3, %o1! void *
F0090C4C: 40000fb1                 call    _bcopy
F0090C50: 9410001a                 mov     %i2, %o2
F0090C54: c02ec01a                 clrb    [%i3+%i2]
F0090C58: 9006a001                 add     %i2, 1, %o0
F0090C5C: d0270000                 st      %o0, [%i4]
F0090C60: b0102000                 mov     0, %i0
F0090C64: 81c7e008                 ret
F0090C68: 81e80000                 restore
