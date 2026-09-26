/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011cc00 */

int _chroot(char *param_1)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  undefined4 local_8;
  
  puVar1 = *(undefined4 **)(DAT_001e875c + 0x24);
  iVar3 = _suser();
  iVar4 = 0;
  if (iVar3 != 0) {
    uVar2 = _chdirec(*puVar1,&local_8);
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
    iVar4 = DAT_001e875c;
    if (*(char *)(DAT_001e875c + 0x68) == '\0') {
      if (*(int *)(_active_u + 0x164) != 0) {
        _vn_rele(*(int *)(_active_u + 0x164));
      }
      iVar4 = _active_u;
      *(undefined4 *)(_active_u + 0x164) = local_8;
    }
  }
  return iVar4;
}

