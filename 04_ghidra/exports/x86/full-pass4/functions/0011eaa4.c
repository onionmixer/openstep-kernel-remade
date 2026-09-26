/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011eaa4 */

void _ustat(void)

{
  undefined2 *puVar1;
  undefined1 uVar2;
  int local_5c;
  int local_58;
  undefined4 local_54;
  undefined1 local_44 [4];
  int local_40;
  int local_34;
  undefined4 local_2c;
  
  puVar1 = *(undefined2 **)(DAT_001e875c + 0x24);
  uVar2 = _vafsidtovfs(*puVar1,&local_5c);
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
  if (*(char *)(DAT_001e875c + 0x68) == '\0') {
    uVar2 = (**(code **)(*(int *)(local_5c + 4) + 0xc))(local_5c,local_44);
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
    if (*(char *)(DAT_001e875c + 0x68) == '\0') {
      _bzero(&local_58,0x14);
      local_58 = local_34 * local_40 + 0x1ff;
      if (local_58 < 0) {
        local_58 = local_34 * local_40 + 0x3fe;
      }
      local_58 = local_58 >> 9;
      local_54 = local_2c;
      uVar2 = _copyout(&local_58,*(undefined4 *)(puVar1 + 2),0x14);
      *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
    }
  }
  return;
}

