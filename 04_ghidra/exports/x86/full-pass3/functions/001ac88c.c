/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ac88c */

bool FUN_001ac88c(int param_1)

{
  undefined4 *puVar1;
  undefined1 local_58;
  undefined1 local_57;
  undefined1 local_56;
  byte local_55;
  undefined4 local_44;
  byte local_40;
  int local_3c;
  
  _bzero(&local_58,0x54);
  local_58 = *(undefined1 *)(param_1 + 0x188);
  local_57 = *(undefined1 *)(param_1 + 0x189);
  local_44 = 0x14;
  local_40 = local_40 | 1;
  puVar1 = (undefined4 *)_objc_msgSend(param_1,PTR_s_allocSdBuf__001f9ac0,0);
  *puVar1 = 3;
  puVar1[5] = &local_58;
  *(byte *)(puVar1 + 8) = *(byte *)(puVar1 + 8) & 0xfe | 2;
  local_56 = 0;
  local_55 = local_55 & 0x1f | *(char *)(param_1 + 0x189) << 5;
  _objc_msgSend(param_1,PTR_s_enqueueSdBuf__001f9abc,puVar1);
  _objc_msgSend(param_1,PTR_s_freeSdBuf__001f9ab8,puVar1);
  return local_3c != 0;
}

