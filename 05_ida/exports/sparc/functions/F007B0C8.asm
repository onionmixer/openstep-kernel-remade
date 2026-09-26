F007B0C8: 9de3bf98                 save    %sp, -0x68, %sp
F007B0CC: 113c044390122340         set     aNotificationSe, %o0! "notification server: %s: krtn = %d\n"
F007B0D4: 92100019                 mov     %i1, %o1
F007B0D8: 7ffe6560                 call    _printf
F007B0DC: 94100018                 mov     %i0, %o2
F007B0E0: 113c0443                 sethi   %hi(aNotificationSe_0), %o0! "notification server"
F007B0E4: 7ffe6823                 call    _panic
F007B0E8: 90122368                 bset    %lo(aNotificationSe_0), %o0! "notification server"
F007B0EC: 81c7e008                 ret
F007B0F0: 81e80000                 restore
