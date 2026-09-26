/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11aa80. */
int __cdecl biowait(_BYTE *a1)
{
  int v1; // esi
  int result; // eax
  char v3; // dl

  v1 = splhigh(); /*0x11aa8d*/
  while ( (*a1 & 2) == 0 ) /*0x11aa92*/
    sleep((unsigned int)a1); /*0x11aa97*/
  splx(v1); /*0x11aaa5*/
  result = dword_1E875C; /*0x11aaaa*/
  if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x11aab2*/
  {
    v3 = geterror(a1); /*0x11aabe*/
    result = dword_1E875C; /*0x11aac0*/
    *(_BYTE *)(dword_1E875C + 104) = v3; /*0x11aac5*/
  }
  return result; /*0x11aacb*/
}
