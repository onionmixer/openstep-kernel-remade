F00B88D0: 9de3bf98                 save    %sp, -0x68, %sp
F00B88D4: 912e2003                 sll     %i0, 3, %o0
F00B88D8: 90220018                 sub     %o0, %i0, %o0
F00B88DC: a32a2004                 sll     %o0, 4, %l1
F00B88E0: 7ffebde4                 call    _kalloc
F00B88E4: 90100011                 mov     %l1, %o0! void *
F00B88E8: a0920000                 orcc    %o0, %g0, %l0
F00B88EC: 02800023                 be      locret_F00B8978
F00B88F0: 01000000                 nop
F00B88F4: 7fff7159                 call    _bzero
F00B88F8: 92100011                 mov     %l1, %o1
F00B88FC: 133c04fc                 sethi   %hi(_scsi_ncmds), %o1
F00B8900: d40260b8                 ld      [%o1+%lo(_scsi_ncmds)], %o2
F00B8904: 113c04fc                 sethi   %hi(_scsi_spl), %o0
F00B8908: d00220c0                 ld      [%o0+%lo(_scsi_spl)], %o0
F00B890C: 94028018                 add     %o2, %i0, %o2
F00B8910: 7fff78fd                 call    _splr
F00B8914: d42260b8                 st      %o2, [%o1+%lo(_scsi_ncmds)]
F00B8918: 94102000                 mov     0, %o2
F00B891C: 98063fff                 add     %i0, -1, %o4
F00B8920: 80a2800c                 cmp     %o2, %o4
F00B8924: 1680000b                 bge     loc_F00B8950
F00B8928: 9a100008                 mov     %o0, %o5
F00B892C: 96102070                 mov     0x70, %o3 ! 'p'
F00B8930: 92102000                 mov     0, %o1
F00B8934: 9004000b                 add     %l0, %o3, %o0
F00B8938: d0224010                 st      %o0, [%o1+%l0]
F00B893C: 9602e070                 inc     0x70, %o3 ! 'p'
F00B8940: 9402a001                 inc     %o2
F00B8944: 80a2800c                 cmp     %o2, %o4
F00B8948: 06bffffb                 bl      loc_F00B8934
F00B894C: 92026070                 inc     0x70, %o1 ! 'p'
F00B8950: 9010000d                 mov     %o5, %o0
F00B8954: 932e2003                 sll     %i0, 3, %o1
F00B8958: 92224018                 sub     %o1, %i0, %o1
F00B895C: 932a6004                 sll     %o1, 4, %o1
F00B8960: 173c04c5                 sethi   %hi(dword_F013179C), %o3
F00B8964: d402e39c                 ld      [%o3+%lo(dword_F013179C)], %o2
F00B8968: 92024010                 add     %o1, %l0, %o1
F00B896C: d4227f90                 st      %o2, [%o1-0x70]
F00B8970: 7fff78ed                 call    _splx
F00B8974: e022e39c                 st      %l0, [%o3+%lo(dword_F013179C)]
F00B8978: 81c7e008                 ret
F00B897C: 81e80000                 restore
