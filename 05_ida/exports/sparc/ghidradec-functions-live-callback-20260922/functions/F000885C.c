
undefined8 _rpause(undefined4 param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar3;
  undefined4 unaff_i1;
  int iVar4;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  iVar4 = _active_u;
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
  if ((*piVar3 != 0x1c) || (piVar3[1] != 0x7fffffff)) goto loc_F00088F8;
  iVar2 = piVar3[2];
  bVar1 = *(byte *)(_active_u + 0x25c);
  piVar3 = (int *)(bVar1 & 8);
  if (iVar2 == 1) {
    *(byte *)(_active_u + 0x25c) = bVar1 & 0xf7;
  }
  else {
    param_2 = _active_u;
    if (iVar2 < 2) {
      if (iVar2 != 0) {
loc_F00088F8:
        *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
        iVar4 = param_2;
        goto locret_F0008928;
      }
    }
    else {
      if (iVar2 != 2) goto loc_F00088F8;
      *(byte *)(_active_u + 0x25c) = bVar1 | 8;
    }
  }
  if ((bVar1 & 8) == 0) {
    *(undefined4 *)(dword_F0133DDC + 0x30) = 0;
  }
  else {
    *(undefined4 *)(dword_F0133DDC + 0x30) = 0x7fffffff;
  }
locret_F0008928:
  return CONCAT44(iVar4,piVar3);
}

