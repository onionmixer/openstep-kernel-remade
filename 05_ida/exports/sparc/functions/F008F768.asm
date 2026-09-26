F008F768: 9de3bf90                 save    %sp, -0x70, %sp
F008F76C: a2100018                 mov     %i0, %l1
F008F770: a0102000                 mov     0, %l0
F008F774: 2b3c0504                 sethi   -0xFEBF000, %l5
F008F778: 293c0504                 sethi   -0xFEBF000, %l4
F008F77C: 273c0504                 sethi   -0xFEBF000, %l3
F008F780: a407bff0                 add     %fp, var_10, %l2
F008F784: d20560b8                 ld      [%l5+0xB8], %o1! SEL
F008F788: 4001883a                 call    _objc_msgSend
F008F78C: 90100011                 mov     %l1, %o0
F008F790: 80a40008                 cmp     %l0, %o0
F008F794: 1a800016                 bcc     loc_F008F7EC
F008F798: 90100011                 mov     %l1, %o0! id
F008F79C: d20520c8                 ld      [%l4+0xC8], %o1! SEL
F008F7A0: 40018834                 call    _objc_msgSend
F008F7A4: 94100010                 mov     %l0, %o2
F008F7A8: e423a040                 st      %l2, [%sp+0x70+var_30]
F008F7AC: b0100008                 mov     %o0, %i0
F008F7B0: d204e058                 ld      [%l3+0x58], %o1! SEL
F008F7B4: 4001882f                 call    _objc_msgSend
F008F7B8: 01000000                 nop
F008F7BC: 00000008                 illtrap
F008F7C0: d207bff0                 ld      [%fp+var_10], %o1
F008F7C4: d0064000                 ld      [%i1], %o0
F008F7C8: 80a24008                 cmp     %o1, %o0
F008F7CC: 12bfffee                 bne     loc_F008F784
F008F7D0: a0042001                 inc     %l0
F008F7D4: d207bff4                 ld      [%fp+var_C], %o1
F008F7D8: d0066004                 ld      [%i1+4], %o0
F008F7DC: 80a24008                 cmp     %o1, %o0
F008F7E0: 02800004                 be      locret_F008F7F0
F008F7E4: d20560b8                 ld      [%l5+0xB8], %o1
F008F7E8: 30bfffe8                 ba,a    loc_F008F788
F008F7EC: b0102000                 mov     0, %i0
F008F7F0: 81c7e008                 ret
F008F7F4: 81e80000                 restore
