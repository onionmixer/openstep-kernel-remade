/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x107f48. */
int _setgid()
{
  __int16 v0; // di
  __int16 v1; // bx
  int result; // eax
  __int16 v3; // si
  _DWORD *posix_proc; // [esp+Ch] [ebp-4h]

  v0 = *(_WORD *)(*(_DWORD *)(active_u + 28) + 8); /*0x107f62*/
  v1 = **(_WORD **)(dword_1E875C + 36); /*0x107f66*/
  posix_proc = get_posix_proc(*(__int16 *)(*(_DWORD *)active_u + 48)); /*0x107f75*/
  if ( v1 < 0 ) /*0x107f7e*/
  {
    result = dword_1E875C; /*0x107f80*/
    *(_BYTE *)(dword_1E875C + 104) = 22; /*0x107f85*/
    return result; /*0x107f89*/
  }
  v3 = *((_WORD *)posix_proc + 4); /*0x107f93*/
  if ( suser() ) /*0x107f97*/
  {
    v3 = v1; /*0x107fb8*/
    v0 = v1; /*0x107fba*/
  }
  else if ( v1 != v0 && v1 != v3 ) /*0x107fa8*/
  {
    result = dword_1E875C; /*0x107faa*/
    *(_BYTE *)(dword_1E875C + 104) = 1; /*0x107faf*/
    return result; /*0x107fb3*/
  }
  *(_BYTE *)(dword_1E875C + 104) = 0; /*0x107fc1*/
  lock_write(active_u + 32); /*0x107fce*/
  *(_DWORD *)(active_u + 28) = crcopy(*(_DWORD *)(active_u + 28)); /*0x107fe8*/
  *(_WORD *)(*(_DWORD *)(active_u + 28) + 8) = v0; /*0x107ff3*/
  *(_WORD *)(*(_DWORD *)(active_u + 28) + 4) = v1; /*0x107fff*/
  result = lock_done(active_u + 32); /*0x10800c*/
  *((_WORD *)posix_proc + 4) = v3; /*0x108014*/
  return result; /*0x10801b*/
}
