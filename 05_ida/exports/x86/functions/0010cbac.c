/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10cbac. */
void __cdecl sub_10CBAC(int a1, char a2, _DWORD *a3)
{
  int v3; // edi
  unsigned int v4; // eax
  unsigned int i; // edx
  unsigned int v6; // eax

  if ( (a2 & 2) != 0 ) /*0x10cbbe*/
  {
    v3 = spltty(); /*0x10cbc5*/
    if ( a3 && (a3[16] & 0x14) == 0x14 ) /*0x10cbd4*/
    {
      if ( a1 == 10 ) /*0x10cbd9*/
        ttyoutput(13, a3); /*0x10cbde*/
      ttyoutput(a1, a3); /*0x10cbe8*/
      ttstart(a3); /*0x10cbee*/
    }
    splx(v3); /*0x10cbf7*/
  }
  if ( (a2 & 4) != 0 && a1 && a1 != 13 && a1 != 127 ) /*0x10cc13*/
  {
    v4 = pmsgbuf; /*0x10cc15*/
    if ( *(_DWORD *)pmsgbuf != 405601 ) /*0x10cc20*/
    {
      *(_DWORD *)pmsgbuf = 405601; /*0x10cc22*/
      *(_DWORD *)(v4 + 8) = 0; /*0x10cc28*/
      *(_DWORD *)(v4 + 4) = 0; /*0x10cc2f*/
      for ( i = 0; i <= 0xFF3; ++i ) /*0x10cc36*/
        *(_BYTE *)(i + pmsgbuf + 12) = 0; /*0x10cc3d*/
    }
    v6 = pmsgbuf; /*0x10cc4b*/
    *(_BYTE *)(*(_DWORD *)(pmsgbuf + 4) + pmsgbuf + 12) = a1; /*0x10cc57*/
    ++*(_DWORD *)(v6 + 4); /*0x10cc5a*/
    if ( *(_DWORD *)(pmsgbuf + 4) >= 0xFF4u ) /*0x10cc68*/
      *(_DWORD *)(pmsgbuf + 4) = 0; /*0x10cc71*/
  }
  if ( (a2 & 1) != 0 && a1 ) /*0x10cc82*/
    cnputc(a1); /*0x10cc85*/
  if ( (a2 & 8) != 0 ) /*0x10cc90*/
    *(_BYTE *)(*a3)++ = a1; /*0x10cc96*/
}
