/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cf884. */
char *__cdecl _objc_addHeader(int a1)
{
  int v1; // ebx
  int v2; // eax
  const void *v3; // ebx
  int zone; // esi
  int v5; // eax
  int v6; // esi
  int v7; // eax
  char *result; // eax
  size_t v9; // [esp-4h] [ebp-Ch]
  size_t v10; // [esp-4h] [ebp-Ch]

  ++_nel; /*0x1cf889*/
  if ( dword_1E55F8 ) /*0x1cf896*/
  {
    v3 = dword_1E55F8; /*0x1cf8c0*/
    zone = _objc_create_zone(); /*0x1cf8cb*/
    v10 = 24 * _nel; /*0x1cf8d8*/
    v5 = _objc_create_zone(); /*0x1cf8d9*/
    dword_1E55F8 = (void *)(*(int (__stdcall **)(int, size_t))(zone + 4))(v5, v10); /*0x1cf8e6*/
    memcpy(dword_1E55F8, v3, 24 * (_nel - 1)); /*0x1cf8fb*/
    v6 = _objc_create_zone(); /*0x1cf908*/
    v7 = _objc_create_zone(); /*0x1cf90b*/
    (*(void (__stdcall **)(int, const void *))(v6 + 8))(v7, v3); /*0x1cf914*/
  }
  else
  {
    v1 = _objc_create_zone(); /*0x1cf89d*/
    v9 = 24 * _nel; /*0x1cf8aa*/
    v2 = _objc_create_zone(); /*0x1cf8ab*/
    dword_1E55F8 = (void *)(*(int (__stdcall **)(int, size_t))(v1 + 4))(v2, v9); /*0x1cf8b6*/
  }
  result = (char *)dword_1E55F8 + 24 * _nel; /*0x1cf921*/
  *((_DWORD *)result - 6) = a1; /*0x1cf92a*/
  *((_DWORD *)result - 5) = 0; /*0x1cf92d*/
  *((_DWORD *)result - 4) = 0; /*0x1cf934*/
  *((_DWORD *)result - 3) = 0; /*0x1cf93b*/
  *((_DWORD *)result - 2) = 0; /*0x1cf942*/
  *((_DWORD *)result - 1) = 0; /*0x1cf949*/
  return result; /*0x1cf953*/
}
