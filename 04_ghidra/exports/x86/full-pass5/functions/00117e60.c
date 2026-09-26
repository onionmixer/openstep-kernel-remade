/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00117e60 */

int _getsockname(int param_1,sockaddr *param_2,socklen_t *param_3)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_8;
  
  puVar1 = *(undefined4 **)(DAT_001e875c + 0x24);
  iVar3 = _getsock(*puVar1);
  iVar5 = 0;
  if (iVar3 != 0) {
    uVar2 = _copyin(puVar1[2],&local_8,4);
    *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
    iVar5 = DAT_001e875c;
    if (*(char *)(DAT_001e875c + 0x68) == '\0') {
      iVar3 = *(int *)(iVar3 + 0x18);
      iVar4 = _m_getclr(1,8);
      iVar5 = DAT_001e875c;
      if (iVar4 == 0) {
        *(undefined1 *)(DAT_001e875c + 0x68) = 0x37;
      }
      else {
        uVar2 = (**(code **)(*(int *)(iVar3 + 0xc) + 0x1c))(iVar3,0xf,0,iVar4,0);
        *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
        if (*(char *)(DAT_001e875c + 0x68) == '\0') {
          if (*(short *)(iVar4 + 8) < local_8) {
            local_8 = (int)*(short *)(iVar4 + 8);
          }
          uVar2 = _copyout(iVar4 + *(int *)(iVar4 + 4),puVar1[1],local_8);
          *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
          if (*(char *)(DAT_001e875c + 0x68) == '\0') {
            uVar2 = _copyout(&local_8,puVar1[2],4);
            *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
          }
        }
        iVar5 = _m_freem(iVar4);
      }
    }
  }
  return iVar5;
}

