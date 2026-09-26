
/* WARNING: Removing unreachable block (ram,0xf00ba7b0) */

undefined8 _zsa_rxint(int param_1,undefined4 param_2)

{
  byte bVar1;
  sword sVar2;
  int *piVar3;
  int iVar4;
  undefined4 unaff_l0;
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
  piVar3 = *(int **)(param_1 + 0x18);
  bVar1 = *(byte *)(*(int *)(param_1 + 0x10) + 2);
  iVar4 = *piVar3;
  if ((bVar1 == 0) && ((*(byte *)((int)piVar3 + 0xe) & 0x80) != 0)) goto locret_F00BA7B8;
  sVar2 = *(sword *)(piVar3 + 0x44);
  *(sword *)(piVar3 + 0x44) = sVar2 + 1;
  *(byte *)((int)piVar3 + sVar2 + 0xf) = bVar1;
  if (0xff < *(sword *)(piVar3 + 0x44)) {
    *(undefined2 *)(piVar3 + 0x44) = 0;
  }
  if (*(sword *)(piVar3 + 0x44) == *(sword *)((int)piVar3 + 0x112)) {
    *(sword *)(piVar3 + 2) = *(sword *)(piVar3 + 2) + 1;
    sVar2 = *(sword *)(piVar3 + 3);
  }
  else {
    sVar2 = *(sword *)(piVar3 + 3);
  }
  *(sword *)(piVar3 + 3) = sVar2 + 1;
  if ((*(word *)(iVar4 + 0x38) & 0x1f) == 3) {
loc_F00BA78C:
    *(undefined2 *)(piVar3 + 1) = 0;
  }
  else {
    if ((bVar1 & 0x7f) != (int)*(char *)(iVar4 + 0x52)) {
      sVar2 = *(sword *)(piVar3 + 1);
      *(sword *)(piVar3 + 1) = sVar2 + 1;
      if ((sword)(sVar2 + 1) < 0x15) goto locret_F00BA7B8;
      goto loc_F00BA78C;
    }
    *(undefined2 *)(piVar3 + 1) = 0;
  }
  *(byte *)(param_1 + 0x30) = *(byte *)(param_1 + 0x30) | 1;
  if (_zssoftpend == 0) {
    _zssoftpend = 1;
    _setzssoft();
  }
locret_F00BA7B8:
  return CONCAT44(param_2,param_1);
}

