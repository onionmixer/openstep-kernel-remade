/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cbf80. */
_BOOL4 __cdecl sub_1CBF80(int a1, _DWORD *a2, _DWORD *a3)
{
  int v3; // ebx

  v3 = 0; /*0x1cbf8a*/
  if ( *a3 == *a2 && a3[1] == a2[1] && a3[2] == a2[2] ) /*0x1cbfa0*/
    return a3[3] == a2[3]; /*0x1cbfaa*/
  return v3; /*0x1cbfad*/
}
