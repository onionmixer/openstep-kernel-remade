F0059764: 9de3bf90                 save    %sp, -0x70, %sp
F0059768: a0100018                 mov     %i0, %l0
F005976C: 90100010                 mov     %l0, %o0
F0059770: 92100019                 mov     %i1, %o1
F0059774: 7fffe8ed                 call    _ipc_entry_alloc
F0059778: 9407bff4                 add     %fp, var_C, %o2
F005977C: 80a22000                 cmp     %o0, 0
F0059780: 1280000a                 bne     locret_F00597A8
F0059784: b0100008                 mov     %o0, %i0
F0059788: d007bff4                 ld      [%fp+var_C], %o0
F005978C: 13000400                 sethi   0x100000, %o1
F0059790: d4020000                 ld      [%o0], %o2
F0059794: 92126001                 bset    1, %o1
F0059798: 94128009                 bset    %o1, %o2
F005979C: d4220000                 st      %o2, [%o0]
F00597A0: c0242008                 clr     [%l0+8]
F00597A4: b0102000                 mov     0, %i0
F00597A8: 81c7e008                 ret
F00597AC: 81e80000                 restore
