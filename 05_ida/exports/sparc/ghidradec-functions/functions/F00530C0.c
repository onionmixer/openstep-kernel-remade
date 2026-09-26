
/* WARNING: Removing unreachable block (ram,0xf00531b4) */
/* WARNING: Removing unreachable block (ram,0xf0053194) */
/* WARNING: Removing unreachable block (ram,0xf0053144) */
/* WARNING: Removing unreachable block (ram,0xf0053154) */
/* WARNING: Removing unreachable block (ram,0xf0053184) */
/* WARNING: Removing unreachable block (ram,0xf0053218) */
/* WARNING: Removing unreachable block (ram,0xf0053124) */

undefined8 sub_F00530C0(int param_1,int param_2,int *param_3)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 unaff_l0;
  uint *puVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar5;
  undefined4 uVar6;
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
  iVar5 = *(int *)(param_1 + 0x30);
  if (param_2 < 0xc) {
    iVar3 = *(int *)(iVar5 + 0x50);
    if (*(uint *)(iVar5 + 0x70) <
        (uint)(param_2 + 1 << ((byte)*(undefined4 *)(iVar3 + 0x50) & 0x1f))) {
      puVar4 = (uint *)(((*(uint *)(iVar5 + 0x70) & ~*(uint *)(iVar3 + 0x48)) +
                        *(int *)(iVar3 + 0x34)) - 1 & *(uint *)(iVar3 + 0x4c));
      goto loc_F0053114;
    }
  }
  puVar4 = *(uint **)(*(int *)(iVar5 + 0x50) + 0x30);
loc_F0053114:
  iVar3 = iVar5;
  _bmap(iVar5,param_2,1,0,0);
  iVar3 = iVar3 << ((byte)*(undefined4 *)(*(int *)(iVar5 + 0x50) + 100) & 0x1f);
  if (iVar3 < 0) {
    _geteblk();
    _bzero(puVar4[8],puVar4[5]);
    puVar4[10] = 0;
  }
  else {
    puVar1 = *(uint **)(iVar5 + 0x40);
    if (*(int *)(iVar5 + 0x58) + 1 == param_2) {
      _breada(puVar1,iVar3,puVar4,_rablock,_rasize);
      puVar4 = puVar1;
    }
    else {
      _bread(puVar1,iVar3,puVar4);
      puVar4 = puVar1;
    }
  }
  *(int *)(iVar5 + 0x58) = param_2;
  *(word *)(iVar5 + 0x44) = *(word *)(iVar5 + 0x44) | 4;
  _microtime(&_iuniqtime);
  if ((*(word *)(iVar5 + 0x44) & 4) != 0) {
    *(undefined4 *)(iVar5 + 0x74) = _iuniqtime;
  }
  if ((*(word *)(iVar5 + 0x44) & 2) != 0) {
    *(undefined4 *)(iVar5 + 0x7c) = _iuniqtime;
  }
  if ((*(word *)(iVar5 + 0x44) & 0x40) == 0) {
    uVar2 = *puVar4;
  }
  else {
    *(undefined4 *)(iVar5 + 0x4c) = 0;
    *(undefined4 *)(iVar5 + 0x84) = _iuniqtime;
    uVar2 = *puVar4;
  }
  uVar6 = 0;
  if ((uVar2 & 4) == 0) {
    *param_3 = (int)puVar4;
  }
  else {
    _brelse(puVar4);
    uVar6 = 5;
  }
  return CONCAT44(DAT_f0135000,uVar6);
}
