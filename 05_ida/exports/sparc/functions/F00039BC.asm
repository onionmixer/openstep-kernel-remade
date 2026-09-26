F00039BC: 033c041882106000         set     _kernel_stack, %g1
F00039C4: 80a38001                 cmp     %sp, %g1
F00039C8: 38800002                 bgu,a   loc_F00039D0
F00039CC: 9c206060                 sub     %g1, 0x60, %sp ! '`'
F00039D0: aa2c2f00                 andn    %l0, 0xF00, %l5
F00039D4: a80d200f                 and     %l4, 0xF, %l4
F00039D8: 832d2008                 sll     %l4, 8, %g1
F00039DC: a0154001                 or      %l5, %g1, %l0
F00039E0: 80a06f00                 cmp     %g1, 0xF00
F00039E4: 12800005                 bne     loc_F00039F8
F00039E8: ad2d2002                 sll     %l4, 2, %l6
F00039EC: 11200000                 sethi   0x80000000, %o0
F00039F0: 40024d3e                 call    _set_intmask
F00039F4: 92102000                 mov     0, %o1
F00039F8: 90100000                 clr     %o0
F00039FC: 912a200c                 sll     %o0, 12, %o0
F0003A00: 033fbfd082004008         set     -0x100C000, %g1
F0003A08: d0004000                 ld      [%g1], %o0
F0003A0C: 13000040                 sethi   0x10000, %o1
F0003A10: 932a4014                 sll     %o1, %l4, %o1
F0003A14: 808a0009                 btst    %o1, %o0
F0003A18: 32800006                 bne,a   loc_F0003A30
F0003A1C: ac05a040                 inc     0x40, %l6 ! '@'
F0003A20: 93326010                 srl     %o1, 16, %o1
F0003A24: 808a0009                 btst    %o1, %o0
F0003A28: 22bffe9e                 be,a    sys_rtt
F0003A2C: 9c100017                 mov     %l7, %sp
F0003A30: 273fffe0                 sethi   -0x8000, %l3
F0003A34: 808a4013                 btst    %l3, %o1
F0003A38: 32800002                 bne,a   loc_F0003A40
F0003A3C: d2206004                 st      %o1, [%g1+4]
F0003A40: 32800002                 bne,a   loc_F0003A48
F0003A44: c0004000                 ld      [%g1], %g0
F0003A48: 033c0428821062e8         set     _int_vector, %g1
F0003A50: e6004016                 ld      [%g1+%l6], %l3
F0003A54: 293fbfe0                 sethi   -0x1008000, %l4
F0003A58: e8052000                 ld      [%l4], %l4
F0003A5C: 818c0000                 saved
F0003A60: 818c2020                 saved
F0003A64: 01000000                 nop
F0003A68: 01000000                 nop
F0003A6C: 01000000                 nop
F0003A70: 808c2040                 btst    0x40, %l0 ! '@'
F0003A74: 32800006                 bne,a   loc_F0003A8C
F0003A78: ac05e05c                 add     %l7, 0x5C, %l6 ! '\'
F0003A7C: 0b3c04288a116024         set     _active_pcb, %g5
F0003A84: ca014000                 ld      [%g5], %g5
F0003A88: ac016234                 add     %g5, 0x234, %l6
F0003A8C: 9fc4c000                 call    %l3
F0003A90: 01000000                 nop
F0003A94: 40024db8                 call    _flush_writebuffers_to
F0003A98: 01000000                 nop
F0003A9C: 10bffe81                 ba      sys_rtt
F0003AA0: 9c100017                 mov     %l7, %sp
