/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x142b34. */
unsigned int __cdecl fragacct(int a1, int a2, int a3, int a4)
{
  int v4; // edi
  unsigned int result; // eax
  int v6; // esi
  int v7; // eax
  unsigned int v8; // edx
  int v9; // ebx
  int v10; // [esp+Ch] [ebp-10h]
  int v11; // [esp+10h] [ebp-Ch]
  _DWORD *v12; // [esp+14h] [ebp-8h]
  unsigned int v13; // [esp+18h] [ebp-4h]
  int v14; // [esp+28h] [ebp+Ch]

  v4 = *(_DWORD *)(a1 + 56); /*0x142b40*/
  result = 2 * *(unsigned __int8 *)(a2 + fragtbl[v4]); /*0x142b51*/
  v13 = result; /*0x142b53*/
  v14 = 2 * a2; /*0x142b58*/
  v6 = 1; /*0x142b5b*/
  if ( v4 > 1 )
  {
    v12 = (_DWORD *)(a3 + 4); /*0x142b6a*/
    do
    {
      v7 = v4 + (v4 < 0 ? 7 : 0);
      LOBYTE(v7) = v7 & 0xF8; /*0x142b79*/
      result = v6 + v4 - v7; /*0x142b81*/
      v8 = v13; /*0x142b83*/
      if ( _bittest((const int *)&v8, result) ) /*0x142b86*/
      {
        v9 = around[v6]; /*0x142b8b*/
        v10 = inside[v6]; /*0x142b99*/
        v11 = v6; /*0x142b9c*/
        if ( v6 <= v4 ) /*0x142ba1*/
        {
          do /*0x142bd1*/
          {
            result = v9 & v14; /*0x142ba7*/
            if ( v10 == (v9 & v14) ) /*0x142bac*/
            {
              *v12 += a4; /*0x142bb4*/
              v11 += v6; /*0x142bb6*/
              v9 <<= v6; /*0x142bbb*/
              v10 <<= v6; /*0x142bbd*/
            }
            v9 *= 2; /*0x142bc0*/
            v10 *= 2; /*0x142bc2*/
            ++v11; /*0x142bc5*/
          }
          while ( *(_DWORD *)(a1 + 56) >= v11 ); /*0x142bd1*/
        }
      }
      ++v12; /*0x142bd3*/
      ++v6; /*0x142bd7*/
      v4 = *(_DWORD *)(a1 + 56); /*0x142bdb*/
    }
    while ( v6 < v4 );
  }
  return result; /*0x142be5*/
}
