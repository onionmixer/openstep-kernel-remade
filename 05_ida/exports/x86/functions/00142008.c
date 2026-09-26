/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x142008. */
int __cdecl lf_lockctl(int a1, int a2, int a3)
{
  int v3; // edi
  unsigned int v4; // ebx
  int v5; // eax
  int v6; // eax
  int v7; // esi

  v3 = sub_1420E4(a1); /*0x14201a*/
  v4 = kalloc(0x1Cu); /*0x142023*/
  *(_WORD *)(v4 + 2) = *(_WORD *)a2; /*0x142028*/
  *(_DWORD *)(v4 + 4) = *(_DWORD *)(a2 + 4); /*0x14202f*/
  v5 = *(_DWORD *)(a2 + 8); /*0x142035*/
  if ( v5 ) /*0x14203a*/
    v6 = *(_DWORD *)(a2 + 4) + v5 - 1; /*0x14203f*/
  else
    v6 = -1; /*0x142044*/
  *(_DWORD *)(v4 + 8) = v6; /*0x142049*/
  *(_DWORD *)(v4 + 12) = get_posix_proc(*(__int16 *)(*(_DWORD *)active_u + 48)); /*0x14205d*/
  *(_DWORD *)(v4 + 16) = v3; /*0x142060*/
  ++*(_DWORD *)(v3 + 8); /*0x142063*/
  *(_DWORD *)(v4 + 20) = 0; /*0x142066*/
  *(_DWORD *)(v4 + 24) = 0; /*0x14206d*/
  if ( a3 == 7 ) /*0x14207b*/
  {
    v7 = sub_142544(v4, a2); /*0x142084*/
    sub_14286C(v4); /*0x142087*/
LABEL_12:
    sub_142154(v3); /*0x1420d0*/
    return v7; /*0x1420d6*/
  }
  if ( *(_WORD *)a2 == 3 ) /*0x142098*/
  {
    v7 = sub_142434(v4); /*0x1420a0*/
    sub_14286C(v4); /*0x1420a3*/
    goto LABEL_12; /*0x1420ab*/
  }
  if ( a3 == 8 ) /*0x1420b4*/
    *(_WORD *)v4 = 1; /*0x1420b6*/
  else
    *(_WORD *)v4 = 2; /*0x1420c0*/
  return sub_1421B8(v4); /*0x1420db*/
}
