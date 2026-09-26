/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001403b8 */

int _disksort_remove(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  
  if (DAT_001f50ec == 0) {
    if ((*(byte *)(param_1 + 0xc) & 1) != 0) {
      iVar3 = (*DAT_001f50dc)(param_1);
      if (iVar3 == 0) {
        *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) & 0xfe;
        pcVar4 = DAT_001f50e8;
        goto LAB_0014040b;
      }
      goto LAB_00140410;
    }
LAB_00140428:
    uVar6 = _splbio();
    piVar7 = (int *)(param_1 + 0x24);
    do {
      do {
      } while (*piVar7 != 0);
      LOCK();
      iVar3 = *piVar7;
      *piVar7 = 1;
      UNLOCK();
    } while (iVar3 == 1);
    piVar7 = *(int **)(param_1 + 0x10);
    if ((int *)(param_1 + 0x10) == piVar7) {
      LOCK();
      *(undefined4 *)(param_1 + 0x24) = 0;
      UNLOCK();
      _splx(uVar6);
      iVar5 = 0;
    }
    else {
      do {
        iVar3 = *piVar7;
        if (param_2 == iVar3) {
          *piVar7 = *(int *)(iVar3 + 0xc);
          iVar5 = iVar3;
          if (*(int **)(param_1 + 0x10) == piVar7) {
            *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) & 0xf7;
            *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(iVar3 + 0x38);
          }
          break;
        }
        if (*(int *)(iVar3 + 0xc) != 0) {
          do {
            iVar5 = *(int *)(iVar3 + 0xc);
            if (param_2 == iVar5) break;
            iVar3 = iVar5;
          } while (*(int *)(iVar5 + 0xc) != 0);
          if (*(int *)(iVar3 + 0xc) != 0) {
            iVar1 = *(int *)(param_2 + 0xc);
            *(int *)(iVar3 + 0xc) = iVar1;
            iVar5 = param_2;
            if (iVar1 == 0) {
              piVar7[1] = iVar3;
            }
            break;
          }
        }
        piVar7 = (int *)piVar7[4];
        iVar5 = iVar3;
      } while ((int *)(param_1 + 0x10) != piVar7);
      while (((piVar7 = *(int **)(param_1 + 0x10), (*(byte *)(param_1 + 0xc) & 8) == 0 &&
              ((int *)(param_1 + 0x10) != piVar7)) && (*piVar7 == 0))) {
        piVar2 = (int *)piVar7[4];
        iVar3 = piVar7[5];
        if ((int *)(param_1 + 0x10) == piVar2) {
          *(int *)(param_1 + 0x14) = iVar3;
        }
        else {
          piVar2[5] = iVar3;
        }
        if (iVar3 == param_1 + 0x10) {
          *(int **)(param_1 + 0x10) = piVar2;
        }
        else {
          *(int **)(iVar3 + 0x10) = piVar2;
        }
        _kfree(piVar7,0x18);
        *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
      }
      LOCK();
      *(undefined4 *)(param_1 + 0x24) = 0;
      UNLOCK();
      _splx(uVar6);
    }
  }
  else {
    if ((*(byte *)(param_1 + 0xc) & 1) == 0) {
      if (*(int *)(param_1 + 0x10) == param_1 + 0x10) {
        *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) | 1;
        pcVar4 = DAT_001f50e4;
LAB_0014040b:
        (*pcVar4)(param_1);
      }
LAB_00140410:
      if ((*(byte *)(param_1 + 0xc) & 1) == 0) goto LAB_00140428;
    }
    iVar5 = (*DAT_001f50e0)(param_1,param_2);
  }
  return iVar5;
}

