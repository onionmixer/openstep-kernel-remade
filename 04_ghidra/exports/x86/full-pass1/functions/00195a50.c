/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00195a50 */

uint FUN_00195a50(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  bVar2 = false;
  uVar5 = *(uint *)(param_3 + 8);
  if (uVar5 == 0x36) {
    DAT_001e7758 = (int)*(char *)(param_3 + 0xc);
    *(undefined4 *)(param_3 + 8) = 0;
  }
  else if (uVar5 < 0x37) {
    if (uVar5 == 0x1d) {
      DAT_001e774c = (int)*(char *)(param_3 + 0xc);
      *(undefined4 *)(param_3 + 8) = 0;
    }
    else {
      if (uVar5 != 0x2a) goto LAB_00195b0c;
      DAT_001e7754 = (int)*(char *)(param_3 + 0xc);
      *(undefined4 *)(param_3 + 8) = 0;
    }
  }
  else if (uVar5 == 0x60) {
    DAT_001e7750 = (int)*(char *)(param_3 + 0xc);
    *(undefined4 *)(param_3 + 8) = 0;
  }
  else if (uVar5 < 0x61) {
    if (uVar5 == 0x38) {
      DAT_001e775c = (int)*(char *)(param_3 + 0xc);
      *(undefined4 *)(param_3 + 8) = 0;
    }
    else {
LAB_00195b0c:
      bVar2 = true;
    }
  }
  else {
    if (uVar5 != 0x61) goto LAB_00195b0c;
    DAT_001e7760 = (int)*(char *)(param_3 + 0xc);
    *(undefined4 *)(param_3 + 8) = 0;
  }
  if (bVar2) {
    uVar5 = 0;
    if ((DAT_001e7758 != 0) || (DAT_001e7754 != 0)) {
      uVar5 = 1;
    }
    if ((DAT_001e774c == 0) && (DAT_001e7750 == 0)) {
      iVar3 = 0;
    }
    else {
      iVar3 = 0xdc;
    }
    uVar4 = (uint)*(ushort *)(&_ascii + ((*(int *)(param_3 + 8) * 2 | uVar5) + iVar3) * 2);
    if ((DAT_001e7760 == 0) && (DAT_001e775c == 0)) {
      uVar6 = 0;
    }
    else {
      uVar6 = 0x80;
    }
    uVar5 = uVar4 - 0x101;
    switch(uVar5) {
    case 0:
    case 1:
    case 3:
    case 5:
    case 6:
    case 7:
      break;
    default:
      uVar4 = uVar4 | uVar6;
    }
    if (*(char *)(param_3 + 0xc) != '\0') goto LAB_00195bbf;
  }
  uVar4 = 0x100;
LAB_00195bbf:
  if (uVar4 != 0x100) {
    if ((*(byte *)(param_1 + 0x124) & 1) == 0) {
      uVar5 = (*(code *)(&PTR__ttyinput_001daffc)[DAT_001e9817 * 0xc])(uVar4,&_cons);
    }
    else {
      piVar1 = (int *)(param_1 + 0x170);
      do {
        do {
        } while (*piVar1 != 0);
        LOCK();
        iVar3 = *piVar1;
        *piVar1 = 1;
        UNLOCK();
      } while (iVar3 == 1);
      iVar3 = *(int *)(param_1 + 0x168) + 1;
      if (iVar3 == 0x10) {
        iVar3 = 0;
      }
      if (*(int *)(param_1 + 0x16c) != iVar3) {
        *(uint *)(param_1 + 0x128 + *(int *)(param_1 + 0x168) * 4) = uVar4;
        iVar3 = *(int *)(param_1 + 0x168) + 1;
        if (iVar3 == 0x10) {
          iVar3 = 0;
        }
        *(int *)(param_1 + 0x168) = iVar3;
        _thread_wakeup_prim(param_1 + 0x128,0,0);
      }
      LOCK();
      uVar5 = *(uint *)(param_1 + 0x170);
      *(uint *)(param_1 + 0x170) = 0;
      UNLOCK();
    }
  }
  return uVar5;
}

