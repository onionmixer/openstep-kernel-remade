/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11cc68. */
int __cdecl chdirec(int a1, _DWORD *a2)
{
  int result; // eax
  int v3; // [esp+8h] [ebp-8h]
  int v4; // [esp+Ch] [ebp-4h] BYREF

  result = lookupname(a1, 0, 1, 0, (int)&v4); /*0x11cc81*/
  if ( !result ) /*0x11cc8b*/
  {
    if ( *(_DWORD *)(v4 + 40) != 2 ) /*0x11cc94*/
    {
      result = 20; /*0x11cc96*/
LABEL_5:
      v3 = result; /*0x11ccbc*/
      vn_rele(v4); /*0x11ccc3*/
      return v3; /*0x11cccb*/
    }
    result = (*(int (__cdecl **)(int, int, _DWORD))(*(_DWORD *)(v4 + 28) + 28))(v4, 64, *(_DWORD *)(active_u + 28)); /*0x11ccb3*/
    if ( result ) /*0x11ccba*/
      goto LABEL_5; /*0x11ccba*/
    *a2 = v4; /*0x11ccd3*/
  }
  return result; /*0x11ccd8*/
}
