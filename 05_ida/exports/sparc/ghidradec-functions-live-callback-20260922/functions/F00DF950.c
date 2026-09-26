
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
  undefined8 *puVar1;
  undefined8 *puVar2;
  undefined8 *puVar3;
  undefined (*pauVar4) [13];
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  undefined *puVar8;
  uint uVar9;
  undefined4 unaff_l0;
  uint uVar10;
  undefined *puVar11;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar12;
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
  
  puVar1 = paIoaudio;
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
  uVar10 = 0;
  pauVar4 = paAudiochannel;
  switch(*(undefined4 *)(param_1 + 0x14)) {
  case :
    if (*(int *)(param_1 + 4) != 0x28) {
      uVar12 = 0x67;
      break;
    }
    puVar1 = paIoaudio;
    if (*(int *)(param_1 + 0x1c) == 0x82) {
      _objc_msgSend(paIoaudio,paInputchannelfo,*(undefined4 *)(param_1 + 0xc));
      puVar2 = puVar1;
      _objc_msgSend();
      *(undefined8 **)((int)register0x00000038 + -0x14) = puVar2;
      if (puVar2 == (undefined8 *)0x0) {
        uVar6 = *(undefined4 *)(param_1 + 0x24);
        uVar12 = 1;
loc_F00DFA9C:
        __NXAudioAddStream(puVar1,(undefined *)((int)register0x00000038 + -0x14),uVar6,0,uVar12);
      }
    }
    else {
      uVar12 = 4;
      if (*(int *)(param_1 + 0x1c) == 0x81) {
        uVar12 = 3;
      }
      _objc_msgSend(paIoaudio,paOutputchannelf,*(undefined4 *)(param_1 + 0xc));
      puVar2 = puVar1;
      _objc_msgSend();
      *(undefined8 **)((int)register0x00000038 + -0x14) = puVar2;
      if (puVar2 == (undefined8 *)0x0) {
        uVar6 = *(undefined4 *)(param_1 + 0x24);
        goto loc_F00DFA9C;
      }
    }
    _audio_snd_reply_ret_stream
              (param_2,*(undefined4 *)(param_1 + 0x10),
               *(undefined4 *)((int)register0x00000038 + -0x14));
    uVar12 = 0;
    break;
  case :
    if (*(int *)(param_1 + 4) != 0x20) {
      uVar12 = 0x67;
      break;
    }
    _objc_msgSend(paIoaudio,paOutputchannelf,*(undefined4 *)(param_1 + 0xc));
    __NXAudioGetSndoutOptions();
    if ((*(uint *)(param_1 + 0x1c) & 4) == 0) {
      uVar10 = *(uint *)((int)register0x00000038 + -0x18) & 0xfffffffe;
    }
    else {
      uVar10 = *(uint *)((int)register0x00000038 + -0x18) | 1;
    }
    *(uint *)((int)register0x00000038 + -0x18) = uVar10;
    if ((*(uint *)(param_1 + 0x1c) & 2) == 0) {
      uVar10 = *(uint *)((int)register0x00000038 + -0x18) & 0xffffffef;
    }
    else {
      uVar10 = *(uint *)((int)register0x00000038 + -0x18) | 0x10;
    }
    *(uint *)((int)register0x00000038 + -0x18) = uVar10;
    if ((*(uint *)(param_1 + 0x1c) & 1) == 0) {
      uVar10 = *(uint *)((int)register0x00000038 + -0x18) & 0xfffffff7;
    }
    else {
      uVar10 = *(uint *)((int)register0x00000038 + -0x18) | 8;
    }
    goto loc_F00E0170;
  case :
    if (*(int *)(param_1 + 4) == 0x18) {
      _objc_msgSend(paIoaudio,paOutputchannelf,*(undefined4 *)(param_1 + 0xc));
      __NXAudioGetSndoutOptions();
      uVar9 = *(uint *)((int)register0x00000038 + -0x18);
      if ((uVar9 & 1) != 0) {
        uVar10 = 4;
      }
      if ((uVar9 & 0x10) != 0) {
        uVar10 = uVar10 | 2;
      }
      if ((uVar9 & 8) != 0) {
        uVar10 = uVar10 | 1;
      }
      _audio_snd_reply_ret_parms(param_2,*(undefined4 *)(param_1 + 0x10),uVar10);
      uVar12 = 0;
    }
    else {
      uVar12 = 0x67;
    }
    break;
  case :
    if (*(int *)(param_1 + 4) == 0x20) {
      uVar9 = *(uint *)(param_1 + 0x1c);
      uVar12 = *(undefined4 *)(param_1 + 0xc);
      uVar10 = (uVar9 & 0xff00) >> 8;
      *(uint *)((int)register0x00000038 + -0x1c) = uVar10;
      uVar9 = uVar9 & 0xff;
      *(uint *)((int)register0x00000038 + -0x20) = uVar9;
      *(uint *)((int)register0x00000038 + -0x1c) = uVar10 * 2 + -0x56;
      *(uint *)((int)register0x00000038 + -0x20) = uVar9 * 2 + -0x56;
      _objc_msgSend(paIoaudio,paOutputchannelf,uVar12);
      __NXAudioSetSpeaker();
      uVar12 = 100;
    }
    else {
      uVar12 = 0x67;
    }
    break;
  case :
    if (*(int *)(param_1 + 4) == 0x18) {
      _objc_msgSend(paIoaudio,paOutputchannelf,*(undefined4 *)(param_1 + 0xc));
      __NXAudioGetSpeaker();
      iVar5 = *(int *)((int)register0x00000038 + -0x1c);
      uVar12 = *(undefined4 *)(param_1 + 0x10);
      *(int *)((int)register0x00000038 + -0x1c) = iVar5 / 2 + 0x2b;
      iVar7 = *(int *)((int)register0x00000038 + -0x20);
      *(uint *)((int)register0x00000038 + -0x20) = iVar7 / 2 + 0x2bU;
      _audio_snd_reply_ret_volume(param_2,uVar12,(iVar5 / 2 + 0x2b) * 0x100 | iVar7 / 2 + 0x2bU);
      uVar12 = 0;
    }
    else {
      uVar12 = 0x67;
    }
    break;
  case :
  case :
  case :
  case :
    uVar12 = 0x6c;
    break;
  case :
  case :
    if (*(int *)(param_1 + 4) != 0x28) {
      uVar12 = 0x67;
      break;
    }
    _objc_msgSend(paAudiochannel,paStreamforowner,*(undefined4 *)(param_1 + 0x24));
    if (pauVar4 != (undefined (*) [13])0x0) {
      *(undefined4 *)((int)register0x00000038 + -0x440) =
           *(undefined4 *)((int)register0x00000038 + -0x10);
      *(undefined4 *)((int)register0x00000038 + -0x43c) =
           *(undefined4 *)((int)register0x00000038 + -0xc);
      __NXAudioStreamControl();
      uVar12 = 100;
      break;
    }
  :
    uVar12 = 100;
    break;
  case :
    if (*(int *)(param_1 + 4) == 0x20) {
      puVar2 = paIoaudio;
      _objc_msgSend(paIoaudio,paOutputchannelf,*(undefined4 *)(param_1 + 0xc));
      puVar3 = puVar2;
      _objc_msgSend(puVar2,paAudiodevice);
      _audio_reset_snd_dev_port();
      if (puVar3 == (undefined8 *)0x0) {
        uVar12 = 0x70;
      }
      else {
        _objc_msgSend(puVar2,paRemovesndstrea);
        _objc_msgSend(puVar1,paInputchannelfo,*(undefined4 *)(param_1 + 0xc));
        _objc_msgSend();
        _audio_snd_reply_ret_device(param_2,*(undefined4 *)(param_1 + 0x10),puVar3);
        uVar12 = 0;
      }
    }
    else {
      uVar12 = 0x67;
    }
    break;
  case :
    if (*(int *)(param_1 + 4) != 0x30) {
      uVar12 = 0x67;
      break;
    }
    _objc_msgSend(paAudiochannel,paStreamforowner,*(undefined4 *)(param_1 + 0x1c));
    goto joined_r0xf00e02ec;
  case :
    if (*(int *)(param_1 + 4) != 0x30) {
      uVar12 = 0x67;
      break;
    }
    _objc_msgSend(paAudiochannel,paStreamforowner,*(undefined4 *)(param_1 + 0x1c));
joined_r0xf00e02ec:
    uVar12 = 0x6a;
    if (pauVar4 != (undefined (*) [13])0x0) {
      uVar12 = 100;
      __NXAudioRemoveStream();
    }
    break;
  case :
    if (*(int *)(param_1 + 4) != 0x20) {
      uVar12 = 0x67;
      break;
    }
    _objc_msgSend(paIoaudio,paOutputchannelf,*(undefined4 *)(param_1 + 0xc));
    __NXAudioGetSndoutOptions();
    if ((*(uint *)(param_1 + 0x1c) & 1) == 0) {
      uVar10 = *(uint *)((int)register0x00000038 + -0x18) & 0xfffffffd;
    }
    else {
      uVar10 = *(uint *)((int)register0x00000038 + -0x18) | 2;
    }
    *(uint *)((int)register0x00000038 + -0x18) = uVar10;
    if ((*(uint *)(param_1 + 0x1c) & 2) == 0) {
      uVar10 = *(uint *)((int)register0x00000038 + -0x18) & 0xfffffffb;
    }
    else {
      uVar10 = *(uint *)((int)register0x00000038 + -0x18) | 4;
    }
loc_F00E0170:
    *(uint *)((int)register0x00000038 + -0x18) = uVar10;
    __NXAudioSetSndoutOptions(puVar1,0,*(undefined4 *)((int)register0x00000038 + -0x18));
    uVar12 = 100;
    break;
  case :
    if (*(int *)(param_1 + 4) != 0x18) {
      uVar12 = 0x67;
      break;
    }
    _objc_msgSend(paIoaudio,paOutputchannelf,*(undefined4 *)(param_1 + 0xc));
    puVar11 = (undefined *)((int)register0x00000038 + -0x38);
    __NXAudioGetSamplingRates();
    *(undefined4 *)((int)register0x00000038 + -0x24) = 0;
    if (*(int *)((int)register0x00000038 + -0x43c) != 0) {
      *(undefined4 *)((int)register0x00000038 + -0x24) = 1;
    }
    iVar7 = 0;
    puVar8 = puVar11;
    if (0 < *(int *)((int)register0x00000038 + -0x440)) {
      do {
        iVar5 = *(int *)(puVar8 + -0x400);
        uVar10 = *(uint *)((int)register0x00000038 + -0x24);
        if (iVar5 - 8000U < 0xe) {
          uVar10 = uVar10 | 2;
loc_F00DFE1C:
          *(uint *)((int)register0x00000038 + -0x24) = uVar10;
        }
        else {
          if (iVar5 == 0x5622) {
            uVar10 = uVar10 | 0x10;
            goto loc_F00DFE1C;
          }
          if (iVar5 < 0x5623) {
            if (iVar5 == 0x2b11) {
              uVar10 = *(uint *)((int)register0x00000038 + -0x24) | 4;
            }
            else {
              uVar10 = uVar10 | 8;
              if (iVar5 != 16000) goto loc_F00DFE24;
            }
            goto loc_F00DFE1C;
          }
          if (iVar5 == 0xac44) {
            uVar10 = *(uint *)((int)register0x00000038 + -0x24) | 0x40;
            goto loc_F00DFE1C;
          }
          if (iVar5 < 0xac45) {
            if (iVar5 == 32000) {
              uVar10 = *(uint *)((int)register0x00000038 + -0x24) | 0x20;
              goto loc_F00DFE1C;
            }
          }
          else if (iVar5 == 48000) {
            uVar10 = *(uint *)((int)register0x00000038 + -0x24) | 0x80;
            goto loc_F00DFE1C;
          }
        }
loc_F00DFE24:
        iVar7 = iVar7 + 1;
        puVar8 = puVar8 + 4;
      } while (iVar7 < *(int *)((int)register0x00000038 + -0x440));
    }
    __NXAudioGetDataEncodings
              (puVar1,(undefined *)((int)register0x00000038 + -0x438),
               (undefined *)((int)register0x00000038 + -0x440));
    *(undefined4 *)((int)register0x00000038 + -0x30) = 0;
    iVar7 = 0;
    if (0 < *(int *)((int)register0x00000038 + -0x440)) {
      do {
        iVar5 = *(int *)(puVar11 + -0x400);
        if (iVar5 == 0x259) {
          uVar10 = *(uint *)((int)register0x00000038 + -0x30) | 2;
loc_F00DFEAC:
          *(uint *)((int)register0x00000038 + -0x30) = uVar10;
        }
        else if (iVar5 < 0x25a) {
          if (iVar5 == 600) {
            uVar10 = *(uint *)((int)register0x00000038 + -0x30) | 4;
            goto loc_F00DFEAC;
          }
        }
        else if (iVar5 == 0x25a) {
          uVar10 = *(uint *)((int)register0x00000038 + -0x30) | 1;
          goto loc_F00DFEAC;
        }
        iVar7 = iVar7 + 1;
        puVar11 = puVar11 + 4;
      } while (iVar7 < *(int *)((int)register0x00000038 + -0x440));
    }
    goto loc_F00E00C8;
  case :
    if (*(int *)(param_1 + 4) != 0x18) {
      uVar12 = 0x67;
      break;
    }
    _objc_msgSend(paIoaudio,paInputchannelfo,*(undefined4 *)(param_1 + 0xc));
    puVar11 = (undefined *)((int)register0x00000038 + -0x38);
    __NXAudioGetSamplingRates();
    *(undefined4 *)((int)register0x00000038 + -0x24) = 0;
    if (*(int *)((int)register0x00000038 + -0x43c) != 0) {
      *(undefined4 *)((int)register0x00000038 + -0x24) = 1;
    }
    iVar7 = 0;
    puVar8 = puVar11;
    if (0 < *(int *)((int)register0x00000038 + -0x440)) {
      do {
        iVar5 = *(int *)(puVar8 + -0x400);
        uVar10 = *(uint *)((int)register0x00000038 + -0x24);
        if (iVar5 - 8000U < 0xe) {
          uVar10 = uVar10 | 2;
loc_F00E0020:
          *(uint *)((int)register0x00000038 + -0x24) = uVar10;
        }
        else {
          if (iVar5 == 0x5622) {
            uVar10 = uVar10 | 0x10;
            goto loc_F00E0020;
          }
          if (iVar5 < 0x5623) {
            if (iVar5 == 0x2b11) {
              uVar10 = *(uint *)((int)register0x00000038 + -0x24) | 4;
            }
            else {
              uVar10 = uVar10 | 8;
              if (iVar5 != 16000) goto loc_F00E0028;
            }
            goto loc_F00E0020;
          }
          if (iVar5 == 0xac44) {
            uVar10 = *(uint *)((int)register0x00000038 + -0x24) | 0x40;
            goto loc_F00E0020;
          }
          if (iVar5 < 0xac45) {
            if (iVar5 == 32000) {
              uVar10 = *(uint *)((int)register0x00000038 + -0x24) | 0x20;
              goto loc_F00E0020;
            }
          }
          else if (iVar5 == 48000) {
            uVar10 = *(uint *)((int)register0x00000038 + -0x24) | 0x80;
            goto loc_F00E0020;
          }
        }
loc_F00E0028:
        iVar7 = iVar7 + 1;
        puVar8 = puVar8 + 4;
      } while (iVar7 < *(int *)((int)register0x00000038 + -0x440));
    }
    __NXAudioGetDataEncodings
              (puVar1,(undefined *)((int)register0x00000038 + -0x438),
               (undefined *)((int)register0x00000038 + -0x440));
    *(undefined4 *)((int)register0x00000038 + -0x30) = 0;
    iVar7 = 0;
    if (0 < *(int *)((int)register0x00000038 + -0x440)) {
      do {
        iVar5 = *(int *)(puVar11 + -0x400);
        if (iVar5 == 0x259) {
          uVar10 = *(uint *)((int)register0x00000038 + -0x30) | 2;
loc_F00E00B0:
          *(uint *)((int)register0x00000038 + -0x30) = uVar10;
        }
        else if (iVar5 < 0x25a) {
          if (iVar5 == 600) {
            uVar10 = *(uint *)((int)register0x00000038 + -0x30) | 4;
            goto loc_F00E00B0;
          }
        }
        else if (iVar5 == 0x25a) {
          uVar10 = *(uint *)((int)register0x00000038 + -0x30) | 1;
          goto loc_F00E00B0;
        }
        iVar7 = iVar7 + 1;
        puVar11 = puVar11 + 4;
      } while (iVar7 < *(int *)((int)register0x00000038 + -0x440));
    }
loc_F00E00C8:
    __NXAudioGetChannelCountLimit(puVar1,(undefined *)((int)register0x00000038 + -0x34));
    _audio_snd_reply_ret_formats
              (param_2,*(undefined4 *)(param_1 + 0x10),
               *(undefined4 *)((int)register0x00000038 + -0x24),
               *(undefined4 *)((int)register0x00000038 + -0x28),
               *(undefined4 *)((int)register0x00000038 + -0x2c),
               *(undefined4 *)((int)register0x00000038 + -0x30),
               *(undefined4 *)((int)register0x00000038 + -0x34));
    uVar12 = 0;
  }
  return CONCAT44(param_2,uVar12);
}

