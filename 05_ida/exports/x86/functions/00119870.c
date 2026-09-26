/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x119870. */
int __cdecl vfs_remove(_DWORD *a1)
{
  _DWORD **v1; // edx
  _DWORD *v2; // eax
  _DWORD *v3; // esi
  _DWORD *v4; // ebx
  _DWORD *v5; // eax

  if ( (_DWORD *)rootvfs == a1 ) /*0x11987f*/
    panic(aVfsRemoveUnmou); /*0x119886*/
  v1 = (_DWORD **)rootvfs; /*0x11988e*/
  if ( !rootvfs ) /*0x119896*/
LABEL_15:
    panic(aVfsRemoveVfsNo); /*0x119906*/
  while ( 1 ) /*0x119898*/
  {
    v2 = *v1; /*0x119898*/
    if ( *v1 == a1 ) /*0x11989c*/
      break; /*0x11989c*/
    v1 = (_DWORD **)*v1; /*0x119900*/
    if ( !v2 ) /*0x119904*/
      goto LABEL_15; /*0x119904*/
  }
  *v1 = (_DWORD *)*v2; /*0x1198a0*/
  v3 = (_DWORD *)v2[2]; /*0x1198a2*/
  if ( v3[3] ) /*0x1198a5*/
  {
    v3[3] = 0; /*0x1198f0*/
  }
  else
  {
    v4 = v3 + 4; /*0x1198ab*/
    if ( v3[4] ) /*0x1198ae*/
    {
      while ( 1 ) /*0x1198b4*/
      {
        v5 = (_DWORD *)*v4; /*0x1198b4*/
        if ( (_DWORD *)*v4 == a1 ) /*0x1198b8*/
          break; /*0x1198b8*/
        v4 = v5 + 72; /*0x1198ba*/
        if ( !v5[72] ) /*0x1198c0*/
          goto LABEL_9; /*0x1198c7*/
      }
    }
    else
    {
LABEL_9:
      if ( (_DWORD *)*v4 != a1 ) /*0x1198cb*/
        panic(aVfsRemoveCanTF); /*0x1198d2*/
    }
    *v4 = a1[72]; /*0x1198e0*/
    microtime(v3 + 5); /*0x1198e6*/
  }
  return vfs_unlock(a1); /*0x119913*/
}
