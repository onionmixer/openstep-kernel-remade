
/* WARNING: Removing unreachable block (ram,0xf002a360) */
/* WARNING: Removing unreachable block (ram,0xf002a37c) */
/* WARNING: Removing unreachable block (ram,0xf002a33c) */
/* WARNING: Removing unreachable block (ram,0xf002a2ec) */
/* WARNING: Removing unreachable block (ram,0xf002a2b8) */
/* WARNING: Removing unreachable block (ram,0xf002a2a0) */
/* WARNING: Removing unreachable block (ram,0xf002a310) */
/* WARNING: Removing unreachable block (ram,0xf002a2c8) */
/* WARNING: Removing unreachable block (ram,0xf002a324) */
/* WARNING: Removing unreachable block (ram,0xf002a34c) */
/* WARNING: Removing unreachable block (ram,0xf002a388) */
/* WARNING: Removing unreachable block (ram,0xf002a36c) */
/* WARNING: Removing unreachable block (ram,0xf002a270) */

undefined8 sub_F002A26C(int param_1,undefined4 param_2,sword *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar3;
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
  iVar3 = param_1;
  _if_private();
  iVar3 = *(int *)(iVar3 + 0xc);
  if (*param_3 == 0) {
    _bcopy(param_3 + 1,(undefined *)((int)register0x00000038 + -0x18),0xe);
    *(undefined2 *)((int)register0x00000038 + -0xc) =
         *(undefined2 *)((int)register0x00000038 + -0xc);
  }
  else {
    if (*param_3 != 2) {
      _nb_free(param_2);
      iVar3 = 0x2f;
      goto locret_F002A394;
    }
    *(undefined4 *)((int)register0x00000038 + -0x1c) = *(undefined4 *)(param_3 + 2);
    iVar1 = param_1;
    _if_private();
    *(undefined4 *)((int)register0x00000038 + -0x24) = *(undefined4 *)(iVar1 + 8);
    iVar1 = param_1;
    _if_private(param_1);
    iVar2 = param_1;
    _arpresolve(param_1,iVar1,(undefined *)((int)register0x00000038 + -0x24),param_2,
                (undefined *)((int)register0x00000038 + -0x1c),
                (undefined *)((int)register0x00000038 + -0x18),
                (undefined *)((int)register0x00000038 + -0x20));
    if (iVar2 == 0) {
      iVar3 = 0;
      goto locret_F002A394;
    }
    *(undefined2 *)((int)register0x00000038 + -0xc) = 0x800;
  }
  _nb_grow_top(param_2,0xe);
  _nb_write(param_2,0xc,2,(undefined *)((int)register0x00000038 + -0xc));
  _if_output(iVar3,param_2,(undefined *)((int)register0x00000038 + -0x18));
  if (iVar3 == 0) {
    iVar1 = param_1;
    _if_opackets(param_1);
    _if_opackets_set(param_1,iVar1 + 1);
  }
  else {
    iVar1 = param_1;
    _if_oerrors(param_1);
    _if_oerrors_set(param_1,iVar1 + 1);
  }
locret_F002A394:
  return CONCAT44(param_2,iVar3);
}

