/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x124338. */
int __cdecl sub_124338(int a1, int a2, char **a3)
{
  int result; // eax
  __int16 v4; // ax
  __int16 v5; // ax
  __int16 v6; // ax
  int *v7; // eax
  int v8; // esi
  char *v9; // eax
  int v10; // ebx
  _DWORD v11[4]; // [esp+Ch] [ebp-10h] BYREF

  result = socreate(2, a3, 2, 0); /*0x124351*/
  if ( result ) /*0x12435d*/
  {
    *a3 = nullptr; /*0x124362*/
    return result; /*0x124368*/
  }
  if ( (*(_WORD *)(a1 + 12) & 1) == 0 ) /*0x124376*/
  {
    v4 = *(_WORD *)(a1 + 12); /*0x124378*/
    LOBYTE(v4) = v4 | 0x21; /*0x12437c*/
    *(_WORD *)(a2 + 16) = v4; /*0x12437e*/
    result = ifioctl((int)*a3, -2145359600, (_DWORD *)a2); /*0x12438e*/
    if ( result ) /*0x12439a*/
      return result; /*0x12439a*/
    goto LABEL_9; /*0x12439a*/
  }
  if ( *(__int16 *)(a1 + 12) >= 0 ) /*0x1243ab*/
  {
LABEL_9:
    v6 = *(_WORD *)(a1 + 12); /*0x1243e0*/
    HIBYTE(v6) |= 0x40u; /*0x1243e4*/
    *(_WORD *)(a1 + 12) = v6; /*0x1243e7*/
    bzero(v11, 0x10u); /*0x1243f1*/
    LOWORD(v11[0]) = 2; /*0x1243f6*/
    *(_DWORD *)(a2 + 16) = v11[0]; /*0x1243ff*/
    *(_DWORD *)(a2 + 20) = v11[1]; /*0x124405*/
    *(_DWORD *)(a2 + 24) = v11[2]; /*0x12440b*/
    *(_DWORD *)(a2 + 28) = v11[3]; /*0x124411*/
    result = ifioctl((int)*a3, -2145359604, (_DWORD *)a2); /*0x124420*/
    if ( !result ) /*0x12442c*/
    {
      v7 = m_get(1, 8); /*0x124432*/
      v8 = (int)v7; /*0x124437*/
      if ( v7 ) /*0x12443e*/
      {
        *((_WORD *)v7 + 4) = 16; /*0x124448*/
        v9 = (char *)v7 + v7[1]; /*0x124450*/
        *(_WORD *)v9 = 2; /*0x124453*/
        *((_WORD *)v9 + 1) = __ROR2__(68, 8); /*0x124461*/
        *((_DWORD *)v9 + 1) = 0; /*0x124465*/
        v10 = sobind((int)*a3, v8); /*0x124478*/
        m_freem(v8); /*0x12447b*/
        if ( v10 ) /*0x124482*/
        {
          return v10; /*0x124494*/
        }
        else
        {
          *((_WORD *)*a3 + 3) |= 0x100u; /*0x124489*/
          return 0; /*0x12448f*/
        }
      }
      else
      {
        return 55; /*0x124440*/
      }
    }
    return result; /*0x124445*/
  }
  result = ifioctl((int)*a3, -1071617779, (_DWORD *)a2); /*0x1243b9*/
  if ( !result ) /*0x1243c2*/
  {
    v5 = *(_WORD *)(a1 + 12); /*0x1243c8*/
    HIBYTE(v5) &= ~0x40u; /*0x1243cc*/
    *(_WORD *)(a1 + 12) = v5; /*0x1243cf*/
    return -1; /*0x1243d3*/
  }
  return result; /*0x124499*/
}
