/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0018fee4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _pmap_protect(int *param_1,uint param_2,uint param_3,int param_4)

{
  uint *puVar1;
  byte bVar2;
  undefined4 uVar3;
  byte *pbVar4;
  byte bVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  int in_FS_OFFSET;
  byte *local_10;
  uint local_8;
  
  if (param_1 != (int *)0x0) {
    if (param_4 == 0) {
      uVar3 = _splvm();
      if (((param_1 == _kernel_pmap) || (param_1[6] != 0)) &&
         (__tlb_stat = __tlb_stat + 1, uVar7 = param_2, param_3 - param_2 <= _page_size)) {
        for (; uVar7 < param_3; uVar7 = uVar7 + 0x1000) {
          if (param_1 == _kernel_pmap) {
            invlpg(uVar7);
          }
          else {
            invlpg(in_FS_OFFSET + uVar7);
          }
        }
        _DAT_001f7af4 = _DAT_001f7af4 + 1;
      }
      while (param_2 < param_3) {
        uVar7 = _section_size + -1 + param_2 + _page_size & -_section_size;
        if (param_3 < uVar7) {
          uVar7 = param_3;
        }
        FUN_0018f7f8(param_1,param_2,uVar7,1);
        param_2 = uVar7;
      }
    }
    else {
      uVar3 = _splvm();
      piVar6 = param_1 + 3;
      do {
        do {
        } while (*piVar6 != 0);
        LOCK();
        iVar8 = *piVar6;
        *piVar6 = 1;
        UNLOCK();
      } while (iVar8 == 1);
      if (((param_1 == _kernel_pmap) || (param_1[6] != 0)) &&
         (__tlb_stat = __tlb_stat + 1, uVar7 = param_2, param_3 - param_2 <= _page_size)) {
        for (; uVar7 < param_3; uVar7 = uVar7 + 0x1000) {
          if (param_1 == _kernel_pmap) {
            invlpg(uVar7);
          }
          else {
            invlpg(in_FS_OFFSET + uVar7);
          }
        }
        _DAT_001f7af4 = _DAT_001f7af4 + 1;
      }
      while (uVar7 = param_2, uVar7 < param_3) {
        local_8 = _section_size + -1 + uVar7 + _page_size & -_section_size;
        if (param_3 < local_8) {
          local_8 = param_3;
        }
        puVar1 = (uint *)(*param_1 + (uVar7 >> 0x16) * 4);
        param_2 = local_8;
        if (((*puVar1 & 1) != 0) &&
           (pbVar4 = (byte *)((uVar7 >> 10 & 0xffc) + (*puVar1 & 0xfffff000)), param_2 = local_8,
           pbVar4 != (byte *)0x0)) {
          puVar1 = (uint *)(*param_1 + (local_8 >> 0x16) * 4);
          if ((*puVar1 & 1) == 0) {
            local_10 = (byte *)0x0;
          }
          else {
            local_10 = (byte *)((*puVar1 & 0xfffff000) + (local_8 >> 10 & 0xffc));
          }
          uVar7 = ~_page_mask;
          if (((uint)pbVar4 & uVar7) != ((uint)local_10 & uVar7)) {
            local_10 = (byte *)((uint)(pbVar4 + _page_mask + _ptes_per_vm_page * 4) & uVar7);
          }
          while (param_2 = local_8, pbVar4 < local_10) {
            iVar8 = _ptes_per_vm_page;
            if ((*pbVar4 & 1) == 0) {
              pbVar4 = pbVar4 + _ptes_per_vm_page * 4;
            }
            else {
              while (0 < iVar8) {
                bVar2 = *pbVar4;
                if (_kernel_pmap == param_1) {
                  bVar5 = *(byte *)(&_kernel_prot_codes + param_4);
                }
                else {
                  bVar5 = *(byte *)(&_user_prot_codes + param_4);
                }
                *pbVar4 = bVar2 & 0xf9 | (bVar5 & 3) * '\x02';
                *pbVar4 = *pbVar4 & 0xfe | bVar2 & 1;
                pbVar4 = pbVar4 + 4;
                iVar8 = iVar8 + -1;
              }
            }
          }
        }
      }
      LOCK();
      param_1[3] = 0;
      UNLOCK();
    }
    _splx(uVar3);
  }
  return;
}

