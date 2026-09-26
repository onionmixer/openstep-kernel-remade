F0099F74: 9de3bf98                 save    %sp, -0x68, %sp
F0099F78: 113c04c5                 sethi   %hi(dword_F0131498), %o0
F0099F7C: d0022098                 ld      [%o0+%lo(dword_F0131498)], %o0
F0099F80: 80a22000                 cmp     %o0, 0
F0099F84: 02800004                 be      locret_F0099F94
F0099F88: 92100019                 mov     %i1, %o1
F0099F8C: 7fff7372                 call    _calloutRemove
F0099F90: 90100018                 mov     %i0, %o0
F0099F94: 81c7e008                 ret
F0099F98: 81e80000                 restore
