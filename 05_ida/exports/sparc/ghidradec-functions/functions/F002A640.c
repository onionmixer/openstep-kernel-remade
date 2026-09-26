
/* WARNING: Removing unreachable block (ram,0xf002a7d0) */
/* WARNING: Removing unreachable block (ram,0xf002a7b8) */
/* WARNING: Removing unreachable block (ram,0xf002a7a0) */
/* WARNING: Removing unreachable block (ram,0xf002a78c) */
/* WARNING: Removing unreachable block (ram,0xf002a770) */
/* WARNING: Removing unreachable block (ram,0xf002a75c) */
/* WARNING: Removing unreachable block (ram,0xf002a710) */
/* WARNING: Removing unreachable block (ram,0xf002a6ac) */
/* WARNING: Removing unreachable block (ram,0xf002a668) */
/* WARNING: Removing unreachable block (ram,0xf002a6cc) */
/* WARNING: Removing unreachable block (ram,0xf002a730) */
/* WARNING: Removing unreachable block (ram,0xf002a764) */
/* WARNING: Removing unreachable block (ram,0xf002a77c) */
/* WARNING: Removing unreachable block (ram,0xf002a798) */
/* WARNING: Removing unreachable block (ram,0xf002a7f4) */
/* WARNING: Removing unreachable block (ram,0xf002a7c0) */
/* WARNING: Removing unreachable block (ram,0xf002a7e4) */
/* WARNING: Removing unreachable block (ram,0xf002a644) */

undefined8 sub_F002A640(uint param_1,int param_2,uint param_3)

{
  sword sVar1;
  sword sVar2;
  uint uVar3;
  undefined4 unaff_l0;
  uint uVar4;
  undefined4 unaff_l1;
  int iVar5;
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
  uVar4 = param_1;
  _if_private();
  if (*(int *)(uVar4 + 0xc) != param_2) {
    uVar6 = 0x2f;
    goto locret_F002A808;
  }
  _nb_read(param_3,0xc,2,(undefined *)((int)register0x00000038 + -0x12));
  sVar1 = *(sword *)((int)register0x00000038 + -0x12);
  if ((word)(sVar1 - 0x1000U) < 0x10) {
    uVar4 = ((int)sVar1 << 0x19) >> 0x10;
    if (uVar4 == 0) {
      uVar6 = 0x2f;
      goto locret_F002A808;
    }
    uVar3 = param_3;
    _nb_size();
    if (uVar4 + 0x12 < uVar3) {
      _nb_read(param_3,uVar4 | 0xe,4,(undefined *)((int)register0x00000038 + -0x10));
      sVar2 = *(sword *)((int)register0x00000038 + -0x10);
      *(sword *)((int)register0x00000038 + -0x12) = sVar2;
      if ((sVar2 != 0x800) && (sVar2 != 0x806)) {
        uVar6 = 0x2f;
        goto locret_F002A808;
      }
      param_2 = (int)*(sword *)((int)register0x00000038 + -0xe);
      iVar5 = sVar1 * 0x2000000 >> 0x10;
      uVar4 = param_3;
      _nb_size();
      if ((uint)(iVar5 + param_2 + 0xe) <= uVar4) {
        sub_F002A548(param_3,iVar5,(param_2 + -4) * 0x10000 >> 0x10);
        goto loc_F002A738;
      }
    }
    uVar6 = 0x2f;
  }
  else {
loc_F002A738:
    if (*(sword *)((int)register0x00000038 + -0x12) == 0x800) {
      _nb_shrink_top(param_3,0xe);
      uVar4 = param_1;
      _if_ipackets(param_1);
      _if_ipackets_set(param_1,uVar4 + 1);
      _inet_queue(param_1,param_3);
      uVar6 = 0;
    }
    else if (*(sword *)((int)register0x00000038 + -0x12) == 0x806) {
      uVar4 = param_1;
      _if_ipackets(param_1);
      _if_ipackets_set(param_1,uVar4 + 1);
      uVar4 = param_1;
      _if_flags();
      if ((uVar4 & 0x4000) == 0) {
        _nb_shrink_top(param_3,0xe);
        uVar4 = param_1;
        _if_private();
        *(undefined4 *)((int)register0x00000038 + -0x18) = *(undefined4 *)(uVar4 + 8);
        uVar4 = param_1;
        _if_private(param_1);
        _arpinput(param_1,uVar4,(undefined *)((int)register0x00000038 + -0x18),param_3);
        uVar6 = 0;
      }
      else {
        _nb_free(param_3);
        uVar6 = 0;
      }
    }
    else {
      uVar6 = 0x2f;
    }
  }
locret_F002A808:
  return CONCAT44(param_2,uVar6);
}
