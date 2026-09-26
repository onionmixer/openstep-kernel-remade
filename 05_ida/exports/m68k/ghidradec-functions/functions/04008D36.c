
void _kill(void)

{
  int *piVar1;
  sword sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined uVar6;
  uint uVar7;
  undefined4 uVar8;
  
  piVar1 = *(int **)(dword_40B57D4 + 0x24);
  uVar7 = piVar1[1];
  if (0x20 < uVar7) {
    *(undefined *)(dword_40B57D4 + 100) = 0x16;
    return;
  }
  iVar3 = *piVar1;
  if (iVar3 < 1) {
    if (iVar3 == -1) {
      uVar8 = 1;
      iVar3 = 0;
    }
    else if (iVar3 == 0) {
      uVar8 = 0;
      iVar3 = 0;
    }
    else {
      uVar8 = 0;
      iVar3 = -*piVar1;
      uVar7 = piVar1[1];
    }
    uVar6 = _killpg1(uVar7,iVar3,uVar8);
    *(undefined *)(dword_40B57D4 + 100) = uVar6;
    return;
  }
  iVar3 = _pfind(iVar3);
  if (iVar3 == 0) {
    *(undefined *)(dword_40B57D4 + 100) = 3;
    return;
  }
  if ((*(byte *)(*_active_u + 0x16) & 0x40) == 0) {
    sVar2 = *(sword *)(*(int *)((int)_active_u + 0x1a) + 2);
    if ((sVar2 != 0) && (sVar2 != *(sword *)(iVar3 + 0x2c))) goto loc_4008E34;
  }
  else {
    iVar4 = _get_posix_proc((int)*(sword *)(iVar3 + 0x30));
    iVar5 = _suser();
    if (iVar5 == 0) {
      sVar2 = *(sword *)(*(int *)((int)_active_u + 0x1a) + 2);
      if ((((sVar2 != *(sword *)(iVar4 + 4)) && (sVar2 != *(sword *)(iVar4 + 6))) &&
          (sVar2 = *(sword *)(*(int *)((int)_active_u + 0x1a) + 6), sVar2 != *(sword *)(iVar4 + 4)))
         && (sVar2 != *(sword *)(iVar4 + 6))) {
        if (piVar1[1] != 0x13) {
loc_4008E34:
          *(undefined *)(dword_40B57D4 + 100) = 1;
          return;
        }
        iVar4 = _get_posix_proc((int)*(sword *)(iVar3 + 0x30));
        iVar4 = *(int *)(iVar4 + 0xe);
        iVar5 = _get_posix_proc((int)*(sword *)(*_active_u + 0x30));
        if (*(int *)(iVar4 + 8) != *(int *)(*(int *)(iVar5 + 0xe) + 8)) goto loc_4008E34;
      }
    }
    *(undefined *)(dword_40B57D4 + 100) = 0;
  }
  if (piVar1[1] != 0) {
    _psignal(iVar3,piVar1[1]);
  }
  return;
}
