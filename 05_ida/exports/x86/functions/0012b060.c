/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12b060. */
int __cdecl tcp_ctloutput(int a1, int a2, int a3, int a4, int *a5)
{
  int v5; // ebx
  int v7; // edx
  int *v8; // eax
  int v9; // [esp+Ch] [ebp-4h]

  v9 = 0; /*0x12b072*/
  v5 = *(_DWORD *)(*(_DWORD *)(a2 + 8) + 32); /*0x12b07f*/
  if ( a3 != 6 ) /*0x12b086*/
    return ip_ctloutput(a1, a2, a3, a4, a5); /*0x12b093*/
  if ( a1 ) /*0x12b0a2*/
  {
    if ( a1 == 1 ) /*0x12b0a7*/
    {
      v7 = *a5; /*0x12b0ad*/
      if ( a4 == 1 && v7 && *(_WORD *)(v7 + 8) > 3u ) /*0x12b0bd*/
      {
        if ( *(_DWORD *)(*(_DWORD *)(v7 + 4) + v7) ) /*0x12b0c2*/
          *(_BYTE *)(v5 + 27) |= 4u; /*0x12b0c8*/
        else
          *(_BYTE *)(v5 + 27) &= ~4u; /*0x12b0d0*/
      }
      else
      {
        v9 = 22; /*0x12b0d8*/
      }
      if ( v7 ) /*0x12b0e1*/
        m_free(v7); /*0x12b0e4*/
    }
  }
  else
  {
    v8 = m_get(1, 10); /*0x12b0f0*/
    *a5 = (int)v8; /*0x12b0f7*/
    *((_WORD *)v8 + 4) = 4; /*0x12b0f9*/
    if ( a4 == 1 ) /*0x12b102*/
    {
      *(int *)((char *)v8 + v8[1]) = *(_BYTE *)(v5 + 27) & 4; /*0x12b115*/
    }
    else if ( a4 == 2 ) /*0x12b107*/
    {
      *(int *)((char *)v8 + v8[1]) = *(unsigned __int16 *)(v5 + 24); /*0x12b123*/
    }
    else
    {
      return 22; /*0x12b128*/
    }
  }
  return v9; /*0x12b135*/
}
