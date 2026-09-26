/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x107e60. */
int _setuid()
{
  __int16 v0; // di
  __int16 v1; // bx
  int result; // eax
  __int16 v3; // si
  int v4; // eax
  int v5; // edx
  _DWORD *posix_proc; // [esp+Ch] [ebp-4h]

  v0 = *(_WORD *)(*(_DWORD *)(active_u + 28) + 6); /*0x107e7a*/
  v1 = **(_WORD **)(dword_1E875C + 36); /*0x107e7e*/
  posix_proc = get_posix_proc(*(__int16 *)(*(_DWORD *)active_u + 48)); /*0x107e8d*/
  if ( v1 < 0 ) /*0x107e96*/
  {
    result = dword_1E875C; /*0x107e98*/
    *(_BYTE *)(dword_1E875C + 104) = 22; /*0x107e9d*/
    return result; /*0x107ea1*/
  }
  v3 = *((_WORD *)posix_proc + 3); /*0x107eab*/
  if ( suser() ) /*0x107eaf*/
  {
    v3 = v1; /*0x107ed0*/
    v0 = v1; /*0x107ed2*/
  }
  else if ( v1 != v0 && v1 != v3 ) /*0x107ec0*/
  {
    result = dword_1E875C; /*0x107ec2*/
    *(_BYTE *)(dword_1E875C + 104) = 1; /*0x107ec7*/
    return result; /*0x107ecb*/
  }
  *(_BYTE *)(dword_1E875C + 104) = 0; /*0x107ed9*/
  lock_write(active_u + 32); /*0x107ee6*/
  *(_DWORD *)(active_u + 28) = crcopy(*(_DWORD *)(active_u + 28)); /*0x107f00*/
  v4 = *(_DWORD *)(active_u + 28); /*0x107f08*/
  *((_WORD *)posix_proc + 2) = v0; /*0x107f0e*/
  *(_WORD *)(v4 + 6) = v0; /*0x107f12*/
  v5 = *(_DWORD *)active_u; /*0x107f1b*/
  *(_WORD *)(*(_DWORD *)(active_u + 28) + 2) = v1; /*0x107f20*/
  *(_WORD *)(v5 + 44) = v1; /*0x107f24*/
  result = lock_done(active_u + 32); /*0x107f31*/
  *((_WORD *)posix_proc + 3) = v3; /*0x107f39*/
  return result; /*0x107f40*/
}
