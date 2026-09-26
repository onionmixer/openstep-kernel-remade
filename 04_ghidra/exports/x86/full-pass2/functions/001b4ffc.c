/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b4ffc */

uint FUN_001b4ffc(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined *puVar6;
  
  uVar5 = 0;
  uVar2 = _objc_msgSend(param_1,PTR_s__inputChannel_001f9908);
  cVar1 = _objc_msgSend(param_4,PTR_s_isEqual__001f9838,uVar2);
  if (cVar1 == '\0') {
    uVar2 = _objc_msgSend(param_1,PTR_s__outputChannel_001f9900);
    cVar1 = _objc_msgSend(param_4,PTR_s_isEqual__001f9838,uVar2);
    if (cVar1 == '\0') {
      uVar2 = _objc_msgSend(PTR_s_InputStream_001f9dc4,PTR_s_class_001f9234);
      cVar1 = _objc_msgSend(param_4,PTR_s_isKindOf__001f9260,uVar2);
      if (cVar1 == '\0') {
        uVar2 = _objc_msgSend(PTR_s_OutputStream_001f9dc0,PTR_s_class_001f9234);
        cVar1 = _objc_msgSend(param_4,PTR_s_isKindOf__001f9260,uVar2);
        if (cVar1 == '\0') {
          _IOLog("Audio: unknown parameter object\n");
          return 0;
        }
        switch(param_3) {
        case 400:
          param_1 = param_4;
          puVar6 = PTR_s_dataEncoding_001f9828;
          break;
        case 0x191:
          param_1 = param_4;
          puVar6 = PTR_s_samplingRate_001f9824;
          break;
        case 0x192:
          param_1 = param_4;
          puVar6 = PTR_s_channelCount_001f98b0;
          break;
        case 0x193:
          param_1 = param_4;
          puVar6 = PTR_s_highWaterMark_001f9820;
          break;
        case 0x194:
          param_1 = param_4;
          puVar6 = PTR_s_lowWaterMark_001f981c;
          break;
        default:
          return 0;
        case 0x196:
          return 0x25f;
        case 0x197:
          goto switchD_001b503d_caseD_2;
        case 0x198:
          iVar3 = _objc_msgSend(param_4,PTR_s_gainLeft_001f9818);
          param_1 = param_4;
          puVar6 = PTR_s_gainRight_001f9814;
          goto LAB_001b5483;
        case 0x199:
          param_1 = param_4;
          puVar6 = PTR_s_gainLeft_001f9818;
          break;
        case 0x19a:
          param_1 = param_4;
          puVar6 = PTR_s_gainRight_001f9814;
        }
      }
      else {
        switch(param_3) {
        case 400:
          param_1 = param_4;
          puVar6 = PTR_s_dataEncoding_001f9828;
          break;
        case 0x191:
          param_1 = param_4;
          puVar6 = PTR_s_samplingRate_001f9824;
          break;
        case 0x192:
          param_1 = param_4;
          puVar6 = PTR_s_channelCount_001f98b0;
          break;
        case 0x193:
          param_1 = param_4;
          puVar6 = PTR_s_highWaterMark_001f9820;
          break;
        case 0x194:
          param_1 = param_4;
          puVar6 = PTR_s_lowWaterMark_001f981c;
          break;
        case 0x195:
          return 0x25d;
        default:
          return 0;
        }
      }
      goto LAB_001b54a0;
    }
    switch(param_3) {
    case 0:
      param_1 = param_4;
      puVar6 = PTR_s_descriptorSize_001f988c;
      break;
    case 1:
      param_1 = param_4;
      puVar6 = PTR_s_dmaCount_001f98ac;
      break;
    case 2:
      goto switchD_001b503d_caseD_2;
    case 3:
    case 4:
    case 5:
    case 6:
      return 0;
    case 7:
    case 8:
    case 9:
      param_4 = param_1;
      puVar6 = PTR_s_isOutputMuted_001f9864;
      goto LAB_001b5460;
    case 10:
      param_4 = param_1;
      puVar6 = PTR_s_isLoudnessEnhanced_001f982c;
LAB_001b5460:
      cVar1 = _objc_msgSend(param_4,puVar6);
      return (int)cVar1;
    case 0xb:
      iVar3 = _objc_msgSend(param_1,PTR_s_outputAttenuationLeft_001f985c);
      iVar4 = _objc_msgSend(param_1,PTR_s_outputAttenuationRight_001f9858);
      return (iVar4 + iVar3) / 2;
    case 0xc:
      puVar6 = PTR_s_outputAttenuationLeft_001f985c;
      break;
    case 0xd:
      puVar6 = PTR_s_outputAttenuationRight_001f9858;
      break;
    default:
      return 0;
    case 0x19:
      return (int)*(char *)(*(int *)(param_1 + 0x174) + 0x16);
    case 0x1a:
      return (int)*(char *)(*(int *)(param_1 + 0x174) + 0x15);
    case 0x1b:
      return (int)*(char *)(*(int *)(param_1 + 0x174) + 0x17);
    case 0x1c:
      return (int)*(char *)(*(int *)(param_1 + 0x174) + 0x18);
    case 0x1d:
      return (int)*(char *)(*(int *)(param_1 + 0x174) + 0x19);
    }
    goto LAB_001b54a0;
  }
  switch(param_3) {
  case 0:
    param_1 = param_4;
    puVar6 = PTR_s_descriptorSize_001f988c;
    goto LAB_001b54a0;
  case 1:
    param_1 = param_4;
    puVar6 = PTR_s_dmaCount_001f98ac;
    goto LAB_001b54a0;
  case 2:
switchD_001b503d_caseD_2:
    puVar6 = PTR_s_isDetectingPeaks_001f9834;
    goto LAB_001b5460;
  case 0xe:
    puVar6 = PTR_s__analogInputSource_001f9830;
    goto LAB_001b54a0;
  case 0x10:
    iVar3 = _objc_msgSend(param_1,PTR_s_inputGainLeft_001f984c);
    puVar6 = PTR_s_inputGainRight_001f9848;
LAB_001b5483:
    iVar4 = _objc_msgSend(param_1,puVar6);
    uVar5 = (uint)(iVar4 + iVar3) >> 1;
    break;
  case 0x11:
    puVar6 = PTR_s_inputGainLeft_001f984c;
    goto LAB_001b54a0;
  case 0x12:
    puVar6 = PTR_s_inputGainRight_001f9848;
LAB_001b54a0:
    uVar5 = _objc_msgSend(param_1,puVar6);
    break;
  case 0x1e:
    uVar5 = (uint)*(char *)(*(int *)(param_1 + 0x174) + 0x10);
    break;
  case 0x1f:
    uVar5 = (uint)*(char *)(*(int *)(param_1 + 0x174) + 0x11);
    break;
  case 0x20:
    uVar5 = (uint)*(char *)(*(int *)(param_1 + 0x174) + 0x12);
    break;
  case 0x21:
    uVar5 = (uint)*(char *)(*(int *)(param_1 + 0x174) + 0x13);
    break;
  case 0x22:
    uVar5 = (uint)*(char *)(*(int *)(param_1 + 0x174) + 0x14);
  }
  return uVar5;
}

