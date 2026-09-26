F009FBA0: 9de3bf98                 save    %sp, -0x68, %sp
F009FBA4: 113c0463                 sethi   %hi(_pmap_var_info), %o0
F009FBA8: d0022180                 ld      [%o0+%lo(_pmap_var_info)], %o0
F009FBAC: 80a22000                 cmp     %o0, 0
F009FBB0: 02800059                 be      loc_F009FD14
F009FBB4: 213c04f7                 sethi   %hi(word_F013DE72), %l0
F009FBB8: d2142272                 lduh    [%l0+%lo(word_F013DE72)], %o1
F009FBBC: 113c0460                 sethi   %hi(aDRegTblsVmPage), %o0! "----  %d reg tbls/vm page ; %d seg tbls"...
F009FBC0: a0142272                 bset    %lo(word_F013DE72), %l0
F009FBC4: d4142002                 lduh    [%l0+2], %o2
F009FBC8: 7ffdd2a4                 call    _printf
F009FBCC: 90122088                 bset    %lo(aDRegTblsVmPage), %o0! "----  %d reg tbls/vm page ; %d seg tbls"...
F009FBD0: d2142004                 lduh    [%l0+4], %o1
F009FBD4: 113c0460                 sethi   %hi(aDRegPoolsVmPag), %o0! "----  %d reg pools/vm page ; %d seg poo"...
F009FBD8: d4142006                 lduh    [%l0+6], %o2
F009FBDC: 7ffdd29f                 call    _printf
F009FBE0: 901220c0                 bset    %lo(aDRegPoolsVmPag), %o0! "----  %d reg pools/vm page ; %d seg poo"...
F009FBE4: 113c0460                 sethi   %hi(aTksegtblsD), %o0! "tksegtbls\t\t= %d\n"
F009FBE8: d204200a                 ld      [%l0+0xA], %o1
F009FBEC: 7ffdd29b                 call    _printf
F009FBF0: 901220f8                 bset    %lo(aTksegtblsD), %o0! "tksegtbls\t\t= %d\n"
F009FBF4: 113c0460                 sethi   %hi(aNksegtblsInuse), %o0! "nksegtbls_inuse\t\t= %d\n"
F009FBF8: d2042012                 ld      [%l0+0x12], %o1
F009FBFC: 7ffdd297                 call    _printf
F009FC00: 90122110                 bset    %lo(aNksegtblsInuse), %o0! "nksegtbls_inuse\t\t= %d\n"
F009FC04: 113c0460                 sethi   %hi(aTksegpoolsD), %o0! "tksegpools\t\t= %d\n"
F009FC08: d204200e                 ld      [%l0+0xE], %o1
F009FC0C: 7ffdd293                 call    _printf
F009FC10: 90122128                 bset    %lo(aTksegpoolsD), %o0! "tksegpools\t\t= %d\n"
F009FC14: 113c04f7                 sethi   %hi(dword_F013DE38), %o0
F009FC18: d2022238                 ld      [%o0+%lo(dword_F013DE38)], %o1
F009FC1C: 113c0460                 sethi   %hi(aKsegActiveCoun), %o0! "kseg_active.count\t= %d\n"
F009FC20: 7ffdd28e                 call    _printf
F009FC24: 90122140                 bset    %lo(aKsegActiveCoun), %o0! "kseg_active.count\t= %d\n"
F009FC28: 113c04f7                 sethi   %hi(dword_F013DE48), %o0
F009FC2C: d2022248                 ld      [%o0+%lo(dword_F013DE48)], %o1
F009FC30: 113c0460                 sethi   %hi(aKsegSemiActive), %o0! "kseg_semi_active.count\t= %d\n"
F009FC34: 7ffdd289                 call    _printf
F009FC38: 90122158                 bset    %lo(aKsegSemiActive), %o0! "kseg_semi_active.count\t= %d\n"
F009FC3C: 113c0460                 sethi   %hi(aNuregtblsAlloc), %o0! "nuregtbls_allocd\t= %d\n"
F009FC40: d2042026                 ld      [%l0+0x26], %o1
F009FC44: 7ffdd285                 call    _printf
F009FC48: 90122178                 bset    %lo(aNuregtblsAlloc), %o0! "nuregtbls_allocd\t= %d\n"
F009FC4C: 113c0460                 sethi   %hi(aNuregtblsInuse), %o0! "nuregtbls_inuse\t\t= %d\n"
F009FC50: d2042022                 ld      [%l0+0x22], %o1
F009FC54: 7ffdd281                 call    _printf
F009FC58: 90122190                 bset    %lo(aNuregtblsInuse), %o0! "nuregtbls_inuse\t\t= %d\n"
F009FC5C: 113c0460                 sethi   %hi(aNuregpoolsD), %o0! "nuregpools\t\t= %d\n"
F009FC60: d204202a                 ld      [%l0+0x2A], %o1
F009FC64: 7ffdd27d                 call    _printf
F009FC68: 901221a8                 bset    %lo(aNuregpoolsD), %o0! "nuregpools\t\t= %d\n"
F009FC6C: 113c04f7                 sethi   %hi(dword_F013DFA8), %o0
F009FC70: d20223a8                 ld      [%o0+%lo(dword_F013DFA8)], %o1
F009FC74: 113c0460                 sethi   %hi(aRegFreeCountD), %o0! "reg_free.count\t\t= %d\n"
F009FC78: 7ffdd278                 call    _printf
F009FC7C: 901221c0                 bset    %lo(aRegFreeCountD), %o0! "reg_free.count\t\t= %d\n"
F009FC80: 113c04f7                 sethi   %hi(dword_F013DFB8), %o0
F009FC84: d20223b8                 ld      [%o0+%lo(dword_F013DFB8)], %o1
F009FC88: 113c0460                 sethi   %hi(aRegSemiActiveC), %o0! "reg_semi_active.count\t= %d\n"
F009FC8C: 7ffdd273                 call    _printf
F009FC90: 901221d8                 bset    %lo(aRegSemiActiveC), %o0! "reg_semi_active.count\t= %d\n"
F009FC94: 113c04f7                 sethi   %hi(dword_F013DF98), %o0
F009FC98: d2022398                 ld      [%o0+%lo(dword_F013DF98)], %o1
F009FC9C: 113c0460                 sethi   %hi(aRegActiveCount), %o0! "reg_active.count\t= %d\n"
F009FCA0: 7ffdd26e                 call    _printf
F009FCA4: 901221f8                 bset    %lo(aRegActiveCount), %o0! "reg_active.count\t= %d\n"
F009FCA8: 113c0460                 sethi   %hi(aNusegtblsAlloc), %o0! "nusegtbls_allocd\t= %d\n"
F009FCAC: d204201a                 ld      [%l0+0x1A], %o1
F009FCB0: 7ffdd26a                 call    _printf
F009FCB4: 90122210                 bset    %lo(aNusegtblsAlloc), %o0! "nusegtbls_allocd\t= %d\n"
F009FCB8: 113c0460                 sethi   %hi(aNusegtblsInuse), %o0! "nusegtbls_inuse\t\t= %d\n"
F009FCBC: d2042016                 ld      [%l0+0x16], %o1
F009FCC0: 7ffdd266                 call    _printf
F009FCC4: 90122228                 bset    %lo(aNusegtblsInuse), %o0! "nusegtbls_inuse\t\t= %d\n"
F009FCC8: 113c0460                 sethi   %hi(aNusegpoolsD), %o0! "nusegpools\t\t= %d\n"
F009FCCC: d204201e                 ld      [%l0+0x1E], %o1
F009FCD0: 7ffdd262                 call    _printf
F009FCD4: 90122240                 bset    %lo(aNusegpoolsD), %o0! "nusegpools\t\t= %d\n"
F009FCD8: 113c04f7                 sethi   %hi(dword_F013DFD8), %o0
F009FCDC: d20223d8                 ld      [%o0+%lo(dword_F013DFD8)], %o1
F009FCE0: 113c0460                 sethi   %hi(aSegFreeCountD), %o0! "seg_free.count\t\t= %d\n"
F009FCE4: 7ffdd25d                 call    _printf
F009FCE8: 90122258                 bset    %lo(aSegFreeCountD), %o0! "seg_free.count\t\t= %d\n"
F009FCEC: 113c04f7                 sethi   %hi(dword_F013DFE8), %o0
F009FCF0: d20223e8                 ld      [%o0+%lo(dword_F013DFE8)], %o1
F009FCF4: 113c0460                 sethi   %hi(aSegSemiActiveC), %o0! "seg_semi_active.count\t= %d\n"
F009FCF8: 7ffdd258                 call    _printf
F009FCFC: 90122270                 bset    %lo(aSegSemiActiveC), %o0! "seg_semi_active.count\t= %d\n"
F009FD00: 113c04f7                 sethi   %hi(dword_F013DFC8), %o0
F009FD04: d20223c8                 ld      [%o0+%lo(dword_F013DFC8)], %o1
F009FD08: 113c0460                 sethi   %hi(aSegActiveCount), %o0! "seg_active.count\t= %d\n"
F009FD0C: 7ffdd253                 call    _printf
F009FD10: 90122290                 bset    %lo(aSegActiveCount), %o0! "seg_active.count\t= %d\n"
F009FD14: 113c04f7                 sethi   %hi(dword_F013DEA0), %o0
F009FD18: d00222a0                 ld      [%o0+%lo(dword_F013DEA0)], %o0
F009FD1C: 80a22000                 cmp     %o0, 0
F009FD20: 1280000b                 bne     loc_F009FD4C
F009FD24: 113c04f7                 sethi   -0xFEC2400, %o0
F009FD28: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F009FD2C: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F009FD30: 80a22000                 cmp     %o0, 0
F009FD34: 02800005                 be      loc_F009FD48
F009FD38: 113c0460                 sethi   %hi(aPmapVacflushD), %o0! "pmap_vacflush \t=\t%d\n"
F009FD3C: 901222a8                 bset    %lo(aPmapVacflushD), %o0! "pmap_vacflush \t=\t%d\n"
F009FD40: 1080000c                 ba      loc_F009FD70
F009FD44: 92102000                 mov     0, %o1
F009FD48: 113c04f7                 sethi   -0xFEC2400, %o0
F009FD4C: d20222a0                 ld      [%o0+0x2A0], %o1
F009FD50: 80a26000                 cmp     %o1, 0
F009FD54: 02800009                 be      loc_F009FD78
F009FD58: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F009FD5C: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F009FD60: 80a22000                 cmp     %o0, 0
F009FD64: 02800005                 be      loc_F009FD78
F009FD68: 113c0460                 sethi   %hi(aPmapVacflushD_0), %o0! "pmap_vacflush \t=\t%d\n"
F009FD6C: 901222c0                 bset    %lo(aPmapVacflushD_0), %o0! "pmap_vacflush \t=\t%d\n"
F009FD70: 7ffdd23a                 call    _printf
F009FD74: 01000000                 nop
F009FD78: 113c04f7                 sethi   %hi(dword_F013DEA4), %o0
F009FD7C: d00222a4                 ld      [%o0+%lo(dword_F013DEA4)], %o0
F009FD80: 80a22000                 cmp     %o0, 0
F009FD84: 1280000b                 bne     loc_F009FDB0
F009FD88: 113c04f7                 sethi   -0xFEC2400, %o0
F009FD8C: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F009FD90: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F009FD94: 80a22000                 cmp     %o0, 0
F009FD98: 02800005                 be      loc_F009FDAC
F009FD9C: 113c0460                 sethi   %hi(aPmapMapD), %o0! "pmap_map \t=\t%d\n"
F009FDA0: 901222d8                 bset    %lo(aPmapMapD), %o0! "pmap_map \t=\t%d\n"
F009FDA4: 1080000c                 ba      loc_F009FDD4
F009FDA8: 92102000                 mov     0, %o1
F009FDAC: 113c04f7                 sethi   -0xFEC2400, %o0
F009FDB0: d20222a4                 ld      [%o0+0x2A4], %o1
F009FDB4: 80a26000                 cmp     %o1, 0
F009FDB8: 02800009                 be      loc_F009FDDC
F009FDBC: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F009FDC0: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F009FDC4: 80a22000                 cmp     %o0, 0
F009FDC8: 02800005                 be      loc_F009FDDC
F009FDCC: 113c0460                 sethi   %hi(aPmapMapD_0), %o0! "pmap_map \t=\t%d\n"
F009FDD0: 901222e8                 bset    %lo(aPmapMapD_0), %o0! "pmap_map \t=\t%d\n"
F009FDD4: 7ffdd221                 call    _printf
F009FDD8: 01000000                 nop
F009FDDC: 113c04f7                 sethi   %hi(dword_F013DEA8), %o0
F009FDE0: d00222a8                 ld      [%o0+%lo(dword_F013DEA8)], %o0
F009FDE4: 80a22000                 cmp     %o0, 0
F009FDE8: 1280000b                 bne     loc_F009FE14
F009FDEC: 113c04f7                 sethi   -0xFEC2400, %o0
F009FDF0: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F009FDF4: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F009FDF8: 80a22000                 cmp     %o0, 0
F009FDFC: 02800005                 be      loc_F009FE10
F009FE00: 113c0460                 sethi   %hi(aPmapChangeProt), %o0! "pmap_change_prot \t=\t%d\n"
F009FE04: 901222f8                 bset    %lo(aPmapChangeProt), %o0! "pmap_change_prot \t=\t%d\n"
F009FE08: 1080000c                 ba      loc_F009FE38
F009FE0C: 92102000                 mov     0, %o1
F009FE10: 113c04f7                 sethi   -0xFEC2400, %o0
F009FE14: d20222a8                 ld      [%o0+0x2A8], %o1
F009FE18: 80a26000                 cmp     %o1, 0
F009FE1C: 02800009                 be      loc_F009FE40
F009FE20: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F009FE24: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F009FE28: 80a22000                 cmp     %o0, 0
F009FE2C: 02800005                 be      loc_F009FE40
F009FE30: 113c0460                 sethi   %hi(aPmapChangeProt_0), %o0! "pmap_change_prot \t=\t%d\n"
F009FE34: 90122310                 bset    %lo(aPmapChangeProt_0), %o0! "pmap_change_prot \t=\t%d\n"
F009FE38: 7ffdd208                 call    _printf
F009FE3C: 01000000                 nop
F009FE40: 113c04f7                 sethi   %hi(dword_F013DEAC), %o0
F009FE44: d00222ac                 ld      [%o0+%lo(dword_F013DEAC)], %o0
F009FE48: 80a22000                 cmp     %o0, 0
F009FE4C: 1280000b                 bne     loc_F009FE78
F009FE50: 113c04f7                 sethi   -0xFEC2400, %o0
F009FE54: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F009FE58: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F009FE5C: 80a22000                 cmp     %o0, 0
F009FE60: 02800005                 be      loc_F009FE74
F009FE64: 113c0460                 sethi   %hi(aPmapCreateD), %o0! "pmap_create \t=\t%d\n"
F009FE68: 90122328                 bset    %lo(aPmapCreateD), %o0! "pmap_create \t=\t%d\n"
F009FE6C: 1080000c                 ba      loc_F009FE9C
F009FE70: 92102000                 mov     0, %o1
F009FE74: 113c04f7                 sethi   -0xFEC2400, %o0
F009FE78: d20222ac                 ld      [%o0+0x2AC], %o1
F009FE7C: 80a26000                 cmp     %o1, 0
F009FE80: 02800009                 be      loc_F009FEA4
F009FE84: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F009FE88: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F009FE8C: 80a22000                 cmp     %o0, 0
F009FE90: 02800005                 be      loc_F009FEA4
F009FE94: 113c0460                 sethi   %hi(aPmapCreateD_0), %o0! "pmap_create \t=\t%d\n"
F009FE98: 90122340                 bset    %lo(aPmapCreateD_0), %o0! "pmap_create \t=\t%d\n"
F009FE9C: 7ffdd1ef                 call    _printf
F009FEA0: 01000000                 nop
F009FEA4: 113c04f7                 sethi   %hi(dword_F013DEB0), %o0
F009FEA8: d00222b0                 ld      [%o0+%lo(dword_F013DEB0)], %o0
F009FEAC: 80a22000                 cmp     %o0, 0
F009FEB0: 1280000b                 bne     loc_F009FEDC
F009FEB4: 113c04f7                 sethi   -0xFEC2400, %o0
F009FEB8: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F009FEBC: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F009FEC0: 80a22000                 cmp     %o0, 0
F009FEC4: 02800005                 be      loc_F009FED8
F009FEC8: 113c0460                 sethi   %hi(aPmapDestroyD), %o0! "pmap_destroy \t=\t%d\n"
F009FECC: 90122358                 bset    %lo(aPmapDestroyD), %o0! "pmap_destroy \t=\t%d\n"
F009FED0: 1080000c                 ba      loc_F009FF00
F009FED4: 92102000                 mov     0, %o1
F009FED8: 113c04f7                 sethi   -0xFEC2400, %o0
F009FEDC: d20222b0                 ld      [%o0+0x2B0], %o1
F009FEE0: 80a26000                 cmp     %o1, 0
F009FEE4: 02800009                 be      loc_F009FF08
F009FEE8: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F009FEEC: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F009FEF0: 80a22000                 cmp     %o0, 0
F009FEF4: 02800005                 be      loc_F009FF08
F009FEF8: 113c0460                 sethi   %hi(aPmapDestroyD_0), %o0! "pmap_destroy \t=\t%d\n"
F009FEFC: 90122370                 bset    %lo(aPmapDestroyD_0), %o0! "pmap_destroy \t=\t%d\n"
F009FF00: 7ffdd1d6                 call    _printf
F009FF04: 01000000                 nop
F009FF08: 113c04f7                 sethi   %hi(dword_F013DEB4), %o0
F009FF0C: d00222b4                 ld      [%o0+%lo(dword_F013DEB4)], %o0
F009FF10: 80a22000                 cmp     %o0, 0
F009FF14: 1280000b                 bne     loc_F009FF40
F009FF18: 113c04f7                 sethi   -0xFEC2400, %o0
F009FF1C: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F009FF20: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F009FF24: 80a22000                 cmp     %o0, 0
F009FF28: 02800005                 be      loc_F009FF3C
F009FF2C: 113c0460                 sethi   %hi(aPmapReferenceD), %o0! "pmap_reference \t=\t%d\n"
F009FF30: 90122388                 bset    %lo(aPmapReferenceD), %o0! "pmap_reference \t=\t%d\n"
F009FF34: 1080000c                 ba      loc_F009FF64
F009FF38: 92102000                 mov     0, %o1
F009FF3C: 113c04f7                 sethi   -0xFEC2400, %o0
F009FF40: d20222b4                 ld      [%o0+0x2B4], %o1
F009FF44: 80a26000                 cmp     %o1, 0
F009FF48: 02800009                 be      loc_F009FF6C
F009FF4C: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F009FF50: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F009FF54: 80a22000                 cmp     %o0, 0
F009FF58: 02800005                 be      loc_F009FF6C
F009FF5C: 113c0460                 sethi   %hi(aPmapReferenceD_0), %o0! "pmap_reference \t=\t%d\n"
F009FF60: 901223a0                 bset    %lo(aPmapReferenceD_0), %o0! "pmap_reference \t=\t%d\n"
F009FF64: 7ffdd1bd                 call    _printf
F009FF68: 01000000                 nop
F009FF6C: 113c04f7                 sethi   %hi(dword_F013DEB8), %o0
F009FF70: d00222b8                 ld      [%o0+%lo(dword_F013DEB8)], %o0
F009FF74: 80a22000                 cmp     %o0, 0
F009FF78: 1280000b                 bne     loc_F009FFA4
F009FF7C: 113c04f7                 sethi   -0xFEC2400, %o0
F009FF80: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F009FF84: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F009FF88: 80a22000                 cmp     %o0, 0
F009FF8C: 02800005                 be      loc_F009FFA0
F009FF90: 113c0460                 sethi   %hi(aPmapPageTableE_3), %o0! "pmap_page_table_entry \t=\t%d\n"
F009FF94: 901223b8                 bset    %lo(aPmapPageTableE_3), %o0! "pmap_page_table_entry \t=\t%d\n"
F009FF98: 1080000c                 ba      loc_F009FFC8
F009FF9C: 92102000                 mov     0, %o1
F009FFA0: 113c04f7                 sethi   -0xFEC2400, %o0
F009FFA4: d20222b8                 ld      [%o0+0x2B8], %o1
F009FFA8: 80a26000                 cmp     %o1, 0
F009FFAC: 02800009                 be      loc_F009FFD0
F009FFB0: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F009FFB4: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F009FFB8: 80a22000                 cmp     %o0, 0
F009FFBC: 02800005                 be      loc_F009FFD0
F009FFC0: 113c0460                 sethi   %hi(aPmapPageTableE_4), %o0! "pmap_page_table_entry \t=\t%d\n"
F009FFC4: 901223d8                 bset    %lo(aPmapPageTableE_4), %o0! "pmap_page_table_entry \t=\t%d\n"
F009FFC8: 7ffdd1a4                 call    _printf
F009FFCC: 01000000                 nop
F009FFD0: 113c0463                 sethi   %hi(_pmap_opt_info), %o0
F009FFD4: d0022184                 ld      [%o0+%lo(_pmap_opt_info)], %o0
F009FFD8: 80a22000                 cmp     %o0, 0
F009FFDC: 0280000b                 be      loc_F00A0008
F009FFE0: 113c0460                 sethi   %hi(aPmapPageTableE_5), %o0! "pmap_page_table_entry \t=\t%d\n"
F009FFE4: 213c04f7                 sethi   %hi(dword_F013DEB8), %l0
F009FFE8: d20422b8                 ld      [%l0+%lo(dword_F013DEB8)], %o1
F009FFEC: 901223f8                 bset    %lo(aPmapPageTableE_5), %o0! "pmap_page_table_entry \t=\t%d\n"
F009FFF0: 7ffdd19a                 call    _printf
F009FFF4: a01422b8                 bset    %lo(dword_F013DEB8), %l0
F009FFF8: 113c0461                 sethi   %hi(aPmapPageTableE_6), %o0! "pmap_page_table_entry_act \t=\t%d\n"
F009FFFC: d2042004                 ld      [%l0+4], %o1
F00A0000: 7ffdd196                 call    _printf
F00A0004: 90122018                 bset    %lo(aPmapPageTableE_6), %o0! "pmap_page_table_entry_act \t=\t%d\n"
F00A0008: 113c04f7                 sethi   %hi(dword_F013DEC0), %o0
F00A000C: d00222c0                 ld      [%o0+%lo(dword_F013DEC0)], %o0
F00A0010: 80a22000                 cmp     %o0, 0
F00A0014: 1280000b                 bne     loc_F00A0040
F00A0018: 113c04f7                 sethi   -0xFEC2400, %o0
F00A001C: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A0020: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A0024: 80a22000                 cmp     %o0, 0
F00A0028: 02800005                 be      loc_F00A003C
F00A002C: 113c0461                 sethi   %hi(aPmapGetpteD), %o0! "pmap_getpte \t=\t%d\n"
F00A0030: 90122040                 bset    %lo(aPmapGetpteD), %o0! "pmap_getpte \t=\t%d\n"
F00A0034: 1080000c                 ba      loc_F00A0064
F00A0038: 92102000                 mov     0, %o1
F00A003C: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0040: d20222c0                 ld      [%o0+0x2C0], %o1
F00A0044: 80a26000                 cmp     %o1, 0
F00A0048: 02800009                 be      loc_F00A006C
F00A004C: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A0050: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A0054: 80a22000                 cmp     %o0, 0
F00A0058: 02800005                 be      loc_F00A006C
F00A005C: 113c0461                 sethi   %hi(aPmapGetpteD_0), %o0! "pmap_getpte \t=\t%d\n"
F00A0060: 90122058                 bset    %lo(aPmapGetpteD_0), %o0! "pmap_getpte \t=\t%d\n"
F00A0064: 7ffdd17d                 call    _printf
F00A0068: 01000000                 nop
F00A006C: 113c04f7                 sethi   %hi(dword_F013DEC4), %o0
F00A0070: d00222c4                 ld      [%o0+%lo(dword_F013DEC4)], %o0
F00A0074: 80a22000                 cmp     %o0, 0
F00A0078: 1280000b                 bne     loc_F00A00A4
F00A007C: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0080: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A0084: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A0088: 80a22000                 cmp     %o0, 0
F00A008C: 02800005                 be      loc_F00A00A0
F00A0090: 113c0461                 sethi   %hi(aPmapRemoveD), %o0! "pmap_remove \t=\t%d\n"
F00A0094: 90122070                 bset    %lo(aPmapRemoveD), %o0! "pmap_remove \t=\t%d\n"
F00A0098: 1080000c                 ba      loc_F00A00C8
F00A009C: 92102000                 mov     0, %o1
F00A00A0: 113c04f7                 sethi   -0xFEC2400, %o0
F00A00A4: d20222c4                 ld      [%o0+0x2C4], %o1
F00A00A8: 80a26000                 cmp     %o1, 0
F00A00AC: 02800009                 be      loc_F00A00D0
F00A00B0: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A00B4: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A00B8: 80a22000                 cmp     %o0, 0
F00A00BC: 02800005                 be      loc_F00A00D0
F00A00C0: 113c0461                 sethi   %hi(aPmapRemoveD_0), %o0! "pmap_remove \t=\t%d\n"
F00A00C4: 90122088                 bset    %lo(aPmapRemoveD_0), %o0! "pmap_remove \t=\t%d\n"
F00A00C8: 7ffdd164                 call    _printf
F00A00CC: 01000000                 nop
F00A00D0: 113c04f7                 sethi   %hi(dword_F013DEC8), %o0
F00A00D4: d00222c8                 ld      [%o0+%lo(dword_F013DEC8)], %o0
F00A00D8: 80a22000                 cmp     %o0, 0
F00A00DC: 1280000b                 bne     loc_F00A0108
F00A00E0: 113c04f7                 sethi   -0xFEC2400, %o0
F00A00E4: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A00E8: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A00EC: 80a22000                 cmp     %o0, 0
F00A00F0: 02800005                 be      loc_F00A0104
F00A00F4: 113c0461                 sethi   %hi(aPmapRemoveAllD), %o0! "pmap_remove_all \t=\t%d\n"
F00A00F8: 901220a0                 bset    %lo(aPmapRemoveAllD), %o0! "pmap_remove_all \t=\t%d\n"
F00A00FC: 1080000c                 ba      loc_F00A012C
F00A0100: 92102000                 mov     0, %o1
F00A0104: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0108: d20222c8                 ld      [%o0+0x2C8], %o1
F00A010C: 80a26000                 cmp     %o1, 0
F00A0110: 02800009                 be      loc_F00A0134
F00A0114: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A0118: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A011C: 80a22000                 cmp     %o0, 0
F00A0120: 02800005                 be      loc_F00A0134
F00A0124: 113c0461                 sethi   %hi(aPmapRemoveAllD_0), %o0! "pmap_remove_all \t=\t%d\n"
F00A0128: 901220b8                 bset    %lo(aPmapRemoveAllD_0), %o0! "pmap_remove_all \t=\t%d\n"
F00A012C: 7ffdd14b                 call    _printf
F00A0130: 01000000                 nop
F00A0134: 113c04f7                 sethi   %hi(dword_F013DECC), %o0
F00A0138: d00222cc                 ld      [%o0+%lo(dword_F013DECC)], %o0
F00A013C: 80a22000                 cmp     %o0, 0
F00A0140: 1280000b                 bne     loc_F00A016C
F00A0144: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0148: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A014C: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A0150: 80a22000                 cmp     %o0, 0
F00A0154: 02800005                 be      loc_F00A0168
F00A0158: 113c0461                 sethi   %hi(aPmapExpandD), %o0! "pmap_expand \t=\t%d\n"
F00A015C: 901220d0                 bset    %lo(aPmapExpandD), %o0! "pmap_expand \t=\t%d\n"
F00A0160: 1080000c                 ba      loc_F00A0190
F00A0164: 92102000                 mov     0, %o1
F00A0168: 113c04f7                 sethi   -0xFEC2400, %o0
F00A016C: d20222cc                 ld      [%o0+0x2CC], %o1
F00A0170: 80a26000                 cmp     %o1, 0
F00A0174: 02800009                 be      loc_F00A0198
F00A0178: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A017C: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A0180: 80a22000                 cmp     %o0, 0
F00A0184: 02800005                 be      loc_F00A0198
F00A0188: 113c0461                 sethi   %hi(aPmapExpandD_0), %o0! "pmap_expand \t=\t%d\n"
F00A018C: 901220e8                 bset    %lo(aPmapExpandD_0), %o0! "pmap_expand \t=\t%d\n"
F00A0190: 7ffdd132                 call    _printf
F00A0194: 01000000                 nop
F00A0198: 113c04f7                 sethi   %hi(dword_F013DED0), %o0
F00A019C: d00222d0                 ld      [%o0+%lo(dword_F013DED0)], %o0
F00A01A0: 80a22000                 cmp     %o0, 0
F00A01A4: 1280000b                 bne     loc_F00A01D0
F00A01A8: 113c04f7                 sethi   -0xFEC2400, %o0
F00A01AC: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A01B0: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A01B4: 80a22000                 cmp     %o0, 0
F00A01B8: 02800005                 be      loc_F00A01CC
F00A01BC: 113c0461                 sethi   %hi(aPmapEnterDevD), %o0! "pmap_enter_dev \t=\t%d\n"
F00A01C0: 90122100                 bset    %lo(aPmapEnterDevD), %o0! "pmap_enter_dev \t=\t%d\n"
F00A01C4: 1080000c                 ba      loc_F00A01F4
F00A01C8: 92102000                 mov     0, %o1
F00A01CC: 113c04f7                 sethi   -0xFEC2400, %o0
F00A01D0: d20222d0                 ld      [%o0+0x2D0], %o1
F00A01D4: 80a26000                 cmp     %o1, 0
F00A01D8: 02800009                 be      loc_F00A01FC
F00A01DC: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A01E0: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A01E4: 80a22000                 cmp     %o0, 0
F00A01E8: 02800005                 be      loc_F00A01FC
F00A01EC: 113c0461                 sethi   %hi(aPmapEnterDevD_0), %o0! "pmap_enter_dev \t=\t%d\n"
F00A01F0: 90122118                 bset    %lo(aPmapEnterDevD_0), %o0! "pmap_enter_dev \t=\t%d\n"
F00A01F4: 7ffdd119                 call    _printf
F00A01F8: 01000000                 nop
F00A01FC: 113c04f7                 sethi   %hi(dword_F013DED4), %o0
F00A0200: d00222d4                 ld      [%o0+%lo(dword_F013DED4)], %o0
F00A0204: 80a22000                 cmp     %o0, 0
F00A0208: 1280000b                 bne     loc_F00A0234
F00A020C: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0210: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A0214: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A0218: 80a22000                 cmp     %o0, 0
F00A021C: 02800005                 be      loc_F00A0230
F00A0220: 113c0461                 sethi   %hi(aPmapEnterCache), %o0! "pmap_enter_cache_spec \t=\t%d\n"
F00A0224: 90122130                 bset    %lo(aPmapEnterCache), %o0! "pmap_enter_cache_spec \t=\t%d\n"
F00A0228: 1080000c                 ba      loc_F00A0258
F00A022C: 92102000                 mov     0, %o1
F00A0230: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0234: d20222d4                 ld      [%o0+0x2D4], %o1
F00A0238: 80a26000                 cmp     %o1, 0
F00A023C: 02800009                 be      loc_F00A0260
F00A0240: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A0244: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A0248: 80a22000                 cmp     %o0, 0
F00A024C: 02800005                 be      loc_F00A0260
F00A0250: 113c0461                 sethi   %hi(aPmapEnterCache_0), %o0! "pmap_enter_cache_spec \t=\t%d\n"
F00A0254: 90122150                 bset    %lo(aPmapEnterCache_0), %o0! "pmap_enter_cache_spec \t=\t%d\n"
F00A0258: 7ffdd100                 call    _printf
F00A025C: 01000000                 nop
F00A0260: 113c04f7                 sethi   %hi(dword_F013DED8), %o0
F00A0264: d00222d8                 ld      [%o0+%lo(dword_F013DED8)], %o0
F00A0268: 80a22000                 cmp     %o0, 0
F00A026C: 1280000b                 bne     loc_F00A0298
F00A0270: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0274: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A0278: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A027C: 80a22000                 cmp     %o0, 0
F00A0280: 02800005                 be      loc_F00A0294
F00A0284: 113c0461                 sethi   %hi(aPmapEnterShare), %o0! "pmap_enter_shared_range \t=\t%d\n"
F00A0288: 90122170                 bset    %lo(aPmapEnterShare), %o0! "pmap_enter_shared_range \t=\t%d\n"
F00A028C: 1080000c                 ba      loc_F00A02BC
F00A0290: 92102000                 mov     0, %o1
F00A0294: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0298: d20222d8                 ld      [%o0+0x2D8], %o1
F00A029C: 80a26000                 cmp     %o1, 0
F00A02A0: 02800009                 be      loc_F00A02C4
F00A02A4: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A02A8: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A02AC: 80a22000                 cmp     %o0, 0
F00A02B0: 02800005                 be      loc_F00A02C4
F00A02B4: 113c0461                 sethi   %hi(aPmapEnterShare_0), %o0! "pmap_enter_shared_range \t=\t%d\n"
F00A02B8: 90122190                 bset    %lo(aPmapEnterShare_0), %o0! "pmap_enter_shared_range \t=\t%d\n"
F00A02BC: 7ffdd0e7                 call    _printf
F00A02C0: 01000000                 nop
F00A02C4: 113c04f7                 sethi   %hi(dword_F013DEDC), %o0
F00A02C8: d00222dc                 ld      [%o0+%lo(dword_F013DEDC)], %o0
F00A02CC: 80a22000                 cmp     %o0, 0
F00A02D0: 1280000b                 bne     loc_F00A02FC
F00A02D4: 113c04f7                 sethi   -0xFEC2400, %o0
F00A02D8: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A02DC: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A02E0: 80a22000                 cmp     %o0, 0
F00A02E4: 02800005                 be      loc_F00A02F8
F00A02E8: 113c0461                 sethi   %hi(aPmapCopyOnWrit), %o0! "pmap_copy_on_write \t=\t%d\n"
F00A02EC: 901221b0                 bset    %lo(aPmapCopyOnWrit), %o0! "pmap_copy_on_write \t=\t%d\n"
F00A02F0: 1080000c                 ba      loc_F00A0320
F00A02F4: 92102000                 mov     0, %o1
F00A02F8: 113c04f7                 sethi   -0xFEC2400, %o0
F00A02FC: d20222dc                 ld      [%o0+0x2DC], %o1
F00A0300: 80a26000                 cmp     %o1, 0
F00A0304: 02800009                 be      loc_F00A0328
F00A0308: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A030C: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A0310: 80a22000                 cmp     %o0, 0
F00A0314: 02800005                 be      loc_F00A0328
F00A0318: 113c0461                 sethi   %hi(aPmapCopyOnWrit_0), %o0! "pmap_copy_on_write \t=\t%d\n"
F00A031C: 901221d0                 bset    %lo(aPmapCopyOnWrit_0), %o0! "pmap_copy_on_write \t=\t%d\n"
F00A0320: 7ffdd0ce                 call    _printf
F00A0324: 01000000                 nop
F00A0328: 113c04f7                 sethi   %hi(dword_F013DEE0), %o0
F00A032C: d00222e0                 ld      [%o0+%lo(dword_F013DEE0)], %o0
F00A0330: 80a22000                 cmp     %o0, 0
F00A0334: 1280000b                 bne     loc_F00A0360
F00A0338: 113c04f7                 sethi   -0xFEC2400, %o0
F00A033C: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A0340: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A0344: 80a22000                 cmp     %o0, 0
F00A0348: 02800005                 be      loc_F00A035C
F00A034C: 113c0461                 sethi   %hi(aPmapMovePageD), %o0! "pmap_move_page \t=\t%d\n"
F00A0350: 901221f0                 bset    %lo(aPmapMovePageD), %o0! "pmap_move_page \t=\t%d\n"
F00A0354: 1080000c                 ba      loc_F00A0384
F00A0358: 92102000                 mov     0, %o1
F00A035C: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0360: d20222e0                 ld      [%o0+0x2E0], %o1
F00A0364: 80a26000                 cmp     %o1, 0
F00A0368: 02800009                 be      loc_F00A038C
F00A036C: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A0370: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A0374: 80a22000                 cmp     %o0, 0
F00A0378: 02800005                 be      loc_F00A038C
F00A037C: 113c0461                 sethi   %hi(aPmapMovePageD_0), %o0! "pmap_move_page \t=\t%d\n"
F00A0380: 90122208                 bset    %lo(aPmapMovePageD_0), %o0! "pmap_move_page \t=\t%d\n"
F00A0384: 7ffdd0b5                 call    _printf
F00A0388: 01000000                 nop
F00A038C: 113c04f7                 sethi   %hi(dword_F013DEE4), %o0
F00A0390: d00222e4                 ld      [%o0+%lo(dword_F013DEE4)], %o0
F00A0394: 80a22000                 cmp     %o0, 0
F00A0398: 1280000b                 bne     loc_F00A03C4
F00A039C: 113c04f7                 sethi   -0xFEC2400, %o0
F00A03A0: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A03A4: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A03A8: 80a22000                 cmp     %o0, 0
F00A03AC: 02800005                 be      loc_F00A03C0
F00A03B0: 113c0461                 sethi   %hi(aPmapProtectD), %o0! "pmap_protect \t=\t%d\n"
F00A03B4: 90122220                 bset    %lo(aPmapProtectD), %o0! "pmap_protect \t=\t%d\n"
F00A03B8: 1080000c                 ba      loc_F00A03E8
F00A03BC: 92102000                 mov     0, %o1
F00A03C0: 113c04f7                 sethi   -0xFEC2400, %o0
F00A03C4: d20222e4                 ld      [%o0+0x2E4], %o1
F00A03C8: 80a26000                 cmp     %o1, 0
F00A03CC: 02800009                 be      loc_F00A03F0
F00A03D0: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A03D4: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A03D8: 80a22000                 cmp     %o0, 0
F00A03DC: 02800005                 be      loc_F00A03F0
F00A03E0: 113c0461                 sethi   %hi(aPmapProtectD_0), %o0! "pmap_protect \t=\t%d\n"
F00A03E4: 90122238                 bset    %lo(aPmapProtectD_0), %o0! "pmap_protect \t=\t%d\n"
F00A03E8: 7ffdd09c                 call    _printf
F00A03EC: 01000000                 nop
F00A03F0: 113c04f7                 sethi   %hi(dword_F013DEE8), %o0
F00A03F4: d00222e8                 ld      [%o0+%lo(dword_F013DEE8)], %o0
F00A03F8: 80a22000                 cmp     %o0, 0
F00A03FC: 1280000b                 bne     loc_F00A0428
F00A0400: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0404: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A0408: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A040C: 80a22000                 cmp     %o0, 0
F00A0410: 02800005                 be      loc_F00A0424
F00A0414: 113c0461                 sethi   %hi(aPmapPageProtec), %o0! "pmap_page_protect \t=\t%d\n"
F00A0418: 90122250                 bset    %lo(aPmapPageProtec), %o0! "pmap_page_protect \t=\t%d\n"
F00A041C: 1080000c                 ba      loc_F00A044C
F00A0420: 92102000                 mov     0, %o1
F00A0424: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0428: d20222e8                 ld      [%o0+0x2E8], %o1
F00A042C: 80a26000                 cmp     %o1, 0
F00A0430: 02800009                 be      loc_F00A0454
F00A0434: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A0438: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A043C: 80a22000                 cmp     %o0, 0
F00A0440: 02800005                 be      loc_F00A0454
F00A0444: 113c0461                 sethi   %hi(aPmapPageProtec_0), %o0! "pmap_page_protect \t=\t%d\n"
F00A0448: 90122270                 bset    %lo(aPmapPageProtec_0), %o0! "pmap_page_protect \t=\t%d\n"
F00A044C: 7ffdd083                 call    _printf
F00A0450: 01000000                 nop
F00A0454: 113c04f7                 sethi   %hi(dword_F013DEEC), %o0
F00A0458: d00222ec                 ld      [%o0+%lo(dword_F013DEEC)], %o0
F00A045C: 80a22000                 cmp     %o0, 0
F00A0460: 1280000b                 bne     loc_F00A048C
F00A0464: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0468: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A046C: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A0470: 80a22000                 cmp     %o0, 0
F00A0474: 02800005                 be      loc_F00A0488
F00A0478: 113c0461                 sethi   %hi(aPmapChangeWiri_0), %o0! "pmap_change_wiring \t=\t%d\n"
F00A047C: 90122290                 bset    %lo(aPmapChangeWiri_0), %o0! "pmap_change_wiring \t=\t%d\n"
F00A0480: 1080000c                 ba      loc_F00A04B0
F00A0484: 92102000                 mov     0, %o1
F00A0488: 113c04f7                 sethi   -0xFEC2400, %o0
F00A048C: d20222ec                 ld      [%o0+0x2EC], %o1
F00A0490: 80a26000                 cmp     %o1, 0
F00A0494: 02800009                 be      loc_F00A04B8
F00A0498: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A049C: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A04A0: 80a22000                 cmp     %o0, 0
F00A04A4: 02800005                 be      loc_F00A04B8
F00A04A8: 113c0461                 sethi   %hi(aPmapChangeWiri_1), %o0! "pmap_change_wiring \t=\t%d\n"
F00A04AC: 901222b0                 bset    %lo(aPmapChangeWiri_1), %o0! "pmap_change_wiring \t=\t%d\n"
F00A04B0: 7ffdd06a                 call    _printf
F00A04B4: 01000000                 nop
F00A04B8: 113c04f7                 sethi   %hi(dword_F013DEF0), %o0
F00A04BC: d00222f0                 ld      [%o0+%lo(dword_F013DEF0)], %o0
F00A04C0: 80a22000                 cmp     %o0, 0
F00A04C4: 1280000b                 bne     loc_F00A04F0
F00A04C8: 113c04f7                 sethi   -0xFEC2400, %o0
F00A04CC: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A04D0: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A04D4: 80a22000                 cmp     %o0, 0
F00A04D8: 02800005                 be      loc_F00A04EC
F00A04DC: 113c0461                 sethi   %hi(aPmapResidentEx), %o0! "pmap_resident_extract \t=\t%d\n"
F00A04E0: 901222d0                 bset    %lo(aPmapResidentEx), %o0! "pmap_resident_extract \t=\t%d\n"
F00A04E4: 1080000c                 ba      loc_F00A0514
F00A04E8: 92102000                 mov     0, %o1
F00A04EC: 113c04f7                 sethi   -0xFEC2400, %o0
F00A04F0: d20222f0                 ld      [%o0+0x2F0], %o1
F00A04F4: 80a26000                 cmp     %o1, 0
F00A04F8: 02800009                 be      loc_F00A051C
F00A04FC: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A0500: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A0504: 80a22000                 cmp     %o0, 0
F00A0508: 02800005                 be      loc_F00A051C
F00A050C: 113c0461                 sethi   %hi(aPmapResidentEx_0), %o0! "pmap_resident_extract \t=\t%d\n"
F00A0510: 901222f0                 bset    %lo(aPmapResidentEx_0), %o0! "pmap_resident_extract \t=\t%d\n"
F00A0514: 7ffdd051                 call    _printf
F00A0518: 01000000                 nop
F00A051C: 113c04f7                 sethi   %hi(dword_F013DEF4), %o0
F00A0520: d00222f4                 ld      [%o0+%lo(dword_F013DEF4)], %o0
F00A0524: 80a22000                 cmp     %o0, 0
F00A0528: 1280000b                 bne     loc_F00A0554
F00A052C: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0530: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A0534: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A0538: 80a22000                 cmp     %o0, 0
F00A053C: 02800005                 be      loc_F00A0550
F00A0540: 113c0461                 sethi   %hi(aPmapExtractD), %o0! "pmap_extract \t=\t%d\n"
F00A0544: 90122310                 bset    %lo(aPmapExtractD), %o0! "pmap_extract \t=\t%d\n"
F00A0548: 1080000c                 ba      loc_F00A0578
F00A054C: 92102000                 mov     0, %o1
F00A0550: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0554: d20222f4                 ld      [%o0+0x2F4], %o1
F00A0558: 80a26000                 cmp     %o1, 0
F00A055C: 02800009                 be      loc_F00A0580
F00A0560: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A0564: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A0568: 80a22000                 cmp     %o0, 0
F00A056C: 02800005                 be      loc_F00A0580
F00A0570: 113c0461                 sethi   %hi(aPmapExtractD_0), %o0! "pmap_extract \t=\t%d\n"
F00A0574: 90122328                 bset    %lo(aPmapExtractD_0), %o0! "pmap_extract \t=\t%d\n"
F00A0578: 7ffdd038                 call    _printf
F00A057C: 01000000                 nop
F00A0580: 113c04f7                 sethi   %hi(dword_F013DEF8), %o0
F00A0584: d00222f8                 ld      [%o0+%lo(dword_F013DEF8)], %o0
F00A0588: 80a22000                 cmp     %o0, 0
F00A058C: 1280000b                 bne     loc_F00A05B8
F00A0590: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0594: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A0598: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A059C: 80a22000                 cmp     %o0, 0
F00A05A0: 02800005                 be      loc_F00A05B4
F00A05A4: 113c0461                 sethi   %hi(aPmapClearPageA), %o0! "pmap_clear_page_attrib \t=\t%d\n"
F00A05A8: 90122340                 bset    %lo(aPmapClearPageA), %o0! "pmap_clear_page_attrib \t=\t%d\n"
F00A05AC: 1080000c                 ba      loc_F00A05DC
F00A05B0: 92102000                 mov     0, %o1
F00A05B4: 113c04f7                 sethi   -0xFEC2400, %o0
F00A05B8: d20222f8                 ld      [%o0+0x2F8], %o1
F00A05BC: 80a26000                 cmp     %o1, 0
F00A05C0: 02800009                 be      loc_F00A05E4
F00A05C4: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A05C8: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A05CC: 80a22000                 cmp     %o0, 0
F00A05D0: 02800005                 be      loc_F00A05E4
F00A05D4: 113c0461                 sethi   %hi(aPmapClearPageA_0), %o0! "pmap_clear_page_attrib \t=\t%d\n"
F00A05D8: 90122360                 bset    %lo(aPmapClearPageA_0), %o0! "pmap_clear_page_attrib \t=\t%d\n"
F00A05DC: 7ffdd01f                 call    _printf
F00A05E0: 01000000                 nop
F00A05E4: 113c04f7                 sethi   %hi(dword_F013DEFC), %o0
F00A05E8: d00222fc                 ld      [%o0+%lo(dword_F013DEFC)], %o0
F00A05EC: 80a22000                 cmp     %o0, 0
F00A05F0: 1280000b                 bne     loc_F00A061C
F00A05F4: 113c04f7                 sethi   -0xFEC2400, %o0
F00A05F8: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A05FC: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A0600: 80a22000                 cmp     %o0, 0
F00A0604: 02800005                 be      loc_F00A0618
F00A0608: 113c0461                 sethi   %hi(aPmapCheckPageA_0), %o0! "pmap_check_page_attrib \t=\t%d\n"
F00A060C: 90122380                 bset    %lo(aPmapCheckPageA_0), %o0! "pmap_check_page_attrib \t=\t%d\n"
F00A0610: 1080000c                 ba      loc_F00A0640
F00A0614: 92102000                 mov     0, %o1
F00A0618: 113c04f7                 sethi   -0xFEC2400, %o0
F00A061C: d20222fc                 ld      [%o0+0x2FC], %o1
F00A0620: 80a26000                 cmp     %o1, 0
F00A0624: 02800009                 be      loc_F00A0648
F00A0628: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A062C: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A0630: 80a22000                 cmp     %o0, 0
F00A0634: 02800005                 be      loc_F00A0648
F00A0638: 113c0461                 sethi   %hi(aPmapCheckPageA_1), %o0! "pmap_check_page_attrib \t=\t%d\n"
F00A063C: 901223a0                 bset    %lo(aPmapCheckPageA_1), %o0! "pmap_check_page_attrib \t=\t%d\n"
F00A0640: 7ffdd006                 call    _printf
F00A0644: 01000000                 nop
F00A0648: 113c04f7                 sethi   %hi(dword_F013DF00), %o0
F00A064C: d0022300                 ld      [%o0+%lo(dword_F013DF00)], %o0
F00A0650: 80a22000                 cmp     %o0, 0
F00A0654: 1280000b                 bne     loc_F00A0680
F00A0658: 113c04f7                 sethi   -0xFEC2400, %o0
F00A065C: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A0660: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A0664: 80a22000                 cmp     %o0, 0
F00A0668: 02800005                 be      loc_F00A067C
F00A066C: 113c0461                 sethi   %hi(aPmapCollectD), %o0! "pmap_collect \t=\t%d\n"
F00A0670: 901223c0                 bset    %lo(aPmapCollectD), %o0! "pmap_collect \t=\t%d\n"
F00A0674: 1080000c                 ba      loc_F00A06A4
F00A0678: 92102000                 mov     0, %o1
F00A067C: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0680: d2022300                 ld      [%o0+0x300], %o1
F00A0684: 80a26000                 cmp     %o1, 0
F00A0688: 02800009                 be      loc_F00A06AC
F00A068C: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A0690: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A0694: 80a22000                 cmp     %o0, 0
F00A0698: 02800005                 be      loc_F00A06AC
F00A069C: 113c0461                 sethi   %hi(aPmapCollectD_0), %o0! "pmap_collect \t=\t%d\n"
F00A06A0: 901223d8                 bset    %lo(aPmapCollectD_0), %o0! "pmap_collect \t=\t%d\n"
F00A06A4: 7ffdcfed                 call    _printf
F00A06A8: 01000000                 nop
F00A06AC: 113c04f7                 sethi   %hi(dword_F013DF04), %o0
F00A06B0: d0022304                 ld      [%o0+%lo(dword_F013DF04)], %o0
F00A06B4: 80a22000                 cmp     %o0, 0
F00A06B8: 1280000b                 bne     loc_F00A06E4
F00A06BC: 113c04f7                 sethi   -0xFEC2400, %o0
F00A06C0: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A06C4: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A06C8: 80a22000                 cmp     %o0, 0
F00A06CC: 02800005                 be      loc_F00A06E0
F00A06D0: 113c0461                 sethi   %hi(aPmapActivateD), %o0! "pmap_activate \t=\t%d\n"
F00A06D4: 901223f0                 bset    %lo(aPmapActivateD), %o0! "pmap_activate \t=\t%d\n"
F00A06D8: 1080000c                 ba      loc_F00A0708
F00A06DC: 92102000                 mov     0, %o1
F00A06E0: 113c04f7                 sethi   -0xFEC2400, %o0
F00A06E4: d2022304                 ld      [%o0+0x304], %o1
F00A06E8: 80a26000                 cmp     %o1, 0
F00A06EC: 02800009                 be      loc_F00A0710
F00A06F0: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A06F4: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A06F8: 80a22000                 cmp     %o0, 0
F00A06FC: 02800005                 be      loc_F00A0710
F00A0700: 113c0462                 sethi   %hi(aPmapActivateD_0), %o0! "pmap_activate \t=\t%d\n"
F00A0704: 90122008                 bset    %lo(aPmapActivateD_0), %o0! "pmap_activate \t=\t%d\n"
F00A0708: 7ffdcfd4                 call    _printf
F00A070C: 01000000                 nop
F00A0710: 113c0463                 sethi   %hi(_pmap_opt_info), %o0
F00A0714: d0022184                 ld      [%o0+%lo(_pmap_opt_info)], %o0
F00A0718: 80a22000                 cmp     %o0, 0
F00A071C: 0280000b                 be      loc_F00A0748
F00A0720: 113c0462                 sethi   %hi(aPmapActivateD_1), %o0! "pmap_activate \t=\t%d\n"
F00A0724: 213c04f7                 sethi   %hi(dword_F013DF04), %l0
F00A0728: d2042304                 ld      [%l0+%lo(dword_F013DF04)], %o1
F00A072C: 90122020                 bset    %lo(aPmapActivateD_1), %o0! "pmap_activate \t=\t%d\n"
F00A0730: 7ffdcfca                 call    _printf
F00A0734: a0142304                 bset    %lo(dword_F013DF04), %l0
F00A0738: 113c0462                 sethi   %hi(aPmapActivateAc), %o0! "pmap_activate_act \t=\t%d\n"
F00A073C: d2042004                 ld      [%l0+4], %o1
F00A0740: 7ffdcfc6                 call    _printf
F00A0744: 90122038                 bset    %lo(aPmapActivateAc), %o0! "pmap_activate_act \t=\t%d\n"
F00A0748: 113c04f7                 sethi   %hi(dword_F013DF0C), %o0
F00A074C: d002230c                 ld      [%o0+%lo(dword_F013DF0C)], %o0
F00A0750: 80a22000                 cmp     %o0, 0
F00A0754: 1280000b                 bne     loc_F00A0780
F00A0758: 113c04f7                 sethi   -0xFEC2400, %o0
F00A075C: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A0760: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A0764: 80a22000                 cmp     %o0, 0
F00A0768: 02800005                 be      loc_F00A077C
F00A076C: 113c0462                 sethi   %hi(aPmapDeactivate), %o0! "pmap_deactivate \t=\t%d\n"
F00A0770: 90122058                 bset    %lo(aPmapDeactivate), %o0! "pmap_deactivate \t=\t%d\n"
F00A0774: 1080000c                 ba      loc_F00A07A4
F00A0778: 92102000                 mov     0, %o1
F00A077C: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0780: d202230c                 ld      [%o0+0x30C], %o1
F00A0784: 80a26000                 cmp     %o1, 0
F00A0788: 02800009                 be      loc_F00A07AC
F00A078C: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A0790: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A0794: 80a22000                 cmp     %o0, 0
F00A0798: 02800005                 be      loc_F00A07AC
F00A079C: 113c0462                 sethi   %hi(aPmapDeactivate_0), %o0! "pmap_deactivate \t=\t%d\n"
F00A07A0: 90122070                 bset    %lo(aPmapDeactivate_0), %o0! "pmap_deactivate \t=\t%d\n"
F00A07A4: 7ffdcfad                 call    _printf
F00A07A8: 01000000                 nop
F00A07AC: 113c04f7                 sethi   %hi(dword_F013DF10), %o0
F00A07B0: d0022310                 ld      [%o0+%lo(dword_F013DF10)], %o0
F00A07B4: 80a22000                 cmp     %o0, 0
F00A07B8: 1280000b                 bne     loc_F00A07E4
F00A07BC: 113c04f7                 sethi   -0xFEC2400, %o0
F00A07C0: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A07C4: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A07C8: 80a22000                 cmp     %o0, 0
F00A07CC: 02800005                 be      loc_F00A07E0
F00A07D0: 113c0462                 sethi   %hi(aPmapKernelD), %o0! "pmap_kernel \t=\t%d\n"
F00A07D4: 90122088                 bset    %lo(aPmapKernelD), %o0! "pmap_kernel \t=\t%d\n"
F00A07D8: 1080000c                 ba      loc_F00A0808
F00A07DC: 92102000                 mov     0, %o1
F00A07E0: 113c04f7                 sethi   -0xFEC2400, %o0
F00A07E4: d2022310                 ld      [%o0+0x310], %o1
F00A07E8: 80a26000                 cmp     %o1, 0
F00A07EC: 02800009                 be      loc_F00A0810
F00A07F0: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A07F4: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A07F8: 80a22000                 cmp     %o0, 0
F00A07FC: 02800005                 be      loc_F00A0810
F00A0800: 113c0462                 sethi   %hi(aPmapKernelD_0), %o0! "pmap_kernel \t=\t%d\n"
F00A0804: 901220a0                 bset    %lo(aPmapKernelD_0), %o0! "pmap_kernel \t=\t%d\n"
F00A0808: 7ffdcf94                 call    _printf
F00A080C: 01000000                 nop
F00A0810: 113c04f7                 sethi   %hi(dword_F013DF14), %o0
F00A0814: d0022314                 ld      [%o0+%lo(dword_F013DF14)], %o0
F00A0818: 80a22000                 cmp     %o0, 0
F00A081C: 1280000b                 bne     loc_F00A0848
F00A0820: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0824: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A0828: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A082C: 80a22000                 cmp     %o0, 0
F00A0830: 02800005                 be      loc_F00A0844
F00A0834: 113c0462                 sethi   %hi(aPmapZeroPageD), %o0! "pmap_zero_page \t=\t%d\n"
F00A0838: 901220b8                 bset    %lo(aPmapZeroPageD), %o0! "pmap_zero_page \t=\t%d\n"
F00A083C: 1080000c                 ba      loc_F00A086C
F00A0840: 92102000                 mov     0, %o1
F00A0844: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0848: d2022314                 ld      [%o0+0x314], %o1
F00A084C: 80a26000                 cmp     %o1, 0
F00A0850: 02800009                 be      loc_F00A0874
F00A0854: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A0858: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A085C: 80a22000                 cmp     %o0, 0
F00A0860: 02800005                 be      loc_F00A0874
F00A0864: 113c0462                 sethi   %hi(aPmapZeroPageD_0), %o0! "pmap_zero_page \t=\t%d\n"
F00A0868: 901220d0                 bset    %lo(aPmapZeroPageD_0), %o0! "pmap_zero_page \t=\t%d\n"
F00A086C: 7ffdcf7b                 call    _printf
F00A0870: 01000000                 nop
F00A0874: 113c04f7                 sethi   %hi(dword_F013DF18), %o0
F00A0878: d0022318                 ld      [%o0+%lo(dword_F013DF18)], %o0
F00A087C: 80a22000                 cmp     %o0, 0
F00A0880: 1280000b                 bne     loc_F00A08AC
F00A0884: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0888: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A088C: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A0890: 80a22000                 cmp     %o0, 0
F00A0894: 02800005                 be      loc_F00A08A8
F00A0898: 113c0462                 sethi   %hi(aPmapCopyPageD), %o0! "pmap_copy_page \t=\t%d\n"
F00A089C: 901220e8                 bset    %lo(aPmapCopyPageD), %o0! "pmap_copy_page \t=\t%d\n"
F00A08A0: 1080000c                 ba      loc_F00A08D0
F00A08A4: 92102000                 mov     0, %o1
F00A08A8: 113c04f7                 sethi   -0xFEC2400, %o0
F00A08AC: d2022318                 ld      [%o0+0x318], %o1
F00A08B0: 80a26000                 cmp     %o1, 0
F00A08B4: 02800009                 be      loc_F00A08D8
F00A08B8: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A08BC: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A08C0: 80a22000                 cmp     %o0, 0
F00A08C4: 02800005                 be      loc_F00A08D8
F00A08C8: 113c0462                 sethi   %hi(aPmapCopyPageD_0), %o0! "pmap_copy_page \t=\t%d\n"
F00A08CC: 90122100                 bset    %lo(aPmapCopyPageD_0), %o0! "pmap_copy_page \t=\t%d\n"
F00A08D0: 7ffdcf62                 call    _printf
F00A08D4: 01000000                 nop
F00A08D8: 113c04f7                 sethi   %hi(dword_F013DF1C), %o0
F00A08DC: d002231c                 ld      [%o0+%lo(dword_F013DF1C)], %o0
F00A08E0: 80a22000                 cmp     %o0, 0
F00A08E4: 1280000b                 bne     loc_F00A0910
F00A08E8: 113c04f7                 sethi   -0xFEC2400, %o0
F00A08EC: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A08F0: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A08F4: 80a22000                 cmp     %o0, 0
F00A08F8: 02800005                 be      loc_F00A090C
F00A08FC: 113c0462                 sethi   %hi(aCopyToPhysD), %o0! "copy_to_phys \t=\t%d\n"
F00A0900: 90122118                 bset    %lo(aCopyToPhysD), %o0! "copy_to_phys \t=\t%d\n"
F00A0904: 1080000c                 ba      loc_F00A0934
F00A0908: 92102000                 mov     0, %o1
F00A090C: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0910: d202231c                 ld      [%o0+0x31C], %o1
F00A0914: 80a26000                 cmp     %o1, 0
F00A0918: 02800009                 be      loc_F00A093C
F00A091C: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A0920: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A0924: 80a22000                 cmp     %o0, 0
F00A0928: 02800005                 be      loc_F00A093C
F00A092C: 113c0462                 sethi   %hi(aCopyToPhysD_0), %o0! "copy_to_phys \t=\t%d\n"
F00A0930: 90122130                 bset    %lo(aCopyToPhysD_0), %o0! "copy_to_phys \t=\t%d\n"
F00A0934: 7ffdcf49                 call    _printf
F00A0938: 01000000                 nop
F00A093C: 113c04f7                 sethi   %hi(dword_F013DF20), %o0
F00A0940: d0022320                 ld      [%o0+%lo(dword_F013DF20)], %o0
F00A0944: 80a22000                 cmp     %o0, 0
F00A0948: 1280000b                 bne     loc_F00A0974
F00A094C: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0950: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A0954: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A0958: 80a22000                 cmp     %o0, 0
F00A095C: 02800005                 be      loc_F00A0970
F00A0960: 113c0462                 sethi   %hi(aCopyFromPhysD), %o0! "copy_from_phys \t=\t%d\n"
F00A0964: 90122148                 bset    %lo(aCopyFromPhysD), %o0! "copy_from_phys \t=\t%d\n"
F00A0968: 1080000c                 ba      loc_F00A0998
F00A096C: 92102000                 mov     0, %o1
F00A0970: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0974: d2022320                 ld      [%o0+0x320], %o1
F00A0978: 80a26000                 cmp     %o1, 0
F00A097C: 02800009                 be      loc_F00A09A0
F00A0980: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A0984: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A0988: 80a22000                 cmp     %o0, 0
F00A098C: 02800005                 be      loc_F00A09A0
F00A0990: 113c0462                 sethi   %hi(aCopyFromPhysD_0), %o0! "copy_from_phys \t=\t%d\n"
F00A0994: 90122160                 bset    %lo(aCopyFromPhysD_0), %o0! "copy_from_phys \t=\t%d\n"
F00A0998: 7ffdcf30                 call    _printf
F00A099C: 01000000                 nop
F00A09A0: 113c04f7                 sethi   %hi(dword_F013DF24), %o0
F00A09A4: d0022324                 ld      [%o0+%lo(dword_F013DF24)], %o0
F00A09A8: 80a22000                 cmp     %o0, 0
F00A09AC: 1280000b                 bne     loc_F00A09D8
F00A09B0: 113c04f7                 sethi   -0xFEC2400, %o0
F00A09B4: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A09B8: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A09BC: 80a22000                 cmp     %o0, 0
F00A09C0: 02800005                 be      loc_F00A09D4
F00A09C4: 113c0462                 sethi   %hi(aAddPoolD), %o0! "add_pool \t=\t%d\n"
F00A09C8: 90122178                 bset    %lo(aAddPoolD), %o0! "add_pool \t=\t%d\n"
F00A09CC: 1080000c                 ba      loc_F00A09FC
F00A09D0: 92102000                 mov     0, %o1
F00A09D4: 113c04f7                 sethi   -0xFEC2400, %o0
F00A09D8: d2022324                 ld      [%o0+0x324], %o1
F00A09DC: 80a26000                 cmp     %o1, 0
F00A09E0: 02800009                 be      loc_F00A0A04
F00A09E4: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A09E8: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A09EC: 80a22000                 cmp     %o0, 0
F00A09F0: 02800005                 be      loc_F00A0A04
F00A09F4: 113c0462                 sethi   %hi(aAddPoolD_0), %o0! "add_pool \t=\t%d\n"
F00A09F8: 90122188                 bset    %lo(aAddPoolD_0), %o0! "add_pool \t=\t%d\n"
F00A09FC: 7ffdcf17                 call    _printf
F00A0A00: 01000000                 nop
F00A0A04: 113c04f7                 sethi   %hi(dword_F013DF28), %o0
F00A0A08: d0022328                 ld      [%o0+%lo(dword_F013DF28)], %o0
F00A0A0C: 80a22000                 cmp     %o0, 0
F00A0A10: 1280000b                 bne     loc_F00A0A3C
F00A0A14: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0A18: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A0A1C: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A0A20: 80a22000                 cmp     %o0, 0
F00A0A24: 02800005                 be      loc_F00A0A38
F00A0A28: 113c0462                 sethi   %hi(aDelFirstPoolD), %o0! "del_first_pool \t=\t%d\n"
F00A0A2C: 90122198                 bset    %lo(aDelFirstPoolD), %o0! "del_first_pool \t=\t%d\n"
F00A0A30: 1080000c                 ba      loc_F00A0A60
F00A0A34: 92102000                 mov     0, %o1
F00A0A38: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0A3C: d2022328                 ld      [%o0+0x328], %o1
F00A0A40: 80a26000                 cmp     %o1, 0
F00A0A44: 02800009                 be      loc_F00A0A68
F00A0A48: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A0A4C: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A0A50: 80a22000                 cmp     %o0, 0
F00A0A54: 02800005                 be      loc_F00A0A68
F00A0A58: 113c0462                 sethi   %hi(aDelFirstPoolD_0), %o0! "del_first_pool \t=\t%d\n"
F00A0A5C: 901221b0                 bset    %lo(aDelFirstPoolD_0), %o0! "del_first_pool \t=\t%d\n"
F00A0A60: 7ffdcefe                 call    _printf
F00A0A64: 01000000                 nop
F00A0A68: 113c04f7                 sethi   %hi(dword_F013DF2C), %o0
F00A0A6C: d002232c                 ld      [%o0+%lo(dword_F013DF2C)], %o0
F00A0A70: 80a22000                 cmp     %o0, 0
F00A0A74: 1280000b                 bne     loc_F00A0AA0
F00A0A78: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0A7C: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A0A80: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A0A84: 80a22000                 cmp     %o0, 0
F00A0A88: 02800005                 be      loc_F00A0A9C
F00A0A8C: 113c0462                 sethi   %hi(aDelAnyPoolD), %o0! "del_any_pool \t=\t%d\n"
F00A0A90: 901221c8                 bset    %lo(aDelAnyPoolD), %o0! "del_any_pool \t=\t%d\n"
F00A0A94: 1080000c                 ba      loc_F00A0AC4
F00A0A98: 92102000                 mov     0, %o1
F00A0A9C: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0AA0: d202232c                 ld      [%o0+0x32C], %o1
F00A0AA4: 80a26000                 cmp     %o1, 0
F00A0AA8: 02800009                 be      loc_F00A0ACC
F00A0AAC: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A0AB0: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A0AB4: 80a22000                 cmp     %o0, 0
F00A0AB8: 02800005                 be      loc_F00A0ACC
F00A0ABC: 113c0462                 sethi   %hi(aDelAnyPoolD_0), %o0! "del_any_pool \t=\t%d\n"
F00A0AC0: 901221e0                 bset    %lo(aDelAnyPoolD_0), %o0! "del_any_pool \t=\t%d\n"
F00A0AC4: 7ffdcee5                 call    _printf
F00A0AC8: 01000000                 nop
F00A0ACC: 113c04f7                 sethi   %hi(dword_F013DF30), %o0
F00A0AD0: d0022330                 ld      [%o0+%lo(dword_F013DF30)], %o0
F00A0AD4: 80a22000                 cmp     %o0, 0
F00A0AD8: 1280000b                 bne     loc_F00A0B04
F00A0ADC: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0AE0: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A0AE4: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A0AE8: 80a22000                 cmp     %o0, 0
F00A0AEC: 02800005                 be      loc_F00A0B00
F00A0AF0: 113c0462                 sethi   %hi(aVmToSrmmuProtD), %o0! "vm_to_srmmu_prot \t=\t%d\n"
F00A0AF4: 901221f8                 bset    %lo(aVmToSrmmuProtD), %o0! "vm_to_srmmu_prot \t=\t%d\n"
F00A0AF8: 1080000c                 ba      loc_F00A0B28
F00A0AFC: 92102000                 mov     0, %o1
F00A0B00: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0B04: d2022330                 ld      [%o0+0x330], %o1
F00A0B08: 80a26000                 cmp     %o1, 0
F00A0B0C: 02800009                 be      loc_F00A0B30
F00A0B10: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A0B14: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A0B18: 80a22000                 cmp     %o0, 0
F00A0B1C: 02800005                 be      loc_F00A0B30
F00A0B20: 113c0462                 sethi   %hi(aVmToSrmmuProtD_0), %o0! "vm_to_srmmu_prot \t=\t%d\n"
F00A0B24: 90122210                 bset    %lo(aVmToSrmmuProtD_0), %o0! "vm_to_srmmu_prot \t=\t%d\n"
F00A0B28: 7ffdcecc                 call    _printf
F00A0B2C: 01000000                 nop
F00A0B30: 113c04f7                 sethi   %hi(dword_F013DF34), %o0
F00A0B34: d0022334                 ld      [%o0+%lo(dword_F013DF34)], %o0
F00A0B38: 80a22000                 cmp     %o0, 0
F00A0B3C: 1280000b                 bne     loc_F00A0B68
F00A0B40: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0B44: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A0B48: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A0B4C: 80a22000                 cmp     %o0, 0
F00A0B50: 02800005                 be      loc_F00A0B64
F00A0B54: 113c0462                 sethi   %hi(aSrmmuToVmProtD), %o0! "srmmu_to_vm_prot \t=\t%d\n"
F00A0B58: 90122228                 bset    %lo(aSrmmuToVmProtD), %o0! "srmmu_to_vm_prot \t=\t%d\n"
F00A0B5C: 1080000c                 ba      loc_F00A0B8C
F00A0B60: 92102000                 mov     0, %o1
F00A0B64: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0B68: d2022334                 ld      [%o0+0x334], %o1
F00A0B6C: 80a26000                 cmp     %o1, 0
F00A0B70: 02800009                 be      loc_F00A0B94
F00A0B74: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A0B78: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A0B7C: 80a22000                 cmp     %o0, 0
F00A0B80: 02800005                 be      loc_F00A0B94
F00A0B84: 113c0462                 sethi   %hi(aSrmmuToVmProtD_0), %o0! "srmmu_to_vm_prot \t=\t%d\n"
F00A0B88: 90122240                 bset    %lo(aSrmmuToVmProtD_0), %o0! "srmmu_to_vm_prot \t=\t%d\n"
F00A0B8C: 7ffdceb3                 call    _printf
F00A0B90: 01000000                 nop
F00A0B94: 113c04f7                 sethi   %hi(dword_F013DF38), %o0
F00A0B98: d0022338                 ld      [%o0+%lo(dword_F013DF38)], %o0
F00A0B9C: 80a22000                 cmp     %o0, 0
F00A0BA0: 1280000b                 bne     loc_F00A0BCC
F00A0BA4: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0BA8: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A0BAC: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A0BB0: 80a22000                 cmp     %o0, 0
F00A0BB4: 02800005                 be      loc_F00A0BC8
F00A0BB8: 113c0462                 sethi   %hi(aSetInvalidpteD), %o0! "set_invalidpte \t=\t%d\n"
F00A0BBC: 90122258                 bset    %lo(aSetInvalidpteD), %o0! "set_invalidpte \t=\t%d\n"
F00A0BC0: 1080000c                 ba      loc_F00A0BF0
F00A0BC4: 92102000                 mov     0, %o1
F00A0BC8: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0BCC: d2022338                 ld      [%o0+0x338], %o1
F00A0BD0: 80a26000                 cmp     %o1, 0
F00A0BD4: 02800009                 be      loc_F00A0BF8
F00A0BD8: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A0BDC: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A0BE0: 80a22000                 cmp     %o0, 0
F00A0BE4: 02800005                 be      loc_F00A0BF8
F00A0BE8: 113c0462                 sethi   %hi(aSetInvalidpteD_0), %o0! "set_invalidpte \t=\t%d\n"
F00A0BEC: 90122270                 bset    %lo(aSetInvalidpteD_0), %o0! "set_invalidpte \t=\t%d\n"
F00A0BF0: 7ffdce9a                 call    _printf
F00A0BF4: 01000000                 nop
F00A0BF8: 113c04f7                 sethi   %hi(dword_F013DF3C), %o0
F00A0BFC: d002233c                 ld      [%o0+%lo(dword_F013DF3C)], %o0
F00A0C00: 80a22000                 cmp     %o0, 0
F00A0C04: 1280000b                 bne     loc_F00A0C30
F00A0C08: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0C0C: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A0C10: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A0C14: 80a22000                 cmp     %o0, 0
F00A0C18: 02800005                 be      loc_F00A0C2C
F00A0C1C: 113c0462                 sethi   %hi(aUpdatePteD), %o0! "update_pte \t=\t%d\n"
F00A0C20: 90122288                 bset    %lo(aUpdatePteD), %o0! "update_pte \t=\t%d\n"
F00A0C24: 1080000c                 ba      loc_F00A0C54
F00A0C28: 92102000                 mov     0, %o1
F00A0C2C: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0C30: d202233c                 ld      [%o0+0x33C], %o1
F00A0C34: 80a26000                 cmp     %o1, 0
F00A0C38: 02800009                 be      loc_F00A0C5C
F00A0C3C: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A0C40: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A0C44: 80a22000                 cmp     %o0, 0
F00A0C48: 02800005                 be      loc_F00A0C5C
F00A0C4C: 113c0462                 sethi   %hi(aUpdatePteD_0), %o0! "update_pte \t=\t%d\n"
F00A0C50: 901222a0                 bset    %lo(aUpdatePteD_0), %o0! "update_pte \t=\t%d\n"
F00A0C54: 7ffdce81                 call    _printf
F00A0C58: 01000000                 nop
F00A0C5C: 113c04f7                 sethi   %hi(dword_F013DF40), %o0
F00A0C60: d0022340                 ld      [%o0+%lo(dword_F013DF40)], %o0
F00A0C64: 80a22000                 cmp     %o0, 0
F00A0C68: 1280000b                 bne     loc_F00A0C94
F00A0C6C: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0C70: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A0C74: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A0C78: 80a22000                 cmp     %o0, 0
F00A0C7C: 02800005                 be      loc_F00A0C90
F00A0C80: 113c0462                 sethi   %hi(aSetPteD), %o0! "set_pte \t=\t%d\n"
F00A0C84: 901222b8                 bset    %lo(aSetPteD), %o0! "set_pte \t=\t%d\n"
F00A0C88: 1080000c                 ba      loc_F00A0CB8
F00A0C8C: 92102000                 mov     0, %o1
F00A0C90: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0C94: d2022340                 ld      [%o0+0x340], %o1
F00A0C98: 80a26000                 cmp     %o1, 0
F00A0C9C: 02800009                 be      loc_F00A0CC0
F00A0CA0: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A0CA4: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A0CA8: 80a22000                 cmp     %o0, 0
F00A0CAC: 02800005                 be      loc_F00A0CC0
F00A0CB0: 113c0462                 sethi   %hi(aSetPteD_0), %o0! "set_pte \t=\t%d\n"
F00A0CB4: 901222c8                 bset    %lo(aSetPteD_0), %o0! "set_pte \t=\t%d\n"
F00A0CB8: 7ffdce68                 call    _printf
F00A0CBC: 01000000                 nop
F00A0CC0: 113c04f7                 sethi   %hi(dword_F013DF44), %o0
F00A0CC4: d0022344                 ld      [%o0+%lo(dword_F013DF44)], %o0
F00A0CC8: 80a22000                 cmp     %o0, 0
F00A0CCC: 1280000b                 bne     loc_F00A0CF8
F00A0CD0: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0CD4: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A0CD8: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A0CDC: 80a22000                 cmp     %o0, 0
F00A0CE0: 02800005                 be      loc_F00A0CF4
F00A0CE4: 113c0462                 sethi   %hi(aSetPteModrefD), %o0! "set_pte_modref \t=\t%d\n"
F00A0CE8: 901222d8                 bset    %lo(aSetPteModrefD), %o0! "set_pte_modref \t=\t%d\n"
F00A0CEC: 1080000c                 ba      loc_F00A0D1C
F00A0CF0: 92102000                 mov     0, %o1
F00A0CF4: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0CF8: d2022344                 ld      [%o0+0x344], %o1
F00A0CFC: 80a26000                 cmp     %o1, 0
F00A0D00: 02800009                 be      loc_F00A0D24
F00A0D04: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A0D08: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A0D0C: 80a22000                 cmp     %o0, 0
F00A0D10: 02800005                 be      loc_F00A0D24
F00A0D14: 113c0462                 sethi   %hi(aSetPteModrefD_0), %o0! "set_pte_modref \t=\t%d\n"
F00A0D18: 901222f0                 bset    %lo(aSetPteModrefD_0), %o0! "set_pte_modref \t=\t%d\n"
F00A0D1C: 7ffdce4f                 call    _printf
F00A0D20: 01000000                 nop
F00A0D24: 113c04f7                 sethi   %hi(dword_F013DF48), %o0
F00A0D28: d0022348                 ld      [%o0+%lo(dword_F013DF48)], %o0
F00A0D2C: 80a22000                 cmp     %o0, 0
F00A0D30: 1280000b                 bne     loc_F00A0D5C
F00A0D34: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0D38: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A0D3C: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A0D40: 80a22000                 cmp     %o0, 0
F00A0D44: 02800005                 be      loc_F00A0D58
F00A0D48: 113c0462                 sethi   %hi(aSetPtpD), %o0! "set_ptp \t=\t%d\n"
F00A0D4C: 90122308                 bset    %lo(aSetPtpD), %o0! "set_ptp \t=\t%d\n"
F00A0D50: 1080000c                 ba      loc_F00A0D80
F00A0D54: 92102000                 mov     0, %o1
F00A0D58: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0D5C: d2022348                 ld      [%o0+0x348], %o1
F00A0D60: 80a26000                 cmp     %o1, 0
F00A0D64: 02800009                 be      loc_F00A0D88
F00A0D68: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A0D6C: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A0D70: 80a22000                 cmp     %o0, 0
F00A0D74: 02800005                 be      loc_F00A0D88
F00A0D78: 113c0462                 sethi   %hi(aSetPtpD_0), %o0! "set_ptp \t=\t%d\n"
F00A0D7C: 90122318                 bset    %lo(aSetPtpD_0), %o0! "set_ptp \t=\t%d\n"
F00A0D80: 7ffdce36                 call    _printf
F00A0D84: 01000000                 nop
F00A0D88: 113c04f7                 sethi   %hi(dword_F013DF4C), %o0
F00A0D8C: d002234c                 ld      [%o0+%lo(dword_F013DF4C)], %o0
F00A0D90: 80a22000                 cmp     %o0, 0
F00A0D94: 1280000b                 bne     loc_F00A0DC0
F00A0D98: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0D9C: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A0DA0: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A0DA4: 80a22000                 cmp     %o0, 0
F00A0DA8: 02800005                 be      loc_F00A0DBC
F00A0DAC: 113c0462                 sethi   %hi(aSetInvalidptpD), %o0! "set_invalidptp \t=\t%d\n"
F00A0DB0: 90122328                 bset    %lo(aSetInvalidptpD), %o0! "set_invalidptp \t=\t%d\n"
F00A0DB4: 1080000c                 ba      loc_F00A0DE4
F00A0DB8: 92102000                 mov     0, %o1
F00A0DBC: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0DC0: d202234c                 ld      [%o0+0x34C], %o1
F00A0DC4: 80a26000                 cmp     %o1, 0
F00A0DC8: 02800009                 be      loc_F00A0DEC
F00A0DCC: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A0DD0: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A0DD4: 80a22000                 cmp     %o0, 0
F00A0DD8: 02800005                 be      loc_F00A0DEC
F00A0DDC: 113c0462                 sethi   %hi(aSetInvalidptpD_0), %o0! "set_invalidptp \t=\t%d\n"
F00A0DE0: 90122340                 bset    %lo(aSetInvalidptpD_0), %o0! "set_invalidptp \t=\t%d\n"
F00A0DE4: 7ffdce1d                 call    _printf
F00A0DE8: 01000000                 nop
F00A0DEC: 113c04f7                 sethi   %hi(dword_F013DF50), %o0
F00A0DF0: d0022350                 ld      [%o0+%lo(dword_F013DF50)], %o0
F00A0DF4: 80a22000                 cmp     %o0, 0
F00A0DF8: 1280000b                 bne     loc_F00A0E24
F00A0DFC: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0E00: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A0E04: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A0E08: 80a22000                 cmp     %o0, 0
F00A0E0C: 02800005                 be      loc_F00A0E20
F00A0E10: 113c0462                 sethi   %hi(aPmapAllocRegEn), %o0! "pmap_alloc_reg_entry \t=\t%d\n"
F00A0E14: 90122358                 bset    %lo(aPmapAllocRegEn), %o0! "pmap_alloc_reg_entry \t=\t%d\n"
F00A0E18: 1080000c                 ba      loc_F00A0E48
F00A0E1C: 92102000                 mov     0, %o1
F00A0E20: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0E24: d2022350                 ld      [%o0+0x350], %o1
F00A0E28: 80a26000                 cmp     %o1, 0
F00A0E2C: 02800009                 be      loc_F00A0E50
F00A0E30: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A0E34: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A0E38: 80a22000                 cmp     %o0, 0
F00A0E3C: 02800005                 be      loc_F00A0E50
F00A0E40: 113c0462                 sethi   %hi(aPmapAllocRegEn_0), %o0! "pmap_alloc_reg_entry \t=\t%d\n"
F00A0E44: 90122378                 bset    %lo(aPmapAllocRegEn_0), %o0! "pmap_alloc_reg_entry \t=\t%d\n"
F00A0E48: 7ffdce04                 call    _printf
F00A0E4C: 01000000                 nop
F00A0E50: 113c04f7                 sethi   %hi(dword_F013DF54), %o0
F00A0E54: d0022354                 ld      [%o0+%lo(dword_F013DF54)], %o0
F00A0E58: 80a22000                 cmp     %o0, 0
F00A0E5C: 1280000b                 bne     loc_F00A0E88
F00A0E60: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0E64: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A0E68: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A0E6C: 80a22000                 cmp     %o0, 0
F00A0E70: 02800005                 be      loc_F00A0E84
F00A0E74: 113c0462                 sethi   %hi(aPmapDeallocReg), %o0! "pmap_dealloc_reg_entry \t=\t%d\n"
F00A0E78: 90122398                 bset    %lo(aPmapDeallocReg), %o0! "pmap_dealloc_reg_entry \t=\t%d\n"
F00A0E7C: 1080000c                 ba      loc_F00A0EAC
F00A0E80: 92102000                 mov     0, %o1
F00A0E84: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0E88: d2022354                 ld      [%o0+0x354], %o1
F00A0E8C: 80a26000                 cmp     %o1, 0
F00A0E90: 02800009                 be      loc_F00A0EB4
F00A0E94: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A0E98: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A0E9C: 80a22000                 cmp     %o0, 0
F00A0EA0: 02800005                 be      loc_F00A0EB4
F00A0EA4: 113c0462                 sethi   %hi(aPmapDeallocReg_0), %o0! "pmap_dealloc_reg_entry \t=\t%d\n"
F00A0EA8: 901223b8                 bset    %lo(aPmapDeallocReg_0), %o0! "pmap_dealloc_reg_entry \t=\t%d\n"
F00A0EAC: 7ffdcdeb                 call    _printf
F00A0EB0: 01000000                 nop
F00A0EB4: 113c04f7                 sethi   %hi(dword_F013DF58), %o0
F00A0EB8: d0022358                 ld      [%o0+%lo(dword_F013DF58)], %o0
F00A0EBC: 80a22000                 cmp     %o0, 0
F00A0EC0: 1280000b                 bne     loc_F00A0EEC
F00A0EC4: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0EC8: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A0ECC: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A0ED0: 80a22000                 cmp     %o0, 0
F00A0ED4: 02800005                 be      loc_F00A0EE8
F00A0ED8: 113c0462                 sethi   %hi(aPmapSegEntryD), %o0! "pmap_seg_entry \t=\t%d\n"
F00A0EDC: 901223d8                 bset    %lo(aPmapSegEntryD), %o0! "pmap_seg_entry \t=\t%d\n"
F00A0EE0: 1080000c                 ba      loc_F00A0F10
F00A0EE4: 92102000                 mov     0, %o1
F00A0EE8: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0EEC: d2022358                 ld      [%o0+0x358], %o1
F00A0EF0: 80a26000                 cmp     %o1, 0
F00A0EF4: 02800009                 be      loc_F00A0F18
F00A0EF8: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A0EFC: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A0F00: 80a22000                 cmp     %o0, 0
F00A0F04: 02800005                 be      loc_F00A0F18
F00A0F08: 113c0462                 sethi   %hi(aPmapSegEntryD_0), %o0! "pmap_seg_entry \t=\t%d\n"
F00A0F0C: 901223f0                 bset    %lo(aPmapSegEntryD_0), %o0! "pmap_seg_entry \t=\t%d\n"
F00A0F10: 7ffdcdd2                 call    _printf
F00A0F14: 01000000                 nop
F00A0F18: 113c04f7                 sethi   %hi(dword_F013DF5C), %o0
F00A0F1C: d002235c                 ld      [%o0+%lo(dword_F013DF5C)], %o0
F00A0F20: 80a22000                 cmp     %o0, 0
F00A0F24: 1280000b                 bne     loc_F00A0F50
F00A0F28: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0F2C: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A0F30: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A0F34: 80a22000                 cmp     %o0, 0
F00A0F38: 02800005                 be      loc_F00A0F4C
F00A0F3C: 113c0463                 sethi   %hi(aPmapAllocKsegE), %o0! "pmap_alloc_kseg_entry \t=\t%d\n"
F00A0F40: 90122008                 bset    %lo(aPmapAllocKsegE), %o0! "pmap_alloc_kseg_entry \t=\t%d\n"
F00A0F44: 1080000c                 ba      loc_F00A0F74
F00A0F48: 92102000                 mov     0, %o1
F00A0F4C: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0F50: d202235c                 ld      [%o0+0x35C], %o1
F00A0F54: 80a26000                 cmp     %o1, 0
F00A0F58: 02800009                 be      loc_F00A0F7C
F00A0F5C: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A0F60: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A0F64: 80a22000                 cmp     %o0, 0
F00A0F68: 02800005                 be      loc_F00A0F7C
F00A0F6C: 113c0463                 sethi   %hi(aPmapAllocKsegE_0), %o0! "pmap_alloc_kseg_entry \t=\t%d\n"
F00A0F70: 90122028                 bset    %lo(aPmapAllocKsegE_0), %o0! "pmap_alloc_kseg_entry \t=\t%d\n"
F00A0F74: 7ffdcdb9                 call    _printf
F00A0F78: 01000000                 nop
F00A0F7C: 113c04f7                 sethi   %hi(dword_F013DF60), %o0
F00A0F80: d0022360                 ld      [%o0+%lo(dword_F013DF60)], %o0
F00A0F84: 80a22000                 cmp     %o0, 0
F00A0F88: 1280000b                 bne     loc_F00A0FB4
F00A0F8C: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0F90: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A0F94: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A0F98: 80a22000                 cmp     %o0, 0
F00A0F9C: 02800005                 be      loc_F00A0FB0
F00A0FA0: 113c0463                 sethi   %hi(aPmapDeallocKse), %o0! "pmap_dealloc_kseg_entry \t=\t%d\n"
F00A0FA4: 90122048                 bset    %lo(aPmapDeallocKse), %o0! "pmap_dealloc_kseg_entry \t=\t%d\n"
F00A0FA8: 1080000c                 ba      loc_F00A0FD8
F00A0FAC: 92102000                 mov     0, %o1
F00A0FB0: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0FB4: d2022360                 ld      [%o0+0x360], %o1
F00A0FB8: 80a26000                 cmp     %o1, 0
F00A0FBC: 02800009                 be      loc_F00A0FE0
F00A0FC0: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A0FC4: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A0FC8: 80a22000                 cmp     %o0, 0
F00A0FCC: 02800005                 be      loc_F00A0FE0
F00A0FD0: 113c0463                 sethi   %hi(aPmapDeallocKse_0), %o0! "pmap_dealloc_kseg_entry \t=\t%d\n"
F00A0FD4: 90122068                 bset    %lo(aPmapDeallocKse_0), %o0! "pmap_dealloc_kseg_entry \t=\t%d\n"
F00A0FD8: 7ffdcda0                 call    _printf
F00A0FDC: 01000000                 nop
F00A0FE0: 113c04f7                 sethi   %hi(dword_F013DF64), %o0
F00A0FE4: d0022364                 ld      [%o0+%lo(dword_F013DF64)], %o0
F00A0FE8: 80a22000                 cmp     %o0, 0
F00A0FEC: 1280000b                 bne     loc_F00A1018
F00A0FF0: 113c04f7                 sethi   -0xFEC2400, %o0
F00A0FF4: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A0FF8: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A0FFC: 80a22000                 cmp     %o0, 0
F00A1000: 02800005                 be      loc_F00A1014
F00A1004: 113c0463                 sethi   %hi(aPmapAllocSegEn), %o0! "pmap_alloc_seg_entry \t=\t%d\n"
F00A1008: 90122088                 bset    %lo(aPmapAllocSegEn), %o0! "pmap_alloc_seg_entry \t=\t%d\n"
F00A100C: 1080000c                 ba      loc_F00A103C
F00A1010: 92102000                 mov     0, %o1
F00A1014: 113c04f7                 sethi   -0xFEC2400, %o0
F00A1018: d2022364                 ld      [%o0+0x364], %o1
F00A101C: 80a26000                 cmp     %o1, 0
F00A1020: 02800009                 be      loc_F00A1044
F00A1024: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A1028: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A102C: 80a22000                 cmp     %o0, 0
F00A1030: 02800005                 be      loc_F00A1044
F00A1034: 113c0463                 sethi   %hi(aPmapAllocSegEn_0), %o0! "pmap_alloc_seg_entry \t=\t%d\n"
F00A1038: 901220a8                 bset    %lo(aPmapAllocSegEn_0), %o0! "pmap_alloc_seg_entry \t=\t%d\n"
F00A103C: 7ffdcd87                 call    _printf
F00A1040: 01000000                 nop
F00A1044: 113c04f7                 sethi   %hi(dword_F013DF68), %o0
F00A1048: d0022368                 ld      [%o0+%lo(dword_F013DF68)], %o0
F00A104C: 80a22000                 cmp     %o0, 0
F00A1050: 1280000b                 bne     loc_F00A107C
F00A1054: 113c04f7                 sethi   -0xFEC2400, %o0
F00A1058: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A105C: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A1060: 80a22000                 cmp     %o0, 0
F00A1064: 02800005                 be      loc_F00A1078
F00A1068: 113c0463                 sethi   %hi(aPmapDeallocSeg), %o0! "pmap_dealloc_seg_entry \t=\t%d\n"
F00A106C: 901220c8                 bset    %lo(aPmapDeallocSeg), %o0! "pmap_dealloc_seg_entry \t=\t%d\n"
F00A1070: 1080000c                 ba      loc_F00A10A0
F00A1074: 92102000                 mov     0, %o1
F00A1078: 113c04f7                 sethi   -0xFEC2400, %o0
F00A107C: d2022368                 ld      [%o0+0x368], %o1
F00A1080: 80a26000                 cmp     %o1, 0
F00A1084: 02800009                 be      loc_F00A10A8
F00A1088: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A108C: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A1090: 80a22000                 cmp     %o0, 0
F00A1094: 02800005                 be      loc_F00A10A8
F00A1098: 113c0463                 sethi   %hi(aPmapDeallocSeg_0), %o0! "pmap_dealloc_seg_entry \t=\t%d\n"
F00A109C: 901220e8                 bset    %lo(aPmapDeallocSeg_0), %o0! "pmap_dealloc_seg_entry \t=\t%d\n"
F00A10A0: 7ffdcd6e                 call    _printf
F00A10A4: 01000000                 nop
F00A10A8: 113c04f7                 sethi   %hi(dword_F013DF6C), %o0
F00A10AC: d002236c                 ld      [%o0+%lo(dword_F013DF6C)], %o0
F00A10B0: 80a22000                 cmp     %o0, 0
F00A10B4: 1280000b                 bne     loc_F00A10E0
F00A10B8: 113c04f7                 sethi   -0xFEC2400, %o0
F00A10BC: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A10C0: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A10C4: 80a22000                 cmp     %o0, 0
F00A10C8: 02800005                 be      loc_F00A10DC
F00A10CC: 113c0463                 sethi   %hi(aPmapAllocConte), %o0! "pmap_alloc_context \t=\t%d\n"
F00A10D0: 90122108                 bset    %lo(aPmapAllocConte), %o0! "pmap_alloc_context \t=\t%d\n"
F00A10D4: 1080000c                 ba      loc_F00A1104
F00A10D8: 92102000                 mov     0, %o1
F00A10DC: 113c04f7                 sethi   -0xFEC2400, %o0
F00A10E0: d202236c                 ld      [%o0+0x36C], %o1
F00A10E4: 80a26000                 cmp     %o1, 0
F00A10E8: 02800009                 be      loc_F00A110C
F00A10EC: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A10F0: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A10F4: 80a22000                 cmp     %o0, 0
F00A10F8: 02800005                 be      loc_F00A110C
F00A10FC: 113c0463                 sethi   %hi(aPmapAllocConte_0), %o0! "pmap_alloc_context \t=\t%d\n"
F00A1100: 90122128                 bset    %lo(aPmapAllocConte_0), %o0! "pmap_alloc_context \t=\t%d\n"
F00A1104: 7ffdcd55                 call    _printf
F00A1108: 01000000                 nop
F00A110C: 113c04f7                 sethi   %hi(dword_F013DF70), %o0
F00A1110: d0022370                 ld      [%o0+%lo(dword_F013DF70)], %o0
F00A1114: 80a22000                 cmp     %o0, 0
F00A1118: 1280000b                 bne     loc_F00A1144
F00A111C: 113c04f7                 sethi   -0xFEC2400, %o0
F00A1120: 113c0463                 sethi   %hi(_pmap_func_info0), %o0
F00A1124: d0022178                 ld      [%o0+%lo(_pmap_func_info0)], %o0
F00A1128: 80a22000                 cmp     %o0, 0
F00A112C: 02800005                 be      loc_F00A1140
F00A1130: 113c0463                 sethi   %hi(aGarbageCollect), %o0! "garbage_collect \t=\t%d\n"
F00A1134: 90122148                 bset    %lo(aGarbageCollect), %o0! "garbage_collect \t=\t%d\n"
F00A1138: 1080000c                 ba      loc_F00A1168
F00A113C: 92102000                 mov     0, %o1
F00A1140: 113c04f7                 sethi   -0xFEC2400, %o0
F00A1144: d2022370                 ld      [%o0+0x370], %o1
F00A1148: 80a26000                 cmp     %o1, 0
F00A114C: 02800009                 be      locret_F00A1170
F00A1150: 113c0463                 sethi   %hi(_pmap_func_info1), %o0
F00A1154: d002217c                 ld      [%o0+%lo(_pmap_func_info1)], %o0
F00A1158: 80a22000                 cmp     %o0, 0
F00A115C: 02800005                 be      locret_F00A1170
F00A1160: 113c0463                 sethi   %hi(aGarbageCollect_0), %o0! "garbage_collect \t=\t%d\n"
F00A1164: 90122160                 bset    %lo(aGarbageCollect_0), %o0! "garbage_collect \t=\t%d\n"
F00A1168: 7ffdcd3c                 call    _printf
F00A116C: 01000000                 nop
F00A1170: 81c7e008                 ret
F00A1174: 81e80000                 restore
