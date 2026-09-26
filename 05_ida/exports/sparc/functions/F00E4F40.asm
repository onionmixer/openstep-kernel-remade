F00E4F40: 9de3be40                 save    %sp, -0x1C0, %sp
F00E4F44: 9007bea0                 add     %fp, var_160, %o0
F00E4F48: 7fff2969                 call    _prom_stack_init
F00E4F4C: 92102154                 mov     0x154, %o1
F00E4F50: 7fff295c                 call    _prom_rootnode
F00E4F54: a0100008                 mov     %o0, %l0
F00E4F58: 92100018                 mov     %i0, %o1
F00E4F5C: 7fff2973                 call    _prom_findnode_byname
F00E4F60: 94100010                 mov     %l0, %o2
F00E4F64: b0920000                 orcc    %o0, %g0, %i0
F00E4F68: 22800004                 be,a    locret_F00E4F78
F00E4F6C: b0102000                 mov     0, %i0
F00E4F70: 7fff2968                 call    _prom_stack_fini
F00E4F74: 90100010                 mov     %l0, %o0
F00E4F78: 81c7e008                 ret
F00E4F7C: 81e80000                 restore
