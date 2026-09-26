/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001aa93c */

void FUN_001aa93c(undefined *param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined **ppuVar3;
  undefined4 uVar4;
  undefined *puStack_20;
  undefined *puStack_1c;
  undefined *puStack_18;
  undefined *puStack_14;
  undefined *puStack_10;
  
  puStack_10 = PTR_s_oper_001f9b28;
  puStack_14 = *(undefined **)(param_1 + 300);
  puStack_18 = (undefined *)0x1aa957;
  uVar2 = _objc_msgSend();
  uVar4 = 0;
  switch(uVar2) {
  case 1:
    ppuVar3 = (undefined **)&stack0xfffffff4;
    if (param_1[0x128] == '\0') {
      puStack_10 = (undefined *)0x1;
      puStack_14 = PTR_s_resetAndEnable__001f9b24;
      puStack_18 = param_1;
      puStack_1c = (undefined *)0x1aa9ac;
      cVar1 = _objc_msgSend();
      ppuVar3 = (undefined **)&stack0xfffffff4;
      if (cVar1 == '\0') {
        uVar4 = 5;
        ppuVar3 = (undefined **)&stack0xfffffff4;
      }
    }
    break;
  case 2:
    puStack_10 = (undefined *)0x0;
    puStack_14 = PTR_s_resetAndEnable__001f9b24;
    puStack_18 = param_1;
    puStack_1c = (undefined *)0x1aa9d3;
    _objc_msgSend();
    ppuVar3 = &puStack_18;
    break;
  default:
    goto switchD_001aa966_caseD_3;
  case 4:
    puStack_10 = (undefined *)0x0;
    puStack_14 = PTR_s_done__001f9b20;
    puStack_18 = *(undefined **)(param_1 + 300);
    puStack_1c = (undefined *)0x1aa9ec;
    _objc_msgSend();
    puStack_1c = (undefined *)0x1aa9f1;
    _IOExitThread();
    return;
  case 5:
    puStack_10 = PTR_s_enablePromiscuousMode_001f9b1c;
    puStack_14 = param_1;
    puStack_18 = (undefined *)0x1aaa05;
    cVar1 = _objc_msgSend();
    if (cVar1 == '\0') {
      param_1[0x129] = 0;
      uVar4 = 1;
      ppuVar3 = (undefined **)&stack0xfffffff4;
    }
    else {
      param_1[0x129] = 1;
      ppuVar3 = (undefined **)&stack0xfffffff4;
    }
    break;
  case 6:
    puStack_10 = PTR_s_disablePromiscuousMode_001f9b18;
    puStack_14 = param_1;
    puStack_18 = (undefined *)0x1aaa35;
    _objc_msgSend();
    param_1[0x129] = 0;
    ppuVar3 = &puStack_14;
    break;
  case 7:
    puStack_10 = param_1 + 0x13c;
    puStack_14 = PTR_s_addMulticastAddress__001f9b14;
    puStack_18 = param_1;
    puStack_1c = (undefined *)0x1aaa54;
    _objc_msgSend();
    puStack_1c = PTR_s_enableMulticastMode_001f9b10;
    puStack_20 = param_1;
    _objc_msgSend();
    ppuVar3 = &puStack_20;
    break;
  case 8:
    puStack_10 = param_1 + 0x13c;
    puStack_14 = PTR_s_removeMulticastAddress__001f9b0c;
    puStack_18 = param_1;
    puStack_1c = (undefined *)0x1aaa78;
    _objc_msgSend();
    ppuVar3 = (undefined **)&stack0xfffffff4;
    if (*(undefined **)(param_1 + 0x144) == param_1 + 0x144) {
      puStack_10 = PTR_s_disableMulticastMode_001f9b08;
      puStack_14 = param_1;
      puStack_18 = (undefined *)0x1aaa96;
      _objc_msgSend();
      ppuVar3 = (undefined **)&stack0xfffffff4;
    }
  }
  *(undefined4 *)((int)ppuVar3 + -4) = uVar4;
  *(undefined **)((int)ppuVar3 + -8) = PTR_s_done__001f9b20;
  *(undefined4 *)((int)ppuVar3 + -0xc) = *(undefined4 *)(param_1 + 300);
  *(undefined4 *)((int)ppuVar3 + -0x10) = 0x1aaaad;
  _objc_msgSend();
switchD_001aa966_caseD_3:
  return;
}

