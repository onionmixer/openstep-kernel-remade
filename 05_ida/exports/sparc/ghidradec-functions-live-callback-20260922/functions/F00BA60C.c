
/* WARNING: Removing unreachable block (ram,0xf00ba6b4) */
/* WARNING: Removing unreachable block (ram,0xf00ba674) */

undefined8 _zsa_xsint(int param_1,undefined4 param_2)

{
  byte bVar1;
  byte bVar2;
  sword sVar3;
  byte *pbVar4;
  int iVar5;
  undefined4 unaff_l0;
  int *piVar6;
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
  pbVar4 = *(byte **)(param_1 + 0x10);
  piVar6 = *(int **)(param_1 + 0x18);
  bVar1 = *pbVar4;
  bVar2 = *(byte *)((int)piVar6 + 0xe);
  iVar5 = *piVar6;
  *(byte *)((int)piVar6 + 0xe) = bVar1;
  *pbVar4 = 0x10;
  if (((bVar1 ^ bVar2) & 0x80) != 0) {
    if ((bVar1 & 0x80) != 0) {
      sVar3 = *(sword *)(piVar6 + 3);
      goto loc_F00BA680;
    }
    *(sword *)((int)piVar6 + 6) = *(sword *)((int)piVar6 + 6) + 1;
    *pbVar4 = 0x30;
    if ((*(word *)(iVar5 + 0x38) & 0x1f) != 2) {
      sVar3 = *(sword *)(piVar6 + 3);
      goto loc_F00BA680;
    }
    _prom_enter_mon();
  }
  sVar3 = *(sword *)(piVar6 + 3);
loc_F00BA680:
  *(sword *)(piVar6 + 3) = sVar3 + 1;
  *(sword *)((int)piVar6 + 10) = *(sword *)((int)piVar6 + 10) + 1;
  *(byte *)(param_1 + 0x30) = *(byte *)(param_1 + 0x30) | 1;
  if (_zssoftpend == 0) {
    _zssoftpend = 1;
    _setzssoft();
  }
  return CONCAT44(param_2,param_1);
}

