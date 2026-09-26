/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001aba38 */

void FUN_001aba38(int param_1)

{
  char cVar1;
  int iVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  undefined4 uStack_1c;
  int iStack_18;
  undefined *puStack_14;
  undefined *puStack_10;
  
  puStack_10 = PTR_s_oper_001f9b28;
  puStack_14 = *(undefined **)(param_1 + 0x154);
  iStack_18 = 0x1aba53;
  iVar2 = _objc_msgSend();
  puVar4 = (undefined *)0x0;
  if (iVar2 == 2) {
    puStack_10 = (undefined *)0x0;
    puStack_14 = PTR_s_resetAndEnable__001f9b24;
    iStack_18 = param_1;
    uStack_1c = 0x1abaa7;
    _objc_msgSend();
    *(byte *)(param_1 + 0x128) = *(byte *)(param_1 + 0x128) & 0xfe;
    ppuVar3 = (undefined **)&uStack_1c;
    uStack_1c = 0;
  }
  else {
    if (2 < iVar2) {
      if (iVar2 != 4) {
        return;
      }
      puStack_10 = (undefined *)0x0;
      puStack_14 = PTR_s_done__001f9b20;
      iStack_18 = *(undefined4 *)(param_1 + 0x154);
      uStack_1c = 0x1abadd;
      _objc_msgSend();
      uStack_1c = 0x1abae2;
      _IOExitThread();
      return;
    }
    if (iVar2 != 1) {
      return;
    }
    if ((*(byte *)(param_1 + 0x128) & 1) == 0) {
      puStack_10 = (undefined *)0x1;
      puStack_14 = PTR_s_resetAndEnable__001f9b24;
      iStack_18 = param_1;
      uStack_1c = 0x1aba88;
      cVar1 = _objc_msgSend();
      if (cVar1 == '\0') {
        puVar4 = (undefined *)0x5;
      }
    }
    ppuVar3 = &puStack_10;
    puStack_10 = puVar4;
  }
  *(undefined **)((int)ppuVar3 + -4) = PTR_s_done__001f9b20;
  *(undefined4 *)((int)ppuVar3 + -8) = *(undefined4 *)(param_1 + 0x154);
  *(undefined4 *)((int)ppuVar3 + -0xc) = 0x1abac3;
  _objc_msgSend();
  return;
}

