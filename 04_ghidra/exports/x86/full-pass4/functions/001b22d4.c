/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b22d4 */

int FUN_001b22d4(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint local_c;
  uint local_8;
  
  _IOGetTimestamp(&local_c);
  uVar2 = local_c + 0xa000000;
  uVar3 = local_8 + (0xf5ffffff < local_c);
  uVar1 = *(uint *)(param_1 + 0x1f0);
  if (((local_8 < uVar1) || ((uVar1 == local_8 && (local_c < *(uint *)(param_1 + 0x1ec))))) &&
     ((uVar1 < uVar3 || ((uVar3 == uVar1 && (*(uint *)(param_1 + 0x1ec) < uVar2)))))) {
    uVar2 = *(uint *)(param_1 + 0x1ec);
    uVar3 = *(uint *)(param_1 + 0x1f0);
  }
  if (*(char *)(param_1 + 0x208) != '\0') {
    uVar1 = *(uint *)(param_1 + 0x204);
    if ((uVar1 <= uVar3) && ((uVar1 != uVar3 || (*(uint *)(param_1 + 0x200) <= uVar2)))) {
      if (*(uint *)(param_1 + 0x1fc) < uVar1) {
        return param_1;
      }
      if ((uVar1 == *(uint *)(param_1 + 0x1fc)) &&
         (*(uint *)(param_1 + 0x1f8) < *(uint *)(param_1 + 0x200))) {
        return param_1;
      }
    }
  }
  *(uint *)(param_1 + 0x200) = uVar2;
  *(uint *)(param_1 + 0x204) = uVar3;
  _objc_msgSend(param_1,PTR_s_runPeriodicEvent__001f99b0,uVar2,uVar3);
  return param_1;
}

