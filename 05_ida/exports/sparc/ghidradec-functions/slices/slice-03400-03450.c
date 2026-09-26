/* GHIDRADEC_FUNCTION index=3400 start=0xf0045018 */

/* WARNING: Removing unreachable block (ram,0xf0045038) */

undefined8 sub_F0045018(uint *param_1,undefined4 param_2)

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
  uVar1 = *param_1;
  *param_1 = uVar1 & 0xfffffffe;
  if ((uVar1 & 2) != 0) {
    *param_1 = uVar1 & 0xfffffffc;
    _wakeup(param_1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3401 start=0xf00453cc */

undefined8 sub_F00453CC(uint *param_1)

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
  undefined4 unaff_i1;
  uint *puVar2;
  uint *puVar3;
  undefined4 unaff_i2;
  uint *puVar4;
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
  puVar2 = *(uint **)(_drhashtbl + (*param_1 & 0x1f) * 4);
  if (puVar2 != (uint *)0x0) {
    iVar1 = (int)puVar2 - (int)param_1;
    puVar4 = (uint *)0x0;
    do {
      puVar3 = puVar2;
      if (iVar1 == 0) {
        puVar2 = puVar3;
        if (puVar4 == (uint *)0x0) {
          *(uint *)(_drhashtbl + (*puVar3 & 0x1f) * 4) = puVar3[9];
        }
        else {
          puVar4[9] = puVar3[9];
        }
        break;
      }
      puVar2 = (uint *)puVar3[9];
      iVar1 = (int)puVar2 - (int)param_1;
      puVar4 = puVar3;
    } while (puVar2 != (uint *)0x0);
  }
  return CONCAT44(puVar2,param_1);
}
/* GHIDRADEC_FUNCTION index=3402 start=0xf0046108 */

undefined8 sub_F0046108(undefined4 param_1,undefined4 param_2)

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
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3403 start=0xf0046114 */

/* WARNING: Removing unreachable block (ram,0xf0046154) */

undefined8 sub_F0046114(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
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
  iVar1 = *(int *)(param_1 + 0x14) + -4;
  *(int *)(param_1 + 0x14) = iVar1;
  if (iVar1 < 0) {
    uVar3 = 0;
  }
  else {
    puVar2 = *(undefined4 **)(param_1 + 0xc);
    if ((((uint)puVar2 & 3) == 0) && (((uint)param_2 & 3) == 0)) {
      *param_2 = *puVar2;
      iVar1 = *(int *)(param_1 + 0xc);
    }
    else {
      _bcopy(puVar2,param_2,4);
      iVar1 = *(int *)(param_1 + 0xc);
    }
    uVar3 = 1;
    *(int *)(param_1 + 0xc) = iVar1 + 4;
  }
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=3404 start=0xf0046180 */

/* WARNING: Removing unreachable block (ram,0xf00461c0) */

undefined8 sub_F0046180(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
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
  iVar1 = *(int *)(param_1 + 0x14) + -4;
  *(int *)(param_1 + 0x14) = iVar1;
  if (iVar1 < 0) {
    uVar3 = 0;
  }
  else {
    puVar2 = *(undefined4 **)(param_1 + 0xc);
    if ((((uint)puVar2 & 3) == 0) && (((uint)param_2 & 3) == 0)) {
      *puVar2 = *param_2;
      iVar1 = *(int *)(param_1 + 0xc);
    }
    else {
      _bcopy(param_2,puVar2,4);
      iVar1 = *(int *)(param_1 + 0xc);
    }
    uVar3 = 1;
    *(int *)(param_1 + 0xc) = iVar1 + 4;
  }
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=3405 start=0xf00461ec */

/* WARNING: Removing unreachable block (ram,0xf0046210) */

undefined8 sub_F00461EC(int param_1,undefined4 param_2,int param_3)

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
  iVar1 = *(int *)(param_1 + 0x14) - param_3;
  *(int *)(param_1 + 0x14) = iVar1;
  if (-1 < iVar1) {
    _bcopy(*(undefined4 *)(param_1 + 0xc),param_2,param_3);
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + param_3;
  }
  return CONCAT44(param_2,(uint)(-1 < iVar1));
}
/* GHIDRADEC_FUNCTION index=3406 start=0xf0046238 */

/* WARNING: Removing unreachable block (ram,0xf004625c) */

undefined8 sub_F0046238(int param_1,undefined4 param_2,int param_3)

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
  iVar1 = *(int *)(param_1 + 0x14) - param_3;
  *(int *)(param_1 + 0x14) = iVar1;
  if (-1 < iVar1) {
    _bcopy(param_2,*(undefined4 *)(param_1 + 0xc),param_3);
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + param_3;
  }
  return CONCAT44(param_2,(uint)(-1 < iVar1));
}
/* GHIDRADEC_FUNCTION index=3407 start=0xf0046284 */

undefined8 sub_F0046284(int param_1,undefined4 param_2)

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
  return CONCAT44(param_2,*(int *)(param_1 + 0xc) - *(int *)(param_1 + 0x10));
}
/* GHIDRADEC_FUNCTION index=3408 start=0xf004629c */

undefined8 sub_F004629C(int param_1,int param_2)

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
  iVar1 = *(int *)(param_1 + 0x10) + param_2;
  iVar2 = *(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x14);
  if (iVar1 <= iVar2) {
    *(int *)(param_1 + 0xc) = iVar1;
    *(int *)(param_1 + 0x14) = iVar2 - iVar1;
  }
  return CONCAT44(param_2,(uint)(iVar1 <= iVar2));
}
/* GHIDRADEC_FUNCTION index=3409 start=0xf00462dc */

undefined8 sub_F00462DC(int param_1,int param_2)

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
  iVar1 = 0;
  if (param_2 <= *(int *)(param_1 + 0x14)) {
    if ((*(uint *)(param_1 + 0xc) & 3) == 0) {
      iVar1 = *(int *)(param_1 + 0xc);
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) - param_2;
      *(int *)(param_1 + 0xc) = iVar1 + param_2;
    }
    else {
      iVar1 = 0;
    }
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=3410 start=0xf00465f4 */

/* WARNING: Removing unreachable block (ram,0xf0046708) */
/* WARNING: Removing unreachable block (ram,0xf0046674) */
/* WARNING: Removing unreachable block (ram,0xf0046630) */
/* WARNING: Removing unreachable block (ram,0xf00466c8) */
/* WARNING: Removing unreachable block (ram,0xf0046734) */
/* WARNING: Removing unreachable block (ram,0xf004660c) */

undefined8 sub_F00465F4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  sword sVar4;
  uint uVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
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
  *(undefined4 *)((int)register0x00000038 + 0x44) = param_1;
  *(undefined4 *)((int)register0x00000038 + 0x48) = param_2;
  *(undefined4 *)((int)register0x00000038 + 0x4c) = param_3;
  iVar1 = dword_F0133DDC + 0x28;
  _setjmp();
  if (iVar1 != 0) {
    sub_F0046758(**(int **)((int)register0x00000038 + 0x44),
                 *(uint *)((int)register0x00000038 + 0x48) & 0x4b,1,
                 *(undefined4 *)((int)register0x00000038 + 0x4c));
    uVar5 = 4;
    goto locret_F0046750;
  }
  iVar1 = *(int *)(**(int **)((int)register0x00000038 + 0x44) + 0x30);
  if ((*(uint *)((int)register0x00000038 + 0x48) & 1) == 0) {
loc_F004667C:
    uVar2 = *(uint *)((int)register0x00000038 + 0x48);
  }
  else {
    sVar4 = *(sword *)(iVar1 + 0x82) + 1;
    *(sword *)(iVar1 + 0x82) = sVar4;
    uVar2 = *(uint *)((int)register0x00000038 + 0x48);
    if (sVar4 == 1) {
      _wakeup(iVar1 + 0x82);
      goto loc_F004667C;
    }
  }
  if ((uVar2 & 2) == 0) {
loc_F00466D0:
    uVar2 = *(uint *)((int)register0x00000038 + 0x48);
  }
  else {
    if ((uVar2 & 4) == 0) {
      sVar4 = *(sword *)(iVar1 + 0x80);
    }
    else {
      if (*(sword *)(iVar1 + 0x82) == 0) {
        uVar5 = 6;
        goto locret_F0046750;
      }
      sVar4 = *(sword *)(iVar1 + 0x80);
    }
    *(sword *)(iVar1 + 0x80) = sVar4 + 1;
    uVar2 = *(uint *)((int)register0x00000038 + 0x48);
    if ((sword)(sVar4 + 1) == 1) {
      _wakeup(iVar1 + 0x80);
      goto loc_F00466D0;
    }
  }
  uVar3 = *(uint *)((int)register0x00000038 + 0x48);
  if ((uVar2 & 1) != 0) {
    sVar4 = *(sword *)(iVar1 + 0x80);
    while (uVar3 = *(uint *)((int)register0x00000038 + 0x48), sVar4 == 0) {
      if ((uVar3 & 4) != 0) {
        uVar5 = 0;
        goto locret_F0046750;
      }
      if (*(int *)(iVar1 + 0x7c) != 0) {
        uVar5 = 0;
        goto locret_F0046750;
      }
      _sleep(iVar1 + 0x80,0x1a);
      sVar4 = *(sword *)(iVar1 + 0x80);
    }
  }
  if ((uVar3 & 2) == 0) {
    uVar5 = 0;
  }
  else {
    sVar4 = *(sword *)(iVar1 + 0x82);
    while (sVar4 == 0) {
      _sleep(iVar1 + 0x82,0x1a);
      sVar4 = *(sword *)(iVar1 + 0x82);
    }
    uVar5 = 0;
  }
locret_F0046750:
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=3411 start=0xf0046758 */

/* WARNING: Removing unreachable block (ram,0xf004687c) */
/* WARNING: Removing unreachable block (ram,0xf004680c) */
/* WARNING: Removing unreachable block (ram,0xf00467c8) */
/* WARNING: Removing unreachable block (ram,0xf00467c0) */
/* WARNING: Removing unreachable block (ram,0xf00467f0) */
/* WARNING: Removing unreachable block (ram,0xf0046854) */
/* WARNING: Removing unreachable block (ram,0xf00468a0) */
/* WARNING: Removing unreachable block (ram,0xf00467a4) */

sqword sub_F0046758(int param_1,uint param_2,int param_3)

{
  sword sVar1;
  int iVar2;
  undefined4 unaff_l0;
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
  iVar3 = *(int *)(param_1 + 0x30);
  if (param_3 < 2) {
    if ((param_2 & 1) == 0) {
      iVar2 = *(int *)(iVar3 + 0x74);
    }
    else {
      sVar1 = *(sword *)(iVar3 + 0x82);
      *(sword *)(iVar3 + 0x82) = sVar1 + -1;
      if (sVar1 == 1) {
        if ((*(word *)(iVar3 + 0x88) & 2) != 0) {
          *(word *)(iVar3 + 0x88) = *(word *)(iVar3 + 0x88) & 0xfffd;
          _wakeup(iVar3 + 0x80);
        }
        if (*(int *)(iVar3 + 0x78) == 0) {
          iVar2 = *(int *)(iVar3 + 0x74);
        }
        else {
          _selwakeup(*(int *)(iVar3 + 0x78),*(word *)(iVar3 + 0x88) & 0x10);
          _thread_deallocate(*(undefined4 *)(iVar3 + 0x78));
          *(undefined4 *)(iVar3 + 0x78) = 0;
          *(word *)(iVar3 + 0x88) = *(word *)(iVar3 + 0x88) & 0xffef;
          iVar2 = *(int *)(iVar3 + 0x74);
        }
      }
      else {
        iVar2 = *(int *)(iVar3 + 0x74);
      }
    }
    if (iVar2 == 0) {
      iVar2 = *(int *)(iVar3 + 0x70);
    }
    else {
      _thread_deallocate();
      *(undefined4 *)(iVar3 + 0x74) = 0;
      iVar2 = *(int *)(iVar3 + 0x70);
    }
    if (iVar2 != 0) {
      _thread_deallocate();
      *(undefined4 *)(iVar3 + 0x70) = 0;
    }
    if ((param_2 & 2) == 0) {
      iVar2 = *(int *)(iVar3 + 0x80);
    }
    else {
      sVar1 = *(sword *)(iVar3 + 0x80);
      *(sword *)(iVar3 + 0x80) = sVar1 + -1;
      if (sVar1 == 1) {
        if ((*(word *)(iVar3 + 0x88) & 1) != 0) {
          *(word *)(iVar3 + 0x88) = *(word *)(iVar3 + 0x88) & 0xfffe;
          _wakeup(iVar3 + 0x82);
        }
        iVar2 = *(int *)(iVar3 + 0x80);
      }
      else {
        iVar2 = *(int *)(iVar3 + 0x80);
      }
    }
    if (iVar2 == 0) {
      iVar2 = *(int *)(iVar3 + 0x68);
      if (iVar2 == 0) {
        iVar2 = *(int *)(iVar3 + 0x7c);
      }
      else {
        do {
          sub_F0047258();
        } while (iVar2 != 0);
        iVar2 = *(int *)(iVar3 + 0x7c);
      }
      if (iVar2 != 0) {
        _smark(iVar3,0x42);
      }
      *(undefined4 *)(iVar3 + 0x68) = 0;
      *(undefined2 *)(iVar3 + 0x86) = 0;
      *(undefined2 *)(iVar3 + 0x84) = 0;
      *(undefined4 *)(iVar3 + 0x7c) = 0;
    }
  }
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=3412 start=0xf00468c0 */

/* WARNING: Removing unreachable block (ram,0xf0046acc) */
/* WARNING: Removing unreachable block (ram,0xf0046bd0) */
/* WARNING: Removing unreachable block (ram,0xf0046b98) */
/* WARNING: Removing unreachable block (ram,0xf0046ab0) */
/* WARNING: Removing unreachable block (ram,0xf0046a80) */
/* WARNING: Removing unreachable block (ram,0xf0046a54) */
/* WARNING: Removing unreachable block (ram,0xf00469e4) */
/* WARNING: Removing unreachable block (ram,0xf0046eb0) */
/* WARNING: Removing unreachable block (ram,0xf0046e8c) */
/* WARNING: Removing unreachable block (ram,0xf0046e40) */
/* WARNING: Removing unreachable block (ram,0xf0046dd4) */
/* WARNING: Removing unreachable block (ram,0xf0046d64) */
/* WARNING: Removing unreachable block (ram,0xf0046d34) */
/* WARNING: Removing unreachable block (ram,0xf0046cc8) */
/* WARNING: Removing unreachable block (ram,0xf00468f0) */
/* WARNING: Removing unreachable block (ram,0xf0046ce8) */
/* WARNING: Removing unreachable block (ram,0xf0046d54) */
/* WARNING: Removing unreachable block (ram,0xf0046d84) */
/* WARNING: Removing unreachable block (ram,0xf0046e1c) */
/* WARNING: Removing unreachable block (ram,0xf0046e70) */
/* WARNING: Removing unreachable block (ram,0xf0046ea8) */
/* WARNING: Removing unreachable block (ram,0xf0046c1c) */
/* WARNING: Removing unreachable block (ram,0xf0046a04) */
/* WARNING: Removing unreachable block (ram,0xf0046a70) */
/* WARNING: Removing unreachable block (ram,0xf0046aa4) */
/* WARNING: Removing unreachable block (ram,0xf0046b58) */
/* WARNING: Removing unreachable block (ram,0xf0046bb4) */
/* WARNING: Removing unreachable block (ram,0xf0046bd8) */
/* WARNING: Removing unreachable block (ram,0xf0046ef4) */
/* WARNING: Removing unreachable block (ram,0xf00468d8) */

undefined8 sub_F00468C0(int param_1,int param_2,int param_3)

{
  sword sVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  word wVar7;
  uint uVar8;
  undefined4 unaff_l0;
  int *piVar9;
  undefined4 unaff_l1;
  int iVar10;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  int iVar11;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar12;
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
  iVar11 = 0;
  if (*(int *)(param_2 + 8) != 0) {
    _printf(aFifoRdwrNonZer);
  }
  puVar12 = *(undefined4 **)(param_1 + 0x30);
  while ((*(word *)(puVar12 + 0x10) & 1) != 0) {
    *(word *)(puVar12 + 0x10) = *(word *)(puVar12 + 0x10) | 0x10;
    _sleep(puVar12,10);
  }
  *(word *)(puVar12 + 0x10) = *(word *)(puVar12 + 0x10) | 1;
  if (param_3 == 1) {
    uVar4 = *(uint *)(param_2 + 0x14);
    if (dword_F010F398 < uVar4) {
      iVar11 = 0x16;
    }
    else {
      if (uVar4 == 0) {
        wVar7 = *(word *)(puVar12 + 0x10);
        goto loc_F0046ECC;
      }
      sVar1 = *(sword *)((int)puVar12 + 0x82);
loc_F0046950:
      if (sVar1 == 0) goto loc_F0046C0C;
      uVar8 = puVar12[0x1f];
      if (uVar4 + uVar8 <= _fifoinfo) {
        sVar1 = *(sword *)(puVar12 + 0x21);
loc_F0046A3C:
        if ((int)sVar1 - (int)*(sword *)((int)puVar12 + 0x86) != puVar12[0x1f]) {
          _printf(aFifoWritePtrMi);
        }
        if (dword_F010F39C < *(sword *)((int)puVar12 + 0x86)) {
          _printf(aFifoWriteRptrT);
        }
        iVar10 = (int)*(sword *)((int)puVar12 + 0x8a);
        iVar2 = iVar10;
        .umul(iVar10,dword_F010F39C);
        if (iVar2 < *(sword *)(puVar12 + 0x21)) {
          _printf(aFifoWriteWptrT,(int)*(sword *)(puVar12 + 0x21),iVar10);
          goto loc_F0046AAC;
        }
        sVar1 = *(sword *)((int)puVar12 + 0x8a);
        while( true ) {
          iVar2 = (int)sVar1;
          .umul(iVar2,dword_F010F39C);
          if (uVar4 <= (uint)(iVar2 - *(sword *)(puVar12 + 0x21))) break;
          puVar3 = puVar12;
          sub_F0047104();
          if (puVar3 == (undefined4 *)0x0) {
            uVar4 = *(uint *)(param_2 + 0x14);
            goto loc_F0046BFC;
          }
          *puVar3 = 0;
          if (puVar12[0x1a] == 0) {
            puVar12[0x1a] = puVar3;
          }
          else {
            *(undefined4 **)puVar12[0x1b] = puVar3;
          }
          puVar12[0x1b] = puVar3;
loc_F0046AAC:
          sVar1 = *(sword *)((int)puVar12 + 0x8a);
        }
        piVar9 = (int *)puVar12[0x1a];
        for (iVar2 = (int)*(sword *)(puVar12 + 0x21); dword_F010F39C <= iVar2;
            iVar2 = iVar2 - dword_F010F39C) {
          piVar9 = (int *)*piVar9;
        }
        for (; uVar4 != 0; uVar4 = uVar4 - uVar8) {
          uVar8 = uVar4;
          if ((uint)(dword_F010F39C - iVar2) < uVar4) {
            uVar8 = dword_F010F39C - iVar2;
          }
          iVar11 = (int)piVar9 + iVar2;
          _uiomove(iVar11,uVar8,1,param_2);
          if (iVar11 != 0) {
            wVar7 = *(word *)(puVar12 + 0x10);
            goto loc_F0046ECC;
          }
          iVar2 = 0;
          puVar12[0x1f] = puVar12[0x1f] + uVar8;
          *(sword *)(puVar12 + 0x21) = *(sword *)(puVar12 + 0x21) + (sword)uVar8;
          piVar9 = (int *)*piVar9;
        }
        _smark(puVar12,0x42);
        if ((*(word *)(puVar12 + 0x22) & 1) != 0) {
          *(word *)(puVar12 + 0x22) = *(word *)(puVar12 + 0x22) & 0xfffe;
          _wakeup((int)puVar12 + 0x82);
        }
        if (puVar12[0x1c] != 0) {
          _selwakeup(puVar12[0x1c],*(word *)(puVar12 + 0x22) & 4);
          _thread_deallocate(puVar12[0x1c]);
          puVar12[0x1c] = 0;
          *(word *)(puVar12 + 0x22) = *(word *)(puVar12 + 0x22) & 0xfffb;
        }
loc_F0046BFC:
        if (uVar4 == 0) {
          wVar7 = *(word *)(puVar12 + 0x10);
          goto loc_F0046ECC;
        }
        sVar1 = *(sword *)((int)puVar12 + 0x82);
        goto loc_F0046950;
      }
      if ((*(word *)(param_2 + 0x10) & 4) == 0) {
        if ((_fifoinfo < uVar4) && (uVar8 < _fifoinfo)) goto loc_F0046A2C;
        wVar7 = *(word *)(puVar12 + 0x10);
        *(word *)(puVar12 + 0x22) = *(word *)(puVar12 + 0x22) | 2;
        *(word *)(puVar12 + 0x10) = wVar7 & 0xfffe;
        if ((wVar7 & 0x10) != 0) {
          *(word *)(puVar12 + 0x10) = wVar7 & 0xffee;
          _wakeup(puVar12);
        }
        uVar5 = 0x1a;
        puVar3 = puVar12 + 0x20;
        while( true ) {
          _sleep(puVar3,uVar5);
          if ((*(word *)(puVar12 + 0x10) & 1) == 0) break;
          *(word *)(puVar12 + 0x10) = *(word *)(puVar12 + 0x10) | 0x10;
          uVar5 = 10;
          puVar3 = puVar12;
        }
        *(word *)(puVar12 + 0x10) = *(word *)(puVar12 + 0x10) | 1;
        uVar4 = *(uint *)(param_2 + 0x14);
        goto loc_F0046BFC;
      }
      if ((_fifoinfo < uVar4) && (uVar8 < _fifoinfo)) {
loc_F0046A2C:
        uVar4 = _fifoinfo - puVar12[0x1f];
        sVar1 = *(sword *)(puVar12 + 0x21);
        goto loc_F0046A3C;
      }
loc_F0046C80:
      iVar11 = 0x23;
      if ((*(uint *)(*_active_u + 0x14) & 0x4000) != 0) {
        iVar11 = 0xb;
      }
    }
  }
  else {
    uVar4 = *(uint *)(param_2 + 0x14);
    if (uVar4 == 0) {
      wVar7 = *(word *)(puVar12 + 0x10);
      goto loc_F0046ECC;
    }
    uVar8 = puVar12[0x1f];
    if (uVar8 == 0) {
      do {
        if (*(sword *)(puVar12 + 0x20) == 0) {
          wVar7 = *(word *)(puVar12 + 0x10);
          goto loc_F0046ECC;
        }
        if ((*(word *)(param_2 + 0x10) & 4) != 0) goto loc_F0046C80;
        wVar7 = *(word *)(puVar12 + 0x10);
        *(word *)(puVar12 + 0x22) = *(word *)(puVar12 + 0x22) | 1;
        *(word *)(puVar12 + 0x10) = wVar7 & 0xfffe;
        if ((wVar7 & 0x10) != 0) {
          *(word *)(puVar12 + 0x10) = wVar7 & 0xffee;
          _wakeup(puVar12);
        }
        uVar5 = 0x1a;
        puVar3 = (undefined4 *)((int)puVar12 + 0x82);
        while( true ) {
          _sleep(puVar3,uVar5);
          if ((*(word *)(puVar12 + 0x10) & 1) == 0) break;
          *(word *)(puVar12 + 0x10) = *(word *)(puVar12 + 0x10) | 0x10;
          uVar5 = 10;
          puVar3 = puVar12;
        }
        uVar8 = puVar12[0x1f];
        *(word *)(puVar12 + 0x10) = *(word *)(puVar12 + 0x10) | 1;
      } while (uVar8 == 0);
      sVar1 = *(sword *)(puVar12 + 0x21);
    }
    else {
      sVar1 = *(sword *)(puVar12 + 0x21);
    }
    if ((int)sVar1 - (int)*(sword *)((int)puVar12 + 0x86) != puVar12[0x1f]) {
      _printf(aFifoReadPtrMis);
    }
    if (dword_F010F39C < *(sword *)((int)puVar12 + 0x86)) {
      _printf(aFifoReadRptrTo);
    }
    iVar10 = (int)*(sword *)((int)puVar12 + 0x8a);
    iVar2 = iVar10;
    .umul(iVar10,dword_F010F39C);
    if (iVar2 < *(sword *)(puVar12 + 0x21)) {
      _printf(aFifoReadWptrTo,(int)*(sword *)(puVar12 + 0x21),iVar10);
    }
    iVar2 = (int)*(sword *)((int)puVar12 + 0x86);
    iVar10 = puVar12[0x1a];
    if (uVar8 < uVar4) {
      uVar4 = uVar8;
    }
    while (uVar4 != 0) {
      uVar8 = uVar4;
      if ((uint)(dword_F010F39C - iVar2) < uVar4) {
        uVar8 = dword_F010F39C - iVar2;
      }
      iVar11 = iVar10 + iVar2;
      _uiomove(iVar11,uVar8,0,param_2);
      if (iVar11 != 0) {
        wVar7 = *(word *)(puVar12 + 0x10);
        goto loc_F0046ECC;
      }
      uVar4 = uVar4 - uVar8;
      puVar12[0x1f] = puVar12[0x1f] - uVar8;
      iVar6 = *(word *)((int)puVar12 + 0x86) + uVar8;
      *(sword *)((int)puVar12 + 0x86) = (sword)iVar6;
      iVar2 = 0;
      if (dword_F010F39C < iVar6 * 0x10000 >> 0x10) {
        _printf(aFifoReadRptrAf);
      }
      if (*(sword *)((int)puVar12 + 0x86) == dword_F010F39C) {
        *(undefined2 *)((int)puVar12 + 0x86) = 0;
        sub_F0047258(iVar10,puVar12);
        puVar12[0x1a] = iVar10;
        *(sword *)(puVar12 + 0x21) = *(sword *)(puVar12 + 0x21) - (sword)dword_F010F39C;
      }
    }
    _smark(puVar12,4);
    if ((*(word *)(puVar12 + 0x22) & 2) != 0) {
      *(word *)(puVar12 + 0x22) = *(word *)(puVar12 + 0x22) & 0xfffd;
      _wakeup(puVar12 + 0x20);
    }
    if (puVar12[0x1d] == 0) {
      wVar7 = *(word *)(puVar12 + 0x10);
      goto loc_F0046ECC;
    }
    _selwakeup(puVar12[0x1d],*(word *)(puVar12 + 0x22) & 8);
    _thread_deallocate(puVar12[0x1d]);
    puVar12[0x1d] = 0;
    *(word *)(puVar12 + 0x22) = *(word *)(puVar12 + 0x22) & 0xfff7;
  }
  wVar7 = *(word *)(puVar12 + 0x10);
loc_F0046ECC:
  *(word *)(puVar12 + 0x10) = wVar7 & 0xfffe;
  if ((wVar7 & 0x10) != 0) {
    *(word *)(puVar12 + 0x10) = wVar7 & 0xffee;
    _wakeup(puVar12);
  }
  *(undefined4 *)(param_2 + 8) = 0;
  return CONCAT44(param_2,iVar11);
loc_F0046C0C:
  iVar11 = 0x20;
  _psignal(*_active_u,0xd);
  wVar7 = *(word *)(puVar12 + 0x10);
  goto loc_F0046ECC;
}
/* GHIDRADEC_FUNCTION index=3413 start=0xf0046f08 */

undefined8 sub_F0046F08(int param_1,int param_2,undefined4 param_3)

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
  iVar1 = *(int *)(iVar2 + 0x38);
  (**(code **)(*(int *)(iVar1 + 0x1c) + 0x14))(iVar1,param_2,param_3);
  if (iVar1 == 0) {
    *(undefined4 *)(param_2 + 0x20) = *(undefined4 *)(iVar2 + 0x4c);
    *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(iVar2 + 0x50);
    *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)(iVar2 + 0x54);
    *(undefined4 *)(param_2 + 0x2c) = *(undefined4 *)(iVar2 + 0x58);
    *(undefined4 *)(param_2 + 0x30) = *(undefined4 *)(iVar2 + 0x5c);
    *(undefined4 *)(param_2 + 0x34) = *(undefined4 *)(iVar2 + 0x60);
    *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x7c);
    *(undefined4 *)(param_2 + 0x1c) = _fifoinfo;
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=3414 start=0xf0046f88 */

/* WARNING: Removing unreachable block (ram,0xf004701c) */
/* WARNING: Removing unreachable block (ram,0xf0047050) */
/* WARNING: Removing unreachable block (ram,0xf0046fd8) */

undefined8 sub_F0046F88(int param_1,int param_2)

{
  word wVar2;
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
  undefined4 uVar4;
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
  iVar3 = *(int *)(param_1 + 0x30);
  if (param_2 == 1) {
    if (*(int *)(iVar3 + 0x7c) != 0) {
      uVar4 = 1;
      goto locret_F0047074;
    }
    iVar1 = iVar3 + 0x70;
    _selthreadcache();
    if (iVar1 == 0) {
      uVar4 = 0;
      goto locret_F0047074;
    }
    wVar2 = *(word *)(iVar3 + 0x88) | 4;
  }
  else if (param_2 < 2) {
    if (param_2 != 0) {
      uVar4 = 0;
      goto locret_F0047074;
    }
    if (*(sword *)(iVar3 + 0x82) == 0) {
      uVar4 = 1;
      goto locret_F0047074;
    }
    iVar1 = iVar3 + 0x78;
    _selthreadcache();
    if (iVar1 == 0) {
      uVar4 = 0;
      goto locret_F0047074;
    }
    wVar2 = *(word *)(iVar3 + 0x88) | 0x10;
  }
  else {
    if (param_2 != 2) {
      uVar4 = 0;
      goto locret_F0047074;
    }
    if ((*(uint *)(iVar3 + 0x7c) < _fifoinfo) && (0 < *(sword *)(iVar3 + 0x82))) {
      uVar4 = 1;
      goto locret_F0047074;
    }
    iVar1 = iVar3 + 0x74;
    _selthreadcache();
    if (iVar1 == 0) {
      uVar4 = 0;
      goto locret_F0047074;
    }
    wVar2 = *(word *)(iVar3 + 0x88) | 8;
  }
  *(word *)(iVar3 + 0x88) = wVar2;
  uVar4 = 0;
locret_F0047074:
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=3415 start=0xf004707c */

/* WARNING: Removing unreachable block (ram,0xf00470a8) */
/* WARNING: Removing unreachable block (ram,0xf0047090) */
/* WARNING: Removing unreachable block (ram,0xf00470b8) */
/* WARNING: Removing unreachable block (ram,0xf0047084) */

sqword sub_F004707C(int param_1,uint param_2)

{
  undefined4 uVar1;
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
  _sunsave(iVar2);
  _spec_fsync(param_1,param_2);
  if (*(int *)(iVar2 + 0x38) == 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x30);
  }
  else {
    _vn_rele();
    *(undefined4 *)(iVar2 + 0x38) = 0;
    uVar1 = *(undefined4 *)(param_1 + 0x30);
  }
  _kfree(uVar1,0x8c);
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=3416 start=0xf00470c8 */

undefined8 sub_F00470C8(int param_1,int param_2)

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
/* GHIDRADEC_FUNCTION index=3417 start=0xf00470e0 */

undefined8 sub_F00470E0(undefined4 param_1,undefined4 param_2)

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
/* GHIDRADEC_FUNCTION index=3418 start=0xf00470ec */

/* WARNING: Removing unreachable block (ram,0xf00470f4) */

undefined8 sub_F00470EC(undefined4 param_1,undefined4 param_2)

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
  _panic(aFifoBadop);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3419 start=0xf0047104 */

/* WARNING: Removing unreachable block (ram,0xf0047158) */
/* WARNING: Removing unreachable block (ram,0xf0047178) */
/* WARNING: Removing unreachable block (ram,0xf00471b8) */

undefined8 sub_F0047104(undefined4 *param_1,undefined4 param_2)

{
  word wVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
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
  if (_fifo_alloc < dword_F010F3A0) {
    _fifo_alloc = _fifo_alloc + dword_F010F39C;
    _kmem_alloc_wired(_kernel_map,(undefined *)((int)register0x00000038 + -0xc));
    uVar3 = *(undefined4 *)((int)register0x00000038 + -0xc);
    *(sword *)((int)param_1 + 0x8a) = *(sword *)((int)param_1 + 0x8a) + 1;
  }
  else {
    wVar1 = *(word *)(param_1 + 0x10);
    *(word *)(param_1 + 0x10) = wVar1 & 0xfffe;
    if ((wVar1 & 0x10) != 0) {
      *(word *)(param_1 + 0x10) = wVar1 & 0xffee;
      _wakeup(param_1);
    }
    uVar3 = 0x1a;
    puVar2 = &_fifo_alloc;
    while( true ) {
      _sleep(puVar2,uVar3);
      if ((*(word *)(param_1 + 0x10) & 1) == 0) break;
      *(word *)(param_1 + 0x10) = *(word *)(param_1 + 0x10) | 0x10;
      uVar3 = 10;
      puVar2 = param_1;
    }
    uVar3 = 0;
    *(word *)(param_1 + 0x10) = *(word *)(param_1 + 0x10) | 1;
  }
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=3420 start=0xf0047258 */

/* WARNING: Removing unreachable block (ram,0xf00472b8) */
/* WARNING: Removing unreachable block (ram,0xf0047294) */

undefined8 sub_F0047258(undefined4 *param_1,int param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar1;
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
  *(sword *)(param_2 + 0x8a) = *(sword *)(param_2 + 0x8a) + -1;
  if (*(undefined4 **)(param_2 + 0x6c) == param_1) {
    *(undefined4 *)(param_2 + 0x6c) = 0;
    uVar1 = 0;
  }
  else {
    uVar1 = *param_1;
  }
  _kmem_free(_kernel_map,param_1,dword_F010F39C);
  if (dword_F010F3A0 <= _fifo_alloc) {
    _wakeup(&_fifo_alloc);
  }
  _fifo_alloc = _fifo_alloc - dword_F010F39C;
  return CONCAT44(DAT_f013ac00,uVar1);
}
/* GHIDRADEC_FUNCTION index=3421 start=0xf00472d8 */

undefined8 sub_F00472D8(undefined4 param_1,undefined4 param_2)

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
  return CONCAT44(param_2,0x400);
}
/* GHIDRADEC_FUNCTION index=3422 start=0xf00475c4 */

undefined8 sub_F00475C4(undefined4 *param_1)

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
  *param_1 = *(undefined4 *)
              (_stable +
              ((uint)(*(word *)((int)param_1 + 0x42) >> 8) + (*(word *)((int)param_1 + 0x42) & 0xff)
              & 0xf) * 4);
  *(undefined4 **)
   (_stable +
   ((uint)(*(word *)((int)param_1 + 0x42) >> 8) + (*(word *)((int)param_1 + 0x42) & 0xff) & 0xf) * 4
   ) = param_1;
  return CONCAT44(_stable,param_1);
}
/* GHIDRADEC_FUNCTION index=3423 start=0xf00478c4 */

undefined8 sub_F00478C4(uint param_1,int param_2,int param_3)

{
  sword sVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar3;
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
  puVar3 = *(undefined4 **)(_stable + (((param_1 & 0xffff) >> 8) + (param_1 & 0xff) & 0xf) * 4);
  if (puVar3 != (undefined4 *)0x0) {
    sVar1 = *(sword *)((int)puVar3 + 0x42);
    do {
      if (sVar1 == (sword)param_1) {
        if (puVar3[0xb] == param_3) {
          iVar2 = puVar3[0xe];
          if ((iVar2 == 0) || (param_2 == 0)) {
loc_F0047974:
            iVar2 = puVar3[0xe];
            goto loc_F0047978;
          }
          if (iVar2 == param_2) {
loc_F0047990:
            sVar1 = *(sword *)((int)puVar3 + 10);
          }
          else {
            if (iVar2 == 0) {
              iVar2 = puVar3[0xe];
loc_F0047978:
              if (iVar2 == 0) {
                if (param_2 == 0) goto loc_F0047990;
                puVar3 = (undefined4 *)*puVar3;
              }
              else {
                puVar3 = (undefined4 *)*puVar3;
              }
              goto loc_F00479A0;
            }
            if (*(int *)(iVar2 + 0x1c) != *(int *)(param_2 + 0x1c)) {
              iVar2 = puVar3[0xe];
              goto loc_F0047978;
            }
            (**(code **)(*(int *)(iVar2 + 0x1c) + 0x6c))(iVar2,param_2);
            if (iVar2 == 0) goto loc_F0047974;
            sVar1 = *(sword *)((int)puVar3 + 10);
          }
          *(sword *)((int)puVar3 + 10) = sVar1 + 1;
          goto locret_F00479B0;
        }
        puVar3 = (undefined4 *)*puVar3;
      }
      else {
        puVar3 = (undefined4 *)*puVar3;
      }
loc_F00479A0:
      if (puVar3 == (undefined4 *)0x0) goto loc_f00479ac;
      sVar1 = *(sword *)((int)puVar3 + 0x42);
    } while( true );
  }
  puVar3 = (undefined4 *)0x0;
locret_F00479B0:
  return CONCAT44(param_2,puVar3);
loc_f00479ac:
  puVar3 = (undefined4 *)0x0;
  goto locret_F00479B0;
}
/* GHIDRADEC_FUNCTION index=3424 start=0xf0047a38 */

/* WARNING: Removing unreachable block (ram,0xf0047aa8) */
/* WARNING: Removing unreachable block (ram,0xf0047a64) */

sqword sub_F0047A38(undefined4 param_1,uint param_2)

{
  word wVar1;
  undefined4 unaff_l0;
  undefined *puVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar3;
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
  if (dword_F012F56C == 0) {
    dword_F012F56C = 1;
    puVar2 = _stable;
    puVar3 = (undefined4 *)_stable._0_4_;
    do {
      if (puVar3 != (undefined4 *)0x0) {
        wVar1 = *(word *)(puVar3 + 2);
        do {
          if ((wVar1 & 0x80) == 0) {
            if (puVar3[0xb] == 3) {
              _bflush(puVar3 + 1,0xffffffff,0xffffffff);
              goto loc_F0047AB0;
            }
            puVar3 = (undefined4 *)*puVar3;
          }
          else {
loc_F0047AB0:
            puVar3 = (undefined4 *)*puVar3;
          }
          if (puVar3 == (undefined4 *)0x0) break;
          wVar1 = *(word *)(puVar3 + 2);
        } while( true );
      }
      puVar2 = (undefined *)((int)puVar2 + 4);
      if (_stable + 0x3f < puVar2) goto loc_F0047AD4;
      puVar3 = *(undefined4 **)puVar2;
    } while( true );
  }
locret_F0047AD8:
  return (qword)param_2 << 0x20;
loc_F0047AD4:
  dword_F012F56C = 0;
  goto locret_F0047AD8;
}
/* GHIDRADEC_FUNCTION index=3425 start=0xf0047ae0 */

undefined8 sub_F0047AE0(undefined4 param_1,undefined4 param_2)

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
/* GHIDRADEC_FUNCTION index=3426 start=0xf0047aec */

/* WARNING: Removing unreachable block (ram,0xf0047b90) */
/* WARNING: Removing unreachable block (ram,0xf0047c00) */
/* WARNING: Removing unreachable block (ram,0xf0047b7c) */
/* WARNING: Removing unreachable block (ram,0xf0047c10) */
/* WARNING: Removing unreachable block (ram,0xf0047c8c) */
/* WARNING: Removing unreachable block (ram,0xf0047c24) */

undefined8 sub_F0047AEC(int *param_1,undefined4 param_2)

{
  word wVar1;
  int iVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  int iVar4;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar5;
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
  iVar4 = *(int *)(*param_1 + 0x30);
  wVar1 = *(word *)(iVar4 + 0x42);
  switch(*(undefined4 *)(*param_1 + 0x28)) {
  case :
    iVar5 = (int)(sword)wVar1;
    if (wVar1 >> 8 < _nblkdev) {
      (**(code **)(_bdevsw + (uint)(wVar1 >> 8) * 0x18))(iVar5,param_2);
    }
    else {
      iVar5 = 6;
    }
    bVar6 = false;
    if (iVar5 == 0) {
      _set_blocksize(iVar4,(int)(sword)wVar1);
      bVar6 = true;
    }
    goto loc_F0047CAC;
  case :
  case :
    *(word *)((int)register0x00000038 + -10) = wVar1;
    while (wVar1 = *(word *)((int)register0x00000038 + -10), wVar1 >> 8 < _nchrdev) {
      iVar3 = (int)(sword)wVar1;
      iVar5 = *param_1;
      while (iVar2 = iVar3, _isclosing(iVar3,*(undefined4 *)(iVar5 + 0x28)), iVar2 != 0) {
        _sleep(iVar4,0x28);
        iVar5 = *param_1;
      }
      iVar5 = iVar3;
      (**(code **)(_cdevsw + (uint)(wVar1 >> 8) * 0x2c))
                (iVar3,param_2,(undefined *)((int)register0x00000038 + -10));
      if (*(sword *)((int)register0x00000038 + -10) == iVar3) goto loc_F0047CA8;
      if (((iVar5 != 0) && (iVar5 != 0xb)) && (bVar6 = iVar5 == 0, iVar5 != 0x11))
      goto loc_F0047CAC;
      iVar5 = *param_1;
      _specvp(iVar5,(int)*(sword *)((int)register0x00000038 + -10),4);
      iVar4 = *(int *)(iVar5 + 0x30);
      _vn_rele(*param_1);
      *param_1 = iVar5;
    }
    iVar5 = 6;
    goto locret_F0047CC0;
  :
    iVar5 = 0;
    break;
  case :
    _printf(aSpecOpenGotAVf);
  case :
    iVar5 = 0x2d;
  }
loc_F0047CA8:
  bVar6 = iVar5 == 0;
loc_F0047CAC:
  if (bVar6) {
    *(int *)(iVar4 + 100) = *(int *)(iVar4 + 100) + 1;
  }
locret_F0047CC0:
  return CONCAT44(param_2,iVar5);
}
/* GHIDRADEC_FUNCTION index=3427 start=0xf0047cc8 */

/* WARNING: Removing unreachable block (ram,0xf0047dcc) */
/* WARNING: Removing unreachable block (ram,0xf0047d40) */
/* WARNING: Removing unreachable block (ram,0xf0047d18) */
/* WARNING: Removing unreachable block (ram,0xf0047e18) */
/* WARNING: Removing unreachable block (ram,0xf0047dd4) */
/* WARNING: Removing unreachable block (ram,0xf0047cec) */

undefined8 sub_F0047CC8(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  word wVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined *puVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar6;
  int iVar7;
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
  *(undefined4 *)((int)register0x00000038 + 0x44) = param_1;
  *(undefined4 *)((int)register0x00000038 + 0x48) = param_2;
  *(int *)((int)register0x00000038 + 0x4c) = param_3;
  *(undefined4 *)((int)register0x00000038 + 0x50) = param_4;
  if (param_3 < 2) {
    iVar2 = dword_F0133DDC + 0x28;
    _setjmp();
    if (iVar2 != 0) {
      *(word *)(*(int *)(*(int *)((int)register0x00000038 + 0x44) + 0x30) + 0x40) =
           *(word *)(*(int *)(*(int *)((int)register0x00000038 + 0x44) + 0x30) + 0x40) & 0xfff7;
      _wakeup();
      uVar6 = 4;
      goto locret_F0047E24;
    }
    iVar4 = *(int *)((int)register0x00000038 + 0x44);
    iVar7 = *(int *)(iVar4 + 0x30);
    iVar2 = (int)*(sword *)(iVar7 + 0x42);
    *(int *)(iVar7 + 100) = *(int *)(iVar7 + 100) + -1;
    _stillopen(iVar2,*(undefined4 *)(iVar4 + 0x28));
    if (iVar2 != 0) {
      uVar6 = 0;
      goto locret_F0047E24;
    }
    wVar1 = *(word *)(iVar7 + 0x42);
    uVar3 = *(uint *)(*(int *)((int)register0x00000038 + 0x44) + 0x28);
    *(word *)((int)register0x00000038 + -10) = wVar1;
    if (uVar3 == 4) {
      iVar2 = (uint)(wVar1 >> 8) * 0x2c;
      puVar5 = _cdevsw;
      uVar6 = *(undefined4 *)((int)register0x00000038 + 0x48);
    }
    else {
      if (4 < uVar3) {
        if (uVar3 != 8) {
          uVar6 = 0;
          goto locret_F0047E24;
        }
        _printf(aSpecCloseGotAV);
        goto loc_F0047E20;
      }
      if (uVar3 != 3) {
        uVar6 = 0;
        goto locret_F0047E24;
      }
      _bflush(*(undefined4 *)(iVar7 + 0x3c),0xffffffff,0xffffffff);
      _binval(*(undefined4 *)(iVar7 + 0x3c));
      wVar1 = *(word *)((int)register0x00000038 + -10);
      uVar6 = *(undefined4 *)((int)register0x00000038 + 0x48);
      iVar2 = (uint)(wVar1 >> 8) * 0x18;
      puVar5 = _bdevsw;
    }
    (**(code **)(puVar5 + iVar2 + 4))((int)(sword)wVar1,uVar6);
    uVar6 = 0;
  }
  else {
loc_F0047E20:
    uVar6 = 0;
  }
locret_F0047E24:
  return CONCAT44(param_2,uVar6);
}
/* GHIDRADEC_FUNCTION index=3428 start=0xf0047e2c */

/* WARNING: Removing unreachable block (ram,0xf004810c) */
/* WARNING: Removing unreachable block (ram,0xf00480f0) */
/* WARNING: Removing unreachable block (ram,0xf0048080) */
/* WARNING: Removing unreachable block (ram,0xf0048000) */
/* WARNING: Removing unreachable block (ram,0xf0047fdc) */
/* WARNING: Removing unreachable block (ram,0xf0048030) */
/* WARNING: Removing unreachable block (ram,0xf0047f98) */
/* WARNING: Removing unreachable block (ram,0xf0047f60) */
/* WARNING: Removing unreachable block (ram,0xf0047ecc) */
/* WARNING: Removing unreachable block (ram,0xf0047e74) */
/* WARNING: Removing unreachable block (ram,0xf0047f50) */
/* WARNING: Removing unreachable block (ram,0xf0047f88) */
/* WARNING: Removing unreachable block (ram,0xf0048040) */
/* WARNING: Removing unreachable block (ram,0xf0047fcc) */
/* WARNING: Removing unreachable block (ram,0xf0048010) */
/* WARNING: Removing unreachable block (ram,0xf0047f38) */
/* WARNING: Removing unreachable block (ram,0xf0048100) */
/* WARNING: Removing unreachable block (ram,0xf00480cc) */
/* WARNING: Removing unreachable block (ram,0xf00480b0) */
/* WARNING: Removing unreachable block (ram,0xf0047e44) */
/* WARNING: Removing unreachable block (ram,0xf0047e68) */

undefined8 sub_F0047E2C(int param_1,int param_2,uint param_3,uint param_4)

{
  word wVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  code *pcVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  int iVar8;
  undefined4 unaff_l5;
  uint *puVar9;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar10;
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
  iVar8 = *(int *)(param_1 + 0x30);
  wVar1 = *(word *)(iVar8 + 0x42);
  if (1 < param_3) {
    _panic(aSpecRdwr);
  }
  if (param_3 == 0) {
    if (*(int *)(param_2 + 0x14) != 0) {
      _smark(iVar8,4);
      iVar10 = *(int *)(param_1 + 0x28);
      goto loc_F0047E80;
    }
  }
  else {
    iVar10 = *(int *)(param_1 + 0x28);
loc_F0047E80:
    if (iVar10 == 4) {
      if (param_3 == 0) {
        pcVar6 = *(code **)(DAT_f011c9f8 + (uint)(wVar1 >> 8) * 0x2c);
      }
      else {
        _smark(iVar8,0x42);
        pcVar6 = *(code **)(DAT_f011c9f8 + (uint)(wVar1 >> 8) * 0x2c + 4);
      }
      iVar2 = (int)(sword)wVar1;
      (*pcVar6)(iVar2,param_2);
      goto locret_F0048138;
    }
    iVar2 = 0x2d;
    if (iVar10 != 3) goto locret_F0048138;
    if (*(int *)(param_2 + 0x14) != 0) {
      puVar9 = *(uint **)(iVar8 + 0x3c);
      iVar10 = *(int *)(param_2 + 8);
      while( true ) {
        iVar2 = iVar10;
        .udiv(iVar10,0x2000);
        .urem(iVar10,0x2000);
        iVar7 = 0x2000 - iVar10;
        if (*(int *)(param_2 + 0x14) < 0x2000 - iVar10) {
          iVar7 = *(int *)(param_2 + 0x14);
        }
        iVar3 = 0x2000;
        .udiv(0x2000,*(undefined4 *)(iVar8 + 0x48));
        iVar4 = iVar2;
        .umul(iVar2,iVar3);
        _rablock = iVar4 + iVar3;
        _rasize = 0x2000;
        puVar5 = puVar9;
        if (param_3 == 0) {
          if (iVar4 < 0) {
            puVar5 = (uint *)0x2000;
            _geteblk();
            _bzero(puVar5[8],puVar5[5]);
            puVar5[10] = 0;
          }
          else if (*(int *)(iVar8 + 0x44) + 1 == iVar2) {
            _breada(puVar9,iVar4,0x2000,_rablock,0x2000);
          }
          else {
            _bread(puVar9,iVar4,0x2000);
          }
          *(int *)(iVar8 + 0x44) = iVar2;
        }
        else if (iVar7 == 0x2000) {
          _getblk(puVar9,iVar4,0x2000);
        }
        else {
          _bread(puVar9,iVar4,0x2000);
        }
        if ((int)(puVar5[5] - puVar5[10]) < iVar7) {
          iVar7 = puVar5[5] - puVar5[10];
        }
        if ((*puVar5 & 4) != 0) break;
        iVar2 = puVar5[8] + iVar10;
        _uiomove(iVar2,iVar7,param_3,param_2);
        if (param_3 == 0) {
          if (iVar7 + iVar10 == 0x2000) {
            *puVar5 = *puVar5 | 0x80;
          }
          _brelse(puVar5);
        }
        else {
          if ((param_4 & 4) == 0) {
            if (iVar7 + iVar10 == 0x2000) {
              *puVar5 = *puVar5 | 0x80;
              _bawrite();
            }
            else {
              _bdwrite(puVar5);
            }
          }
          else {
            _bwrite(puVar5);
          }
          _smark(iVar8,0x42);
        }
        if (((iVar2 != 0) || (*(int *)(param_2 + 0x14) < 1)) || (iVar7 == 0)) goto locret_F0048138;
        iVar10 = *(int *)(param_2 + 8);
      }
      iVar2 = 5;
      _brelse(puVar5,iVar7);
      goto locret_F0048138;
    }
  }
  iVar2 = 0;
locret_F0048138:
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=3429 start=0xf0048140 */

/* WARNING: Removing unreachable block (ram,0xf0048158) */

undefined8 sub_F0048140(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  word wVar1;
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
  if (*(int *)(param_1 + 0x28) != 4) {
    _panic(aSpecIoctl);
  }
  wVar1 = *(word *)(iVar2 + 0x42);
  iVar2 = (int)(sword)wVar1;
  (**(code **)(DAT_f011ca00 + (uint)(wVar1 >> 8) * 0x2c))(iVar2,param_2,param_3,param_4);
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=3430 start=0xf00481ac */

/* WARNING: Removing unreachable block (ram,0xf00481c4) */

undefined8 sub_F00481AC(int param_1,undefined4 param_2)

{
  word wVar1;
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
  if (*(int *)(param_1 + 0x28) != 4) {
    _panic(aSpecSelect);
  }
  wVar1 = *(word *)(iVar2 + 0x42);
  iVar2 = (int)(sword)wVar1;
  (**(code **)(DAT_f011ca0c + (uint)(wVar1 >> 8) * 0x2c))(iVar2,param_2);
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=3431 start=0xf0048210 */

/* WARNING: Removing unreachable block (ram,0xf0048288) */
/* WARNING: Removing unreachable block (ram,0xf0048258) */
/* WARNING: Removing unreachable block (ram,0xf0048240) */
/* WARNING: Removing unreachable block (ram,0xf0048270) */
/* WARNING: Removing unreachable block (ram,0xf00482a4) */
/* WARNING: Removing unreachable block (ram,0xf0048220) */

sqword sub_F0048210(int param_1,uint param_2)

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
  iVar1 = (int)*(sword *)(*_active_u + 0x30);
  _get_posix_proc();
  *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) | 0x80000000;
  iVar2 = *(int *)(param_1 + 0x30);
  _sunsave(iVar2);
  if (*(int *)(iVar2 + 0x38) != 0) {
    _spec_fsync(param_1,param_2);
  }
  if (*(int *)(iVar2 + 0x38) != 0) {
    _vn_rele();
    *(undefined4 *)(iVar2 + 0x38) = 0;
    if (*(int *)(iVar2 + 0x3c) != 0) {
      _vn_rele();
    }
  }
  *(uint *)(iVar1 + 0x18) = *(uint *)(iVar1 + 0x18) & 0x7fffffff;
  _kfree(iVar2,0x68);
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=3432 start=0xf00482b4 */

/* WARNING: Removing unreachable block (ram,0xf00482d8) */
/* WARNING: Removing unreachable block (ram,0xf00482cc) */

undefined8 sub_F00482B4(int param_1,int *param_2,undefined4 param_3)

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
  iVar2 = *(int *)(param_1 + 0x30);
  iVar1 = *(int *)(iVar2 + 0x38);
  if (iVar1 == 0) {
    _getthetime((undefined *)((int)register0x00000038 + -0x10));
    _bzero(param_2,0x40);
    param_2[6] = *(int *)(iVar2 + 0x48);
    param_2[8] = *(int *)((int)register0x00000038 + -0x10);
    param_2[9] = *(int *)((int)register0x00000038 + -0xc);
    param_2[10] = *(int *)((int)register0x00000038 + -0x10);
    param_2[0xb] = *(int *)((int)register0x00000038 + -0xc);
    param_2[0xc] = *(int *)((int)register0x00000038 + -0x10);
    param_2[0xd] = *(int *)((int)register0x00000038 + -0xc);
    iVar1 = *(int *)(param_1 + 0x28);
  }
  else {
    (**(code **)(*(int *)(iVar1 + 0x1c) + 0x14))(iVar1,param_2,param_3);
    if (iVar1 != 0) goto locret_F00483B0;
    param_2[8] = *(int *)(iVar2 + 0x4c);
    param_2[9] = *(int *)(iVar2 + 0x50);
    param_2[10] = *(int *)(iVar2 + 0x54);
    param_2[0xb] = *(int *)(iVar2 + 0x58);
    param_2[0xc] = *(int *)(iVar2 + 0x5c);
    iVar1 = *param_2;
    param_2[0xd] = *(int *)(iVar2 + 0x60);
  }
  if (iVar1 == 3) {
    (**(code **)(*(int *)(param_1 + 0x1c) + 0x80))();
    param_2[7] = param_1;
  }
  else {
    if (iVar1 != 4) {
      iVar1 = 0;
      goto locret_F00483B0;
    }
    param_2[7] = 0x2000;
  }
  iVar1 = 0;
locret_F00483B0:
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=3433 start=0xf00484f0 */

undefined8 sub_F00484F0(int param_1,undefined4 param_2)

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
  return CONCAT44(param_2,*(undefined4 *)(*(int *)(param_1 + 0x30) + 0x48));
}
/* GHIDRADEC_FUNCTION index=3434 start=0xf0048660 */

undefined8 sub_F0048660(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
  iVar1 = (int)(sword)*(word *)(param_1 + 0x2c);
  (**(code **)(DAT_f011c7b8 + (uint)(*(word *)(param_1 + 0x2c) >> 8) * 0x18))
            (iVar1,param_2,param_3,param_4);
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=3435 start=0xf00486a8 */

undefined8 sub_F00486A8(undefined4 param_1,undefined4 param_2)

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
/* GHIDRADEC_FUNCTION index=3436 start=0xf00486f8 */

undefined8 sub_F00486F8(int param_1,int param_2)

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
/* GHIDRADEC_FUNCTION index=3437 start=0xf0048780 */

sqword sub_F0048780(int param_1,uint param_2)

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
  (**(code **)(DAT_f011c7b4 + (uint)(*(word *)(*(int *)(param_1 + 0x40) + 0x2c) >> 8) * 0x18))();
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=3438 start=0xf004ba68 */

/* WARNING: Removing unreachable block (ram,0xf004bc68) */
/* WARNING: Removing unreachable block (ram,0xf004bc24) */
/* WARNING: Removing unreachable block (ram,0xf004bad0) */
/* WARNING: Removing unreachable block (ram,0xf004bb2c) */
/* WARNING: Removing unreachable block (ram,0xf004bc54) */
/* WARNING: Removing unreachable block (ram,0xf004bccc) */
/* WARNING: Removing unreachable block (ram,0xf004bac0) */

undefined8 sub_F004BA68(int param_1,char *param_2,uint param_3,int *param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  undefined4 unaff_l0;
  int *piVar5;
  undefined4 unaff_l1;
  uint uVar6;
  uint uVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  int iVar8;
  undefined4 unaff_l5;
  int iVar9;
  undefined4 unaff_l6;
  int iVar10;
  undefined4 unaff_l7;
  uint uVar11;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  uint uVar12;
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
  iVar9 = 0;
  iVar8 = 0;
  uVar7 = 0;
  uVar12 = 0;
  uVar6 = 0;
  uVar11 = *(int *)(param_1 + 0x70) + 0x3ffU & 0xfffffc00;
  iVar10 = (param_3 + 4 & 0xfffffffc) + 8;
  if (uVar11 != 0) {
    do {
      if ((uVar6 & ~*(uint *)(*(int *)(param_1 + 0x50) + 0x48)) == 0) {
        if (iVar8 != 0) {
          _brelse(iVar8);
        }
        iVar8 = param_1;
        _blkatoff(param_1,uVar6,0);
        uVar7 = 0;
        if (iVar8 != 0) {
          iVar1 = *param_4;
          goto loc_F004BAE8;
        }
loc_F004BC70:
        iVar8 = (int)*(char *)(dword_F0133DDC + 0x38);
        goto locret_F004BCF8;
      }
      iVar1 = *param_4;
loc_F004BAE8:
      if (iVar1 == 0) {
        if ((uVar7 & 0x3ff) == 0) {
          param_4[1] = -1;
          iVar9 = 0;
          iVar1 = *(int *)(iVar8 + 0x20);
        }
        else {
          iVar1 = *(int *)(iVar8 + 0x20);
        }
      }
      else {
        iVar1 = *(int *)(iVar8 + 0x20);
      }
      piVar5 = (int *)(iVar1 + uVar7);
      if ((*(sword *)(piVar5 + 1) == 0) ||
         (iVar2 = param_1, sub_F004CCF8(param_1,piVar5,uVar7,uVar6), iVar2 != 0)) {
        uVar3 = 0x400 - (uVar7 & 0x3ff);
      }
      else {
        if (*param_4 == 2) {
          iVar1 = *piVar5;
        }
        else {
          uVar3 = (uint)*(word *)(piVar5 + 1);
          if (*(int *)(iVar1 + uVar7) != 0) {
            uVar3 = (uVar3 - 8) - (*(word *)((int)piVar5 + 6) + 4 & 0xfffffffc);
          }
          if (0 < (int)uVar3) {
            if ((int)uVar3 < iVar10) {
              if (*param_4 != 0) {
                iVar1 = *piVar5;
                goto loc_F004BBEC;
              }
              iVar9 = iVar9 + uVar3;
              if (param_4[1] == -1) {
                param_4[1] = uVar6;
              }
              if (iVar9 < iVar10) goto loc_F004BBE8;
              *param_4 = 1;
              uVar3 = (uVar6 + *(word *)(piVar5 + 1)) - param_4[1];
            }
            else {
              *param_4 = 2;
              param_4[1] = uVar6;
              uVar3 = (uint)*(word *)(piVar5 + 1);
            }
            param_4[2] = uVar3;
          }
loc_F004BBE8:
          iVar1 = *piVar5;
        }
loc_F004BBEC:
        if (iVar1 == 0) {
          uVar3 = (uint)*(word *)(piVar5 + 1);
          uVar12 = uVar6;
        }
        else if (*(word *)((int)piVar5 + 6) == param_3) {
          if (*param_2 == *(char *)(piVar5 + 2)) {
            pcVar4 = param_2;
            _bcmp(param_2,piVar5 + 2,param_3);
            if (pcVar4 == (char *)0x0) {
              *(uint *)(param_1 + 0x4c) = uVar6;
              if (*(int *)(param_1 + 0x48) == *piVar5) {
                *param_5 = param_1;
                *(sword *)(param_1 + 0x12) = *(sword *)(param_1 + 0x12) + 1;
              }
              else {
                iVar9 = (int)*(sword *)(param_1 + 0x46);
                _iget(iVar9,*(undefined4 *)(param_1 + 0x50));
                *param_5 = iVar9;
                if (iVar9 == 0) {
                  _brelse(iVar8);
                  goto loc_F004BC70;
                }
              }
              *param_4 = 3;
              param_4[1] = uVar6;
              param_4[2] = uVar6 - uVar12;
              param_4[3] = iVar8;
              param_4[4] = (int)piVar5;
              goto loc_F004BCF4;
            }
            uVar3 = (uint)*(word *)(piVar5 + 1);
            uVar12 = uVar6;
          }
          else {
            uVar3 = (uint)*(word *)(piVar5 + 1);
            uVar12 = uVar6;
          }
        }
        else {
          uVar3 = (uint)*(word *)(piVar5 + 1);
          uVar12 = uVar6;
        }
      }
      uVar6 = uVar6 + uVar3;
      uVar7 = uVar7 + uVar3;
    } while (uVar6 < uVar11);
  }
  if (iVar8 == 0) {
    iVar8 = *param_4;
  }
  else {
    _brelse(iVar8);
    iVar8 = *param_4;
  }
  if (iVar8 == 0) {
    param_4[1] = uVar11;
    param_4[2] = 0x400;
    *param_5 = 0;
  }
  else {
    *param_5 = 0;
  }
loc_F004BCF4:
  iVar8 = 0;
locret_F004BCF8:
  return CONCAT44(param_2,iVar8);
}
/* GHIDRADEC_FUNCTION index=3439 start=0xf004bd00 */

/* WARNING: Removing unreachable block (ram,0xf004bec0) */
/* WARNING: Removing unreachable block (ram,0xf004be4c) */
/* WARNING: Removing unreachable block (ram,0xf004be24) */
/* WARNING: Removing unreachable block (ram,0xf004bdec) */
/* WARNING: Removing unreachable block (ram,0xf004be44) */
/* WARNING: Removing unreachable block (ram,0xf004beb4) */
/* WARNING: Removing unreachable block (ram,0xf004bef0) */
/* WARNING: Removing unreachable block (ram,0xf004bd4c) */

undefined8
sub_F004BD00(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,int param_6)

{
  sword sVar1;
  word wVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar5;
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
  iVar4 = *(int *)((int)register0x00000038 + 0x5c);
  if ((*(int *)(param_6 + 0x30) != *(int *)(param_3 + 0x30)) ||
     (*(int *)(param_6 + 0x30) != *(int *)(param_2 + 0x30))) {
    iVar5 = 0x12;
    goto locret_F004BF08;
  }
  if (*(int *)(param_2 + 0x48) == *(int *)(param_6 + 0x48)) {
    iVar5 = -1;
    goto locret_F004BF08;
  }
  iVar5 = param_3;
  _iaccess(param_3,0x80);
  if (iVar5 != 0) goto locret_F004BF08;
  if (((*(word *)(param_3 + 100) & 0x200) == 0) ||
     (sVar1 = *(sword *)(*(int *)(_active_u + 0x1c) + 2), sVar1 == 0)) {
loc_F004BDB0:
    wVar2 = *(word *)(param_2 + 100);
  }
  else {
    if (sVar1 != *(sword *)(param_3 + 0x68)) {
      iVar5 = 1;
      if (*(sword *)(param_6 + 0x68) != sVar1) goto locret_F004BF08;
      goto loc_F004BDB0;
    }
    wVar2 = *(word *)(param_2 + 100);
  }
  bVar6 = (wVar2 & 0xf000) == 0x4000;
  if ((*(word *)(param_6 + 100) & 0xf000) == 0x4000) {
    if (!bVar6) {
      iVar5 = 0x15;
      goto locret_F004BF08;
    }
    iVar3 = param_6;
    sub_F004CDC4(param_6,*(undefined4 *)(param_3 + 0x48));
    iVar5 = 0x42;
    if ((iVar3 == 0) || (2 < *(sword *)(param_6 + 0x66))) goto locret_F004BF08;
  }
  else {
    iVar5 = 0x14;
    if (bVar6) goto locret_F004BF08;
  }
  _dnlc_remove(param_3 + 0xc,param_4);
  **(undefined4 **)(iVar4 + 0x10) = *(undefined4 *)(param_2 + 0x48);
  _dnlc_enter(param_3 + 0xc,param_4,param_2 + 0xc,0);
  _bwrite(*(undefined4 *)(iVar4 + 0xc));
  *(undefined4 *)(iVar4 + 0xc) = 0;
  iVar5 = (int)*(char *)(dword_F0133DDC + 0x38);
  if (iVar5 == 0) {
    *(word *)(param_3 + 0x44) = *(word *)(param_3 + 0x44) | 0x42;
    *(sword *)(param_6 + 0x66) = *(sword *)(param_6 + 0x66) + -1;
    *(word *)(param_6 + 0x44) = *(word *)(param_6 + 0x44) | 0x40;
    if (bVar6) {
      sVar1 = *(sword *)(param_6 + 0x66);
      *(sword *)(param_6 + 0x66) = sVar1 + -1;
      if (sVar1 != 1) {
        _panic(aDirenterTarget);
      }
      _itrunc(param_6,0);
      *(sword *)(param_3 + 0x66) = *(sword *)(param_3 + 0x66) + -1;
      *(word *)(param_3 + 0x44) = *(word *)(param_3 + 0x44) | 0x40;
      if ((param_1 != param_3) &&
         (iVar5 = param_2, sub_F004BF10(param_2,param_1,param_3), iVar5 != 0)) goto locret_F004BF08;
    }
    iVar5 = 0;
  }
locret_F004BF08:
  return CONCAT44(param_2,iVar5);
}
/* GHIDRADEC_FUNCTION index=3440 start=0xf004bf10 */

/* WARNING: Removing unreachable block (ram,0xf004c1f8) */
/* WARNING: Removing unreachable block (ram,0xf004c1a8) */
/* WARNING: Removing unreachable block (ram,0xf004c128) */
/* WARNING: Removing unreachable block (ram,0xf004c0d8) */
/* WARNING: Removing unreachable block (ram,0xf004c07c) */
/* WARNING: Removing unreachable block (ram,0xf004c044) */
/* WARNING: Removing unreachable block (ram,0xf004bfac) */
/* WARNING: Removing unreachable block (ram,0xf004bf98) */
/* WARNING: Removing unreachable block (ram,0xf004c01c) */
/* WARNING: Removing unreachable block (ram,0xf004c058) */
/* WARNING: Removing unreachable block (ram,0xf004c084) */
/* WARNING: Removing unreachable block (ram,0xf004c110) */
/* WARNING: Removing unreachable block (ram,0xf004c174) */
/* WARNING: Removing unreachable block (ram,0xf004c1c0) */
/* WARNING: Removing unreachable block (ram,0xf004c22c) */
/* WARNING: Removing unreachable block (ram,0xf004bf30) */

undefined8 sub_F004BF10(int param_1,int param_2,int param_3)

{
  word wVar1;
  int iVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  int iVar4;
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
  wVar1 = *(word *)(param_1 + 0x44);
  iVar3 = 0;
  if ((wVar1 & 1) != 0) {
    do {
      *(word *)(param_1 + 0x44) = wVar1 | 0x10;
      _sleep(param_1,10);
      wVar1 = *(word *)(param_1 + 0x44);
    } while ((wVar1 & 1) != 0);
    wVar1 = *(word *)(param_1 + 0x44);
  }
  *(word *)(param_1 + 0x44) = wVar1 | 1;
  if ((*(sword *)(param_1 + 0x66) == 0) || (*(uint *)(param_1 + 0x70) < 0x18)) {
    *(word *)(param_1 + 0x44) = wVar1 & 0xfffe;
    if ((wVar1 & 0x10) != 0) {
      *(word *)(param_1 + 0x44) = wVar1 & 0xffee;
      _wakeup(param_1);
      iVar3 = 0;
      goto locret_F004C238;
    }
loc_F004C1E4:
    iVar3 = 0;
  }
  else {
    iVar4 = param_1;
    _blkatoff(param_1,0,(undefined *)((int)register0x00000038 + -0xc));
    iVar2 = *(int *)((int)register0x00000038 + -0xc);
    if (iVar4 == 0) {
      iVar3 = (int)*(char *)(dword_F0133DDC + 0x38);
      bVar5 = true;
    }
    else {
      bVar5 = iVar4 == 0;
      if (*(int *)(iVar2 + 0xc) != *(int *)(param_3 + 0x48)) {
        if ((*(sword *)(iVar2 + 0x12) == 2) &&
           ((*(uint *)(iVar2 + 0x14) & 0xffff0000) == 0x2e2e0000)) {
          *(sword *)(param_3 + 0x66) = *(sword *)(param_3 + 0x66) + 1;
          *(word *)(param_3 + 0x44) = *(word *)(param_3 + 0x44) | 0x40;
          _iupdat(param_3,1);
          _dnlc_remove(param_1 + 0xc,&asc_F010EA60);
          *(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 0xc) =
               *(undefined4 *)(param_3 + 0x48);
          _dnlc_enter(param_1 + 0xc,&asc_F010EA68,param_3 + 0xc,0);
          _bwrite(iVar4);
          iVar3 = (int)*(char *)(dword_F0133DDC + 0x38);
          iVar4 = 0;
          if (iVar3 == 0) {
            wVar1 = *(word *)(param_1 + 0x44);
            *(word *)(param_1 + 0x44) = wVar1 & 0xfffe;
            if ((wVar1 & 0x10) != 0) {
              *(word *)(param_1 + 0x44) = wVar1 & 0xffee;
              _wakeup(param_1);
            }
            if (param_2 == 0) {
              iVar3 = 0;
              goto locret_F004C238;
            }
            wVar1 = *(word *)(param_3 + 0x44);
            *(word *)(param_3 + 0x44) = wVar1 & 0xfffe;
            if ((wVar1 & 0x10) == 0) goto loc_F004C130;
            *(word *)(param_3 + 0x44) = wVar1 & 0xffee;
            _wakeup(param_3);
            wVar1 = *(word *)(param_2 + 0x44);
            while ((wVar1 & 1) != 0) {
              *(word *)(param_2 + 0x44) = wVar1 | 0x10;
              _sleep(param_2,10);
loc_F004C130:
              wVar1 = *(word *)(param_2 + 0x44);
            }
            *(word *)(param_2 + 0x44) = *(word *)(param_2 + 0x44) | 1;
            if (*(sword *)(param_2 + 0x66) != 0) {
              *(sword *)(param_2 + 0x66) = *(sword *)(param_2 + 0x66) + -1;
              *(word *)(param_2 + 0x44) = *(word *)(param_2 + 0x44) | 0x40;
              _iupdat(param_2,1);
            }
            wVar1 = *(word *)(param_2 + 0x44);
            *(word *)(param_2 + 0x44) = wVar1 & 0xfffe;
            if ((wVar1 & 0x10) == 0) goto loc_F004C1C8;
            *(word *)(param_2 + 0x44) = wVar1 & 0xffee;
            _wakeup(param_2);
            wVar1 = *(word *)(param_3 + 0x44);
            while ((wVar1 & 1) != 0) {
              *(word *)(param_3 + 0x44) = wVar1 | 0x10;
              _sleep(param_3,10);
loc_F004C1C8:
              wVar1 = *(word *)(param_3 + 0x44);
            }
            *(word *)(param_3 + 0x44) = *(word *)(param_3 + 0x44) | 1;
            goto loc_F004C1E4;
          }
        }
        else {
          sub_F004CD8C(param_1,aMangledEntry,0);
          iVar3 = 0x16;
        }
        bVar5 = iVar4 == 0;
      }
    }
    if (bVar5) {
      wVar1 = *(word *)(param_1 + 0x44);
    }
    else {
      _brelse(iVar4);
      wVar1 = *(word *)(param_1 + 0x44);
    }
    *(word *)(param_1 + 0x44) = wVar1 & 0xfffe;
    if ((wVar1 & 0x10) != 0) {
      *(word *)(param_1 + 0x44) = wVar1 & 0xffee;
      _wakeup(param_1);
    }
  }
locret_F004C238:
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=3441 start=0xf004c32c */

/* WARNING: Removing unreachable block (ram,0xf004c4e8) */
/* WARNING: Removing unreachable block (ram,0xf004c424) */
/* WARNING: Removing unreachable block (ram,0xf004c374) */
/* WARNING: Removing unreachable block (ram,0xf004c3a0) */
/* WARNING: Removing unreachable block (ram,0xf004c52c) */
/* WARNING: Removing unreachable block (ram,0xf004c45c) */
/* WARNING: Removing unreachable block (ram,0xf004c354) */

undefined8 sub_F004C32C(uint param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  undefined4 unaff_l1;
  sword sVar8;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar9;
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
  uVar5 = param_2[1] + param_2[2];
  if (*param_2 == 0) {
    if ((param_2[1] & 0x3ff) != 0) {
      _panic(aDirprepareentr);
    }
    if (*(int *)(*(int *)(param_1 + 0x50) + 0x34) < 0x400) {
      _panic(aDirblksizFsize);
      iVar4 = *(int *)(param_1 + 0x50);
    }
    else {
      iVar4 = *(int *)(param_1 + 0x50);
    }
    uVar1 = param_1;
    _bmap(param_1,param_2[1] >> ((byte)*(undefined4 *)(iVar4 + 0x50) & 0x1f),0,
          (param_2[1] & ~*(uint *)(iVar4 + 0x48)) + 0x400,0);
    if (((int)uVar1 < 1) || (*(char *)(dword_F0133DDC + 0x38) != '\0')) {
      iVar4 = 0x1c;
      if (*(char *)(dword_F0133DDC + 0x38) != 0) {
        iVar4 = (int)*(char *)(dword_F0133DDC + 0x38);
      }
      goto locret_F004C53C;
    }
    *(uint *)(param_1 + 0x70) = uVar5;
    *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 0x42;
  }
  else if (*(uint *)(param_1 + 0x70) < uVar5) {
    *(uint *)(param_1 + 0x70) = uVar5 + 0x3ff & 0xfffffc00;
    *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 0x42;
  }
  _blkatoff(param_1,param_2[1],param_2 + 4);
  param_2[3] = param_1;
  if (param_1 == 0) {
    iVar4 = (int)*(char *)(dword_F0133DDC + 0x38);
  }
  else {
    piVar6 = (int *)param_2[4];
    if (*param_2 == 0) {
      _bzero(piVar6,0x400);
      *(undefined2 *)(piVar6 + 1) = 0x400;
    }
    else if (*param_2 < 3) {
      uVar5 = (uint)*(word *)(piVar6 + 1);
      iVar9 = (*(word *)((int)piVar6 + 6) + 4 & 0xfffffffc) + 8;
      iVar4 = uVar5 - iVar9;
      sVar8 = (sword)iVar4;
      piVar7 = piVar6;
      if ((int)uVar5 < (int)param_2[2]) {
        iVar2 = *piVar6;
        while( true ) {
          iVar3 = (int)piVar6 + uVar5;
          if (iVar2 == 0) {
            iVar4 = iVar4 + iVar9;
          }
          else {
            *(sword *)(piVar7 + 1) = (sword)iVar9;
            piVar7 = (int *)((int)piVar7 + iVar9);
          }
          iVar9 = (*(word *)(iVar3 + 6) + 4 & 0xfffffffc) + 8;
          iVar4 = iVar4 + ((uint)*(word *)(iVar3 + 4) - iVar9);
          sVar8 = (sword)iVar4;
          uVar5 = uVar5 + *(word *)(iVar3 + 4);
          _bcopy(iVar3,piVar7,iVar9);
          if ((int)param_2[2] <= (int)uVar5) break;
          iVar2 = *piVar7;
        }
      }
      piVar6 = piVar7;
      if (*piVar6 == 0) {
        *(sword *)(piVar6 + 1) = sVar8 + (sword)iVar9;
      }
      else {
        *(sword *)(piVar6 + 1) = (sword)iVar9;
        piVar6 = (int *)((int)piVar6 + iVar9);
        *(sword *)(piVar6 + 1) = sVar8;
      }
    }
    else {
      _panic(aDirprepareentr_0);
    }
    param_2[4] = (uint)piVar6;
    iVar4 = 0;
  }
locret_F004C53C:
  return CONCAT44(param_2,iVar4);
}
/* GHIDRADEC_FUNCTION index=3442 start=0xf004c544 */

/* WARNING: Removing unreachable block (ram,0xf004c708) */
/* WARNING: Removing unreachable block (ram,0xf004c694) */
/* WARNING: Removing unreachable block (ram,0xf004c59c) */
/* WARNING: Removing unreachable block (ram,0xf004c570) */
/* WARNING: Removing unreachable block (ram,0xf004c670) */
/* WARNING: Removing unreachable block (ram,0xf004c6ac) */
/* WARNING: Removing unreachable block (ram,0xf004c6cc) */
/* WARNING: Removing unreachable block (ram,0xf004c558) */

undefined8 sub_F004C544(int param_1,int *param_2,int *param_3)

{
  sword sVar1;
  word wVar2;
  int iVar3;
  undefined2 uVar5;
  int iVar4;
  uint uVar6;
  undefined4 uVar7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar8;
  undefined4 unaff_l3;
  int iVar9;
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
  iVar9 = 0;
  if (param_3 == (int *)0x0) {
    _panic(aDirmakeinodeNo);
  }
  iVar8 = *param_3;
  if (iVar8 == 2) {
    uVar7 = *(undefined4 *)(param_1 + 0x50);
    _dirpref(uVar7);
  }
  else {
    uVar7 = *(undefined4 *)(param_1 + 0x48);
  }
  uVar6 = *(uint *)(_vttoif_tab + iVar8 * 4);
  wVar2 = *(word *)(param_3 + 1);
  iVar3 = param_1;
  _ialloc(param_1,uVar7,uVar6 | wVar2);
  if (iVar3 == 0) {
    iVar9 = (int)*(char *)(dword_F0133DDC + 0x38);
  }
  else {
    *(sword *)(iVar3 + 100) = (sword)(uVar6 | wVar2);
    *(word *)(iVar3 + 0x44) = *(word *)(iVar3 + 0x44) | 0x46;
    if ((iVar8 - 3U < 2) || (iVar8 == 9)) {
      sVar1 = *(sword *)(param_3 + 0xe);
      *(int *)(iVar3 + 0x8c) = (int)sVar1;
      *(sword *)(iVar3 + 0x38) = sVar1;
    }
    *(int *)(iVar3 + 0x34) = iVar8;
    if (iVar8 == 2) {
      uVar5 = 2;
    }
    else {
      uVar5 = 1;
    }
    *(undefined2 *)(iVar3 + 0x66) = uVar5;
    if (*(sword *)(*(int *)(iVar3 + 0x30) + 0x124) == 0) {
      *(undefined2 *)(iVar3 + 0x68) = *(undefined2 *)(*(int *)(_active_u + 0x1c) + 2);
      uVar5 = *(undefined2 *)(param_1 + 0x6a);
    }
    else {
      *(undefined2 *)(iVar3 + 0xe4) = *(undefined2 *)(param_1 + 0xe4);
      *(undefined2 *)(iVar3 + 0xe6) = *(undefined2 *)(param_1 + 0xe6);
      uVar5 = _nogroup;
      *(undefined2 *)(iVar3 + 0x68) = *(undefined2 *)(*(int *)(iVar3 + 0x30) + 0x124);
    }
    *(undefined2 *)(iVar3 + 0x6a) = uVar5;
    if ((*(word *)(iVar3 + 100) & 0x400) != 0) {
      iVar4 = (int)*(sword *)(iVar3 + 0x6a);
      _groupmember();
      if (iVar4 == 0) {
        *(word *)(iVar3 + 100) = *(word *)(iVar3 + 100) & 0xfbff;
      }
    }
    _iupdat(iVar3,1);
    if (iVar8 == 2) {
      iVar9 = iVar3;
      sub_F004C720(iVar3,param_1);
    }
    if (iVar9 == 0) {
      wVar2 = *(word *)(iVar3 + 0x44);
      *(word *)(iVar3 + 0x44) = wVar2 & 0xfffe;
      if ((wVar2 & 0x10) != 0) {
        *(word *)(iVar3 + 0x44) = wVar2 & 0xffee;
        _wakeup(iVar3);
      }
      *param_2 = iVar3;
    }
    else {
      *(undefined2 *)(iVar3 + 0x66) = 0;
      *(word *)(iVar3 + 0x44) = *(word *)(iVar3 + 0x44) | 0x40;
      _iput();
    }
  }
  return CONCAT44(param_2,iVar9);
}
/* GHIDRADEC_FUNCTION index=3443 start=0xf004c720 */

/* WARNING: Removing unreachable block (ram,0xf004c7e4) */
/* WARNING: Removing unreachable block (ram,0xf004c798) */
/* WARNING: Removing unreachable block (ram,0xf004c7d0) */
/* WARNING: Removing unreachable block (ram,0xf004c84c) */
/* WARNING: Removing unreachable block (ram,0xf004c73c) */

undefined8 sub_F004C720(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
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
  iVar4 = param_1;
  _bmap(param_1,0,0,0x400,0);
  if ((iVar4 < 1) || (*(char *)(dword_F0133DDC + 0x38) != '\0')) {
    iVar4 = 0x1c;
    if (*(char *)(dword_F0133DDC + 0x38) != 0) {
      iVar4 = (int)*(char *)(dword_F0133DDC + 0x38);
    }
  }
  else {
    if (*(int *)(iVar3 + 0x34) < 0x400) {
      _panic(aDirblksizFsize_0);
    }
    *(undefined4 *)(param_1 + 0x70) = 0x400;
    *(word *)(param_1 + 0x44) = *(word *)(param_1 + 0x44) | 0x42;
    *(sword *)(param_2 + 0x66) = *(sword *)(param_2 + 0x66) + 1;
    *(word *)(param_2 + 0x44) = *(word *)(param_2 + 0x44) | 0x40;
    _iupdat(param_2,1);
    iVar1 = *(int *)(param_1 + 0x40);
    _bread(iVar1,iVar4 << ((byte)*(undefined4 *)(iVar3 + 100) & 0x1f),*(undefined4 *)(iVar3 + 0x34))
    ;
    iVar4 = (int)*(char *)(dword_F0133DDC + 0x38);
    if (iVar4 == 0) {
      puVar2 = *(undefined4 **)(iVar1 + 0x20);
      *puVar2 = _mastertemplate;
      puVar2[1] = DAT_f010e9f4._0_4_;
      puVar2[2] = DAT_f010e9f4._4_4_;
      puVar2[3] = DAT_f010e9f4._8_4_;
      puVar2[4] = DAT_f010e9f4._12_4_;
      puVar2[5] = DAT_f010e9f4._16_4_;
      *puVar2 = *(undefined4 *)(param_1 + 0x48);
      puVar2[3] = *(undefined4 *)(param_2 + 0x48);
      _bwrite(iVar1);
      iVar4 = (int)*(char *)(dword_F0133DDC + 0x38);
    }
  }
  return CONCAT44(param_2,iVar4);
}
/* GHIDRADEC_FUNCTION index=3444 start=0xf004ccf8 */

/* WARNING: Removing unreachable block (ram,0xf004cd78) */
/* WARNING: Removing unreachable block (ram,0xf004cd58) */

undefined8 sub_F004CCF8(undefined4 param_1,int param_2,uint param_3,undefined4 param_4)

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
  undefined4 uVar2;
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
  if (((((*(word *)(param_2 + 4) & 3) == 0) &&
       ((int)(uint)*(word *)(param_2 + 4) <= (int)(0x400 - (param_3 & 0x3ff)))) &&
      (0xfe < *(word *)(param_2 + 6))) && (*(word *)(param_2 + 6) < 0x100)) {
    if (_dirchk == 0) {
      uVar2 = 0;
      goto locret_F004CD84;
    }
    iVar1 = param_2 + 8;
    sub_F004CDB8();
    if (iVar1 == 0) {
      uVar2 = 0;
      goto locret_F004CD84;
    }
  }
  sub_F004CD8C(param_1,aMangledEntry_0,param_4);
  uVar2 = 1;
locret_F004CD84:
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=3445 start=0xf004cd8c */

/* WARNING: Removing unreachable block (ram,0xf004cda8) */

undefined8 sub_F004CD8C(int param_1,undefined4 param_2,undefined4 param_3)

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
  _printf(aSBadDirInoDAtO,*(int *)(param_1 + 0x50) + 0xd4,*(undefined4 *)(param_1 + 0x48),param_3,
          param_2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=3446 start=0xf004cdb8 */

sqword sub_F004CDB8(undefined4 param_1,uint param_2)

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
/* GHIDRADEC_FUNCTION index=3447 start=0xf004cdc4 */

/* WARNING: Removing unreachable block (ram,0xf004cdf8) */

undefined8 sub_F004CDC4(int param_1,int param_2)

{
  word wVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
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
  uVar5 = 0;
  if (*(int *)(param_1 + 0x70) != 0) {
    do {
      iVar2 = 0;
      _rdwri(0,param_1,(int *)((int)register0x00000038 + -0x20),0xc,uVar5,1,
             (undefined *)((int)register0x00000038 + -0x24));
      if (iVar2 != 0) {
        uVar6 = 0;
        goto locret_F004CEA4;
      }
      if (*(int *)((int)register0x00000038 + -0x24) != 0) {
        uVar6 = 0;
        goto locret_F004CEA4;
      }
      uVar3 = (uint)*(word *)((int)register0x00000038 + -0x1c);
      if (uVar3 == 0) {
        uVar6 = 0;
        goto locret_F004CEA4;
      }
      iVar2 = *(int *)((int)register0x00000038 + -0x20);
      if (iVar2 == 0) {
        uVar4 = *(uint *)(param_1 + 0x70);
      }
      else {
        if (2 < *(word *)((int)register0x00000038 + -0x1a)) {
          uVar6 = 0;
          goto locret_F004CEA4;
        }
        if (*(char *)((int)register0x00000038 + -0x18) != '.') {
          uVar6 = 0;
          goto locret_F004CEA4;
        }
        if (*(word *)((int)register0x00000038 + -0x1a) == 1) {
          wVar1 = *(word *)((int)register0x00000038 + -0x1c);
        }
        else {
          if (*(char *)((int)register0x00000038 + -0x17) != '.') {
            uVar6 = 0;
            goto locret_F004CEA4;
          }
          if (iVar2 != param_2) {
            uVar6 = 0;
            goto locret_F004CEA4;
          }
          wVar1 = *(word *)((int)register0x00000038 + -0x1c);
        }
        uVar3 = (uint)wVar1;
        uVar4 = *(uint *)(param_1 + 0x70);
      }
      uVar5 = uVar5 + uVar3;
    } while (uVar5 < uVar4);
  }
  uVar6 = 1;
locret_F004CEA4:
  return CONCAT44(param_2,uVar6);
}
/* GHIDRADEC_FUNCTION index=3448 start=0xf004ceac */

/* WARNING: Removing unreachable block (ram,0xf004d0c0) */
/* WARNING: Removing unreachable block (ram,0xf004d084) */
/* WARNING: Removing unreachable block (ram,0xf004d058) */
/* WARNING: Removing unreachable block (ram,0xf004d048) */
/* WARNING: Removing unreachable block (ram,0xf004cf90) */
/* WARNING: Removing unreachable block (ram,0xf004d008) */
/* WARNING: Removing unreachable block (ram,0xf004d01c) */
/* WARNING: Removing unreachable block (ram,0xf004cfdc) */
/* WARNING: Removing unreachable block (ram,0xf004d0a0) */
/* WARNING: Removing unreachable block (ram,0xf004d0d8) */
/* WARNING: Removing unreachable block (ram,0xf004cedc) */

undefined8 sub_F004CEAC(int param_1,int param_2)

{
  sword sVar1;
  word wVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
  int iVar6;
  int iVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar8;
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
  iVar8 = 0;
  while ((unk_F010EB7D._0_1_ & 1) != 0) {
    unk_F010EB7D._0_1_ = unk_F010EB7D._0_1_ | 2;
    _sleep(&unk_F010EB7D,10);
  }
  unk_F010EB7D._0_1_ = 1;
  iVar5 = param_2;
  if (*(int *)(param_2 + 0x48) == *(int *)(param_1 + 0x48)) {
    iVar8 = 0x16;
  }
  else if (*(int *)(param_2 + 0x48) != 2) {
    wVar2 = *(word *)(param_2 + 100);
    while (((iVar7 = 0, (wVar2 & 0xf000) == 0x4000 && (*(sword *)(iVar5 + 0x66) != 0)) &&
           (0x17 < *(uint *)(iVar5 + 0x70)))) {
      iVar7 = iVar5;
      _blkatoff(iVar5,0,(undefined *)((int)register0x00000038 + -0xc));
      iVar4 = iVar5;
      if (iVar7 == 0) {
loc_F004D070:
        iVar8 = (int)*(char *)(dword_F0133DDC + 0x38);
        iVar5 = iVar4;
        goto loc_F004D07C;
      }
      iVar4 = *(int *)((int)register0x00000038 + -0xc);
      if ((*(sword *)(iVar4 + 0x12) != 2) || ((*(uint *)(iVar4 + 0x14) & 0xffff0000) != 0x2e2e0000))
      {
        puVar3 = aMangledEntry_1;
        goto loc_F004CFDC;
      }
      iVar6 = *(int *)(iVar4 + 0xc);
      if (iVar6 == *(int *)(param_1 + 0x48)) {
        iVar8 = 0x16;
        goto loc_F004D07C;
      }
      if (iVar6 == 2) goto loc_F004D07C;
      _brelse(iVar7);
      iVar7 = 0;
      if (iVar5 == param_2) {
        wVar2 = *(word *)(param_2 + 0x44);
        *(word *)(param_2 + 0x44) = wVar2 & 0xfffe;
        if ((wVar2 & 0x10) != 0) {
          *(word *)(param_2 + 0x44) = wVar2 & 0xffee;
          _wakeup(param_2);
        }
        sVar1 = *(sword *)(iVar5 + 0x46);
      }
      else {
        _iput(iVar5);
        sVar1 = *(sword *)(iVar5 + 0x46);
      }
      iVar4 = (int)sVar1;
      _iget(iVar4,*(undefined4 *)(iVar5 + 0x50),iVar6);
      if (iVar4 == 0) goto loc_F004D070;
      wVar2 = *(word *)(iVar4 + 100);
      iVar5 = iVar4;
    }
    puVar3 = aBadSizeUnlinke;
loc_F004CFDC:
    sub_F004CD8C(iVar5,puVar3,0);
    iVar8 = 0x14;
loc_F004D07C:
    if (iVar7 != 0) {
      _brelse(iVar7);
    }
  }
  if ((unk_F010EB7D._0_1_ & 2) != 0) {
    _wakeup(&unk_F010EB7D);
  }
  unk_F010EB7D._0_1_ = 0;
  if ((iVar5 != 0) && (iVar5 != param_2)) {
    _iput(iVar5);
    wVar2 = *(word *)(param_2 + 0x44);
    while ((wVar2 & 1) != 0) {
      *(word *)(param_2 + 0x44) = wVar2 | 0x10;
      _sleep(param_2,10);
      wVar2 = *(word *)(param_2 + 0x44);
    }
    *(word *)(param_2 + 0x44) = *(word *)(param_2 + 0x44) | 1;
    if ((iVar8 == 0) && (*(sword *)(param_2 + 0x66) == 0)) {
      iVar8 = 2;
    }
  }
  return CONCAT44(param_2,iVar8);
}
/* GHIDRADEC_FUNCTION index=3449 start=0xf004d11c */

undefined8 sub_F004D11C(int param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
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
  if ((dword_F013AD9C == 0) || ((*(uint *)(param_1 + 0xc) & 0x80000000) != 0)) {
    if ((dword_F013AD9C != 0) ||
       ((-1 < *(int *)(param_1 + 0xc) || (iVar1 = param_1, (*dword_F013AD8C)(), iVar1 != 0))))
    goto locret_F004D1B0;
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0x7fffffff;
    pcVar2 = DAT_f013ad94._4_4_;
  }
  else {
    if (param_1 + 0x10 != *(int *)(param_1 + 0x10)) goto locret_F004D1B0;
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x80000000;
    pcVar2 = DAT_f013ad94._0_4_;
  }
  (*pcVar2)(param_1);
locret_F004D1B0:
  return CONCAT44(param_2,param_1);
}

