/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x16cb9c. */
int __cdecl kern_serv_port_serv(int *a1, int a2, int a3, int a4)
{
  int v4; // esi
  int v5; // ebx
  int v6; // eax
  int v7; // ebx
  int v8; // eax
  int result; // eax
  int v10; // eax

  v4 = *a1; /*0x16cba8*/
  if ( *(_DWORD *)(*a1 + 1196) == a2 ) /*0x16cbb0*/
    *(_DWORD *)(v4 + 1196) = 0; /*0x16cbb2*/
  v5 = 0; /*0x16cbbc*/
  v6 = 0; /*0x16cbbe*/
  do /*0x16cbdb*/
  {
    if ( *(_DWORD *)(v6 + v4 + 396) == a2 ) /*0x16cbc7*/
      *(_DWORD *)(v6 + v4 + 396) = 0; /*0x16cbc9*/
    v6 += 16; /*0x16cbd4*/
    ++v5; /*0x16cbd7*/
  }
  while ( v5 <= 49 ); /*0x16cbdb*/
  v7 = 0; /*0x16cbdd*/
  v8 = 0; /*0x16cbdf*/
  do /*0x16cbf5*/
  {
    if ( !*(_DWORD *)(v8 + v4 + 396) ) /*0x16cbe4*/
      break; /*0x16cbec*/
    v8 += 16; /*0x16cbee*/
    ++v7; /*0x16cbf1*/
  }
  while ( v7 <= 49 ); /*0x16cbf5*/
  result = 6; /*0x16cbf7*/
  if ( v7 != 50 ) /*0x16cbff*/
  {
    result = port_set_add_EXTERNAL(*(_DWORD *)(v4 + 8)); /*0x16cc0a*/
    if ( !result ) /*0x16cc11*/
    {
      v10 = 16 * v7; /*0x16cc15*/
      *(_DWORD *)(v10 + v4 + 396) = a2; /*0x16cc18*/
      *(_DWORD *)(v10 + v4 + 400) = a3; /*0x16cc22*/
      *(_DWORD *)(v10 + v4 + 404) = a4; /*0x16cc2c*/
      *(_DWORD *)(v10 + v4 + 408) = 1; /*0x16cc33*/
      return 0; /*0x16cc3e*/
    }
  }
  return result; /*0x16cc43*/
}
