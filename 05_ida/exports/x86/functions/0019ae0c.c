/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x19ae0c. */
int __cdecl sub_19AE0C(int a1)
{
  _DWORD *v1; // eax
  unsigned __int8 v3; // al
  unsigned int v4; // ebx
  unsigned int v5; // ebx
  unsigned __int8 v6; // al
  unsigned int v7; // ebx
  unsigned __int8 v8; // bl
  unsigned __int8 v9; // [esp+Ch] [ebp-28h]
  int i; // [esp+10h] [ebp-24h]
  char *v11; // [esp+14h] [ebp-20h]
  char *v12; // [esp+14h] [ebp-20h]
  char *v13; // [esp+14h] [ebp-20h]
  int v14; // [esp+18h] [ebp-1Ch]
  int v15; // [esp+18h] [ebp-1Ch]
  int v16; // [esp+18h] [ebp-1Ch]
  int v17; // [esp+1Ch] [ebp-18h]
  int v18; // [esp+20h] [ebp-14h]
  int v19; // [esp+24h] [ebp-10h]
  char *v20; // [esp+28h] [ebp-Ch]
  char *v21; // [esp+28h] [ebp-Ch]
  _DWORD *v22; // [esp+2Ch] [ebp-8h]

  v1 = *(_DWORD **)(a1 + 28); /*0x19ae18*/
  v22 = v1; /*0x19ae1b*/
  if ( *v1 == 3 ) /*0x19ae23*/
  {
    if ( v1[64] ) /*0x19ae3f*/
    {
      v20 = (char *)v1[49]; /*0x19ae52*/
      __outbyte(0x3CEu, 5u); /*0x19ae5c*/
      _InterlockedIncrement(&dword_1E8654); /*0x19ae5d*/
      v3 = __inbyte(0x3CFu); /*0x19ae69*/
      __outbyte(0x3CEu, 5u); /*0x19ae76*/
      _InterlockedIncrement(&dword_1E8654); /*0x19ae77*/
      __outbyte(0x3CFu, v3 & 0xFC); /*0x19ae85*/
      _InterlockedIncrement(&dword_1E8654); /*0x19ae86*/
      __outbyte(0x3CEu, 1u); /*0x19ae94*/
      _InterlockedIncrement(&dword_1E8654); /*0x19ae95*/
      __outbyte(0x3CFu, 0); /*0x19aea3*/
      _InterlockedIncrement(&dword_1E8654); /*0x19aea4*/
      __outbyte(0x3CEu, 8u); /*0x19aeb2*/
      _InterlockedIncrement(&dword_1E8654); /*0x19aeb3*/
      __outbyte(0x3CFu, 0xFFu); /*0x19aec1*/
      _InterlockedIncrement(&dword_1E8654); /*0x19aec2*/
      __outbyte(0x3C4u, 2u); /*0x19aed0*/
      _InterlockedIncrement(&dword_1E8654); /*0x19aed1*/
      __outbyte(0x3C5u, 1u); /*0x19aedf*/
      _InterlockedIncrement(&dword_1E8654); /*0x19aee0*/
      v11 = (char *)v22[53]; /*0x19aef0*/
      v14 = v22[50]; /*0x19af00*/
      if ( v14 ) /*0x19af05*/
      {
        v4 = v22[51]; /*0x19af0a*/
        v19 = v22[4]; /*0x19af13*/
        do /*0x19af2e*/
        {
          qmemcpy(v11, v20, v4); /*0x19af20*/
          v11 += v19; /*0x19af25*/
          v20 += v4; /*0x19af28*/
          --v14; /*0x19af2b*/
        }
        while ( v14 ); /*0x19af2e*/
      }
      __outbyte(0x3C4u, 2u); /*0x19af37*/
      _InterlockedIncrement(&dword_1E8654); /*0x19af38*/
      __outbyte(0x3C5u, 2u); /*0x19af44*/
      _InterlockedIncrement(&dword_1E8654); /*0x19af45*/
      v12 = (char *)v22[53]; /*0x19af55*/
      v15 = v22[50]; /*0x19af61*/
      if ( v15 ) /*0x19af66*/
      {
        v5 = v22[51]; /*0x19af6b*/
        v18 = v22[4]; /*0x19af74*/
        do /*0x19af8e*/
        {
          qmemcpy(v12, v20, v5); /*0x19af80*/
          v12 += v18; /*0x19af85*/
          v20 += v5; /*0x19af88*/
          --v15; /*0x19af8b*/
        }
        while ( v15 ); /*0x19af8e*/
      }
    }
    else
    {
      v21 = (char *)v1[49]; /*0x19afa5*/
      v13 = (char *)v1[53]; /*0x19afb1*/
      __outbyte(0x3CEu, 5u); /*0x19afbb*/
      _InterlockedIncrement(&dword_1E8654); /*0x19afbc*/
      v6 = __inbyte(0x3CFu); /*0x19afc8*/
      __outbyte(0x3CEu, 5u); /*0x19afd8*/
      _InterlockedIncrement(&dword_1E8654); /*0x19afd9*/
      __outbyte(0x3CFu, v6 & 0xFC | 1); /*0x19afe7*/
      _InterlockedIncrement(&dword_1E8654); /*0x19afe8*/
      v16 = v22[50]; /*0x19aff8*/
      if ( v16 ) /*0x19affd*/
      {
        v7 = v22[51]; /*0x19b002*/
        v17 = v22[4]; /*0x19b00b*/
        do /*0x19b026*/
        {
          qmemcpy(v13, v21, v7); /*0x19b018*/
          v13 += v17; /*0x19b01d*/
          v21 += v7; /*0x19b020*/
          --v16; /*0x19b023*/
        }
        while ( v16 ); /*0x19b026*/
      }
    }
    for ( i = 0; i <= 8; ++i ) /*0x19b031*/
    {
      v9 = *((_BYTE *)v22 + i + 216); /*0x19b044*/
      __outbyte(0x3CEu, i); /*0x19b04f*/
      _InterlockedIncrement(&dword_1E8654); /*0x19b050*/
      __outbyte(0x3CFu, v9); /*0x19b05f*/
      _InterlockedIncrement(&dword_1E8654); /*0x19b060*/
    }
    v8 = *((_BYTE *)v22 + 227); /*0x19b070*/
    __outbyte(0x3C4u, 2u); /*0x19b07a*/
    _InterlockedIncrement(&dword_1E8654); /*0x19b07b*/
    __outbyte(0x3C5u, v8); /*0x19b089*/
    _InterlockedIncrement(&dword_1E8654); /*0x19b08a*/
    *v22 = 0; /*0x19b094*/
    return 0; /*0x19b09a*/
  }
  else
  {
    IOLog(aVgaconsoleBogu); /*0x19ae2b*/
    return -1; /*0x19ae30*/
  }
}
