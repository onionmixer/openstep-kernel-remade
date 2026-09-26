
/* WARNING: Removing unreachable block (ram,0xf000fec4) */
/* WARNING: Removing unreachable block (ram,0xf000ffac) */
/* WARNING: Removing unreachable block (ram,0xf000fee0) */
/* WARNING: Removing unreachable block (ram,0xf000ff40) */

undefined8 _setpriority(undefined4 param_1,undefined4 param_2)

{
  sword sVar1;
  int iVar2;
  undefined uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar4;
  int iVar5;
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
  bool bVar6;
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
  piVar4 = *(int **)(dword_F0133DDC + 0x24);
  iVar5 = 0;
  iVar2 = *piVar4;
  if (iVar2 == 1) {
    if (piVar4[1] == 0) {
      piVar4[1] = (int)*(sword *)(*_active_u + 0x2e);
    }
    bVar6 = true;
    if (_allproc != 0) {
      sVar1 = *(sword *)(_allproc + 0x2e);
      iVar2 = _allproc;
      while( true ) {
        if ((int)sVar1 == piVar4[1]) {
          iVar5 = iVar5 + 1;
          _donice(iVar2,piVar4[2]);
          iVar2 = *(int *)(iVar2 + 8);
        }
        else {
          iVar2 = *(int *)(iVar2 + 8);
        }
        if (iVar2 == 0) break;
        sVar1 = *(sword *)(iVar2 + 0x2e);
      }
      bVar6 = iVar5 == 0;
    }
loc_F000FFDC:
    if (!bVar6) goto locret_F000FFF0;
    uVar3 = 3;
  }
  else {
    if (iVar2 < 2) {
      if (iVar2 == 0) {
        iVar2 = piVar4[1];
        if (iVar2 == 0) {
          iVar2 = *_active_u;
        }
        else {
          _pfind();
        }
        if (iVar2 == 0) {
          bVar6 = true;
        }
        else {
          _donice(iVar2,piVar4[2]);
          bVar6 = false;
        }
        goto loc_F000FFDC;
      }
    }
    else if (iVar2 == 2) {
      if (piVar4[1] == 0) {
        piVar4[1] = (int)*(sword *)(_active_u[7] + 2);
      }
      bVar6 = true;
      if (_allproc != 0) {
        sVar1 = *(sword *)(_allproc + 0x2c);
        iVar2 = _allproc;
        while( true ) {
          if ((int)sVar1 == piVar4[1]) {
            iVar5 = iVar5 + 1;
            _donice(iVar2,piVar4[2]);
            iVar2 = *(int *)(iVar2 + 8);
          }
          else {
            iVar2 = *(int *)(iVar2 + 8);
          }
          if (iVar2 == 0) break;
          sVar1 = *(sword *)(iVar2 + 0x2c);
        }
        bVar6 = iVar5 == 0;
      }
      goto loc_F000FFDC;
    }
    uVar3 = 0x16;
  }
  *(undefined *)(dword_F0133DDC + 0x38) = uVar3;
locret_F000FFF0:
  return CONCAT44(param_2,param_1);
}

