F0091238: 9de3bf90                 save    %sp, -0x70, %sp
F009123C: d0062004                 ld      [%i0+4], %o0
F0091240: 80a2206c                 cmp     %o0, 0x6C ! 'l'
F0091244: 12800018                 bne     loc_F00912A4
F0091248: 90103ed0                 mov     -0x130, %o0
F009124C: d0060000                 ld      [%i0], %o0
F0091250: 80a22000                 cmp     %o0, 0
F0091254: 06800013                 bl      loc_F00912A0
F0091258: 133c0448                 sethi   %hi(dword_F0112264), %o1
F009125C: d0062018                 ld      [%i0+0x18], %o0
F0091260: d2026264                 ld      [%o1+%lo(dword_F0112264)], %o1
F0091264: 80a20009                 cmp     %o0, %o1
F0091268: 1280000f                 bne     loc_F00912A4
F009126C: 90103ed0                 mov     -0x130, %o0
F0091270: d0062020                 ld      [%i0+0x20], %o0
F0091274: 133c0448                 sethi   %hi(dword_F0112268), %o1
F0091278: d2026268                 ld      [%o1+%lo(dword_F0112268)], %o1
F009127C: 80a20009                 cmp     %o0, %o1
F0091280: 12800009                 bne     loc_F00912A4
F0091284: 90103ed0                 mov     -0x130, %o0
F0091288: d0062064                 ld      [%i0+0x64], %o0
F009128C: 133c0448                 sethi   %hi(dword_F011226C), %o1
F0091290: d202626c                 ld      [%o1+%lo(dword_F011226C)], %o1
F0091294: 80a20009                 cmp     %o0, %o1
F0091298: 02800005                 be      loc_F00912AC
F009129C: 92102200                 mov     0x200, %o1
F00912A0: 90103ed0                 mov     -0x130, %o0
F00912A4: 1080001c                 ba      locret_F0091314
F00912A8: d026601c                 st      %o0, [%i1+0x1C]
F00912AC: d0062008                 ld      [%i0+8], %o0
F00912B0: 7fff4ff7                 call    _convert_port_to_host
F00912B4: d227bff4                 st      %o1, [%fp+var_C]
F00912B8: 94062024                 add     %i0, 0x24, %o2 ! '$'
F00912BC: d206201c                 ld      [%i0+0x1C], %o1
F00912C0: 98066024                 add     %i1, 0x24, %o4 ! '$'
F00912C4: d6062068                 ld      [%i0+0x68], %o3
F00912C8: 7ffffc53                 call    _kern_IOGetIntValues
F00912CC: 9a07bff4                 add     %fp, var_C, %o5
F00912D0: 80a22000                 cmp     %o0, 0
F00912D4: 12800010                 bne     locret_F0091314
F00912D8: d026601c                 st      %o0, [%i1+0x1C]
F00912DC: 113c0448                 sethi   %hi(dword_F0112270), %o0
F00912E0: d4022270                 ld      [%o0+%lo(dword_F0112270)], %o2
F00912E4: d207bff4                 ld      [%fp+var_C], %o1
F00912E8: d4266020                 st      %o2, [%i1+0x20]
F00912EC: 113fffc09012200f         set     -0xFFF1, %o0
F00912F4: 940a8008                 and     %o2, %o0, %o2
F00912F8: 900a6fff                 and     %o1, 0xFFF, %o0
F00912FC: 912a2004                 sll     %o0, 4, %o0
F0091300: 94128008                 bset    %o0, %o2
F0091304: d4266020                 st      %o2, [%i1+0x20]
F0091308: 932a6002                 sll     %o1, 2, %o1
F009130C: 92026024                 inc     0x24, %o1 ! '$'
F0091310: d2266004                 st      %o1, [%i1+4]
F0091314: 81c7e008                 ret
F0091318: 81e80000                 restore
