/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15d8f8. */
int __cdecl netipc_listen(int a1, int a2, int a3, __int16 a4, __int16 a5, char a6, int a7)
{
  int v8; // esi
  volatile __int32 *v9; // ebx
  int v10; // edx

  if ( *(_WORD *)(*(_DWORD *)(active_u + 28) + 2) ) /*0x15d917*/
    return 8; /*0x15d91e*/
  if ( !a7 ) /*0x15d92c*/
    return 4; /*0x15d92e*/
  v8 = zalloc(listener_zone); /*0x15d944*/
  *(_DWORD *)(v8 + 4) = a2; /*0x15d949*/
  *(_WORD *)(v8 + 12) = a4; /*0x15d94c*/
  *(_DWORD *)(v8 + 8) = a3; /*0x15d953*/
  *(_WORD *)(v8 + 14) = a5; /*0x15d956*/
  *(_DWORD *)(v8 + 16) = a7; /*0x15d95d*/
  ipc_object_reference(a7); /*0x15d961*/
  v9 = (volatile __int32 *)((char *)&listeners + 8 * (a6 & 0xF)); /*0x15d96c*/
  v10 = splnet(); /*0x15d978*/
  do /*0x15d992*/
  {
    while ( *v9 ) /*0x15d980*/
      ; /*0x15d982*/
  }
  while ( _InterlockedExchange(v9, 1) == 1 ); /*0x15d992*/
  *(_DWORD *)v8 = *((_DWORD *)v9 + 1); /*0x15d997*/
  *((_DWORD *)v9 + 1) = v8; /*0x15d999*/
  _InterlockedExchange(v9, 0); /*0x15d99e*/
  splx(v10); /*0x15d9a1*/
  ipc_kobject_set(a7, 0, 17); /*0x15d9ae*/
  return 0; /*0x15d9b8*/
}
