/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ad548 */

undefined4 FUN_001ad548(int param_1,undefined4 param_2,int param_3,char param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined1 local_58;
  undefined1 local_57;
  undefined1 local_56;
  byte local_55;
  undefined1 local_52;
  undefined4 local_44;
  byte local_40;
  
  _bzero(&local_58,0x54);
  local_58 = *(undefined1 *)(param_1 + 0x188);
  local_57 = *(undefined1 *)(param_1 + 0x189);
  local_44 = 0x14;
  local_40 = local_40 | 1;
  puVar1 = (undefined4 *)_objc_msgSend(param_1,PTR_s_allocSdBuf__001f9ac0,0);
  puVar1[5] = &local_58;
  *(byte *)(puVar1 + 8) = *(byte *)(puVar1 + 8) & 0xfd | (param_4 != '\0') * '\x02' | 1;
  local_56 = 0x1b;
  local_55 = local_55 & 0x1f | *(char *)(param_1 + 0x189) << 5;
  if (param_3 == 1) {
    local_52 = 0;
  }
  else {
    if (param_3 != 0) {
      if (param_3 == 2) {
        local_52 = 2;
        *puVar1 = 4;
      }
      goto LAB_001ad5f2;
    }
    local_52 = 1;
  }
  *puVar1 = 3;
LAB_001ad5f2:
  uVar2 = _objc_msgSend(param_1,PTR_s_enqueueSdBuf__001f9abc,puVar1);
  _objc_msgSend(param_1,PTR_s_freeSdBuf__001f9ab8,puVar1);
  return uVar2;
}

