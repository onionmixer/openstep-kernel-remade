/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x110fdc. */
int __cdecl ttyretype(int *a1)
{
  int v1; // esi
  int v2; // ebx
  int v3; // ebx
  int result; // eax
  int v5; // [esp+Ch] [ebp-8h]
  int v6; // [esp+10h] [ebp-4h] BYREF

  v1 = *a1; /*0x110fe8*/
  if ( *(_BYTE *)(*a1 + 87) != 0xFF ) /*0x110fef*/
    ttyecho(*(unsigned __int8 *)(*a1 + 87), a1); /*0x110ff8*/
  ttyoutput(10, v1); /*0x111003*/
  v5 = spltty(); /*0x11100d*/
  v2 = *(_DWORD *)(v1 + 16) - 1; /*0x111013*/
  while ( 1 ) /*0x111027*/
  {
    v2 = nextc3(v1 + 12, v2, &v6); /*0x111027*/
    if ( !v2 ) /*0x11102e*/
      break; /*0x11102e*/
    ttyecho(v6, a1); /*0x111038*/
  }
  v3 = *(_DWORD *)(v1 + 4) - 1; /*0x111047*/
  while ( 1 ) /*0x111054*/
  {
    v3 = nextc3(v1, v3, &v6); /*0x111054*/
    if ( !v3 ) /*0x11105b*/
      break; /*0x11105b*/
    ttyecho(v6, a1); /*0x111065*/
  }
  *(_DWORD *)(v1 + 64) &= ~0x40000u; /*0x111070*/
  result = splx(v5); /*0x11107b*/
  *(_BYTE *)(v1 + 75) = *(_BYTE *)v1; /*0x111082*/
  *(_BYTE *)(v1 + 76) = 0; /*0x111085*/
  return result; /*0x11108c*/
}
