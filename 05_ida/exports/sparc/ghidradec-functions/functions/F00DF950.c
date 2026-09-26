
/* WARNING: Removing unreachable block (ram,0xf00dfa9c) */
/* WARNING: Removing unreachable block (ram,0xf00dfa04) */
/* WARNING: Removing unreachable block (ram,0xf00dfa60) */
/* WARNING: Removing unreachable block (ram,0xf00dfaec) */
/* WARNING: Removing unreachable block (ram,0xf00dfbb8) */
/* WARNING: Removing unreachable block (ram,0xf00dfb74) */
/* WARNING: Removing unreachable block (ram,0xf00dfc20) */
/* WARNING: Removing unreachable block (ram,0xf00dfc70) */
/* WARNING: Removing unreachable block (ram,0xf00e01d0) */
/* WARNING: Removing unreachable block (ram,0xf00e0274) */
/* WARNING: Removing unreachable block (ram,0xf00e025c) */
/* WARNING: Removing unreachable block (ram,0xf00e0220) */
/* WARNING: Removing unreachable block (ram,0xf00e0204) */
/* WARNING: Removing unreachable block (ram,0xf00e02a4) */
/* WARNING: Removing unreachable block (ram,0xf00e012c) */
/* WARNING: Removing unreachable block (ram,0xf00e00f0) */
/* WARNING: Removing unreachable block (ram,0xf00dfe38) */
/* WARNING: Removing unreachable block (ram,0xf00dfce4) */
/* WARNING: Removing unreachable block (ram,0xf00dff08) */
/* WARNING: Removing unreachable block (ram,0xf00e003c) */
/* WARNING: Removing unreachable block (ram,0xf00dfd04) */
/* WARNING: Removing unreachable block (ram,0xf00e00c8) */
/* WARNING: Removing unreachable block (ram,0xf00e0120) */
/* WARNING: Removing unreachable block (ram,0xf00e02e0) */
/* WARNING: Removing unreachable block (ram,0xf00e02f4) */
/* WARNING: Removing unreachable block (ram,0xf00e0218) */
/* WARNING: Removing unreachable block (ram,0xf00e0244) */
/* WARNING: Removing unreachable block (ram,0xf00e0264) */
/* WARNING: Removing unreachable block (ram,0xf00e01ac) */
/* WARNING: Removing unreachable block (ram,0xf00dfc64) */
/* WARNING: Removing unreachable block (ram,0xf00dfcb4) */
/* WARNING: Removing unreachable block (ram,0xf00dfc30) */
/* WARNING: Removing unreachable block (ram,0xf00dfb7c) */
/* WARNING: Removing unreachable block (ram,0xf00dfae0) */
/* WARNING: Removing unreachable block (ram,0xf00e017c) */
/* WARNING: Removing unreachable block (ram,0xf00dfa74) */
/* WARNING: Removing unreachable block (ram,0xf00dfa18) */
/* WARNING: Removing unreachable block (ram,0xf00dfab0) */
/* WARNING: Removing unreachable block (ram,0xf00dfee8) */

undefined8 sub_F00DF950(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  uint uVar6;
  undefined4 unaff_l0;
  uint uVar7;
  undefined *puVar8;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar9;
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
  int aiStack_438 [270];
  
  iVar3 = paIoaudio;
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
  *(undefined4 *)((int)register0x00000038 + -0x18) = 0;
  *(undefined4 *)((int)register0x00000038 + -0xc) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
  uVar7 = 0;
  iVar4 = paAudiochannel;
  switch(*(undefined4 *)(param_1 + 0x14)) {
  case :
    if (*(int *)(param_1 + 4) != 0x28) {
      uVar9 = 0x67;
      break;
    }
    iVar3 = paIoaudio;
    if (*(int *)(param_1 + 0x1c) == 0x82) {
      _objc_msgSend(paIoaudio,paInputchannelfo,*(undefined4 *)(param_1 + 0xc));
      iVar4 = iVar3;
      _objc_msgSend();
      *(int *)((int)register0x00000038 + -0x14) = iVar4;
      if (iVar4 == 0) {
        uVar2 = *(undefined4 *)(param_1 + 0x24);
        uVar9 = 1;
loc_F00DFA9C:
        __NXAudioAddStream(iVar3,(undefined *)((int)register0x00000038 + -0x14),uVar2,0,uVar9);
      }
    }
    else {
      uVar9 = 4;
      if (*(int *)(param_1 + 0x1c) == 0x81) {
        uVar9 = 3;
      }
      _objc_msgSend(paIoaudio,paOutputchannelf,*(undefined4 *)(param_1 + 0xc));
      iVar4 = iVar3;
      _objc_msgSend();
      *(int *)((int)register0x00000038 + -0x14) = iVar4;
      if (iVar4 == 0) {
        uVar2 = *(undefined4 *)(param_1 + 0x24);
        goto loc_F00DFA9C;
      }
    }
    _audio_snd_reply_ret_stream
              (param_2,*(undefined4 *)(param_1 + 0x10),
               *(undefined4 *)((int)register0x00000038 + -0x14));
    uVar9 = 0;
    break;
  case :
    if (*(int *)(param_1 + 4) != 0x20) {
      uVar9 = 0x67;
      break;
    }
    _objc_msgSend(paIoaudio,paOutputchannelf,*(undefined4 *)(param_1 + 0xc));
    __NXAudioGetSndoutOptions();
    if ((*(uint *)(param_1 + 0x1c) & 4) == 0) {
      uVar7 = *(uint *)((int)register0x00000038 + -0x18) & 0xfffffffe;
    }
    else {
      uVar7 = *(uint *)((int)register0x00000038 + -0x18) | 1;
    }
    *(uint *)((int)register0x00000038 + -0x18) = uVar7;
    if ((*(uint *)(param_1 + 0x1c) & 2) == 0) {
      uVar7 = *(uint *)((int)register0x00000038 + -0x18) & 0xffffffef;
    }
    else {
      uVar7 = *(uint *)((int)register0x00000038 + -0x18) | 0x10;
    }
    *(uint *)((int)register0x00000038 + -0x18) = uVar7;
    if ((*(uint *)(param_1 + 0x1c) & 1) == 0) {
      uVar7 = *(uint *)((int)register0x00000038 + -0x18) & 0xfffffff7;
    }
    else {
      uVar7 = *(uint *)((int)register0x00000038 + -0x18) | 8;
    }
    goto loc_F00E0170;
  case :
    if (*(int *)(param_1 + 4) == 0x18) {
      _objc_msgSend(paIoaudio,paOutputchannelf,*(undefined4 *)(param_1 + 0xc));
      __NXAudioGetSndoutOptions();
      uVar6 = *(uint *)((int)register0x00000038 + -0x18);
      if ((uVar6 & 1) != 0) {
        uVar7 = 4;
      }
      if ((uVar6 & 0x10) != 0) {
        uVar7 = uVar7 | 2;
      }
      if ((uVar6 & 8) != 0) {
        uVar7 = uVar7 | 1;
      }
      _audio_snd_reply_ret_parms(param_2,*(undefined4 *)(param_1 + 0x10),uVar7);
      uVar9 = 0;
    }
    else {
      uVar9 = 0x67;
    }
    break;
  case :
    if (*(int *)(param_1 + 4) == 0x20) {
      uVar6 = *(uint *)(param_1 + 0x1c);
      uVar9 = *(undefined4 *)(param_1 + 0xc);
      uVar7 = (uVar6 & 0xff00) >> 8;
      *(uint *)((int)register0x00000038 + -0x1c) = uVar7;
      uVar6 = uVar6 & 0xff;
      *(uint *)((int)register0x00000038 + -0x20) = uVar6;
      *(uint *)((int)register0x00000038 + -0x1c) = uVar7 * 2 + -0x56;
      *(uint *)((int)register0x00000038 + -0x20) = uVar6 * 2 + -0x56;
      _objc_msgSend(paIoaudio,paOutputchannelf,uVar9);
      __NXAudioSetSpeaker();
      uVar9 = 100;
    }
    else {
      uVar9 = 0x67;
    }
    break;
  case :
    if (*(int *)(param_1 + 4) == 0x18) {
      _objc_msgSend(paIoaudio,paOutputchannelf,*(undefined4 *)(param_1 + 0xc));
      __NXAudioGetSpeaker();
      iVar4 = *(int *)((int)register0x00000038 + -0x1c);
      uVar9 = *(undefined4 *)(param_1 + 0x10);
      *(int *)((int)register0x00000038 + -0x1c) = iVar4 / 2 + 0x2b;
      iVar3 = *(int *)((int)register0x00000038 + -0x20);
      *(uint *)((int)register0x00000038 + -0x20) = iVar3 / 2 + 0x2bU;
      _audio_snd_reply_ret_volume(param_2,uVar9,(iVar4 / 2 + 0x2b) * 0x100 | iVar3 / 2 + 0x2bU);
      uVar9 = 0;
    }
    else {
      uVar9 = 0x67;
    }
    break;
  case :
  case :
  case :
  case :
    uVar9 = 0x6c;
    break;
  case :
  case :
    if (*(int *)(param_1 + 4) != 0x28) {
      uVar9 = 0x67;
      break;
    }
    iVar3 = paAudiochannel;
    _objc_msgSend(paAudiochannel,paStreamforowner,*(undefined4 *)(param_1 + 0x24));
    if (iVar3 != 0) {
      *(undefined4 *)((int)register0x00000038 + -0x440) =
           *(undefined4 *)((int)register0x00000038 + -0x10);
      *(undefined4 *)((int)register0x00000038 + -0x43c) =
           *(undefined4 *)((int)register0x00000038 + -0xc);
      __NXAudioStreamControl();
      uVar9 = 100;
      break;
    }
  :
    uVar9 = 100;
    break;
  case :
    if (*(int *)(param_1 + 4) == 0x20) {
      iVar4 = paIoaudio;
      _objc_msgSend(paIoaudio,paOutputchannelf,*(undefined4 *)(param_1 + 0xc));
      iVar1 = iVar4;
      _objc_msgSend(iVar4,paAudiodevice);
      _audio_reset_snd_dev_port();
      if (iVar1 == 0) {
        uVar9 = 0x70;
      }
      else {
        _objc_msgSend(iVar4,paRemovesndstrea);
        _objc_msgSend(iVar3,paInputchannelfo,*(undefined4 *)(param_1 + 0xc));
        _objc_msgSend();
        _audio_snd_reply_ret_device(param_2,*(undefined4 *)(param_1 + 0x10),iVar1);
        uVar9 = 0;
      }
    }
    else {
      uVar9 = 0x67;
    }
    break;
  case :
    if (*(int *)(param_1 + 4) != 0x30) {
      uVar9 = 0x67;
      break;
    }
    _objc_msgSend(paAudiochannel,paStreamforowner,*(undefined4 *)(param_1 + 0x1c));
    goto joined_r0xf00e02ec;
  case :
    if (*(int *)(param_1 + 4) != 0x30) {
      uVar9 = 0x67;
      break;
    }
    _objc_msgSend(paAudiochannel,paStreamforowner,*(undefined4 *)(param_1 + 0x1c));
joined_r0xf00e02ec:
    uVar9 = 0x6a;
    if (iVar4 != 0) {
      uVar9 = 100;
      __NXAudioRemoveStream();
    }
    break;
  case :
    if (*(int *)(param_1 + 4) != 0x20) {
      uVar9 = 0x67;
      break;
    }
    _objc_msgSend(paIoaudio,paOutputchannelf,*(undefined4 *)(param_1 + 0xc));
    __NXAudioGetSndoutOptions();
    if ((*(uint *)(param_1 + 0x1c) & 1) == 0) {
      uVar7 = *(uint *)((int)register0x00000038 + -0x18) & 0xfffffffd;
    }
    else {
      uVar7 = *(uint *)((int)register0x00000038 + -0x18) | 2;
    }
    *(uint *)((int)register0x00000038 + -0x18) = uVar7;
    if ((*(uint *)(param_1 + 0x1c) & 2) == 0) {
      uVar7 = *(uint *)((int)register0x00000038 + -0x18) & 0xfffffffb;
    }
    else {
      uVar7 = *(uint *)((int)register0x00000038 + -0x18) | 4;
    }
loc_F00E0170:
    *(uint *)((int)register0x00000038 + -0x18) = uVar7;
    __NXAudioSetSndoutOptions(iVar3,0,*(undefined4 *)((int)register0x00000038 + -0x18));
    uVar9 = 100;
    break;
  case :
    if (*(int *)(param_1 + 4) != 0x18) {
      uVar9 = 0x67;
      break;
    }
    _objc_msgSend(paIoaudio,paOutputchannelf,*(undefined4 *)(param_1 + 0xc));
    puVar8 = (undefined *)((int)register0x00000038 + -0x38);
    __NXAudioGetSamplingRates();
    *(undefined4 *)((int)register0x00000038 + -0x24) = 0;
    if (*(int *)((int)register0x00000038 + -0x43c) != 0) {
      *(undefined4 *)((int)register0x00000038 + -0x24) = 1;
    }
    iVar4 = 0;
    puVar5 = puVar8;
    if (0 < *(int *)((int)register0x00000038 + -0x440)) {
      do {
        iVar1 = *(int *)(puVar5 + -0x400);
        uVar7 = *(uint *)((int)register0x00000038 + -0x24);
        if (iVar1 - 8000U < 0xe) {
          uVar7 = uVar7 | 2;
loc_F00DFE1C:
          *(uint *)((int)register0x00000038 + -0x24) = uVar7;
        }
        else {
          if (iVar1 == 0x5622) {
            uVar7 = uVar7 | 0x10;
            goto loc_F00DFE1C;
          }
          if (iVar1 < 0x5623) {
            if (iVar1 == 0x2b11) {
              uVar7 = *(uint *)((int)register0x00000038 + -0x24) | 4;
            }
            else {
              uVar7 = uVar7 | 8;
              if (iVar1 != 16000) goto loc_F00DFE24;
            }
            goto loc_F00DFE1C;
          }
          if (iVar1 == 0xac44) {
            uVar7 = *(uint *)((int)register0x00000038 + -0x24) | 0x40;
            goto loc_F00DFE1C;
          }
          if (iVar1 < 0xac45) {
            if (iVar1 == 32000) {
              uVar7 = *(uint *)((int)register0x00000038 + -0x24) | 0x20;
              goto loc_F00DFE1C;
            }
          }
          else if (iVar1 == 48000) {
            uVar7 = *(uint *)((int)register0x00000038 + -0x24) | 0x80;
            goto loc_F00DFE1C;
          }
        }
loc_F00DFE24:
        iVar4 = iVar4 + 1;
        puVar5 = puVar5 + 4;
      } while (iVar4 < *(int *)((int)register0x00000038 + -0x440));
    }
    __NXAudioGetDataEncodings
              (iVar3,(undefined *)((int)register0x00000038 + -0x438),
               (undefined *)((int)register0x00000038 + -0x440));
    *(undefined4 *)((int)register0x00000038 + -0x30) = 0;
    iVar4 = 0;
    if (0 < *(int *)((int)register0x00000038 + -0x440)) {
      do {
        iVar1 = *(int *)(puVar8 + -0x400);
        if (iVar1 == 0x259) {
          uVar7 = *(uint *)((int)register0x00000038 + -0x30) | 2;
loc_F00DFEAC:
          *(uint *)((int)register0x00000038 + -0x30) = uVar7;
        }
        else if (iVar1 < 0x25a) {
          if (iVar1 == 600) {
            uVar7 = *(uint *)((int)register0x00000038 + -0x30) | 4;
            goto loc_F00DFEAC;
          }
        }
        else if (iVar1 == 0x25a) {
          uVar7 = *(uint *)((int)register0x00000038 + -0x30) | 1;
          goto loc_F00DFEAC;
        }
        iVar4 = iVar4 + 1;
        puVar8 = puVar8 + 4;
      } while (iVar4 < *(int *)((int)register0x00000038 + -0x440));
    }
    goto loc_F00E00C8;
  case :
    if (*(int *)(param_1 + 4) != 0x18) {
      uVar9 = 0x67;
      break;
    }
    _objc_msgSend(paIoaudio,paInputchannelfo,*(undefined4 *)(param_1 + 0xc));
    puVar8 = (undefined *)((int)register0x00000038 + -0x38);
    __NXAudioGetSamplingRates();
    *(undefined4 *)((int)register0x00000038 + -0x24) = 0;
    if (*(int *)((int)register0x00000038 + -0x43c) != 0) {
      *(undefined4 *)((int)register0x00000038 + -0x24) = 1;
    }
    iVar4 = 0;
    puVar5 = puVar8;
    if (0 < *(int *)((int)register0x00000038 + -0x440)) {
      do {
        iVar1 = *(int *)(puVar5 + -0x400);
        uVar7 = *(uint *)((int)register0x00000038 + -0x24);
        if (iVar1 - 8000U < 0xe) {
          uVar7 = uVar7 | 2;
loc_F00E0020:
          *(uint *)((int)register0x00000038 + -0x24) = uVar7;
        }
        else {
          if (iVar1 == 0x5622) {
            uVar7 = uVar7 | 0x10;
            goto loc_F00E0020;
          }
          if (iVar1 < 0x5623) {
            if (iVar1 == 0x2b11) {
              uVar7 = *(uint *)((int)register0x00000038 + -0x24) | 4;
            }
            else {
              uVar7 = uVar7 | 8;
              if (iVar1 != 16000) goto loc_F00E0028;
            }
            goto loc_F00E0020;
          }
          if (iVar1 == 0xac44) {
            uVar7 = *(uint *)((int)register0x00000038 + -0x24) | 0x40;
            goto loc_F00E0020;
          }
          if (iVar1 < 0xac45) {
            if (iVar1 == 32000) {
              uVar7 = *(uint *)((int)register0x00000038 + -0x24) | 0x20;
              goto loc_F00E0020;
            }
          }
          else if (iVar1 == 48000) {
            uVar7 = *(uint *)((int)register0x00000038 + -0x24) | 0x80;
            goto loc_F00E0020;
          }
        }
loc_F00E0028:
        iVar4 = iVar4 + 1;
        puVar5 = puVar5 + 4;
      } while (iVar4 < *(int *)((int)register0x00000038 + -0x440));
    }
    __NXAudioGetDataEncodings
              (iVar3,(undefined *)((int)register0x00000038 + -0x438),
               (undefined *)((int)register0x00000038 + -0x440));
    *(undefined4 *)((int)register0x00000038 + -0x30) = 0;
    iVar4 = 0;
    if (0 < *(int *)((int)register0x00000038 + -0x440)) {
      do {
        iVar1 = *(int *)(puVar8 + -0x400);
        if (iVar1 == 0x259) {
          uVar7 = *(uint *)((int)register0x00000038 + -0x30) | 2;
loc_F00E00B0:
          *(uint *)((int)register0x00000038 + -0x30) = uVar7;
        }
        else if (iVar1 < 0x25a) {
          if (iVar1 == 600) {
            uVar7 = *(uint *)((int)register0x00000038 + -0x30) | 4;
            goto loc_F00E00B0;
          }
        }
        else if (iVar1 == 0x25a) {
          uVar7 = *(uint *)((int)register0x00000038 + -0x30) | 1;
          goto loc_F00E00B0;
        }
        iVar4 = iVar4 + 1;
        puVar8 = puVar8 + 4;
      } while (iVar4 < *(int *)((int)register0x00000038 + -0x440));
    }
loc_F00E00C8:
    __NXAudioGetChannelCountLimit(iVar3,(undefined *)((int)register0x00000038 + -0x34));
    _audio_snd_reply_ret_formats
              (param_2,*(undefined4 *)(param_1 + 0x10),
               *(undefined4 *)((int)register0x00000038 + -0x24),
               *(undefined4 *)((int)register0x00000038 + -0x28),
               *(undefined4 *)((int)register0x00000038 + -0x2c),
               *(undefined4 *)((int)register0x00000038 + -0x30),
               *(undefined4 *)((int)register0x00000038 + -0x34));
    uVar9 = 0;
  }
  return CONCAT44(param_2,uVar9);
}
