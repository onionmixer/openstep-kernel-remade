/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001be9c0 */

void _audio_makeIMuLawTab(void)

{
  short *psVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  short local_804 [512];
  int local_404 [256];
  
  if (DAT_001e53cc == 0) {
    DAT_001e53cc = _IOMalloc(0x4000);
    iVar2 = 0;
    iVar3 = 0;
    psVar1 = local_804;
    do {
      local_404[iVar2] = (int)psVar1;
      *psVar1 = (short)iVar2;
      *(short *)(iVar3 + 2 + (int)local_804) = (short)(&_audio_muLaw)[iVar2] >> 2;
      psVar1 = psVar1 + 2;
      iVar3 = iVar3 + 4;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 0x100);
    _qsort(local_404,0x100,4,(int *)FUN_001beb1c);
    iVar2 = 0;
    iVar3 = 0;
    iVar5 = -0x2000;
    do {
      if (iVar3 < 0xff) {
        iVar4 = iVar5 - *(short *)(local_404[iVar3] + 2);
        if ((0 < iVar4) && (*(short *)(local_404[iVar3 + 1] + 2) - iVar5 < iVar4)) {
          iVar3 = iVar3 + 1;
        }
      }
      *(undefined1 *)(iVar2 + DAT_001e53cc) = *(undefined1 *)local_404[iVar3];
      iVar2 = iVar2 + 1;
      iVar5 = iVar5 + 1;
    } while (iVar2 < 0x4000);
  }
  return;
}

