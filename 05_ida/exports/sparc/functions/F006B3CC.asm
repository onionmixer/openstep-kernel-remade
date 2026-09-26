F006B3CC: 9de3bf38                 save    %sp, -0xC8, %sp
F006B3D0: a2102000                 mov     0, %l1
F006B3D4: 90100018                 mov     %i0, %o0
F006B3D8: 92102001                 mov     1, %o1
F006B3DC: 94102001                 mov     1, %o2
F006B3E0: 96102000                 mov     0, %o3
F006B3E4: 7ffeed78                 call    _lookupname
F006B3E8: 9807bfbc                 add     %fp, var_44, %o4
F006B3EC: 80a22000                 cmp     %o0, 0
F006B3F0: 12800083                 bne     locret_F006B5FC
F006B3F4: b0102004                 mov     4, %i0
F006B3F8: 7ffe846d                 call    _check_exec_access
F006B3FC: d007bfbc                 ld      [%fp+var_44], %o0
F006B400: 80a22000                 cmp     %o0, 0
F006B404: 02800004                 be      loc_F006B414
F006B408: 90102000                 mov     0, %o0
F006B40C: 10800079                 ba      loc_F006B5F0
F006B410: a2102006                 mov     6, %l1
F006B414: 9407bfc0                 add     %fp, var_40, %o2
F006B418: 9610201c                 mov     0x1C, %o3
F006B41C: 98102000                 mov     0, %o4
F006B420: 9a102001                 mov     1, %o5
F006B424: d207bfbc                 ld      [%fp+var_44], %o1
F006B428: 84102001                 mov     1, %g2
F006B42C: c423a05c                 st      %g2, [%sp+0xC8+var_6C]
F006B430: 7ffef589                 call    _vn_rdwr
F006B434: c023a060                 clr     [%sp+0xC8+var_68]
F006B438: 80a22000                 cmp     %o0, 0
F006B43C: 3280006d                 bne,a   loc_F006B5F0
F006B440: a2102004                 mov     4, %l1
F006B444: d407bfc0                 ld      [%fp+var_40], %o2
F006B448: 113fbb7e901222ce         set     -0x1120532, %o0
F006B450: 80a28008                 cmp     %o2, %o0
F006B454: 12800004                 bne     loc_F006B464
F006B458: 1132bfae                 sethi   -0x35014800, %o0
F006B45C: 1080001d                 ba      loc_F006B4D0
F006B460: 90102000                 mov     0, %o0
F006B464: 901222be                 bset    0x2BE, %o0
F006B468: 80a28008                 cmp     %o2, %o0
F006B46C: 02800018                 be      loc_F006B4CC
F006B470: 133fc000                 sethi   -0x1000000, %o1
F006B474: d027bfa0                 st      %o0, [%fp+var_60]
F006B478: a02c0009                 bclr    %o1, %l0
F006B47C: d00fbfa3                 ldub    [%fp+var_60+3], %o0
F006B480: 13003fc0                 sethi   0xFF0000, %o1
F006B484: 912a2018                 sll     %o0, 24, %o0
F006B488: a0140008                 bset    %o0, %l0
F006B48C: d00fbfa2                 ldub    [%fp+var_60+2], %o0
F006B490: a02c0009                 bclr    %o1, %l0
F006B494: d20fbfa1                 ldub    [%fp+var_60+1], %o1
F006B498: 912a2010                 sll     %o0, 16, %o0
F006B49C: a0140008                 bset    %o0, %l0
F006B4A0: 113fffc0901220ff         set     -0xFF01, %o0
F006B4A8: a00c0008                 and     %l0, %o0, %l0
F006B4AC: 932a6008                 sll     %o1, 8, %o1
F006B4B0: a0140009                 bset    %o1, %l0
F006B4B4: d00fbfa0                 ldub    [%fp+var_60], %o0
F006B4B8: a00c3f00                 and     %l0, -0x100, %l0
F006B4BC: a0140008                 bset    %o0, %l0
F006B4C0: 80a28010                 cmp     %o2, %l0
F006B4C4: 3280004b                 bne,a   loc_F006B5F0
F006B4C8: a2102002                 mov     2, %l1
F006B4CC: 90102001                 mov     1, %o0
F006B4D0: 80a22000                 cmp     %o0, 0
F006B4D4: 02800030                 be      loc_F006B594
F006B4D8: d007bfbc                 ld      [%fp+var_44], %o0
F006B4DC: a007bfc0                 add     %fp, var_40, %l0
F006B4E0: 92100010                 mov     %l0, %o1
F006B4E4: 7ffffc58                 call    _fatfile_getarch
F006B4E8: 9407bfe0                 add     %fp, var_20, %o2
F006B4EC: a2920000                 orcc    %o0, %g0, %l1
F006B4F0: 12800040                 bne     loc_F006B5F0
F006B4F4: 90102000                 mov     0, %o0
F006B4F8: 94100010                 mov     %l0, %o2
F006B4FC: 9610201c                 mov     0x1C, %o3
F006B500: d207bfbc                 ld      [%fp+var_44], %o1
F006B504: 9a102001                 mov     1, %o5
F006B508: d807bfe8                 ld      [%fp+var_18], %o4
F006B50C: 84102001                 mov     1, %g2
F006B510: c423a05c                 st      %g2, [%sp+0xC8+var_6C]
F006B514: 7ffef550                 call    _vn_rdwr
F006B518: c023a060                 clr     [%sp+0xC8+var_68]
F006B51C: 80a22000                 cmp     %o0, 0
F006B520: 12800034                 bne     loc_F006B5F0
F006B524: a2102004                 mov     4, %l1
F006B528: d207bfc0                 ld      [%fp+var_40], %o1
F006B52C: 113fbb7e901222ce         set     -0x1120532, %o0
F006B534: 80a24008                 cmp     %o1, %o0
F006B538: 1280002e                 bne     loc_F006B5F0
F006B53C: a2102002                 mov     2, %l1
F006B540: d2264000                 st      %o1, [%i1]
F006B544: d007bfc4                 ld      [%fp+var_3C], %o0
F006B548: d0266004                 st      %o0, [%i1+4]
F006B54C: d007bfc8                 ld      [%fp+var_38], %o0
F006B550: d0266008                 st      %o0, [%i1+8]
F006B554: d007bfcc                 ld      [%fp+var_34], %o0
F006B558: d026600c                 st      %o0, [%i1+0xC]
F006B55C: d007bfd0                 ld      [%fp+var_30], %o0
F006B560: d0266010                 st      %o0, [%i1+0x10]
F006B564: d007bfd4                 ld      [%fp+var_2C], %o0
F006B568: d0266014                 st      %o0, [%i1+0x14]
F006B56C: d007bfd8                 ld      [%fp+var_28], %o0
F006B570: d0266018                 st      %o0, [%i1+0x18]
F006B574: d007bfe8                 ld      [%fp+var_18], %o0
F006B578: d0268000                 st      %o0, [%i2]
F006B57C: d007bfec                 ld      [%fp+var_14], %o0
F006B580: d026c000                 st      %o0, [%i3]
F006B584: d007bfbc                 ld      [%fp+var_44], %o0
F006B588: b0102000                 mov     0, %i0
F006B58C: 1080001c                 ba      locret_F006B5FC
F006B590: d0270000                 st      %o0, [%i4]
F006B594: d007bfc0                 ld      [%fp+var_40], %o0
F006B598: d0264000                 st      %o0, [%i1]
F006B59C: d007bfc4                 ld      [%fp+var_3C], %o0
F006B5A0: d0266004                 st      %o0, [%i1+4]
F006B5A4: d007bfc8                 ld      [%fp+var_38], %o0
F006B5A8: d0266008                 st      %o0, [%i1+8]
F006B5AC: d007bfcc                 ld      [%fp+var_34], %o0
F006B5B0: d026600c                 st      %o0, [%i1+0xC]
F006B5B4: d007bfd0                 ld      [%fp+var_30], %o0
F006B5B8: d0266010                 st      %o0, [%i1+0x10]
F006B5BC: d007bfd4                 ld      [%fp+var_2C], %o0
F006B5C0: d0266014                 st      %o0, [%i1+0x14]
F006B5C4: d007bfd8                 ld      [%fp+var_28], %o0
F006B5C8: d0266018                 st      %o0, [%i1+0x18]
F006B5CC: c0268000                 clr     [%i2]
F006B5D0: d007bfbc                 ld      [%fp+var_44], %o0
F006B5D4: d0020000                 ld      [%o0], %o0
F006B5D8: d0022014                 ld      [%o0+0x14], %o0
F006B5DC: d026c000                 st      %o0, [%i3]
F006B5E0: d007bfbc                 ld      [%fp+var_44], %o0
F006B5E4: b0100011                 mov     %l1, %i0
F006B5E8: 10800005                 ba      locret_F006B5FC
F006B5EC: d0270000                 st      %o0, [%i4]
F006B5F0: 7ffef55d                 call    _vn_rele
F006B5F4: d007bfbc                 ld      [%fp+var_44], %o0
F006B5F8: b0100011                 mov     %l1, %i0
F006B5FC: 81c7e008                 ret
F006B600: 81e80000                 restore
