/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x185274. */
int __cdecl vol_panel_remove(int a1)
{
  int v1; // esi
  _DWORD *v2; // eax
  int v3; // eax
  int v4; // eax

  v1 = 0; /*0x18527d*/
  if ( panel_req_port )
  {
    v2 = (_DWORD *)kalloc(0x20u); /*0x18528a*/
    qmemcpy(v2, &unk_1E150C, 0x20u); /*0x18529e*/
    v2[3] = dword_1E13F4; /*0x1852a6*/
    v2[4] = panel_req_port; /*0x1852af*/
    v2[7] = a1; /*0x1852b2*/
    v3 = msg_send_from_kernel(v2, 1, 0); /*0x1852ba*/
    v1 = v3; /*0x1852bf*/
    if ( v3 )
      printf("vol_panel_remove: msg_send returned %d\n", v3);
  }
  v4 = sub_1857FC(a1); /*0x1852d7*/
  if ( v4 ) /*0x1852e1*/
    kfree(v4, 20); /*0x1852e6*/
  return v1; /*0x1852f0*/
}
