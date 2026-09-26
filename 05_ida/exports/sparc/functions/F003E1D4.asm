F003E1D4: 9de3bf58                 save    %sp, -0xA8, %sp
F003E1D8: 90102005                 mov     5, %o0
F003E1DC: d027bfd8                 st      %o0, [%fp+var_28]
F003E1E0: c027bfdc                 clr     [%fp+var_24]
F003E1E4: 113c04d190122230         set     _hostname, %o0
F003E1EC: d027bff0                 st      %o0, [%fp+var_10]
F003E1F0: f027bff4                 st      %i0, [%fp+var_C]
F003E1F4: a007bfe0                 add     %fp, __src, %l0
F003E1F8: 90100010                 mov     %l0, %o0! void *
F003E1FC: 40015b17                 call    _bzero
F003E200: 92102010                 mov     0x10, %o1
F003E204: 7fffff08                 call    sub_F003DE24
F003E208: 01000000                 nop
F003E20C: 80a22000                 cmp     %o0, 0
F003E210: 02800004                 be      loc_F003E220
F003E214: 01000000                 nop
F003E218: 10800063                 ba      locret_F003E3A4
F003E21C: b0100008                 mov     %o0, %i0
F003E220: 4000a794                 call    _kalloc
F003E224: 90102100                 mov     0x100, %o0
F003E228: d027bfe0                 st      %o0, [%fp+__src]
F003E22C: 4000a791                 call    _kalloc
F003E230: 90102100                 mov     0x100, %o0
F003E234: d027bfec                 st      %o0, [%fp+var_14]
F003E238: a2102000                 mov     0, %l1
F003E23C: 2f3c04bd                 sethi   %hi(unk_F012F514), %l7
F003E240: 2d3c0119                 sethi   -0xFFB9C00, %l6
F003E244: 113c0119aa122154         set     _xdr_bp_getfile_res, %l5
F003E24C: a6100010                 mov     %l0, %l3
F003E250: a407bfd0                 add     %fp, var_30, %l2
F003E254: 29000061                 sethi   0x18400, %l4
F003E258: 9015e114                 or      %l7, %lo(unk_F012F514), %o0
F003E25C: 921522ba                 or      %l4, 0x2BA, %o1
F003E260: 94102001                 mov     1, %o2! size_t
F003E264: da07bfd8                 ld      [%fp+var_28], %o5
F003E268: 96102002                 mov     2, %o3
F003E26C: d807bfdc                 ld      [%fp+var_24], %o4
F003E270: da27bfd0                 st      %o5, [%fp+var_30]
F003E274: d827bfd4                 st      %o4, [%fp+var_2C]
F003E278: ea23a05c                 st      %l5, [%sp+0xA8+var_4C]
F003E27C: e623a060                 st      %l3, [%sp+0xA8+var_48]
F003E280: e423a064                 st      %l2, [%sp+0xA8+var_44]
F003E284: c023a068                 clr     [%sp+0xA8+var_40]
F003E288: 9815a118                 or      %l6, 0x118, %o4
F003E28C: 7ffffeac                 call    sub_F003DD3C
F003E290: 9a07bff0                 add     %fp, var_10, %o5
F003E294: a0100008                 mov     %o0, %l0
F003E298: 80a42005                 cmp     %l0, 5
F003E29C: 12800007                 bne     loc_F003E2B8
F003E2A0: 80a42000                 cmp     %l0, 0
F003E2A4: a2046001                 inc     %l1
F003E2A8: 80a46004                 cmp     %l1, 4
F003E2AC: 04bfffec                 ble     loc_F003E25C
F003E2B0: 9015e114                 or      %l7, 0x114, %o0
F003E2B4: 80a42000                 cmp     %l0, 0
F003E2B8: 12800009                 bne     loc_F003E2DC
F003E2BC: d007bfe0                 ld      [%fp+__src], %o0! __dst
F003E2C0: d207bfe0                 ld      [%fp+__src], %o1! __src
F003E2C4: 7fff2499                 call    _strcpy
F003E2C8: 90100019                 mov     %i1, %o0! __dst
F003E2CC: d207bfec                 ld      [%fp+var_14], %o1! __src
F003E2D0: 7fff2496                 call    _strcpy
F003E2D4: 9010001b                 mov     %i3, %o0
F003E2D8: d007bfe0                 ld      [%fp+__src], %o0
F003E2DC: 4000a7b1                 call    _kfree
F003E2E0: 92102100                 mov     0x100, %o1
F003E2E4: d007bfec                 ld      [%fp+var_14], %o0
F003E2E8: 4000a7ae                 call    _kfree
F003E2EC: 92102100                 mov     0x100, %o1
F003E2F0: 80a42000                 cmp     %l0, 0
F003E2F4: 02800006                 be      loc_F003E30C
F003E2F8: 80a42005                 cmp     %l0, 5
F003E2FC: 0280002a                 be      locret_F003E3A4
F003E300: b010203c                 mov     0x3C, %i0 ! '<'
F003E304: 10800028                 ba      locret_F003E3A4
F003E308: b0100010                 mov     %l0, %i0
F003E30C: 9007bfe8                 add     %fp, var_18, %o0! void *
F003E310: 9207bfcc                 add     %fp, var_34, %o1! void *
F003E314: 400159ff                 call    _bcopy
F003E318: 94102004                 mov     4, %o2
F003E31C: d04e4000                 ldsb    [%i1], %o0
F003E320: 80a22000                 cmp     %o0, 0
F003E324: 22800020                 be,a    locret_F003E3A4
F003E328: b0102016                 mov     0x16, %i0
F003E32C: d04ec000                 ldsb    [%i3], %o0
F003E330: 80a22000                 cmp     %o0, 0
F003E334: 02800005                 be      loc_F003E348
F003E338: d007bfcc                 ld      [%fp+var_34], %o0
F003E33C: 80a22000                 cmp     %o0, 0
F003E340: 12800004                 bne     loc_F003E350
F003E344: d207bfe4                 ld      [%fp+var_1C], %o1! size_t
F003E348: 10800017                 ba      locret_F003E3A4
F003E34C: b0102016                 mov     0x16, %i0
F003E350: 80a26001                 cmp     %o1, 1
F003E354: 02800006                 be      loc_F003E36C
F003E358: 113c0435                 sethi   %hi(aGetfileUnknown), %o0! "getfile: unknown address type %d\n"
F003E35C: 7fff58bf                 call    _printf
F003E360: 90122088                 bset    %lo(aGetfileUnknown), %o0! "getfile: unknown address type %d\n"
F003E364: 10800010                 ba      locret_F003E3A4
F003E368: b010202b                 mov     0x2B, %i0 ! '+'
F003E36C: 9010001a                 mov     %i2, %o0! void *
F003E370: 40015aba                 call    _bzero
F003E374: 92102010                 mov     0x10, %o1
F003E378: 90102002                 mov     2, %o0
F003E37C: d0368000                 sth     %o0, [%i2]
F003E380: 113c0435901220b0         set     aNfsMountingSFr, %o0! "NFS mounting \"%s\" from  %s:%s\n"
F003E388: 92100018                 mov     %i0, %o1
F003E38C: 94100019                 mov     %i1, %o2
F003E390: d807bfcc                 ld      [%fp+var_34], %o4
F003E394: 9610001b                 mov     %i3, %o3
F003E398: 7fff58b0                 call    _printf
F003E39C: d826a004                 st      %o4, [%i2+4]
F003E3A0: b0102000                 mov     0, %i0
F003E3A4: 81c7e008                 ret
F003E3A8: 81e80000                 restore
