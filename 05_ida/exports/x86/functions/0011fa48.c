/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11fa48. */
int __cdecl sub_11FA48(int a1, int a2, int a3)
{
  __int16 v3; // ax
  void *v4; // eax
  int v6; // ebx
  int v7; // eax
  int v8; // eax
  int v9; // [esp-14h] [ebp-3Ch]
  int v10; // [esp+Ch] [ebp-1Ch]
  int v11; // [esp+10h] [ebp-18h] BYREF
  int v12; // [esp+14h] [ebp-14h] BYREF
  _BYTE v13[12]; // [esp+18h] [ebp-10h] BYREF
  __int16 v14; // [esp+24h] [ebp-4h] BYREF

  v10 = *(_DWORD *)(if_private(a1) + 12); /*0x11fa66*/
  if ( *(_WORD *)a3 ) /*0x11fa69*/
  {
    if ( *(_WORD *)a3 != 2 ) /*0x11fa73*/
    {
      nb_free(a2); /*0x11fadd*/
      return 47; /*0x11fae7*/
    }
    v12 = *(_DWORD *)(a3 + 4); /*0x11fa93*/
    v9 = *(_DWORD *)(if_private(a1) + 8); /*0x11faaf*/
    v4 = (void *)if_private(a1); /*0x11fab1*/
    if ( !arpresolve(a1, v4, v9, a2, &v12, v13, (int)&v11) ) /*0x11fabb*/
      return 0; /*0x11fac9*/
    v3 = 2048; /*0x11facc*/
  }
  else
  {
    bcopy((const void *)(a3 + 2), v13, 0xEu); /*0x11fa82*/
    v3 = v14; /*0x11fa87*/
  }
  v14 = __ROR2__(v3, 8); /*0x11fad5*/
  nb_grow_top(a2, 14); /*0x11faef*/
  nb_write(a2, 12, 2u, &v14); /*0x11fb00*/
  v6 = if_output(v10, a2, v13); /*0x11fb10*/
  if ( v6 ) /*0x11fb17*/
  {
    v8 = if_oerrors(a1); /*0x11fb2d*/
    if_oerrors_set(a1, v8 + 1); /*0x11fb35*/
  }
  else
  {
    v7 = if_opackets(a1); /*0x11fb1a*/
    if_opackets_set(a1, v7 + 1); /*0x11fb22*/
  }
  return v6; /*0x11fb3f*/
}
