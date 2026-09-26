/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x113500. */
int __cdecl catq(int *a1, int *a2)
{
  int v2; // eax
  int result; // eax
  unsigned __int8 *v4; // ecx
  int v5; // ecx
  int v6; // esi
  int v7; // eax
  int v8; // eax
  signed int v9; // ebx
  _DWORD *v10; // ebx
  int *v11; // eax
  int v12; // [esp+Ch] [ebp-18h]
  int v13; // [esp+14h] [ebp-10h]
  int v14; // [esp+18h] [ebp-Ch]
  int v15; // [esp+1Ch] [ebp-8h]

  v2 = spltty(); /*0x11350c*/
  if ( *a2 ) /*0x113514*/
  {
    splx(v2); /*0x113549*/
    while ( 1 ) /*0x113556*/
    {
      v15 = spltty(); /*0x113556*/
      if ( *a1 > 0 ) /*0x11355c*/
      {
        v12 = a1[1]; /*0x113583*/
        v14 = *(unsigned __int8 *)v12; /*0x113589*/
        v4 = (unsigned __int8 *)v12; /*0x11358c*/
        LOBYTE(v4) = v12 & 0xC0; /*0x11358e*/
        v5 = (char)v4[((v12 & 0x3F) >> 3) + 4]; /*0x1135a6*/
        if ( _bittest(&v5, (v12 & 0x3F) - 8 * ((v12 & 0x3F) >> 3)) ) /*0x1135b0*/
          v14 |= 0x100u; /*0x1135b5*/
        a1[1] = v12 + 1; /*0x1135c0*/
        v6 = *a1 - 1; /*0x1135c5*/
        *a1 = v6; /*0x1135c8*/
        if ( v6 <= 0 ) /*0x1135cd*/
        {
          v7 = a1[1] - 1; /*0x1135d2*/
          LOBYTE(v7) = v7 & 0xC0; /*0x1135d3*/
          a1[1] = 0; /*0x1135d5*/
          a1[2] = 0; /*0x1135dc*/
          *(_DWORD *)v7 = cfreelist; /*0x1135e9*/
          goto LABEL_12; /*0x1135eb*/
        }
        v8 = a1[1]; /*0x1135f0*/
        if ( (v8 & 0x3F) == 0 ) /*0x1135f5*/
        {
          a1[1] = *(_DWORD *)(v8 - 64) + 12; /*0x1135fd*/
          *(_DWORD *)(v8 - 64) = cfreelist; /*0x113606*/
          v7 = v8 - 64; /*0x113609*/
LABEL_12:
          cfreelist = v7; /*0x11360c*/
          cfreecount += 52; /*0x113611*/
          if ( cwaiting ) /*0x11361f*/
          {
            wakeup((int)&cwaiting); /*0x113626*/
            cwaiting = 0; /*0x11362b*/
          }
        }
      }
      else
      {
        v14 = -1; /*0x11355e*/
        *a1 = 0; /*0x113565*/
        a1[2] = 0; /*0x11356b*/
        a1[1] = 0; /*0x113572*/
      }
      result = splx(v15); /*0x113635*/
      if ( v14 < 0 ) /*0x113649*/
        return result; /*0x113649*/
      v13 = spltty(); /*0x113654*/
      v9 = a2[2]; /*0x11365a*/
      if ( v9 && *a2 >= 0 ) /*0x113664*/
      {
        if ( (v9 & 0x3F) != 0 ) /*0x1136af*/
          goto LABEL_23; /*0x1136af*/
        v11 = (int *)cfreelist; /*0x1136b1*/
        *(_DWORD *)(v9 - 64) = cfreelist; /*0x1136b6*/
        if ( v11 ) /*0x1136bb*/
        {
          cfreelist = *v11; /*0x1136cc*/
          cfreecount -= 52; /*0x1136d2*/
          *v11 = 0; /*0x1136d9*/
          v9 = (signed int)(v11 + 3); /*0x1136df*/
          goto LABEL_23; /*0x1136df*/
        }
LABEL_18:
        splx(v13); /*0x113670*/
      }
      else
      {
        v10 = (_DWORD *)cfreelist; /*0x113666*/
        if ( !cfreelist ) /*0x11366e*/
          goto LABEL_18; /*0x11366e*/
        cfreelist = *(_DWORD *)cfreelist; /*0x11367e*/
        cfreecount -= 52; /*0x113684*/
        *v10 = 0; /*0x11368b*/
        bzero(v10 + 1, 8u); /*0x113697*/
        v9 = (signed int)(v10 + 3); /*0x11369c*/
        a2[1] = v9; /*0x1136a2*/
LABEL_23:
        if ( (v14 & 0x100) != 0 ) /*0x1136e8*/
          *(_BYTE *)((v9 & 0xFFFFFFC0) + ((v9 & 0x3F) >> 3) + 4) |= 1 << ((v9 & 0x3F) - 8 * ((v9 & 0x3F) >> 3)); /*0x11371e*/
        *(_BYTE *)v9 = v14; /*0x113725*/
        ++*a2; /*0x11372a*/
        a2[2] = v9 + 1; /*0x11372d*/
        splx(v13); /*0x113734*/
      }
    }
  }
  *a2 = *a1; /*0x11351b*/
  a2[1] = a1[1]; /*0x113520*/
  a2[2] = a1[2]; /*0x113526*/
  *a1 = 0; /*0x113529*/
  a1[1] = 0; /*0x11352f*/
  a1[2] = 0; /*0x113536*/
  return splx(v2); /*0x11373f*/
}
