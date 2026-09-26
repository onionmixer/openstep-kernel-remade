/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00117b9c */

int _getsockopt(int param_1,int param_2,int param_3,void *param_4,socklen_t *param_5)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  int local_c;
  int local_8;
  
  puVar1 = *(undefined4 **)(DAT_001e875c + 0x24);
  local_c = 0;
  iVar3 = _getsock(*puVar1);
  iVar4 = 0;
  if (iVar3 != 0) {
    if (puVar1[3] == 0) {
      local_8 = 0;
    }
    else {
      uVar2 = _copyin(puVar1[4],&local_8,4);
      *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
      if (*(char *)(DAT_001e875c + 0x68) != '\0') {
        return DAT_001e875c;
      }
    }
    uVar2 = _sogetopt(*(undefined4 *)(iVar3 + 0x18),puVar1[1],puVar1[2],&local_c);
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
    if (((*(char *)(DAT_001e875c + 0x68) == '\0') && (puVar1[3] != 0)) && (local_8 != 0)) {
      if (local_c == 0) {
        return 0;
      }
      if (*(short *)(local_c + 8) < local_8) {
        local_8 = (int)*(short *)(local_c + 8);
      }
      uVar2 = _copyout(local_c + *(int *)(local_c + 4),puVar1[3],local_8);
      *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
      if (*(char *)(DAT_001e875c + 0x68) == '\0') {
        uVar2 = _copyout(&local_8,puVar1[4],4);
        *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
      }
    }
    iVar4 = 0;
    if (local_c != 0) {
      iVar4 = _m_free(local_c);
    }
  }
  return iVar4;
}

