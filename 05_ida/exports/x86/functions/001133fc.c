/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1133fc. */
int __cdecl unputc(int *a1)
{
  int v1; // edi
  int v2; // ebx
  int v3; // eax
  int v4; // edx
  int v5; // edi
  int v6; // ecx
  int v7; // ebx
  _DWORD *v8; // ecx
  _DWORD *v9; // eax
  _DWORD *v10; // ecx
  int v12; // [esp+Ch] [ebp-8h]
  int v13; // [esp+10h] [ebp-4h]

  v13 = spltty(); /*0x11340d*/
  if ( *a1 > 0 ) /*0x113413*/
  {
    v1 = a1[2] - 1; /*0x113427*/
    a1[2] = v1; /*0x11342a*/
    v12 = *(char *)v1; /*0x113434*/
    v2 = v1; /*0x113437*/
    LOBYTE(v2) = v1 & 0xC0; /*0x113439*/
    v3 = (v1 & 0x3F) >> 3; /*0x113448*/
    v4 = *(char *)(v2 + v3 + 4); /*0x11344f*/
    if ( _bittest(&v4, (v1 & 0x3F) - 8 * v3) ) /*0x113459*/
      v12 |= 0x100u; /*0x11345e*/
    v5 = *a1 - 1; /*0x113467*/
    *a1 = v5; /*0x11346a*/
    if ( v5 > 0 ) /*0x11346f*/
    {
      v7 = a1[2]; /*0x11349f*/
      LOBYTE(v7) = v7 & 0xC0; /*0x1134a1*/
      if ( a1[2] == v7 + 12 ) /*0x1134a9*/
      {
        a1[2] = v7; /*0x1134ab*/
        v8 = (_DWORD *)a1[1]; /*0x1134ae*/
        for ( LOBYTE(v8) = (unsigned __int8)v8 & 0xC0; *v8 != v7; v8 = (_DWORD *)*v8 ) /*0x1134b6*/
          ; /*0x1134bc*/
        v9 = v8; /*0x1134c2*/
        a1[2] = (int)(v8 + 16); /*0x1134c7*/
        v10 = (_DWORD *)*v8; /*0x1134ca*/
        *v10 = cfreelist; /*0x1134d2*/
        cfreelist = (int)v10; /*0x1134d4*/
        cfreecount += 52; /*0x1134da*/
        *v9 = 0; /*0x1134e1*/
      }
    }
    else
    {
      v6 = a1[2]; /*0x113471*/
      LOBYTE(v6) = v6 & 0xC0; /*0x113474*/
      a1[1] = 0; /*0x113477*/
      a1[2] = 0; /*0x11347e*/
      *(_DWORD *)v6 = cfreelist; /*0x11348b*/
      cfreelist = v6; /*0x11348d*/
      cfreecount += 52; /*0x113493*/
    }
  }
  else
  {
    v12 = -1; /*0x113415*/
  }
  splx(v13); /*0x1134eb*/
  return v12; /*0x1134f6*/
}
