/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c7f58 */

void FUN_001c7f58(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_24;
  undefined4 local_20;
  
  if (*(char *)(param_1 + 0x250) != '\0') {
    uVar1 = _objc_msgSend(param_1,PTR_s_name_001f9228);
    _IOLog("%s: Initializing video mode.\n",uVar1);
  }
  iVar2 = _objc_msgSend(param_1,PTR_s_runVPCode_withRegs__001f9590,1,0);
  if (iVar2 == 0) {
    uVar1 = _objc_msgSend(param_1,PTR_s_name_001f9228);
    _IOLog("%s: Failed to initialize mode.\n",uVar1);
  }
  else {
    _objc_msgSend(param_1,PTR_s_setGammaTable_001f9588);
    if (*(char *)(param_1 + 0x250) != '\0') {
      uVar1 = _objc_msgSend(param_1,PTR_s_name_001f9228,*(undefined4 *)(param_1 + 0x248));
      _IOLog("%s: Enabling linear framebuffer: 0x%08x\n",uVar1);
    }
    local_24 = *(undefined4 *)(param_1 + 0x248);
    local_20 = *(undefined4 *)(param_1 + 0x24c);
    iVar2 = _objc_msgSend(param_1,PTR_s_runVPCode_withRegs__001f9590,2,&local_24);
    if (iVar2 != 0) {
      iVar2 = _objc_msgSend(param_1,PTR_s_displayInfo_001f9610);
      _memset(*(void **)(iVar2 + 0x14),0,*(int *)(iVar2 + 0xc) * *(int *)(iVar2 + 4));
    }
  }
  return;
}

