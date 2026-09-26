F0041630: 9de3bf58                 save    %sp, -0xA8, %sp
F0041634: d206201c                 ld      [%i0+0x1C], %o1
F0041638: 113c04cf                 sethi   %hi(_active_u), %o0
F004163C: d40221d8                 ld      [%o0+%lo(_active_u)], %o2
F0041640: d6026014                 ld      [%o1+0x14], %o3
F0041644: 90100018                 mov     %i0, %o0
F0041648: d402a01c                 ld      [%o2+0x1C], %o2
F004164C: 9fc2c000                 call    %o3
F0041650: 9207bfb8                 add     %fp, var_48, %o1
F0041654: 80a22000                 cmp     %o0, 0
F0041658: 02800004                 be      loc_F0041668
F004165C: d257bfcc                 ldsh    [%fp+var_34], %o1
F0041660: 1080000a                 ba      locret_F0041688
F0041664: b0100008                 mov     %o0, %i0
F0041668: d2264000                 st      %o1, [%i1]
F004166C: d0062030                 ld      [%i0+0x30], %o0
F0041670: d002207c                 ld      [%o0+0x7C], %o0
F0041674: 80a22000                 cmp     %o0, 0
F0041678: 02800003                 be      loc_F0041684
F004167C: 90027fff                 add     %o1, -1, %o0
F0041680: d0264000                 st      %o0, [%i1]
F0041684: b0102000                 mov     0, %i0
F0041688: 81c7e008                 ret
F004168C: 81e80000                 restore
