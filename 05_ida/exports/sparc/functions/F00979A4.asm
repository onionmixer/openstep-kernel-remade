F00979A4: 9de3bf90                 save    %sp, -0x70, %sp
F00979A8: a4100019                 mov     %i1, %l2
F00979AC: a610001a                 mov     %i2, %l3
F00979B0: 80a62000                 cmp     %i0, 0
F00979B4: 12800013                 bne     locret_F0097A00
F00979B8: 01000000                 nop
F00979BC: 7ffffc73                 call    _splusclock
F00979C0: 01000000                 nop
F00979C4: a0100008                 mov     %o0, %l0
F00979C8: 7fffffd0                 call    _clock_value
F00979CC: 90102001                 mov     1, %o0
F00979D0: 92a4c009                 subcc   %l3, %o1, %o1
F00979D4: 90648008                 subc    %l2, %o0, %o0
F00979D8: 153c04c5                 sethi   %hi(qword_F0131468), %o2
F00979DC: d03aa068                 std     %o0, [%o2+%lo(qword_F0131468)]
F00979E0: 7ffffcd1                 call    _splx
F00979E4: 90100010                 mov     %l0, %o0
F00979E8: 90100012                 mov     %l2, %o0
F00979EC: 92100013                 mov     %l3, %o1
F00979F0: 7fff59f9                 call    _ns_time_to_timeval
F00979F4: 9407bff0                 add     %fp, var_10, %o2
F00979F8: 400036cc                 call    _set_tod
F00979FC: d007bff0                 ld      [%fp+var_10], %o0
F0097A00: 81c7e008                 ret
F0097A04: 81e80000                 restore
