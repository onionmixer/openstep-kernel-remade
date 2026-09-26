F0094244: 9de3bf98                 save    %sp, -0x68, %sp
F0094248: 073c04c4                 sethi   %hi(dword_F0131264), %g3
F009424C: c400e264                 ld      [%g3+%lo(dword_F0131264)], %g2
F0094250: 80a0a000                 cmp     %g2, 0
F0094254: 32800004                 bne,a   loc_F0094264
F0094258: c020e264                 clr     [%g3+%lo(dword_F0131264)]
F009425C: 10800003                 ba      locret_F0094268
F0094260: b0102000                 mov     0, %i0
F0094264: b0102001                 mov     1, %i0
F0094268: 81c7e008                 ret
F009426C: 81e80000                 restore
