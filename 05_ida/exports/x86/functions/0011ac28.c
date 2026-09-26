/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x11ac28. */
int __cdecl blkflush(int a1, int a2, unsigned int a3)
{
  int result; // eax
  unsigned int i; // ebx
  int v5; // esi
  int v6; // esi
  int v7; // eax
  int v8; // eax
  int v9; // esi
  int v10; // [esp+Ch] [ebp-10h]
  int v11; // [esp+18h] [ebp-4h]

  v10 = (*(int (__cdecl **)(int))(*(_DWORD *)(a1 + 28) + 128))(a1); /*0x11ac40*/
  if ( v10 < 0 ) /*0x11ac48*/
    panic(aCouldnTDetermi_0); /*0x11ac4f*/
  result = (int)&bufhash + 12 * (((_BYTE)a1 + (unsigned __int8)(a2 / 8)) & 0xF); /*0x11ac85*/
  v11 = result; /*0x11ac8c*/
LABEL_4:
  for ( i = *(_DWORD *)(v11 + 4); v11 != i; i = *(_DWORD *)(i + 4) ) /*0x11ac97*/
  {
    if ( *(_DWORD *)(i + 64) == a1 && (*(_BYTE *)(i + 2) & 1) == 0 ) /*0x11acb0*/
    {
      result = *(_DWORD *)(i + 20); /*0x11acb6*/
      if ( result ) /*0x11acbb*/
      {
        v5 = *(_DWORD *)(i + 36); /*0x11acc1*/
        if ( (int)(a3 / v10 + a2 - 1) >= v5 ) /*0x11acc7*/
        {
          result = v5 + result / v10; /*0x11acd1*/
          if ( a2 < result ) /*0x11acd6*/
          {
            v6 = splhigh(); /*0x11ace1*/
            v7 = *(_DWORD *)i; /*0x11ace3*/
            if ( (*(_DWORD *)i & 8) != 0 ) /*0x11ace7*/
            {
              LOBYTE(v7) = v7 | 0x40; /*0x11ace9*/
              *(_DWORD *)i = v7; /*0x11aceb*/
              sleep(i); /*0x11acf0*/
              result = splx(v6); /*0x11acf6*/
              goto LABEL_4; /*0x11acfe*/
            }
            if ( (v7 & 0x200) != 0 ) /*0x11ad03*/
            {
              splx(v6); /*0x11ad0a*/
              v8 = splbio(); /*0x11ad0f*/
              *(_DWORD *)(*(_DWORD *)(i + 16) + 12) = *(_DWORD *)(i + 12); /*0x11ad1c*/
              *(_DWORD *)(*(_DWORD *)(i + 12) + 16) = *(_DWORD *)(i + 16); /*0x11ad25*/
              *(_BYTE *)i |= 8u; /*0x11ad28*/
              splx(v8); /*0x11ad2c*/
              v9 = *(_DWORD *)i; /*0x11ad34*/
              *(_DWORD *)i &= 0xFFFFFDF8; /*0x11ad3e*/
              if ( (v9 & 0x200) == 0 ) /*0x11ad48*/
                ++*(_DWORD *)(active_u + 416); /*0x11ad4f*/
              if ( *(_DWORD *)(i + 20) > *(_DWORD *)(i + 24) ) /*0x11ad5b*/
                panic(aBwrite); /*0x11ad62*/
              result = (*(int (__cdecl **)(unsigned int))(*(_DWORD *)(*(_DWORD *)(i + 64) + 28) + 84))(i); /*0x11ad74*/
              if ( (v9 & 0x100) != 0 ) /*0x11ad7f*/
              {
                if ( (v9 & 0x200) != 0 ) /*0x11ad9a*/
                  *(_BYTE *)i |= 0x80u; /*0x11ada0*/
              }
              else
              {
                biowait(i); /*0x11ad82*/
                result = brelse(i); /*0x11ad88*/
              }
              goto LABEL_4; /*0x11ad90*/
            }
            result = splx(v6); /*0x11ada9*/
          }
        }
      }
    }
  }
  return result; /*0x11adc0*/
}
