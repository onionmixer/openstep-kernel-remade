/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cf95c. */
void *__cdecl _objc_removeHeader(int a1)
{
  size_t i; // ebx
  size_t j; // edx
  int (__stdcall **zone)(int, void *, size_t); // ebx
  int v4; // eax
  void *result; // eax
  void *v6; // [esp-8h] [ebp-14h]
  size_t v7; // [esp-4h] [ebp-10h]

  for ( i = 0; _nel > i; ++i ) /*0x1cf96a*/
  {
    if ( *((_DWORD *)dword_1E55F8 + 6 * i) == a1 ) /*0x1cf97b*/
    {
      for ( j = i; j < _nel - 1; ++j ) /*0x1cf987*/
        qmemcpy((char *)dword_1E55F8 + 24 * j, (char *)dword_1E55F8 + 24 * j + 24, 0x18u); /*0x1cf9a3*/
    }
  }
  --_nel; /*0x1cf9b9*/
  zone = (int (__stdcall **)(int, void *, size_t))_objc_create_zone(); /*0x1cf9c4*/
  v7 = 24 * _nel; /*0x1cf9d1*/
  v6 = dword_1E55F8; /*0x1cf9d8*/
  v4 = _objc_create_zone(); /*0x1cf9d9*/
  result = (void *)(*zone)(v4, v6, v7); /*0x1cf9e1*/
  dword_1E55F8 = result; /*0x1cf9e3*/
  return result; /*0x1cf9eb*/
}
