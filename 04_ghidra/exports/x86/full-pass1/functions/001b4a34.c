/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b4a34 */

void FUN_001b4a34(undefined *param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined **ppuVar3;
  undefined *puStack_20;
  undefined *puStack_1c;
  undefined *puStack_18;
  undefined *puStack_14;
  undefined *puStack_10;
  
  puStack_10 = PTR_s_command_001f98dc;
  puStack_14 = PTR_s__audioCommand_001f98e0;
  puStack_18 = param_1;
  puStack_1c = (undefined *)0x1b4a50;
  puStack_14 = (undefined *)_objc_msgSend();
  puStack_18 = (undefined *)0x1b4a59;
  uVar2 = _objc_msgSend();
  switch(uVar2) {
  case 0:
    puStack_10 = PTR_s_updateInputGainLeft_001f98d8;
    puStack_14 = param_1;
    puStack_18 = (undefined *)0x1b4af1;
    _objc_msgSend();
    ppuVar3 = &puStack_18;
    puStack_18 = (undefined *)0x1;
    break;
  case 1:
    puStack_10 = PTR_s_updateInputGainRight_001f98d4;
    puStack_14 = param_1;
    puStack_18 = (undefined *)0x1b4b05;
    _objc_msgSend();
    ppuVar3 = &puStack_18;
    puStack_18 = (undefined *)0x1;
    break;
  case 2:
    puStack_10 = PTR_s_updateOutputMute_001f98d0;
    puStack_14 = param_1;
    puStack_18 = (undefined *)0x1b4b19;
    _objc_msgSend();
    ppuVar3 = &puStack_18;
    puStack_18 = (undefined *)0x1;
    break;
  case 3:
    puStack_10 = PTR_s_updateOutputAttenuationLeft_001f98cc;
    puStack_14 = param_1;
    puStack_18 = (undefined *)0x1b4b2d;
    _objc_msgSend();
    ppuVar3 = &puStack_18;
    puStack_18 = (undefined *)0x1;
    break;
  case 4:
    puStack_10 = PTR_s_updateOutputAttenuationRight_001f98c8;
    puStack_14 = param_1;
    puStack_18 = (undefined *)0x1b4b41;
    _objc_msgSend();
    ppuVar3 = &puStack_18;
    puStack_18 = (undefined *)0x1;
    break;
  case 5:
    puStack_10 = PTR_s_updateLoudnessEnhanced_001f98c4;
    puStack_14 = param_1;
    puStack_18 = (undefined *)0x1b4b55;
    _objc_msgSend();
    ppuVar3 = &puStack_18;
    puStack_18 = (undefined *)0x1;
    break;
  case 6:
    puStack_10 = PTR_s_isInputActive_001f98f8;
    puStack_14 = param_1;
    puStack_18 = (undefined *)0x1b4b69;
    cVar1 = _objc_msgSend();
    if (cVar1 != '\0') {
      puStack_10 = PTR_s__inputChannel_001f9908;
      puStack_14 = param_1;
      puStack_18 = (undefined *)0x1b4b7d;
      puStack_18 = (undefined *)_objc_msgSend();
      puStack_1c = PTR_s__stopDMAForChannel__001f98c0;
      puStack_20 = param_1;
      _objc_msgSend();
    }
    ppuVar3 = &puStack_10;
    puStack_10 = (undefined *)0x1;
    break;
  case 7:
    puStack_10 = PTR_s_isOutputActive_001f98f4;
    puStack_14 = param_1;
    puStack_18 = (undefined *)0x1b4ba1;
    cVar1 = _objc_msgSend();
    if (cVar1 != '\0') {
      puStack_10 = PTR_s__outputChannel_001f9900;
      puStack_14 = param_1;
      puStack_18 = (undefined *)0x1b4bb5;
      puStack_18 = (undefined *)_objc_msgSend();
      puStack_1c = PTR_s__stopDMAForChannel__001f98c0;
      puStack_20 = param_1;
      _objc_msgSend();
    }
    ppuVar3 = &puStack_10;
    puStack_10 = (undefined *)0x1;
    break;
  case 8:
    puStack_10 = (undefined *)0x1;
    puStack_14 = (undefined *)0x1e;
    puStack_18 = PTR_s_setInput_enable__001f98bc;
    puStack_1c = param_1;
    puStack_20 = (undefined *)0x1b4bdd;
    _objc_msgSend();
    ppuVar3 = &puStack_20;
    puStack_20 = (undefined *)0x1;
    break;
  case 9:
    puStack_10 = (undefined *)0x0;
    puStack_14 = (undefined *)0x1e;
    puStack_18 = PTR_s_setInput_enable__001f98bc;
    puStack_1c = param_1;
    puStack_20 = (undefined *)0x1b4bf5;
    _objc_msgSend();
    ppuVar3 = &puStack_20;
    puStack_20 = (undefined *)0x1;
    break;
  case 10:
    puStack_10 = (undefined *)0x1;
    puStack_14 = (undefined *)0x1f;
    puStack_18 = PTR_s_setInput_enable__001f98bc;
    puStack_1c = param_1;
    puStack_20 = (undefined *)0x1b4c0d;
    _objc_msgSend();
    ppuVar3 = &puStack_20;
    puStack_20 = (undefined *)0x1;
    break;
  case 0xb:
    puStack_10 = (undefined *)0x0;
    puStack_14 = (undefined *)0x1f;
    puStack_18 = PTR_s_setInput_enable__001f98bc;
    puStack_1c = param_1;
    puStack_20 = (undefined *)0x1b4c25;
    _objc_msgSend();
    ppuVar3 = &puStack_20;
    puStack_20 = (undefined *)0x1;
    break;
  case 0xc:
    puStack_10 = (undefined *)0x1;
    puStack_14 = (undefined *)0x20;
    puStack_18 = PTR_s_setInput_enable__001f98bc;
    puStack_1c = param_1;
    puStack_20 = (undefined *)0x1b4c3d;
    _objc_msgSend();
    ppuVar3 = &puStack_20;
    puStack_20 = (undefined *)0x1;
    break;
  case 0xd:
    puStack_10 = (undefined *)0x0;
    puStack_14 = (undefined *)0x20;
    puStack_18 = PTR_s_setInput_enable__001f98bc;
    puStack_1c = param_1;
    puStack_20 = (undefined *)0x1b4c55;
    _objc_msgSend();
    ppuVar3 = &puStack_20;
    puStack_20 = (undefined *)0x1;
    break;
  case 0xe:
    puStack_10 = (undefined *)0x1;
    puStack_14 = (undefined *)0x21;
    puStack_18 = PTR_s_setInput_enable__001f98bc;
    puStack_1c = param_1;
    puStack_20 = (undefined *)0x1b4c6d;
    _objc_msgSend();
    ppuVar3 = &puStack_20;
    puStack_20 = (undefined *)0x1;
    break;
  case 0xf:
    puStack_10 = (undefined *)0x0;
    puStack_14 = (undefined *)0x21;
    puStack_18 = PTR_s_setInput_enable__001f98bc;
    puStack_1c = param_1;
    puStack_20 = (undefined *)0x1b4c85;
    _objc_msgSend();
    ppuVar3 = &puStack_20;
    puStack_20 = (undefined *)0x1;
    break;
  case 0x10:
    puStack_10 = (undefined *)0x1;
    puStack_14 = (undefined *)0x22;
    puStack_18 = PTR_s_setInput_enable__001f98bc;
    puStack_1c = param_1;
    puStack_20 = (undefined *)0x1b4c9d;
    _objc_msgSend();
    ppuVar3 = &puStack_20;
    puStack_20 = (undefined *)0x1;
    break;
  case 0x11:
    puStack_10 = (undefined *)0x0;
    puStack_14 = (undefined *)0x22;
    puStack_18 = PTR_s_setInput_enable__001f98bc;
    puStack_1c = param_1;
    puStack_20 = (undefined *)0x1b4cb5;
    _objc_msgSend();
    ppuVar3 = &puStack_20;
    puStack_20 = (undefined *)0x1;
    break;
  case 0x12:
    puStack_10 = (undefined *)0x1;
    puStack_14 = (undefined *)0x19;
    puStack_18 = PTR_s_setOutput_enable__001f98b8;
    puStack_1c = param_1;
    puStack_20 = (undefined *)0x1b4ccd;
    _objc_msgSend();
    ppuVar3 = &puStack_20;
    puStack_20 = (undefined *)0x1;
    break;
  case 0x13:
    puStack_10 = (undefined *)0x0;
    puStack_14 = (undefined *)0x19;
    puStack_18 = PTR_s_setOutput_enable__001f98b8;
    puStack_1c = param_1;
    puStack_20 = (undefined *)0x1b4ce5;
    _objc_msgSend();
    ppuVar3 = &puStack_20;
    puStack_20 = (undefined *)0x1;
    break;
  case 0x14:
    puStack_10 = (undefined *)0x1;
    puStack_14 = (undefined *)0x1a;
    puStack_18 = PTR_s_setOutput_enable__001f98b8;
    puStack_1c = param_1;
    puStack_20 = (undefined *)0x1b4cfd;
    _objc_msgSend();
    ppuVar3 = &puStack_20;
    puStack_20 = (undefined *)0x1;
    break;
  case 0x15:
    puStack_10 = (undefined *)0x0;
    puStack_14 = (undefined *)0x1a;
    puStack_18 = PTR_s_setOutput_enable__001f98b8;
    puStack_1c = param_1;
    puStack_20 = (undefined *)0x1b4d15;
    _objc_msgSend();
    ppuVar3 = &puStack_20;
    puStack_20 = (undefined *)0x1;
    break;
  case 0x16:
    puStack_10 = (undefined *)0x1;
    puStack_14 = (undefined *)0x1b;
    puStack_18 = PTR_s_setOutput_enable__001f98b8;
    puStack_1c = param_1;
    puStack_20 = (undefined *)0x1b4d29;
    _objc_msgSend();
    ppuVar3 = &puStack_20;
    puStack_20 = (undefined *)0x1;
    break;
  case 0x17:
    puStack_10 = (undefined *)0x0;
    puStack_14 = (undefined *)0x1b;
    puStack_18 = PTR_s_setOutput_enable__001f98b8;
    puStack_1c = param_1;
    puStack_20 = (undefined *)0x1b4d3d;
    _objc_msgSend();
    ppuVar3 = &puStack_20;
    puStack_20 = (undefined *)0x1;
    break;
  case 0x18:
    puStack_10 = (undefined *)0x1;
    puStack_14 = (undefined *)0x1c;
    puStack_18 = PTR_s_setOutput_enable__001f98b8;
    puStack_1c = param_1;
    puStack_20 = (undefined *)0x1b4d51;
    _objc_msgSend();
    ppuVar3 = &puStack_20;
    puStack_20 = (undefined *)0x1;
    break;
  case 0x19:
    puStack_10 = (undefined *)0x0;
    puStack_14 = (undefined *)0x1c;
    puStack_18 = PTR_s_setOutput_enable__001f98b8;
    puStack_1c = param_1;
    puStack_20 = (undefined *)0x1b4d65;
    _objc_msgSend();
    ppuVar3 = &puStack_20;
    puStack_20 = (undefined *)0x1;
    break;
  case 0x1a:
    puStack_10 = (undefined *)0x1;
    puStack_14 = (undefined *)0x1d;
    puStack_18 = PTR_s_setOutput_enable__001f98b8;
    puStack_1c = param_1;
    puStack_20 = (undefined *)0x1b4d79;
    _objc_msgSend();
    ppuVar3 = &puStack_20;
    puStack_20 = (undefined *)0x1;
    break;
  case 0x1b:
    puStack_10 = (undefined *)0x0;
    puStack_14 = (undefined *)0x1d;
    puStack_18 = PTR_s_setOutput_enable__001f98b8;
    puStack_1c = param_1;
    puStack_20 = (undefined *)0x1b4d8d;
    _objc_msgSend();
    ppuVar3 = &puStack_20;
    puStack_20 = (undefined *)0x1;
    break;
  default:
    ppuVar3 = &puStack_10;
    puStack_10 = (undefined *)0x1;
  }
  *(undefined **)((int)ppuVar3 + -4) = PTR_s_done__001f9b20;
  *(undefined **)((int)ppuVar3 + -8) = PTR_s__audioCommand_001f98e0;
  *(undefined **)((int)ppuVar3 + -0xc) = param_1;
  *(undefined4 *)((int)ppuVar3 + -0x10) = 0x1b4da6;
  uVar2 = _objc_msgSend();
  *(undefined4 *)((int)ppuVar3 + -8) = uVar2;
  *(undefined4 *)((int)ppuVar3 + -0xc) = 0x1b4daf;
  _objc_msgSend();
  return;
}

