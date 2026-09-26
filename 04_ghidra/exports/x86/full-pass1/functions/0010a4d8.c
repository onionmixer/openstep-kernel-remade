/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0010a4d8 */

uint _uwritec(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  if (0 < (int)param_1[5]) {
    do {
      if ((int)param_1[1] < 1) {
                    /* WARNING: Subroutine does not return */
        _panic(s_uwritec_001daa55);
      }
      piVar1 = (int *)*param_1;
      if (piVar1[1] != 0) {
        iVar2 = param_1[3];
        if (iVar2 == 1) {
          uVar3 = (uint)*(byte *)*piVar1;
        }
        else if (iVar2 < 2) {
          if (iVar2 != 0) {
LAB_0010a554:
                    /* WARNING: Subroutine does not return */
            _panic(s_uwritec__bogus_uio_segflg_001daa5d);
          }
          uVar3 = _fubyte(*piVar1);
        }
        else {
          if (iVar2 != 2) goto LAB_0010a554;
          uVar3 = _fuibyte(*piVar1);
        }
        if ((int)uVar3 < 0) {
          return 0xffffffff;
        }
        *piVar1 = *piVar1 + 1;
        piVar1[1] = piVar1[1] + -1;
        param_1[5] = param_1[5] + -1;
        param_1[2] = param_1[2] + 1;
        return uVar3 & 0xff;
      }
      *param_1 = piVar1 + 2;
      iVar2 = param_1[1];
      param_1[1] = iVar2 + -1;
    } while (iVar2 != 1);
  }
  return 0xffffffff;
}

