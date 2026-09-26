/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001bb418 */

undefined4 __NXAudioGetExclusiveUser(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0xca;
  }
  else {
    uVar1 = _objc_msgSend(param_1,PTR_s_exclusiveUser_001f9910);
    *param_2 = uVar1;
    uVar1 = 0;
  }
  return uVar1;
}

