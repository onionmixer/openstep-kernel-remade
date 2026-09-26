/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010958c */

int _kill(pid_t param_1,int param_2)

{
  short sVar1;
  int *piVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int extraout_EAX;
  undefined4 uVar7;
  
  iVar5 = DAT_001e875c;
  piVar2 = *(int **)(DAT_001e875c + 0x24);
  uVar4 = piVar2[1];
  if (0x20 < uVar4) {
    *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
    return iVar5;
  }
  iVar5 = *piVar2;
  if (iVar5 < 1) {
    if (iVar5 == -1) {
      uVar7 = 1;
      iVar5 = 0;
    }
    else if (iVar5 == 0) {
      uVar7 = 0;
      iVar5 = 0;
    }
    else {
      uVar7 = 0;
      iVar5 = -*piVar2;
      uVar4 = piVar2[1];
    }
    uVar3 = _killpg1(uVar4,iVar5,uVar7);
    iVar5 = DAT_001e875c;
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar3;
    return iVar5;
  }
  uVar4 = _pfind(iVar5);
  iVar5 = DAT_001e875c;
  if (uVar4 == 0) {
    *(undefined1 *)(DAT_001e875c + 0x68) = 3;
    return iVar5;
  }
  if ((*(byte *)(*_active_u + 0x16) & 2) == 0) {
    if ((*(short *)(_active_u[7] + 2) != 0) &&
       (*(short *)(uVar4 + 0x2c) != *(short *)(_active_u[7] + 2))) goto LAB_00109689;
  }
  else {
    iVar5 = _get_posix_proc((int)*(short *)(uVar4 + 0x30));
    iVar6 = _suser();
    if (iVar6 == 0) {
      sVar1 = *(short *)(_active_u[7] + 2);
      if ((((sVar1 != *(short *)(iVar5 + 4)) && (sVar1 != *(short *)(iVar5 + 6))) &&
          (sVar1 = *(short *)(_active_u[7] + 6), sVar1 != *(short *)(iVar5 + 4))) &&
         (sVar1 != *(short *)(iVar5 + 6))) {
        if (piVar2[1] != 0x13) {
LAB_00109689:
          iVar5 = DAT_001e875c;
          *(undefined1 *)(DAT_001e875c + 0x68) = 1;
          return iVar5;
        }
        iVar5 = _get_posix_proc((int)*(short *)(uVar4 + 0x30));
        iVar5 = *(int *)(iVar5 + 0x10);
        iVar6 = _get_posix_proc((int)*(short *)(*_active_u + 0x30));
        if (*(int *)(iVar5 + 8) != *(int *)(*(int *)(iVar6 + 0x10) + 8)) goto LAB_00109689;
      }
    }
    *(undefined1 *)(DAT_001e875c + 0x68) = 0;
  }
  iVar5 = 0;
  if ((char *)piVar2[1] != (char *)0x0) {
    _psignal(uVar4,(char *)piVar2[1]);
    iVar5 = extraout_EAX;
  }
  return iVar5;
}

