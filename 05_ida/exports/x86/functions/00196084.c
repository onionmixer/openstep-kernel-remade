/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x196084. */
int kmtrygetc()
{
  int v0; // eax
  int v1; // edx
  int v3; // ecx
  unsigned int v4; // eax
  int v5; // ebx
  int v6; // ecx
  int v7; // eax
  int v8; // ecx
  int v9; // ebx
  int v10; // eax
  int v11; // edx

  v0 = steal_keyboard_event(); /*0x196089*/
  v1 = v0; /*0x19608e*/
  if ( !v0 ) /*0x196092*/
    return -1; /*0x196099*/
  v3 = 0; /*0x1960a0*/
  v4 = *(_DWORD *)(v0 + 8); /*0x1960a2*/
  if ( v4 == 54 ) /*0x1960a8*/
  {
    dword_1E7758 = *(char *)(v1 + 12); /*0x196118*/
    *(_DWORD *)(v1 + 8) = 0; /*0x19611e*/
    goto LABEL_21; /*0x196125*/
  }
  if ( v4 > 0x36 ) /*0x1960aa*/
  {
    if ( v4 == 96 ) /*0x1960bf*/
    {
      dword_1E7750 = *(char *)(v1 + 12); /*0x1960f0*/
      *(_DWORD *)(v1 + 8) = 0; /*0x1960f6*/
      goto LABEL_21; /*0x1960fd*/
    }
    if ( v4 > 0x60 ) /*0x1960c1*/
    {
      if ( v4 == 97 ) /*0x1960d3*/
      {
        dword_1E7760 = *(char *)(v1 + 12); /*0x196140*/
        *(_DWORD *)(v1 + 8) = 0; /*0x196146*/
        goto LABEL_21; /*0x19614d*/
      }
    }
    else if ( v4 == 56 ) /*0x1960c6*/
    {
      dword_1E775C = *(char *)(v1 + 12); /*0x19612c*/
      *(_DWORD *)(v1 + 8) = 0; /*0x196132*/
      goto LABEL_21; /*0x196139*/
    }
  }
  else
  {
    if ( v4 == 29 ) /*0x1960af*/
    {
      dword_1E774C = *(char *)(v1 + 12); /*0x1960dc*/
      *(_DWORD *)(v1 + 8) = 0; /*0x1960e2*/
      goto LABEL_21; /*0x1960e9*/
    }
    if ( v4 == 42 ) /*0x1960b4*/
    {
      dword_1E7754 = *(char *)(v1 + 12); /*0x196104*/
      *(_DWORD *)(v1 + 8) = 0; /*0x19610a*/
      goto LABEL_21; /*0x196111*/
    }
  }
  v3 = 1; /*0x196150*/
LABEL_21:
  if ( !v3 ) /*0x196157*/
    goto LABEL_36; /*0x196157*/
  v5 = 0; /*0x19615d*/
  if ( dword_1E7758 || dword_1E7754 ) /*0x19616f*/
    v5 = 1; /*0x196171*/
  v6 = dword_1E774C || dword_1E7750 ? 220 : 0;
  v7 = v6 + (v5 | (2 * *(_DWORD *)(v1 + 8))); /*0x19619b*/
  v8 = (unsigned __int16)ascii[v7]; /*0x19619d*/
  if ( dword_1E7760 || dword_1E775C ) /*0x1961b5*/
    v9 = 128; /*0x1961b7*/
  else
    v9 = 0; /*0x1961c0*/
  switch ( ascii[v7] ) /*0x1961cd*/
  {
    case 257: /*0x1961cd*/
    case 258: /*0x1961cd*/
    case 260: /*0x1961cd*/
    case 262: /*0x1961cd*/
    case 263: /*0x1961cd*/
    case 264: /*0x1961cd*/
      break;
    default:
      v8 |= v9; /*0x1961f4*/
      break; /*0x1961f4*/
  }
  v10 = v8; /*0x1961f6*/
  if ( !*(_BYTE *)(v1 + 12) ) /*0x1961f8*/
LABEL_36:
    v10 = 256; /*0x1961fe*/
  v11 = -1; /*0x196203*/
  if ( v10 != 256 ) /*0x19620d*/
    return v10; /*0x19620f*/
  return v11; /*0x196216*/
}
