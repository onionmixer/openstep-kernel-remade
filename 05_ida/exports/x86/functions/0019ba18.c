/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19ba18. */
int __cdecl sub_19BA18(_DWORD *a1)
{
  int result; // eax
  unsigned int v2; // eax
  _BYTE *v3; // ebx
  unsigned int k; // esi
  unsigned int j; // esi
  _DWORD *v6; // ebx
  unsigned int i; // esi
  int v8; // [esp+Ch] [ebp-18h]
  int v9; // [esp+Ch] [ebp-18h]
  int v10; // [esp+14h] [ebp-10h]
  int v11; // [esp+18h] [ebp-Ch]
  _WORD *v12; // [esp+1Ch] [ebp-8h]
  int v13; // [esp+20h] [ebp-4h]

  result = a1[36] + 12 * a1[41]; /*0x19ba33*/
  v11 = result + 12; /*0x19ba39*/
  v10 = a1[35] + 8 * a1[42]; /*0x19ba4e*/
  v13 = result; /*0x19ba51*/
  if ( !__OFSUB__(result, result + 12) ) /*0x19ba56*/
  {
    do /*0x19bbce*/
    {
      v2 = a1[7]; /*0x19ba5c*/
      if ( v2 > 3 ) /*0x19ba62*/
      {
        if ( v2 != 4 ) /*0x19ba77*/
LABEL_26:
          panic(aFbconsoleFlipc); /*0x19bbb8*/
        v6 = (_DWORD *)(a1[6] + a1[4] * v13 + 4 * v10); /*0x19bb79*/
        for ( i = 0; i <= 7; ++i ) /*0x19bb7c*/
        {
          v9 = a1[44]; /*0x19bb8e*/
          result = v9 & 0xFFFFFF; /*0x19bb93*/
          if ( (*v6 & 0xFFFFFF) == (v9 & 0xFFFFFF) ) /*0x19bb9a*/
            *v6 = a1[45]; /*0x19bba2*/
          else
            *v6 = v9; /*0x19bbab*/
          ++v6; /*0x19bbad*/
        }
      }
      else if ( v2 >= 2 ) /*0x19ba67*/
      {
        v12 = (_WORD *)(a1[6] + a1[4] * v13 + 2 * v10); /*0x19bb0c*/
        for ( j = 0; j <= 7; ++j ) /*0x19bb39*/
        {
          result = a1[44]; /*0x19bb3c*/
          if ( *v12 == (_WORD)result ) /*0x19bb48*/
            *v12 = *((_WORD *)a1 + 90); /*0x19bb51*/
          else
            *v12 = result; /*0x19bb5b*/
          ++v12; /*0x19bb5e*/
        }
      }
      else
      {
        if ( v2 != 1 ) /*0x19ba6c*/
          goto LABEL_26; /*0x19ba6c*/
        v3 = (_BYTE *)(a1[6] + a1[4] * v13 + v10); /*0x19ba91*/
        for ( k = 0; k <= 7; ++k ) /*0x19ba93*/
        {
          v8 = a1[44]; /*0x19baa1*/
          result = (unsigned __int16)v8; /*0x19baa4*/
          if ( (unsigned __int8)*v3 == (unsigned __int16)v8 ) /*0x19baa9*/
            *v3 = *((_BYTE *)a1 + 180); /*0x19bab1*/
          else
            *v3 = v8; /*0x19babb*/
          ++v3; /*0x19babd*/
        }
      }
      ++v13; /*0x19bbc5*/
    }
    while ( v13 < v11 ); /*0x19bbce*/
  }
  return result; /*0x19bbd7*/
}
