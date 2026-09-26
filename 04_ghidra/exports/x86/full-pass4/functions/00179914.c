/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00179914 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __regparm1 _vm_object_collapse(int param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  undefined *puVar4;
  undefined *puVar5;
  int *piVar6;
  undefined *puVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  
  if (_vm_object_collapse_allowed == 0) {
    return param_1;
  }
  while( true ) {
    if (param_2 == 0) {
      return param_1;
    }
    if (*(short *)(param_2 + 0x44) != 0) {
      return param_1;
    }
    if (*(int *)(param_2 + 0x28) != 0) {
      return param_1;
    }
    piVar1 = *(int **)(param_2 + 0x20);
    if (piVar1 == (int *)0x0) {
      return param_1;
    }
    piVar6 = piVar1 + 4;
    do {
      do {
      } while (*piVar6 != 0);
      LOCK();
      iVar9 = *piVar6;
      *piVar6 = 1;
      UNLOCK();
    } while (iVar9 == 1);
    if (((piVar1[0x11] & 0x10ffffU) != 0x100000) ||
       ((piVar1[8] != 0 && (*(int *)(piVar1[8] + 0x1c) != 0)))) break;
    uVar2 = *(uint *)(param_2 + 0x24);
    uVar3 = *(uint *)(param_2 + 0x14);
    if ((short)piVar1[6] == 1) {
      while ((int *)*piVar1 != piVar1) {
        iVar9 = *piVar1;
        uVar10 = *(uint *)(iVar9 + 0x18) - uVar2;
        if ((*(uint *)(iVar9 + 0x18) < uVar2) || (uVar3 <= uVar10)) {
          do {
          } while (_vm_page_queue_lock != 0);
          LOCK();
          UNLOCK();
LAB_00179a33:
          _vm_page_queue_lock = 1;
          _vm_page_free(iVar9);
          LOCK();
          _vm_page_queue_lock = 0;
          UNLOCK();
        }
        else {
          iVar8 = _vm_page_lookup(param_2,uVar10);
          if (iVar8 != 0) {
            do {
            } while (_vm_page_queue_lock != 0);
            LOCK();
            UNLOCK();
            goto LAB_00179a33;
          }
          _vm_page_rename(iVar9,param_2,uVar10);
        }
      }
      *(int *)(param_2 + 0x28) = piVar1[10];
      *(uint *)(param_2 + 0x2c) = uVar2 + piVar1[0xb];
      piVar1[10] = 0;
      piVar1[0xc] = 0;
      piVar1[0xd] = 0;
      *(int *)(param_2 + 0x20) = piVar1[8];
      *(int *)(param_2 + 0x24) = *(int *)(param_2 + 0x24) + piVar1[9];
      if ((*(int *)(param_2 + 0x20) != 0) && (*(int *)(*(int *)(param_2 + 0x20) + 0x1c) != 0)) {
                    /* WARNING: Subroutine does not return */
        _panic(s_vm_object_collapse__we_collapsed_001e0c60);
      }
      LOCK();
      piVar1[4] = 0;
      UNLOCK();
      do {
      } while (_vm_object_list_lock != 0);
      LOCK();
      UNLOCK();
      puVar4 = (undefined *)piVar1[2];
      puVar5 = (undefined *)piVar1[3];
      puVar7 = puVar5;
      if (puVar4 != &_vm_object_list) {
        *(undefined **)(puVar4 + 0xc) = puVar5;
        puVar7 = DAT_001f7354;
      }
      DAT_001f7354 = puVar7;
      if (puVar5 != &_vm_object_list) {
        *(undefined **)(puVar5 + 8) = puVar4;
        puVar4 = __vm_object_list;
      }
      __vm_object_list = puVar4;
      __vm_object_count = __vm_object_count + -1;
      LOCK();
      _vm_object_list_lock = 0;
      UNLOCK();
      param_1 = _zfree(_vm_object_zone,piVar1);
      __object_collapses = __object_collapses + 1;
    }
    else {
      if (piVar1[10] != 0) break;
      for (piVar6 = (int *)*piVar1; piVar1 != piVar6; piVar6 = (int *)piVar6[2]) {
        uVar10 = piVar6[6] - uVar2;
        if (((uVar2 <= (uint)piVar6[6]) && (uVar10 <= uVar3)) &&
           (iVar9 = _vm_page_lookup(param_2,uVar10), iVar9 == 0)) goto LAB_00179b4f;
      }
      iVar9 = piVar1[8];
      *(int *)(param_2 + 0x20) = iVar9;
      if (iVar9 != 0) {
        piVar6 = (int *)(iVar9 + 0x10);
        do {
          do {
          } while (*piVar6 != 0);
          LOCK();
          iVar8 = *piVar6;
          *piVar6 = 1;
          UNLOCK();
        } while (iVar8 == 1);
        *(short *)(iVar9 + 0x18) = *(short *)(iVar9 + 0x18) + 1;
        LOCK();
        *(undefined4 *)(iVar9 + 0x10) = 0;
        UNLOCK();
      }
      *(int *)(param_2 + 0x24) = *(int *)(param_2 + 0x24) + piVar1[9];
      *(short *)(piVar1 + 6) = (short)piVar1[6] + -1;
      LOCK();
      param_1 = piVar1[4];
      piVar1[4] = 0;
      UNLOCK();
      __object_bypasses = __object_bypasses + 1;
    }
  }
LAB_00179b4f:
  LOCK();
  iVar9 = piVar1[4];
  piVar1[4] = 0;
  UNLOCK();
  return iVar9;
}

