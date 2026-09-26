
/* WARNING: Removing unreachable block (ram,0xf004cca8) */
/* WARNING: Removing unreachable block (ram,0xf004cc6c) */
/* WARNING: Removing unreachable block (ram,0xf004ccc4) */
/* WARNING: Removing unreachable block (ram,0xf004cc44) */

undefined8 _blkatoff(int param_1,uint param_2,int *param_3)

{
  byte bVar1;
  uint uVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  int iVar4;
  uint uVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint *puVar6;
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
  iVar3 = *(int *)(param_1 + 0x50);
  bVar1 = (byte)*(undefined4 *)(iVar3 + 0x50);
  uVar2 = param_2 >> (bVar1 & 0x1f);
  if ((int)uVar2 < 0xc) {
    if (*(uint *)(param_1 + 0x70) < uVar2 + 1 << (bVar1 & 0x1f)) {
      uVar5 = ((*(uint *)(param_1 + 0x70) & ~*(uint *)(iVar3 + 0x48)) + *(int *)(iVar3 + 0x34)) - 1
              & *(uint *)(iVar3 + 0x4c);
    }
    else {
      uVar5 = *(uint *)(iVar3 + 0x30);
    }
  }
  else {
    uVar5 = *(uint *)(iVar3 + 0x30);
  }
  iVar4 = param_1;
  _bmap(param_1,uVar2,1);
  iVar4 = iVar4 << ((byte)*(undefined4 *)(iVar3 + 100) & 0x1f);
  if (iVar4 < 0) {
    sub_F004CD8C(param_1,aNonexixtentDir,param_2);
    *(undefined *)(dword_F0133DDC + 0x38) = 2;
  }
  if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
    puVar6 = *(uint **)(param_1 + 0x40);
    _bread(puVar6,iVar4,uVar5);
    if ((*puVar6 & 4) == 0) {
      if (param_3 != (int *)0x0) {
        *param_3 = puVar6[8] + (param_2 & ~*(uint *)(iVar3 + 0x48));
      }
    }
    else {
      _brelse(puVar6);
      puVar6 = (uint *)0x0;
    }
  }
  else {
    puVar6 = (uint *)0x0;
  }
  return CONCAT44(param_2,puVar6);
}

