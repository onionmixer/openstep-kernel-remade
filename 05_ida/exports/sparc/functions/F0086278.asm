F0086278: 9de3bf88                 save    %sp, -0x78, %sp
F008627C: 80a6e000                 cmp     %i3, 0
F0086280: 12800005                 bne     loc_F0086294
F0086284: a2100018                 mov     %i0, %l1
F0086288: c0274000                 clr     [%i5]
F008628C: 10800025                 ba      locret_F0086320
F0086290: b0102000                 mov     0, %i0
F0086294: c027bff4                 clr     [%fp+address]
F0086298: 9010001a                 mov     %i2, %o0! target_task
F008629C: 9207bff4                 add     %fp, address, %o1! address
F00862A0: 153c04d0                 sethi   %hi(_page_mask), %o2
F00862A4: da02a0d8                 ld      [%o2+%lo(_page_mask)], %o5
F00862A8: 96102001                 mov     1, %o3! flags
F00862AC: 9838000d                 xnor    %g0, %o5, %o4
F00862B0: a00e400c                 and     %i1, %o4, %l0
F00862B4: 9406401b                 add     %i1, %i3, %o2
F00862B8: 9402800d                 add     %o2, %o5, %o2
F00862BC: 940a800c                 and     %o2, %o4, %o2! size
F00862C0: b6228010                 sub     %o2, %l0, %i3
F00862C4: 40001157                 call    _vm_allocate
F00862C8: 9410001b                 mov     %i3, %o2
F00862CC: b0920000                 orcc    %o0, %g0, %i0
F00862D0: 12800014                 bne     locret_F0086320
F00862D4: 9010001a                 mov     %i2, %o0
F00862D8: 92100011                 mov     %l1, %o1
F00862DC: d407bff4                 ld      [%fp+address], %o2! size
F00862E0: 9610001b                 mov     %i3, %o3
F00862E4: 98100010                 mov     %l0, %o4
F00862E8: 9a102000                 mov     0, %o5
F00862EC: 7ffffcd1                 call    _vm_map_copy
F00862F0: f823a05c                 st      %i4, [%sp+0x78+var_1C]
F00862F4: b0920000                 orcc    %o0, %g0, %i0
F00862F8: 12800007                 bne     loc_F0086314
F00862FC: 9010001a                 mov     %i2, %o0
F0086300: d007bff4                 ld      [%fp+address], %o0
F0086304: 92264010                 sub     %i1, %l0, %o1
F0086308: 90020009                 add     %o0, %o1, %o0! target_task
F008630C: 10800005                 ba      locret_F0086320
F0086310: d0274000                 st      %o0, [%i5]
F0086314: d207bff4                 ld      [%fp+address], %o1! address
F0086318: 40001162                 call    _vm_deallocate
F008631C: 9410001b                 mov     %i3, %o2
F0086320: 81c7e008                 ret
F0086324: 81e80000                 restore
