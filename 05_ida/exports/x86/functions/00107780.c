/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x107780. */
int __cdecl fixjobc(int a1, int a2, int a3)
{
  int v3; // edi
  int result; // eax
  int v5; // edx
  int i; // ebx
  int v7; // edx

  v3 = *(_DWORD *)(a2 + 8); /*0x10778c*/
  result = get_posix_proc(*(__int16 *)(*(_DWORD *)(a1 + 68) + 48)); /*0x107797*/
  v5 = *(_DWORD *)(result + 16); /*0x10779c*/
  if ( v5 != a2 && *(_DWORD *)(v5 + 8) == v3 ) /*0x1077a9*/
  {
    if ( a3 ) /*0x1077af*/
    {
      ++*(_DWORD *)(a2 + 16); /*0x1077b1*/
    }
    else
    {
      result = *(_DWORD *)(a2 + 16); /*0x1077b8*/
      *(_DWORD *)(a2 + 16) = result - 1; /*0x1077be*/
      if ( result == 1 ) /*0x1077c4*/
        result = sub_10782C(a2); /*0x1077c7*/
    }
  }
  for ( i = *(_DWORD *)(a1 + 72); i; i = *(_DWORD *)(i + 76) ) /*0x1077d4*/
  {
    result = get_posix_proc(*(__int16 *)(i + 48)); /*0x1077dd*/
    v7 = *(_DWORD *)(result + 16); /*0x1077e2*/
    if ( v7 != a2 && *(_DWORD *)(v7 + 8) == v3 && *(_BYTE *)(i + 19) != 5 ) /*0x1077f5*/
    {
      if ( a3 ) /*0x1077fb*/
      {
        ++*(_DWORD *)(v7 + 16); /*0x1077fd*/
      }
      else
      {
        result = *(_DWORD *)(v7 + 16); /*0x107804*/
        *(_DWORD *)(v7 + 16) = result - 1; /*0x10780a*/
        if ( result == 1 ) /*0x107810*/
          result = sub_10782C(v7); /*0x107813*/
      }
    }
  }
  return result; /*0x107825*/
}
