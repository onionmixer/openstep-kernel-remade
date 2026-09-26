F00CF910: 9de3bf98                 save    %sp, -0x68, %sp
F00CF914: a80621b0                 add     %i0, 0x1B0, %l4
F00CF918: a40621a8                 add     %i0, 0x1A8, %l2
F00CF91C: 273c0506                 sethi   %hi(paLastreadystate_0), %l3
F00CF920: e204e17c                 ld      [%l3+%lo(paLastreadystate_0)], %l1
F00CF924: d00621b8                 ld      [%i0+0x1B8], %o0! id
F00CF928: 133c0503                 sethi   %hi(paLockwhen), %o1
F00CF92C: d20263f8                 ld      [%o1+%lo(paLockwhen)], %o1! SEL
F00CF930: 400087d0                 call    _objc_msgSend
F00CF934: 94102001                 mov     1, %o2
F00CF938: d00621b0                 ld      [%i0+0x1B0], %o0
F00CF93C: 80a50008                 cmp     %l4, %o0
F00CF940: 2280000b                 be,a    loc_F00CF96C
F00CF944: d00621a8                 ld      [%i0+0x1A8], %o0
F00CF948: a00621b0                 add     %i0, 0x1B0, %l0
F00CF94C: 90100018                 mov     %i0, %o0
F00CF950: 40000049                 call    sub_F00CFA74
F00CF954: 92102000                 mov     0, %o1
F00CF958: d00621b0                 ld      [%i0+0x1B0], %o0
F00CF95C: 80a40008                 cmp     %l0, %o0
F00CF960: 12bffffc                 bne     loc_F00CF950
F00CF964: 90100018                 mov     %i0, %o0
F00CF968: d00621a8                 ld      [%i0+0x1A8], %o0
F00CF96C: 80a48008                 cmp     %l2, %o0
F00CF970: 02800019                 be      loc_F00CF9D4
F00CF974: d204e17c                 ld      [%l3+0x17C], %o1! SEL
F00CF978: a00621a8                 add     %i0, 0x1A8, %l0
F00CF97C: 90100018                 mov     %i0, %o0! id
F00CF980: 400087bc                 call    _objc_msgSend
F00CF984: 92100011                 mov     %l1, %o1! SEL
F00CF988: 80a22002                 cmp     %o0, 2
F00CF98C: 02800011                 be      loc_F00CF9D0
F00CF990: 90100018                 mov     %i0, %o0! id
F00CF994: 400087b7                 call    _objc_msgSend
F00CF998: 92100011                 mov     %l1, %o1
F00CF99C: 80a22003                 cmp     %o0, 3
F00CF9A0: 2280000d                 be,a    loc_F00CF9D4
F00CF9A4: d204e17c                 ld      [%l3+0x17C], %o1
F00CF9A8: d04e21c8                 ldsb    [%i0+0x1C8], %o0
F00CF9AC: 80a22000                 cmp     %o0, 0
F00CF9B0: 12800008                 bne     loc_F00CF9D0
F00CF9B4: 90100018                 mov     %i0, %o0
F00CF9B8: 4000002f                 call    sub_F00CFA74
F00CF9BC: 92102001                 mov     1, %o1
F00CF9C0: d00621a8                 ld      [%i0+0x1A8], %o0
F00CF9C4: 80a40008                 cmp     %l0, %o0
F00CF9C8: 12bfffee                 bne     loc_F00CF980
F00CF9CC: 90100018                 mov     %i0, %o0! id
F00CF9D0: d204e17c                 ld      [%l3+0x17C], %o1! SEL
F00CF9D4: 400087a7                 call    _objc_msgSend
F00CF9D8: 90100018                 mov     %i0, %o0
F00CF9DC: d20621a8                 ld      [%i0+0x1A8], %o1
F00CF9E0: 80a48009                 cmp     %l2, %o1
F00CF9E4: 0280001c                 be      loc_F00CFA54
F00CF9E8: a0100008                 mov     %o0, %l0
F00CF9EC: 80a42001                 cmp     %l0, 1
F00CF9F0: 1280000b                 bne     loc_F00CFA1C
F00CF9F4: 80a42002                 cmp     %l0, 2
F00CF9F8: 113c0504                 sethi   %hi(paIsremovable), %o0! id
F00CF9FC: d20221a8                 ld      [%o0+%lo(paIsremovable)], %o1! SEL
F00CFA00: 4000879c                 call    _objc_msgSend
F00CFA04: 90100018                 mov     %i0, %o0
F00CFA08: 912a2018                 sll     %o0, 24, %o0
F00CFA0C: 80a22000                 cmp     %o0, 0
F00CFA10: 12800009                 bne     loc_F00CFA34
F00CFA14: 113c0505                 sethi   -0xFEBEC00, %o0
F00CFA18: 80a42002                 cmp     %l0, 2
F00CFA1C: 02800006                 be      loc_F00CFA34
F00CFA20: 113c0505                 sethi   -0xFEBEC00, %o0
F00CFA24: d04e21c8                 ldsb    [%i0+0x1C8], %o0
F00CFA28: 80a22000                 cmp     %o0, 0
F00CFA2C: 0280000a                 be      loc_F00CFA54
F00CFA30: 113c0505                 sethi   -0xFEBEC00, %o0! id
F00CFA34: d2022374                 ld      [%o0+0x374], %o1! SEL
F00CFA38: 4000878e                 call    _objc_msgSend
F00CFA3C: 90100018                 mov     %i0, %o0
F00CFA40: 90100018                 mov     %i0, %o0
F00CFA44: 7fffe25d                 call    _volCheckRequest
F00CFA48: 92102002                 mov     2, %o1
F00CFA4C: 10bfffb7                 ba      loc_F00CF928
F00CFA50: d00621b8                 ld      [%i0+0x1B8], %o0
F00CFA54: 113c0505                 sethi   %hi(paUnlockioqlock), %o0! id
F00CFA58: d2022374                 ld      [%o0+%lo(paUnlockioqlock)], %o1! SEL
F00CFA5C: 40008785                 call    _objc_msgSend
F00CFA60: 90100018                 mov     %i0, %o0
F00CFA64: 10bfffb1                 ba      loc_F00CF928
F00CFA68: d00621b8                 ld      [%i0+0x1B8], %o0
