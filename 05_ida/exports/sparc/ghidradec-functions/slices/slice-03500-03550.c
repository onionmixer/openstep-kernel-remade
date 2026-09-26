/* GHIDRADEC_FUNCTION index=3500 start=0xf0052e84 */

/* WARNING: Removing unreachable block (ram,0xf0052f5c) */
/* WARNING: Removing unreachable block (ram,0xf0052f44) */
/* WARNING: Removing unreachable block (ram,0xf0052ec8) */
/* WARNING: Removing unreachable block (ram,0xf0052ef8) */
/* WARNING: Removing unreachable block (ram,0xf0052f80) */
/* WARNING: Removing unreachable block (ram,0xf0052eb4) */

undefined8 sub_F0052E84(int param_1,undefined *param_2,undefined4 *param_3,undefined *param_4)

{
  int iVar1;
  int iVar2;
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
  undefined auStackX_0 [92];
  
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
  *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
  *param_3 = 5;
  *(undefined2 *)(param_3 + 0xe) = 0;
  iVar1 = *(int *)(param_1 + 0x30);
  _direnter(iVar1,param_2,0,0,0,param_3,(undefined *)((int)register0x00000038 + -0xc));
  if (iVar1 == 0) {
    param_2 = param_4;
    _strlen();
    if ((param_2 < (undefined *)0x3c) && (_dosymlink != 0)) {
      _bcopy(param_4,*(int *)((int)register0x00000038 + -0xc) + 0x8c,param_2);
      iVar2 = *(int *)((int)register0x00000038 + -0xc);
      *(uint *)(iVar2 + 200) = *(uint *)(iVar2 + 200) | 1;
      *(undefined **)(*(int *)(iVar2 + 0xc) + 0x14) = param_2;
      *(undefined **)(iVar2 + 0x70) = param_2;
      *(word *)(iVar2 + 0x44) = *(word *)(iVar2 + 0x44) | 0x42;
    }
    else {
      iVar1 = 1;
      _rdwri(1,*(undefined4 *)((int)register0x00000038 + -0xc),param_4,param_2,0,1,0);
    }
  }
  else if (iVar1 != 0x11) {
    iVar2 = *(int *)(param_1 + 0x30);
    goto loc_F0052F68;
  }
  _iput(*(undefined4 *)((int)register0x00000038 + -0xc));
  iVar2 = *(int *)(param_1 + 0x30);
loc_F0052F68:
  if ((*(word *)(iVar2 + 0x44) & 0x46) != 0) {
    *(word *)(iVar2 + 0x44) = *(word *)(iVar2 + 0x44) | 8;
    param_2 = DAT_f0135000;
    _microtime(&_iuniqtime);
    iVar2 = *(int *)(param_1 + 0x30);
    if ((*(word *)(iVar2 + 0x44) & 4) != 0) {
      *(undefined4 *)(iVar2 + 0x74) = _iuniqtime;
      iVar2 = *(int *)(param_1 + 0x30);
    }
    if ((*(word *)(iVar2 + 0x44) & 2) != 0) {
      *(undefined4 *)(iVar2 + 0x7c) = _iuniqtime;
    }
    if ((*(word *)(*(int *)(param_1 + 0x30) + 0x44) & 0x40) == 0) {
      iVar2 = *(int *)(param_1 + 0x30);
    }
    else {
      *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x4c) = 0;
      *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x84) = _iuniqtime;
      iVar2 = *(int *)(param_1 + 0x30);
    }
    *(word *)(iVar2 + 0x44) = *(word *)(iVar2 + 0x44) & 0xffb9;
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=3501 start=0xf0053070 */

/* WARNING: Removing unreachable block (ram,0xf00530a0) */

sqword sub_F0053070(int param_1,uint param_2,undefined4 *param_3,int *param_4)

{
  int iVar1;
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
  iVar2 = *(int *)(param_1 + 0x30);
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(iVar2 + 0x40);
  }
  if (param_4 != (int *)0x0) {
    iVar1 = iVar2;
    _bmap(iVar2,param_2,1,0,0);
    *param_4 = iVar1 << ((byte)*(undefined4 *)(*(int *)(iVar2 + 0x50) + 100) & 0x1f);
  }
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=3502 start=0xf00530c0 */

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
/* GHIDRADEC_FUNCTION index=3503 start=0xf005322c */

/* WARNING: Removing unreachable block (ram,0xf0053240) */

undefined8 sub_F005322C(undefined4 param_1,uint *param_2)

{
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
  param_2[10] = 0;
  *param_2 = *param_2 | 0x80;
  _brelse();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3504 start=0xf0053250 */

undefined8 sub_F0053250(int param_1,int param_2)

{
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
  return CONCAT44(param_2,(uint)(param_1 == param_2));
}
/* GHIDRADEC_FUNCTION index=3505 start=0xf0053268 */

undefined8 sub_F0053268(undefined4 param_1,undefined4 param_2)

{
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
  return CONCAT44(param_2,0x16);
}
/* GHIDRADEC_FUNCTION index=3506 start=0xf0053274 */

/* WARNING: Removing unreachable block (ram,0xf005327c) */

undefined8 sub_F0053274(undefined4 param_1,undefined4 param_2)

{
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
  _panic(aUfsBadop);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3507 start=0xf005328c */

/* WARNING: Removing unreachable block (ram,0xf0053298) */

undefined8 sub_F005328C(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
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
  _lf_lockctl(param_1,param_2,param_3);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3508 start=0xf00532a8 */

/* WARNING: Removing unreachable block (ram,0xf00532b8) */
/* WARNING: Removing unreachable block (ram,0xf00532ac) */

sqword sub_F00532A8(int param_1,undefined4 *param_2)

{
  undefined2 *puVar1;
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
  puVar1 = (undefined2 *)0xc;
  _kalloc();
  _bzero();
  *puVar1 = 10;
  *(undefined4 *)(puVar1 + 2) = *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x48);
  *(undefined4 *)(puVar1 + 4) = *(undefined4 *)(*(int *)(param_1 + 0x30) + 0xd0);
  *param_2 = puVar1;
  return ZEXT48(param_2) << 0x20;
}
/* GHIDRADEC_FUNCTION index=3509 start=0xf00532ec */

/* WARNING: Removing unreachable block (ram,0xf0053368) */
/* WARNING: Removing unreachable block (ram,0xf0053320) */
/* WARNING: Removing unreachable block (ram,0xf0053394) */
/* WARNING: Removing unreachable block (ram,0xf0053344) */

undefined8 sub_F00532EC(uint *param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  word wVar3;
  undefined4 unaff_l0;
  uint uVar4;
  undefined4 unaff_l1;
  undefined4 uVar5;
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
  undefined auStackX_0 [92];
  
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
  uVar1 = param_1[0x10];
  (**(code **)(*(int *)(uVar1 + 0x1c) + 0x80))();
  bVar6 = (*param_1 & 1) == 0;
  if (bVar6) {
    uVar2 = param_1[9];
    uVar5 = *(undefined4 *)(param_1[0x10] + 0x30);
    uVar4 = param_1[8];
    .umul(uVar2,uVar1);
  }
  else {
    uVar2 = param_1[9];
    uVar5 = *(undefined4 *)(param_1[0x10] + 0x30);
    uVar4 = param_1[8];
    .umul(uVar2,uVar1);
  }
  wVar3 = (word)bVar6;
  _rdwri(wVar3,uVar5,uVar4,param_1[5],uVar2,1,(undefined *)((int)register0x00000038 + -0xc));
  *(word *)(param_1 + 7) = wVar3;
  param_1[10] = *(uint *)((int)register0x00000038 + -0xc);
  if (*(sword *)(param_1 + 7) != 0) {
    *param_1 = *param_1 | 4;
  }
  _biodone(param_1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3510 start=0xf00533a4 */

/* WARNING: Removing unreachable block (ram,0xf0053658) */
/* WARNING: Removing unreachable block (ram,0xf0053614) */
/* WARNING: Removing unreachable block (ram,0xf00535e4) */
/* WARNING: Removing unreachable block (ram,0xf00535a8) */
/* WARNING: Removing unreachable block (ram,0xf00534e0) */
/* WARNING: Removing unreachable block (ram,0xf005341c) */
/* WARNING: Removing unreachable block (ram,0xf00534a8) */
/* WARNING: Removing unreachable block (ram,0xf0053518) */
/* WARNING: Removing unreachable block (ram,0xf0053594) */
/* WARNING: Removing unreachable block (ram,0xf00535f0) */
/* WARNING: Removing unreachable block (ram,0xf0053638) */
/* WARNING: Removing unreachable block (ram,0xf00536ac) */
/* WARNING: Removing unreachable block (ram,0xf00533cc) */

undefined8 sub_F00533A4(int *param_1,undefined4 param_2,uint param_3)

{
  undefined uVar1;
  char cVar2;
  word wVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar8;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  int iVar9;
  undefined4 unaff_l5;
  uint uVar10;
  undefined4 unaff_l6;
  uint uVar11;
  undefined4 unaff_l7;
  uint uVar12;
  undefined4 unaff_i0;
  int iVar13;
  undefined4 uVar14;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  uint uVar15;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  iVar8 = param_1[0xc];
  wVar3 = *(word *)(iVar8 + 0x44);
  *(undefined4 *)((int)register0x00000038 + -0xc) = param_2;
  uVar11 = _page_size;
  while (_page_size = uVar11, (wVar3 & 1) != 0) {
    *(word *)(iVar8 + 0x44) = wVar3 | 0x10;
    _sleep(iVar8,10);
    uVar11 = _page_size;
    wVar3 = *(word *)(iVar8 + 0x44);
  }
  iVar9 = *(int *)(iVar8 + 0x50);
  uVar5 = *(uint *)(iVar8 + 0x70);
  iVar13 = 0;
  wVar3 = *(word *)(iVar8 + 0x44);
  *(undefined4 *)((int)register0x00000038 + -0x14) = *(undefined4 *)(iVar8 + 0x40);
  *(word *)(iVar8 + 0x44) = wVar3 | 5;
  uVar15 = *(uint *)(iVar9 + 0x30);
  if (uVar5 < param_3 + uVar11) {
    _vm_page_zero_fill(*(undefined4 *)((int)register0x00000038 + -0xc));
  }
  uVar5 = *(uint *)(iVar9 + 0x48);
  do {
    uVar12 = param_3 & ~uVar5;
    uVar6 = uVar15 - uVar12;
    uVar10 = param_3 >> ((byte)*(undefined4 *)(iVar9 + 0x50) & 0x1f);
    uVar5 = uVar11;
    if (uVar6 < uVar11) {
      uVar5 = uVar6;
    }
    uVar6 = *(uint *)(iVar8 + 0x70) - param_3;
    if (*(uint *)(iVar8 + 0x70) <= param_3) {
      if (iVar13 != 0) {
        wVar3 = *(word *)(iVar8 + 0x44);
        goto loc_F0053684;
      }
      wVar3 = *(word *)(iVar8 + 0x44);
loc_F0053500:
      *(word *)(iVar8 + 0x44) = wVar3 & 0xfffe;
      if ((wVar3 & 0x10) != 0) {
        *(word *)(iVar8 + 0x44) = wVar3 & 0xffee;
        _wakeup(iVar8);
      }
      uVar14 = 1;
      goto locret_F00536B8;
    }
    if (uVar6 < uVar5) {
      uVar5 = uVar6;
    }
    uVar1 = *(undefined *)(dword_F0133DDC + 0x38);
    *(undefined *)(dword_F0133DDC + 0x38) = 0;
    iVar7 = iVar8;
    _bmap(iVar8,uVar10,1,uVar12 + uVar5,0);
    cVar2 = *(char *)(dword_F0133DDC + 0x38);
    iVar7 = iVar7 << ((byte)*(undefined4 *)(iVar9 + 100) & 0x1f);
    *(undefined *)(dword_F0133DDC + 0x38) = uVar1;
    if (cVar2 != 0) {
      *(int *)(*param_1 + 0x34) = (int)cVar2;
      _printf(aIoErrorOnPagei);
      wVar3 = *(word *)(iVar8 + 0x44);
loc_F00535FC:
      *(word *)(iVar8 + 0x44) = wVar3 & 0xfffe;
      if ((wVar3 & 0x10) != 0) {
        *(word *)(iVar8 + 0x44) = wVar3 & 0xffee;
        _wakeup(iVar8);
      }
      uVar14 = 2;
      goto locret_F00536B8;
    }
    if (iVar7 < 0) {
      wVar3 = *(word *)(iVar8 + 0x44);
      goto loc_F0053500;
    }
    if ((int)uVar10 < 0xc) {
      if (*(uint *)(iVar8 + 0x70) < uVar10 + 1 << ((byte)*(undefined4 *)(iVar9 + 0x50) & 0x1f)) {
        uVar6 = ((*(uint *)(iVar8 + 0x70) & ~*(uint *)(iVar9 + 0x48)) + *(int *)(iVar9 + 0x34)) - 1
                & *(uint *)(iVar9 + 0x4c);
      }
      else {
        uVar6 = *(uint *)(iVar9 + 0x30);
      }
    }
    else {
      uVar6 = *(uint *)(iVar9 + 0x30);
    }
    puVar4 = *(uint **)((int)register0x00000038 + -0x14);
    if (*(int *)(iVar8 + 0x58) + 1U == uVar10) {
      _breada(puVar4,iVar7,uVar6,_rablock,_rasize);
    }
    else {
      _bread(puVar4,iVar7,uVar6);
    }
    *(uint *)(iVar8 + 0x58) = uVar10;
    if ((int)(uVar6 - puVar4[10]) < (int)uVar5) {
      uVar5 = uVar6 - puVar4[10];
    }
    if ((*puVar4 & 4) != 0) {
      *(int *)(*param_1 + 0x34) = (int)*(sword *)(puVar4 + 7);
      _brelse(puVar4);
      _printf(aIoErrorOnPagei_0);
      wVar3 = *(word *)(iVar8 + 0x44);
      goto loc_F00535FC;
    }
    _copy_to_phys(puVar4[8] + uVar12,
                  *(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x24) + iVar13,uVar5);
    if (uVar5 == uVar15) {
      *puVar4 = *puVar4 | 0x400000;
    }
    _brelse(puVar4);
    uVar11 = uVar11 - uVar5;
    iVar13 = iVar13 + uVar5;
    param_3 = param_3 + uVar5;
    if (((int)uVar11 < 1) || (uVar5 == 0)) {
      wVar3 = *(word *)(iVar8 + 0x44);
loc_F0053684:
      *(word *)(iVar8 + 0x44) = wVar3 & 0xfffe;
      if ((wVar3 & 0x10) != 0) {
        *(word *)(iVar8 + 0x44) = wVar3 & 0xffee;
        _wakeup(iVar8);
      }
      uVar14 = 0;
locret_F00536B8:
      return CONCAT44(0xfffe,uVar14);
    }
    uVar5 = *(uint *)(iVar9 + 0x48);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=3511 start=0xf00536c0 */

/* WARNING: Removing unreachable block (ram,0xf0053928) */
/* WARNING: Removing unreachable block (ram,0xf0053908) */
/* WARNING: Removing unreachable block (ram,0xf00538a8) */
/* WARNING: Removing unreachable block (ram,0xf0053868) */
/* WARNING: Removing unreachable block (ram,0xf0053830) */
/* WARNING: Removing unreachable block (ram,0xf0053764) */
/* WARNING: Removing unreachable block (ram,0xf00537a4) */
/* WARNING: Removing unreachable block (ram,0xf005381c) */
/* WARNING: Removing unreachable block (ram,0xf0053874) */
/* WARNING: Removing unreachable block (ram,0xf00538d4) */
/* WARNING: Removing unreachable block (ram,0xf00538f8) */
/* WARNING: Removing unreachable block (ram,0xf00539b0) */
/* WARNING: Removing unreachable block (ram,0xf00536e8) */

undefined8 sub_F00536C0(int *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  undefined uVar1;
  char cVar2;
  word wVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar7;
  uint uVar8;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  int iVar9;
  undefined4 unaff_l5;
  uint uVar10;
  undefined4 unaff_l6;
  uint uVar11;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar12;
  undefined4 uVar13;
  undefined4 unaff_i1;
  uint *puVar14;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  iVar7 = param_1[0xc];
  wVar3 = *(word *)(iVar7 + 0x44);
  *(undefined4 *)((int)register0x00000038 + -0xc) = param_2;
  while ((wVar3 & 1) != 0) {
    *(word *)(iVar7 + 0x44) = wVar3 | 0x10;
    _sleep(iVar7,10);
    wVar3 = *(word *)(iVar7 + 0x44);
  }
  iVar12 = 0;
  puVar14 = *(uint **)(iVar7 + 0x40);
  iVar9 = *(int *)(iVar7 + 0x50);
  *(word *)(iVar7 + 0x44) = *(word *)(iVar7 + 0x44) | 1;
  uVar11 = *(uint *)(iVar9 + 0x30);
  uVar4 = *(uint *)(iVar9 + 0x48);
  do {
    uVar10 = param_4 & ~uVar4;
    uVar8 = param_4 >> ((byte)*(undefined4 *)(iVar9 + 0x50) & 0x1f);
    uVar4 = param_3;
    if (uVar11 - uVar10 < param_3) {
      uVar4 = uVar11 - uVar10;
    }
    uVar1 = *(undefined *)(dword_F0133DDC + 0x38);
    *(undefined *)(dword_F0133DDC + 0x38) = 0;
    iVar6 = iVar7;
    _bmap(iVar7,uVar8,0x20,uVar10 + uVar4,0);
    cVar2 = *(char *)(dword_F0133DDC + 0x38);
    iVar6 = iVar6 << ((byte)*(undefined4 *)(iVar9 + 100) & 0x1f);
    *(undefined *)(dword_F0133DDC + 0x38) = uVar1;
    if ((cVar2 != 0) || (iVar6 < 0)) {
      *(int *)(*param_1 + 0x34) = (int)cVar2;
      _printf(aIoErrorOnPageo);
loc_F0053880:
      wVar3 = *(word *)(iVar7 + 0x44);
      *(word *)(iVar7 + 0x44) = wVar3 & 0xfffe;
      if ((wVar3 & 0x10) != 0) {
        *(word *)(iVar7 + 0x44) = wVar3 & 0xffee;
        _wakeup(iVar7);
      }
      uVar13 = 2;
      goto locret_F00539BC;
    }
    if (*(uint *)(iVar7 + 0x70) < param_4 + uVar4) {
      *(uint *)(iVar7 + 0x70) = param_4 + uVar4;
    }
    if ((int)uVar8 < 0xc) {
      if (*(uint *)(iVar7 + 0x70) < uVar8 + 1 << ((byte)*(undefined4 *)(iVar9 + 0x50) & 0x1f)) {
        uVar8 = ((*(uint *)(iVar7 + 0x70) & ~*(uint *)(iVar9 + 0x48)) + *(int *)(iVar9 + 0x34)) - 1
                & *(uint *)(iVar9 + 0x4c);
      }
      else {
        uVar8 = *(uint *)(iVar9 + 0x30);
      }
    }
    else {
      uVar8 = *(uint *)(iVar9 + 0x30);
    }
    puVar5 = puVar14;
    if (uVar4 == uVar11) {
      _getblk(puVar14,iVar6,uVar8);
    }
    else {
      _bread(puVar14,iVar6,uVar8);
    }
    if ((int)(uVar8 - puVar5[10]) < (int)uVar4) {
      uVar4 = uVar8 - puVar5[10];
    }
    if ((*puVar5 & 4) != 0) {
      *(int *)(*param_1 + 0x34) = (int)*(sword *)(puVar5 + 7);
      _brelse(puVar5);
      _printf(aIoErrorOnPageo_0);
      goto loc_F0053880;
    }
    param_3 = param_3 - uVar4;
    param_4 = param_4 + uVar4;
    iVar6 = *(int *)((int)register0x00000038 + -0xc) + iVar12;
    iVar12 = iVar12 + uVar4;
    _copy_from_phys(iVar6,puVar5[8] + uVar10,uVar4);
    if (uVar4 + uVar10 == uVar11) {
      *puVar5 = *puVar5 | 0x400000;
      _bawrite();
      wVar3 = *(word *)(iVar7 + 0x44);
    }
    else {
      _bdwrite(puVar5);
      wVar3 = *(word *)(iVar7 + 0x44);
    }
    *(word *)(iVar7 + 0x44) = wVar3 | 0x42;
    *(word *)(iVar7 + 100) = *(word *)(iVar7 + 100) & 0xf3ff;
    _microtime(&_iuniqtime);
    if ((*(word *)(iVar7 + 0x44) & 4) != 0) {
      *(undefined4 *)(iVar7 + 0x74) = _iuniqtime;
    }
    if ((*(word *)(iVar7 + 0x44) & 2) != 0) {
      *(undefined4 *)(iVar7 + 0x7c) = _iuniqtime;
    }
    if ((*(word *)(iVar7 + 0x44) & 0x40) != 0) {
      *(undefined4 *)(iVar7 + 0x4c) = 0;
      *(undefined4 *)(iVar7 + 0x84) = _iuniqtime;
    }
    if ((param_3 == 0) || (uVar4 == 0)) {
      wVar3 = *(word *)(iVar7 + 0x44);
      *(word *)(iVar7 + 0x44) = wVar3 & 0xfffe;
      if ((wVar3 & 0x10) != 0) {
        *(word *)(iVar7 + 0x44) = wVar3 & 0xffee;
        _wakeup(iVar7);
      }
      uVar13 = 0;
locret_F00539BC:
      return CONCAT44(puVar14,uVar13);
    }
    uVar4 = *(uint *)(iVar9 + 0x48);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=3512 start=0xf005e1a4 */

undefined8
sub_F005E1A4(uint param_1,int param_2,int *param_3,int *param_4,undefined4 *param_5,int *param_6)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
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
  undefined auStackX_0 [92];
  
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
  uVar1 = *(uint *)(param_2 + 0x10);
  puVar3 = *(undefined4 **)((int)register0x00000038 + 0x5c);
joined_r0xf005e1b0:
  if (param_1 == uVar1) {
    *param_3 = param_2;
loc_F005E2B8:
    *param_5 = param_4;
    *puVar3 = param_6;
    return CONCAT44(param_2,param_1);
  }
  if (param_1 < uVar1) {
    iVar2 = *(int *)(param_2 + 0x18);
    if (iVar2 == 0) {
      *param_3 = param_2;
      goto loc_F005E2B8;
    }
    uVar1 = *(uint *)(iVar2 + 0x10);
    if (param_1 < uVar1) {
      if (*(int *)(iVar2 + 0x18) != 0) {
        *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(iVar2 + 0x1c);
        *(int *)(iVar2 + 0x1c) = param_2;
        param_2 = iVar2;
      }
      *param_6 = param_2;
    }
    else {
      *param_6 = param_2;
    }
    param_6 = (int *)(param_2 + 0x18);
    param_2 = *(int *)(param_2 + 0x18);
    if (uVar1 < param_1) {
      if (*(int *)(iVar2 + 0x1c) != 0) {
        *param_4 = param_2;
        param_4 = (int *)(param_2 + 0x1c);
        param_2 = *(int *)(param_2 + 0x1c);
        goto loc_F005E2A4;
      }
      uVar1 = *(uint *)(param_2 + 0x10);
      goto joined_r0xf005e1b0;
    }
  }
  else {
    iVar2 = *(int *)(param_2 + 0x1c);
    if (iVar2 == 0) {
      *param_3 = param_2;
      goto loc_F005E2B8;
    }
    uVar1 = *(uint *)(iVar2 + 0x10);
    if (uVar1 < param_1) {
      if (*(int *)(iVar2 + 0x1c) != 0) {
        *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(iVar2 + 0x18);
        *(int *)(iVar2 + 0x18) = param_2;
        param_2 = iVar2;
      }
      *param_4 = param_2;
    }
    else {
      *param_4 = param_2;
    }
    param_4 = (int *)(param_2 + 0x1c);
    param_2 = *(int *)(param_2 + 0x1c);
    if (param_1 < uVar1) {
      if (*(int *)(iVar2 + 0x18) != 0) {
        *param_6 = param_2;
        param_6 = (int *)(param_2 + 0x18);
        param_2 = *(int *)(param_2 + 0x18);
        goto loc_F005E2A4;
      }
      uVar1 = *(uint *)(param_2 + 0x10);
      goto joined_r0xf005e1b0;
    }
  }
loc_F005E2A4:
  uVar1 = *(uint *)(param_2 + 0x10);
  goto joined_r0xf005e1b0;
}
/* GHIDRADEC_FUNCTION index=3513 start=0xf005e2c8 */

undefined8
sub_F005E2C8(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
            undefined4 *param_5)

{
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
  *param_3 = *(undefined4 *)(param_1 + 0x18);
  *param_5 = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(param_1 + 0x18) = *param_2;
  *(undefined4 *)(param_1 + 0x1c) = *param_4;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3514 start=0xf0068384 */

undefined8 sub_F0068384(undefined4 *param_1)

{
  undefined4 *puVar1;
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
  param_1[2] = 0;
  puVar1 = param_1;
  if ((undefined4 **)dword_F012F674 != &dword_F012F670) {
    *dword_F012F674 = param_1;
    puVar1 = dword_F012F670;
  }
  dword_F012F670 = puVar1;
  param_1[1] = dword_F012F674;
  *param_1 = &dword_F012F670;
  dword_F012F674 = param_1;
  dword_F010FB00 = dword_F010FB00 + 1;
  iRamf013c0c8 = iRamf013c0c8 + 1;
  return CONCAT44(0xf010f800,dword_F010FB00);
}
/* GHIDRADEC_FUNCTION index=3515 start=0xf00683ec */

/* WARNING: Removing unreachable block (ram,0xf0068450) */
/* WARNING: Removing unreachable block (ram,0xf0068508) */
/* WARNING: Removing unreachable block (ram,0xf0068464) */
/* WARNING: Removing unreachable block (ram,0xf00684d8) */

undefined8 sub_F00683EC(uint param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  bool bVar4;
  undefined4 unaff_l0;
  int *piVar5;
  undefined4 unaff_l1;
  int iVar6;
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
  bVar4 = true;
  iVar6 = 0;
  piVar5 = (int *)(param_1 & ~_page_mask);
  piVar3 = piVar5;
  if (0 < dword_F012F67C) {
    do {
      if (piVar3[2] != 0) {
        bVar4 = false;
      }
      iVar6 = iVar6 + 1;
      piVar3 = (int *)((int)piVar3 + dword_F012F678);
    } while (iVar6 < dword_F012F67C);
  }
  if (bVar4) {
    iVar6 = 0;
    if (0 < dword_F012F67C) {
      do {
        iVar2 = *piVar5;
        piVar3 = (int *)piVar5[1];
        *(int **)(iVar2 + 4) = piVar3;
        if (piVar3 != &dword_F012F670) {
          *piVar3 = iVar2;
          iVar2 = dword_F012F670;
        }
        dword_F012F670 = iVar2;
        dword_F010FB00 = dword_F010FB00 + -1;
        iRamf013c0c8 = iRamf013c0c8 + -1;
        _stack_finalize(piVar5 + 3);
        iVar6 = iVar6 + 1;
        piVar5 = (int *)((int)piVar5 + dword_F012F678);
      } while (iVar6 < dword_F012F67C);
    }
    _kmem_free(_kernel_map,param_1,dword_F012F678);
    _stackStats = _stackStats + -1;
  }
  else {
    uVar1 = param_1;
    _canSwap();
    if (uVar1 != 0) {
      _doSwapout(param_1);
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3516 start=0xf0069948 */

/* WARNING: Removing unreachable block (ram,0xf0069970) */
/* WARNING: Removing unreachable block (ram,0xf0069998) */
/* WARNING: Removing unreachable block (ram,0xf006994c) */

undefined8 sub_F0069948(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 unaff_l0;
  undefined4 uVar3;
  undefined4 unaff_l1;
  code *pcVar4;
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
  iVar1 = param_1;
  _splusclock();
  do {
    do {
    } while (dword_F012F680 != 0);
    puVar2 = &dword_F012F680;
    _simple_lock_try();
  } while (puVar2 == (undefined4 *)0x0);
  *(undefined4 *)(param_1 + 0x34) = 0;
  pcVar4 = *(code **)(param_1 + 0x28);
  uVar3 = *(undefined4 *)(param_1 + 0x2c);
  dword_F012F680 = 0;
  _splx(iVar1);
  (*pcVar4)(uVar3);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3517 start=0xf006a3c4 */

undefined8 sub_F006A3C4(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar3;
  int *piVar4;
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
  piVar1 = *(int **)(param_1 + 0x10);
  piVar2 = (int *)(param_1 + 0x1c);
  piVar3 = (int *)0x0;
  piVar4 = piVar3;
  if (piVar1 != (int *)0x0) {
    do {
      piVar3 = (int *)((int)piVar3 + 1);
      piVar4 = piVar2;
      if (*piVar2 == 9) goto locret_F006A40C;
      piVar2 = (int *)((int)piVar2 + piVar2[1]);
    } while (piVar3 < piVar1);
    piVar4 = (int *)0x0;
  }
locret_F006A40C:
  return CONCAT44(piVar1,piVar4);
}
/* GHIDRADEC_FUNCTION index=3518 start=0xf006a498 */

/* WARNING: Removing unreachable block (ram,0xf006a4cc) */
/* WARNING: Removing unreachable block (ram,0xf006a4a4) */

undefined8 sub_F006A498(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar4;
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
  uVar4 = 0;
  iVar1 = param_1;
  _firstsegfromheader();
  while (iVar1 != 0) {
    uVar3 = *(int *)(iVar1 + 0x20) + *(int *)(iVar1 + 0x24);
    if (uVar4 < uVar3) {
      uVar4 = uVar3;
    }
    iVar2 = param_1;
    _nextsegfromheader(param_1,iVar1);
    iVar1 = iVar2;
  }
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=3519 start=0xf006a83c */

/* WARNING: Removing unreachable block (ram,0xf006ab60) */
/* WARNING: Removing unreachable block (ram,0xf006aa5c) */
/* WARNING: Removing unreachable block (ram,0xf006aaa0) */
/* WARNING: Removing unreachable block (ram,0xf006a978) */
/* WARNING: Removing unreachable block (ram,0xf006a904) */
/* WARNING: Removing unreachable block (ram,0xf006a954) */
/* WARNING: Removing unreachable block (ram,0xf006aacc) */
/* WARNING: Removing unreachable block (ram,0xf006aa7c) */
/* WARNING: Removing unreachable block (ram,0xf006aa3c) */
/* WARNING: Removing unreachable block (ram,0xf006ab78) */
/* WARNING: Removing unreachable block (ram,0xf006a86c) */

undefined8
sub_F006A83C(int *param_1,undefined4 param_2,int param_3,undefined4 param_4,uint param_5,int param_6
            )

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 unaff_l0;
  int iVar6;
  undefined4 unaff_l1;
  uint uVar7;
  undefined4 unaff_l3;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 unaff_l4;
  int iVar10;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar11;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar12;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  puVar8 = (undefined4 *)0x0;
  iVar10 = *(int *)((int)register0x00000038 + 0x60);
  if (param_6 < 7) {
    param_6 = param_6 + 1;
    if (*(int *)(param_3 + 4) == dword_F0134764) {
      iVar2 = *(int *)(param_3 + 8);
      _check_cpu_subtype();
      if (iVar2 != 0) {
        switch(*(undefined4 *)(param_3 + 0xc)) {
        case :
        case :
        case :
          if (param_6 != 1) {
            puVar11 = (undefined4 *)0x4;
            goto locret_F006ABA8;
          }
          break;
        case :
        case :
          if (param_6 == 1) {
            puVar11 = (undefined4 *)0x4;
            goto locret_F006ABA8;
          }
          break;
        :
          goto def_F006A8A4;
        case :
          puVar11 = (undefined4 *)0x4;
          if (param_6 != 2) goto locret_F006ABA8;
        }
        piVar3 = param_1;
        _vnode_pager_setup(param_1,0,1);
        if ((param_5 < *(int *)(param_3 + 0x14) + 0x1cU) ||
           (uVar1 = *(int *)(param_3 + 0x14) + _page_mask + 0x1c & ~_page_mask, uVar1 == 0)) {
loc_F006A980:
          puVar11 = (undefined4 *)0x2;
        }
        else {
          *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
          iVar2 = _kernel_map;
          _vm_allocate_with_pager
                    (_kernel_map,(undefined *)((int)register0x00000038 + -0xc),uVar1,1,piVar3,
                     param_4);
          iVar6 = 1;
          if (iVar2 == 0) {
            iVar2 = *(int *)(param_3 + 0x10);
            puVar11 = (undefined4 *)0x0;
            do {
              uVar7 = 0x1c;
              do {
                iVar2 = iVar2 + -1;
                iVar5 = *(int *)((int)register0x00000038 + -0xc);
                if (iVar2 == -1) break;
                puVar4 = (undefined4 *)(iVar5 + uVar7);
                uVar7 = uVar7 + puVar4[1];
                if (*(int *)(param_3 + 0x14) + 0x1cU < uVar7) {
                  _vm_map_remove(_kernel_map,iVar5,iVar5 + uVar1);
                  goto loc_F006A980;
                }
                puVar9 = puVar8;
                switch(*puVar4) {
                case :
                  bVar12 = puVar11 == (undefined4 *)0x0;
                  if (iVar6 == 1) {
                    sub_F006ABB0(puVar4,piVar3,param_4,param_5,*(undefined4 *)(*param_1 + 0x14),
                                 param_2,iVar10);
                    puVar11 = puVar4;
                    break;
                  }
                  goto loc_F006AB0C;
                :
                  puVar11 = (undefined4 *)0x0;
                  break;
                case :
                  bVar12 = puVar11 == (undefined4 *)0x0;
                  if (iVar6 != 2) goto loc_F006AB0C;
                  sub_F006AF04(puVar4,iVar10);
                  puVar11 = puVar4;
                  break;
                case :
                  bVar12 = puVar11 == (undefined4 *)0x0;
                  if (iVar6 != 2) goto loc_F006AB0C;
                  sub_F006AE50(puVar4,iVar10);
                  puVar11 = puVar4;
                  break;
                case :
                  bVar12 = puVar11 == (undefined4 *)0x0;
                  if (iVar6 != 1) goto loc_F006AB0C;
                  sub_F006B130(puVar4,param_2,param_6);
                  puVar11 = puVar4;
                  break;
                case :
                  bVar12 = puVar11 == (undefined4 *)0x0;
                  if (iVar6 != 1) goto loc_F006AB0C;
                  if (*(int *)((int)register0x00000038 + 0x5c) != 0) {
                    sub_F006B1F8(puVar4,*(undefined4 *)((int)register0x00000038 + 0x5c));
                    puVar11 = puVar4;
                  }
                  break;
                case :
                  bVar12 = puVar11 == (undefined4 *)0x0;
                  if (iVar6 != 2) goto loc_F006AB0C;
                  puVar9 = puVar4;
                  if ((param_6 != 1) && (puVar8 != (undefined4 *)0x0)) {
                    puVar9 = puVar8;
                    puVar11 = (undefined4 *)0x4;
                  }
                }
                bVar12 = puVar11 == (undefined4 *)0x0;
                puVar8 = puVar9;
loc_F006AB0C:
              } while (bVar12);
              if ((puVar11 != (undefined4 *)0x0) || (iVar6 = iVar6 + 1, 2 < iVar6))
              goto loc_F006AB44;
              iVar2 = *(int *)(param_3 + 0x10);
            } while( true );
          }
          puVar11 = (undefined4 *)0x5;
        }
        goto locret_F006ABA8;
      }
    }
    puVar11 = (undefined4 *)0x1;
    goto locret_F006ABA8;
  }
def_F006A8A4:
  puVar11 = (undefined4 *)0x4;
locret_F006ABA8:
  return CONCAT44(param_2,puVar11);
loc_F006AB44:
  iVar2 = *(int *)((int)register0x00000038 + -0xc);
  if ((puVar11 == (undefined4 *)0x0) && (puVar8 != (undefined4 *)0x0)) {
    sub_F006B20C(puVar8,param_2,param_6,iVar10);
    iVar2 = *(int *)((int)register0x00000038 + -0xc);
    puVar11 = puVar8;
  }
  _vm_map_remove(_kernel_map,iVar2,iVar2 + uVar1);
  if (((puVar11 != (undefined4 *)0x0) || (param_6 != 1)) || (*(int *)(iVar10 + 0xc) != 0))
  goto locret_F006ABA8;
  goto def_F006A8A4;
}
/* GHIDRADEC_FUNCTION index=3520 start=0xf006abb0 */

/* WARNING: Removing unreachable block (ram,0xf006ae04) */
/* WARNING: Removing unreachable block (ram,0xf006adc8) */
/* WARNING: Removing unreachable block (ram,0xf006ada0) */
/* WARNING: Removing unreachable block (ram,0xf006ad8c) */
/* WARNING: Removing unreachable block (ram,0xf006ad54) */
/* WARNING: Removing unreachable block (ram,0xf006ace8) */
/* WARNING: Removing unreachable block (ram,0xf006ac68) */
/* WARNING: Removing unreachable block (ram,0xf006ac58) */
/* WARNING: Removing unreachable block (ram,0xf006ac88) */
/* WARNING: Removing unreachable block (ram,0xf006ad20) */
/* WARNING: Removing unreachable block (ram,0xf006ad78) */
/* WARNING: Removing unreachable block (ram,0xf006ad38) */
/* WARNING: Removing unreachable block (ram,0xf006acfc) */
/* WARNING: Removing unreachable block (ram,0xf006add4) */
/* WARNING: Removing unreachable block (ram,0xf006ae24) */
/* WARNING: Removing unreachable block (ram,0xf006ac10) */

undefined8 sub_F006ABB0(int param_1,int param_2,int param_3,uint param_4,int param_5,int param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 *puVar6;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar7;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar8;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  puVar6 = *(undefined4 **)((int)register0x00000038 + 0x5c);
  if ((uint)(*(int *)(param_1 + 0x20) + *(int *)(param_1 + 0x24)) <= param_4) {
    uVar1 = *(int *)(param_1 + 0x1c) + _page_mask & ~_page_mask;
    if (-1 < (int)uVar1) {
      if (uVar1 != 0) {
        *(uint *)((int)register0x00000038 + -0xc) = *(uint *)(param_1 + 0x18) & ~_page_mask;
        iVar5 = param_6;
        _vm_map_find(param_6,0,0,(undefined *)((int)register0x00000038 + -0xc),uVar1,0);
        if (iVar5 != 0) {
          uVar7 = 5;
          goto locret_F006AE48;
        }
        iVar5 = *(int *)(param_1 + 0x20);
        uVar2 = *(int *)(param_1 + 0x24) + _page_mask & ~_page_mask;
        if ((int)uVar2 < 0) goto loc_F006AC44;
        if (0 < (int)uVar2) {
          uVar4 = uVar2;
          _pmap_create();
          _vm_map_create();
          *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
          uVar8 = uVar4;
          _vm_allocate_with_pager();
          if (uVar8 == 0) {
            uVar3 = *(uint *)(param_1 + 0x24);
            uVar8 = uVar2;
            if ((uVar2 == uVar3) || ((param_5 != 0 && (iVar5 + param_3 + uVar3 == param_5)))) {
loc_F006ADB4:
              param_2 = param_6;
              _vm_map_copy(param_6,uVar4,*(undefined4 *)((int)register0x00000038 + -0xc),uVar8,
                           *(undefined4 *)((int)register0x00000038 + -0x10),0,0);
              _vm_map_deallocate(uVar4);
              if (param_2 != 0) {
                uVar7 = 4;
                goto locret_F006AE48;
              }
              iVar5 = *(int *)(param_1 + 0x28);
              goto loc_F006ADF0;
            }
            *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
            uVar8 = uVar3 & ~_page_mask;
            iVar5 = _kernel_map;
            _vm_map_find(_kernel_map,0,0,(undefined *)((int)register0x00000038 + -0x14),_page_size,1
                        );
            if (iVar5 == 0) {
              iVar5 = _kernel_map;
              _vm_map_copy(_kernel_map,uVar4,*(undefined4 *)((int)register0x00000038 + -0x14),
                           _page_size,uVar8,0,0);
              if (iVar5 == 0) {
                _bzero(*(int *)((int)register0x00000038 + -0x14) +
                       (*(int *)(param_1 + 0x24) - uVar8),uVar2 - *(int *)(param_1 + 0x24));
                param_2 = param_6;
                _vm_map_copy(param_6,_kernel_map,*(int *)((int)register0x00000038 + -0xc) + uVar8,
                             _page_size,*(undefined4 *)((int)register0x00000038 + -0x14),0,0);
                _vm_deallocate(_kernel_map,*(undefined4 *)((int)register0x00000038 + -0x14),
                               _page_size);
                if (param_2 == 0) goto loc_F006ADB4;
              }
              else {
                _vm_deallocate(_kernel_map,*(undefined4 *)((int)register0x00000038 + -0x14),
                               _page_size);
              }
              _vm_map_deallocate(uVar4);
              uVar7 = 4;
              goto locret_F006AE48;
            }
          }
          _vm_map_deallocate(uVar4);
          uVar7 = 5;
          goto locret_F006AE48;
        }
        iVar5 = *(int *)(param_1 + 0x28);
loc_F006ADF0:
        if (iVar5 != 3) {
          _vm_map_protect(param_6,*(int *)((int)register0x00000038 + -0xc),
                          *(int *)((int)register0x00000038 + -0xc) + uVar1,iVar5,1);
        }
        if (*(int *)(param_1 + 0x2c) != 3) {
          _vm_map_protect(param_6,*(int *)((int)register0x00000038 + -0xc),
                          *(int *)((int)register0x00000038 + -0xc) + uVar1,*(int *)(param_1 + 0x2c),
                          0);
        }
        uVar7 = 0;
        if (*(int *)(param_1 + 0x20) != 0) goto locret_F006AE48;
        *puVar6 = *(undefined4 *)((int)register0x00000038 + -0xc);
      }
      uVar7 = 0;
      goto locret_F006AE48;
    }
  }
loc_F006AC44:
  uVar7 = 2;
locret_F006AE48:
  return CONCAT44(param_2,uVar7);
}
/* GHIDRADEC_FUNCTION index=3521 start=0xf006ae50 */

/* WARNING: Removing unreachable block (ram,0xf006aea8) */
/* WARNING: Removing unreachable block (ram,0xf006aec8) */
/* WARNING: Removing unreachable block (ram,0xf006ae84) */

undefined8 sub_F006AE50(int param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  iVar1 = _active_threads;
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
  if (*(int *)(param_2 + 0xc) == 0) {
    iVar2 = param_1 + 8;
    iVar3 = _active_threads;
    sub_F006B058(_active_threads,iVar2,*(int *)(param_1 + 4) + -8,param_2 + 8);
    if (((iVar3 == 0) &&
        (iVar3 = iVar1, sub_F006B0C4(iVar1,iVar2,*(int *)(param_1 + 4) + -8,param_2 + 4), iVar3 == 0
        )) && (sub_F006AFF0(iVar1,iVar2,*(int *)(param_1 + 4) + -8), iVar3 = iVar1, iVar1 == 0)) {
      iVar3 = 0;
      *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) | 0x80000000;
      *(int *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) + 1;
    }
  }
  else {
    iVar3 = 4;
  }
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=3522 start=0xf006af04 */

/* WARNING: Removing unreachable block (ram,0xf006af94) */
/* WARNING: Removing unreachable block (ram,0xf006af60) */
/* WARNING: Removing unreachable block (ram,0xf006af48) */
/* WARNING: Removing unreachable block (ram,0xf006afd0) */
/* WARNING: Removing unreachable block (ram,0xf006afb8) */
/* WARNING: Removing unreachable block (ram,0xf006af2c) */

undefined8 sub_F006AF04(int param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  int iVar2;
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
  undefined auStackX_0 [92];
  
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
  if (*(int *)(param_2 + 0xc) == 0) {
    *(int *)((int)register0x00000038 + -0xc) = _active_threads;
  }
  else {
    iVar1 = *(int *)(_active_threads + 0xc);
    _thread_create(iVar1,(undefined *)((int)register0x00000038 + -0xc));
    if (iVar1 != 0) {
      iVar1 = 7;
      goto locret_F006AFE8;
    }
    _thread_deallocate(*(undefined4 *)((int)register0x00000038 + -0xc));
  }
  iVar2 = param_1 + 8;
  iVar1 = *(int *)((int)register0x00000038 + -0xc);
  sub_F006AFF0(iVar1,iVar2,*(int *)(param_1 + 4) + -8);
  if (iVar1 == 0) {
    if (*(int *)(param_2 + 0xc) == 0) {
      iVar1 = _active_threads;
      sub_F006B058(_active_threads,iVar2,*(int *)(param_1 + 4) + -8,param_2 + 8);
      if ((iVar1 != 0) ||
         (iVar1 = _active_threads,
         sub_F006B0C4(_active_threads,iVar2,*(int *)(param_1 + 4) + -8,param_2 + 4), iVar1 != 0))
      goto locret_F006AFE8;
    }
    else {
      _thread_resume(*(undefined4 *)((int)register0x00000038 + -0xc),iVar2);
    }
    iVar1 = 0;
    *(int *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) + 1;
  }
locret_F006AFE8:
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=3523 start=0xf006aff0 */

/* WARNING: Removing unreachable block (ram,0xf006b024) */

undefined8 sub_F006AFF0(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 unaff_l0;
  int iVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
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
  if (param_3 == 0) {
    uVar3 = 0;
  }
  else {
    do {
      uVar3 = *param_2;
      iVar2 = param_2[1];
      param_2 = param_2 + 2;
      param_3 = param_3 + (iVar2 + 2) * -4;
      iVar1 = param_1;
      _thread_setstatus(param_1,uVar3,param_2,iVar2);
      if (iVar1 != 0) {
        uVar3 = 4;
        goto locret_F006B050;
      }
      param_2 = param_2 + iVar2;
    } while (param_3 != 0);
    uVar3 = 0;
  }
locret_F006B050:
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=3524 start=0xf006b058 */

/* WARNING: Removing unreachable block (ram,0xf006b090) */

undefined8 sub_F006B058(int param_1,undefined4 *param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  int iVar3;
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
  *param_4 = 0;
  do {
    if (param_3 == 0) {
      uVar2 = 0;
locret_F006B0BC:
      return CONCAT44(param_2,uVar2);
    }
    uVar2 = *param_2;
    iVar3 = param_2[1];
    param_2 = param_2 + 2;
    param_3 = param_3 + (iVar3 + 2) * -4;
    iVar1 = param_1;
    _thread_userstack(param_1,uVar2,param_2,iVar3,param_4);
    if (iVar1 != 0) {
      uVar2 = 4;
      goto locret_F006B0BC;
    }
    param_2 = param_2 + iVar3;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=3525 start=0xf006b0c4 */

/* WARNING: Removing unreachable block (ram,0xf006b0fc) */

undefined8 sub_F006B0C4(int param_1,undefined4 *param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  int iVar3;
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
  *param_4 = 0;
  do {
    if (param_3 == 0) {
      uVar2 = 0;
locret_F006B128:
      return CONCAT44(param_2,uVar2);
    }
    uVar2 = *param_2;
    iVar3 = param_2[1];
    param_2 = param_2 + 2;
    param_3 = param_3 + (iVar3 + 2) * -4;
    iVar1 = param_1;
    _thread_entrypoint(param_1,uVar2,param_2,iVar3,param_4);
    if (iVar1 != 0) {
      uVar2 = 4;
      goto locret_F006B128;
    }
    param_2 = param_2 + iVar3;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=3526 start=0xf006b130 */

/* WARNING: Removing unreachable block (ram,0xf006b1c4) */
/* WARNING: Removing unreachable block (ram,0xf006b198) */
/* WARNING: Removing unreachable block (ram,0xf006b1e8) */
/* WARNING: Removing unreachable block (ram,0xf006b17c) */

undefined8 sub_F006B130(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
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
  undefined auStackX_0 [92];
  
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
  pcVar4 = (char *)(param_1 + *(int *)(param_1 + 8));
  pcVar3 = pcVar4;
  do {
    pcVar2 = (char *)0x2;
    if ((char *)(param_1 + *(int *)(param_1 + 4)) <= pcVar3) goto locret_F006B1F0;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  sub_F006B3CC(pcVar4,(undefined *)((int)register0x00000038 + -0x28),
               (undefined *)((int)register0x00000038 + -0x44),
               (undefined *)((int)register0x00000038 + -0x48),
               (undefined *)((int)register0x00000038 + -0x4c));
  pcVar2 = pcVar4;
  if (pcVar4 == (char *)0x0) {
    _memset((undefined *)((int)register0x00000038 + -0x40),0,0x14);
    *(undefined4 *)((int)register0x00000038 + -0x40) = 0;
    pcVar2 = *(char **)((int)register0x00000038 + -0x4c);
    sub_F006A83C(pcVar2,param_2,(undefined *)((int)register0x00000038 + -0x28),
                 *(undefined4 *)((int)register0x00000038 + -0x44),
                 *(undefined4 *)((int)register0x00000038 + -0x48),param_3,
                 (undefined *)((int)register0x00000038 + -0x50),
                 (undefined *)((int)register0x00000038 + -0x40));
    if ((pcVar2 == (char *)0x0) &&
       (*(uint *)((int)register0x00000038 + -0x50) < *(uint *)(param_1 + 0xc))) {
      pcVar2 = (char *)0x3;
    }
    _vn_rele(*(undefined4 *)((int)register0x00000038 + -0x4c));
  }
locret_F006B1F0:
  return CONCAT44(param_2,pcVar2);
}
/* GHIDRADEC_FUNCTION index=3527 start=0xf006b1f8 */

sqword sub_F006B1F8(int param_1,undefined4 *param_2)

{
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
  *param_2 = *(undefined4 *)(param_1 + 0xc);
  return ZEXT48(param_2) << 0x20;
}
/* GHIDRADEC_FUNCTION index=3528 start=0xf006b20c */

/* WARNING: Removing unreachable block (ram,0xf006b3b4) */
/* WARNING: Removing unreachable block (ram,0xf006b32c) */
/* WARNING: Removing unreachable block (ram,0xf006b2b8) */
/* WARNING: Removing unreachable block (ram,0xf006b278) */
/* WARNING: Removing unreachable block (ram,0xf006b268) */
/* WARNING: Removing unreachable block (ram,0xf006b290) */
/* WARNING: Removing unreachable block (ram,0xf006b308) */
/* WARNING: Removing unreachable block (ram,0xf006b358) */
/* WARNING: Removing unreachable block (ram,0xf006b3bc) */
/* WARNING: Removing unreachable block (ram,0xf006b254) */

undefined8 sub_F006B20C(int param_1,int param_2,undefined4 param_3,int param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
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
  int iVar7;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  pcVar5 = (char *)(param_1 + *(int *)(param_1 + 8));
  pcVar4 = pcVar5;
  do {
    if ((char *)(param_1 + *(int *)(param_1 + 4)) <= pcVar4) {
      pcVar5 = (char *)0x2;
      goto locret_F006B3C4;
    }
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  sub_F006B3CC(pcVar5,(undefined *)((int)register0x00000038 + -0x28),
               (undefined *)((int)register0x00000038 + -0x44),
               (undefined *)((int)register0x00000038 + -0x48),
               (undefined *)((int)register0x00000038 + -0x4c));
  if (pcVar5 != (char *)0x0) goto locret_F006B3C4;
  iVar2 = *(int *)((int)register0x00000038 + -0x48);
  _pmap_create();
  _vm_map_create();
  _memset((undefined *)((int)register0x00000038 + -0x40),0,0x14);
  *(undefined4 *)((int)register0x00000038 + -0x40) = 0;
  pcVar5 = *(char **)((int)register0x00000038 + -0x4c);
  sub_F006A83C(pcVar5,iVar2,(undefined *)((int)register0x00000038 + -0x28),
               *(undefined4 *)((int)register0x00000038 + -0x44),
               *(undefined4 *)((int)register0x00000038 + -0x48),param_3,0,
               (undefined *)((int)register0x00000038 + -0x40));
  if (pcVar5 == (char *)0x0) {
    if (*(int *)(iVar2 + 0x1c) < 1) {
      pcVar5 = (char *)0x4;
    }
    else {
      iVar7 = *(int *)(*(int *)(iVar2 + 0x10) + 8);
      iVar6 = *(int *)(*(int *)(iVar2 + 0xc) + 0xc);
      *(int *)((int)register0x00000038 + -0x50) = iVar7;
      iVar6 = iVar6 - iVar7;
      iVar3 = param_2;
      _vm_map_find(param_2,0,0,(undefined *)((int)register0x00000038 + -0x50),iVar6,0);
      if ((iVar3 == 0) ||
         (iVar3 = param_2,
         _vm_map_find(param_2,0,0,(undefined *)((int)register0x00000038 + -0x50),iVar6,1),
         iVar3 == 0)) {
        iVar3 = param_2;
        _vm_map_copy(param_2,iVar2,*(undefined4 *)((int)register0x00000038 + -0x50),iVar6,iVar7,0,0)
        ;
        iVar6 = *(int *)((int)register0x00000038 + -0x50);
        if (iVar3 != 0) goto loc_F006B370;
      }
      else {
loc_F006B370:
        pcVar5 = (char *)0x5;
        iVar6 = *(int *)((int)register0x00000038 + -0x50);
      }
      if (iVar6 != iVar7) {
        *(int *)((int)register0x00000038 + -0x3c) =
             *(int *)((int)register0x00000038 + -0x3c) + (iVar6 - iVar7);
      }
    }
    if (pcVar5 == (char *)0x0) {
      *(uint *)(param_4 + 0x10) = *(uint *)(param_4 + 0x10) | 0x40000000;
      *(undefined4 *)(param_4 + 4) = *(undefined4 *)((int)register0x00000038 + -0x3c);
    }
  }
  _vm_map_deallocate(iVar2);
  _vn_rele(*(undefined4 *)((int)register0x00000038 + -0x4c));
locret_F006B3C4:
  return CONCAT44(param_2,pcVar5);
}
/* GHIDRADEC_FUNCTION index=3529 start=0xf006b3cc */

/* WARNING: Removing unreachable block (ram,0xf006b514) */
/* WARNING: Removing unreachable block (ram,0xf006b430) */
/* WARNING: Removing unreachable block (ram,0xf006b3f8) */
/* WARNING: Removing unreachable block (ram,0xf006b4e4) */
/* WARNING: Removing unreachable block (ram,0xf006b5f0) */
/* WARNING: Removing unreachable block (ram,0xf006b3e4) */

undefined8
sub_F006B3CC(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
            undefined4 *param_5)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  _lookupname(param_1,1,1,0,(undefined *)((int)register0x00000038 + -0x44));
  iVar4 = 4;
  if (param_1 != 0) goto locret_F006B5FC;
  iVar4 = *(int *)((int)register0x00000038 + -0x44);
  _check_exec_access();
  iVar2 = 0;
  if (iVar4 == 0) {
    _vn_rdwr(0,*(undefined4 *)((int)register0x00000038 + -0x44),
             (undefined *)((int)register0x00000038 + -0x40),0x1c,0,1,1,0);
    if (iVar2 == 0) {
      uVar3 = *(uint *)((int)register0x00000038 + -0x40);
      if (uVar3 == 0xfeedface) {
        bVar1 = false;
      }
      else {
        if ((uVar3 != 0xcafebabe) &&
           (*(undefined4 *)((int)register0x00000038 + -0x60) = 0xcafebabe,
           uVar3 != ((uint)*(byte *)((int)register0x00000038 + -0x5d) << 0x18 |
                     (uint)*(byte *)((int)register0x00000038 + -0x5e) << 0x10 |
                     (uint)*(byte *)((int)register0x00000038 + -0x5f) << 8 |
                    (uint)*(byte *)((int)register0x00000038 + -0x60)))) {
          iVar4 = 2;
          goto loc_F006B5F0;
        }
        bVar1 = true;
      }
      iVar4 = *(int *)((int)register0x00000038 + -0x44);
      if (!bVar1) {
        *param_2 = *(undefined4 *)((int)register0x00000038 + -0x40);
        param_2[1] = *(undefined4 *)((int)register0x00000038 + -0x3c);
        param_2[2] = *(undefined4 *)((int)register0x00000038 + -0x38);
        param_2[3] = *(undefined4 *)((int)register0x00000038 + -0x34);
        param_2[4] = *(undefined4 *)((int)register0x00000038 + -0x30);
        param_2[5] = *(undefined4 *)((int)register0x00000038 + -0x2c);
        param_2[6] = *(undefined4 *)((int)register0x00000038 + -0x28);
        *param_3 = 0;
        *param_4 = *(undefined4 *)(**(int **)((int)register0x00000038 + -0x44) + 0x14);
        iVar4 = 0;
        *param_5 = *(undefined4 *)((int)register0x00000038 + -0x44);
        goto locret_F006B5FC;
      }
      _fatfile_getarch(iVar4,(undefined *)((int)register0x00000038 + -0x40),
                       (undefined *)((int)register0x00000038 + -0x20));
      iVar2 = 0;
      if (iVar4 == 0) {
        _vn_rdwr(0,*(undefined4 *)((int)register0x00000038 + -0x44),
                 (undefined *)((int)register0x00000038 + -0x40),0x1c,
                 *(undefined4 *)((int)register0x00000038 + -0x18),1,1,0);
        iVar4 = 4;
        if ((iVar2 == 0) && (iVar4 = 2, *(int *)((int)register0x00000038 + -0x40) == -0x1120532)) {
          *param_2 = 0xfeedface;
          param_2[1] = *(undefined4 *)((int)register0x00000038 + -0x3c);
          param_2[2] = *(undefined4 *)((int)register0x00000038 + -0x38);
          param_2[3] = *(undefined4 *)((int)register0x00000038 + -0x34);
          param_2[4] = *(undefined4 *)((int)register0x00000038 + -0x30);
          param_2[5] = *(undefined4 *)((int)register0x00000038 + -0x2c);
          param_2[6] = *(undefined4 *)((int)register0x00000038 + -0x28);
          *param_3 = *(undefined4 *)((int)register0x00000038 + -0x18);
          *param_4 = *(undefined4 *)((int)register0x00000038 + -0x14);
          iVar4 = 0;
          *param_5 = *(undefined4 *)((int)register0x00000038 + -0x44);
          goto locret_F006B5FC;
        }
      }
    }
    else {
      iVar4 = 4;
    }
  }
  else {
    iVar4 = 6;
  }
loc_F006B5F0:
  _vn_rele(*(undefined4 *)((int)register0x00000038 + -0x44));
locret_F006B5FC:
  return CONCAT44(param_2,iVar4);
}
/* GHIDRADEC_FUNCTION index=3530 start=0xf006b604 */

/* WARNING: Removing unreachable block (ram,0xf006b864) */
/* WARNING: Removing unreachable block (ram,0xf006b794) */
/* WARNING: Removing unreachable block (ram,0xf006b730) */
/* WARNING: Removing unreachable block (ram,0xf006b70c) */
/* WARNING: Removing unreachable block (ram,0xf006b700) */
/* WARNING: Removing unreachable block (ram,0xf006b6c0) */
/* WARNING: Removing unreachable block (ram,0xf006b874) */
/* WARNING: Removing unreachable block (ram,0xf006b750) */
/* WARNING: Removing unreachable block (ram,0xf006b810) */
/* WARNING: Removing unreachable block (ram,0xf006b89c) */
/* WARNING: Removing unreachable block (ram,0xf006b698) */

undefined8 sub_F006B604(undefined *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  undefined *puVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar8;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 *puVar9;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar10;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
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
  puVar4 = param_1;
  if (*(sword *)(*(int *)(_active_u + 0x1c) + 2) == 0) {
    uVar6 = *(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x10);
    *(uint *)(param_1 + 0x18) = uVar6;
    if ((-1 < *(int *)(param_1 + 0x14)) && (0x2b < uVar6)) {
      uVar8 = (uint)*(sword *)(param_1 + 0x2e);
      if ((0x14 < uVar8) && (uVar8 <= uVar6 - 0x18)) {
        *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
        puVar10 = param_1 + 0x2c;
        if (0 < (int)uVar8) {
          param_2 = 0xf0111c00;
          puVar2 = DAT_f0134800;
          puVar9 = (undefined4 *)((int)register0x00000038 + -0xc);
          puVar4 = puVar10;
          do {
            _spltty();
            puVar3 = _mfree;
            if (_mfree == (undefined4 *)0x0) {
              puVar3 = (undefined4 *)0x1;
              _m_more(1,1);
            }
            else {
              if (*(sword *)((int)_mfree + 10) != 0) {
                _panic(&aMget_15);
              }
              *(undefined2 *)((int)puVar3 + 10) = 1;
              word_F0134B0C = word_F0134B0C + -1;
              DAT_f0134b0e._0_2_ = DAT_f0134b0e._0_2_ + 1;
              _mfree = (undefined4 *)*puVar3;
              puVar3[1] = 0xc;
              *puVar3 = 0;
            }
            _splx(puVar2);
            if (puVar3 == (undefined4 *)0x0) {
              _m_freem(*(undefined4 *)((int)register0x00000038 + -0xc));
              goto locret_F006B8A4;
            }
            uVar6 = _page_size >> 1;
            if (uVar8 < 0x70) {
loc_F006B7EC:
              uVar6 = 0x70;
              if ((int)uVar8 < 0x71) {
                uVar6 = uVar8;
              }
            }
            else {
              _spltty(uVar6);
              if (_mclfree == (int *)0x0) {
                _m_clalloc(1,1,0);
              }
              piVar1 = _mclfree;
              if (_mclfree != (int *)0x0) {
                iVar7 = (int)_mclfree - _mbutl >> 10;
                _mclrefcnt[iVar7] = _mclrefcnt[iVar7] + '\x01';
                DAT_f0134afc._0_4_ = DAT_f0134afc._0_4_ + -1;
                _mclfree = (int *)*_mclfree;
              }
              _splx(uVar6);
              if (piVar1 == (int *)0x0) {
                *(undefined2 *)(puVar3 + 2) = 0x70;
              }
              else {
                puVar3[1] = (int)piVar1 - (int)puVar3;
                *(undefined2 *)(puVar3 + 2) = 0x400;
                *(undefined2 *)(puVar3 + 3) = 1;
              }
              uVar6 = (uint)*(sword *)(puVar3 + 2);
              if (uVar6 != _page_size) goto loc_F006B7EC;
              if (uVar8 <= uVar6) {
                uVar6 = uVar8;
              }
            }
            *(sword *)(puVar3 + 2) = (sword)uVar6;
            puVar10 = puVar4 + uVar6;
            uVar8 = uVar8 - uVar6;
            _bcopy(puVar4,(int)puVar3 + puVar3[1]);
            *puVar9 = puVar3;
            puVar2 = puVar4;
            puVar9 = puVar3;
            puVar4 = puVar10;
          } while (0 < (int)uVar8);
        }
        if (DAT_f010fcd0._0_4_ == *(int *)(param_1 + 0x3c)) {
          uVar5 = *(undefined4 *)((int)register0x00000038 + -0xc);
        }
        else {
          if (unk_F010FCC8 != 0) {
            if (*(sword *)(unk_F010FCC8 + 0x26) == 1) {
              _rtfree(unk_F010FCC8);
            }
            else {
              *(sword *)(unk_F010FCC8 + 0x26) = *(sword *)(unk_F010FCC8 + 0x26) + -1;
            }
          }
          unk_F010FCC8 = 0;
          uVar5 = *(undefined4 *)((int)register0x00000038 + -0xc);
        }
        _ip_output(uVar5,0,&unk_F010FCC8,0x21);
        puVar4 = puVar10;
      }
    }
  }
locret_F006B8A4:
  return CONCAT44(param_2,puVar4);
}
/* GHIDRADEC_FUNCTION index=3531 start=0xf006dc24 */

undefined8 sub_F006DC24(char *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
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
  cVar1 = *param_1;
  while (((cVar1 != '\0' && (iVar2 = (int)*param_2, iVar2 != 0x20)) && (1 < (iVar2 - 9U & 0xff)))) {
    if (iVar2 == 0) {
      uVar3 = 0;
      goto locret_F006DC88;
    }
    cVar1 = *param_1;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
    if (cVar1 != iVar2) {
      uVar3 = 1;
      goto locret_F006DC88;
    }
    cVar1 = *param_1;
  }
  uVar3 = 0;
locret_F006DC88:
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=3532 start=0xf006dc90 */

/* WARNING: Removing unreachable block (ram,0xf006dcfc) */
/* WARNING: Removing unreachable block (ram,0xf006dd5c) */
/* WARNING: Removing unreachable block (ram,0xf006dcb0) */

undefined8 sub_F006DC90(undefined4 param_1,undefined4 param_2)

{
  undefined (*pauVar1) [9];
  undefined *puVar2;
  undefined4 unaff_l0;
  undefined (**ppauVar3) [9];
  undefined4 unaff_l1;
  undefined (**ppauVar4) [9];
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
  ppauVar4 = (undefined (**) [9])0x0;
  ppauVar3 = &_miniMonCommands;
  pauVar1 = _miniMonCommands;
  while (pauVar1 != (undefined (*) [9])0x0) {
    pauVar1 = *ppauVar3;
    sub_F006DC24(pauVar1,param_1);
    if ((pauVar1 == (undefined (*) [9])0x0) &&
       (bVar5 = ppauVar4 != (undefined (**) [9])0x0, ppauVar4 = ppauVar3, bVar5)) {
      puVar2 = aAmbiguousComma;
      goto loc_F006DD5C;
    }
    ppauVar3 = ppauVar3 + 3;
    pauVar1 = *ppauVar3;
  }
  ppauVar3 = &_miniMonMDCommands;
  pauVar1 = _miniMonMDCommands;
  do {
    if (pauVar1 == (undefined (*) [9])0x0) {
      if (ppauVar4 == (undefined (**) [9])0x0) {
        puVar2 = aInvalidCommand;
loc_F006DD5C:
        param_1 = 1;
        _safe_prf(puVar2);
      }
      else {
        (*(code *)ppauVar4[1])(param_1);
      }
      return CONCAT44(param_2,param_1);
    }
    pauVar1 = *ppauVar3;
    sub_F006DC24(pauVar1,param_1);
    if ((pauVar1 == (undefined (*) [9])0x0) &&
       (bVar5 = ppauVar4 != (undefined (**) [9])0x0, ppauVar4 = ppauVar3, bVar5)) {
      puVar2 = aAmbiguousComma_0;
      goto loc_F006DD5C;
    }
    ppauVar3 = ppauVar3 + 3;
    pauVar1 = *ppauVar3;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=3533 start=0xf006dd7c */

/* WARNING: Removing unreachable block (ram,0xf006de2c) */
/* WARNING: Removing unreachable block (ram,0xf006ddf0) */
/* WARNING: Removing unreachable block (ram,0xf006de04) */
/* WARNING: Removing unreachable block (ram,0xf006ddcc) */
/* WARNING: Removing unreachable block (ram,0xf006dddc) */
/* WARNING: Removing unreachable block (ram,0xf006de24) */
/* WARNING: Removing unreachable block (ram,0xf006de34) */
/* WARNING: Removing unreachable block (ram,0xf006dd88) */

undefined8 sub_F006DD7C(undefined *param_1,int param_2)

{
  undefined *puVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined *puVar2;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  puVar2 = param_1;
  puVar1 = param_1;
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
    puVar2 = param_1;
    puVar1 = param_1;
  }
  do {
    param_2 = param_2 + -1;
loc_F006DD88:
    _miniMonGetchar();
    if (param_1 == (undefined *)0xa) {
      *puVar2 = 0;
locret_F006DE40:
      return CONCAT44(param_2,puVar2);
    }
    if (10 < (int)param_1) {
      if (param_1 == (undefined *)0xd) {
        _miniMonPutchar(10);
        *puVar2 = 0;
        goto locret_F006DE40;
      }
      if (param_1 != (undefined *)0x15) goto loc_F006DE10;
      param_1 = (undefined *)0xa;
      _miniMonPutchar();
      puVar2 = puVar1;
      goto loc_F006DD88;
    }
    if (param_1 == (undefined *)0x8) {
      param_1 = (undefined *)0x20;
      _miniMonPutchar();
      if (puVar2 != puVar1) {
        param_1 = (undefined *)0x8;
        _miniMonPutchar();
        param_2 = param_2 + 1;
        puVar2 = puVar2 + -1;
      }
      goto loc_F006DD88;
    }
loc_F006DE10:
    if (param_2 == 0) {
      _miniMonPutchar(8);
      _miniMonPutchar(0x20);
      param_1 = (undefined *)0x8;
      _miniMonPutchar();
      goto loc_F006DD88;
    }
    *puVar2 = (char)param_1;
    puVar2 = puVar2 + 1;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=3534 start=0xf006df38 */

sqword sub_F006DF38(undefined4 param_1,uint param_2)

{
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
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=3535 start=0xf006df44 */

/* WARNING: Removing unreachable block (ram,0xf006df8c) */
/* WARNING: Removing unreachable block (ram,0xf006df58) */
/* WARNING: Removing unreachable block (ram,0xf006dfd4) */
/* WARNING: Removing unreachable block (ram,0xf006df4c) */

undefined8 sub_F006DF44(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar2;
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
  _safe_prf(aMiniMonitorCom);
  _safe_prf(aHelpPrintThisM);
  piVar2 = &_miniMonCommands;
  iVar1 = DAT_f010fd90._0_4_;
  if (_miniMonCommands != 0) {
    while( true ) {
      if (iVar1 != 0) {
        _safe_prf(aSS_5,*piVar2);
      }
      if (piVar2[3] == 0) break;
      iVar1 = piVar2[5];
      piVar2 = piVar2 + 3;
    }
  }
  piVar2 = &_miniMonMDCommands;
  iVar1 = iRamf01128a8;
  if (_miniMonMDCommands != 0) {
    while( true ) {
      if (iVar1 != 0) {
        _safe_prf(aSS_6,*piVar2);
      }
      if (piVar2[3] == 0) break;
      iVar1 = piVar2[5];
      piVar2 = piVar2 + 3;
    }
  }
  return CONCAT44(param_2,1);
}
/* GHIDRADEC_FUNCTION index=3536 start=0xf006e080 */

/* WARNING: Removing unreachable block (ram,0xf006e084) */

undefined8 sub_F006E080(undefined4 param_1,undefined4 param_2)

{
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
  _kdp_reset();
  return CONCAT44(param_2,1);
}
/* GHIDRADEC_FUNCTION index=3537 start=0xf006e094 */

/* WARNING: Removing unreachable block (ram,0xf006e0d0) */
/* WARNING: Removing unreachable block (ram,0xf006e0c4) */
/* WARNING: Removing unreachable block (ram,0xf006e0b0) */
/* WARNING: Removing unreachable block (ram,0xf006e09c) */

undefined8 sub_F006E094(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
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
  puVar1 = __kernDebuggerLock;
  _simple_lock_try();
  if (puVar1 == (undefined4 *)0x0) {
    _safe_prf(aCouldnTAcquire);
    _safe_prf(aExitFromMonito);
    param_1 = 1;
  }
  else {
    _miniMonGdb(param_1);
    *__kernDebuggerLock = 0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3538 start=0xf006e714 */

/* WARNING: Removing unreachable block (ram,0xf006e7d4) */
/* WARNING: Removing unreachable block (ram,0xf006e80c) */
/* WARNING: Removing unreachable block (ram,0xf006e804) */
/* WARNING: Removing unreachable block (ram,0xf006e7c0) */
/* WARNING: Removing unreachable block (ram,0xf006e794) */
/* WARNING: Removing unreachable block (ram,0xf006e71c) */

undefined8 sub_F006E714(undefined4 *param_1,undefined4 param_2)

{
  undefined *puVar1;
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
  undefined auStackX_0 [92];
  
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
  puVar1 = (undefined *)((int)register0x00000038 + -0xc);
  _PMGetPowerEvent();
  if (puVar1 == (undefined *)0x0) {
    switch(*(undefined4 *)((int)register0x00000038 + -0xc)) {
    case :
    case :
      dword_F012F928 = 1;
      *(undefined4 *)((int)register0x00000038 + -0x10) = 0x10000;
      _PMSetPowerState((undefined *)((int)register0x00000038 + -0x10));
      break;
    case :
    case :
    case :
      dword_F012F928 = 2;
      *(undefined4 *)((int)register0x00000038 + -0x10) = 0x10000;
      _PMSetPowerState((undefined *)((int)register0x00000038 + -0x10),2);
      dword_F012F928 = 0;
      *(undefined4 *)((int)register0x00000038 + -0x10) = 0x10000;
      _PMSetPowerState((undefined *)((int)register0x00000038 + -0x10),0);
      break;
    case :
    case :
    case :
      if (dword_F012F928 != 0) {
        dword_F012F928 = 0;
        *(undefined4 *)((int)register0x00000038 + -0x10) = 0x10000;
        _PMSetPowerState((undefined *)((int)register0x00000038 + -0x10),0);
      }
    case :
      _PMUpdateClock();
    :
    }
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = *(undefined4 *)((int)register0x00000038 + -0xc);
    }
  }
  return CONCAT44(param_2,puVar1);
}
/* GHIDRADEC_FUNCTION index=3539 start=0xf006fb2c */

/* WARNING: Removing unreachable block (ram,0xf006fb50) */

sqword sub_F006FB2C(uint *param_1,uint param_2)

{
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
  _safe_prf(aKdpUnknownRequ,*param_1 >> 0x19,*param_1 & 0xffff,*(undefined *)((int)param_1 + 1),
            param_1[1]);
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=3540 start=0xf006fb60 */

undefined8 sub_F006FB60(uint *param_1,uint *param_2,undefined2 *param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  if (*param_2 < 0xc) {
    uVar1 = 0;
    goto locret_F006FC0C;
  }
  if (dword_F013C408 == 0) {
    _kdp = *(undefined2 *)(param_1 + 2);
    DAT_f013c414 = *(undefined2 *)((int)param_1 + 10);
    dword_F013C408 = 1;
    uRamf013c404 = (uint)*(byte *)((int)param_1 + 1);
loc_F006FBCC:
    param_1[2] = 0;
  }
  else {
    if (*(byte *)((int)param_1 + 1) == uRamf013c404) goto loc_F006FBCC;
    param_1[2] = 1;
  }
  *param_1 = *param_1 | 0x1000000;
  *(undefined2 *)((int)param_1 + 2) = 0xc;
  uVar1 = 1;
  *param_3 = _kdp;
  *param_2 = *param_1 & 0xffff;
locret_F006FC0C:
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=3541 start=0xf006fc14 */

undefined8 sub_F006FC14(uint *param_1,uint *param_2,undefined2 *param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  if ((*param_2 < 8) || (dword_F013C408 == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
    *param_3 = _kdp;
    DAT_f013c414 = 0;
    _kdp = 0;
    dword_F013C408 = 0;
    DAT_f013c410._0_4_ = 0;
    uRamf013c404 = 0;
    byte_F013C416 = 0;
    *param_1 = *param_1 | 0x1000000;
    *(undefined2 *)((int)param_1 + 2) = 8;
    *param_2 = *param_1 & 0xffff;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=3542 start=0xf006fc9c */

/* WARNING: Removing unreachable block (ram,0xf006fcc8) */

undefined8 sub_F006FC9C(uint *param_1,uint *param_2,undefined2 *param_3)

{
  uint uVar1;
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
  uVar1 = *param_2;
  if (7 < uVar1) {
    *param_1 = *param_1 | 0x1000000;
    *(undefined2 *)((int)param_1 + 2) = 0x14;
    _kdp_machine_hostinfo(param_1 + 2);
    *param_3 = _kdp;
    *param_2 = *param_1 & 0xffff;
  }
  return CONCAT44(param_2,(uint)(7 < uVar1));
}
/* GHIDRADEC_FUNCTION index=3543 start=0xf006fd04 */

undefined8 sub_F006FD04(uint *param_1,uint *param_2,undefined2 *param_3)

{
  uint uVar1;
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
  uVar1 = *param_2;
  if (7 < uVar1) {
    *param_1 = *param_1 | 0x1000000;
    *(undefined2 *)((int)param_1 + 2) = 8;
    DAT_f013c410._0_4_ = 1;
    *param_3 = _kdp;
    *param_2 = *param_1 & 0xffff;
    param_2 = (uint *)&_kdp;
  }
  return CONCAT44(param_2,(uint)(7 < uVar1));
}
/* GHIDRADEC_FUNCTION index=3544 start=0xf006fd74 */

undefined8 sub_F006FD74(uint *param_1,uint *param_2,undefined2 *param_3)

{
  uint uVar1;
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
  uVar1 = *param_2;
  if (0xb < uVar1) {
    *param_1 = *param_1 | 0x1000000;
    *(undefined2 *)((int)param_1 + 2) = 8;
    DAT_f013c410._0_4_ = 0;
    *param_3 = _kdp;
    *param_2 = *param_1 & 0xffff;
  }
  return CONCAT44(param_2,(uint)(0xb < uVar1));
}
/* GHIDRADEC_FUNCTION index=3545 start=0xf006fddc */

/* WARNING: Removing unreachable block (ram,0xf006fe14) */

undefined8 sub_F006FDDC(uint *param_1,uint *param_2,undefined2 *param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  if (*param_2 < 0x10) {
    uVar1 = 0;
  }
  else {
    if (param_1[3] < 0x401) {
      _copywithin(param_1 + 4,param_1[2]);
      param_1[2] = 0;
    }
    else {
      param_1[2] = 2;
    }
    *param_1 = *param_1 | 0x1000000;
    *(undefined2 *)((int)param_1 + 2) = 0xc;
    uVar1 = 1;
    *param_3 = _kdp;
    *param_2 = *param_1 & 0xffff;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=3546 start=0xf006fe64 */

/* WARNING: Removing unreachable block (ram,0xf006feb8) */

undefined8 sub_F006FE64(uint *param_1,uint *param_2,undefined2 *param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
  uint uVar2;
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
  if (*param_2 < 0x10) {
    uVar1 = 0;
  }
  else {
    uVar2 = param_1[3];
    *param_1 = *param_1 | 0x1000000;
    *(undefined2 *)((int)param_1 + 2) = 0xc;
    if (uVar2 < 0x401) {
      _copywithin(param_1[2],param_1 + 3,uVar2);
      param_1[2] = 0;
      *(sword *)((int)param_1 + 2) = (sword)*param_1 + (sword)uVar2;
    }
    else {
      param_1[2] = 2;
    }
    uVar1 = 1;
    *param_3 = _kdp;
    *param_2 = *param_1 & 0xffff;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=3547 start=0xf006fefc */

undefined8 sub_F006FEFC(uint *param_1,uint *param_2,undefined2 *param_3)

{
  uint uVar1;
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
  uVar1 = *param_2;
  if (7 < uVar1) {
    param_1[2] = 0x400;
    *param_1 = *param_1 | 0x1000000;
    *(undefined2 *)((int)param_1 + 2) = 0xc;
    *param_3 = _kdp;
    *param_2 = *param_1 & 0xffff;
  }
  return CONCAT44(param_2,(uint)(7 < uVar1));
}
/* GHIDRADEC_FUNCTION index=3548 start=0xf006ff64 */

undefined8 sub_F006FF64(uint *param_1,uint *param_2,undefined2 *param_3)

{
  uint uVar1;
  uint uVar2;
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
  uVar1 = *param_2;
  if (7 < uVar1) {
    param_1[2] = 0;
    param_1[3] = 0xf0000000;
    param_1[4] = 0xf000000;
    param_1[5] = 7;
    *param_1 = *param_1 | 0x1000000;
    uVar2 = param_1[2];
    *(undefined2 *)((int)param_1 + 2) = 0xc;
    param_1[2] = uVar2 + 1;
    *(sword *)((int)param_1 + 2) = (sword)*param_1 + (sword)(uVar2 + 1) * 0xc;
    *param_3 = _kdp;
    *param_2 = *param_1 & 0xffff;
  }
  return CONCAT44(param_2,(uint)(7 < uVar1));
}
/* GHIDRADEC_FUNCTION index=3549 start=0xf0070004 */

/* WARNING: Removing unreachable block (ram,0xf0070038) */

undefined8 sub_F0070004(uint *param_1,uint *param_2,undefined2 *param_3)

{
  uint uVar1;
  uint uVar2;
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
  undefined auStackX_0 [92];
  
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
  uVar1 = *param_2;
  if (0xf < uVar1) {
    uVar2 = param_1[2];
    *(uint *)((int)register0x00000038 + -0xc) = (*param_1 & 0xffff) - 0xc;
    _kdp_machine_write_regs
              (uVar2,param_1[3],param_1 + 4,(undefined *)((int)register0x00000038 + -0xc));
    param_1[2] = uVar2;
    *param_1 = *param_1 | 0x1000000;
    *(undefined2 *)((int)param_1 + 2) = 0xc;
    *param_3 = _kdp;
    *param_2 = *param_1 & 0xffff;
  }
  return CONCAT44(param_2,(uint)(0xf < uVar1));
}

