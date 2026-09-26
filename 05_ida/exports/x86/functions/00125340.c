/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x125340. */
int __cdecl in_pcbnotify(_DWORD *a1, int a2, __int16 a3, int a4, __int16 a5, unsigned int a6, int (__cdecl *a7)(int))
{
  int v7; // ecx
  int result; // eax
  int v10; // edx
  _DWORD *v11; // ebx
  int v12; // [esp+Ch] [ebp-Ch]
  int v13; // [esp+10h] [ebp-8h]
  int v14; // [esp+14h] [ebp-4h]

  result = a2; /*0x125349*/
  LOWORD(v7) = a3; /*0x12534f*/
  if ( a6 <= 0x15 && *(_WORD *)a2 == 2 ) /*0x125364*/
  {
    result = *(_DWORD *)(a2 + 4); /*0x12536a*/
    v14 = result; /*0x12536d*/
    if ( result ) /*0x125372*/
    {
      result = a6 - 14; /*0x125378*/
      if ( a6 - 14 <= 3 || a6 == 6 || a6 == 1 ) /*0x125388*/
      {
        v7 = 0; /*0x12538a*/
        a5 = 0; /*0x12538c*/
        a4 = 0; /*0x12538e*/
        if ( a6 != 6 ) /*0x125398*/
          a7 = in_rtchange; /*0x12539a*/
      }
      v10 = (unsigned __int8)inetctlerrmap[a6]; /*0x1253a1*/
      v11 = (_DWORD *)*a1; /*0x1253ab*/
      if ( (_DWORD *)*a1 != a1 ) /*0x1253af*/
      {
        do /*0x125419*/
        {
          if ( v11[3] == v14 /*0x1253e4*/
            && v11[7]
            && (!a5 || *((_WORD *)v11 + 12) == a5)
            && (!a4 || v11[5] == a4)
            && (!(_WORD)v7 || *((_WORD *)v11 + 8) == (_WORD)v7) )
          {
            if ( v10 ) /*0x1253ee*/
              *(_WORD *)(v11[7] + 86) = v10; /*0x1253f3*/
            result = (int)v11; /*0x1253f7*/
            v11 = (_DWORD *)*v11; /*0x1253f9*/
            if ( a7 ) /*0x1253ff*/
            {
              v12 = v10; /*0x125402*/
              v13 = v7; /*0x125405*/
              result = a7(result); /*0x12540b*/
              v7 = v13; /*0x125410*/
              v10 = v12; /*0x125413*/
            }
          }
          else
          {
            v11 = (_DWORD *)*v11; /*0x1253e6*/
          }
        }
        while ( a1 != v11 ); /*0x125419*/
      }
    }
  }
  return result; /*0x12541e*/
}
