/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ca6dc. */
id __cdecl +[Protocol _fixup:numElements:](id a1, SEL a2, id a3, int a4)
{
  int i; // esi
  int v5; // eax
  int v6; // ebx
  char v8; // [esp+0h] [ebp-Ch]

  for ( i = 0; a4 > i; ++i ) /*0x1ca6ea*/
  {
    v5 = 20 * i; /*0x1ca6ef*/
    if ( *((int *)a3 + 5 * i) <= 1 && *(_DWORD *)((char *)a3 + v5 + 8) ) /*0x1ca6f8*/
      *(_DWORD *)((char *)a3 + v5 + 8) -= 4; /*0x1ca6ff*/
    v6 = 20 * i; /*0x1ca707*/
    if ( !*((_DWORD *)a3 + 5 * i) && *(_DWORD *)((char *)a3 + v6 + 8) ) /*0x1ca714*/
    {
      _objc_inform("Unable to install protocols by name...\n", v8); /*0x1ca720*/
      _objc_inform("Protocol %s must be recompiled.\n", *(const char **)((char *)a3 + v6 + 4)); /*0x1ca72f*/
    }
    *((_DWORD *)a3 + 5 * i) = a1; /*0x1ca73d*/
  }
  return a1; /*0x1ca74c*/
}
