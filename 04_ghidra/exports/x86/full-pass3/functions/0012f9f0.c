/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0012f9f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _rinval(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  piVar6 = &_rtable;
  do {
    iVar2 = *piVar6;
    while (iVar3 = iVar2, iVar3 != 0) {
      iVar2 = *(int *)(iVar3 + 8);
      iVar1 = iVar3 + 0xc;
      if (*(int *)(iVar3 + 0x30) == param_1) {
        iVar4 = 0;
        for (iVar5 = (&_rtable)
                     [(byte)(*(byte *)(iVar3 + 0x4a) ^ *(byte *)(iVar3 + 0x4b) ^
                             *(byte *)(iVar3 + 0x4c) ^ *(byte *)(iVar3 + 0x4d) ^
                             *(byte *)(iVar3 + 0x4e) ^ *(byte *)(iVar3 + 0x4f) ^
                             *(byte *)(iVar3 + 0x50) ^ *(byte *)(iVar3 + 0x51) ^
                             *(byte *)(iVar3 + 0x54) ^ *(byte *)(iVar3 + 0x55) ^
                             *(byte *)(iVar3 + 0x56) ^ *(byte *)(iVar3 + 0x57) ^
                             *(byte *)(iVar3 + 0x58) ^ *(byte *)(iVar3 + 0x59) ^
                             *(byte *)(iVar3 + 0x5a) ^ *(byte *)(iVar3 + 0x5b)) & 0x3f]; iVar5 != 0;
            iVar5 = *(int *)(iVar5 + 8)) {
          if (iVar5 == iVar3) {
            if (iVar4 == 0) {
              (&_rtable)
              [(byte)(*(byte *)(iVar3 + 0x4a) ^ *(byte *)(iVar3 + 0x4b) ^ *(byte *)(iVar3 + 0x4c) ^
                      *(byte *)(iVar3 + 0x4d) ^ *(byte *)(iVar3 + 0x4e) ^ *(byte *)(iVar3 + 0x4f) ^
                      *(byte *)(iVar3 + 0x50) ^ *(byte *)(iVar3 + 0x51) ^ *(byte *)(iVar3 + 0x54) ^
                      *(byte *)(iVar3 + 0x55) ^ *(byte *)(iVar3 + 0x56) ^ *(byte *)(iVar3 + 0x57) ^
                      *(byte *)(iVar3 + 0x58) ^ *(byte *)(iVar3 + 0x59) ^ *(byte *)(iVar3 + 0x5a) ^
                     *(byte *)(iVar3 + 0x5b)) & 0x3f] = *(undefined4 *)(iVar3 + 8);
            }
            else {
              *(undefined4 *)(iVar4 + 8) = *(undefined4 *)(iVar3 + 8);
            }
            __rnhash = __rnhash + -1;
            break;
          }
          iVar4 = iVar5;
        }
        *(short *)(iVar3 + 0x12) = *(short *)(iVar3 + 0x12) + 1;
        _binvalfree(iVar1);
        _dnlc_purge_vp(iVar1);
        if (1 < *(ushort *)(iVar3 + 0x12)) {
          *(undefined4 *)(iVar3 + 8) =
               (&_rtable)
               [(byte)(*(byte *)(iVar3 + 0x4a) ^ *(byte *)(iVar3 + 0x4b) ^ *(byte *)(iVar3 + 0x4c) ^
                       *(byte *)(iVar3 + 0x4d) ^ *(byte *)(iVar3 + 0x4e) ^ *(byte *)(iVar3 + 0x4f) ^
                       *(byte *)(iVar3 + 0x50) ^ *(byte *)(iVar3 + 0x51) ^ *(byte *)(iVar3 + 0x54) ^
                       *(byte *)(iVar3 + 0x55) ^ *(byte *)(iVar3 + 0x56) ^ *(byte *)(iVar3 + 0x57) ^
                       *(byte *)(iVar3 + 0x58) ^ *(byte *)(iVar3 + 0x59) ^ *(byte *)(iVar3 + 0x5a) ^
                      *(byte *)(iVar3 + 0x5b)) & 0x3f];
          (&_rtable)
          [(byte)(*(byte *)(iVar3 + 0x4a) ^ *(byte *)(iVar3 + 0x4b) ^ *(byte *)(iVar3 + 0x4c) ^
                  *(byte *)(iVar3 + 0x4d) ^ *(byte *)(iVar3 + 0x4e) ^ *(byte *)(iVar3 + 0x4f) ^
                  *(byte *)(iVar3 + 0x50) ^ *(byte *)(iVar3 + 0x51) ^ *(byte *)(iVar3 + 0x54) ^
                  *(byte *)(iVar3 + 0x55) ^ *(byte *)(iVar3 + 0x56) ^ *(byte *)(iVar3 + 0x57) ^
                  *(byte *)(iVar3 + 0x58) ^ *(byte *)(iVar3 + 0x59) ^ *(byte *)(iVar3 + 0x5a) ^
                 *(byte *)(iVar3 + 0x5b)) & 0x3f] = iVar3;
          __rnhash = __rnhash + 1;
        }
        _vn_rele(iVar1);
      }
    }
    piVar6 = piVar6 + 1;
    if ((int *)0x1ef13f < piVar6) {
      return;
    }
  } while( true );
}

