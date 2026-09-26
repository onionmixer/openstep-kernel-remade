
/* WARNING: Removing unreachable block (ram,0xf0042170) */
/* WARNING: Removing unreachable block (ram,0xf0042130) */
/* WARNING: Removing unreachable block (ram,0xf0042108) */
/* WARNING: Removing unreachable block (ram,0xf00421d0) */
/* WARNING: Removing unreachable block (ram,0xf0042144) */
/* WARNING: Removing unreachable block (ram,0xf0042184) */
/* WARNING: Removing unreachable block (ram,0xf00420cc) */

undefined8 _xdr_getrddirres(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  uint uVar4;
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
  *(undefined4 *)((int)register0x00000038 + -0x10) = 0xffffffff;
  iVar3 = param_1;
  _xdr_enum(param_1,param_2 + 4);
  if (iVar3 == 0) {
    uVar5 = 0;
  }
  else if (*(int *)(param_2 + 4) == 0) {
    uVar4 = *(uint *)(param_2 + 0xc);
    iVar3 = *(int *)(param_2 + 0x14);
    while( true ) {
      iVar1 = param_1;
      _xdr_bool(param_1,(undefined *)((int)register0x00000038 + -0xc));
      if (iVar1 == 0) break;
      if (*(int *)((int)register0x00000038 + -0xc) == 0) {
        _xdr_bool(param_1,param_2 + 0x10);
        uVar5 = 1;
        if (param_1 != 0) {
          uVar2 = *(undefined4 *)((int)register0x00000038 + -0x10);
          *(int *)(param_2 + 0xc) = iVar3 - *(int *)(param_2 + 0x14);
          *(undefined4 *)(param_2 + 8) = uVar2;
          goto locret_F0042200;
        }
        break;
      }
      if (((int)uVar4 < 6) || (iVar1 = param_1, _xdr_u_long(param_1,iVar3), iVar1 == 0)) break;
      iVar1 = param_1;
      _xdr_u_short(param_1,iVar3 + 6);
      if (iVar1 == 0) {
        uVar5 = 0;
        goto locret_F0042200;
      }
      if ((uVar4 < (*(word *)(iVar3 + 6) + 0xc & 0xfffffffc)) ||
         (iVar1 = param_1, _xdr_opaque(param_1,iVar3 + 8), iVar1 == 0)) break;
      iVar1 = param_1;
      _xdr_u_long(param_1,(undefined *)((int)register0x00000038 + -0x10));
      if (iVar1 == 0) {
        uVar5 = 0;
        goto locret_F0042200;
      }
      *(word *)(iVar3 + 4) = *(sword *)(iVar3 + 6) + 0xcU & 0xfffc;
      *(undefined *)(iVar3 + (uint)*(word *)(iVar3 + 6) + 8) = 0;
      uVar4 = uVar4 - *(word *)(iVar3 + 4);
      iVar3 = iVar3 + (uint)*(word *)(iVar3 + 4);
      if ((int)uVar4 < 0) break;
    }
    uVar5 = 0;
  }
  else {
    uVar5 = 1;
  }
locret_F0042200:
  return CONCAT44(param_2,uVar5);
}

