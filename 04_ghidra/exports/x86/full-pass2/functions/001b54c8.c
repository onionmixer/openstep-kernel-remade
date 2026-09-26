/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b54c8 */

undefined1
FUN_001b54c8(char *param_1,undefined4 param_2,undefined4 param_3,char *param_4,char *param_5)

{
  char cVar1;
  undefined *puVar2;
  char cVar3;
  char **ppcVar4;
  char **ppcVar5;
  char **ppcVar6;
  char **ppcVar7;
  char *pcStack_24;
  char *pcStack_20;
  char *pcStack_1c;
  char *pcStack_18;
  
  pcStack_18 = PTR_s__inputChannel_001f9908;
  pcStack_1c = param_1;
  pcStack_20 = (char *)0x1b54eb;
  pcStack_20 = (char *)_objc_msgSend();
  pcStack_24 = PTR_s_isEqual__001f9838;
  cVar1 = _objc_msgSend(param_5);
  cVar3 = (char)param_4;
  if (cVar1 == '\0') {
    pcStack_18 = PTR_s__outputChannel_001f9900;
    pcStack_1c = param_1;
    pcStack_20 = (char *)0x1b5615;
    pcStack_20 = (char *)_objc_msgSend();
    pcStack_24 = PTR_s_isEqual__001f9838;
    cVar1 = _objc_msgSend(param_5);
    ppcVar4 = (char **)&stack0xffffffec;
    if (cVar1 == '\0') {
      pcStack_18 = PTR_s_class_001f9234;
      pcStack_1c = PTR_s_InputStream_001f9dc4;
      pcStack_20 = (char *)0x1b5743;
      pcStack_20 = (char *)_objc_msgSend();
      pcStack_24 = PTR_s_isKindOf__001f9260;
      cVar1 = _objc_msgSend(param_5);
      if (cVar1 == '\0') {
        pcStack_18 = PTR_s_class_001f9234;
        pcStack_1c = PTR_s_OutputStream_001f9dc0;
        pcStack_20 = (char *)0x1b57ef;
        pcStack_20 = (char *)_objc_msgSend();
        pcStack_24 = PTR_s_isKindOf__001f9260;
        cVar1 = _objc_msgSend(param_5);
        ppcVar6 = (char **)&stack0xffffffec;
        if (cVar1 == '\0') {
          pcStack_18 = "Audio: unknown parameter object\n";
          pcStack_1c = (char *)0x1b58d6;
          _IOLog();
          return 0;
        }
        switch(param_3) {
        case 400:
          ppcVar7 = &pcStack_18;
          pcStack_18 = param_4;
          puVar2 = PTR_s_setDataEncoding__001f9800;
          break;
        case 0x191:
          ppcVar7 = &pcStack_18;
          pcStack_18 = param_4;
          puVar2 = PTR_s_setSamplingRate__001f97fc;
          break;
        case 0x192:
          ppcVar7 = &pcStack_18;
          pcStack_18 = param_4;
          puVar2 = PTR_s_setChannelCount__001f97f8;
          break;
        case 0x193:
          ppcVar7 = &pcStack_18;
          pcStack_18 = param_4;
          puVar2 = PTR_s_setHighWaterMark__001f97f4;
          break;
        case 0x194:
          ppcVar7 = &pcStack_18;
          pcStack_18 = param_4;
          puVar2 = PTR_s_setLowWaterMark__001f97f0;
          break;
        default:
          goto switchD_001b5511_caseD_3;
        case 0x196:
          if (param_4 != (char *)0x25f) {
            return 0;
          }
          return 1;
        case 0x197:
          pcStack_18 = (char *)(int)cVar3;
          ppcVar7 = &pcStack_18;
          puVar2 = PTR_s_setDetectPeaks__001f9810;
          break;
        case 0x198:
          pcStack_18 = param_4;
          pcStack_1c = PTR_s_setGainLeft__001f97ec;
          ppcVar6 = &pcStack_20;
          pcStack_20 = param_5;
          pcStack_24 = (char *)0x1b58ae;
          _objc_msgSend();
        case 0x19a:
          ppcVar7 = (char **)((int)ppcVar6 + -4);
          *(char **)((int)ppcVar6 + -4) = param_4;
          puVar2 = PTR_s_setGainRight__001f97e8;
          break;
        case 0x199:
          ppcVar7 = &pcStack_18;
          pcStack_18 = param_4;
          puVar2 = PTR_s_setGainLeft__001f97ec;
        }
      }
      else {
        switch(param_3) {
        case 400:
          ppcVar7 = &pcStack_18;
          pcStack_18 = param_4;
          puVar2 = PTR_s_setDataEncoding__001f9800;
          break;
        case 0x191:
          ppcVar7 = &pcStack_18;
          pcStack_18 = param_4;
          puVar2 = PTR_s_setSamplingRate__001f97fc;
          break;
        case 0x192:
          ppcVar7 = &pcStack_18;
          pcStack_18 = param_4;
          puVar2 = PTR_s_setChannelCount__001f97f8;
          break;
        case 0x193:
          ppcVar7 = &pcStack_18;
          pcStack_18 = param_4;
          puVar2 = PTR_s_setHighWaterMark__001f97f4;
          break;
        case 0x194:
          ppcVar7 = &pcStack_18;
          pcStack_18 = param_4;
          puVar2 = PTR_s_setLowWaterMark__001f97f0;
          break;
        case 0x195:
          if (param_4 == (char *)0x25d) {
            return 1;
          }
        default:
switchD_001b5511_caseD_3:
          return 0;
        }
      }
LAB_001b58c3:
      *(undefined **)((int)ppcVar7 + -4) = puVar2;
      *(char **)((int)ppcVar7 + -8) = param_5;
      *(undefined4 *)((int)ppcVar7 + -0xc) = 0x1b58ca;
      _objc_msgSend();
    }
    else {
      switch(param_3) {
      case 0:
      case 1:
      case 3:
      case 4:
      case 5:
      case 6:
        goto switchD_001b5511_caseD_0;
      case 2:
        pcStack_18 = (char *)(int)cVar3;
        ppcVar7 = &pcStack_18;
        puVar2 = PTR_s_setDetectPeaks__001f9810;
        goto LAB_001b58c3;
      case 7:
      case 8:
      case 9:
        pcStack_18 = (char *)(int)cVar3;
        ppcVar5 = &pcStack_18;
        puVar2 = PTR_s__setOutputMute__001f9860;
        break;
      case 10:
        pcStack_18 = (char *)(int)cVar3;
        ppcVar5 = &pcStack_18;
        puVar2 = PTR_s__setLoudnessEnhanced__001f9808;
        break;
      case 0xb:
        pcStack_18 = param_4;
        pcStack_1c = PTR_s__setOutputAttenuationLeft__001f9854;
        ppcVar4 = &pcStack_20;
        pcStack_20 = param_1;
        pcStack_24 = (char *)0x1b56f2;
        _objc_msgSend();
      case 0xd:
        ppcVar5 = (char **)((int)ppcVar4 + -4);
        *(char **)((int)ppcVar4 + -4) = param_4;
        puVar2 = PTR_s__setOutputAttenuationRight__001f9850;
        break;
      case 0xc:
        ppcVar5 = &pcStack_18;
        pcStack_18 = param_4;
        puVar2 = PTR_s__setOutputAttenuationLeft__001f9854;
        break;
      default:
        goto switchD_001b5511_caseD_3;
      case 0x19:
      case 0x1a:
      case 0x1b:
      case 0x1c:
      case 0x1d:
        pcStack_20 = PTR_s__setOutputFor_to__001f9804;
        goto LAB_001b5722;
      }
LAB_001b5707:
      *(undefined **)((int)ppcVar5 + -4) = puVar2;
      *(char **)((int)ppcVar5 + -8) = param_1;
      *(undefined4 *)((int)ppcVar5 + -0xc) = 0x1b570e;
      _objc_msgSend();
    }
switchD_001b5511_caseD_0:
    return 1;
  }
  switch(param_3) {
  case 0:
  case 1:
    goto switchD_001b5511_caseD_0;
  case 2:
    pcStack_18 = (char *)(int)cVar3;
    ppcVar7 = &pcStack_18;
    puVar2 = PTR_s_setDetectPeaks__001f9810;
    goto LAB_001b58c3;
  default:
    goto switchD_001b5511_caseD_3;
  case 0xe:
    ppcVar5 = &pcStack_18;
    pcStack_18 = param_4;
    puVar2 = PTR_s__setAnalogInputSource__001f980c;
    break;
  case 0x10:
    pcStack_18 = param_4;
    pcStack_1c = PTR_s__setInputGainLeft__001f9844;
    pcStack_20 = param_1;
    pcStack_24 = (char *)0x1b55c2;
    _objc_msgSend();
    ppcVar5 = &pcStack_24;
    pcStack_24 = param_4;
    puVar2 = PTR_s__setInputGainRight__001f9840;
    break;
  case 0x11:
    ppcVar5 = &pcStack_18;
    pcStack_18 = param_4;
    puVar2 = PTR_s__setInputGainLeft__001f9844;
    break;
  case 0x12:
    ppcVar5 = &pcStack_18;
    pcStack_18 = param_4;
    puVar2 = PTR_s__setInputGainRight__001f9840;
    break;
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x22:
    pcStack_20 = PTR_s__setInputFor_to__001f983c;
LAB_001b5722:
    pcStack_18 = (char *)(int)cVar3;
    pcStack_1c = (char *)param_3;
    pcStack_24 = param_1;
    _objc_msgSend();
    return 1;
  }
  goto LAB_001b5707;
}

