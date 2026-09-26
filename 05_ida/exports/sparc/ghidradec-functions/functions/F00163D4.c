
/* WARNING: Removing unreachable block (ram,0xf00164fc) */
/* WARNING: Removing unreachable block (ram,0xf00164f4) */
/* WARNING: Removing unreachable block (ram,0xf00164e4) */
/* WARNING: Removing unreachable block (ram,0xf00163d8) */

undefined8 _soo_select(int param_1,int param_2)

{
  word wVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar4;
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
  iVar4 = *(int *)(param_1 + 0x18);
  _splnet();
  if (param_2 == 1) {
    if (((*(sword *)(iVar4 + 0x24) == 0) && ((*(word *)(iVar4 + 6) & 0x20) == 0)) &&
       (*(sword *)(iVar4 + 0x20) == 0)) {
      wVar1 = *(word *)(iVar4 + 0x56);
joined_r0xf001644c:
      iVar4 = iVar4 + 0x24;
joined_r0xf00164bc:
      if (wVar1 == 0) {
        _sbselqueue(iVar4);
        goto loc_F00164FC;
      }
    }
  }
  else if (param_2 < 2) {
    if (param_2 != 0) {
loc_F00164FC:
      _splx(param_1);
      uVar5 = 0;
      goto locret_F0016508;
    }
    if (*(sword *)(iVar4 + 0x58) == 0) {
      wVar1 = *(word *)(iVar4 + 6) & 0x40;
      goto joined_r0xf001644c;
    }
  }
  else {
    if (param_2 != 2) goto loc_F00164FC;
    iVar2 = (uint)*(word *)(iVar4 + 0x3e) - (uint)*(word *)(iVar4 + 0x3c);
    iVar3 = (uint)*(word *)(iVar4 + 0x42) - (uint)*(word *)(iVar4 + 0x40);
    if (iVar3 < iVar2) {
      iVar2 = iVar3;
    }
    wVar1 = *(word *)(iVar4 + 6);
    if (0 < iVar2) {
      if (((wVar1 & 2) != 0) || ((*(word *)(*(int *)(iVar4 + 0xc) + 10) & 4) == 0))
      goto loc_F00164E4;
      wVar1 = *(word *)(iVar4 + 6);
    }
    if ((wVar1 & 0x10) == 0) {
      wVar1 = *(word *)(iVar4 + 0x56);
      iVar4 = iVar4 + 0x3c;
      goto joined_r0xf00164bc;
    }
  }
loc_F00164E4:
  _splx(param_1);
  uVar5 = 1;
locret_F0016508:
  return CONCAT44(param_2,uVar5);
}
