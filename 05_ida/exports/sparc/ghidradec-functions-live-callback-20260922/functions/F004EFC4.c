
int _iflush(sword param_1)

{
  sword sVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar2;
  undefined4 unaff_i1;
  int *piVar3;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
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
  iVar2 = 0;
  if (_inode_list == (int *)0x0) {
    return 0;
  }
  sVar1 = *(sword *)((int)_inode_list + 0x46);
  piVar3 = _inode_list;
  do {
    if ((int)sVar1 == (int)param_1) {
      if ((*(word *)(piVar3 + 0x11) & 0x100) == 0) {
        *(int *)(*piVar3 + 4) = piVar3[1];
        *(int *)piVar3[1] = *piVar3;
        *piVar3 = (int)piVar3;
        piVar3[1] = (int)piVar3;
      }
      else {
        iVar2 = -1;
      }
loc_F004F070:
      piVar3 = (int *)piVar3[2];
    }
    else if ((*(word *)(piVar3 + 0x11) & 0x100) == 0) {
      piVar3 = (int *)piVar3[2];
    }
    else if ((*(word *)(piVar3 + 0x19) & 0xf000) == 0x6000) {
      if (piVar3[0x23] == (int)param_1) {
        if (-1 < iVar2) {
          iVar2 = iVar2 + 1;
        }
        goto loc_F004F070;
      }
      piVar3 = (int *)piVar3[2];
    }
    else {
      piVar3 = (int *)piVar3[2];
    }
    if (piVar3 == (int *)0x0) {
      return iVar2;
    }
    sVar1 = *(sword *)((int)piVar3 + 0x46);
  } while( true );
}

