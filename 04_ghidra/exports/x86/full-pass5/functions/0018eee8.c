/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018eee8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _pmap_bootstrap(int param_1,undefined4 param_2,uint *param_3,uint *param_4)

{
  int *piVar1;
  undefined4 *puVar2;
  uint *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined4 uVar11;
  uint uVar12;
  uint local_18;
  uint local_8;
  
  uVar10 = *(uint *)(param_1 + 0x18);
  _section_size = (_page_size >> 2) << 0xc;
  _ptes_per_vm_page = _page_size >> 0xc;
  puVar6 = &_kernel_prot_codes;
  puVar2 = &_user_prot_codes;
  iVar8 = 0;
  do {
    switch(iVar8) {
    case 0:
      *puVar6 = 0;
      *puVar2 = 0;
      break;
    case 1:
    case 4:
    case 5:
      *puVar6 = 0;
      *puVar2 = 2;
      break;
    case 2:
    case 3:
    case 6:
    case 7:
      *puVar6 = 1;
      *puVar2 = 3;
      break;
    default:
      goto switchD_0018ef29_default;
    }
    puVar6 = puVar6 + 1;
    puVar2 = puVar2 + 1;
switchD_0018ef29_default:
    iVar8 = iVar8 + 1;
    if (7 < iVar8) {
      _kernel_pmap = &_kernel_pmap_store;
      _DAT_001f7a6c = 0;
      puVar2 = (undefined4 *)_alloc_cnvmem(0x1000,0x1000);
      *_kernel_pmap = (int)puVar2;
      _bzero(puVar2,0x1000);
      piVar1 = _kernel_pmap;
      _kernel_pmap[2] = 1;
      *piVar1 = *piVar1 + 0xc00;
      local_8 = 0;
      local_18 = 0;
      uVar9 = (DAT_001f7a8c & 3) * 2 | 1;
      if (uVar10 != 0) {
        do {
          puVar3 = (uint *)((local_8 >> 0x16) * 4 + *_kernel_pmap);
          if (((*puVar3 & 1) == 0) ||
             (puVar3 = (uint *)((*puVar3 & 0xfffff000) + (local_8 >> 10 & 0xffc)),
             puVar3 == (uint *)0x0)) {
            FUN_0018ecc0(local_8);
            puVar3 = (uint *)((local_8 >> 0x16) * 4 + *_kernel_pmap);
            if ((*puVar3 & 1) == 0) {
              puVar3 = (uint *)0x0;
            }
            else {
              puVar3 = (uint *)((*puVar3 & 0xfffff000) + (local_8 >> 10 & 0xffc));
            }
          }
          if (local_18 - 0xa0000 < 0x60000) {
            uVar9 = uVar9 | 8;
          }
          else {
            uVar9 = uVar9 & 0xfffffff7;
          }
          *puVar3 = uVar9;
          uVar9 = uVar9 & 0xfff | (uVar9 & 0xfffff000) + 0x1000;
          local_8 = local_8 + 0x1000;
          local_18 = local_18 + 0x1000;
        } while (local_18 < uVar10);
      }
      *param_3 = local_8;
      local_18 = 0;
      do {
        puVar3 = (uint *)((local_8 >> 0x16) * 4 + *_kernel_pmap);
        if (((*puVar3 & 1) == 0) ||
           (puVar6 = (undefined4 *)((*puVar3 & 0xfffff000) + (local_8 >> 10 & 0xffc)),
           puVar6 == (undefined4 *)0x0)) {
          FUN_0018ecc0(local_8);
          puVar3 = (uint *)((local_8 >> 0x16) * 4 + *_kernel_pmap);
          if ((*puVar3 & 1) == 0) {
            puVar6 = (undefined4 *)0x0;
          }
          else {
            puVar6 = (undefined4 *)((*puVar3 & 0xfffff000) + (local_8 >> 10 & 0xffc));
          }
        }
        if (local_18 - 0xa0000 < 0x60000) {
          uVar11 = 8;
        }
        else {
          uVar11 = 0;
        }
        *puVar6 = uVar11;
        local_8 = local_8 + 0x1000;
        local_18 = local_18 + 0x1000;
      } while (local_18 < 0x4000000);
      if (_DAT_0001285c != 0) {
        uVar12 = ~_page_mask;
        uVar10 = _DAT_0001286c & uVar12;
        uVar4 = (((uint)_DAT_00012860 * (uint)_DAT_0001285e + _DAT_0001286c * 2) - uVar10) +
                _page_mask;
        _DAT_00012854 = (_DAT_0001286c + local_8) - uVar10;
        uVar9 = (DAT_001f7a8c & 3) * 2 | 1 | uVar10 & 0xfffff000;
        for (; uVar10 < (uVar4 & uVar12); uVar10 = uVar10 + 0x1000) {
          puVar3 = (uint *)((local_8 >> 0x16) * 4 + *_kernel_pmap);
          if (((*puVar3 & 1) == 0) ||
             (puVar3 = (uint *)((*puVar3 & 0xfffff000) + (local_8 >> 10 & 0xffc)),
             puVar3 == (uint *)0x0)) {
            FUN_0018ecc0(local_8);
            puVar3 = (uint *)((local_8 >> 0x16) * 4 + *_kernel_pmap);
            if ((*puVar3 & 1) == 0) {
              puVar3 = (uint *)0x0;
            }
            else {
              puVar3 = (uint *)((*puVar3 & 0xfffff000) + (local_8 >> 10 & 0xffc));
            }
          }
          if (uVar10 - 0xa0000 < 0x60000) {
            uVar9 = uVar9 | 8;
          }
          else {
            uVar9 = uVar9 & 0xfffffff7;
          }
          *puVar3 = uVar9;
          uVar9 = uVar9 & 0xfff | (uVar9 & 0xfffff000) + 0x1000;
          local_8 = local_8 + 0x1000;
        }
      }
      *param_4 = local_8;
      puVar5 = (undefined4 *)*_kernel_pmap;
      puVar6 = puVar5 + 0x100;
      puVar7 = puVar2;
      for (; puVar5 < puVar6; puVar5 = puVar5 + 1) {
        *puVar7 = *puVar5;
        puVar7 = puVar7 + 1;
      }
      puVar3 = (uint *)(((uint)puVar2 >> 0x16) * 4 + *_kernel_pmap);
      if ((((*puVar3 & 1) == 0) ||
          (puVar3 = (uint *)(((uint)puVar2 >> 10 & 0xffc) + (*puVar3 & 0xfffff000)),
          puVar3 == (uint *)0x0)) || ((*puVar3 & 1) == 0)) {
        iVar8 = 0;
      }
      else {
        iVar8 = (*puVar3 & 0xfffff000) + ((uint)puVar2 & 0xfff);
      }
      _kernel_pmap[1] = iVar8;
      return;
    }
  } while( true );
}

