F0085A88: 9de3bf90                 save    %sp, -0x70, %sp
F0085A8C: a4100018                 mov     %i0, %l2
F0085A90: 7fff8ccd                 call    _lock_write
F0085A94: 90100012                 mov     %l2, %o0
F0085A98: d004a04c                 ld      [%l2+0x4C], %o0
F0085A9C: 90022001                 inc     %o0
F0085AA0: d024a04c                 st      %o0, [%l2+0x4C]
F0085AA4: 40005b47                 call    _pmap_create
F0085AA8: 90102000                 mov     0, %o0
F0085AAC: d204a014                 ld      [%l2+0x14], %o1
F0085AB0: d404a018                 ld      [%l2+0x18], %o2
F0085AB4: 7ffff97f                 call    _vm_map_create
F0085AB8: d604a020                 ld      [%l2+0x20], %o3
F0085ABC: 9204a00c                 add     %l2, 0xC, %o1
F0085AC0: e204a010                 ld      [%l2+0x10], %l1
F0085AC4: 80a44009                 cmp     %l1, %o1
F0085AC8: 028000bd                 be      loc_F0085DBC
F0085ACC: b0100008                 mov     %o0, %i0
F0085AD0: 27200000                 sethi   0x80000000, %l3
F0085AD4: 111fffffa81223ff         set     0x7FFFFFFF, %l4
F0085ADC: d2046018                 ld      [%l1+0x18], %o1
F0085AE0: 11080000                 sethi   0x20000000, %o0
F0085AE4: 808a4008                 btst    %o0, %o1
F0085AE8: 02800004                 be      loc_F0085AF8
F0085AEC: 113c0446                 sethi   %hi(aVmMapForkEncou), %o0! "vm_map_fork: encountered a submap"
F0085AF0: 7ffe3da0                 call    _panic
F0085AF4: 90122288                 bset    %lo(aVmMapForkEncou), %o0! "vm_map_fork: encountered a submap"
F0085AF8: d0046024                 ld      [%l1+0x24], %o0
F0085AFC: 80a22001                 cmp     %o0, 1
F0085B00: 02800069                 be      loc_F0085CA4
F0085B04: 01000000                 nop
F0085B08: 348000a9                 bg,a    loc_F0085DAC
F0085B0C: e2046004                 ld      [%l1+4], %l1
F0085B10: 80a22000                 cmp     %o0, 0
F0085B14: 328000a6                 bne,a   loc_F0085DAC
F0085B18: e2046004                 ld      [%l1+4], %l1
F0085B1C: d0046018                 ld      [%l1+0x18], %o0
F0085B20: 808a0013                 btst    %l3, %o0
F0085B24: 12800031                 bne     loc_F0085BE8
F0085B28: 90102000                 mov     0, %o0
F0085B2C: d2046008                 ld      [%l1+8], %o1
F0085B30: d404600c                 ld      [%l1+0xC], %o2
F0085B34: 7ffff95f                 call    _vm_map_create
F0085B38: 96102001                 mov     1, %o3
F0085B3C: a0100008                 mov     %o0, %l0
F0085B40: c024202c                 clr     [%l0+0x2C]
F0085B44: 7ffff97f                 call    __vm_map_entry_create
F0085B48: 9004200c                 add     %l0, 0xC, %o0
F0085B4C: d2044000                 ld      [%l1], %o1
F0085B50: d2220000                 st      %o1, [%o0]
F0085B54: d2046004                 ld      [%l1+4], %o1
F0085B58: d2222004                 st      %o1, [%o0+4]
F0085B5C: d2046008                 ld      [%l1+8], %o1
F0085B60: d2222008                 st      %o1, [%o0+8]
F0085B64: d204600c                 ld      [%l1+0xC], %o1
F0085B68: d222200c                 st      %o1, [%o0+0xC]
F0085B6C: d2046010                 ld      [%l1+0x10], %o1
F0085B70: d2222010                 st      %o1, [%o0+0x10]
F0085B74: d2046014                 ld      [%l1+0x14], %o1
F0085B78: d2222014                 st      %o1, [%o0+0x14]
F0085B7C: d2046018                 ld      [%l1+0x18], %o1
F0085B80: d2222018                 st      %o1, [%o0+0x18]
F0085B84: d204601c                 ld      [%l1+0x1C], %o1
F0085B88: d222201c                 st      %o1, [%o0+0x1C]
F0085B8C: d2046020                 ld      [%l1+0x20], %o1
F0085B90: d2222020                 st      %o1, [%o0+0x20]
F0085B94: d2046024                 ld      [%l1+0x24], %o1
F0085B98: d2222024                 st      %o1, [%o0+0x24]
F0085B9C: d2046028                 ld      [%l1+0x28], %o1
F0085BA0: d2222028                 st      %o1, [%o0+0x28]
F0085BA4: d204201c                 ld      [%l0+0x1C], %o1
F0085BA8: 92026001                 inc     %o1
F0085BAC: d404200c                 ld      [%l0+0xC], %o2
F0085BB0: d224201c                 st      %o1, [%l0+0x1C]
F0085BB4: d4220000                 st      %o2, [%o0]
F0085BB8: d204200c                 ld      [%l0+0xC], %o1
F0085BBC: d2026004                 ld      [%o1+4], %o1
F0085BC0: d4020000                 ld      [%o0], %o2
F0085BC4: d2222004                 st      %o1, [%o0+4]
F0085BC8: d0224000                 st      %o0, [%o1]
F0085BCC: d022a004                 st      %o0, [%o2+4]
F0085BD0: d0046018                 ld      [%l1+0x18], %o0
F0085BD4: 90120013                 bset    %l3, %o0
F0085BD8: d0246018                 st      %o0, [%l1+0x18]
F0085BDC: d0046008                 ld      [%l1+8], %o0
F0085BE0: e0246010                 st      %l0, [%l1+0x10]
F0085BE4: d0246014                 st      %o0, [%l1+0x14]
F0085BE8: 7ffff956                 call    __vm_map_entry_create
F0085BEC: 9006200c                 add     %i0, 0xC, %o0
F0085BF0: d2044000                 ld      [%l1], %o1
F0085BF4: a0100008                 mov     %o0, %l0
F0085BF8: d2240000                 st      %o1, [%l0]
F0085BFC: d0046004                 ld      [%l1+4], %o0
F0085C00: d0242004                 st      %o0, [%l0+4]
F0085C04: d0046008                 ld      [%l1+8], %o0
F0085C08: d0242008                 st      %o0, [%l0+8]
F0085C0C: d004600c                 ld      [%l1+0xC], %o0
F0085C10: d024200c                 st      %o0, [%l0+0xC]
F0085C14: d0046010                 ld      [%l1+0x10], %o0
F0085C18: d0242010                 st      %o0, [%l0+0x10]
F0085C1C: d0046014                 ld      [%l1+0x14], %o0
F0085C20: d0242014                 st      %o0, [%l0+0x14]
F0085C24: d0046018                 ld      [%l1+0x18], %o0
F0085C28: d0242018                 st      %o0, [%l0+0x18]
F0085C2C: d004601c                 ld      [%l1+0x1C], %o0
F0085C30: d024201c                 st      %o0, [%l0+0x1C]
F0085C34: d0046020                 ld      [%l1+0x20], %o0
F0085C38: d0242020                 st      %o0, [%l0+0x20]
F0085C3C: d0046024                 ld      [%l1+0x24], %o0
F0085C40: d0242024                 st      %o0, [%l0+0x24]
F0085C44: d2046028                 ld      [%l1+0x28], %o1
F0085C48: d0042010                 ld      [%l0+0x10], %o0
F0085C4C: 7ffff95d                 call    _vm_map_reference
F0085C50: d2242028                 st      %o1, [%l0+0x28]
F0085C54: d006201c                 ld      [%i0+0x1C], %o0
F0085C58: 90022001                 inc     %o0
F0085C5C: d206200c                 ld      [%i0+0xC], %o1
F0085C60: d026201c                 st      %o0, [%i0+0x1C]
F0085C64: d2240000                 st      %o1, [%l0]
F0085C68: d006200c                 ld      [%i0+0xC], %o0
F0085C6C: d0022004                 ld      [%o0+4], %o0
F0085C70: d2040000                 ld      [%l0], %o1
F0085C74: d0242004                 st      %o0, [%l0+4]
F0085C78: e0220000                 st      %l0, [%o0]
F0085C7C: e0226004                 st      %l0, [%o1+4]
F0085C80: d604600c                 ld      [%l1+0xC], %o3
F0085C84: d0062024                 ld      [%i0+0x24], %o0
F0085C88: d204a024                 ld      [%l2+0x24], %o1
F0085C8C: d8046008                 ld      [%l1+8], %o4
F0085C90: d4042008                 ld      [%l0+8], %o2
F0085C94: 400067ba                 call    _pmap_copy
F0085C98: 9622c00c                 sub     %o3, %o4, %o3
F0085C9C: 10800044                 ba      loc_F0085DAC
F0085CA0: e2046004                 ld      [%l1+4], %l1
F0085CA4: 7ffff927                 call    __vm_map_entry_create
F0085CA8: 9006200c                 add     %i0, 0xC, %o0
F0085CAC: d2044000                 ld      [%l1], %o1
F0085CB0: a0100008                 mov     %o0, %l0
F0085CB4: d2240000                 st      %o1, [%l0]
F0085CB8: d0046004                 ld      [%l1+4], %o0
F0085CBC: d0242004                 st      %o0, [%l0+4]
F0085CC0: d0046008                 ld      [%l1+8], %o0
F0085CC4: d0242008                 st      %o0, [%l0+8]
F0085CC8: d004600c                 ld      [%l1+0xC], %o0
F0085CCC: d024200c                 st      %o0, [%l0+0xC]
F0085CD0: d0046010                 ld      [%l1+0x10], %o0
F0085CD4: d0242010                 st      %o0, [%l0+0x10]
F0085CD8: d0046014                 ld      [%l1+0x14], %o0
F0085CDC: d0242014                 st      %o0, [%l0+0x14]
F0085CE0: d0046018                 ld      [%l1+0x18], %o0
F0085CE4: d0242018                 st      %o0, [%l0+0x18]
F0085CE8: d004601c                 ld      [%l1+0x1C], %o0
F0085CEC: d024201c                 st      %o0, [%l0+0x1C]
F0085CF0: d0046020                 ld      [%l1+0x20], %o0
F0085CF4: d0242020                 st      %o0, [%l0+0x20]
F0085CF8: d0046024                 ld      [%l1+0x24], %o0
F0085CFC: d0242024                 st      %o0, [%l0+0x24]
F0085D00: d0046028                 ld      [%l1+0x28], %o0
F0085D04: d0242028                 st      %o0, [%l0+0x28]
F0085D08: c0342028                 clrh    [%l0+0x28]
F0085D0C: d0042018                 ld      [%l0+0x18], %o0
F0085D10: c0242010                 clr     [%l0+0x10]
F0085D14: 900a0014                 and     %o0, %l4, %o0
F0085D18: d0242018                 st      %o0, [%l0+0x18]
F0085D1C: d006201c                 ld      [%i0+0x1C], %o0
F0085D20: 90022001                 inc     %o0
F0085D24: d206200c                 ld      [%i0+0xC], %o1
F0085D28: d026201c                 st      %o0, [%i0+0x1C]
F0085D2C: d2240000                 st      %o1, [%l0]
F0085D30: d006200c                 ld      [%i0+0xC], %o0
F0085D34: d0022004                 ld      [%o0+4], %o0
F0085D38: d2040000                 ld      [%l0], %o1
F0085D3C: d0242004                 st      %o0, [%l0+4]
F0085D40: e0220000                 st      %l0, [%o0]
F0085D44: e0226004                 st      %l0, [%o1+4]
F0085D48: d0046018                 ld      [%l1+0x18], %o0
F0085D4C: 808a0013                 btst    %l3, %o0
F0085D50: 02800011                 be      loc_F0085D94
F0085D54: 90100018                 mov     %i0, %o0
F0085D58: d2046010                 ld      [%l1+0x10], %o1
F0085D5C: d4042008                 ld      [%l0+8], %o2
F0085D60: d604200c                 ld      [%l0+0xC], %o3
F0085D64: d8046014                 ld      [%l1+0x14], %o4
F0085D68: 9a102000                 mov     0, %o5
F0085D6C: c023a05c                 clr     [%sp+0x70+var_14]
F0085D70: 7ffffe30                 call    _vm_map_copy
F0085D74: 9622c00a                 sub     %o3, %o2, %o3
F0085D78: 80a22000                 cmp     %o0, 0
F0085D7C: 0280000b                 be      loc_F0085DA8
F0085D80: 113c0446                 sethi   %hi(aVmMapForkCopyI), %o0! "vm_map_fork: copy in share_map region f"...
F0085D84: 7ffe3a35                 call    _printf
F0085D88: 901222b0                 bset    %lo(aVmMapForkCopyI), %o0! "vm_map_fork: copy in share_map region f"...
F0085D8C: 10800008                 ba      loc_F0085DAC
F0085D90: e2046004                 ld      [%l1+4], %l1
F0085D94: 90100012                 mov     %l2, %o0
F0085D98: 92100018                 mov     %i0, %o1
F0085D9C: 94100011                 mov     %l1, %o2
F0085DA0: 7ffffda3                 call    _vm_map_copy_entry
F0085DA4: 96100010                 mov     %l0, %o3
F0085DA8: e2046004                 ld      [%l1+4], %l1
F0085DAC: 9004a00c                 add     %l2, 0xC, %o0
F0085DB0: 80a44008                 cmp     %l1, %o0
F0085DB4: 32bfff4b                 bne,a   loc_F0085AE0
F0085DB8: d2046018                 ld      [%l1+0x18], %o1
F0085DBC: d204a028                 ld      [%l2+0x28], %o1
F0085DC0: 90100012                 mov     %l2, %o0
F0085DC4: 7fff8c9c                 call    _lock_done
F0085DC8: d2262028                 st      %o1, [%i0+0x28]
F0085DCC: 81c7e008                 ret
F0085DD0: 81e80000                 restore
