/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001acb04 */

undefined4
FUN_001acb04(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)_objc_msgSend(param_1,PTR_s_allocSdBuf__001f9ac0,0);
  *puVar1 = 3;
  puVar1[5] = param_3;
  puVar1[3] = param_4;
  puVar1[4] = param_5;
  puVar1[6] = 0;
  *(byte *)(puVar1 + 8) = *(byte *)(puVar1 + 8) & 0xfe;
  uVar2 = _objc_msgSend(param_1,PTR_s_enqueueSdBuf__001f9abc,puVar1);
  _objc_msgSend(param_1,PTR_s_freeSdBuf__001f9ab8,puVar1);
  return uVar2;
}

