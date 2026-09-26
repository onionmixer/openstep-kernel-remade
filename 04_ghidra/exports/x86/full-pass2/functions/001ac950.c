/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ac950 */

void FUN_001ac950(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_objc_msgSend(param_1,PTR_s_allocSdBuf__001f9ac0,0);
  *puVar1 = 5;
  *(byte *)(puVar1 + 8) = *(byte *)(puVar1 + 8) & 0xfe;
  _objc_msgSend(param_1,PTR_s_enqueueSdBuf__001f9abc,puVar1);
  _objc_msgSend(param_1,PTR_s_freeSdBuf__001f9ab8,puVar1);
  return;
}

