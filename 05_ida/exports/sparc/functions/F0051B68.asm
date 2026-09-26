F0051B68: 9de3bf98                 save    %sp, -0x68, %sp
F0051B6C: e0062030                 ld      [%i0+0x30], %l0
F0051B70: d0142044                 lduh    [%l0+0x44], %o0
F0051B74: 808a2046                 btst    0x46, %o0 ! 'F'
F0051B78: 0280001c                 be      loc_F0051BE8
F0051B7C: 90122008                 bset    8, %o0
F0051B80: d0342044                 sth     %o0, [%l0+0x44]
F0051B84: 233c04d4                 sethi   %hi(_iuniqtime), %l1
F0051B88: 40007292                 call    _microtime
F0051B8C: 90146148                 or      %l1, %lo(_iuniqtime), %o0
F0051B90: d0142044                 lduh    [%l0+0x44], %o0
F0051B94: 808a2004                 btst    4, %o0
F0051B98: 02800003                 be      loc_F0051BA4
F0051B9C: d0046148                 ld      [%l1+%lo(_iuniqtime)], %o0
F0051BA0: d0242074                 st      %o0, [%l0+0x74]
F0051BA4: d0142044                 lduh    [%l0+0x44], %o0
F0051BA8: 808a2002                 btst    2, %o0
F0051BAC: 02800003                 be      loc_F0051BB8
F0051BB0: d0046148                 ld      [%l1+0x148], %o0
F0051BB4: d024207c                 st      %o0, [%l0+0x7C]
F0051BB8: d0142044                 lduh    [%l0+0x44], %o0
F0051BBC: 808a2040                 btst    0x40, %o0 ! '@'
F0051BC0: 22800006                 be,a    loc_F0051BD8
F0051BC4: d2142044                 lduh    [%l0+0x44], %o1
F0051BC8: c024204c                 clr     [%l0+0x4C]
F0051BCC: d0046148                 ld      [%l1+0x148], %o0
F0051BD0: d0242084                 st      %o0, [%l0+0x84]
F0051BD4: d2142044                 lduh    [%l0+0x44], %o1
F0051BD8: 1100003f901223b9         set     0xFFB9, %o0
F0051BE0: 920a4008                 and     %o1, %o0, %o1
F0051BE4: d2342044                 sth     %o1, [%l0+0x44]
F0051BE8: d0142064                 lduh    [%l0+0x64], %o0
F0051BEC: 1300003c                 sethi   0xF000, %o1
F0051BF0: 900a0009                 and     %o0, %o1, %o0
F0051BF4: 9132200d                 srl     %o0, 13, %o0
F0051BF8: 133c043a921263bc         set     _iftovt_tab, %o1
F0051C00: 912a2002                 sll     %o0, 2, %o0
F0051C04: d0020009                 ld      [%o0+%o1], %o0
F0051C08: d0264000                 st      %o0, [%i1]
F0051C0C: d0142064                 lduh    [%l0+0x64], %o0
F0051C10: d0366004                 sth     %o0, [%i1+4]
F0051C14: d0142068                 lduh    [%l0+0x68], %o0
F0051C18: d0366006                 sth     %o0, [%i1+6]
F0051C1C: d014206a                 lduh    [%l0+0x6A], %o0
F0051C20: d0366008                 sth     %o0, [%i1+8]
F0051C24: d0542046                 ldsh    [%l0+0x46], %o0
F0051C28: d026600c                 st      %o0, [%i1+0xC]
F0051C2C: d0042048                 ld      [%l0+0x48], %o0
F0051C30: d0266010                 st      %o0, [%i1+0x10]
F0051C34: d0142066                 lduh    [%l0+0x66], %o0
F0051C38: d0366014                 sth     %o0, [%i1+0x14]
F0051C3C: d0062028                 ld      [%i0+0x28], %o0
F0051C40: 80a22001                 cmp     %o0, 1
F0051C44: 32800004                 bne,a   loc_F0051C54
F0051C48: d0042070                 ld      [%l0+0x70], %o0
F0051C4C: d0060000                 ld      [%i0], %o0
F0051C50: d0022014                 ld      [%o0+0x14], %o0
F0051C54: d0266018                 st      %o0, [%i1+0x18]
F0051C58: d0042074                 ld      [%l0+0x74], %o0
F0051C5C: d0266020                 st      %o0, [%i1+0x20]
F0051C60: c0266024                 clr     [%i1+0x24]
F0051C64: d004207c                 ld      [%l0+0x7C], %o0
F0051C68: d0266028                 st      %o0, [%i1+0x28]
F0051C6C: c026602c                 clr     [%i1+0x2C]
F0051C70: d0042084                 ld      [%l0+0x84], %o0
F0051C74: d0266030                 st      %o0, [%i1+0x30]
F0051C78: c0266034                 clr     [%i1+0x34]
F0051C7C: d004208c                 ld      [%l0+0x8C], %o0
F0051C80: d0366038                 sth     %o0, [%i1+0x38]
F0051C84: d006201c                 ld      [%i0+0x1C], %o0
F0051C88: d2022080                 ld      [%o0+0x80], %o1
F0051C8C: 9fc24000                 call    %o1
F0051C90: 90100018                 mov     %i0, %o0
F0051C94: d40420cc                 ld      [%l0+0xCC], %o2
F0051C98: 92100008                 mov     %o0, %o1
F0051C9C: 7ffed219                 call    _umul
F0051CA0: 9010000a                 mov     %o2, %o0
F0051CA4: 91322009                 srl     %o0, 9, %o0
F0051CA8: d026603c                 st      %o0, [%i1+0x3C]
F0051CAC: d2142064                 lduh    [%l0+0x64], %o1
F0051CB0: 1100003c                 sethi   0xF000, %o0
F0051CB4: 920a4008                 and     %o1, %o0, %o1
F0051CB8: 11000008                 sethi   0x2000, %o0
F0051CBC: 80a24008                 cmp     %o1, %o0
F0051CC0: 0280000b                 be      loc_F0051CEC
F0051CC4: 11000018                 sethi   0x6000, %o0
F0051CC8: 80a24008                 cmp     %o1, %o0
F0051CCC: 3280000a                 bne,a   loc_F0051CF4
F0051CD0: d0062024                 ld      [%i0+0x24], %o0
F0051CD4: d006201c                 ld      [%i0+0x1C], %o0
F0051CD8: d2022080                 ld      [%o0+0x80], %o1
F0051CDC: 9fc24000                 call    %o1
F0051CE0: 90100018                 mov     %i0, %o0
F0051CE4: 10800006                 ba      locret_F0051CFC
F0051CE8: d026601c                 st      %o0, [%i1+0x1C]
F0051CEC: 10800004                 ba      locret_F0051CFC
F0051CF0: d226601c                 st      %o1, [%i1+0x1C]
F0051CF4: d0022010                 ld      [%o0+0x10], %o0
F0051CF8: d026601c                 st      %o0, [%i1+0x1C]
F0051CFC: 81c7e008                 ret
F0051D00: 91e82000                 restore %g0, 0, %o0
