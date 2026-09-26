F00A3E40: 9de3bf98                 save    %sp, -0x68, %sp
F00A3E44: 7fffc62d                 call    _mmu_getsyncflt
F00A3E48: b4100018                 mov     %i0, %i2
F00A3E4C: 113c0428                 sethi   %hi(_afsrbuf), %o0
F00A3E50: 7fffc62e                 call    _mmu_getasyncflt
F00A3E54: 901222d0                 bset    %lo(_afsrbuf), %o0
F00A3E58: 40000231                 call    _init_mem_installed
F00A3E5C: 01000000                 nop
F00A3E60: 113c04f8                 sethi   %hi(_end), %o0
F00A3E64: d0022130                 ld      [%o0+%lo(_end)], %o0
F00A3E68: 133c04f4                 sethi   %hi(_econtig), %o1
F00A3E6C: 90022fff                 inc     0xFFF, %o0
F00A3E70: 900a3000                 and     %o0, -0x1000, %o0
F00A3E74: 7ffff79a                 call    _fill_pmapinfo
F00A3E78: d0226390                 st      %o0, [%o1+%lo(_econtig)]
F00A3E7C: 113c045d                 sethi   %hi(_viking), %o0
F00A3E80: d00222d0                 ld      [%o0+%lo(_viking)], %o0
F00A3E84: 80a22000                 cmp     %o0, 0
F00A3E88: 02800008                 be      loc_F00A3EA8
F00A3E8C: 113c0464                 sethi   %hi(_nctxs), %o0
F00A3E90: d0022310                 ld      [%o0+%lo(_nctxs)], %o0
F00A3E94: a32a2002                 sll     %o0, 2, %l1
F00A3E98: 11000010                 sethi   0x4000, %o0
F00A3E9C: 80a44008                 cmp     %l1, %o0
F00A3EA0: 1a800004                 bcc     loc_F00A3EB0
F00A3EA4: 253c04f4                 sethi   -0xFEC3000, %l2
F00A3EA8: 23000010                 sethi   0x4000, %l1
F00A3EAC: 253c04f4                 sethi   -0xFEC3000, %l2
F00A3EB0: d204a390                 ld      [%l2+0x390], %o1
F00A3EB4: 2f3c000c                 sethi   %hi(_bootops), %l7
F00A3EB8: d005e038                 ld      [%l7+%lo(_bootops)], %o0
F00A3EBC: 273c0464                 sethi   %hi(_nctxs), %l3
F00A3EC0: d404e310                 ld      [%l3+%lo(_nctxs)], %o2
F00A3EC4: 96100011                 mov     %l1, %o3
F00A3EC8: d802201c                 ld      [%o0+0x1C], %o4
F00A3ECC: 9fc30000                 call    %o4
F00A3ED0: 952aa002                 sll     %o2, 2, %o2
F00A3ED4: 213c04f6                 sethi   %hi(_contexts), %l0
F00A3ED8: d204a390                 ld      [%l2+0x390], %o1
F00A3EDC: 80a20009                 cmp     %o0, %o1
F00A3EE0: 02800005                 be      loc_F00A3EF4
F00A3EE4: d02421d8                 st      %o0, [%l0+%lo(_contexts)]
F00A3EE8: 113c0464                 sethi   %hi(aCannotAllocate), %o0! "Cannot allocate memory for srmmu hw tab"...
F00A3EEC: 7ffdc4a1                 call    _panic
F00A3EF0: 901223a0                 bset    %lo(aCannotAllocate), %o0! "Cannot allocate memory for srmmu hw tab"...
F00A3EF4: 400002c5                 call    _va_to_pa
F00A3EF8: d00421d8                 ld      [%l0+0x1D8], %o0
F00A3EFC: 213c04f9                 sethi   %hi(_pcontexts), %l0
F00A3F00: 80a23fff                 cmp     %o0, -1
F00A3F04: 12800005                 bne     loc_F00A3F18
F00A3F08: d0242250                 st      %o0, [%l0+%lo(_pcontexts)]
F00A3F0C: 113c0464                 sethi   %hi(aInvalidPhysica), %o0! "Invalid physical address for srmmu hw t"...
F00A3F10: 7ffdc498                 call    _panic
F00A3F14: 901223d0                 bset    %lo(aInvalidPhysica), %o0! "Invalid physical address for srmmu hw t"...
F00A3F18: d2042250                 ld      [%l0+0x250], %o1
F00A3F1C: 90047fff                 add     %l1, -1, %o0
F00A3F20: 808a4008                 btst    %o0, %o1
F00A3F24: 02800004                 be      loc_F00A3F34
F00A3F28: 113c0465                 sethi   %hi(aPhysicalAddres_0), %o0! "Physical address not aligned as require"...
F00A3F2C: 7ffdc491                 call    _panic
F00A3F30: 90122000                 bset    %lo(aPhysicalAddres_0), %o0! "Physical address not aligned as require"...
F00A3F34: d004e310                 ld      [%l3+0x310], %o0
F00A3F38: d204a390                 ld      [%l2+0x390], %o1
F00A3F3C: 900223ff                 inc     0x3FF, %o0
F00A3F40: 9132200a                 srl     %o0, 10, %o0
F00A3F44: 912a200c                 sll     %o0, 12, %o0
F00A3F48: a0024008                 add     %o1, %o0, %l0
F00A3F4C: e024a390                 st      %l0, [%l2+0x390]
F00A3F50: 113c04f0                 sethi   %hi(_mem_size), %o0
F00A3F54: d0022108                 ld      [%o0+%lo(_mem_size)], %o0
F00A3F58: 7ffd89aa                 call    _udiv
F00A3F5C: 921020c8                 mov     0xC8, %o1
F00A3F60: ac100008                 mov     %o0, %l6
F00A3F64: 11001000                 sethi   0x400000, %o0
F00A3F68: 80a58008                 cmp     %l6, %o0
F00A3F6C: 38800002                 bgu,a   loc_F00A3F74
F00A3F70: ac100008                 mov     %o0, %l6
F00A3F74: 333c04d0                 sethi   %hi(_page_mask), %i1
F00A3F78: d20660d8                 ld      [%i1+%lo(_page_mask)], %o1
F00A3F7C: 90058009                 add     %l6, %o1, %o0
F00A3F80: ac2a0009                 andn    %o0, %o1, %l6
F00A3F84: a735a008                 srl     %l6, 8, %l3
F00A3F88: d005e038                 ld      [%l7+0x38], %o0
F00A3F8C: 92100010                 mov     %l0, %o1
F00A3F90: 2b3c0447                 sethi   %hi(_page_size), %l5
F00A3F94: d605613c                 ld      [%l5+%lo(_page_size)], %o3
F00A3F98: a32ce008                 sll     %l3, 8, %l1
F00A3F9C: d802201c                 ld      [%o0+0x1C], %o4
F00A3FA0: 9fc30000                 call    %o4
F00A3FA4: 94100011                 mov     %l1, %o2
F00A3FA8: 92100012                 mov     %l2, %o1
F00A3FAC: 293c04f8                 sethi   %hi(_kernel_seg_tables), %l4
F00A3FB0: d2026390                 ld      [%o1+0x390], %o1
F00A3FB4: 80a20009                 cmp     %o0, %o1
F00A3FB8: 02800005                 be      loc_F00A3FCC
F00A3FBC: d02520f0                 st      %o0, [%l4+%lo(_kernel_seg_tables)]
F00A3FC0: 113c0465                 sethi   %hi(aCannotAllocate_0), %o0! "Cannot allocate memory for srmmu hw tab"...
F00A3FC4: 7ffdc46b                 call    _panic
F00A3FC8: 90122030                 bset    %lo(aCannotAllocate_0), %o0! "Cannot allocate memory for srmmu hw tab"...
F00A3FCC: 4000028f                 call    _va_to_pa
F00A3FD0: d00520f0                 ld      [%l4+0xF0], %o0
F00A3FD4: 213c04f8                 sethi   %hi(_kernel_seg_tables_phys), %l0
F00A3FD8: 80a23fff                 cmp     %o0, -1
F00A3FDC: 12800005                 bne     loc_F00A3FF0
F00A3FE0: d0242100                 st      %o0, [%l0+%lo(_kernel_seg_tables_phys)]
F00A3FE4: 113c0465                 sethi   %hi(aInvalidPhysica_0), %o0! "Invalid physical address for srmmu hw t"...
F00A3FE8: 7ffdc462                 call    _panic
F00A3FEC: 90122060                 bset    %lo(aInvalidPhysica_0), %o0! "Invalid physical address for srmmu hw t"...
F00A3FF0: d005613c                 ld      [%l5+0x13C], %o0
F00A3FF4: d2042100                 ld      [%l0+0x100], %o1
F00A3FF8: 90023fff                 inc     -1, %o0
F00A3FFC: 808a4008                 btst    %o0, %o1
F00A4000: 02800004                 be      loc_F00A4010
F00A4004: 113c0465                 sethi   %hi(aPhysicalAddres_1), %o0! "Physical address not aligned as require"...
F00A4008: 7ffdc45a                 call    _panic
F00A400C: 90122090                 bset    %lo(aPhysicalAddres_1), %o0! "Physical address not aligned as require"...
F00A4010: 9004e00f                 add     %l3, 0xF, %o0
F00A4014: 91322004                 srl     %o0, 4, %o0
F00A4018: d204a390                 ld      [%l2+0x390], %o1
F00A401C: 912a200c                 sll     %o0, 12, %o0
F00A4020: 92024008                 add     %o1, %o0, %o1
F00A4024: d224a390                 st      %o1, [%l2+0x390]
F00A4028: d0042100                 ld      [%l0+0x100], %o0
F00A402C: 90020011                 add     %o0, %l1, %o0
F00A4030: 173c04f8                 sethi   %hi(_kernel_seg_end), %o3
F00A4034: d022e0d0                 st      %o0, [%o3+%lo(_kernel_seg_end)]
F00A4038: d40520f0                 ld      [%l4+0xF0], %o2
F00A403C: 113c04f8                 sethi   %hi(_kernel_seg_tables_end), %o0
F00A4040: 94028011                 add     %o2, %l1, %o2
F00A4044: d42220f8                 st      %o2, [%o0+%lo(_kernel_seg_tables_end)]
F00A4048: d005e038                 ld      [%l7+0x38], %o0
F00A404C: 15000008                 sethi   0x2000, %o2
F00A4050: d802201c                 ld      [%o0+0x1C], %o4
F00A4054: 9fc30000                 call    %o4
F00A4058: 17000004                 sethi   0x1000, %o3
F00A405C: 92100012                 mov     %l2, %o1
F00A4060: 213c04f8                 sethi   %hi(_kernel_region), %l0
F00A4064: d2026390                 ld      [%o1+0x390], %o1
F00A4068: 80a20009                 cmp     %o0, %o1
F00A406C: 02800005                 be      loc_F00A4080
F00A4070: d02420c8                 st      %o0, [%l0+%lo(_kernel_region)]
F00A4074: 113c0465                 sethi   %hi(aCannotAllocate_1), %o0! "Cannot allocate memory for srmmu hw tab"...
F00A4078: 7ffdc43e                 call    _panic
F00A407C: 901220c0                 bset    %lo(aCannotAllocate_1), %o0! "Cannot allocate memory for srmmu hw tab"...
F00A4080: 40000262                 call    _va_to_pa
F00A4084: d00420c8                 ld      [%l0+0xC8], %o0
F00A4088: 213c04f8                 sethi   %hi(_Nl1ptbl_addr), %l0
F00A408C: 80a23fff                 cmp     %o0, -1
F00A4090: 12800005                 bne     loc_F00A40A4
F00A4094: d0242160                 st      %o0, [%l0+%lo(_Nl1ptbl_addr)]
F00A4098: 113c0465                 sethi   %hi(aInvalidPhysica_1), %o0! "Invalid physical address for srmmu hw t"...
F00A409C: 7ffdc435                 call    _panic
F00A40A0: 901220f0                 bset    %lo(aInvalidPhysica_1), %o0! "Invalid physical address for srmmu hw t"...
F00A40A4: d0042160                 ld      [%l0+0x160], %o0
F00A40A8: 808a2fff                 btst    0xFFF, %o0
F00A40AC: 02800004                 be      loc_F00A40BC
F00A40B0: 113c0465                 sethi   %hi(aPhysicalAddres_2), %o0! "Physical address not aligned as require"...
F00A40B4: 7ffdc42f                 call    _panic
F00A40B8: 90122120                 bset    %lo(aPhysicalAddres_2), %o0! "Physical address not aligned as require"...
F00A40BC: e004a390                 ld      [%l2+0x390], %l0
F00A40C0: 11000008                 sethi   0x2000, %o0
F00A40C4: a0040008                 add     %l0, %o0, %l0
F00A40C8: e024a390                 st      %l0, [%l2+0x390]
F00A40CC: e205613c                 ld      [%l5+0x13C], %l1
F00A40D0: 90100016                 mov     %l6, %o0
F00A40D4: 7ffd894b                 call    _udiv
F00A40D8: 92100011                 mov     %l1, %o1
F00A40DC: b0100008                 mov     %o0, %i0
F00A40E0: d20660d8                 ld      [%i1+0xD8], %o1
F00A40E4: 912e2005                 sll     %i0, 5, %o0
F00A40E8: 90020009                 add     %o0, %o1, %o0
F00A40EC: 922a0009                 andn    %o0, %o1, %o1
F00A40F0: a7326005                 srl     %o1, 5, %l3
F00A40F4: d005e038                 ld      [%l7+0x38], %o0
F00A40F8: 92100010                 mov     %l0, %o1
F00A40FC: 952ce005                 sll     %l3, 5, %o2
F00A4100: d802201c                 ld      [%o0+0x1C], %o4
F00A4104: 9fc30000                 call    %o4
F00A4108: 96100011                 mov     %l1, %o3
F00A410C: 92100012                 mov     %l2, %o1
F00A4110: 213c04f8                 sethi   %hi(_kernel_seg_pools), %l0
F00A4114: d2026390                 ld      [%o1+0x390], %o1
F00A4118: 80a20009                 cmp     %o0, %o1
F00A411C: 02800005                 be      loc_F00A4130
F00A4120: d02420e8                 st      %o0, [%l0+%lo(_kernel_seg_pools)]
F00A4124: 113c0465                 sethi   %hi(aCannotAllocate_2), %o0! "Cannot allocate memory for srmmu hw tab"...
F00A4128: 7ffdc412                 call    _panic
F00A412C: 90122150                 bset    %lo(aCannotAllocate_2), %o0! "Cannot allocate memory for srmmu hw tab"...
F00A4130: 40000236                 call    _va_to_pa
F00A4134: d00420e8                 ld      [%l0+0xE8], %o0
F00A4138: a0100008                 mov     %o0, %l0
F00A413C: 80a43fff                 cmp     %l0, -1
F00A4140: 32800006                 bne,a   loc_F00A4158
F00A4144: d005613c                 ld      [%l5+0x13C], %o0
F00A4148: 113c0465                 sethi   %hi(aInvalidPhysica_2), %o0! "Invalid physical address for srmmu hw t"...
F00A414C: 7ffdc409                 call    _panic
F00A4150: 90122180                 bset    %lo(aInvalidPhysica_2), %o0! "Invalid physical address for srmmu hw t"...
F00A4154: d005613c                 ld      [%l5+0x13C], %o0
F00A4158: 90023fff                 inc     -1, %o0
F00A415C: 808c0008                 btst    %o0, %l0
F00A4160: 22800006                 be,a    loc_F00A4178
F00A4164: 9004e07f                 add     %l3, 0x7F, %o0
F00A4168: 113c0465                 sethi   %hi(aPhysicalAddres_3), %o0! "Physical address not aligned as require"...
F00A416C: 7ffdc401                 call    _panic
F00A4170: 901221b0                 bset    %lo(aPhysicalAddres_3), %o0! "Physical address not aligned as require"...
F00A4174: 9004e07f                 add     %l3, 0x7F, %o0
F00A4178: 91322007                 srl     %o0, 7, %o0
F00A417C: e004a390                 ld      [%l2+0x390], %l0
F00A4180: 912a200c                 sll     %o0, 12, %o0
F00A4184: a0040008                 add     %l0, %o0, %l0
F00A4188: e024a390                 st      %l0, [%l2+0x390]
F00A418C: 113c04f7ac122270         set     _pmap_info, %l6
F00A4194: f025a010                 st      %i0, [%l6+0x10]
F00A4198: d215a004                 lduh    [%l6+4], %o1
F00A419C: 7ffd88d9                 call    _umul
F00A41A0: 90100018                 mov     %i0, %o0
F00A41A4: 92102028                 mov     0x28, %o1 ! '('
F00A41A8: a8100008                 mov     %o0, %l4
F00A41AC: 952d2002                 sll     %l4, 2, %o2
F00A41B0: 94028014                 add     %o2, %l4, %o2
F00A41B4: d00660d8                 ld      [%i1+0xD8], %o0
F00A41B8: 952aa003                 sll     %o2, 3, %o2
F00A41BC: 94028008                 add     %o2, %o0, %o2
F00A41C0: 7ffd8910                 call    _udiv
F00A41C4: 902a8008                 andn    %o2, %o0, %o0
F00A41C8: 98100008                 mov     %o0, %o4
F00A41CC: d005e038                 ld      [%l7+0x38], %o0
F00A41D0: 92100010                 mov     %l0, %o1
F00A41D4: 952b2002                 sll     %o4, 2, %o2
F00A41D8: 9402800c                 add     %o2, %o4, %o2
F00A41DC: d605613c                 ld      [%l5+0x13C], %o3
F00A41E0: a32aa003                 sll     %o2, 3, %l1
F00A41E4: d802201c                 ld      [%o0+0x1C], %o4
F00A41E8: 9fc30000                 call    %o4
F00A41EC: 94100011                 mov     %l1, %o2
F00A41F0: 92100012                 mov     %l2, %o1
F00A41F4: 273c04f8                 sethi   %hi(_kernel_seg_entries), %l3
F00A41F8: d2026390                 ld      [%o1+0x390], %o1
F00A41FC: 80a20009                 cmp     %o0, %o1
F00A4200: 02800005                 be      loc_F00A4214
F00A4204: d024e0d8                 st      %o0, [%l3+%lo(_kernel_seg_entries)]
F00A4208: 113c0465                 sethi   %hi(aCannotAllocate_3), %o0! "Cannot allocate memory for srmmu hw tab"...
F00A420C: 7ffdc3d9                 call    _panic
F00A4210: 901221e0                 bset    %lo(aCannotAllocate_3), %o0! "Cannot allocate memory for srmmu hw tab"...
F00A4214: 400001fd                 call    _va_to_pa
F00A4218: d004e0d8                 ld      [%l3+0xD8], %o0
F00A421C: a0100008                 mov     %o0, %l0
F00A4220: 80a43fff                 cmp     %l0, -1
F00A4224: 32800006                 bne,a   loc_F00A423C
F00A4228: d005613c                 ld      [%l5+0x13C], %o0
F00A422C: 113c0465                 sethi   %hi(aInvalidPhysica_3), %o0! "Invalid physical address for srmmu hw t"...
F00A4230: 7ffdc3d0                 call    _panic
F00A4234: 90122210                 bset    %lo(aInvalidPhysica_3), %o0! "Invalid physical address for srmmu hw t"...
F00A4238: d005613c                 ld      [%l5+0x13C], %o0
F00A423C: 90023fff                 inc     -1, %o0
F00A4240: 808c0008                 btst    %o0, %l0
F00A4244: 02800004                 be      loc_F00A4254
F00A4248: 113c0465                 sethi   %hi(aPhysicalAddres_4), %o0! "Physical address not aligned as require"...
F00A424C: 7ffdc3c9                 call    _panic
F00A4250: 90122240                 bset    %lo(aPhysicalAddres_4), %o0! "Physical address not aligned as require"...
F00A4254: 90046fff                 add     %l1, 0xFFF, %o0
F00A4258: d204a390                 ld      [%l2+0x390], %o1
F00A425C: 900a3000                 and     %o0, -0x1000, %o0
F00A4260: 92024008                 add     %o1, %o0, %o1
F00A4264: d224a390                 st      %o1, [%l2+0x390]
F00A4268: e825a00c                 st      %l4, [%l6+0xC]
F00A426C: d004e0d8                 ld      [%l3+0xD8], %o0
F00A4270: 153c04f8                 sethi   %hi(_kernel_seg_entries_end), %o2
F00A4274: 90020011                 add     %o0, %l1, %o0
F00A4278: d022a0e0                 st      %o0, [%o2+%lo(_kernel_seg_entries_end)]
F00A427C: d005e038                 ld      [%l7+0x38], %o0
F00A4280: 233c0464                 sethi   %hi(_nctxs), %l1
F00A4284: d8046310                 ld      [%l1+%lo(_nctxs)], %o4
F00A4288: d605613c                 ld      [%l5+0x13C], %o3
F00A428C: 952b2001                 sll     %o4, 1, %o2
F00A4290: 9402800c                 add     %o2, %o4, %o2
F00A4294: d802201c                 ld      [%o0+0x1C], %o4
F00A4298: 9fc30000                 call    %o4
F00A429C: 952aa002                 sll     %o2, 2, %o2
F00A42A0: 92100012                 mov     %l2, %o1
F00A42A4: 213c04f7                 sethi   %hi(_context_table), %l0
F00A42A8: d2026390                 ld      [%o1+0x390], %o1
F00A42AC: 80a20009                 cmp     %o0, %o1
F00A42B0: 02800005                 be      loc_F00A42C4
F00A42B4: d0242210                 st      %o0, [%l0+%lo(_context_table)]
F00A42B8: 113c0465                 sethi   %hi(aCannotAllocate_4), %o0! "Cannot allocate memory for srmmu hw tab"...
F00A42BC: 7ffdc3ad                 call    _panic
F00A42C0: 90122270                 bset    %lo(aCannotAllocate_4), %o0! "Cannot allocate memory for srmmu hw tab"...
F00A42C4: 400001d1                 call    _va_to_pa
F00A42C8: d0042210                 ld      [%l0+0x210], %o0
F00A42CC: a0100008                 mov     %o0, %l0
F00A42D0: 80a43fff                 cmp     %l0, -1
F00A42D4: 32800006                 bne,a   loc_F00A42EC
F00A42D8: d005613c                 ld      [%l5+0x13C], %o0
F00A42DC: 113c0465                 sethi   %hi(aInvalidPhysica_4), %o0! "Invalid physical address for srmmu hw t"...
F00A42E0: 7ffdc3a4                 call    _panic
F00A42E4: 901222a0                 bset    %lo(aInvalidPhysica_4), %o0! "Invalid physical address for srmmu hw t"...
F00A42E8: d005613c                 ld      [%l5+0x13C], %o0
F00A42EC: 90023fff                 inc     -1, %o0
F00A42F0: 808c0008                 btst    %o0, %l0
F00A42F4: 02800006                 be      loc_F00A430C
F00A42F8: d2046310                 ld      [%l1+0x310], %o1
F00A42FC: 113c0465                 sethi   %hi(aPhysicalAddres_5), %o0! "Physical address not aligned as require"...
F00A4300: 7ffdc39c                 call    _panic
F00A4304: 901222d0                 bset    %lo(aPhysicalAddres_5), %o0! "Physical address not aligned as require"...
F00A4308: d2046310                 ld      [%l1+0x310], %o1
F00A430C: 912a6001                 sll     %o1, 1, %o0
F00A4310: 90020009                 add     %o0, %o1, %o0
F00A4314: 912a2002                 sll     %o0, 2, %o0
F00A4318: 90022fff                 inc     0xFFF, %o0
F00A431C: d204a390                 ld      [%l2+0x390], %o1
F00A4320: 900a3000                 and     %o0, -0x1000, %o0
F00A4324: 92024008                 add     %o1, %o0, %o1
F00A4328: d224a390                 st      %o1, [%l2+0x390]
F00A432C: 7ffff693                 call    _init_kernel_page_tables
F00A4330: 90100018                 mov     %i0, %o0
F00A4334: 7ffffb3c                 call    _init_context_table
F00A4338: 01000000                 nop
F00A433C: 113c045d                 sethi   %hi(_viking), %o0
F00A4340: d00222d0                 ld      [%o0+%lo(_viking)], %o0
F00A4344: 80a22000                 cmp     %o0, 0
F00A4348: 02800009                 be      loc_F00A436C
F00A434C: 113c045d                 sethi   %hi(_mxcc), %o0
F00A4350: d00222d4                 ld      [%o0+%lo(_mxcc)], %o0
F00A4354: 80a22000                 cmp     %o0, 0
F00A4358: 12800006                 bne     loc_F00A4370
F00A435C: 273c000c                 sethi   -0xFFFD000, %l3
F00A4360: 90102000                 mov     0, %o0
F00A4364: 7fffc7e2                 call    _bpt_reg
F00A4368: 13000004                 sethi   0x1000, %o1
F00A436C: 273c000c                 sethi   -0xFFFD000, %l3
F00A4370: d004e038                 ld      [%l3+0x38], %o0
F00A4374: 133c0465                 sethi   %hi(aMemoryUpdate), %o1! "memory-update"
F00A4378: d4022030                 ld      [%o0+0x30], %o2
F00A437C: 9fc28000                 call    %o2
F00A4380: 92126300                 bset    %lo(aMemoryUpdate), %o1! "memory-update"
F00A4384: 80a22000                 cmp     %o0, 0
F00A4388: 12800009                 bne     loc_F00A43AC
F00A438C: 253c0464                 sethi   -0xFEE7000, %l2
F00A4390: 133c0465                 sethi   %hi(aMemoryUpdate_0), %o1! "memory-update"
F00A4394: d004e038                 ld      [%l3+0x38], %o0
F00A4398: 92126310                 bset    %lo(aMemoryUpdate_0), %o1! "memory-update"
F00A439C: d6022034                 ld      [%o0+0x34], %o3
F00A43A0: 9fc2c000                 call    %o3
F00A43A4: 94102000                 mov     0, %o2
F00A43A8: 253c0464                 sethi   -0xFEE7000, %l2
F00A43AC: d404a380                 ld      [%l2+0x380], %o2
F00A43B0: 213c04f8                 sethi   %hi(_cur_memlist), %l0
F00A43B4: d004e038                 ld      [%l3+0x38], %o0
F00A43B8: a2142178                 or      %l0, %lo(_cur_memlist), %l1
F00A43BC: d8042178                 ld      [%l0+%lo(_cur_memlist)], %o4
F00A43C0: 92100011                 mov     %l1, %o1
F00A43C4: d0022008                 ld      [%o0+8], %o0
F00A43C8: 173c0464                 sethi   %hi(_phys_avail), %o3
F00A43CC: d0022004                 ld      [%o0+4], %o0
F00A43D0: 40000060                 call    _copy_memlist
F00A43D4: d822e394                 st      %o4, [%o3+%lo(_phys_avail)]
F00A43D8: d404a380                 ld      [%l2+0x380], %o2
F00A43DC: d004e038                 ld      [%l3+0x38], %o0
F00A43E0: d8042178                 ld      [%l0+%lo(_cur_memlist)], %o4
F00A43E4: 92100011                 mov     %l1, %o1
F00A43E8: d0022008                 ld      [%o0+8], %o0
F00A43EC: 173c0464                 sethi   %hi(_virt_avail), %o3
F00A43F0: d0022008                 ld      [%o0+8], %o0
F00A43F4: 40000057                 call    _copy_memlist
F00A43F8: d822e398                 st      %o4, [%o3+%lo(_virt_avail)]
F00A43FC: d004e038                 ld      [%l3+0x38], %o0
F00A4400: d202202c                 ld      [%o0+0x2C], %o1
F00A4404: 9fc24000                 call    %o1
F00A4408: 01000000                 nop
F00A440C: 40000116                 call    _init_mem_regions
F00A4410: 9010001a                 mov     %i2, %o0
F00A4414: 400001f8                 call    _copy_page_tables
F00A4418: 01000000                 nop
F00A441C: 113c0464                 sethi   %hi(_iom), %o0
F00A4420: d0022338                 ld      [%o0+%lo(_iom)], %o0
F00A4424: 80a22000                 cmp     %o0, 0
F00A4428: 02800022                 be      locret_F00A44B0
F00A442C: 11000008                 sethi   0x2000, %o0
F00A4430: 40000147                 call    _get_from_mem_regions
F00A4434: 92102004                 mov     4, %o1
F00A4438: 133c04f6                 sethi   %hi(_first_page), %o1
F00A443C: d0226100                 st      %o0, [%o1+%lo(_first_page)]
F00A4440: 11000010                 sethi   0x4000, %o0
F00A4444: 40000142                 call    _get_from_mem_regions
F00A4448: 92100008                 mov     %o0, %o1
F00A444C: 133c04f6                 sethi   %hi(_phys_iopte), %o1
F00A4450: d0226318                 st      %o0, [%o1+%lo(_phys_iopte)]
F00A4454: 92100008                 mov     %o0, %o1
F00A4458: 94102000                 mov     0, %o2
F00A445C: 17000010                 sethi   0x4000, %o3
F00A4460: 233c04f4                 sethi   %hi(_econtig), %l1
F00A4464: 213c04f6                 sethi   %hi(_ioptes), %l0
F00A4468: 98102007                 mov     7, %o4
F00A446C: d0046390                 ld      [%l1+%lo(_econtig)], %o0
F00A4470: 9a102000                 mov     0, %o5
F00A4474: 7fffdfa7                 call    _pmap_map
F00A4478: d0242308                 st      %o0, [%l0+%lo(_ioptes)]
F00A447C: d4042308                 ld      [%l0+%lo(_ioptes)], %o2
F00A4480: 11000010                 sethi   0x4000, %o0
F00A4484: 92028008                 add     %o2, %o0, %o1
F00A4488: 113c04f8                 sethi   %hi(_eioptes), %o0
F00A448C: d2222180                 st      %o1, [%o0+%lo(_eioptes)]
F00A4490: 113c045d                 sethi   %hi(_viking), %o0
F00A4494: d00222d0                 ld      [%o0+%lo(_viking)], %o0
F00A4498: 80a22000                 cmp     %o0, 0
F00A449C: 02800005                 be      locret_F00A44B0
F00A44A0: d2246390                 st      %o1, [%l1+%lo(_econtig)]
F00A44A4: 9010000a                 mov     %o2, %o0
F00A44A8: 40000164                 call    _pac_flush
F00A44AC: 92224008                 sub     %o1, %o0, %o1
F00A44B0: 81c7e008                 ret
F00A44B4: 81e80000                 restore
