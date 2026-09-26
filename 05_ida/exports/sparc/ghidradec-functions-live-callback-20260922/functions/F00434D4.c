
/* WARNING: Removing unreachable block (ram,0xf0043598) */
/* WARNING: Removing unreachable block (ram,0xf004356c) */
/* WARNING: Removing unreachable block (ram,0xf0043528) */
/* WARNING: Removing unreachable block (ram,0xf0043584) */
/* WARNING: Removing unreachable block (ram,0xf00434f8) */
/* WARNING: Removing unreachable block (ram,0xf00434e0) */

undefined8 sub_F00434D4(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 unaff_l0;
  word wVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 uVar5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar6;
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
  iVar1 = 1;
  _m_get(1,8);
  if (iVar1 == 0) {
    _printf(aBindresvportCo);
    iVar6 = 0x37;
  }
  else {
    iVar3 = *(int *)(iVar1 + 4);
    *(undefined2 *)(iVar1 + iVar3) = 2;
    iVar3 = iVar1 + iVar3;
    *(undefined4 *)(iVar3 + 4) = 0;
    *(undefined2 *)(iVar1 + 8) = 0x10;
    uVar2 = *(undefined4 *)(_active_u + 0x1c);
    _crdup();
    uVar5 = *(undefined4 *)(_active_u + 0x1c);
    *(undefined4 *)(_active_u + 0x1c) = uVar2;
    iVar6 = 0x30;
    wVar4 = 0x3ff;
    *(undefined2 *)(*(int *)(_active_u + 0x1c) + 2) = 0;
    do {
      if (wVar4 < 0x200) break;
      *(word *)(iVar3 + 2) = wVar4;
      iVar6 = param_1;
      _sobind(param_1,iVar1);
      wVar4 = wVar4 - 1;
    } while (iVar6 == 0x30);
    _m_freem(iVar1);
    *(undefined4 *)(_active_u + 0x1c) = uVar5;
    _crfree(uVar2);
  }
  return CONCAT44(param_2,iVar6);
}

