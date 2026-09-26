F0097A7C: 9de3bf98                 save    %sp, -0x68, %sp
F0097A80: a0100019                 mov     %i1, %l0
F0097A84: a210001a                 mov     %i2, %l1
F0097A88: 80a62000                 cmp     %i0, 0
F0097A8C: 12800008                 bne     locret_F0097AAC
F0097A90: 01000000                 nop
F0097A94: 7fffff9d                 call    _clock_value
F0097A98: 90102001                 mov     1, %o0
F0097A9C: 92824011                 addcc   %o1, %l1, %o1
F0097AA0: 90420010                 addc    %o0, %l0, %o0
F0097AA4: 153c04c5                 sethi   %hi(qword_F0131488), %o2
F0097AA8: d03aa088                 std     %o0, [%o2+%lo(qword_F0131488)]
F0097AAC: 81c7e008                 ret
F0097AB0: 81e80000                 restore
