/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x116230. */
char *__cdecl sonewconn(int a1)
{
  int *v1; // eax
  int v2; // edi
  char *v3; // ebx
  __int16 v4; // dx
  __int16 v5; // dx

  if ( *(__int16 *)(a1 + 24) + *(__int16 *)(a1 + 32) <= 3 * *(__int16 *)(a1 + 34) / 2 ) /*0x116255*/
  {
    v1 = m_getclr(0, 3); /*0x11625f*/
    v2 = (int)v1; /*0x116264*/
    if ( v1 ) /*0x11626b*/
    {
      v3 = (char *)v1 + v1[1]; /*0x11626f*/
      *(_WORD *)v3 = *(_WORD *)a1; /*0x116275*/
      v4 = *(_WORD *)(a1 + 2); /*0x116278*/
      LOBYTE(v4) = v4 & 0xFD; /*0x11627c*/
      *((_WORD *)v3 + 1) = v4; /*0x11627f*/
      *((_WORD *)v3 + 2) = *(_WORD *)(a1 + 4); /*0x116287*/
      v5 = *(_WORD *)(a1 + 6); /*0x11628b*/
      LOBYTE(v5) = v5 | 1; /*0x11628f*/
      *((_WORD *)v3 + 3) = v5; /*0x116292*/
      *((_DWORD *)v3 + 3) = *(_DWORD *)(a1 + 12); /*0x116299*/
      *((_WORD *)v3 + 42) = *(_WORD *)(a1 + 84); /*0x1162a0*/
      *((_WORD *)v3 + 45) = *(_WORD *)(a1 + 90); /*0x1162a8*/
      soqinsque(a1, v3, 0); /*0x1162b0*/
      if ( !(*(int (__cdecl **)(char *, _DWORD, _DWORD, _DWORD, _DWORD))(*((_DWORD *)v3 + 3) + 28))(v3, 0, 0, 0, 0) ) /*0x1162cb*/
        return v3; /*0x1162ea*/
      if ( *((_DWORD *)v3 + 4) ) /*0x1162cd*/
        soqremque(v3, 0); /*0x1162d6*/
      m_free(v2); /*0x1162df*/
    }
  }
  return nullptr; /*0x1162f1*/
}
