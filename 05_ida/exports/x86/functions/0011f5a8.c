/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11f5a8. */
int __cdecl sub_11F5A8(int a1, char *__s1, _WORD *a3)
{
  int v3; // eax
  int v5; // edi
  __int16 v6; // ax
  void *v7; // eax
  int v8; // [esp-8h] [ebp-20h]
  int v9; // [esp+Ch] [ebp-Ch]
  _BYTE v10[8]; // [esp+10h] [ebp-8h] BYREF

  v9 = *(_DWORD *)(if_private(a1) + 12); /*0x11f5c6*/
  if ( !strcmp(__s1, "autoaddr") ) /*0x11f5cf*/
  {
    if ( *a3 == 2 ) /*0x11f5df*/
    {
      v3 = if_private(a1); /*0x11f5e6*/
      return in_bootp(a1, a3, v3); /*0x11f5f6*/
    }
    return 47; /*0x11f5df*/
  }
  if ( !strcmp(__s1, "setaddr") ) /*0x11f602*/
  {
    if ( *a3 != 2 ) /*0x11f612*/
      return 47; /*0x11f6e5*/
    v5 = splimp(); /*0x11f61d*/
    v6 = if_flags(a1); /*0x11f620*/
    LOBYTE(v6) = v6 | 0x41; /*0x11f625*/
    if_flags_set(a1, v6); /*0x11f629*/
    if_init(v9); /*0x11f632*/
    *(_DWORD *)(if_private(a1) + 8) = *((_DWORD *)a3 + 1); /*0x11f646*/
    if ( (if_flags(a1) & 0x4000) == 0 ) /*0x11f655*/
    {
      v8 = *(_DWORD *)(if_private(a1) + 8); /*0x11f667*/
      v7 = (void *)if_private(a1); /*0x11f669*/
      arpwhohas(a1, v7, v8, a3 + 2); /*0x11f673*/
    }
    splx(v5); /*0x11f67c*/
    return 0; /*0x11f6f8*/
  }
  else
  {
    if ( !strcmp(__s1, "add-multicast") || !strcmp(__s1, "rmv-multicast") ) /*0x11f69c*/
    {
      if ( a3[8] == 2 ) /*0x11f6ad*/
      {
        v10[0] = 1; /*0x11f6af*/
        v10[1] = 0; /*0x11f6b3*/
        v10[2] = 94; /*0x11f6b7*/
        v10[3] = *((_BYTE *)a3 + 21) & 0x7F; /*0x11f6c1*/
        v10[4] = *((_BYTE *)a3 + 22); /*0x11f6c7*/
        v10[5] = *((_BYTE *)a3 + 23); /*0x11f6cd*/
        return if_control(v9, __s1, v10); /*0x11f6de*/
      }
      return 47; /*0x11f6ad*/
    }
    return if_control(v9, __s1, a3); /*0x11f6ee*/
  }
}
