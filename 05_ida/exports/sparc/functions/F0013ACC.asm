F0013ACC: 9de3bf98                 save    %sp, -0x68, %sp
F0013AD0: 273c04cf                 sethi   %hi(dword_F0133DDC), %l3
F0013AD4: d004e1dc                 ld      [%l3+%lo(dword_F0133DDC)], %o0
F0013AD8: e0022024                 ld      [%o0+0x24], %l0
F0013ADC: d0040000                 ld      [%l0], %o0
F0013AE0: 80a22000                 cmp     %o0, 0
F0013AE4: 14800010                 bg      loc_F0013B24
F0013AE8: a214e1dc                 or      %l3, %lo(dword_F0133DDC), %l1
F0013AEC: d0047ffc                 ld      [%l1-4], %o0
F0013AF0: d2020000                 ld      [%o0], %o1
F0013AF4: d0026028                 ld      [%o1+0x28], %o0
F0013AF8: 90122010                 bset    0x10, %o0
F0013AFC: d0226028                 st      %o0, [%o1+0x28]
F0013B00: d0047ffc                 ld      [%l1-4], %o0
F0013B04: d2020000                 ld      [%o0], %o1
F0013B08: d0026044                 ld      [%o1+0x44], %o0
F0013B0C: d022607c                 st      %o0, [%o1+0x7C]
F0013B10: d0047ffc                 ld      [%l1-4], %o0
F0013B14: d2020000                 ld      [%o0], %o1
F0013B18: d0026044                 ld      [%o1+0x44], %o0
F0013B1C: 10800082                 ba      locret_F0013D24
F0013B20: d2222080                 st      %o1, [%o0+0x80]
F0013B24: 7fffea67                 call    _pfind
F0013B28: d0042004                 ld      [%l0+4], %o0
F0013B2C: 94920000                 orcc    %o0, %g0, %o2
F0013B30: 32800006                 bne,a   loc_F0013B48
F0013B34: d2040000                 ld      [%l0], %o1
F0013B38: 113c04cf                 sethi   -0xFECC400, %o0
F0013B3C: d20221dc                 ld      [%o0+0x1DC], %o1
F0013B40: 10800078                 ba      loc_F0013D20
F0013B44: 90102003                 mov     3, %o0
F0013B48: 80a2600a                 cmp     %o1, 0xA
F0013B4C: 1280001e                 bne     loc_F0013BC4
F0013B50: e402a068                 ld      [%o2+0x68], %l2
F0013B54: d0047ffc                 ld      [%l1-4], %o0
F0013B58: d6020000                 ld      [%o0], %o3
F0013B5C: d252e02c                 ldsh    [%o3+0x2C], %o1
F0013B60: 80a26000                 cmp     %o1, 0
F0013B64: 22800007                 be,a    loc_F0013B80
F0013B68: d202a028                 ld      [%o2+0x28], %o1
F0013B6C: d052a02c                 ldsh    [%o2+0x2C], %o0
F0013B70: 80a20009                 cmp     %o0, %o1
F0013B74: 12bffff2                 bne     loc_F0013B3C
F0013B78: 113c04cf                 sethi   -0xFECC400, %o0
F0013B7C: d202a028                 ld      [%o2+0x28], %o1
F0013B80: 808a6010                 btst    0x10, %o1
F0013B84: 12bfffee                 bne     loc_F0013B3C
F0013B88: 113c04cf                 sethi   -0xFECC400, %o0
F0013B8C: d002e080                 ld      [%o3+0x80], %o0
F0013B90: 80a22000                 cmp     %o0, 0
F0013B94: 12bfffea                 bne     loc_F0013B3C
F0013B98: 113c04cf                 sethi   -0xFECC400, %o0
F0013B9C: 90126010                 or      %o1, 0x10, %o0
F0013BA0: d022a028                 st      %o0, [%o2+0x28]
F0013BA4: d2047ffc                 ld      [%l1-4], %o1
F0013BA8: 9010000a                 mov     %o2, %o0! unsigned int
F0013BAC: d4024000                 ld      [%o1], %o2
F0013BB0: 92102011                 mov     0x11, %o1! char *
F0013BB4: d422207c                 st      %o2, [%o0+0x7C]
F0013BB8: 7ffff66f                 call    _psignal
F0013BBC: d022e080                 st      %o0, [%o3+0x80]
F0013BC0: 30800059                 ba,a    locret_F0013D24
F0013BC4: d004a044                 ld      [%l2+0x44], %o0
F0013BC8: 80a22000                 cmp     %o0, 0
F0013BCC: 02bfffdc                 be      loc_F0013B3C
F0013BD0: 113c04cf                 sethi   -0xFECC400, %o0
F0013BD4: d04aa013                 ldsb    [%o2+0x13], %o0
F0013BD8: 80a22006                 cmp     %o0, 6
F0013BDC: 12bfffd8                 bne     loc_F0013B3C
F0013BE0: 113c04cf                 sethi   -0xFECC400, %o0
F0013BE4: d0047ffc                 ld      [%l1-4], %o0
F0013BE8: d602a07c                 ld      [%o2+0x7C], %o3
F0013BEC: d0020000                 ld      [%o0], %o0
F0013BF0: 80a2c008                 cmp     %o3, %o0
F0013BF4: 12bfffd2                 bne     loc_F0013B3C
F0013BF8: 113c04cf                 sethi   -0xFECC400, %o0
F0013BFC: d002a028                 ld      [%o2+0x28], %o0
F0013C00: 808a2010                 btst    0x10, %o0
F0013C04: 02bfffcd                 be      loc_F0013B38
F0013C08: 80a26008                 cmp     %o1, 8
F0013C0C: 22800019                 be,a    loc_F0013C70
F0013C10: d00aa017                 ldub    [%o2+0x17], %o0
F0013C14: 14800007                 bg      loc_F0013C30
F0013C18: 80a26009                 cmp     %o1, 9
F0013C1C: 80a26007                 cmp     %o1, 7
F0013C20: 22800018                 be,a    loc_F0013C80
F0013C24: d804a01c                 ld      [%l2+0x1C], %o4
F0013C28: 1080003c                 ba      loc_F0013D18
F0013C2C: 113c04cf                 sethi   -0xFECC400, %o0
F0013C30: 02800013                 be      loc_F0013C7C
F0013C34: 80a2600b                 cmp     %o1, 0xB
F0013C38: 12800038                 bne     loc_F0013D18
F0013C3C: 113c04cf                 sethi   -0xFECC400, %o0
F0013C40: d202e080                 ld      [%o3+0x80], %o1
F0013C44: 80a26000                 cmp     %o1, 0
F0013C48: 32800005                 bne,a   loc_F0013C5C
F0013C4C: d0026028                 ld      [%o1+0x28], %o0
F0013C50: d204e1dc                 ld      [%l3+0x1DC], %o1
F0013C54: 10800033                 ba      loc_F0013D20
F0013C58: 90102016                 mov     0x16, %o0
F0013C5C: c022607c                 clr     [%o1+0x7C]
F0013C60: 900a3fef                 and     %o0, -0x11, %o0
F0013C64: d0226028                 st      %o0, [%o1+0x28]
F0013C68: 1080001c                 ba      loc_F0013CD8
F0013C6C: c022e080                 clr     [%o3+0x80]
F0013C70: 90022020                 inc     0x20, %o0 ! ' '
F0013C74: 10800019                 ba      loc_F0013CD8
F0013C78: d02aa017                 stb     %o0, [%o2+0x17]
F0013C7C: d804a01c                 ld      [%l2+0x1C], %o4
F0013C80: d004200c                 ld      [%l0+0xC], %o0
F0013C84: 80a22020                 cmp     %o0, 0x20 ! ' '
F0013C88: 18800023                 bgu     loc_F0013D14
F0013C8C: d6032084                 ld      [%o4+0x84], %o3
F0013C90: d04aa017                 ldsb    [%o2+0x17], %o0
F0013C94: 13000007921262f8         set     0x1EF8, %o1
F0013C9C: 90023fff                 inc     -1, %o0
F0013CA0: 913a4008                 sra     %o1, %o0, %o0
F0013CA4: 808a2001                 btst    1, %o0
F0013CA8: 32800002                 bne,a   loc_F0013CB0
F0013CAC: c02ae048                 clrb    [%o3+0x48]
F0013CB0: d004200c                 ld      [%l0+0xC], %o0
F0013CB4: d02aa017                 stb     %o0, [%o2+0x17]
F0013CB8: d604200c                 ld      [%l0+0xC], %o3
F0013CBC: 9002ffff                 add     %o3, -1, %o0
F0013CC0: 913a4008                 sra     %o1, %o0, %o0
F0013CC4: 808a2001                 btst    1, %o0
F0013CC8: 02800005                 be      loc_F0013CDC
F0013CCC: 90102003                 mov     3, %o0
F0013CD0: d0032084                 ld      [%o4+0x84], %o0
F0013CD4: d62a2048                 stb     %o3, [%o0+0x48]
F0013CD8: 90102003                 mov     3, %o0
F0013CDC: d202a06c                 ld      [%o2+0x6C], %o1
F0013CE0: 80a26000                 cmp     %o1, 0
F0013CE4: 02800009                 be      loc_F0013D08
F0013CE8: d02aa013                 stb     %o0, [%o2+0x13]
F0013CEC: d04aa017                 ldsb    [%o2+0x17], %o0
F0013CF0: 80a22000                 cmp     %o0, 0
F0013CF4: 02800005                 be      loc_F0013D08
F0013CF8: 90100009                 mov     %o1, %o0! target_task
F0013CFC: 92102002                 mov     2, %o1
F0013D00: 4001744c                 call    _clear_wait
F0013D04: 94102001                 mov     1, %o2
F0013D08: 40017f84                 call    _task_resume
F0013D0C: 90100012                 mov     %l2, %o0
F0013D10: 30800005                 ba,a    locret_F0013D24
F0013D14: 113c04cf                 sethi   -0xFECC400, %o0
F0013D18: d20221dc                 ld      [%o0+0x1DC], %o1
F0013D1C: 90102005                 mov     5, %o0
F0013D20: d02a6038                 stb     %o0, [%o1+0x38]
F0013D24: 81c7e008                 ret
F0013D28: 81e80000                 restore
