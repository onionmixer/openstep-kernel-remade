/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1cd868. */
void (__cdecl __noreturn *__cdecl _class_lookupMethodAndLoadCache(int a1, int a2))(void *a1, SEL sel)
{
  int v2; // esi
  Class Class; // eax
  _DWORD *v5; // ecx
  _DWORD *v6; // edx
  int v7; // eax
  _DWORD *v8; // ebx
  int v9; // ebx
  int v10; // eax
  _DWORD *v11; // eax
  int v12; // [esp-4h] [ebp-10h]
  int v13; // [esp+0h] [ebp-Ch]
  int v14; // [esp+0h] [ebp-Ch]
  int v15; // [esp+0h] [ebp-Ch]
  int v16; // [esp+4h] [ebp-8h]
  int v17; // [esp+4h] [ebp-8h]

  v2 = a1; /*0x1cd86e*/
  if ( (_UNKNOWN *)a1 == &unk_1D6728 ) /*0x1cd877*/
    return sub_1CD25C; /*0x1cd879*/
  if ( (*(_BYTE *)(a1 + 16) & 2) != 0 && (*(_BYTE *)(a1 + 16) & 4) == 0 ) /*0x1cd88e*/
  {
    Class = objc_getClass(*(const char **)(a1 + 8)); /*0x1cd894*/
    sub_1CD284(Class); /*0x1cd89a*/
  }
  while ( 1 ) /*0x1cd8a4*/
  {
    v5 = *(_DWORD **)(v2 + 28); /*0x1cd8a4*/
    if ( v5 ) /*0x1cd8a9*/
    {
      while ( 1 ) /*0x1cd8ac*/
      {
        v6 = v5 + 2; /*0x1cd8ac*/
        v7 = v5[1] - 1; /*0x1cd8b2*/
        if ( v7 >= 0 ) /*0x1cd8b3*/
          break; /*0x1cd8b3*/
LABEL_10:
        v5 = (_DWORD *)*v5; /*0x1cd8c5*/
        if ( !v5 ) /*0x1cd8c9*/
          goto LABEL_11; /*0x1cd8c9*/
      }
      while ( *v6 != a2 ) /*0x1cd8bd*/
      {
        v6 += 3; /*0x1cd8bf*/
        if ( --v7 < 0 ) /*0x1cd8c3*/
          goto LABEL_10; /*0x1cd8c3*/
      }
      v8 = v6; /*0x1cd910*/
    }
    else
    {
LABEL_11:
      v8 = nullptr; /*0x1cd8cb*/
    }
    if ( v8 ) /*0x1cd8cf*/
      break; /*0x1cd8cf*/
    v2 = *(_DWORD *)(v2 + 4); /*0x1cd8d1*/
    if ( !v2 ) /*0x1cd8d6*/
    {
      v9 = NXDefaultMallocZone(v13, v16); /*0x1cd8dd*/
      v10 = NXDefaultMallocZone(12, v14); /*0x1cd8e1*/
      v11 = (_DWORD *)(*(int (__stdcall **)(int, int, int, int))(v9 + 4))(v10, v12, v15, v17); /*0x1cd8ea*/
      *v11 = a2; /*0x1cd8ef*/
      v11[1] = ""; /*0x1cd8f1*/
      v11[2] = _objc_msgForward; /*0x1cd8f8*/
      sub_1CD76C(a1, v11); /*0x1cd904*/
      return (void (__cdecl __noreturn *)(void *, SEL))_objc_msgForward; /*0x1cd90e*/
    }
  }
  sub_1CD76C(a1, v8); /*0x1cd919*/
  return (void (__cdecl __noreturn *)(void *, SEL))v8[2]; /*0x1cd924*/
}
