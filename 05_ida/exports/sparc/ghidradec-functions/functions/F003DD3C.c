
/* WARNING: Removing unreachable block (ram,0xf003dd8c) */
/* WARNING: Removing unreachable block (ram,0xf003ddf0) */
/* WARNING: Removing unreachable block (ram,0xf003dd74) */

undefined8
sub_F003DD3C(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar2;
  undefined4 uVar3;
  undefined4 unaff_l3;
  undefined4 *puVar4;
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
  puVar4 = *(undefined4 **)((int)register0x00000038 + 100);
  uVar3 = *(undefined4 *)((int)register0x00000038 + 0x5c);
  uVar5 = *(undefined4 *)((int)register0x00000038 + 0x60);
  *(undefined2 *)(param_1 + 2) = 0x6f;
  iVar2 = *(int *)((int)register0x00000038 + 0x68);
  _clntkudp_create(param_1,100000,2,5,*(undefined4 *)(_active_u + 0x1c));
  if (param_1 == 0) {
    _panic(aPmapRmtcallCln);
    *(undefined4 *)((int)register0x00000038 + -0x20) = param_2;
  }
  else {
    *(undefined4 *)((int)register0x00000038 + -0x20) = param_2;
  }
  *(undefined4 *)((int)register0x00000038 + -0x1c) = param_3;
  *(undefined4 *)((int)register0x00000038 + -0x18) = param_4;
  *(undefined4 *)((int)register0x00000038 + -0x10) = param_6;
  *(undefined4 *)((int)register0x00000038 + -0xc) = param_5;
  *(undefined **)((int)register0x00000038 + -0x30) = (undefined *)((int)register0x00000038 + -0x34);
  *(undefined4 *)((int)register0x00000038 + -0x28) = uVar5;
  *(undefined4 *)((int)register0x00000038 + -0x24) = uVar3;
  *(undefined4 *)((int)register0x00000038 + -0x40) = *puVar4;
  *(undefined4 *)((int)register0x00000038 + -0x3c) = puVar4[1];
  iVar1 = param_1;
  _clntkudp_callit_addr
            (param_1,5,_xdr_rmtcall_args,(undefined *)((int)register0x00000038 + -0x20),
             _xdr_rmtcallres,(undefined *)((int)register0x00000038 + -0x30),
             (undefined *)((int)register0x00000038 + -0x40),iVar2);
  if (iVar2 != 0) {
    *(sword *)(iVar2 + 2) = (sword)*(undefined4 *)((int)register0x00000038 + -0x34);
  }
  (**(code **)(*(int *)(param_1 + 4) + 0x10))(param_1);
  return CONCAT44(param_2,iVar1);
}
