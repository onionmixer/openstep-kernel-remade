/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010b76c */

int _reboot(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined1 local_44 [64];
  
  local_44[0] = 0;
  iVar2 = _suser();
  iVar3 = 0;
  if (iVar2 != 0) {
    iVar3 = DAT_001e875c;
    if ((*(byte *)(*(int *)(DAT_001e875c + 0x24) + 2) & 0x10) != 0) {
      uVar1 = _copyinstr(*(undefined4 *)(*(int *)(DAT_001e875c + 0x24) + 4),local_44,0x40,0);
      iVar3 = DAT_001e875c;
      *(undefined1 *)(DAT_001e875c + 0x68) = uVar1;
    }
    if (*(char *)(DAT_001e875c + 0x68) == '\0') {
      iVar3 = _boot(1,**(undefined4 **)(DAT_001e875c + 0x24),local_44);
    }
  }
  return iVar3;
}

