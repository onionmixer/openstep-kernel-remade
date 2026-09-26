F000B394: 9de3bf98                 save    %sp, -0x68, %sp
F000B398: 133c04d090126058         set     _file_list, %o0
F000B3A0: d0222004                 st      %o0, [%o0+4]
F000B3A4: d0226058                 st      %o0, [%o1+0x58]
F000B3A8: 113c042b                 sethi   %hi(_max_file), %o0
F000B3AC: d2022240                 ld      [%o0+%lo(_max_file)], %o1
F000B3B0: 7fffec54                 call    _umul
F000B3B4: 90102024                 mov     0x24, %o0 ! '$'
F000B3B8: 92100008                 mov     %o0, %o1
F000B3BC: 90102024                 mov     0x24, %o0 ! '$'
F000B3C0: 193c042b                 sethi   %hi(aFileStructs), %o4! "file structs"
F000B3C4: 94102000                 mov     0, %o2
F000B3C8: 96102000                 mov     0, %o3
F000B3CC: 4001b2db                 call    _zinit
F000B3D0: 98132248                 bset    %lo(aFileStructs), %o4! "file structs"
F000B3D4: 133c04d2                 sethi   %hi(_file_zone), %o1
F000B3D8: d0226230                 st      %o0, [%o1+%lo(_file_zone)]
F000B3DC: 81c7e008                 ret
F000B3E0: 81e80000                 restore
