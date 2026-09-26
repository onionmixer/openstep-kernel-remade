/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a76a4 */

void FUN_001a76a4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4,
                 undefined2 param_5)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)_IOMalloc(0x18);
  *puVar2 = param_1;
  puVar2[1] = param_2;
  puVar2[2] = param_3;
  *(undefined2 *)(puVar2 + 3) = param_4;
  *(undefined2 *)((int)puVar2 + 0xe) = param_5;
  _objc_msgSend(DAT_001e86e8,PTR_s_lock_001f9220);
  if ((undefined4 **)DAT_001e86e0 == &DAT_001e86e0) {
    DAT_001e86e0 = puVar2;
    DAT_001e86e4 = puVar2;
    puVar2[4] = &DAT_001e86e0;
    puVar2[5] = &DAT_001e86e0;
  }
  else {
    puVar2[5] = DAT_001e86e4;
    puVar2[4] = &DAT_001e86e0;
    puVar1 = (undefined4 *)((int)DAT_001e86e4 + 0x10);
    DAT_001e86e4 = puVar2;
    *puVar1 = puVar2;
  }
  _objc_msgSend(DAT_001e86e8,PTR_s_unlock_001f9474);
  return;
}

