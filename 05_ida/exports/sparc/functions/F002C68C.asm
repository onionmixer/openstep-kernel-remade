F002C68C: 9de3bf98                 save    %sp, -0x68, %sp
F002C690: 073c04d88410e3f0         set     _rawcb, %g2
F002C698: c420a004                 st      %g2, [%g2+4]
F002C69C: c420e3f0                 st      %g2, [%g3+0x3F0]
F002C6A0: 073c04d0                 sethi   %hi(dword_F013416C), %g3
F002C6A4: 84102032                 mov     0x32, %g2 ! '2'
F002C6A8: c420e16c                 st      %g2, [%g3+%lo(dword_F013416C)]
F002C6AC: 81c7e008                 ret
F002C6B0: 81e80000                 restore
