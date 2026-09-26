
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0019157c(int param_1,byte param_2)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint *puVar5;
  int iVar6;
  byte *pbVar7;
  int *piVar8;
  int in_FS_OFFSET;
  int *local_8;
  
  local_8 = (int *)(_pg_desc_tbl +
                   (((uint)(param_1 - __pg_first_phys) >> 0xc) >>
                   ((char)_ptes_per_vm_page - 1U & 0x1f)) * 0x14);
  uVar4 = _splvm();
  *(byte *)(local_8 + 4) = *(byte *)(local_8 + 4) & ~param_2;
  piVar8 = (int *)local_8[1];
  if (piVar8 != (int *)0x0) {
    do {
      uVar2 = local_8[2];
      piVar1 = piVar8 + 3;
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar6 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar6 == 1);
      if (((piVar8 == _kernel_pmap) || (piVar8[6] != 0)) &&
         (__tlb_stat = __tlb_stat + 1, uVar3 = uVar2, (uVar2 + _page_size) - uVar2 <= _page_size)) {
        for (; uVar3 < uVar2 + _page_size; uVar3 = uVar3 + 0x1000) {
          if (piVar8 == _kernel_pmap) {
            invlpg(uVar3);
          }
          else {
            invlpg(in_FS_OFFSET + uVar3);
          }
        }
        _DAT_001f7af4 = _DAT_001f7af4 + 1;
      }
      puVar5 = (uint *)((uVar2 >> 0x16) * 4 + *piVar8);
      if (((*puVar5 & 1) != 0) &&
         (pbVar7 = (byte *)((*puVar5 & 0xfffff000) + (uVar2 >> 10 & 0xffc)),
         iVar6 = _ptes_per_vm_page, pbVar7 != (byte *)0x0)) {
        while (0 < iVar6) {
          if ((param_2 & 1) != 0) {
            *pbVar7 = *pbVar7 & 0xbf;
          }
          if ((param_2 & 2) != 0) {
            *pbVar7 = *pbVar7 & 0xdf;
          }
          pbVar7 = pbVar7 + 4;
          iVar6 = iVar6 + -1;
        }
      }
      LOCK();
      piVar8[3] = 0;
      UNLOCK();
      local_8 = (int *)*local_8;
    } while ((local_8 != (int *)0x0) && (piVar8 = (int *)local_8[1], piVar8 != (int *)0x0));
  }
  _splx(uVar4);
  return;
}

