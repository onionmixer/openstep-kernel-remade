/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x110848. */
int __cdecl ttycheckoutq(int a1, int a2)
{
  int v2; // edi
  int v3; // edx
  int v4; // esi
  void (__cdecl *v5)(int); // eax
  int v7; // [esp+Ch] [ebp-4h]

  v2 = tthiwat[*(_BYTE *)(a1 + 74) & 0x1F]; /*0x11085a*/
  v7 = spltty(); /*0x110867*/
  v3 = *(_DWORD *)(a1 + 24); /*0x110870*/
  if ( v3 <= v2 + 200 || v3 <= v2 ) /*0x110879*/
  {
LABEL_9:
    splx(v7); /*0x1108cf*/
    return 1; /*0x1108d8*/
  }
  else
  {
    while ( 1 ) /*0x110881*/
    {
      v4 = spltty(); /*0x110881*/
      if ( (*(_DWORD *)(a1 + 64) & 0x4000121) == 0 ) /*0x11088a*/
      {
        v5 = *(void (__cdecl **)(int))(a1 + 36); /*0x11088c*/
        if ( v5 ) /*0x110891*/
          v5(a1); /*0x110894*/
      }
      splx(v4); /*0x11089a*/
      if ( !a2 ) /*0x1108a6*/
        break; /*0x1108a6*/
      *(_BYTE *)(a1 + 64) |= 0x40u; /*0x1108b8*/
      sleep(a1 + 24); /*0x1108c2*/
      if ( *(_DWORD *)(a1 + 24) <= v2 ) /*0x1108cd*/
        goto LABEL_9; /*0x1108cd*/
    }
    splx(v7); /*0x1108ac*/
    return 0; /*0x1108b1*/
  }
}
