/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001174f8 */

ssize_t _sendmsg(int param_1,msghdr *param_2,int param_3)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  uint uVar3;
  undefined1 local_9c [128];
  undefined1 local_1c [8];
  undefined1 *local_14;
  uint local_10;
  
  puVar1 = *(undefined4 **)(DAT_001e875c + 0x24);
  uVar2 = _copyin(puVar1[1],local_1c,0x18);
  uVar3 = DAT_001e875c;
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
  if (*(char *)(DAT_001e875c + 0x68) == '\0') {
    if (local_10 < 0x10) {
      uVar2 = _copyin(local_14,local_9c,local_10 << 3);
      *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
      uVar3 = DAT_001e875c;
      if (*(char *)(DAT_001e875c + 0x68) == '\0') {
        local_14 = local_9c;
        uVar3 = _sendit(*puVar1,local_1c,puVar1[2]);
      }
    }
    else {
      *(undefined1 *)(DAT_001e875c + 0x68) = 0x28;
      uVar3 = local_10;
    }
  }
  return uVar3;
}

