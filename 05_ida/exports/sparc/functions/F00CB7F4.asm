F00CB7F4: 9de3bf90                 save    %sp, -0x70, %sp
F00CB7F8: d0062130                 ld      [%i0+0x130], %o0
F00CB7FC: 80a22000                 cmp     %o0, 0
F00CB800: 12800006                 bne     loc_F00CB818
F00CB804: 113c032c                 sethi   -0xFF35000, %o0
F00CB808: d0062134                 ld      [%i0+0x134], %o0
F00CB80C: 80a22000                 cmp     %o0, 0
F00CB810: 02800008                 be      locret_F00CB830
F00CB814: 113c032c                 sethi   -0xFF35000, %o0
F00CB818: 90122194                 bset    0x194, %o0
F00CB81C: 7ffe8a56                 call    _ns_untimeout
F00CB820: 92100018                 mov     %i0, %o1
F00CB824: 94102000                 mov     0, %o2
F00CB828: 96102000                 mov     0, %o3
F00CB82C: d43e2130                 std     %o2, [%i0+0x130]
F00CB830: 81c7e008                 ret
F00CB834: 81e80000                 restore
