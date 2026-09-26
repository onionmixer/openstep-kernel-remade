
/* WARNING: Removing unreachable block (ram,0xf00db160) */
/* WARNING: Removing unreachable block (ram,0xf00db1a4) */
/* WARNING: Removing unreachable block (ram,0xf00db1e0) */
/* WARNING: Removing unreachable block (ram,0xf00db11c) */
/* WARNING: Removing unreachable block (ram,0xf00db188) */
/* WARNING: Removing unreachable block (ram,0xf00db1c4) */
/* WARNING: Removing unreachable block (ram,0xf00db1f0) */
/* WARNING: Removing unreachable block (ram,0xf00db174) */
/* WARNING: Removing unreachable block (ram,0xf00db108) */

undefined8
-[AudioStream sendStatusMessage:forRegion:](int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
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
  iVar1 = *(int *)(param_4 + 0x1c);
  _IOConvertPort(iVar1,0,1);
  uVar2 = *(undefined4 *)(param_1 + 0x10);
  _IOConvertPort(uVar2,0,1);
  if (*(int *)(param_1 + 0x1c) == 0) {
    if ((param_3 == 4) && (*(int *)(param_4 + 0x38) != 0)) {
      param_3 = 6;
    }
    __NXAudioReplyStreamStatus
              (iVar1,uVar2,iVar1,*(undefined4 *)(param_1 + 0x18),*(undefined4 *)(param_4 + 0x14),
               param_3);
    if (iVar1 != 0) {
      _IOLog(aAsReplystreams,iVar1);
    }
  }
  else {
    _objc_msgSend(param_1,paCreatesndreply);
    if (param_3 == 0) {
      _audio_snd_reply_started
                (*(undefined4 *)(param_1 + 0x34),iVar1,*(undefined4 *)(param_4 + 0x14));
      uVar2 = *(undefined4 *)(param_1 + 0x34);
    }
    else if (param_3 == 1) {
      _audio_snd_reply_completed
                (*(undefined4 *)(param_1 + 0x34),iVar1,*(undefined4 *)(param_4 + 0x14));
      uVar2 = *(undefined4 *)(param_1 + 0x34);
    }
    else {
      uVar2 = *(undefined4 *)(param_1 + 0x34);
      if (param_3 == 5) {
        _audio_snd_reply_overflow(uVar2,iVar1,*(undefined4 *)(param_4 + 0x14));
        uVar2 = *(undefined4 *)(param_1 + 0x34);
      }
    }
    _msg_send(uVar2,0x21,1000);
  }
  return CONCAT44(param_2,param_1);
}
