/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1929e8. */
int __cdecl check_for_ast(int a1)
{
  int v1; // edi
  int v2; // eax
  int v3; // edx
  int v4; // edx
  int v5; // ecx
  int v6; // edx
  int result; // eax
  int v8; // [esp+Ch] [ebp-14h]
  int v9; // [esp+14h] [ebp-Ch]
  int v10; // [esp+18h] [ebp-8h]
  int v11; // [esp+1Ch] [ebp-4h]

  v11 = active_threads; /*0x1929f7*/
  v1 = *(_DWORD *)active_u; /*0x1929ff*/
  while ( 1 ) /*0x192b2b*/
  {
    while ( 1 ) /*0x192acf*/
    {
      while ( 1 ) /*0x192a04*/
      {
        _disable(); /*0x192a04*/
        v10 = need_ast[0]; /*0x192a0b*/
        if ( v1 ) /*0x192a10*/
        {
          if ( (*(_BYTE *)(v1 + 42) & 0x20) != 0 && *(_DWORD *)(active_u + 604) ) /*0x192a21*/
          {
            addupc(*(_DWORD *)(a1 + 56), active_u + 584, 1); /*0x192a39*/
            *(_DWORD *)(v1 + 40) &= ~0x200000u; /*0x192a3e*/
          }
          v2 = need_ast[0]; /*0x192a4a*/
          LOBYTE(v2) = need_ast[0] & 0xDF; /*0x192a51*/
          need_ast[0] = v2; /*0x192a53*/
          if ( (*(_BYTE *)(v11 + 380) & 3) == 0 ) /*0x192a6b*/
          {
            if ( *(_BYTE *)(v1 + 23) ) /*0x192a6d*/
              goto LABEL_12; /*0x192a71*/
            v3 = *(_DWORD *)(*(_DWORD *)(v11 + 132) + 124) | *(_DWORD *)(v1 + 24); /*0x192a7c*/
            if ( v3 ) /*0x192a7f*/
            {
              if ( (*(_BYTE *)(v1 + 40) & 0x10) != 0 || (v3 & ~(*(_DWORD *)(v1 + 28) | *(_DWORD *)(v1 + 32))) != 0 ) /*0x192a91*/
              {
                if ( issig(0) ) /*0x192a95*/
LABEL_12:
                  psig(); /*0x192aa1*/
                _disable(); /*0x192aa6*/
              }
            }
          }
        }
        need_ast[0] &= ~v10; /*0x192ab7*/
        if ( (*(_BYTE *)(v11 + 380) & 3) == 0 ) /*0x192acf*/
          break; /*0x192acf*/
        thread_halt_self(); /*0x192ad1*/
      }
      if ( (v10 & 4) != 0 ) /*0x192ae5*/
        goto LABEL_28; /*0x192ae5*/
      v4 = *(_DWORD *)(processor_ptr[0] + 300); /*0x192aec*/
      v8 = *(_DWORD *)(v4 + 264); /*0x192b01*/
      v5 = *(_DWORD *)(v4 + 260); /*0x192b04*/
      v9 = *(_DWORD *)(processor_ptr[0] + 292); /*0x192b10*/
      v6 = *(_DWORD *)(v11 + 88); /*0x192b16*/
      result = *(_DWORD *)(v11 + 96); /*0x192b19*/
      if ( (*(_BYTE *)(v11 + 76) & 2) != 0 || *(int *)(processor_ptr[0] + 264) > 0 ) /*0x192b26*/
        goto LABEL_28; /*0x192b26*/
      if ( result != 1 ) /*0x192b2b*/
        break; /*0x192b2b*/
      if ( v9 || v8 <= 0 || v5 < v6 ) /*0x192b56*/
        goto LABEL_29; /*0x192b56*/
LABEL_28:
      ++*(_DWORD *)(active_u + 436); /*0x192b58*/
      thread_block_with_continuation((int)thread_exception_return); /*0x192b68*/
    }
    if ( v8 && v5 >= v6 && (v5 > v6 || !v9) ) /*0x192b44*/
      goto LABEL_28; /*0x192b44*/
LABEL_29:
    if ( (v10 & 0x40000000) == 0 ) /*0x192b81*/
      return result; /*0x192b97*/
    fp_ast(v11); /*0x192b87*/
  }
}
