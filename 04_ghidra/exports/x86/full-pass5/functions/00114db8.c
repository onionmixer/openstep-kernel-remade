/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00114db8 */

int _soclose(uint param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  uVar2 = _splnet();
  iVar4 = 0;
  if ((*(byte *)(param_1 + 2) & 2) != 0) {
    uVar1 = *(uint *)(param_1 + 0x14);
    while (uVar1 != param_1) {
      _soabort(*(undefined4 *)(param_1 + 0x14));
      uVar1 = *(uint *)(param_1 + 0x14);
    }
    while (*(uint *)(param_1 + 0x1c) != param_1) {
      _soabort(*(undefined4 *)(param_1 + 0x1c));
    }
  }
  if (*(int *)(param_1 + 8) != 0) {
    if (((*(ushort *)(param_1 + 6) & 2) != 0) &&
       (((((*(ushort *)(param_1 + 6) & 8) != 0 || (iVar4 = _sodisconnect(param_1), iVar4 == 0)) &&
         (*(char *)(param_1 + 2) < '\0')) &&
        (((*(ushort *)(param_1 + 6) & 0x108) != 0x108 && ((*(ushort *)(param_1 + 6) & 2) != 0))))))
    {
      do {
        _sleep(param_1 + 0x54);
      } while ((*(byte *)(param_1 + 6) & 2) != 0);
    }
    if ((*(int *)(param_1 + 8) != 0) &&
       (iVar3 = (**(code **)(*(int *)(param_1 + 0xc) + 0x1c))(param_1,1,0,0,0), iVar4 == 0)) {
      iVar4 = iVar3;
    }
  }
  if ((*(byte *)(param_1 + 6) & 1) == 0) {
    *(ushort *)(param_1 + 6) = *(ushort *)(param_1 + 6) | 1;
    if (*(int *)(param_1 + 8) == 0) {
      if (*(int *)(param_1 + 0x10) != 0) {
        iVar3 = _soqremque(param_1,0);
        if ((iVar3 == 0) && (iVar3 = _soqremque(param_1,1), iVar3 == 0)) {
                    /* WARNING: Subroutine does not return */
          _panic(s_sofree_dq_001db2dd);
        }
        *(undefined4 *)(param_1 + 0x10) = 0;
      }
      _sbrelease(param_1 + 0x3c);
      _sorflush(param_1);
      _m_free(param_1 & 0xffffff80);
    }
    _splx(uVar2);
    return iVar4;
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_soclose__NOFDREF_001db2e7);
}

