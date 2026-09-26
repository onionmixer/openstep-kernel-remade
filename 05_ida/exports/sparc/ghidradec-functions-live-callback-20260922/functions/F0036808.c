
/* WARNING: Removing unreachable block (ram,0xf0036960) */
/* WARNING: Removing unreachable block (ram,0xf0036950) */
/* WARNING: Removing unreachable block (ram,0xf0036920) */
/* WARNING: Removing unreachable block (ram,0xf0036910) */
/* WARNING: Removing unreachable block (ram,0xf0036888) */
/* WARNING: Removing unreachable block (ram,0xf00368a4) */
/* WARNING: Removing unreachable block (ram,0xf0036918) */
/* WARNING: Removing unreachable block (ram,0xf003692c) */
/* WARNING: Removing unreachable block (ram,0xf0036958) */
/* WARNING: Removing unreachable block (ram,0xf003696c) */
/* WARNING: Removing unreachable block (ram,0xf0036840) */

undefined8 _tcp_mss(int param_1,uint param_2)

{
  int iVar1;
  undefined *puVar2;
  uint uVar3;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar5;
  undefined2 uVar6;
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
  iVar4 = *(int *)(param_1 + 0x20);
  if (*(int *)(iVar4 + 0x24) == 0) {
    if (*(int *)(iVar4 + 0xc) != 0) {
      *(undefined2 *)(iVar4 + 0x28) = 2;
      *(undefined4 *)(iVar4 + 0x2c) = *(undefined4 *)(iVar4 + 0xc);
      _rtalloc(iVar4 + 0x24);
    }
    uVar3 = _tcp_mssdflt;
    if (*(int *)(iVar4 + 0x24) == 0) goto locret_F0036978;
    iVar1 = *(int *)(*(int *)(iVar4 + 0x24) + 0x2c);
  }
  else {
    iVar1 = *(int *)(*(int *)(iVar4 + 0x24) + 0x2c);
  }
  uVar5 = (int)*(sword *)(iVar1 + 10) - 0x28;
  iVar1 = *(int *)(iVar4 + 0x1c);
  if (0x400 < (int)uVar5) {
    uVar5 = uVar5 & 0xfffffc00;
  }
  puVar2 = (undefined *)((int)register0x00000038 + -0xc);
  *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(iVar4 + 0xc);
  _in_localaddr();
  if (puVar2 == (undefined *)0x0) {
    _min(uVar5,_tcp_mssdflt);
  }
  uVar3 = param_2 & 0xffff;
  if ((uVar3 != 0) && ((int)uVar3 < (int)uVar5)) {
    uVar5 = uVar3;
  }
  if ((int)uVar5 < 0x20) {
    uVar5 = 0x20;
  }
  if (((int)uVar5 < (int)(uint)*(word *)(param_1 + 0x18)) || ((param_2 & 0xffff) != 0)) {
    uVar3 = (uint)*(word *)(iVar1 + 0x3e);
    if (uVar5 <= uVar3) {
      _min(uVar3,0xffff);
      udiv();
      umul();
      _sbreserve(iVar1 + 0x3c,uVar3);
      uVar3 = uVar5;
    }
    uVar6 = (undefined2)uVar3;
    *(undefined2 *)(param_1 + 0x18) = uVar6;
    uVar5 = (uint)*(word *)(iVar1 + 0x26);
    if (uVar3 < uVar5) {
      _min(uVar5,0xffff);
      udiv();
      umul();
      _sbreserve(iVar1 + 0x24,uVar5);
      *(undefined2 *)(param_1 + 0x54) = uVar6;
    }
    else {
      *(undefined2 *)(param_1 + 0x54) = uVar6;
    }
  }
  else {
    *(sword *)(param_1 + 0x54) = (sword)uVar5;
    uVar3 = uVar5;
  }
locret_F0036978:
  return CONCAT44(param_2,uVar3);
}

