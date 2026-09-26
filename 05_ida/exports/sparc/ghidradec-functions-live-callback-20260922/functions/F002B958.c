
/* WARNING: Removing unreachable block (ram,0xf002b9c4) */
/* WARNING: Removing unreachable block (ram,0xf002b9ac) */
/* WARNING: Removing unreachable block (ram,0xf002b998) */
/* WARNING: Removing unreachable block (ram,0xf002b97c) */
/* WARNING: Removing unreachable block (ram,0xf002b9e4) */
/* WARNING: Removing unreachable block (ram,0xf002b970) */
/* WARNING: Removing unreachable block (ram,0xf002b988) */
/* WARNING: Removing unreachable block (ram,0xf002b9a0) */
/* WARNING: Removing unreachable block (ram,0xf002b9bc) */
/* WARNING: Removing unreachable block (ram,0xf002b9d4) */
/* WARNING: Removing unreachable block (ram,0xf002b95c) */

undefined8 sub_F002B958(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
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
  iVar1 = param_1;
  _if_getbuf();
  if (iVar1 == 0) {
    _nb_free(param_2);
    param_1 = 1;
  }
  else {
    iVar2 = param_2;
    _nb_map(param_2);
    iVar3 = iVar1;
    _nb_map(iVar1);
    iVar4 = param_2;
    _nb_size(param_2);
    _bcopy(iVar2,iVar3,iVar4);
    iVar2 = iVar1;
    _nb_size(iVar1);
    iVar3 = param_2;
    _nb_size(param_2);
    _nb_shrink_bot(iVar1,iVar2 - iVar3);
    _nb_free(param_2);
    _if_output(param_1,iVar1,param_3);
  }
  return CONCAT44(param_2,param_1);
}

