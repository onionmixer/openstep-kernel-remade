
/* WARNING: Removing unreachable block (ram,0xf00ba5fc) */

undefined8 _zsa_txint(int param_1,undefined4 param_2)

{
  sword sVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
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
  iVar3 = *(int *)(param_1 + 0x18);
  pbVar4 = *(byte **)(param_1 + 0x10);
  if (*(sword *)(iVar3 + 0x118) < 1) {
    sVar1 = *(sword *)(iVar3 + 0xc);
  }
  else {
    if ((*pbVar4 & 4) != 0) {
      pbVar2 = *(byte **)(iVar3 + 0x114);
      *(byte **)(iVar3 + 0x114) = pbVar2 + 1;
      pbVar4[2] = *pbVar2;
      *(sword *)(iVar3 + 0x118) = *(sword *)(iVar3 + 0x118) + -1;
      goto locret_F00BA604;
    }
    sVar1 = *(sword *)(iVar3 + 0xc);
  }
  *(sword *)(iVar3 + 0xc) = sVar1 + 1;
  *pbVar4 = 0x28;
  *(byte *)(param_1 + 0x30) = *(byte *)(param_1 + 0x30) | 1;
  if (_zssoftpend == 0) {
    _zssoftpend = 1;
    _setzssoft();
  }
locret_F00BA604:
  return CONCAT44(param_2,param_1);
}
