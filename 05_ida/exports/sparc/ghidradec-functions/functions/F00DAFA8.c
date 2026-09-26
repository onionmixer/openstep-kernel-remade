
/* WARNING: Removing unreachable block (ram,0xf00db0cc) */
/* WARNING: Removing unreachable block (ram,0xf00db0a0) */
/* WARNING: Removing unreachable block (ram,0xf00db060) */
/* WARNING: Removing unreachable block (ram,0xf00db010) */
/* WARNING: Removing unreachable block (ram,0xf00dafe4) */
/* WARNING: Removing unreachable block (ram,0xf00db000) */
/* WARNING: Removing unreachable block (ram,0xf00db030) */
/* WARNING: Removing unreachable block (ram,0xf00db0bc) */
/* WARNING: Removing unreachable block (ram,0xf00db07c) */
/* WARNING: Removing unreachable block (ram,0xf00db0ec) */
/* WARNING: Removing unreachable block (ram,0xf00dafd0) */

undefined8
-[AudioStream sendControlMessage:mask:](int param_1,undefined4 param_2,int param_3,uint param_4)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  int iVar5;
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
  if (*(int *)(param_1 + 0x1c) == 0) {
    if ((*(uint *)(param_1 + 0x60) & param_4) != 0) {
      uVar1 = *(undefined4 *)(param_1 + 0x5c);
      _IOConvertPort(uVar1,0,1);
      uVar3 = *(undefined4 *)(param_1 + 0x10);
      _IOConvertPort(uVar3,0,1);
      __NXAudioReplyStreamStatus(uVar1,uVar3,uVar1,*(undefined4 *)(param_1 + 0x18),0,param_3);
    }
    goto locret_F00DB0F4;
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x28),paLock);
  iVar5 = param_1 + 0x2c;
  if (iVar5 == *(int *)(param_1 + 0x2c)) {
loc_F00DB0E4:
    uVar1 = *(undefined4 *)(param_1 + 0x28);
  }
  else {
    _objc_msgSend(param_1,paCreatesndreply);
    iVar4 = *(int *)(param_1 + 0x2c);
    if (iVar5 != iVar4) {
      uVar2 = *(uint *)(iVar4 + 0x18);
      while( true ) {
        if ((uVar2 & param_4) != 0) {
          uVar1 = *(undefined4 *)(iVar4 + 0x1c);
          _IOConvertPort(uVar1,0,1);
          if (param_3 == 2) {
            _audio_snd_reply_paused
                      (*(undefined4 *)(param_1 + 0x34),uVar1,*(undefined4 *)(iVar4 + 0x14));
            uVar3 = *(undefined4 *)(param_1 + 0x34);
          }
          else if (param_3 == 3) {
            _audio_snd_reply_resumed
                      (*(undefined4 *)(param_1 + 0x34),uVar1,*(undefined4 *)(iVar4 + 0x14));
            uVar3 = *(undefined4 *)(param_1 + 0x34);
          }
          else {
            uVar3 = *(undefined4 *)(param_1 + 0x34);
            if (param_3 == 4) {
              _audio_snd_reply_aborted(uVar3,uVar1,*(undefined4 *)(iVar4 + 0x14));
              uVar3 = *(undefined4 *)(param_1 + 0x34);
            }
          }
          _msg_send(uVar3,0x21,1000);
        }
        iVar4 = *(int *)(iVar4 + 0x3c);
        if (iVar5 == iVar4) break;
        uVar2 = *(uint *)(iVar4 + 0x18);
      }
      goto loc_F00DB0E4;
    }
    uVar1 = *(undefined4 *)(param_1 + 0x28);
  }
  _objc_msgSend(uVar1,paUnlock);
locret_F00DB0F4:
  return CONCAT44(param_2,param_1);
}
