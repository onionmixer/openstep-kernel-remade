
/* WARNING: Removing unreachable block (ram,0xf000fd20) */

undefined8 _getpriority(undefined4 param_1,undefined4 param_2)

{
  sword sVar1;
  int iVar2;
  int *piVar3;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar5;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  piVar3 = *(int **)(dword_F0133DDC + 0x24);
  iVar4 = 0x15;
  iVar2 = *piVar3;
  if (iVar2 == 1) {
    if (piVar3[1] == 0) {
      piVar3[1] = (int)*(sword *)(*_active_u + 0x2e);
    }
    bVar5 = true;
    if (_allproc != 0) {
      sVar1 = *(sword *)(_allproc + 0x2e);
      iVar2 = _allproc;
      while( true ) {
        if ((int)sVar1 == piVar3[1]) {
          if (*(char *)(iVar2 + 0x15) < iVar4) {
            iVar4 = (int)*(char *)(iVar2 + 0x15);
          }
          iVar2 = *(int *)(iVar2 + 8);
        }
        else {
          iVar2 = *(int *)(iVar2 + 8);
        }
        if (iVar2 == 0) break;
        sVar1 = *(sword *)(iVar2 + 0x2e);
      }
      bVar5 = iVar4 == 0x15;
    }
  }
  else if (iVar2 < 2) {
    if (iVar2 != 0) {
loc_F000FE1C:
      *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
      goto locret_F000FE50;
    }
    iVar2 = piVar3[1];
    if (iVar2 == 0) {
      iVar2 = *_active_u;
    }
    else {
      _pfind();
    }
    if (iVar2 == 0) {
      bVar5 = true;
    }
    else {
      iVar4 = (int)*(char *)(iVar2 + 0x15);
      bVar5 = iVar4 == 0x15;
    }
  }
  else {
    if (iVar2 != 2) goto loc_F000FE1C;
    if (piVar3[1] == 0) {
      piVar3[1] = (int)*(sword *)(_active_u[7] + 2);
    }
    bVar5 = true;
    if (_allproc != 0) {
      sVar1 = *(sword *)(_allproc + 0x2c);
      iVar2 = _allproc;
      while( true ) {
        if ((int)sVar1 == piVar3[1]) {
          if (*(char *)(iVar2 + 0x15) < iVar4) {
            iVar4 = (int)*(char *)(iVar2 + 0x15);
          }
          iVar2 = *(int *)(iVar2 + 8);
        }
        else {
          iVar2 = *(int *)(iVar2 + 8);
        }
        if (iVar2 == 0) break;
        sVar1 = *(sword *)(iVar2 + 0x2c);
      }
      bVar5 = iVar4 == 0x15;
    }
  }
  if (bVar5) {
    *(undefined *)(dword_F0133DDC + 0x38) = 3;
  }
  else {
    *(int *)(dword_F0133DDC + 0x30) = iVar4;
  }
locret_F000FE50:
  return CONCAT44(param_2,param_1);
}

