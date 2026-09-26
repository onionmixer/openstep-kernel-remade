F00407D4: 9de3bf50                 save    %sp, -0xB0, %sp
F00407D8: a4100018                 mov     %i0, %l2
F00407DC: e604a030                 ld      [%l2+0x30], %l3
F00407E0: d014e060                 lduh    [%l3+0x60], %o0
F00407E4: 808a2008                 btst    8, %o0
F00407E8: 22800009                 be,a    loc_F004080C
F00407EC: d0064000                 ld      [%i1], %o0
F00407F0: d204e098                 ld      [%l3+0x98], %o1
F00407F4: d0066008                 ld      [%i1+8], %o0
F00407F8: 80a24008                 cmp     %o1, %o0
F00407FC: 32800004                 bne,a   loc_F004080C
F0040800: d0064000                 ld      [%i1], %o0
F0040804: 1080004e                 ba      locret_F004093C
F0040808: b0102000                 mov     0, %i0
F004080C: d2066004                 ld      [%i1+4], %o1
F0040810: 80a26001                 cmp     %o1, 1
F0040814: 02800004                 be      loc_F0040824
F0040818: e2022004                 ld      [%o0+4], %l1
F004081C: 10800048                 ba      locret_F004093C
F0040820: b0102016                 mov     0x16, %i0
F0040824: d004a024                 ld      [%l2+0x24], %o0
F0040828: d0022128                 ld      [%o0+0x128], %o0
F004082C: d002201c                 ld      [%o0+0x1C], %o0
F0040830: 80a44008                 cmp     %l1, %o0
F0040834: 2a800002                 bcs,a   loc_F004083C
F0040838: 90100011                 mov     %l1, %o0
F004083C: a2100008                 mov     %o0, %l1
F0040840: e227bff4                 st      %l1, [%fp+var_C]
F0040844: a007bfd0                 add     %fp, var_30, %l0
F0040848: d0066008                 ld      [%i1+8], %o0
F004084C: 92100010                 mov     %l0, %o1! size_t
F0040850: d027bff0                 st      %o0, [%fp+var_10]
F0040854: d004a030                 ld      [%l2+0x30], %o0! void *
F0040858: 94102020                 mov     0x20, %o2 ! ' '! size_t
F004085C: 400150ad                 call    _bcopy
F0040860: 90022040                 inc     0x40, %o0 ! '@'
F0040864: e227bfc4                 st      %l1, [%fp+var_3C]
F0040868: 40009e02                 call    _kalloc
F004086C: 90100011                 mov     %l1, %o0! void *
F0040870: d027bfcc                 st      %o0, [%fp+var_34]
F0040874: 40015179                 call    _bzero
F0040878: 92100011                 mov     %l1, %o1
F004087C: 92102010                 mov     0x10, %o1
F0040880: 153c01079412a2e4         set     _xdr_rddirargs, %o2
F0040888: 96100010                 mov     %l0, %o3
F004088C: 193c0108                 sethi   %hi(_xdr_getrddirres), %o4
F0040890: d004a024                 ld      [%l2+0x24], %o0
F0040894: 981320bc                 bset    %lo(_xdr_getrddirres), %o4
F0040898: d0022128                 ld      [%o0+0x128], %o0
F004089C: 9a07bfb8                 add     %fp, var_48, %o5
F00408A0: 7fffefb5                 call    _rfscall
F00408A4: f423a05c                 st      %i2, [%sp+0xB0+var_54]
F00408A8: b0920000                 orcc    %o0, %g0, %i0
F00408AC: 32800022                 bne,a   loc_F0040934
F00408B0: d007bfcc                 ld      [%fp+var_34], %o0
F00408B4: f007bfbc                 ld      [%fp+var_44], %i0
F00408B8: 80a62046                 cmp     %i0, 0x46 ! 'F'
F00408BC: 12800007                 bne     loc_F00408D8
F00408C0: 80a62000                 cmp     %i0, 0
F00408C4: 7fff930e                 call    _btrash
F00408C8: 90100012                 mov     %l2, %o0
F00408CC: 7fffe357                 call    _nfs_invalidate_caches
F00408D0: 90100012                 mov     %l2, %o0
F00408D4: 80a62000                 cmp     %i0, 0
F00408D8: 32800017                 bne,a   loc_F0040934
F00408DC: d007bfcc                 ld      [%fp+var_34], %o0
F00408E0: d207bfc4                 ld      [%fp+var_3C], %o1
F00408E4: 80a26000                 cmp     %o1, 0
F00408E8: 02800009                 be      loc_F004090C
F00408EC: 94102000                 mov     0, %o2
F00408F0: d007bfcc                 ld      [%fp+var_34], %o0
F00408F4: 7fff4689                 call    _uiomove
F00408F8: 96100019                 mov     %i1, %o3
F00408FC: d207bfc0                 ld      [%fp+var_40], %o1
F0040900: b0100008                 mov     %o0, %i0
F0040904: d227bff0                 st      %o1, [%fp+var_10]
F0040908: d2266008                 st      %o1, [%i1+8]
F004090C: d007bfc8                 ld      [%fp+var_38], %o0
F0040910: 80a22000                 cmp     %o0, 0
F0040914: 02800008                 be      loc_F0040934
F0040918: d007bfcc                 ld      [%fp+var_34], %o0
F004091C: d014e060                 lduh    [%l3+0x60], %o0
F0040920: 90122008                 bset    8, %o0
F0040924: d034e060                 sth     %o0, [%l3+0x60]
F0040928: d0066008                 ld      [%i1+8], %o0
F004092C: d024e098                 st      %o0, [%l3+0x98]
F0040930: d007bfcc                 ld      [%fp+var_34], %o0
F0040934: 40009e1b                 call    _kfree
F0040938: 92100011                 mov     %l1, %o1
F004093C: 81c7e008                 ret
F0040940: 81e80000                 restore
