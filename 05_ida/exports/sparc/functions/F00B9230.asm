F00B9230: 9de3bf50                 save    %sp, -0xB0, %sp
F00B9234: a6100018                 mov     %i0, %l3
F00B9238: e407a05c                 ld      [%fp+arg_5C], %l2
F00B923C: 80a4a001                 cmp     %l2, 1
F00B9240: 02800005                 be      loc_F00B9254
F00B9244: b0102000                 mov     0, %i0
F00B9248: 80a4a000                 cmp     %l2, 0
F00B924C: 12800028                 bne     locret_F00B92EC
F00B9250: 01000000                 nop
F00B9254: 80a66000                 cmp     %i1, 0
F00B9258: 02800025                 be      locret_F00B92EC
F00B925C: a007bfb0                 add     %fp, var_50, %l0
F00B9260: c0264000                 clr     [%i1]
F00B9264: 90100010                 mov     %l0, %o0! void *
F00B9268: 7fff6efc                 call    _bzero
F00B926C: 92102044                 mov     0x44, %o1 ! 'D'
F00B9270: 293c04f6                 sethi   %hi(_iopbmap), %l4
F00B9274: d0052300                 ld      [%l4+%lo(_iopbmap)], %o0
F00B9278: 92072003                 add     %i4, 3, %o1
F00B927C: a20a7ffc                 and     %o1, -4, %l1
F00B9280: 7fffaef8                 call    _rmalloc
F00B9284: 92100011                 mov     %l1, %o1
F00B9288: 80a22000                 cmp     %o0, 0
F00B928C: 12800004                 bne     loc_F00B929C
F00B9290: d027bfd0                 st      %o0, [%fp+var_30]
F00B9294: 10800016                 ba      locret_F00B92EC
F00B9298: b0102000                 mov     0, %i0
F00B929C: 80a76000                 cmp     %i5, 0
F00B92A0: 02800003                 be      loc_F00B92AC
F00B92A4: 90102001                 mov     1, %o0
F00B92A8: d027bfb0                 st      %o0, [%fp+var_50]
F00B92AC: f827bfc4                 st      %i4, [%fp+var_3C]
F00B92B0: 90100013                 mov     %l3, %o0
F00B92B4: 9210001a                 mov     %i2, %o1
F00B92B8: 9410001b                 mov     %i3, %o2
F00B92BC: 96100010                 mov     %l0, %o3
F00B92C0: 7ffffd1b                 call    _scsi_resalloc
F00B92C4: 98100012                 mov     %l2, %o4
F00B92C8: b0920000                 orcc    %o0, %g0, %i0
F00B92CC: 12800007                 bne     loc_F00B92E8
F00B92D0: d007bfd0                 ld      [%fp+var_30], %o0
F00B92D4: d0052300                 ld      [%l4+0x300], %o0
F00B92D8: d407bfd0                 ld      [%fp+var_30], %o2
F00B92DC: 7fffaf0e                 call    _rmfree
F00B92E0: 92100011                 mov     %l1, %o1
F00B92E4: 30800002                 ba,a    locret_F00B92EC
F00B92E8: d0264000                 st      %o0, [%i1]
F00B92EC: 81c7e008                 ret
F00B92F0: 81e80000                 restore
