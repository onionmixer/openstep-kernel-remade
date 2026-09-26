/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x130f38. */
int __cdecl sub_130F38(int a1)
{
  _DWORD *v1; // esi
  int v2; // eax

  v1 = *(_DWORD **)(a1 + 296); /*0x130f40*/
  rflush(a1); /*0x130f47*/
  rinval(a1); /*0x130f4d*/
  if ( v1[6] != 1 ) /*0x130f59*/
    return 16; /*0x130f59*/
  v2 = v1[4]; /*0x130f5b*/
  if ( *(_WORD *)(v2 + 6) != 1 ) /*0x130f63*/
    return 16; /*0x130f65*/
  rp_rmhash(*(_BYTE **)(v2 + 48)); /*0x130f70*/
  rinactive(*(_DWORD *)(v1[4] + 48)); /*0x130f7c*/
  vn_rele(v1[4]); /*0x130f85*/
  vfs_putnum((int)&unk_1E59B8, v1[10]); /*0x130f93*/
  if ( (int)v1[22] >= 0 ) /*0x130fa0*/
    kfree(v1[21], v1[22]); /*0x130fa7*/
  kfree((int)v1, 0x70u); /*0x130fb2*/
  return 0; /*0x130fbc*/
}
