
/* WARNING: Removing unreachable block (ram,0xf002c34c) */
/* WARNING: Removing unreachable block (ram,0xf002c338) */
/* WARNING: Removing unreachable block (ram,0xf002c378) */
/* WARNING: Removing unreachable block (ram,0xf002c324) */
/* WARNING: Removing unreachable block (ram,0xf002c340) */
/* WARNING: Removing unreachable block (ram,0xf002c354) */
/* WARNING: Removing unreachable block (ram,0xf002c300) */

undefined8 _if_output_mbuf(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 unaff_l0;
  int iVar4;
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
  iVar4 = 0;
  for (piVar3 = (int *)param_2; piVar3 != (int *)0x0; piVar3 = (int *)*piVar3) {
    iVar4 = iVar4 + *(sword *)(piVar3 + 2);
  }
  if (*(sword *)(param_1 + 10) < iVar4) {
    _m_freem(param_2);
    param_1 = 0x28;
  }
  else {
    iVar1 = param_1;
    (**(code **)(param_1 + 0x40))();
    if (iVar1 == 0) {
      _m_freem(param_2);
      param_1 = 0x37;
    }
    else {
      iVar2 = iVar1;
      _nb_map();
      _mbuf_read(param_2,iVar2,0,iVar4);
      iVar2 = iVar1;
      _nb_size(iVar1);
      _nb_shrink_bot(iVar1,iVar2 - iVar4);
      _m_freem(param_2);
      (**(code **)(param_1 + 0x34))(param_1,iVar1,param_3);
    }
  }
  return CONCAT44(param_2,param_1);
}
