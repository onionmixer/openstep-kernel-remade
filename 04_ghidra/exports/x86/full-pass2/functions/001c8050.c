/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c8050 */

void FUN_001c8050(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int local_c;
  undefined *local_8;
  
  if (*(char *)(param_1 + 0x250) != '\0') {
    uVar1 = _objc_msgSend(param_1,PTR_s_name_001f9228);
    _IOLog("%s: Resetting VGA parameters.\n",uVar1);
  }
  iVar2 = _objc_msgSend(param_1,PTR_s_runVPCode_withRegs__001f9590,3,0);
  if (iVar2 != 0) {
    local_c = param_1;
    local_8 = PTR_s_IOFrameBufferDisplay_001fa658;
    _objc_msgSendSuper(&local_c,PTR_s_revertToVGAMode_001f94a8);
  }
  return;
}

