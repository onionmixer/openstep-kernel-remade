F00429B0: 9de3bf98                 save    %sp, -0x68, %sp
F00429B4: d2060000                 ld      [%i0], %o1
F00429B8: 900a7ff7                 and     %o1, -9, %o0
F00429BC: 808a6010                 btst    0x10, %o1
F00429C0: 02800006                 be      locret_F00429D8
F00429C4: d0260000                 st      %o0, [%i0]
F00429C8: 900a7fe7                 and     %o1, -0x19, %o0
F00429CC: d0260000                 st      %o0, [%i0]
F00429D0: 7fff4106                 call    _wakeup
F00429D4: 90062068                 add     %i0, 0x68, %o0 ! 'h'
F00429D8: 81c7e008                 ret
F00429DC: 81e80000                 restore
