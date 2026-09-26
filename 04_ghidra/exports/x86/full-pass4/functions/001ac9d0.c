/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ac9d0 */

undefined4 FUN_001ac9d0(undefined4 param_1,undefined4 param_2,char param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  iVar1 = _objc_msgSend(param_1,PTR_s_lastReadyState_001f9c70);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else if (param_3 == '\0') {
    uVar2 = 0xfffffbb2;
  }
  else {
    puVar3 = (undefined4 *)_objc_msgSend(param_1,PTR_s_allocSdBuf__001f9ac0,0);
    *puVar3 = 6;
    *(byte *)(puVar3 + 8) = *(byte *)(puVar3 + 8) | 1;
    uVar2 = _objc_msgSend(param_1,PTR_s_enqueueSdBuf__001f9abc,puVar3);
    _objc_msgSend(param_1,PTR_s_freeSdBuf__001f9ab8,puVar3);
  }
  return uVar2;
}

