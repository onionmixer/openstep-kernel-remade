/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bcad4 */

undefined4 FUN_001bcad4(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *local_440;
  undefined4 local_43c;
  int local_438;
  int local_434;
  int local_430 [256];
  undefined4 local_30;
  uint local_2c;
  undefined4 local_28;
  undefined4 local_24;
  uint local_20;
  uint local_1c;
  int local_18;
  uint local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_43c = 100;
  local_14 = 0;
  local_440 = (undefined4 *)0x0;
  local_8 = 0;
  local_c = 0;
  switch(*(undefined4 *)(param_1 + 0x14)) {
  case 100:
    if (*(int *)(param_1 + 4) == 0x28) {
      if (*(int *)(param_1 + 0x1c) == 0x82) {
        uVar2 = _objc_msgSend(PTR_s_IOAudio_001f9dbc,PTR_s__inputChannelForSndPort__001f9698,
                              *(undefined4 *)(param_1 + 0xc));
        local_10 = _objc_msgSend(uVar2,PTR_s_streamUserForOwnerPort__001f9694,
                                 *(undefined4 *)(param_1 + 0x24));
        if (local_10 != 0) goto LAB_001bcc22;
        local_440 = (undefined4 *)0x1;
      }
      else {
        local_440 = (undefined4 *)0x4;
        if (*(int *)(param_1 + 0x1c) == 0x81) {
          local_440 = (undefined4 *)0x3;
        }
        uVar2 = _objc_msgSend(PTR_s_IOAudio_001f9dbc,PTR_s__outputChannelForSndPort__001f9690,
                              *(undefined4 *)(param_1 + 0xc));
        local_10 = _objc_msgSend(uVar2,PTR_s_streamUserForOwnerPort__001f9694,
                                 *(undefined4 *)(param_1 + 0x24));
        if (local_10 != 0) goto LAB_001bcc22;
      }
      __NXAudioAddStream(uVar2,&local_10,*(undefined4 *)(param_1 + 0x24),0,local_440);
LAB_001bcc22:
      _audio_snd_reply_ret_stream(param_2,*(undefined4 *)(param_1 + 0x10),local_10);
      return 0;
    }
    break;
  case 0x65:
    if (*(int *)(param_1 + 4) == 0x20) {
      uVar2 = _objc_msgSend(PTR_s_IOAudio_001f9dbc,PTR_s__outputChannelForSndPort__001f9690,
                            *(undefined4 *)(param_1 + 0xc));
      __NXAudioGetSndoutOptions(uVar2,&local_14);
      if ((*(byte *)(param_1 + 0x1c) & 4) == 0) {
        local_14 = local_14 & 0xfffffffe;
      }
      else {
        local_14 = local_14 | 1;
      }
      if ((*(byte *)(param_1 + 0x1c) & 2) == 0) {
        local_14 = local_14 & 0xffffffef;
      }
      else {
        local_14 = local_14 | 0x10;
      }
      if ((*(byte *)(param_1 + 0x1c) & 1) == 0) {
        local_14 = local_14 & 0xfffffff7;
      }
      else {
        local_14 = local_14 | 8;
      }
LAB_001bd18c:
      __NXAudioSetSndoutOptions(uVar2,0,local_14);
      return 100;
    }
    break;
  case 0x66:
    if (*(int *)(param_1 + 4) == 0x18) {
      uVar2 = _objc_msgSend(PTR_s_IOAudio_001f9dbc,PTR_s__outputChannelForSndPort__001f9690,
                            *(undefined4 *)(param_1 + 0xc));
      __NXAudioGetSndoutOptions(uVar2,&local_14);
      if ((local_14 & 1) != 0) {
        local_440 = (undefined4 *)0x4;
      }
      if ((local_14 & 0x10) != 0) {
        local_440 = (undefined4 *)((uint)local_440 | 2);
      }
      if ((local_14 & 8) != 0) {
        local_440 = (undefined4 *)((uint)local_440 | 1);
      }
      _audio_snd_reply_ret_parms(param_2,*(undefined4 *)(param_1 + 0x10),local_440);
      return 0;
    }
    break;
  case 0x67:
    if (*(int *)(param_1 + 4) == 0x20) {
      local_18 = (uint)*(byte *)(param_1 + 0x1d) * 2 + -0x56;
      local_1c = (*(uint *)(param_1 + 0x1c) & 0xff) * 2 - 0x56;
      uVar2 = _objc_msgSend(PTR_s_IOAudio_001f9dbc,PTR_s__outputChannelForSndPort__001f9690,
                            *(undefined4 *)(param_1 + 0xc));
      __NXAudioSetSpeaker(uVar2,0,local_18,local_1c);
      return 100;
    }
    break;
  case 0x68:
    if (*(int *)(param_1 + 4) == 0x18) {
      uVar2 = _objc_msgSend(PTR_s_IOAudio_001f9dbc,PTR_s__outputChannelForSndPort__001f9690,
                            *(undefined4 *)(param_1 + 0xc));
      __NXAudioGetSpeaker(uVar2,&local_18,&local_1c);
      local_18 = local_18 / 2 + 0x2b;
      local_1c = (int)local_1c / 2 + 0x2b;
      _audio_snd_reply_ret_volume
                (param_2,*(undefined4 *)(param_1 + 0x10),local_18 * 0x100 | local_1c);
      return 0;
    }
    break;
  case 0x69:
  case 0x6c:
  case 0x6d:
  case 0x6f:
    return 0x6c;
  case 0x6a:
  case 0x6b:
    if (*(int *)(param_1 + 4) == 0x28) {
      iVar3 = _objc_msgSend(PTR_s_AudioChannel_001f9db8,PTR_s_streamForOwnerPort__001f96bc,
                            *(undefined4 *)(param_1 + 0x24));
      if (iVar3 == 0) {
        return 100;
      }
      __NXAudioStreamControl(iVar3,2,local_c,local_8);
      return 100;
    }
    break;
  case 0x6e:
    if (*(int *)(param_1 + 4) == 0x20) {
      uVar2 = _objc_msgSend(PTR_s_IOAudio_001f9dbc,PTR_s__outputChannelForSndPort__001f9690,
                            *(undefined4 *)(param_1 + 0xc));
      uVar4 = _objc_msgSend(uVar2,PTR_s_audioDevice_001f990c,*(undefined4 *)(param_1 + 0x1c));
      iVar3 = _audio_reset_snd_dev_port(uVar4);
      if (iVar3 != 0) {
        _objc_msgSend(uVar2,PTR_s_removeSndStreams_001f968c);
        uVar2 = _objc_msgSend(PTR_s_IOAudio_001f9dbc,PTR_s__inputChannelForSndPort__001f9698,
                              *(undefined4 *)(param_1 + 0xc));
        _objc_msgSend(uVar2,PTR_s_removeSndStreams_001f968c);
        _audio_snd_reply_ret_device(param_2,*(undefined4 *)(param_1 + 0x10),iVar3);
        return 0;
      }
      return 0x70;
    }
    break;
  case 0x70:
    if (*(int *)(param_1 + 4) == 0x30) {
      iVar3 = _objc_msgSend(PTR_s_AudioChannel_001f9db8,PTR_s_streamForOwnerPort__001f96bc,
                            *(undefined4 *)(param_1 + 0x1c));
joined_r0x001bd2e0:
      if (iVar3 != 0) {
        __NXAudioRemoveStream(iVar3);
        return 100;
      }
      return 0x6a;
    }
    break;
  case 0x71:
    if (*(int *)(param_1 + 4) == 0x30) {
      iVar3 = _objc_msgSend(PTR_s_AudioChannel_001f9db8,PTR_s_streamForOwnerPort__001f96bc,
                            *(undefined4 *)(param_1 + 0x1c));
      goto joined_r0x001bd2e0;
    }
    break;
  case 0x72:
    if (*(int *)(param_1 + 4) == 0x20) {
      uVar2 = _objc_msgSend(PTR_s_IOAudio_001f9dbc,PTR_s__outputChannelForSndPort__001f9690,
                            *(undefined4 *)(param_1 + 0xc));
      __NXAudioGetSndoutOptions(uVar2,&local_14);
      if ((*(byte *)(param_1 + 0x1c) & 1) == 0) {
        local_14 = local_14 & 0xfffffffd;
      }
      else {
        local_14 = local_14 | 2;
      }
      if ((*(byte *)(param_1 + 0x1c) & 2) == 0) {
        local_14 = local_14 & 0xfffffffb;
      }
      else {
        local_14 = local_14 | 4;
      }
      goto LAB_001bd18c;
    }
    break;
  case 0x73:
    if (*(int *)(param_1 + 4) == 0x18) {
      uVar2 = _objc_msgSend(PTR_s_IOAudio_001f9dbc,PTR_s__outputChannelForSndPort__001f9690,
                            *(undefined4 *)(param_1 + 0xc));
      __NXAudioGetSamplingRates(uVar2,&local_434,&local_24,&local_28,local_430,&local_438);
      local_20 = 0;
      if (local_434 != 0) {
        local_20 = 1;
      }
      local_20 = (uint)(local_434 != 0);
      iVar3 = 0;
      if (0 < local_438) {
        do {
          iVar1 = local_430[iVar3];
          if (iVar1 - 8000U < 0xe) {
            local_20 = local_20 | 2;
          }
          else if (iVar1 == 0x5622) {
            local_20 = local_20 | 0x10;
          }
          else if (iVar1 < 0x5623) {
            if (iVar1 == 0x2b11) {
              local_20 = local_20 | 4;
            }
            else if (iVar1 == 16000) {
              local_20 = local_20 | 8;
            }
          }
          else if (iVar1 == 0xac44) {
            local_20 = local_20 | 0x40;
          }
          else if (iVar1 < 0xac45) {
            if (iVar1 == 32000) {
              local_20 = local_20 | 0x20;
            }
          }
          else if (iVar1 == 48000) {
            local_20 = local_20 | 0x80;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < local_438);
      }
      __NXAudioGetDataEncodings(uVar2,local_430,&local_438);
      local_2c = 0;
      iVar3 = 0;
      if (0 < local_438) {
        do {
          iVar1 = local_430[iVar3];
          if (iVar1 == 0x259) {
            local_2c = local_2c | 2;
          }
          else if (iVar1 < 0x25a) {
            if (iVar1 == 600) {
              local_2c = local_2c | 4;
            }
          }
          else if (iVar1 == 0x25a) {
            local_2c = local_2c | 1;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < local_438);
      }
LAB_001bd0f9:
      local_440 = &local_30;
      __NXAudioGetChannelCountLimit(uVar2,local_440);
      _audio_snd_reply_ret_formats
                (param_2,*(undefined4 *)(param_1 + 0x10),local_20,local_24,local_28,local_2c,
                 local_30);
      return 0;
    }
    break;
  case 0x74:
    if (*(int *)(param_1 + 4) == 0x18) {
      uVar2 = _objc_msgSend(PTR_s_IOAudio_001f9dbc,PTR_s__inputChannelForSndPort__001f9698,
                            *(undefined4 *)(param_1 + 0xc));
      __NXAudioGetSamplingRates(uVar2,&local_434,&local_24,&local_28,local_430,&local_438);
      local_20 = 0;
      if (local_434 != 0) {
        local_20 = 1;
      }
      local_20 = (uint)(local_434 != 0);
      iVar3 = 0;
      if (0 < local_438) {
        do {
          iVar1 = local_430[iVar3];
          if (iVar1 - 8000U < 0xe) {
            local_20 = local_20 | 2;
          }
          else if (iVar1 == 0x5622) {
            local_20 = local_20 | 0x10;
          }
          else if (iVar1 < 0x5623) {
            if (iVar1 == 0x2b11) {
              local_20 = local_20 | 4;
            }
            else if (iVar1 == 16000) {
              local_20 = local_20 | 8;
            }
          }
          else if (iVar1 == 0xac44) {
            local_20 = local_20 | 0x40;
          }
          else if (iVar1 < 0xac45) {
            if (iVar1 == 32000) {
              local_20 = local_20 | 0x20;
            }
          }
          else if (iVar1 == 48000) {
            local_20 = local_20 | 0x80;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < local_438);
      }
      __NXAudioGetDataEncodings(uVar2,local_430,&local_438);
      local_2c = 0;
      iVar3 = 0;
      if (0 < local_438) {
        do {
          iVar1 = local_430[iVar3];
          if (iVar1 == 0x259) {
            local_2c = local_2c | 2;
          }
          else if (iVar1 < 0x25a) {
            if (iVar1 == 600) {
              local_2c = local_2c | 4;
            }
          }
          else if (iVar1 == 0x25a) {
            local_2c = local_2c | 1;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < local_438);
      }
      goto LAB_001bd0f9;
    }
    break;
  default:
    goto switchD_001bcb1b_default;
  }
  local_43c = 0x67;
switchD_001bcb1b_default:
  return local_43c;
}

