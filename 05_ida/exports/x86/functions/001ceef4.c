/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ceef4. */
int __cdecl objc_addModule(int a1)
{
  int (__cdecl **zone)(int, int, int); // ebx
  int v2; // eax
  int v3; // ebx
  int v4; // eax
  int v5; // eax
  int v6; // edx
  int v8; // [esp-8h] [ebp-Ch]
  int v9; // [esp-4h] [ebp-8h]
  int v10; // [esp-4h] [ebp-8h]

  ++dword_1E8748; /*0x1ceef8*/
  if ( dword_1E874C ) /*0x1cef05*/
  {
    zone = (int (__cdecl **)(int, int, int))_objc_create_zone(); /*0x1cef0c*/
    v9 = 4 * (dword_1E8748 + 1); /*0x1cef17*/
    v8 = dword_1E874C; /*0x1cef1e*/
    v2 = _objc_create_zone(); /*0x1cef1f*/
    dword_1E874C = (*zone)(v2, v8, v9); /*0x1cef29*/
  }
  else
  {
    v3 = _objc_create_zone(); /*0x1cef39*/
    v10 = 4 * (dword_1E8748 + 1); /*0x1cef44*/
    v4 = _objc_create_zone(); /*0x1cef45*/
    dword_1E874C = (*(int (__cdecl **)(int, int))(v3 + 4))(v4, v10); /*0x1cef50*/
  }
  if ( !dword_1E874C ) /*0x1cef5f*/
    _objc_fatal("unable to reallocate module vector"); /*0x1cef66*/
  v5 = dword_1E8748; /*0x1cef6b*/
  v6 = dword_1E874C; /*0x1cef70*/
  *(_DWORD *)(dword_1E874C + 4 * dword_1E8748 - 4) = a1; /*0x1cef79*/
  *(_DWORD *)(v6 + 4 * v5) = 0; /*0x1cef7d*/
  return v6; /*0x1cef86*/
}
