/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1046f0. */
int __cdecl ufalloc(int a1)
{
  int v1; // ebx

  v1 = a1; /*0x1046f4*/
  if ( a1 > 255 ) /*0x1046fd*/
  {
LABEL_7:
    *(_BYTE *)(dword_1E875C + 104) = 24; /*0x104771*/
    return -1; /*0x10477a*/
  }
  else
  {
    while ( 1 ) /*0x10470d*/
    {
      expand_fdlist(*(_DWORD *)(*(_DWORD *)(active_threads + 12) + 56), v1); /*0x10470d*/
      if ( !*(_DWORD *)(*(_DWORD *)(active_u + 336) + 4 * v1) ) /*0x104720*/
        break; /*0x104720*/
      if ( ++v1 > 255 ) /*0x10476f*/
        goto LABEL_7; /*0x10476f*/
    }
    *(_DWORD *)(dword_1E875C + 96) = v1; /*0x10472b*/
    *(_BYTE *)(v1 + *(_DWORD *)(active_u + 340)) = 0; /*0x104739*/
    if ( *(_DWORD *)(active_u + 344) < v1 ) /*0x104748*/
      *(_DWORD *)(active_u + 344) = v1; /*0x10474a*/
    *(_DWORD *)(*(_DWORD *)(active_u + 336) + 4 * v1) = -65536; /*0x10475b*/
    return v1; /*0x104762*/
  }
}
