/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010cd8c */

ssize_t _readv(int param_1,iovec *param_2,int param_3)

{
  int iVar1;
  undefined1 uVar2;
  int iVar3;
  undefined1 local_9c [128];
  undefined1 *local_1c;
  undefined4 local_18;
  
  iVar3 = DAT_001e875c;
  iVar1 = *(int *)(DAT_001e875c + 0x24);
  if (*(uint *)(iVar1 + 8) < 0x11) {
    local_1c = local_9c;
    local_18 = *(undefined4 *)(iVar1 + 8);
    uVar2 = _copyin(*(undefined4 *)(iVar1 + 4),local_1c,*(int *)(iVar1 + 8) * 8);
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
    iVar3 = DAT_001e875c;
    if (*(char *)(DAT_001e875c + 0x68) == '\0') {
      iVar3 = _rwuio(&local_1c,0);
    }
  }
  else {
    *(undefined1 *)(DAT_001e875c + 0x68) = 0x16;
  }
  return iVar3;
}

