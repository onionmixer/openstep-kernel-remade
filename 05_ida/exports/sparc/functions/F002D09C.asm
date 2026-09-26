F002D09C: 9de3bf98                 save    %sp, -0x68, %sp
F002D0A0: 111ff3e3901221f6         set     0x7FCF8DF6, %o0
F002D0A8: 90060008                 add     %i0, %o0, %o0
F002D0AC: 80a22001                 cmp     %o0, 1
F002D0B0: 08800004                 bleu    loc_F002D0C0
F002D0B4: 01000000                 nop
F002D0B8: 1080000e                 ba      locret_F002D0F0
F002D0BC: b0102016                 mov     0x16, %i0
F002D0C0: 7fff8a2b                 call    _suser
F002D0C4: 01000000                 nop
F002D0C8: 80a22000                 cmp     %o0, 0
F002D0CC: 02800006                 be      loc_F002D0E4
F002D0D0: 90100018                 mov     %i0, %o0
F002D0D4: 40000009                 call    _rtrequest
F002D0D8: 92100019                 mov     %i1, %o1
F002D0DC: 10800005                 ba      locret_F002D0F0
F002D0E0: b0100008                 mov     %o0, %i0
F002D0E4: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F002D0E8: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F002D0EC: f04a2038                 ldsb    [%o0+0x38], %i0
F002D0F0: 81c7e008                 ret
F002D0F4: 81e80000                 restore
