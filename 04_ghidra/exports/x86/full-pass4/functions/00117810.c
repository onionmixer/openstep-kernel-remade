/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00117810 */

ssize_t _recvmsg(int param_1,msghdr *param_2,int param_3)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  undefined1 local_9c [128];
  undefined1 local_1c [8];
  undefined1 *local_14;
  uint local_10;
  int local_c;
  undefined4 local_8;
  
  puVar1 = *(undefined4 **)(DAT_001e875c + 0x24);
  uVar2 = _copyin(puVar1[1],local_1c,0x18);
  uVar4 = DAT_001e875c;
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
  if (*(char *)(DAT_001e875c + 0x68) == '\0') {
    if (local_10 < 0x10) {
      uVar2 = _copyin(local_14,local_9c,local_10 << 3);
      *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
      uVar4 = DAT_001e875c;
      if (*(char *)(DAT_001e875c + 0x68) == '\0') {
        local_14 = local_9c;
        if ((local_c != 0) &&
           (iVar3 = _useracc(local_c,local_8,0), uVar4 = DAT_001e875c, iVar3 == 0)) {
          *(undefined1 *)(DAT_001e875c + 0x68) = 0xe;
          return uVar4;
        }
        uVar4 = _recvit(*puVar1,local_1c,puVar1[2],puVar1[1] + 4,puVar1[1] + 0x14);
      }
    }
    else {
      *(undefined1 *)(DAT_001e875c + 0x68) = 0x28;
      uVar4 = local_10;
    }
  }
  return uVar4;
}

