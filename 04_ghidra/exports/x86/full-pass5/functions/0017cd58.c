/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0017cd58 */

/* WARNING: Removing unreachable block (ram,0x0017ce51) */

undefined4 FUN_0017cd58(int param_1,uint param_2,int param_3,uint *param_4)

{
  byte *pbVar1;
  size_t sVar2;
  byte bVar3;
  bool bVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint local_14;
  
  param_2 = param_2 >> ((byte)_page_shift & 0x1f);
  if (param_2 < *(uint *)(param_1 + 0x10)) {
    if (*(uint *)(param_1 + 0x10) << 2 < 0x41) {
      if (*(char *)(*(int *)(param_1 + 8) + param_2 * 4) == '\0') goto LAB_0017cdb4;
      *param_4 = *(uint *)(*(int *)(param_1 + 8) + param_2 * 4);
    }
    else {
      iVar7 = *(int *)(*(int *)(param_1 + 8) + (param_2 >> 4) * 4);
      if ((iVar7 == 0) || (*(char *)(iVar7 + (param_2 & 0xf) * 4) == '\0')) goto LAB_0017cdb4;
      *param_4 = *(uint *)(iVar7 + (param_2 & 0xf) * 4);
    }
    bVar4 = true;
  }
  else {
LAB_0017cdb4:
    bVar4 = false;
  }
  if (param_3 == 1) {
    if (!bVar4) {
      return 5;
    }
    return 0;
  }
  if (bVar4) {
    uVar9 = *param_4;
    uVar8 = uVar9 >> 8;
    if ((int)uVar8 <= *(int *)(*(int *)(&DAT_001e7294 + (uint)(byte)*param_4 * 4) + 0x24)) {
      return 0;
    }
    if ((char)uVar9 != '\0') {
      iVar7 = *(int *)(&DAT_001e7294 + (uVar9 & 0xff) * 4);
      _lock_write(iVar7 + 0x34);
      if (*(int *)(iVar7 + 0x14) <= (int)uVar8) {
                    /* WARNING: Subroutine does not return */
        _panic(s_vnode_pager_deallocpage_001e0e72);
      }
      if ((int)uVar8 < *(int *)(iVar7 + 0x24)) {
        *(uint *)(iVar7 + 0x24) = uVar8;
      }
      bVar3 = (char)(uVar9 >> 8) + (char)((int)uVar8 >> 3) * -8 & 0x1f;
      pbVar1 = (byte *)(((int)uVar8 >> 3) + *(int *)(iVar7 + 0x10));
      *pbVar1 = *pbVar1 & ((byte)(-2 << bVar3) | (byte)(0xfffffffe >> 0x20 - bVar3));
      *(int *)(iVar7 + 0x18) = *(int *)(iVar7 + 0x18) + 1;
      _lock_done(iVar7 + 0x34);
    }
  }
  uVar8 = param_2 + 1;
  uVar9 = *(uint *)(param_1 + 0x10);
  if (uVar9 < uVar8) {
    if (uVar8 * 4 < 0x41) {
      piVar5 = (int *)_kalloc_noblock(uVar8 * 4);
      if (piVar5 == (int *)0x0) {
        return 5;
      }
      local_14 = 0;
      if (0 < *(int *)(param_1 + 0x10)) {
        do {
          piVar5[local_14] = *(int *)(*(int *)(param_1 + 8) + local_14 * 4);
          local_14 = local_14 + 1;
        } while ((int)local_14 < *(int *)(param_1 + 0x10));
      }
      for (iVar7 = *(int *)(param_1 + 0x10); iVar7 < (int)uVar8; iVar7 = iVar7 + 1) {
        *(undefined1 *)(piVar5 + iVar7) = 0;
      }
      if (0 < *(int *)(param_1 + 0x10)) {
        iVar7 = *(int *)(param_1 + 0x10) << 2;
        uVar6 = *(undefined4 *)(param_1 + 8);
        goto LAB_0017d09d;
      }
LAB_0017d0a5:
      *(int **)(param_1 + 8) = piVar5;
    }
    else {
      if (uVar9 == 0) {
        sVar2 = (param_2 >> 4) * 4 + 4;
        piVar5 = (int *)_kalloc_noblock(sVar2);
        if (piVar5 == (int *)0x0) {
          return 5;
        }
        _bzero(piVar5,sVar2);
        goto LAB_0017d0a5;
      }
      if (uVar9 * 4 < 0x41) {
        sVar2 = (param_2 >> 4) * 4 + 4;
        piVar5 = (int *)_kalloc_noblock(sVar2);
        if (piVar5 == (int *)0x0) {
          return 5;
        }
        _bzero(piVar5,sVar2);
        iVar7 = _kalloc_noblock(0x40);
        *piVar5 = iVar7;
        if (iVar7 == 0) {
          _kfree(piVar5,sVar2);
          return 5;
        }
        local_14 = 0;
        if (0 < *(int *)(param_1 + 0x10)) {
          do {
            *(undefined4 *)(*piVar5 + local_14 * 4) =
                 *(undefined4 *)(*(int *)(param_1 + 8) + local_14 * 4);
            local_14 = local_14 + 1;
          } while ((int)local_14 < *(int *)(param_1 + 0x10));
        }
        for (uVar9 = *(uint *)(param_1 + 0x10); uVar9 < 0x10; uVar9 = uVar9 + 1) {
          *(undefined1 *)(*piVar5 + uVar9 * 4) = 0;
        }
        iVar7 = *(int *)(param_1 + 0x10) * 4;
        uVar6 = *(undefined4 *)(param_1 + 8);
LAB_0017d09d:
        _kfree(uVar6,iVar7);
        goto LAB_0017d0a5;
      }
      sVar2 = (param_2 >> 4) * 4 + 4;
      if (sVar2 != (uVar9 - 1 >> 4) * 4 + 4) {
        piVar5 = (int *)_kalloc_noblock(sVar2);
        if (piVar5 == (int *)0x0) {
          return 5;
        }
        _bzero(piVar5,sVar2);
        local_14 = 0;
        if (*(int *)(param_1 + 0x10) - 1U >> 4 != 0xffffffff) {
          do {
            piVar5[local_14] = *(int *)(*(int *)(param_1 + 8) + local_14 * 4);
            local_14 = local_14 + 1;
          } while (local_14 < (*(int *)(param_1 + 0x10) - 1U >> 4) + 1);
        }
        iVar7 = (*(int *)(param_1 + 0x10) - 1U >> 4) * 4 + 4;
        uVar6 = *(undefined4 *)(param_1 + 8);
        goto LAB_0017d09d;
      }
    }
    *(uint *)(param_1 + 0x10) = uVar8;
  }
  if ((uint)(*(int *)(param_1 + 0x10) * 4) < 0x41) {
    iVar7 = _vnode_pager_findpage(*(undefined4 *)(param_1 + 4),param_4);
    if (iVar7 != 5) {
      iVar7 = *(int *)(param_1 + 8);
      uVar9 = *param_4;
      goto LAB_0017d157;
    }
  }
  else {
    uVar9 = param_2 >> 4;
    param_2 = param_2 & 0xf;
    if (*(int *)(*(int *)(param_1 + 8) + uVar9 * 4) == 0) {
      uVar6 = _kalloc_noblock(0x40);
      *(undefined4 *)(*(int *)(param_1 + 8) + uVar9 * 4) = uVar6;
      if (*(int *)(*(int *)(param_1 + 8) + uVar9 * 4) == 0) {
        return 5;
      }
      local_14 = 0;
      do {
        *(undefined1 *)(*(int *)(*(int *)(param_1 + 8) + uVar9 * 4) + local_14 * 4) = 0;
        local_14 = local_14 + 1;
      } while (local_14 < 0x10);
    }
    iVar7 = _vnode_pager_findpage(*(undefined4 *)(param_1 + 4),param_4);
    if (iVar7 != 5) {
      iVar7 = *(int *)(*(int *)(param_1 + 8) + uVar9 * 4);
      uVar9 = *param_4;
LAB_0017d157:
      *(uint *)(iVar7 + param_2 * 4) = uVar9;
      return 0;
    }
  }
  return 5;
}

