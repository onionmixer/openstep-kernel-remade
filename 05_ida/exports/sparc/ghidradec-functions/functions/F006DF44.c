
/* WARNING: Removing unreachable block (ram,0xf006df8c) */
/* WARNING: Removing unreachable block (ram,0xf006df58) */
/* WARNING: Removing unreachable block (ram,0xf006dfd4) */
/* WARNING: Removing unreachable block (ram,0xf006df4c) */

undefined8 sub_F006DF44(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar2;
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
  _safe_prf(aMiniMonitorCom);
  _safe_prf(aHelpPrintThisM);
  piVar2 = &_miniMonCommands;
  iVar1 = DAT_f010fd90._0_4_;
  if (_miniMonCommands != 0) {
    while( true ) {
      if (iVar1 != 0) {
        _safe_prf(aSS_5,*piVar2);
      }
      if (piVar2[3] == 0) break;
      iVar1 = piVar2[5];
      piVar2 = piVar2 + 3;
    }
  }
  piVar2 = &_miniMonMDCommands;
  iVar1 = iRamf01128a8;
  if (_miniMonMDCommands != 0) {
    while( true ) {
      if (iVar1 != 0) {
        _safe_prf(aSS_6,*piVar2);
      }
      if (piVar2[3] == 0) break;
      iVar1 = piVar2[5];
      piVar2 = piVar2 + 3;
    }
  }
  return CONCAT44(param_2,1);
}
