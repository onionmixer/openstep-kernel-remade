F00D3778: 9de3bf50                 save    %sp, -0xB0, %sp
F00D377C: 912f2018                 sll     %i4, 24, %o0
F00D3780: a13a2018                 sra     %o0, 24, %l0
F00D3784: 113c04bb                 sethi   %hi(dword_F012EEAC), %o0
F00D3788: d20222ac                 ld      [%o0+%lo(dword_F012EEAC)], %o1
F00D378C: 901222ac                 bset    %lo(dword_F012EEAC), %o0
F00D3790: d4022004                 ld      [%o0+4], %o2
F00D3794: d227bfb8                 st      %o1, [%fp+var_48]
F00D3798: d2022008                 ld      [%o0+8], %o1
F00D379C: d427bfbc                 st      %o2, [%fp+var_44]
F00D37A0: d402200c                 ld      [%o0+0xC], %o2
F00D37A4: d227bfc0                 st      %o1, [%fp+var_40]
F00D37A8: d2022010                 ld      [%o0+0x10], %o1
F00D37AC: d427bfc4                 st      %o2, [%fp+var_3C]
F00D37B0: d4022014                 ld      [%o0+0x14], %o2
F00D37B4: d227bfc8                 st      %o1, [%fp+var_38]
F00D37B8: d2022018                 ld      [%o0+0x18], %o1
F00D37BC: d427bfcc                 st      %o2, [%fp+var_34]
F00D37C0: d402201c                 ld      [%o0+0x1C], %o2
F00D37C4: d227bfd0                 st      %o1, [%fp+var_30]
F00D37C8: d2022020                 ld      [%o0+0x20], %o1
F00D37CC: d427bfd4                 st      %o2, [%fp+var_2C]
F00D37D0: d4022024                 ld      [%o0+0x24], %o2
F00D37D4: d227bfd8                 st      %o1, [%fp+var_28]
F00D37D8: d2022028                 ld      [%o0+0x28], %o1
F00D37DC: d427bfdc                 st      %o2, [%fp+var_24]
F00D37E0: d402202c                 ld      [%o0+0x2C], %o2
F00D37E4: 80a42000                 cmp     %l0, 0
F00D37E8: d227bfe0                 st      %o1, [%fp+var_20]
F00D37EC: d0022030                 ld      [%o0+0x30], %o0
F00D37F0: d427bfe4                 st      %o2, [%fp+var_1C]
F00D37F4: d027bfe8                 st      %o0, [%fp+var_18]
F00D37F8: c027bfc4                 clr     [%fp+var_3C]
F00D37FC: 12800010                 bne     loc_F00D383C
F00D3800: f427bfd4                 st      %i2, [%fp+var_2C]
F00D3804: 113c0506                 sethi   %hi(paNxconditionloc), %o0
F00D3808: d002226c                 ld      [%o0+%lo(paNxconditionloc)], %o0! id
F00D380C: 133c0503                 sethi   %hi(paAlloc), %o1! SEL
F00D3810: 40007818                 call    _objc_msgSend
F00D3814: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1
F00D3818: d027bfd8                 st      %o0, [%fp+var_28]
F00D381C: 133c0503                 sethi   %hi(paInitwith), %o1
F00D3820: d20263f4                 ld      [%o1+%lo(paInitwith)], %o1! SEL
F00D3824: 40007813                 call    _objc_msgSend
F00D3828: 94102001                 mov     1, %o2
F00D382C: 9007bfb4                 add     %fp, var_4C, %o0
F00D3830: d027bfdc                 st      %o0, [%fp+var_24]
F00D3834: 90103d3e                 mov     -0x2C2, %o0
F00D3838: d027bfb4                 st      %o0, [%fp+var_4C]
F00D383C: 9007bfb8                 add     %fp, var_48, %o0
F00D3840: d406c000                 ld      [%i3], %o2
F00D3844: 92102000                 mov     0, %o1
F00D3848: d427bfe0                 st      %o2, [%fp+var_20]
F00D384C: d606e004                 ld      [%i3+4], %o3
F00D3850: 94102000                 mov     0, %o2
F00D3854: d627bfe4                 st      %o3, [%fp+var_1C]
F00D3858: d806e008                 ld      [%i3+8], %o4
F00D385C: 173c043e                 sethi   %hi(_ev_port_list), %o3
F00D3860: d602e290                 ld      [%o3+%lo(_ev_port_list)], %o3
F00D3864: d827bfe8                 st      %o4, [%fp+var_18]
F00D3868: 7ffe48f1                 call    _msg_send_from_kernel
F00D386C: d627bfc8                 st      %o3, [%fp+var_38]
F00D3870: b4920000                 orcc    %o0, %g0, %i2
F00D3874: 0280000e                 be      loc_F00D38AC
F00D3878: 90100018                 mov     %i0, %o0! id
F00D387C: 133c0504                 sethi   %hi(paName), %o1
F00D3880: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00D3884: 213c03ef                 sethi   %hi(aSThreadopcommo), %l0! "%s: _threadOpCommon msg_send returned %"...
F00D3888: 400077fa                 call    _objc_msgSend
F00D388C: a01422b8                 bset    %lo(aSThreadopcommo), %l0! "%s: _threadOpCommon msg_send returned %"...
F00D3890: 92100008                 mov     %o0, %o1
F00D3894: 90100010                 mov     %l0, %o0
F00D3898: 7fffca17                 call    _IOLog
F00D389C: 9410001a                 mov     %i2, %o2
F00D38A0: 90103d41                 mov     -0x2BF, %o0
F00D38A4: 1080000c                 ba      loc_F00D38D4
F00D38A8: d027bfb4                 st      %o0, [%fp+var_4C]
F00D38AC: 80a42000                 cmp     %l0, 0
F00D38B0: 32800009                 bne,a   loc_F00D38D4
F00D38B4: c027bfb4                 clr     [%fp+var_4C]
F00D38B8: d007bfd8                 ld      [%fp+var_28], %o0! id
F00D38BC: 133c0503                 sethi   %hi(paLockwhen), %o1
F00D38C0: d20263f8                 ld      [%o1+%lo(paLockwhen)], %o1! SEL
F00D38C4: 400077eb                 call    _objc_msgSend
F00D38C8: 94102002                 mov     2, %o2
F00D38CC: 10800003                 ba      loc_F00D38D8
F00D38D0: 912f2018                 sll     %i4, 24, %o0
F00D38D4: 912f2018                 sll     %i4, 24, %o0
F00D38D8: 80a22000                 cmp     %o0, 0
F00D38DC: 12800007                 bne     locret_F00D38F8
F00D38E0: f007bfb4                 ld      [%fp+var_4C], %i0
F00D38E4: d007bfd8                 ld      [%fp+var_28], %o0! id
F00D38E8: 133c0503                 sethi   %hi(paFree), %o1! SEL
F00D38EC: 400077e1                 call    _objc_msgSend
F00D38F0: d20263fc                 ld      [%o1+%lo(paFree)], %o1
F00D38F4: f007bfb4                 ld      [%fp+var_4C], %i0
F00D38F8: 81c7e008                 ret
F00D38FC: 81e80000                 restore
