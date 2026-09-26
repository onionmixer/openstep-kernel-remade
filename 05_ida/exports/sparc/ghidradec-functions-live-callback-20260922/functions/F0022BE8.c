
/* WARNING: Removing unreachable block (ram,0xf0022cb0) */
/* WARNING: Removing unreachable block (ram,0xf0022c94) */
/* WARNING: Removing unreachable block (ram,0xf0022cbc) */
/* WARNING: Removing unreachable block (ram,0xf0022c28) */

undefined8 _unp_connect(sword *param_1,int param_2)

{
  int iVar1;
  sword *psVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  sword *psVar3;
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
  iVar1 = param_2 + *(int *)(param_2 + 4);
  if (*(sword *)(param_2 + 8) + -0xc + *(int *)(param_2 + 4) == 0x70) {
    psVar3 = (sword *)0x28;
    goto locret_F0022CC4;
  }
  *(undefined *)(iVar1 + *(sword *)(param_2 + 8)) = 0;
  psVar3 = (sword *)(iVar1 + 2);
  _lookupname(psVar3,1,1,0,(undefined *)((int)register0x00000038 + -0xc));
  if (psVar3 != (sword *)0x0) goto locret_F0022CC4;
  psVar3 = (sword *)0x26;
  if (*(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x28) == 6) {
    psVar2 = *(sword **)(*(int *)((int)register0x00000038 + -0xc) + 0x20);
    psVar3 = (sword *)0x3d;
    if ((psVar2 != (sword *)0x0) && (psVar3 = (sword *)0x29, *param_1 == *psVar2)) {
      if ((*(word *)(*(int *)(param_1 + 6) + 10) & 4) == 0) {
loc_F0022CB0:
        _unp_connect2(param_1,psVar2);
        psVar3 = param_1;
      }
      else {
        psVar3 = (sword *)0x3d;
        if ((psVar2[1] & 2U) != 0) {
          _sonewconn();
          if (psVar2 != (sword *)0x0) goto loc_F0022CB0;
          psVar3 = (sword *)0x3d;
        }
      }
    }
  }
  _vn_rele(*(undefined4 *)((int)register0x00000038 + -0xc));
locret_F0022CC4:
  return CONCAT44(param_2,psVar3);
}

