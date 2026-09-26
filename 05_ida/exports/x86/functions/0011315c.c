/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11315c. */
int __cdecl putc(int a1, FILE *a2)
{
  int v2; // eax
  int v3; // edi
  int w; // ebx
  _DWORD *v5; // ebx
  int *v7; // eax

  v2 = spltty(); /*0x113165*/
  v3 = v2; /*0x11316a*/
  w = a2->_w; /*0x11316f*/
  if ( w && (int)a2->_p >= 0 ) /*0x113179*/
  {
    if ( (w & 0x3F) == 0 ) /*0x1131cb*/
    {
      v7 = (int *)cfreelist; /*0x1131cd*/
      *(_DWORD *)(w - 64) = cfreelist; /*0x1131d2*/
      if ( !v7 ) /*0x1131d7*/
      {
        splx(v3); /*0x1131da*/
        return -1; /*0x1131e4*/
      }
      cfreelist = *v7; /*0x1131ec*/
      cfreecount -= 52; /*0x1131f2*/
      *v7 = 0; /*0x1131f9*/
      w = (int)(v7 + 3); /*0x1131ff*/
    }
  }
  else
  {
    v5 = (_DWORD *)cfreelist; /*0x11317b*/
    if ( !cfreelist ) /*0x113183*/
    {
      splx(v2); /*0x113186*/
      return -1; /*0x113190*/
    }
    cfreelist = *(_DWORD *)cfreelist; /*0x11319a*/
    cfreecount -= 52; /*0x1131a0*/
    *v5 = 0; /*0x1131a7*/
    bzero(v5 + 1, 8u); /*0x1131b3*/
    w = (int)(v5 + 3); /*0x1131b8*/
    a2->_r = w; /*0x1131be*/
  }
  if ( (a1 & 0x100) != 0 ) /*0x113208*/
    *(_BYTE *)((w & 0xFFFFFFC0) + ((w & 0x3F) >> 3) + 4) |= 1 << ((w & 0x3F) - 8 * ((w & 0x3F) >> 3)); /*0x113238*/
  *(_BYTE *)w = a1; /*0x11323f*/
  ++a2->_p; /*0x113244*/
  a2->_w = w + 1; /*0x113247*/
  splx(v3); /*0x11324b*/
  return 0; /*0x113255*/
}
