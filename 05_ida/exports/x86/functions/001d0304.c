/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1d0304. */
SEL __cdecl sel_getUid(const char *str)
{
  const char *v2; // edx
  unsigned int v3; // ecx
  _BYTE *v4; // edx
  _BYTE *v5; // edx
  int v6; // eax
  _BYTE *v7; // edx
  _DWORD *v8; // esi
  int **v9; // ebx
  unsigned int v10; // [esp+Ch] [ebp-4h]

  if ( !str ) /*0x1d0312*/
    return nullptr; /*0x1d0312*/
  v2 = str; /*0x1d032c*/
  v3 = 0; /*0x1d032e*/
  while ( *v2 ) /*0x1d0330*/
  {
    v3 ^= *(unsigned __int8 *)v2; /*0x1d0338*/
    v4 = v2 + 1; /*0x1d033a*/
    if ( !*v4 ) /*0x1d033b*/
      break; /*0x1d033b*/
    v3 ^= (unsigned __int8)*v4 << 8; /*0x1d0346*/
    v5 = v4 + 1; /*0x1d0348*/
    if ( !*v5 ) /*0x1d0349*/
      break; /*0x1d0349*/
    v6 = (unsigned __int8)*v5 << 16; /*0x1d0351*/
    v3 ^= v6; /*0x1d0354*/
    v7 = v5 + 1; /*0x1d0356*/
    if ( !*v7 ) /*0x1d0357*/
      break; /*0x1d0357*/
    LOBYTE(v6) = *v7; /*0x1d035c*/
    v3 ^= v6 << 24; /*0x1d0361*/
    v2 = v7 + 1; /*0x1d0363*/
  }
  v10 = v3; /*0x1d0368*/
  v8 = off_1E5640; /*0x1d036b*/
  if ( !off_1E5640 ) /*0x1d0373*/
    return nullptr; /*0x1d03bc*/
  while ( 1 ) /*0x1d0378*/
  {
    if ( v8[3] <= (unsigned int)str && v8[4] > (unsigned int)str ) /*0x1d0380*/
      return str; /*0x1d031e*/
    v9 = *(int ***)(v8[5] + 4 * (v10 % v8[1])); /*0x1d038d*/
    if ( v9 ) /*0x1d0392*/
      break; /*0x1d0392*/
LABEL_18:
    v8 = (_DWORD *)v8[6]; /*0x1d03b5*/
    if ( !v8 ) /*0x1d03ba*/
      return nullptr; /*0x1d03ba*/
  }
  while ( *(_BYTE *)v9[1] != *str || strcmp(str, (const char *)v9[1]) ) /*0x1d03a9*/
  {
    v9 = (int **)*v9; /*0x1d03af*/
    if ( !v9 ) /*0x1d03b3*/
      goto LABEL_18; /*0x1d03b3*/
  }
  return (SEL)v9[1]; /*0x1d03c1*/
}
