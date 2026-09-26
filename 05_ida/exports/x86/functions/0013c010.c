/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x13c010. */
int __cdecl dirpref(_DWORD *a1)
{
  int v1; // ebx
  int v2; // eax
  int v4; // [esp+Ch] [ebp-20h]
  int v5; // [esp+10h] [ebp-1Ch]
  int v6; // [esp+14h] [ebp-18h]
  int v7; // [esp+28h] [ebp-4h]

  v5 = a1[11]; /*0x13c025*/
  v4 = a1[46]; /*0x13c037*/
  v7 = 0; /*0x13c03a*/
  v1 = 0; /*0x13c041*/
  if ( v5 > 0 ) /*0x13c049*/
  {
    do /*0x13c096*/
    {
      v2 = a1[(v1 >> a1[28]) + 182]; /*0x13c068*/
      v6 = 16 * (v1 & ~a1[27]); /*0x13c075*/
      if ( v4 > *(_DWORD *)(v2 + v6) && *(_DWORD *)(v2 + v6 + 8) >= a1[50] / v5 ) /*0x13c08a*/
      {
        v7 = v1; /*0x13c08c*/
        v4 = *(_DWORD *)(v2 + v6); /*0x13c08f*/
      }
      ++v1; /*0x13c092*/
    }
    while ( a1[11] > v1 ); /*0x13c096*/
  }
  return a1[46] * v7; /*0x13c0a5*/
}
