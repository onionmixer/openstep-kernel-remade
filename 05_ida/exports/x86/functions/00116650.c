/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x116650. */
void __cdecl sbappendrecord(int a1, int *a2)
{
  int v2; // edx
  __int16 v3; // ax
  int v4; // edx

  if ( a2 ) /*0x11665d*/
  {
    v2 = *(_DWORD *)(a1 + 12); /*0x11665f*/
    if ( v2 && *(_DWORD *)(v2 + 124) ) /*0x116666*/
    {
      do /*0x11666f*/
        v2 = *(_DWORD *)(v2 + 124); /*0x11666c*/
      while ( *(_DWORD *)(v2 + 124) ); /*0x11666f*/
    }
    *(_WORD *)a1 += *((_WORD *)a2 + 4); /*0x116679*/
    v3 = *(_WORD *)(a1 + 4); /*0x11667c*/
    *(_WORD *)(a1 + 4) = v3 + 128; /*0x116687*/
    if ( (unsigned int)a2[1] > 0x7C ) /*0x11668f*/
      *(_WORD *)(a1 + 4) = v3 + 1152; /*0x116695*/
    if ( v2 ) /*0x11669b*/
      *(_DWORD *)(v2 + 124) = a2; /*0x11669d*/
    else
      *(_DWORD *)(a1 + 12) = a2; /*0x1166a4*/
    v4 = *a2; /*0x1166a7*/
    *a2 = 0; /*0x1166a9*/
    sbcompress(a1, v4, a2); /*0x1166b2*/
  }
}
