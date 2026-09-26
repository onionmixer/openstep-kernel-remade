/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001793b0 */

int __regparm1
_vm_object_copy(int param_1,int *param_2,uint param_3,int param_4,int *param_5,uint *param_6,
               undefined4 *param_7)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  
  if (param_2 == (int *)0x0) {
    *param_5 = 0;
    *param_6 = 0;
  }
  else {
    piVar4 = param_2 + 4;
    do {
      do {
      } while (*piVar4 != 0);
      LOCK();
      iVar1 = *piVar4;
      *piVar4 = 1;
      UNLOCK();
    } while (iVar1 == 1);
    if ((param_2[10] == 0) || ((*(byte *)((int)param_2 + 0x46) & 0x10) != 0)) {
      *(short *)(param_2 + 6) = (short)param_2[6] + 1;
      piVar4 = (int *)*param_2;
      if (param_2 != piVar4) {
        do {
          if ((param_3 <= (uint)piVar4[6]) && ((uint)piVar4[6] < param_3 + param_4)) {
            *(byte *)((int)piVar4 + 0x21) = *(byte *)((int)piVar4 + 0x21) | 4;
          }
          piVar4 = (int *)piVar4[2];
        } while (param_2 != piVar4);
      }
      LOCK();
      iVar1 = param_2[4];
      param_2[4] = 0;
      UNLOCK();
      *param_5 = (int)param_2;
      *param_6 = param_3;
      *param_7 = 1;
      return iVar1;
    }
    _vm_object_collapse(param_2);
    while (iVar1 = param_2[7], iVar1 != 0) {
      LOCK();
      iVar5 = *(int *)(iVar1 + 0x10);
      *(int *)(iVar1 + 0x10) = 1;
      UNLOCK();
      if (iVar5 != 1) {
        if ((*(short *)(iVar1 + 0x1a) == 0) && (*(int *)(iVar1 + 0x28) == 0)) {
          *(short *)(iVar1 + 0x18) = *(short *)(iVar1 + 0x18) + 1;
          LOCK();
          *(undefined4 *)(iVar1 + 0x10) = 0;
          UNLOCK();
          LOCK();
          param_1 = param_2[4];
          param_2[4] = 0;
          UNLOCK();
          *param_5 = iVar1;
          goto LAB_00179587;
        }
        LOCK();
        *(undefined4 *)(iVar1 + 0x10) = 0;
        UNLOCK();
        break;
      }
      piVar4 = param_2 + 4;
      LOCK();
      param_2[4] = 0;
      UNLOCK();
      do {
        do {
        } while (*piVar4 != 0);
        LOCK();
        iVar1 = *piVar4;
        *piVar4 = 1;
        UNLOCK();
      } while (iVar1 == 1);
    }
    LOCK();
    param_2[4] = 0;
    UNLOCK();
    iVar1 = param_2[5];
    iVar5 = _zalloc(_vm_object_zone);
    __vm_object_allocate(iVar1,iVar5);
    while( true ) {
      piVar4 = param_2 + 4;
      do {
        do {
        } while (*piVar4 != 0);
        LOCK();
        iVar1 = *piVar4;
        *piVar4 = 1;
        UNLOCK();
      } while (iVar1 == 1);
      iVar1 = param_2[7];
      if (iVar1 == 0) goto LAB_0017953c;
      LOCK();
      iVar2 = *(int *)(iVar1 + 0x10);
      *(int *)(iVar1 + 0x10) = 1;
      UNLOCK();
      if (iVar2 != 1) break;
      LOCK();
      param_2[4] = 0;
      UNLOCK();
    }
    if ((*(int **)(iVar1 + 0x20) != param_2) || (*(int *)(iVar1 + 0x24) != 0)) {
                    /* WARNING: Subroutine does not return */
      _panic(s_vm_object_copy__copy_shadow_inco_001e0bdb);
    }
    *(short *)(param_2 + 6) = (short)param_2[6] + -1;
    *(int *)(iVar1 + 0x20) = iVar5;
    *(short *)(iVar5 + 0x18) = *(short *)(iVar5 + 0x18) + 1;
    LOCK();
    *(undefined4 *)(iVar1 + 0x10) = 0;
    UNLOCK();
LAB_0017953c:
    uVar3 = *(uint *)(iVar5 + 0x14);
    *(int **)(iVar5 + 0x20) = param_2;
    *(undefined4 *)(iVar5 + 0x24) = 0;
    *(short *)(param_2 + 6) = (short)param_2[6] + 1;
    param_2[7] = iVar5;
    for (piVar4 = (int *)*param_2; param_2 != piVar4; piVar4 = (int *)piVar4[2]) {
      if ((uint)piVar4[6] < uVar3) {
        *(byte *)((int)piVar4 + 0x21) = *(byte *)((int)piVar4 + 0x21) | 4;
      }
    }
    LOCK();
    param_1 = param_2[4];
    param_2[4] = 0;
    UNLOCK();
    *param_5 = iVar5;
LAB_00179587:
    *param_6 = param_3;
  }
  *param_7 = 0;
  return param_1;
}

