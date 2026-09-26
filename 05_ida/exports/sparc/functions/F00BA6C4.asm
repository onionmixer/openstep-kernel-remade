F00BA6C4: 9de3bf98                 save    %sp, -0x68, %sp
F00BA6C8: d0062010                 ld      [%i0+0x10], %o0
F00BA6CC: d4062018                 ld      [%i0+0x18], %o2
F00BA6D0: d60a2002                 ldub    [%o0+2], %o3
F00BA6D4: 80a2e000                 cmp     %o3, 0
F00BA6D8: 12800006                 bne     loc_F00BA6F0
F00BA6DC: d8028000                 ld      [%o2], %o4
F00BA6E0: d00aa00e                 ldub    [%o2+0xE], %o0
F00BA6E4: 808a2080                 btst    0x80, %o0
F00BA6E8: 12800034                 bne     locret_F00BA7B8
F00BA6EC: 01000000                 nop
F00BA6F0: d012a110                 lduh    [%o2+0x110], %o0
F00BA6F4: 92022001                 add     %o0, 1, %o1
F00BA6F8: d232a110                 sth     %o1, [%o2+0x110]
F00BA6FC: 912a2010                 sll     %o0, 16, %o0
F00BA700: 913a2010                 sra     %o0, 16, %o0
F00BA704: 90028008                 add     %o2, %o0, %o0
F00BA708: d62a200f                 stb     %o3, [%o0+0xF]
F00BA70C: d052a110                 ldsh    [%o2+0x110], %o0
F00BA710: 80a220ff                 cmp     %o0, 0xFF
F00BA714: 34800002                 bg,a    loc_F00BA71C
F00BA718: c032a110                 clrh    [%o2+0x110]
F00BA71C: d252a110                 ldsh    [%o2+0x110], %o1
F00BA720: d052a112                 ldsh    [%o2+0x112], %o0
F00BA724: 80a24008                 cmp     %o1, %o0
F00BA728: 32800006                 bne,a   loc_F00BA740
F00BA72C: d012a00c                 lduh    [%o2+0xC], %o0
F00BA730: d012a008                 lduh    [%o2+8], %o0
F00BA734: 90022001                 inc     %o0
F00BA738: d032a008                 sth     %o0, [%o2+8]
F00BA73C: d012a00c                 lduh    [%o2+0xC], %o0
F00BA740: 90022001                 inc     %o0
F00BA744: d032a00c                 sth     %o0, [%o2+0xC]
F00BA748: d0132038                 lduh    [%o4+0x38], %o0
F00BA74C: 900a201f                 and     %o0, 0x1F, %o0
F00BA750: 80a22003                 cmp     %o0, 3
F00BA754: 0280000e                 be      loc_F00BA78C
F00BA758: 900ae07f                 and     %o3, 0x7F, %o0
F00BA75C: d24b2052                 ldsb    [%o4+0x52], %o1
F00BA760: 80a20009                 cmp     %o0, %o1
F00BA764: 2280000b                 be,a    loc_F00BA790
F00BA768: c032a004                 clrh    [%o2+4]
F00BA76C: d012a004                 lduh    [%o2+4], %o0
F00BA770: 90022001                 inc     %o0
F00BA774: d032a004                 sth     %o0, [%o2+4]
F00BA778: 912a2010                 sll     %o0, 16, %o0
F00BA77C: 913a2010                 sra     %o0, 16, %o0
F00BA780: 80a22014                 cmp     %o0, 0x14
F00BA784: 0480000d                 ble     locret_F00BA7B8
F00BA788: 01000000                 nop
F00BA78C: c032a004                 clrh    [%o2+4]
F00BA790: d00e2030                 ldub    [%i0+0x30], %o0
F00BA794: 133c04fd                 sethi   %hi(_zssoftpend), %o1
F00BA798: 90122001                 bset    1, %o0
F00BA79C: d02e2030                 stb     %o0, [%i0+0x30]
F00BA7A0: d00261d8                 ld      [%o1+%lo(_zssoftpend)], %o0
F00BA7A4: 80a22000                 cmp     %o0, 0
F00BA7A8: 12800004                 bne     locret_F00BA7B8
F00BA7AC: 90102001                 mov     1, %o0
F00BA7B0: 40000364                 call    _setzssoft
F00BA7B4: d02261d8                 st      %o0, [%o1+%lo(_zssoftpend)]
F00BA7B8: 81c7e008                 ret
F00BA7BC: 81e80000                 restore
