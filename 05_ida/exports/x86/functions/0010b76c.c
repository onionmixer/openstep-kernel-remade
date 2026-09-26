/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x10b76c. */
int __cdecl reboot(int howto)
{
  int result; // eax
  int v2; // edx
  char v3; // dl
  _BYTE v4[64]; // [esp+0h] [ebp-40h] BYREF

  v4[0] = 0; /*0x10b772*/
  result = suser(); /*0x10b776*/
  if ( result ) /*0x10b77d*/
  {
    result = dword_1E875C; /*0x10b77f*/
    v2 = *(_DWORD *)(dword_1E875C + 36); /*0x10b784*/
    if ( (*(_BYTE *)(v2 + 2) & 0x10) != 0 ) /*0x10b78b*/
    {
      v3 = copyinstr(*(_DWORD *)(v2 + 4), v4, 64, 0); /*0x10b79e*/
      result = dword_1E875C; /*0x10b7a0*/
      *(_BYTE *)(dword_1E875C + 104) = v3; /*0x10b7a5*/
    }
    if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x10b7b1*/
      return boot(1, **(_DWORD **)(dword_1E875C + 36), (int)v4); /*0x10b7c3*/
  }
  return result; /*0x10b7c8*/
}
