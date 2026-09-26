F00B0CC0: 9de3bf98                 save    %sp, -0x68, %sp
F00B0CC4: 90100018                 mov     %i0, %o0
F00B0CC8: 92100019                 mov     %i1, %o1
F00B0CCC: 40000012                 call    _walk_layer
F00B0CD0: 9410001a                 mov     %i2, %o2
F00B0CD4: 80a62000                 cmp     %i0, 0
F00B0CD8: 0280000d                 be      locret_F00B0D0C
F00B0CDC: 01000000                 nop
F00B0CE0: d0062008                 ld      [%i0+8], %o0
F00B0CE4: 80a22000                 cmp     %o0, 0
F00B0CE8: 22800006                 be,a    loc_F00B0D00
F00B0CEC: f0062004                 ld      [%i0+4], %i0
F00B0CF0: 92100019                 mov     %i1, %o1
F00B0CF4: 7ffffff3                 call    _walk_devs
F00B0CF8: 9410001a                 mov     %i2, %o2
F00B0CFC: f0062004                 ld      [%i0+4], %i0
F00B0D00: 80a62000                 cmp     %i0, 0
F00B0D04: 32bffff8                 bne,a   loc_F00B0CE4
F00B0D08: d0062008                 ld      [%i0+8], %o0
F00B0D0C: 81c7e008                 ret
F00B0D10: 81e80000                 restore
