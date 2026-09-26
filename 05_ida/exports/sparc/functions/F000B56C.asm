F000B56C: 9de3bf98                 save    %sp, -0x68, %sp
F000B570: 92100018                 mov     %i0, %o1
F000B574: d6024000                 ld      [%o1], %o3
F000B578: d4026004                 ld      [%o1+4], %o2
F000B57C: 193c04d090132058         set     _file_list, %o0
F000B584: 80a28008                 cmp     %o2, %o0
F000B588: 12800004                 bne     loc_F000B598
F000B58C: d422e004                 st      %o2, [%o3+4]
F000B590: 10800003                 ba      loc_F000B59C
F000B594: d6232058                 st      %o3, [%o4+0x58]
F000B598: d6228000                 st      %o3, [%o2]
F000B59C: 113c04d2                 sethi   %hi(_file_zone), %o0
F000B5A0: 4001b70c                 call    _zfree
F000B5A4: d0022230                 ld      [%o0+%lo(_file_zone)], %o0
F000B5A8: 81c7e008                 ret
F000B5AC: 81e80000                 restore
