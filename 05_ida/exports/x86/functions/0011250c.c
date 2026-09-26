/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11250c. */
int __cdecl ptsstop(int a1, int a2)
{
  char v2; // cl
  __int16 v3; // dx
  int result; // eax
  char v5; // si
  __int16 v6; // dx
  _DWORD *v7; // ebx
  int v8; // edx
  int v9; // esi
  int v10; // edx
  int v11; // [esp+Ch] [ebp-4h]

  v2 = a2; /*0x112515*/
  v3 = *(_WORD *)(a1 + 56); /*0x11251b*/
  result = dword_1E56D4[4 * (unsigned __int8)v3]; /*0x112525*/
  if ( v3 ) /*0x11252e*/
  {
    if ( a2 ) /*0x112536*/
    {
      *(_DWORD *)result &= ~0x10u; /*0x112544*/
    }
    else
    {
      v2 = 4; /*0x112538*/
      *(_BYTE *)result |= 0x10u; /*0x11253d*/
    }
    *(_BYTE *)(result + 12) |= v2; /*0x112547*/
    v5 = 0; /*0x11254a*/
    if ( (v2 & 1) != 0 ) /*0x11254f*/
      v5 = 2; /*0x112551*/
    if ( (v2 & 2) != 0 ) /*0x112559*/
      v5 |= 1u; /*0x11255b*/
    v6 = *(_WORD *)(a1 + 56); /*0x112561*/
    result = 16 * (unsigned __int8)v6; /*0x112568*/
    v7 = *(_DWORD **)((char *)dword_1E56D4 + result); /*0x11256b*/
    if ( v6 ) /*0x112574*/
    {
      if ( (v5 & 1) != 0 ) /*0x112580*/
      {
        v11 = spltty(); /*0x112587*/
        v8 = v7[1]; /*0x11258a*/
        if ( v8 ) /*0x11258f*/
        {
          selwakeup(v8, *v7 & 1); /*0x112598*/
          selthreadclear(v7 + 1); /*0x1125a1*/
          *v7 &= ~1u; /*0x1125a6*/
        }
        splx(v11); /*0x1125b0*/
        result = wakeup(a1 + 28); /*0x1125bc*/
      }
      if ( (v5 & 2) != 0 ) /*0x1125ca*/
      {
        v9 = spltty(); /*0x1125d1*/
        v10 = v7[2]; /*0x1125d3*/
        if ( v10 ) /*0x1125d8*/
        {
          selwakeup(v10, *v7 & 2); /*0x1125e1*/
          selthreadclear(v7 + 2); /*0x1125ea*/
          *v7 &= ~2u; /*0x1125ef*/
        }
        splx(v9); /*0x1125f6*/
        return wakeup(a1 + 4); /*0x112602*/
      }
    }
  }
  return result; /*0x11260a*/
}
