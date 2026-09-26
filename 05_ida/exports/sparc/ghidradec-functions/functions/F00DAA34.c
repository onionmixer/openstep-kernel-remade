
/* WARNING: Removing unreachable block (ram,0xf00dab2c) */
/* WARNING: Removing unreachable block (ram,0xf00dab04) */
/* WARNING: Removing unreachable block (ram,0xf00daacc) */
/* WARNING: Removing unreachable block (ram,0xf00daaa0) */
/* WARNING: Removing unreachable block (ram,0xf00daa68) */
/* WARNING: Removing unreachable block (ram,0xf00daa5c) */
/* WARNING: Removing unreachable block (ram,0xf00daa88) */
/* WARNING: Removing unreachable block (ram,0xf00daab0) */
/* WARNING: Removing unreachable block (ram,0xf00daaec) */
/* WARNING: Removing unreachable block (ram,0xf00dab14) */
/* WARNING: Removing unreachable block (ram,0xf00dab38) */
/* WARNING: Removing unreachable block (ram,0xf00daa40) */

undefined8
-[AudioChannel addStreamTag:user:owner:type:]
          (uint param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
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
  uVar1 = *(uint *)(param_1 + 4);
  _objc_msgSend(uVar1,paChannelwilladd);
  if ((uVar1 & 0xff) != 0) {
    uVar1 = param_1;
    _objc_msgSend(param_1,paStreamclass);
    _objc_msgSend();
    _objc_msgSend();
    if (uVar1 != 0) {
      _objc_msgSend(*(undefined4 *)(param_1 + 0x10),paLock);
      iVar2 = *(int *)(param_1 + 0xc);
      _objc_msgSend(iVar2,paCount_0);
      if (iVar2 == 0) {
        uVar4 = param_1;
        _objc_msgSend(param_1,paCreatechannelb);
        if ((uVar4 & 0xff) == 0) {
          _objc_msgSend(*(undefined4 *)(param_1 + 0x10),paUnlock);
          goto loc_F00DAAF4;
        }
        uVar3 = *(undefined4 *)(param_1 + 0xc);
      }
      else {
        uVar3 = *(undefined4 *)(param_1 + 0xc);
      }
      _objc_msgSend(uVar3,paAddobject,uVar1);
      _objc_msgSend(*(undefined4 *)(param_1 + 0x10),paUnlock);
      _objc_msgSend(paAudiochannel,paAddstream,uVar1);
      uVar3 = *param_4;
      _audio_enroll_stream_port(uVar3,1);
      iVar2 = (int)(char)uVar3;
      goto locret_F00DAB48;
    }
  }
loc_F00DAAF4:
  iVar2 = 0;
locret_F00DAB48:
  return CONCAT44(param_2,iVar2);
}

