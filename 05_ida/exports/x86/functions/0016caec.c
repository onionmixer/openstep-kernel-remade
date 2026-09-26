/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16caec. */
int __cdecl kern_serv_port_proc(int *a1, int a2, int a3, int a4)
{
  int v4; // esi
  int v5; // ebx
  int v6; // eax
  int v7; // ebx
  int v8; // eax
  int result; // eax
  int v10; // eax

  v4 = *a1; /*0x16caf8*/
  if ( *(_DWORD *)(*a1 + 1196) == a2 ) /*0x16cb00*/
    *(_DWORD *)(v4 + 1196) = 0; /*0x16cb02*/
  v5 = 0; /*0x16cb0c*/
  v6 = 0; /*0x16cb0e*/
  do /*0x16cb2b*/
  {
    if ( *(_DWORD *)(v6 + v4 + 396) == a2 ) /*0x16cb17*/
      *(_DWORD *)(v6 + v4 + 396) = 0; /*0x16cb19*/
    v6 += 16; /*0x16cb24*/
    ++v5; /*0x16cb27*/
  }
  while ( v5 <= 49 ); /*0x16cb2b*/
  v7 = 0; /*0x16cb2d*/
  v8 = 0; /*0x16cb2f*/
  do /*0x16cb45*/
  {
    if ( !*(_DWORD *)(v8 + v4 + 396) ) /*0x16cb34*/
      break; /*0x16cb3c*/
    v8 += 16; /*0x16cb3e*/
    ++v7; /*0x16cb41*/
  }
  while ( v7 <= 49 ); /*0x16cb45*/
  result = 6; /*0x16cb47*/
  if ( v7 != 50 ) /*0x16cb4f*/
  {
    result = port_set_add_EXTERNAL(*(_DWORD *)(v4 + 8)); /*0x16cb5a*/
    if ( !result ) /*0x16cb61*/
    {
      v10 = 16 * v7; /*0x16cb65*/
      *(_DWORD *)(v10 + v4 + 396) = a2; /*0x16cb68*/
      *(_DWORD *)(v10 + v4 + 400) = a3; /*0x16cb72*/
      *(_DWORD *)(v10 + v4 + 404) = a4; /*0x16cb7c*/
      *(_DWORD *)(v10 + v4 + 408) = 0; /*0x16cb83*/
      return 0; /*0x16cb8e*/
    }
  }
  return result; /*0x16cb93*/
}
