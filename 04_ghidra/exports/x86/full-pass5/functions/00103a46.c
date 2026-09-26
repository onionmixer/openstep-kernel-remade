/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00103a46 */

/* Synthetic analysis entry; not a reconstructed ABI function. Role=noreturn_fallthrough_fragment.
   Context recorded in gap-actions.json. */

bool __analysis_fragment_00103a46(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  kern_return_t kVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint uVar8;
  int unaff_EBP;
  
  uVar6 = *(uint *)(unaff_EBP + -0xb8) >> 1;
  *(uint *)(unaff_EBP + -0xb8) = uVar6;
  *(undefined4 *)(unaff_EBP + -0xec) = 0;
  uVar8 = 0;
  if (uVar6 != 0) {
    *(undefined4 *)(unaff_EBP + -0x100) = *(undefined4 *)(unaff_EBP + -0x100);
    *(undefined4 *)(unaff_EBP + -0x108) = 0;
    do {
      *(int *)(unaff_EBP + -0xec) =
           *(int *)(*(int *)(unaff_EBP + -0x108) + 4 + *(int *)(unaff_EBP + -0x100)) * 4 + 8 +
           *(int *)(unaff_EBP + -0xec);
      *(int *)(unaff_EBP + -0x108) = *(int *)(unaff_EBP + -0x108) + 8;
      uVar8 = uVar8 + 1;
    } while (uVar8 < uVar6);
  }
  iVar5 = *(int *)(unaff_EBP + -0xec) * *(int *)(unaff_EBP + -0xe4) +
          (*(int *)(unaff_EBP + -0x104) * 7 + *(int *)(unaff_EBP + -0xe4)) * 8;
  *(int *)(unaff_EBP + -0xe8) = iVar5 + 0x1c;
  _kmem_alloc_wired(_kernel_map,unaff_EBP + -0xbc);
  puVar7 = *(undefined4 **)(unaff_EBP + -0xbc);
  *puVar7 = 0xfeedface;
  puVar7[1] = DAT_001e8e04;
  puVar7[2] = DAT_001e8e08;
  puVar7[3] = 4;
  puVar7[4] = *(int *)(unaff_EBP + -0xe4) + *(int *)(unaff_EBP + -0x104);
  puVar7[5] = iVar5;
  *(undefined4 *)(unaff_EBP + -0xf0) = 0x1c;
  uVar6 = *(int *)(unaff_EBP + -0xe8) + _page_mask & ~_page_mask;
  *(undefined4 *)(unaff_EBP + -0xc0) = 0;
  iVar5 = *(int *)(unaff_EBP + -0x104);
  while ((0 < iVar5 &&
         (kVar4 = _vm_region(*(vm_map_t *)(unaff_EBP + -0xe0),(vm_address_t *)(unaff_EBP + -0xc0),
                             (vm_size_t *)(unaff_EBP + -0xc4),unaff_EBP + -200,
                             (vm_region_info_t)(unaff_EBP + -0xcc),
                             (mach_msg_type_number_t *)(unaff_EBP + -0xd0),
                             (mach_port_t *)(unaff_EBP + -0xd4)), kVar4 != 3))) {
    puVar7 = (undefined4 *)(*(int *)(unaff_EBP + -0xf0) + *(int *)(unaff_EBP + -0xbc));
    *puVar7 = 1;
    puVar7[1] = 0x38;
    puVar7[6] = *(undefined4 *)(unaff_EBP + -0xc0);
    puVar7[7] = *(undefined4 *)(unaff_EBP + -0xc4);
    puVar7[8] = uVar6;
    puVar7[9] = *(undefined4 *)(unaff_EBP + -0xc4);
    puVar7[10] = *(undefined4 *)(unaff_EBP + -0xcc);
    puVar7[0xb] = *(undefined4 *)(unaff_EBP + -200);
    puVar7[0xc] = 0;
    if ((*(uint *)(unaff_EBP + -200) & 1) == 0) {
      _vm_protect(*(vm_map_t *)(unaff_EBP + -0xe0),*(vm_address_t *)(unaff_EBP + -0xc0),
                  *(vm_size_t *)(unaff_EBP + -0xc4),0,*(uint *)(unaff_EBP + -200) | 1);
    }
    if ((*(byte *)(unaff_EBP + -0xcc) & 1) != 0) {
      _vn_rdwr(1,*(undefined4 *)(unaff_EBP + -0xb4),*(undefined4 *)(unaff_EBP + -0xc0),
               *(undefined4 *)(unaff_EBP + -0xc4),uVar6,0,1);
    }
    *(int *)(unaff_EBP + -0xf0) = *(int *)(unaff_EBP + -0xf0) + 0x38;
    uVar6 = uVar6 + *(int *)(unaff_EBP + -0xc4);
    *(int *)(unaff_EBP + -0xc0) = *(int *)(unaff_EBP + -0xc0) + *(int *)(unaff_EBP + -0xc4);
    *(int *)(unaff_EBP + -0x104) = *(int *)(unaff_EBP + -0x104) + -1;
    iVar5 = *(int *)(unaff_EBP + -0x104);
  }
  do {
    do {
    } while (**(int **)(unaff_EBP + -0xf4) != 0);
    piVar1 = *(int **)(unaff_EBP + -0xf4);
    LOCK();
    iVar5 = *piVar1;
    *piVar1 = 1;
    UNLOCK();
  } while (iVar5 == 1);
  *(int *)(unaff_EBP + -0xf8) = piVar1[7];
  if (0 < *(int *)(unaff_EBP + -0xe4)) {
    *(int *)(unaff_EBP + -0xfc) = unaff_EBP + -0xb0;
    do {
      puVar7 = (undefined4 *)(*(int *)(unaff_EBP + -0xf0) + *(int *)(unaff_EBP + -0xbc));
      *puVar7 = 4;
      puVar7[1] = *(int *)(unaff_EBP + -0xec) + 8;
      *(int *)(unaff_EBP + -0xf0) = *(int *)(unaff_EBP + -0xf0) + 8;
      uVar6 = 0;
      if (*(int *)(unaff_EBP + -0xb8) != 0) {
        *(undefined4 *)(unaff_EBP + -0x100) = *(undefined4 *)(unaff_EBP + -0xfc);
        *(undefined4 *)(unaff_EBP + -0x104) = 0;
        do {
          iVar5 = *(int *)(unaff_EBP + -0xbc);
          iVar2 = *(int *)(unaff_EBP + -0xf0);
          uVar3 = *(undefined4 *)(unaff_EBP + -0xac + uVar6 * 8);
          *(undefined4 *)(iVar2 + iVar5) = *(undefined4 *)(unaff_EBP + -0xb0 + uVar6 * 8);
          *(undefined4 *)(iVar2 + 4 + iVar5) = uVar3;
          *(int *)(unaff_EBP + -0xf0) = iVar2 + 8;
          _thread_getstatus(*(undefined4 *)(unaff_EBP + -0xf8),**(undefined4 **)(unaff_EBP + -0x100)
                            ,iVar5 + iVar2 + 8);
          *(int *)(unaff_EBP + -0xf0) =
               *(int *)(unaff_EBP + -0xf0) +
               *(int *)(*(int *)(unaff_EBP + -0x104) + 4 + *(int *)(unaff_EBP + -0xfc)) * 4;
          *(int *)(unaff_EBP + -0x100) = *(int *)(unaff_EBP + -0x100) + 8;
          *(int *)(unaff_EBP + -0x104) = *(int *)(unaff_EBP + -0x104) + 8;
          uVar6 = uVar6 + 1;
        } while (uVar6 < *(uint *)(unaff_EBP + -0xb8));
      }
      *(undefined4 *)(unaff_EBP + -0xf8) = *(undefined4 *)(*(int *)(unaff_EBP + -0xf8) + 0x10);
      *(int *)(unaff_EBP + -0xe4) = *(int *)(unaff_EBP + -0xe4) + -1;
    } while (0 < *(int *)(unaff_EBP + -0xe4));
  }
  LOCK();
  **(undefined4 **)(unaff_EBP + -0xf4) = 0;
  UNLOCK();
  iVar5 = _vn_rdwr(1,*(undefined4 *)(unaff_EBP + -0xb4),*(undefined4 *)(unaff_EBP + -0xbc),
                   *(undefined4 *)(unaff_EBP + -0xe8),0,1,1);
  _kmem_free(_kernel_map,*(undefined4 *)(unaff_EBP + -0xbc));
  _vn_rele();
  *(char *)(DAT_001e875c + 0x68) = (char)iVar5;
  return iVar5 == 0;
}

