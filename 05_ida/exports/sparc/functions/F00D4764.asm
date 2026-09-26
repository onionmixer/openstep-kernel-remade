F00D4764: 9de3bf78                 save    %sp, -0x88, %sp
F00D4768: 7fffc65d                 call    _IOGetTimestamp
F00D476C: 9007bfe8                 add     %fp, var_18, %o0
F00D4770: d0062110                 ld      [%i0+0x110], %o0! id
F00D4774: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00D4778: 4000743e                 call    _objc_msgSend
F00D477C: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00D4780: d04e21d2                 ldsb    [%i0+0x1D2], %o0
F00D4784: 80a22000                 cmp     %o0, 0
F00D4788: 12800007                 bne     loc_F00D47A4
F00D478C: e00e21c0                 ldub    [%i0+0x1C0], %l0
F00D4790: d0062110                 ld      [%i0+0x110], %o0! id
F00D4794: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00D4798: 40007436                 call    _objc_msgSend
F00D479C: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00D47A0: 3080001b                 ba,a    locret_F00D480C
F00D47A4: d0062168                 ld      [%i0+0x168], %o0
F00D47A8: d0022008                 ld      [%o0+8], %o0
F00D47AC: 920ea004                 and     %i2, 4, %o1
F00D47B0: 900a2004                 and     %o0, 4, %o0
F00D47B4: 80a24008                 cmp     %o1, %o0
F00D47B8: 02800004                 be      loc_F00D47C8
F00D47BC: 80a00009                 cmp     %g0, %o1
F00D47C0: 90602000                 subc    %g0, 0, %o0
F00D47C4: a00a20ff                 and     %o0, 0xFF, %l0
F00D47C8: d0062110                 ld      [%i0+0x110], %o0! id
F00D47CC: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00D47D0: 40007428                 call    _objc_msgSend
F00D47D4: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00D47D8: 9010205a                 mov     0x5A, %o0 ! 'Z'
F00D47DC: d023a05c                 st      %o0, [%sp+0x88+var_2C]
F00D47E0: 90100018                 mov     %i0, %o0! id
F00D47E4: 133c0505                 sethi   %hi(paAbsolutepointe), %o1
F00D47E8: 992f2018                 sll     %i4, 24, %o4
F00D47EC: 993b2018                 sra     %o4, 24, %o4
F00D47F0: d41fbfe8                 ldd     [%fp+var_18], %o2
F00D47F4: 9a100010                 mov     %l0, %o5
F00D47F8: d2026280                 ld      [%o1+%lo(paAbsolutepointe)], %o1! SEL
F00D47FC: d43ba060                 std     %o2, [%sp+0x88+var_28]
F00D4800: 9410001a                 mov     %i2, %o2
F00D4804: 4000741b                 call    _objc_msgSend
F00D4808: 9610001b                 mov     %i3, %o3
F00D480C: 81c7e008                 ret
F00D4810: 81e80000                 restore
