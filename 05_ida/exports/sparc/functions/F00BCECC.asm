F00BCECC: 9de3bf98                 save    %sp, -0x68, %sp
F00BCED0: b2100018                 mov     %i0, %i1
F00BCED4: c4066008                 ld      [%i1+8], %g2
F00BCED8: 8600bfb4                 add     %g2, -0x4C, %g3
F00BCEDC: 80a0e02e                 cmp     %g3, 0x2E ! '.'! switch 47 cases
F00BCEE0: 18800050                 bgu     def_F00BCEF8! jumptable F00BCEF8 default case, cases 1-22,24-33,35-43,45
F00BCEE4: b0102000                 mov     0, %i0
F00BCEE8: 053c02f38410a300         set     jpt_F00BCEF8, %g2
F00BCEF0: 8728e002                 sll     %g3, 2, %g3
F00BCEF4: c400c002                 ld      [%g3+%g2], %g2
F00BCEF8: 81c08000                 jmp     %g2! switch jump
F00BCEFC: 01000000                 nop
F00BCFBC: c0266008                 clr     [%i1+8]! jumptable F00BCEF8 case 0
F00BCFC0: c64e600c                 ldsb    [%i1+0xC], %g3
F00BCFC4: 053c04c8                 sethi   %hi(dword_F013204C), %g2
F00BCFC8: 10800017                 ba      loc_F00BD024
F00BCFCC: c620a04c                 st      %g3, [%g2+%lo(dword_F013204C)]
F00BCFD0: c0266008                 clr     [%i1+8]! jumptable F00BCEF8 case 23
F00BCFD4: c64e600c                 ldsb    [%i1+0xC], %g3
F00BCFD8: 053c04c8                 sethi   %hi(dword_F0132050), %g2
F00BCFDC: 10800012                 ba      loc_F00BD024
F00BCFE0: c620a050                 st      %g3, [%g2+%lo(dword_F0132050)]
F00BCFE4: c0266008                 clr     [%i1+8]! jumptable F00BCEF8 case 34
F00BCFE8: c64e600c                 ldsb    [%i1+0xC], %g3
F00BCFEC: 053c04c8                 sethi   %hi(dword_F0132054), %g2
F00BCFF0: 1080000d                 ba      loc_F00BD024
F00BCFF4: c620a054                 st      %g3, [%g2+%lo(dword_F0132054)]
F00BCFF8: c0266008                 clr     [%i1+8]! jumptable F00BCEF8 case 44
F00BCFFC: c64e600c                 ldsb    [%i1+0xC], %g3
F00BD000: 053c04c8                 sethi   %hi(dword_F0132058), %g2
F00BD004: 10800008                 ba      loc_F00BD024
F00BD008: c620a058                 st      %g3, [%g2+%lo(dword_F0132058)]
F00BD00C: c0266008                 clr     [%i1+8]! jumptable F00BCEF8 case 46
F00BD010: c64e600c                 ldsb    [%i1+0xC], %g3
F00BD014: 053c04c8                 sethi   %hi(dword_F013205C), %g2
F00BD018: 10800003                 ba      loc_F00BD024
F00BD01C: c620a05c                 st      %g3, [%g2+%lo(dword_F013205C)]
F00BD020: b0102001                 mov     1, %i0! jumptable F00BCEF8 default case, cases 1-22,24-33,35-43,45
F00BD024: 80a62000                 cmp     %i0, 0
F00BD028: 12800004                 bne     loc_F00BD038
F00BD02C: 053c04c8                 sethi   -0xFECE000, %g2
F00BD030: 1080003a                 ba      locret_F00BD118
F00BD034: b0102100                 mov     0x100, %i0
F00BD038: c400a054                 ld      [%g2+0x54], %g2
F00BD03C: 80a0a000                 cmp     %g2, 0
F00BD040: 12800007                 bne     loc_F00BD05C
F00BD044: b0102000                 mov     0, %i0
F00BD048: 053c04c8                 sethi   %hi(dword_F0132050), %g2
F00BD04C: c400a050                 ld      [%g2+%lo(dword_F0132050)], %g2
F00BD050: 80a0a000                 cmp     %g2, 0
F00BD054: 02800004                 be      loc_F00BD064
F00BD058: 053c04c8                 sethi   -0xFECE000, %g2
F00BD05C: b0102001                 mov     1, %i0
F00BD060: 053c04c8                 sethi   -0xFECE000, %g2
F00BD064: c400a04c                 ld      [%g2+0x4C], %g2
F00BD068: 80a00002                 cmp     %g0, %g2
F00BD06C: 86602000                 subc    %g0, 0, %g3
F00BD070: c4066008                 ld      [%i1+8], %g2
F00BD074: 8608e100                 and     %g3, 0x100, %g3
F00BD078: 8528a001                 sll     %g2, 1, %g2
F00BD07C: 84108018                 bset    %i0, %g2
F00BD080: 84008003                 add     %g2, %g3, %g2
F00BD084: 313c047fb01623bc         set     _ascii, %i0
F00BD08C: 073c04c8                 sethi   %hi(dword_F013205C), %g3
F00BD090: c600e05c                 ld      [%g3+%lo(dword_F013205C)], %g3
F00BD094: 8528a001                 sll     %g2, 1, %g2
F00BD098: 80a0e000                 cmp     %g3, 0
F00BD09C: 12800007                 bne     loc_F00BD0B8
F00BD0A0: f4108018                 lduh    [%g2+%i0], %i2
F00BD0A4: 053c04c8                 sethi   %hi(dword_F0132058), %g2
F00BD0A8: c400a058                 ld      [%g2+%lo(dword_F0132058)], %g2
F00BD0AC: 80a0a000                 cmp     %g2, 0
F00BD0B0: 02800003                 be      loc_F00BD0BC
F00BD0B4: b0102000                 mov     0, %i0
F00BD0B8: b0102080                 mov     0x80, %i0
F00BD0BC: 8606beff                 add     %i2, -0x101, %g3
F00BD0C0: 80a0e007                 cmp     %g3, 7! switch 8 cases
F00BD0C4: 1880000f                 bgu     def_F00BD0D8! jumptable F00BD0D8 default case, cases 2,4
F00BD0C8: 053c02f4                 sethi   %hi(jpt_F00BD0D8), %g2
F00BD0CC: 8410a0e0                 bset    %lo(jpt_F00BD0D8), %g2
F00BD0D0: 8728e002                 sll     %g3, 2, %g3
F00BD0D4: c400c002                 ld      [%g3+%g2], %g2
F00BD0D8: 81c08000                 jmp     %g2! switch jump
F00BD0DC: 01000000                 nop
F00BD100: b4168018                 bset    %i0, %i2! jumptable F00BD0D8 default case, cases 2,4
F00BD104: c44e600c                 ldsb    [%i1+0xC], %g2! jumptable F00BD0D8 cases 0,1,3,5-7
F00BD108: 80a0a000                 cmp     %g2, 0
F00BD10C: 02800003                 be      locret_F00BD118
F00BD110: b0102100                 mov     0x100, %i0
F00BD114: b010001a                 mov     %i2, %i0
F00BD118: 81c7e008                 ret
F00BD11C: 81e80000                 restore
