F00C65C8: 9de3bf58                 save    %sp, -0xA8, %sp
F00C65CC: e0070000                 ld      [%i4], %l0
F00C65D0: 80a42000                 cmp     %l0, 0
F00C65D4: 22800002                 be,a    loc_F00C65DC
F00C65D8: a0102200                 mov     0x200, %l0
F00C65DC: 9010001b                 mov     %i3, %o0! __s1
F00C65E0: 133c03ea                 sethi   %hi(aIodiskstats), %o1! "IODiskStats"
F00C65E4: 7ffd06f2                 call    _strcmp
F00C65E8: 92126328                 bset    %lo(aIodiskstats), %o1! "IODiskStats"
F00C65EC: 80a22000                 cmp     %o0, 0
F00C65F0: 12800031                 bne     loc_F00C66B4
F00C65F4: 9010001b                 mov     %i3, %o0
F00C65F8: d006213c                 ld      [%i0+0x13C], %o0
F00C65FC: d027bfb8                 st      %o0, [%fp+var_48]
F00C6600: d0062140                 ld      [%i0+0x140], %o0
F00C6604: d027bfbc                 st      %o0, [%fp+var_44]
F00C6608: d0062144                 ld      [%i0+0x144], %o0
F00C660C: d027bfc0                 st      %o0, [%fp+var_40]
F00C6610: d0062148                 ld      [%i0+0x148], %o0
F00C6614: d027bfc4                 st      %o0, [%fp+var_3C]
F00C6618: d006214c                 ld      [%i0+0x14C], %o0
F00C661C: d027bfc8                 st      %o0, [%fp+var_38]
F00C6620: d0062150                 ld      [%i0+0x150], %o0
F00C6624: d027bfcc                 st      %o0, [%fp+var_34]
F00C6628: d0062154                 ld      [%i0+0x154], %o0
F00C662C: d027bfd0                 st      %o0, [%fp+var_30]
F00C6630: d0062158                 ld      [%i0+0x158], %o0
F00C6634: d027bfd4                 st      %o0, [%fp+var_2C]
F00C6638: d006215c                 ld      [%i0+0x15C], %o0
F00C663C: d027bfd8                 st      %o0, [%fp+var_28]
F00C6640: d0062160                 ld      [%i0+0x160], %o0
F00C6644: d027bfdc                 st      %o0, [%fp+var_24]
F00C6648: d0062164                 ld      [%i0+0x164], %o0
F00C664C: d027bfe0                 st      %o0, [%fp+var_20]
F00C6650: d0062168                 ld      [%i0+0x168], %o0
F00C6654: 96102000                 mov     0, %o3
F00C6658: d027bfe4                 st      %o0, [%fp+var_1C]
F00C665C: d006216c                 ld      [%i0+0x16C], %o0
F00C6660: 9407bff8                 add     %fp, var_8, %o2
F00C6664: d027bfe8                 st      %o0, [%fp+var_18]
F00C6668: d0062170                 ld      [%i0+0x170], %o0
F00C666C: 92102000                 mov     0, %o1
F00C6670: d027bfec                 st      %o0, [%fp+var_14]
F00C6674: c0270000                 clr     [%i4]
F00C6678: d0070000                 ld      [%i4], %o0
F00C667C: 80a20010                 cmp     %o0, %l0
F00C6680: 02800014                 be      loc_F00C66D0
F00C6684: 9602e001                 inc     %o3
F00C6688: d002bfc0                 ld      [%o2-0x40], %o0
F00C668C: 80a2e00d                 cmp     %o3, 0xD
F00C6690: d022401a                 st      %o0, [%o1+%i2]
F00C6694: 9402a004                 inc     4, %o2
F00C6698: d0070000                 ld      [%i4], %o0! __s1
F00C669C: 92026004                 inc     4, %o1
F00C66A0: 90022001                 inc     %o0
F00C66A4: 04bffff5                 ble     loc_F00C6678
F00C66A8: d0270000                 st      %o0, [%i4]
F00C66AC: 10800024                 ba      locret_F00C673C
F00C66B0: b0102000                 mov     0, %i0
F00C66B4: 133c03ea                 sethi   %hi(aIoisadisk), %o1! "IOIsADisk"
F00C66B8: 7ffd06bd                 call    _strcmp
F00C66BC: 92126338                 bset    %lo(aIoisadisk), %o1! "IOIsADisk"
F00C66C0: 80a22000                 cmp     %o0, 0
F00C66C4: 12800005                 bne     loc_F00C66D8
F00C66C8: 9010001b                 mov     %i3, %o0! __s1
F00C66CC: c0270000                 clr     [%i4]
F00C66D0: 1080001b                 ba      locret_F00C673C
F00C66D4: b0102000                 mov     0, %i0
F00C66D8: 133c03ea                 sethi   %hi(aIoisaphysicald), %o1! "IOIsAPhysicalDisk"
F00C66DC: 7ffd06b4                 call    _strcmp
F00C66E0: 92126348                 bset    %lo(aIoisaphysicald), %o1! "IOIsAPhysicalDisk"
F00C66E4: 80a22000                 cmp     %o0, 0
F00C66E8: 0280000e                 be      loc_F00C6720
F00C66EC: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00C66F0: f027bff0                 st      %i0, [%fp+var_10]
F00C66F4: 133c0507                 sethi   %hi(stru_F0141EBC.ext), %o1
F00C66F8: 9610001b                 mov     %i3, %o3
F00C66FC: d40262e8                 ld      [%o1+%lo(stru_F0141EBC.ext)], %o2
F00C6700: 9810001c                 mov     %i4, %o4
F00C6704: 133c0504                 sethi   %hi(paGetintvaluesFo_0), %o1
F00C6708: d427bff4                 st      %o2, [%fp+var_C]
F00C670C: d20262c8                 ld      [%o1+%lo(paGetintvaluesFo_0)], %o1! SEL
F00C6710: 4000ac9b                 call    _objc_msgSendSuper
F00C6714: 9410001a                 mov     %i2, %o2
F00C6718: 10800009                 ba      locret_F00C673C
F00C671C: b0100008                 mov     %o0, %i0
F00C6720: 90102001                 mov     1, %o0
F00C6724: d0270000                 st      %o0, [%i4]
F00C6728: d04e2116                 ldsb    [%i0+0x116], %o0
F00C672C: b0102000                 mov     0, %i0
F00C6730: 80a00008                 cmp     %g0, %o0
F00C6734: 90402000                 addc    %g0, 0, %o0
F00C6738: d0268000                 st      %o0, [%i2]
F00C673C: 81c7e008                 ret
F00C6740: 81e80000                 restore
