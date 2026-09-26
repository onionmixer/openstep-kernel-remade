/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a3fc4 */

void FUN_001a3fc4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)_IOMalloc(0x1c);
  *puVar2 = param_3;
  puVar2[3] = 0xffffffff;
  puVar2[2] = 0xffffffff;
  puVar2[4] = 0;
  _objc_msgSend(DAT_001e8684,PTR_s_lock_001f9220);
  puVar2[1] = DAT_001e8678;
  DAT_001e8678 = DAT_001e8678 + 1;
  if ((undefined4 **)DAT_001e867c == &DAT_001e867c) {
    DAT_001e867c = puVar2;
    DAT_001e8680 = puVar2;
    puVar2[5] = &DAT_001e867c;
    puVar2[6] = &DAT_001e867c;
  }
  else {
    puVar2[6] = DAT_001e8680;
    puVar2[5] = &DAT_001e867c;
    puVar1 = (undefined4 *)((int)DAT_001e8680 + 0x14);
    DAT_001e8680 = puVar2;
    *puVar1 = puVar2;
  }
  _objc_msgSend(DAT_001e8684,PTR_s_unlock_001f9474);
  return;
}

