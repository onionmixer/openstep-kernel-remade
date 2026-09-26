
/* WARNING: Removing unreachable block (ram,0xf00c21dc) */
/* WARNING: Removing unreachable block (ram,0xf00c2198) */
/* WARNING: Removing unreachable block (ram,0xf00c21cc) */
/* WARNING: Removing unreachable block (ram,0xf00c21ac) */
/* WARNING: Removing unreachable block (ram,0xf00c2174) */

void sub_F00C2154(int param_1)

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
  _objc_msgSend(param_1,paInterruptport_0);
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0x18;
  do {
    while( true ) {
      *(undefined4 *)((int)register0x00000038 + -0x14) = *(undefined4 *)(param_1 + 0x130);
      puVar1 = (undefined *)((int)register0x00000038 + -0x20);
      _msg_receive((undefined *)((int)register0x00000038 + -0x20),0,0);
      if (puVar1 == (undefined *)0x0) break;
      _IOLog(aMousethreadMsg,puVar1);
      *(undefined4 *)((int)register0x00000038 + -0x1c) = 0x18;
    }
    if (*(int *)((int)register0x00000038 + -0xc) == 0x232325) {
      _objc_msgSend(param_1,paInterrupthandl);
      *(undefined4 *)((int)register0x00000038 + -0x1c) = 0x18;
    }
    else {
      _IOLog(aMousethreadNon,0);
      *(undefined4 *)((int)register0x00000038 + -0x1c) = 0x18;
    }
  } while( true );
}

