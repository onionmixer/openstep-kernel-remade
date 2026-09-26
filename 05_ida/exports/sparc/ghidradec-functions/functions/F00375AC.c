
/* WARNING: Removing unreachable block (ram,0xf0037620) */
/* WARNING: Removing unreachable block (ram,0xf0037608) */
/* WARNING: Removing unreachable block (ram,0xf0037614) */
/* WARNING: Removing unreachable block (ram,0xf0037644) */
/* WARNING: Removing unreachable block (ram,0xf00375e4) */

sqword _tcp_close(int *param_1,uint param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 unaff_l0;
  int *piVar3;
  undefined4 unaff_l1;
  undefined4 *puVar4;
  undefined4 uVar5;
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
  puVar4 = (undefined4 *)param_1[8];
  uVar5 = puVar4[7];
  if ((int *)*param_1 != param_1) {
    piVar3 = *(int **)*param_1;
    while( true ) {
      piVar2 = (int *)piVar3[1];
      iVar1 = piVar2[5];
      *(int *)(*piVar2 + 4) = piVar2[1];
      *(int *)piVar2[1] = *piVar2;
      _m_freem(iVar1);
      if (piVar3 == param_1) break;
      piVar3 = (int *)*piVar3;
    }
  }
  if (param_1[7] != 0) {
    _m_free(param_1[7] & 0xffffff80);
  }
  _kfree(param_1,0x6c);
  puVar4[8] = 0;
  _soisdisconnected(uVar5);
  if (puVar4 == _tcp_last_inpcb) {
    _tcp_last_inpcb = &_tcb;
  }
  _in_pcbdetach(puVar4);
  DAT_f013a7b4._0_4_ = DAT_f013a7b4._0_4_ + 1;
  return (qword)param_2 << 0x20;
}
