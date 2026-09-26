/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b66a8 */

void FUN_001b66a8(undefined *param_1,undefined4 param_2,int param_3,int param_4,uint param_5)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined **ppuVar7;
  undefined *puStack_2c;
  undefined *puStack_28;
  undefined *puStack_24;
  undefined *puStack_20;
  
  bVar2 = false;
  bVar3 = false;
  bVar1 = false;
  if (param_4 == 10) {
    if (param_3 == 0) {
      if ((param_5 & 0x100000) == 0) {
        bVar2 = true;
      }
    }
    else if (param_3 == 1) {
      if ((param_5 & 0x100000) == 0) {
        bVar3 = true;
      }
      else {
        bVar1 = true;
      }
    }
    if ((param_5 & 0x20000) == 0) {
      if (bVar1) {
        puStack_20 = PTR_s_isOutputMuted_001f9864;
        puStack_24 = param_1;
        puStack_28 = (undefined *)0x1b6710;
        cVar4 = _objc_msgSend();
        puStack_20 = (undefined *)(uint)(cVar4 == '\0');
        ppuVar7 = &puStack_20;
        puVar5 = PTR_s__setOutputMute__001f9860;
      }
      else {
        puStack_20 = PTR_s_outputAttenuationLeft_001f985c;
        puStack_24 = param_1;
        puStack_28 = (undefined *)0x1b6739;
        puVar5 = (undefined *)_objc_msgSend();
        puStack_28 = PTR_s_outputAttenuationRight_001f9858;
        puStack_2c = param_1;
        puVar6 = (undefined *)_objc_msgSend();
        if (bVar2) {
          puVar5 = puVar5 + 1;
          if (0 < (int)puVar5) {
            puVar5 = (undefined *)0x0;
          }
          puVar6 = puVar6 + 1;
          if (0 < (int)puVar6) {
            puVar6 = (undefined *)0x0;
          }
        }
        else if (bVar3) {
          puVar5 = puVar5 + -1;
          if ((int)puVar5 < -0x54) {
            puVar5 = (undefined *)0xffffffac;
          }
          puVar6 = puVar6 + -1;
          if ((int)puVar6 < -0x54) {
            puVar6 = (undefined *)0xffffffac;
          }
        }
        puStack_24 = PTR_s__setOutputAttenuationLeft__001f9854;
        puStack_28 = param_1;
        puStack_2c = (undefined *)0x1b6791;
        puStack_20 = puVar5;
        _objc_msgSend();
        ppuVar7 = &puStack_2c;
        puVar5 = PTR_s__setOutputAttenuationRight__001f9850;
        puStack_2c = puVar6;
      }
    }
    else {
      puStack_20 = PTR_s_inputGainLeft_001f984c;
      puStack_24 = param_1;
      puStack_28 = (undefined *)0x1b67ad;
      puVar5 = (undefined *)_objc_msgSend();
      puStack_28 = PTR_s_inputGainRight_001f9848;
      puStack_2c = param_1;
      puVar6 = (undefined *)_objc_msgSend();
      if (bVar2) {
        puVar5 = puVar5 + 0x666;
        if (0x7fff < (int)puVar5) {
          puVar5 = (undefined *)0x8000;
        }
        puVar6 = puVar6 + 0x666;
        if (0x7fff < (int)puVar6) {
          puVar6 = (undefined *)0x8000;
        }
      }
      else if (bVar3) {
        puVar5 = puVar5 + -0x666;
        if ((int)puVar5 < 1) {
          puVar5 = (undefined *)0x0;
        }
        puVar6 = puVar6 + -0x666;
        if ((int)puVar6 < 1) {
          puVar6 = (undefined *)0x0;
        }
      }
      puStack_24 = PTR_s__setInputGainLeft__001f9844;
      puStack_28 = param_1;
      puStack_2c = (undefined *)0x1b681a;
      puStack_20 = puVar5;
      _objc_msgSend();
      ppuVar7 = &puStack_2c;
      puVar5 = PTR_s__setInputGainRight__001f9840;
      puStack_2c = puVar6;
    }
    *(undefined **)((int)ppuVar7 + -4) = puVar5;
    *(undefined **)((int)ppuVar7 + -8) = param_1;
    *(undefined4 *)((int)ppuVar7 + -0xc) = 0x1b682b;
    _objc_msgSend();
  }
  return;
}

