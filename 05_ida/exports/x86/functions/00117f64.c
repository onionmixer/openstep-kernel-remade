/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x117f64. */
int __cdecl getpeername(int a1, sockaddr *a2, socklen_t *a3)
{
  _DWORD *v3; // edi
  int result; // eax
  int v5; // ebx
  int *v6; // esi
  int v7; // [esp+10h] [ebp-4h] BYREF

  v3 = *(_DWORD **)(dword_1E875C + 36); /*0x117f72*/
  result = getsock(*v3); /*0x117f78*/
  if ( result ) /*0x117f82*/
  {
    v5 = *(_DWORD *)(result + 24); /*0x117f88*/
    if ( (*(_BYTE *)(v5 + 6) & 2) != 0 ) /*0x117f8f*/
    {
      v6 = m_getclr(1, 8); /*0x117fa9*/
      if ( v6 ) /*0x117fb0*/
      {
        *(_BYTE *)(dword_1E875C + 104) = copyin(v3[2], &v7, 4); /*0x117fd9*/
        result = dword_1E875C; /*0x117fdc*/
        if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x117fe4*/
        {
          *(_BYTE *)(dword_1E875C + 104) = (*(int (__cdecl **)(int, int, _DWORD, int *, _DWORD))(*(_DWORD *)(v5 + 12) /*0x118005*/
                                                                                               + 28))(
                                             v5,
                                             16,
                                             0,
                                             v6,
                                             0);
          if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x118010*/
          {
            if ( v7 > *((__int16 *)v6 + 4) ) /*0x11801d*/
              v7 = *((__int16 *)v6 + 4); /*0x11801f*/
            *(_BYTE *)(dword_1E875C + 104) = copyout((char *)v6 + v6[1], v3[1], v7); /*0x11803c*/
            if ( !*(_BYTE *)(dword_1E875C + 104) ) /*0x118047*/
              *(_BYTE *)(dword_1E875C + 104) = copyout(&v7, v3[2], 4); /*0x118063*/
          }
          m_freem((int)v6); /*0x11806a*/
        }
      }
      else
      {
        result = dword_1E875C; /*0x117fb2*/
        *(_BYTE *)(dword_1E875C + 104) = 55; /*0x117fb7*/
      }
    }
    else
    {
      result = dword_1E875C; /*0x117f91*/
      *(_BYTE *)(dword_1E875C + 104) = 57; /*0x117f96*/
    }
  }
  return result; /*0x118072*/
}
