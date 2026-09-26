
/* WARNING: Removing unreachable block (ram,0xf003782c) */
/* WARNING: Removing unreachable block (ram,0xf0037844) */
/* WARNING: Removing unreachable block (ram,0xf00377c0) */

undefined8 _tcp_fasttimo(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 *puVar3;
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
  uVar1 = param_1;
  _splnet();
  if ((_tcb != (undefined4 *)0x0) && ((undefined4 **)_tcb != &_tcb)) {
    iVar2 = _tcb[8];
    puVar3 = _tcb;
    while( true ) {
      if (iVar2 == 0) {
        puVar3 = (undefined4 *)*puVar3;
      }
      else if ((*(byte *)(iVar2 + 0x1b) & 2) == 0) {
        puVar3 = (undefined4 *)*puVar3;
      }
      else {
        *(byte *)(iVar2 + 0x1b) = *(byte *)(iVar2 + 0x1b) & 0xfd | 1;
        DAT_f013a7c0._0_4_ = DAT_f013a7c0._0_4_ + 1;
        _tcp_output(iVar2);
        puVar3 = (undefined4 *)*puVar3;
      }
      if ((undefined4 **)puVar3 == &_tcb) break;
      iVar2 = puVar3[8];
    }
  }
  _splx(uVar1);
  return CONCAT44(param_2,param_1);
}
