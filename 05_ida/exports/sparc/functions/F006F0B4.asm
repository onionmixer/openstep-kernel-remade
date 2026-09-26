F006F0B4: 9de3bf98                 save    %sp, -0x68, %sp
F006F0B8: f6062018                 ld      [%i0+0x18], %i3
F006F0BC: 84066138                 add     %i1, 0x138, %g2
F006F0C0: 80a0801b                 cmp     %g2, %i3
F006F0C4: 12800004                 bne     loc_F006F0D4
F006F0C8: c606201c                 ld      [%i0+0x1C], %g3
F006F0CC: 10800004                 ba      loc_F006F0DC
F006F0D0: c626613c                 st      %g3, [%i1+0x13C]
F006F0D4: c626e01c                 st      %g3, [%i3+0x1C]
F006F0D8: 84066138                 add     %i1, 0x138, %g2
F006F0DC: 80a08003                 cmp     %g2, %g3
F006F0E0: 32800003                 bne,a   loc_F006F0EC
F006F0E4: f620e018                 st      %i3, [%g3+0x18]
F006F0E8: f6266138                 st      %i3, [%i1+0x138]
F006F0EC: c4066140                 ld      [%i1+0x140], %g2
F006F0F0: 8400bfff                 inc     -1, %g2
F006F0F4: c4266140                 st      %g2, [%i1+0x140]
F006F0F8: c606a13c                 ld      [%i2+0x13C], %g3
F006F0FC: 8406a138                 add     %i2, 0x138, %g2
F006F100: 80a08003                 cmp     %g2, %g3
F006F104: 32800003                 bne,a   loc_F006F110
F006F108: f020e018                 st      %i0, [%g3+0x18]
F006F10C: f026a138                 st      %i0, [%i2+0x138]
F006F110: c626201c                 st      %g3, [%i0+0x1C]
F006F114: 8406a138                 add     %i2, 0x138, %g2
F006F118: c4262018                 st      %g2, [%i0+0x18]
F006F11C: f026a13c                 st      %i0, [%i2+0x13C]
F006F120: f4262190                 st      %i2, [%i0+0x190]
F006F124: c406a140                 ld      [%i2+0x140], %g2
F006F128: 8400a001                 inc     %g2
F006F12C: c426a140                 st      %g2, [%i2+0x140]
F006F130: 81c7e008                 ret
F006F134: 81e80000                 restore
