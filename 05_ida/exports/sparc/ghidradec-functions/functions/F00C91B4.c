
/* WARNING: Removing unreachable block (ram,0xf00c92e4) */
/* WARNING: Removing unreachable block (ram,0xf00c92c0) */
/* WARNING: Removing unreachable block (ram,0xf00c9230) */
/* WARNING: Removing unreachable block (ram,0xf00c921c) */
/* WARNING: Removing unreachable block (ram,0xf00c9248) */
/* WARNING: Removing unreachable block (ram,0xf00c9300) */
/* WARNING: Removing unreachable block (ram,0xf00c92b0) */
/* WARNING: Removing unreachable block (ram,0xf00c91ec) */

void sub_F00C91B4(int param_1)

{
  int iVar1;
  int iVar2;
  undefined (*pauVar3) [23];
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
loc_F00C91E4:
  iVar2 = param_1;
  _objc_msgSend(param_1,paWaitforinterru,(undefined *)((int)register0x00000038 + -0xc));
  pauVar3 = (undefined (*) [23])paReceivemsg;
  if (iVar2 != -0x2e1) {
    if (iVar2 != 0) {
      iVar4 = param_1;
      _objc_msgSend(param_1,paName);
      iVar1 = param_1;
      _objc_msgSend(param_1,paDevicekind_0);
      _IOLog(aSSThreadWaitfo,iVar4,iVar1,iVar2);
      goto loc_F00C91E4;
    }
    iVar2 = *(int *)((int)register0x00000038 + -0xc);
    pauVar3 = paCommandrequest;
    if (iVar2 != 0x232324) {
      if (0x232324 < iVar2) {
        pauVar3 = (undefined (*) [23])paInterruptoccur_0;
        if (iVar2 == 0x232325) goto loc_F00C92B0;
        iVar4 = *(int *)((int)register0x00000038 + -0xc);
        if (iVar2 == 0x232336) {
          _IOExitThread();
        }
        else {
loc_F00C92D0:
          if (iVar4 - 0x232325U < 0x10) {
            _objc_msgSend(param_1,paInterruptoccur);
          }
          else {
            _objc_msgSend(param_1,paOtheroccurred,iVar4);
          }
        }
        goto loc_F00C91E4;
      }
      pauVar3 = (undefined (*) [23])paTimeoutoccurre;
      if (iVar2 != 0x232323) {
        iVar4 = *(int *)((int)register0x00000038 + -0xc);
        goto loc_F00C92D0;
      }
    }
  }
loc_F00C92B0:
  _objc_msgSend(param_1,pauVar3);
  goto loc_F00C91E4;
}
