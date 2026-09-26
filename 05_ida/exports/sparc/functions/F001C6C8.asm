F001C6C8: 9de3bf98                 save    %sp, -0x68, %sp
F001C6CC: 4001e93b                 call    _spltty
F001C6D0: 01000000                 nop
F001C6D4: d2060000                 ld      [%i0], %o1
F001C6D8: 80a26000                 cmp     %o1, 0
F001C6DC: 14800007                 bg      loc_F001C6F8
F001C6E0: a4100008                 mov     %o0, %l2
F001C6E4: a2103fff                 mov     -1, %l1
F001C6E8: c0260000                 clr     [%i0]
F001C6EC: c0262008                 clr     [%i0+8]
F001C6F0: 10800040                 ba      loc_F001C7F0
F001C6F4: c0262004                 clr     [%i0+4]
F001C6F8: d6062004                 ld      [%i0+4], %o3
F001C6FC: 940ae03f                 and     %o3, 0x3F, %o2
F001C700: 90928000                 orcc    %o2, %g0, %o0
F001C704: e20ac000                 ldub    [%o3], %l1
F001C708: 16800003                 bge     loc_F001C714
F001C70C: 920affc0                 and     %o3, -0x40, %o1
F001C710: 9002a007                 add     %o2, 7, %o0
F001C714: 913a2003                 sra     %o0, 3, %o0
F001C718: 92020009                 add     %o0, %o1, %o1
F001C71C: d24a6004                 ldsb    [%o1+4], %o1
F001C720: 912a2003                 sll     %o0, 3, %o0
F001C724: 90228008                 sub     %o2, %o0, %o0
F001C728: 933a4008                 sra     %o1, %o0, %o1
F001C72C: 808a6001                 btst    1, %o1
F001C730: 32800002                 bne,a   loc_F001C738
F001C734: a2146100                 bset    0x100, %l1
F001C738: 9202e001                 add     %o3, 1, %o1
F001C73C: d0060000                 ld      [%i0], %o0
F001C740: d2262004                 st      %o1, [%i0+4]
F001C744: 90023fff                 inc     -1, %o0
F001C748: 80a22000                 cmp     %o0, 0
F001C74C: 14800012                 bg      loc_F001C794
F001C750: d0260000                 st      %o0, [%i0]
F001C754: c0262008                 clr     [%i0+8]
F001C758: 133c043c                 sethi   %hi(_cfreelist), %o1
F001C75C: 153c043c                 sethi   %hi(_cfreecount), %o2
F001C760: d0062004                 ld      [%i0+4], %o0
F001C764: 213c04d4                 sethi   %hi(_cwaiting), %l0
F001C768: 98023fff                 add     %o0, -1, %o4
F001C76C: 980b3fc0                 and     %o4, -0x40, %o4
F001C770: d002638c                 ld      [%o1+%lo(_cfreelist)], %o0
F001C774: c0262004                 clr     [%i0+4]
F001C778: d0230000                 st      %o0, [%o4]
F001C77C: d002a390                 ld      [%o2+%lo(_cfreecount)], %o0
F001C780: d822638c                 st      %o4, [%o1+%lo(_cfreelist)]
F001C784: d24c22b0                 ldsb    [%l0+%lo(_cwaiting)], %o1
F001C788: 90022034                 inc     0x34, %o0 ! '4'
F001C78C: 10800013                 ba      loc_F001C7D8
F001C790: d022a390                 st      %o0, [%o2+%lo(_cfreecount)]
F001C794: d6062004                 ld      [%i0+4], %o3
F001C798: 808ae03f                 btst    0x3F, %o3 ! '?'
F001C79C: 12800015                 bne     loc_F001C7F0
F001C7A0: 9802ffc0                 add     %o3, -0x40, %o4
F001C7A4: 153c043c                 sethi   %hi(_cfreelist), %o2
F001C7A8: d002ffc0                 ld      [%o3-0x40], %o0
F001C7AC: 213c04d4                 sethi   %hi(_cwaiting), %l0
F001C7B0: d202a38c                 ld      [%o2+%lo(_cfreelist)], %o1
F001C7B4: 9002200c                 inc     0xC, %o0
F001C7B8: d0262004                 st      %o0, [%i0+4]
F001C7BC: d222ffc0                 st      %o1, [%o3-0x40]
F001C7C0: 173c043c                 sethi   %hi(_cfreecount), %o3
F001C7C4: d002e390                 ld      [%o3+%lo(_cfreecount)], %o0
F001C7C8: d822a38c                 st      %o4, [%o2+%lo(_cfreelist)]
F001C7CC: d24c22b0                 ldsb    [%l0+%lo(_cwaiting)], %o1
F001C7D0: 90022034                 inc     0x34, %o0 ! '4'
F001C7D4: d022e390                 st      %o0, [%o3+%lo(_cfreecount)]
F001C7D8: 80a26000                 cmp     %o1, 0
F001C7DC: 02800005                 be      loc_F001C7F0
F001C7E0: 901422b0                 or      %l0, 0x2B0, %o0
F001C7E4: 7fffd981                 call    _wakeup
F001C7E8: 01000000                 nop
F001C7EC: c02c22b0                 clrb    [%l0+0x2B0]
F001C7F0: 4001e94d                 call    _splx
F001C7F4: 90100012                 mov     %l2, %o0
F001C7F8: 81c7e008                 ret
F001C7FC: 91e80011                 restore %g0, %l1, %o0
