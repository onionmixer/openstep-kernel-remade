
/* WARNING: Removing unreachable block (ram,0xf006df14) */
/* WARNING: Removing unreachable block (ram,0xf006def0) */
/* WARNING: Removing unreachable block (ram,0xf006dec8) */
/* WARNING: Removing unreachable block (ram,0xf006deb4) */
/* WARNING: Removing unreachable block (ram,0xf006dea0) */
/* WARNING: Removing unreachable block (ram,0xf006deac) */
/* WARNING: Removing unreachable block (ram,0xf006dee4) */
/* WARNING: Removing unreachable block (ram,0xf006ded0) */
/* WARNING: Removing unreachable block (ram,0xf006df08) */
/* WARNING: Removing unreachable block (ram,0xf006df1c) */
/* WARNING: Removing unreachable block (ram,0xf006de80) */

undefined8 _miniMonLoop(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined *puVar1;
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
  _miniMonState = param_3;
  if (param_2 != 0) {
    _safe_prf(aSystemPanic_0);
    _safe_prf(&aS_2,_panicstr);
    puVar1 = aTypeRToRebootO;
    _safe_prf();
    do {
      while( true ) {
        _miniMonTryGetchar();
        if (puVar1 != (undefined *)0x72) break;
        _safe_prf(aRebooting);
        puVar1 = DAT_f010ff80;
        _miniMonReboot();
      }
    } while (puVar1 != (undefined *)0x6d);
    _safe_prf(0xf010ff88);
  }
  _safe_prf(aNextstepMiniMo);
  do {
    _safe_prf(&aS_3,param_1);
    sub_F006DD7C(unk_F012F89C,0x80);
    puVar1 = unk_F012F89C;
    sub_F006DC90();
  } while (puVar1 != (undefined *)0x0);
  return CONCAT44(unk_F012F89C,param_1);
}

