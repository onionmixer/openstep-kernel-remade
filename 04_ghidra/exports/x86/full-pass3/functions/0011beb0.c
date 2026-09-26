/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011beb0 */

undefined4 _vno_bsd_lock(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if ((((*(uint *)(param_1 + 8) & 0x100) == 0) || ((param_2 & 2) == 0)) &&
     ((-1 < (char)*(uint *)(param_1 + 8) || ((param_2 & 1) == 0)))) {
    iVar1 = *(int *)(param_1 + 0x18);
    iVar2 = _set_label((int *)(DAT_001e875c + 0x28));
    if (iVar2 == 0) {
      do {
        while ((*(byte *)(iVar1 + 4) & 4) != 0) {
          if ((*(byte *)(param_1 + 9) & 1) == 0) {
            if ((param_2 & 4) != 0) {
              return 0x23;
            }
            *(byte *)(iVar1 + 4) = *(byte *)(iVar1 + 4) | 0x10;
            uVar3 = iVar1 + 10;
LAB_0011bf73:
            _sleep(uVar3);
          }
          else {
            _vno_bsd_unlock(param_1,0x100);
          }
        }
        if (((param_2 & 2) == 0) || ((*(ushort *)(iVar1 + 4) & 8) == 0)) {
          if ((*(byte *)(param_1 + 9) & 1) != 0) {
                    /* WARNING: Subroutine does not return */
            _panic(s_vno_bsd_lock_001db720);
          }
          if ((param_2 & 2) != 0) {
            *(short *)(iVar1 + 10) = *(short *)(iVar1 + 10) + 1;
            *(byte *)(iVar1 + 4) = *(byte *)(iVar1 + 4) | 4;
            *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 0x100;
          }
          if ((param_2 & 1) == 0) {
            return 0;
          }
          if (*(char *)(param_1 + 8) < '\0') {
            return 0;
          }
          *(short *)(iVar1 + 8) = *(short *)(iVar1 + 8) + 1;
          *(byte *)(iVar1 + 4) = *(byte *)(iVar1 + 4) | 8;
          *(byte *)(param_1 + 8) = *(byte *)(param_1 + 8) | 0x80;
          return 0;
        }
        if (-1 < *(char *)(param_1 + 8)) {
          if ((param_2 & 4) != 0) {
            return 0x23;
          }
          *(ushort *)(iVar1 + 4) = *(ushort *)(iVar1 + 4) | 0x10;
          uVar3 = iVar1 + 8;
          goto LAB_0011bf73;
        }
        _vno_bsd_unlock(param_1,0x80);
      } while( true );
    }
    if ((_active_u[0x50] >> (*(char *)(*_active_u + 0x17) - 1U & 0x1f) & 1U) != 0) {
      return 4;
    }
    *(undefined1 *)(DAT_001e875c + 0x69) = 2;
  }
  return 0;
}

