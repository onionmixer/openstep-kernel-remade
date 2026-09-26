F001E7B4: 9de3bf98                 save    %sp, -0x68, %sp
F001E7B8: d0062008                 ld      [%i0+8], %o0
F001E7BC: 80a22000                 cmp     %o0, 0
F001E7C0: 1280001f                 bne     locret_F001E83C
F001E7C4: 01000000                 nop
F001E7C8: d0162006                 lduh    [%i0+6], %o0
F001E7CC: 808a2001                 btst    1, %o0
F001E7D0: 0280001b                 be      locret_F001E83C
F001E7D4: 01000000                 nop
F001E7D8: d0062010                 ld      [%i0+0x10], %o0
F001E7DC: 80a22000                 cmp     %o0, 0
F001E7E0: 02800011                 be      loc_F001E824
F001E7E4: 90100018                 mov     %i0, %o0
F001E7E8: 4000069e                 call    _soqremque
F001E7EC: 92102000                 mov     0, %o1
F001E7F0: 80a22000                 cmp     %o0, 0
F001E7F4: 3280000c                 bne,a   loc_F001E824
F001E7F8: c0262010                 clr     [%i0+0x10]
F001E7FC: 90100018                 mov     %i0, %o0
F001E800: 40000698                 call    _soqremque
F001E804: 92102001                 mov     1, %o1
F001E808: 80a22000                 cmp     %o0, 0
F001E80C: 32800006                 bne,a   loc_F001E824
F001E810: c0262010                 clr     [%i0+0x10]
F001E814: 113c042e                 sethi   %hi(aSofreeDq), %o0! "sofree dq"
F001E818: 7fffda56                 call    _panic
F001E81C: 901223e0                 bset    %lo(aSofreeDq), %o0! "sofree dq"
F001E820: c0262010                 clr     [%i0+0x10]
F001E824: 40000739                 call    _sbrelease
F001E828: 9006203c                 add     %i0, 0x3C, %o0 ! '<'
F001E82C: 40000453                 call    _sorflush
F001E830: 90100018                 mov     %i0, %o0
F001E834: 7ffffca0                 call    _m_free
F001E838: 900e3f80                 and     %i0, -0x80, %o0
F001E83C: 81c7e008                 ret
F001E840: 81e80000                 restore
