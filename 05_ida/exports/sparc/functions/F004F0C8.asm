F004F0C8: 9de3bf98                 save    %sp, -0x68, %sp
F004F0CC: d2162044                 lduh    [%i0+0x44], %o1
F004F0D0: 1100003f901223fe         set     0xFFFE, %o0
F004F0D8: 920a4008                 and     %o1, %o0, %o1
F004F0DC: 808a6010                 btst    0x10, %o1
F004F0E0: 02800008                 be      locret_F004F100
F004F0E4: d2362044                 sth     %o1, [%i0+0x44]
F004F0E8: 1100003f901223ef         set     0xFFEF, %o0
F004F0F0: 900a4008                 and     %o1, %o0, %o0
F004F0F4: d0362044                 sth     %o0, [%i0+0x44]
F004F0F8: 7fff0f3c                 call    _wakeup
F004F0FC: 90100018                 mov     %i0, %o0
F004F100: 81c7e008                 ret
F004F104: 81e80000                 restore
