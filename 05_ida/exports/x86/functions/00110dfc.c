/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x110dfc. */
int __cdecl ttyrub(int a1, int *a2)
{
  int v2; // ebx
  int result; // eax
  int v4; // edi
  int v5; // esi
  char v6; // dl
  int v7; // edi
  int i; // edi
  int v9; // [esp+10h] [ebp-8h]
  int v10; // [esp+14h] [ebp-4h] BYREF

  v2 = *a2; /*0x110e0b*/
  result = *(_DWORD *)(*a2 + 60); /*0x110e0d*/
  if ( (result & 8) != 0 && (*(_BYTE *)(v2 + 66) & 0x40) == 0 ) /*0x110e1c*/
  {
    *(_DWORD *)(v2 + 60) = result & 0xFF7FFFFF; /*0x110e2a*/
    if ( (result & 0x10000) != 0 ) /*0x110e32*/
    {
      if ( !*(_BYTE *)(v2 + 75) ) /*0x110e3c*/
        return ttyretype(a2); /*0x110eb1*/
      if ( (unsigned int)(a1 - 265) <= 1 ) /*0x110e47*/
      {
LABEL_9:
        result = ttyrubo(v2, 2); /*0x110e92*/
      }
      else
      {
        result = partab[(unsigned __int8)a1] & 0x3F; /*0x110e55*/
        switch ( partab[(unsigned __int8)a1] & 0x3F ) /*0x110e61*/
        {
          case 0: /*0x110e61*/
            result = ttyrubo(v2, 1); /*0x110e86*/
            break; /*0x110e86*/
          case 1: /*0x110e61*/
          case 2: /*0x110e61*/
          case 3: /*0x110e61*/
          case 5: /*0x110e61*/
          case 6: /*0x110e61*/
            if ( (*(_BYTE *)(v2 + 63) & 0x10) != 0 ) /*0x110e8c*/
              goto LABEL_9; /*0x110e8c*/
            break; /*0x110e8c*/
          case 4: /*0x110e61*/
            if ( *(_DWORD *)v2 > *(char *)(v2 + 75) ) /*0x110ea6*/
              return ttyretype(a2); /*0x110ea6*/
            v9 = spltty(); /*0x110ebd*/
            v4 = *(char *)(v2 + 72); /*0x110ec0*/
            *(_DWORD *)(v2 + 64) |= 0x200000u; /*0x110ec4*/
            *(_DWORD *)(v2 + 60) |= 0x800000u; /*0x110ecb*/
            *(_BYTE *)(v2 + 72) = *(_BYTE *)(v2 + 76); /*0x110ed5*/
            v5 = *(_DWORD *)(v2 + 4) - 1; /*0x110edb*/
            while ( 1 ) /*0x110eef*/
            {
              v5 = nextc3(v2, v5, &v10); /*0x110eef*/
              if ( !v5 ) /*0x110ef6*/
                break; /*0x110ef6*/
              ttyecho(v10, a2); /*0x110f00*/
            }
            *(_DWORD *)(v2 + 60) &= ~0x800000u; /*0x110f0c*/
            *(_DWORD *)(v2 + 64) &= ~0x200000u; /*0x110f13*/
            splx(v9); /*0x110f1e*/
            v6 = *(_BYTE *)(v2 + 72); /*0x110f23*/
            result = v6; /*0x110f26*/
            v7 = v4 - v6; /*0x110f29*/
            *(_BYTE *)(v2 + 72) = v6 + v7; /*0x110f2f*/
            if ( v7 > 8 ) /*0x110f38*/
              v7 = 8; /*0x110f3a*/
            for ( i = v7 - 1; i >= 0; --i ) /*0x110f40*/
              result = ttyoutput(8, v2); /*0x110f47*/
            break; /*0x110f50*/
          default:
            panic(aTtyrub); /*0x110f59*/
            return result; /*0x110f59*/
        }
      }
    }
    else if ( (result & 0x20000) != 0 ) /*0x110f65*/
    {
      if ( (*(_BYTE *)(v2 + 66) & 4) == 0 ) /*0x110f6b*/
      {
        ttyoutput(92, v2); /*0x110f70*/
        *(_DWORD *)(v2 + 64) |= 0x40000u; /*0x110f75*/
      }
      result = ttyecho(a1, a2); /*0x110f84*/
    }
    else
    {
      result = ttyecho(*(unsigned __int8 *)(v2 + 77), a2); /*0x110f91*/
    }
    --*(_BYTE *)(v2 + 75); /*0x110f96*/
  }
  return result; /*0x110f9c*/
}
