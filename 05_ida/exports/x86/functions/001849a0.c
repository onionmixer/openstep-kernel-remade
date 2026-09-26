/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1849a0. */
void __cdecl IOAddDDMEntry(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // ebx
  _DWORD *v7; // eax

  if ( dword_1F74C4 ) /*0x1849ab*/
  {
    v6 = splhigh(); /*0x1849b6*/
    if ( _InterlockedExchange(&xpr_lock, 1) != 1 ) /*0x1849c3*/
    {
      if ( !xprLocked ) /*0x1849d1*/
      {
        dword_1F74C8 += 36; /*0x1849d3*/
        if ( dword_1F74C8 > (unsigned int)dword_1E7580 ) /*0x1849e5*/
          dword_1F74C8 = dword_1F74C4; /*0x1849ed*/
        v7 = (_DWORD *)dword_1F74C8; /*0x1849f3*/
        *(_DWORD *)dword_1F74C8 = a1; /*0x1849fb*/
        v7[1] = a2; /*0x184a00*/
        v7[2] = a3; /*0x184a06*/
        v7[3] = a4; /*0x184a0c*/
        v7[4] = a5; /*0x184a12*/
        v7[5] = a6; /*0x184a18*/
        v7[8] = 0; /*0x184a1b*/
        IOGetTimestamp(v7 + 6); /*0x184a26*/
        if ( uxprGlobal > (unsigned int)dword_1F74CC ) /*0x184a39*/
          ++dword_1F74CC; /*0x184a3c*/
      }
      _InterlockedExchange(&xpr_lock, 0); /*0x184a43*/
    }
    splx(v6); /*0x184a4a*/
  }
}
