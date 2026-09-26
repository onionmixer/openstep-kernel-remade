F0028B64: 9de3bf98                 save    %sp, -0x68, %sp
F0028B68: d0162006                 lduh    [%i0+6], %o0
F0028B6C: 80a22000                 cmp     %o0, 0
F0028B70: 32800006                 bne,a   loc_F0028B88
F0028B74: d0162006                 lduh    [%i0+6], %o0
F0028B78: 113c0430                 sethi   %hi(aVnRele), %o0! "vn_rele"
F0028B7C: 7fffb17d                 call    _panic
F0028B80: 90122148                 bset    %lo(aVnRele), %o0! "vn_rele"
F0028B84: d0162006                 lduh    [%i0+6], %o0
F0028B88: 90023fff                 inc     -1, %o0
F0028B8C: d0362006                 sth     %o0, [%i0+6]
F0028B90: 912a2010                 sll     %o0, 16, %o0
F0028B94: 80a22000                 cmp     %o0, 0
F0028B98: 12800008                 bne     locret_F0028BB8
F0028B9C: 113c04cf                 sethi   %hi(_active_u), %o0
F0028BA0: d206201c                 ld      [%i0+0x1C], %o1
F0028BA4: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F0028BA8: d402604c                 ld      [%o1+0x4C], %o2
F0028BAC: d202201c                 ld      [%o0+0x1C], %o1
F0028BB0: 9fc28000                 call    %o2
F0028BB4: 90100018                 mov     %i0, %o0
F0028BB8: 81c7e008                 ret
F0028BBC: 81e80000                 restore
