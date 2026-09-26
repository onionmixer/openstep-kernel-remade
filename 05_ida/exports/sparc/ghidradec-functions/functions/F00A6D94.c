
/* WARNING: Removing unreachable block (ram,0xf00a6e04) */
/* WARNING: Removing unreachable block (ram,0xf00a6dc8) */
/* WARNING: Removing unreachable block (ram,0xf00a6dc0) */
/* WARNING: Removing unreachable block (ram,0xf00a6de4) */
/* WARNING: Removing unreachable block (ram,0xf00a6e40) */
/* WARNING: Removing unreachable block (ram,0xf00a6d9c) */

undefined8 _p4m35_parerr_reset(int param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined4 unaff_l0;
  int *piVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
  int iVar4;
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
  iVar3 = 0;
  _memerr_disable();
  piVar2 = &dword_F011B044;
  iVar4 = dword_F011B044;
  if (dword_F011B044 != 0) {
    while( true ) {
      _stphys(param_1,iVar4);
      iVar4 = param_1;
      _ldphys();
      if (iVar4 != *piVar2) {
        _printf(DAT_f011b098,param_1);
        iVar3 = iVar3 + 1;
      }
      piVar2 = piVar2 + 1;
      if (*piVar2 == 0) break;
      iVar4 = *piVar2;
    }
  }
  _memerr_init();
  iVar4 = 0;
  if (iVar3 != 0) {
    iVar4 = -1;
  }
  if (iVar4 == 0) {
    puVar1 = aTransient;
  }
  else {
    puVar1 = aPermanent;
  }
  _printf(aParityErrorAtX,param_1,puVar1);
  return CONCAT44(param_2,iVar4);
}
