/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x117e60. */
int __cdecl getsockname(int a1, sockaddr *a2, socklen_t *a3)
{
  _DWORD *v3; // edi
  int result; // eax
  int v5; // ebx
  int v6; // esi
  int *v7; // ebx
  int v8; // [esp+10h] [ebp-4h] BYREF

  v3 = *(_DWORD **)(dword_1E875C + 36); /*0x117e6e*/
  result = getsock(*v3); /*0x117e74*/
  v5 = result; /*0x117e79*/
  if ( result ) /*0x117e80*/
  {
    *(_BYTE *)(dword_1E875C + 104) = copyin(v3[2], &v8, 4); /*0x117e9f*/
    result = dword_1E875C; /*0x117ea2*/
    if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x117eaa*/
    {
      v6 = *(_DWORD *)(v5 + 24); /*0x117eb4*/
      v7 = m_getclr(1, 8); /*0x117ec0*/
      if ( v7 ) /*0x117ec7*/
      {
        *(_BYTE *)(dword_1E875C + 104) = (*(int (__cdecl **)(int, int, _DWORD, int *, _DWORD))(*(_DWORD *)(v6 + 12) + 28))( /*0x117eef*/
                                           v6,
                                           15,
                                           0,
                                           v7,
                                           0);
        if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x117efa*/
        {
          if ( v8 > *((__int16 *)v7 + 4) ) /*0x117f07*/
            v8 = *((__int16 *)v7 + 4); /*0x117f09*/
          *(_BYTE *)(dword_1E875C + 104) = copyout((char *)v7 + v7[1], v3[1], v8); /*0x117f26*/
          if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x117f31*/
            *(_BYTE *)(dword_1E875C + 104) = copyout(&v8, v3[2], 4); /*0x117f4d*/
        }
        m_freem((int)v7); /*0x117f54*/
      }
      else
      {
        result = dword_1E875C; /*0x117ec9*/
        *(_BYTE *)(dword_1E875C + 104) = 55; /*0x117ece*/
      }
    }
  }
  return result; /*0x117f5c*/
}
