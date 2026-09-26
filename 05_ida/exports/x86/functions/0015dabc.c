/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15dabc. */
int __cdecl find_listener(int a1, __int16 a2, int a3, __int16 a4, char a5)
{
  char *v5; // ecx
  int *v6; // eax
  int *v7; // ebx
  __int16 v8; // dx
  __int16 v9; // dx
  int v10; // edx
  int v11; // edx

  v5 = (char *)&listeners + 8 * (a5 & 0xF); /*0x15dad7*/
  v6 = *((int **)v5 + 1); /*0x15dade*/
  v7 = v6; /*0x15dae1*/
  if ( !v6 ) /*0x15dae5*/
    return 0; /*0x15db3c*/
  while ( 1 ) /*0x15dae8*/
  {
    v8 = *((_WORD *)v6 + 7); /*0x15dae8*/
    if ( !v8 || a4 == v8 ) /*0x15daf5*/
    {
      v9 = *((_WORD *)v6 + 6); /*0x15daf7*/
      if ( !v9 || v9 == a2 ) /*0x15db03*/
      {
        v10 = v6[1]; /*0x15db05*/
        if ( !v10 || a1 == v10 ) /*0x15db0f*/
        {
          v11 = v6[2]; /*0x15db11*/
          if ( !v11 || a3 == v11 ) /*0x15db1b*/
            break; /*0x15db1b*/
        }
      }
    }
    v7 = v6; /*0x15db34*/
    v6 = (int *)*v6; /*0x15db36*/
    if ( !v6 ) /*0x15db3a*/
      return 0; /*0x15db3a*/
  }
  if ( *((int **)v5 + 1) != v6 ) /*0x15db20*/
  {
    *v7 = *v6; /*0x15db24*/
    *v6 = *((_DWORD *)v5 + 1); /*0x15db29*/
    *((_DWORD *)v5 + 1) = v6; /*0x15db2b*/
  }
  return v6[4]; /*0x15db41*/
}
